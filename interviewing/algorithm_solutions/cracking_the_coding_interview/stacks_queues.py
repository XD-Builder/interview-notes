#!/usr/local/bin/python3


import sys
import os


class MinStack():
    """O(1) time push, pop and min"""

    def __init__(self):
        """Stack Object"""
        self.stack = []
        self.min_stack = []

    def push(self, ele):
        """Push element to the stack

        :ele1: element to be pushed
        :returns: ele

        """
        if not self.min_stack or ele < self.min_stack[-1]:
            self.min_stack.append(ele)
        self.stack.append(ele)

    def pop(self):
        """Pop element from the stack

        :returns: element popped

        """
        if not self.stack:
            return None
        pop_ele = self.stack.pop()
        return self.min_stack.pop() if pop_ele == self.min_stack[-1] \
            else pop_ele

    def min(self):
        """return minimum element from the stack

        :returns: min

        """
        return self.min_stack[-1] if self.min_stack else None


class TwoStacksQueue(object):

    """Docstring for MyClass. """

    def __init__(self):
        """TODO: to be defined1. """
        self.stack_new = []
        self.stack_old = []

    def add(self, ele):
        """add element to the end of the queue

        :ele: element to enque
        :returns: ele

        """
        self.stack_new.append(ele)
        return ele

    def pop(self):
        """remove element from the head of the queue

        :returns: head of the queue

        """
        if self.stack_old:
            return self.stack_old.pop()
        else:
            while len(self.stack_new):
                self.stack_old.append(self.stack_new.pop())
        return self.stack_old.pop() if len(self.stack_old) else None

    def peek(self):
        """return the first element in the queue

        :returns: first element

        """
        if self.stack_old:
            return self.stack_old[-1]
        else:
            while len(self.stack_new):
                self.stack_old.append(self.stack_new.pop())
        return self.stack_old[-1] if self.stack_old else None


def test_two_stacks_queue():
    """TODO: Docstring for function.

    :arg1: TODO
    :returns: TODO

    """
    two_stacks_queue = TwoStacksQueue()
    for i in range(5):
        print("add to two stacks queue: {}".format(two_stacks_queue.add(i)))
        print("peek first element in the queue: {}".format(
            two_stacks_queue.peek()))
    for i in range(6):
        print("pop two stacks queue: {}".format(two_stacks_queue.pop()))
        print("peek first element in the queue: {}".format(
            two_stacks_queue.peek()))


def test_min_stack():
    """test min stack keeps its promise"""
    min_stack = MinStack()
    for i in [5, 6, 3, 7]:
        print("Pushing {}".format(i))
        min_stack.push(i)
        print("Min is {}".format(min_stack.min()))
    for i in range(5):
        print("Popping {}".format(min_stack.pop()))
        print("Min is {}".format(min_stack.min()))


# test_min_stack()
# test_two_stacks_queue()
