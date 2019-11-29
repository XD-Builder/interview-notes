#!/usr/bin/python3


class LinkedListNode(object):

    """Link list node"""

    def __init__(self, value):
        """Initialize the node"""
        self.value = value
        self.next = None


class LinkedList(object):

    """A simple linklist implementation"""

    def __init__(self):
        """Initialize linklist"""
        self.head = None
        self.tail = None

    def push(self, value):
        """Push node to linkedlist"""
        if not self.head:
            self.tail = self.head = LinkedListNode(value)
        else:
            self.tail.next = LinkedListNode(value)
            self.tail = self.tail.next

    def remove_dups(self):
        """remove duplicates in this linked list

        :returns: current list

        """
        dupMap = {}
        curr = self.head
        prev = None
        while curr:
            if dupMap.get(curr.value):
                prev.next = curr.next
            else:
                dupMap[curr.value] = 1
                prev = curr
            curr = curr.next

    def kth_to_last(self, k):
        """Find Kth to the last element in a singly linked list

        :arg1: k
        :returns: element

        """
        if not self.head:
            return None
        k_ahead_node = self.head
        kth_node = self.head

        # Go through k rounds
        for _ in range(k):
            if not k_ahead_node.next:
                return None
            k_ahead_node = k_ahead_node.next

        while k_ahead_node:
            k_ahead_node = k_ahead_node.next
            kth_node = kth_node.next

        return kth_node.value

    def partition(self, partitionValue):
        """
        Partition a linked list around value x, such that all
        nodes less than x come before all nodes greater than or equal
        to x. Order of elements doesn't matter

        :arg1 partitionValue

        """
        tail = head = curr_node = self.head

        while curr_node:
            next_node = curr_node.next
            # This can have circular loop if tail is never called
            if curr_node.value < partitionValue:
                curr_node.next = head
                head = curr_node
            else:
                # tail => tail , cur => tail, cur1 => cur2 => tail
                tail.next = curr_node
                tail = curr_node
            curr_node = next_node

        # Avoids circular loop if tail is never called.
        # Insures that head.next => head don't happen
        tail.next = None
        self.head = head
        self.tail = tail
        return self

    def __str__(self):
        nodes = []
        curr = self.head
        while curr:
            nodes.append(curr.value)
            curr = curr.next
        return "Nodes : [ " + " ".join(nodes) + " ]"


def remove_dups_test():
    """remove dups should be fast"""
    linkedlist = get_linked_list()
    assert linkedlist.__str__() == "Nodes : [ a b c b ]"
    linkedlist.remove_dups()
    assert linkedlist.__str__() == "Nodes : [ a b c ]"


def kth_to_last_test():
    linkedlist = get_linked_list()
    assert linkedlist.kth_to_last(2) == "c"


def partition_test():
    linkedlist = LinkedList()
    linkedlist.push("a")
    linkedlist.push("b")
    linkedlist.push("c")
    assert linkedlist.partition("e").__str__() == "Nodes : [ c b a ]"

    linkedlist = LinkedList()
    linkedlist.push("b")
    linkedlist.push("c")
    linkedlist.push("d")
    assert linkedlist.partition("a").__str__() == "Nodes : [ b c d ]"

    linkedlist = LinkedList()
    linkedlist.push("b")
    assert linkedlist.partition("a").__str__() == "Nodes : [ b ]"

    linkedlist = LinkedList()
    linkedlist.push("b")
    linkedlist.partition("c").__str__() == "Nodes : [ b ]"


def get_linked_list():
    linkedlist = LinkedList()
    linkedlist.push("a")
    linkedlist.push("b")
    linkedlist.push("c")
    linkedlist.push("b")
    return linkedlist


partition_test()
# kth_to_last_test()
# remove_dups_test()
