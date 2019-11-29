#!/usr/local/bin/python3
"""
Purose:
    Python offers a number of useful synchronization primitives in the
    threading and Queue modules. One that is missing, however, is a
    simple reader-writer lock (RWLock). A RWLock allows improved
    concurrency over a simple mutex, and is useful for objects that
    have high read-to-write ratios like database caches.

"""

import threading


class RWLock(object):
    """An RWLock optimized for both read/write """

    def __init__(self):
        self.rwlock = 0
        self.writers_waiting = 0
        self.monitor = threading.Lock()
        self.readers_ok = threading.Condition(self.monitor)
        self.writers_ok = threading.Condition(self.monitor)

    def acquire_read(self):
        """Acquire a read lock. Several threads can hold this type of lock
                and only when no read locks are also held."""
        self.monitor.acquire()
        # If no reader and writer writing or writer waiting then wait
        while self.rwlock < 0 or self.writers_waiting:
            # releases lock for writer and waits
            self.readers_ok.wait()
        self.rwlock += 1
        self.monitor.release()

    def acquire_write(self):
        """Acquire a write lock. Only one thread can hold this lock, and
        only when no read locks are also held."""
        self.monitor.acquire()
        # If there exist another writer or more than one readers then wait
        while self.rwlock != 0:
            self.writers_waiting += 1
            # Wait and let other read threads or writer proceed
            self.writers_ok.wait()
            self.writers_waiting -= 1
        self.rwlock = -1
        self.monitor.release()

    def promote(self):
        """Promote an already-acquired read lock to a write lock
        WARNING: it is very easy to deadlock with this method"""
        self.monitor.acquire()
        # reduce the rwlock by one for giving up reader lock
        self.rwlock -= 1
        # only proceed if no writer or reader are running
        while self.rwlock != 0:
            self.writers_waiting += 1
            self.writers_ok.wait()
            self.writers_waiting -= 1
        # minus one for acquiring writer lock
        self.rwlock = -1
        self.monitor.release()

    def demote(self):
        """Demote an already-acquired write lock to a read lock"""
        self.monitor.acquire()
        # arbitrarily setting rwlock to 1 assuming no reader or writer now
        self.rwlock = 1
        self.readers_ok.notifyAll()
        self.monitor.release()

    def release(self):
        """Release a lock, whether read or write."""
        self.monitor.acquire()
        # setting rwlock to zero for writer and -1 rwlock for reader
        if self.rwlock < 0:
            self.rwlock = 0
        else:
            self.rwlock -= 1

        # if there is writer waiting for this lock then wake all writers
        wake_writers = self.writers_waiting and self.rwlock == 0
        # else if no writer waiting then wake all readers
        wake_readers = self.writers_waiting == 0
        self.monitor.release()
        if wake_writers:
            self.writers_ok.acquire()
            self.writers_ok.notify()
            self.writers_ok.release()
        elif wake_readers:
            self.readers_ok.acquire()
            self.readers_ok.notifyAll()
            self.readers_ok.release()


def RWLock_test():
    import time
    rwl = RWLock()

    class Reader(threading.Thread):
        def run(self):
            print(self, 'start')
            rwl.acquire_read()
            print(self, 'acquired')
            time.sleep(1)
            print(self, 'stop')
            rwl.release()

    class Writer(threading.Thread):
        def run(self):
            print(self, 'start')
            rwl.acquire_write()
            print(self, 'acquired')
            time.sleep(1)
            print(self, 'stop')
            rwl.release()

    class ReaderWriter(threading.Thread):
        def run(self):
            print(self, 'start')
            rwl.acquire_read()
            print(self, 'acquired')
            rwl.promote()
            print(self, 'promoted')
            print(self, 'stop')
            rwl.release()

    class WriterReader(threading.Thread):
        def run(self):
            print(self, 'start')
            rwl.acquire_write()
            print(self, 'acquired')
            print(self, 'demoted')
            rwl.demote()
            print(self, 'stop')
            rwl.release()

    for i in range(10):
        Reader().start()
    for i in range(10):
        WriterReader().start()
    for i in range(10):
        ReaderWriter().start()
    for i in range(10):
        Writer().start()
    time.sleep(20)
    print("rwlock: {}".format(rwl.rwlock))
    assert rwl.rwlock == 0


RWLock_test()
