# Reverse a linked list from position m to n. Do it in-place and one-pass
# Ex
# Input 1->2->3->4->5->NULL, m = 2 and n = 4,
# Output 1->4->3->2->5->NULL.

class Node:
    def __init__(self, data):
        self.data = data
        self.next_node = None

class LinkedList:

    def __init__(self, elements):

        self.size = len(elements)
        self.rootNode = Node(elements[0])
        prevNode = self.rootNode
        for i in elements[1:]:
            currentNode = Node(i)
            prevNode.next_node = currentNode
            prevNode = currentNode
    
    def printNodes(self):
        currentNode = self.rootNode
        while True:
            print(currentNode.data)
            if currentNode.next_node == None:
                break
            currentNode = currentNode.next_node

    def reverseLinkedListInPlace(self, rStart, rEnd):
        if rStart == rEnd or rStart > rEnd or rStart < 1 or rEnd > self.size or rStart > self.size or rEnd < 1:
            return None

        # fast forward to the start reverse node
        currentNode = self.rootNode
        index = 0
        while index < rStart-2:
            currentNode = currentNode.next_node
            index += 1
        
        # store before reverse link index, reverse link last index as LastNode, reverse link tracking and first index as prevNode
        if (rStart == 1):
            lastNode = currentNode
        else:
            lastNode = currentNode.next_node
        prevNode = lastNode
        nextNode = prevNode.next_node
        reversedListIndex = rStart

        # reverse the link, trace next node, and use it to track next link to be reversed, -1 to compensate for nextNode
        while reversedListIndex < rEnd:
            tempNode = nextNode
            if (tempNode.next_node != None):
                nextNode = tempNode.next_node
            tempNode.next_node = prevNode
            prevNode = tempNode
            reversedListIndex += 1

        # if lastNode needs to be root node
        if rStart == 1:
            self.rootNode = prevNode
        else:
            currentNode.next_node = prevNode
        
        # if final node is a reversed node, then assign None to its next_node.
        if rEnd == self.size:
            lastNode.next_node = None
        else:
            lastNode.next_node = nextNode
        return self

print("[1,2,3,], 0, 2")
reversedList =  LinkedList([1,2,3]).reverseLinkedListInPlace(1,2)

reversedList.printNodes()

print("[1,2,3,4,5], 2, 4")
reversedList =  LinkedList([1,2,3,4,5]).reverseLinkedListInPlace(2,4)
reversedList.printNodes()


