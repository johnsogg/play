import unittest

from tree import Tree, Node

class TestTree(unittest.TestCase):

    def __init__(self, methodName, humanName, maxPts):
        super(TestTree, self).__init__(methodName)
        self.methodName = methodName
        self.humanName = humanName
        self.maxPts = maxPts
        self.points = 0

    def setUp(self):
        self.tree = Tree()

    def testInsert(self):
        self.assertEquals(self.tree.size(), 0)
        self.tree.insert(Node(7))
        self.assertEquals(self.tree.size(), 1)
        self.tree.bulk_insert(7,3,4,5,3,4,6,6,2,1,10)
        self.assertEquals(self.tree.size(), 12)
        self.assertEquals(self.tree.size(), 3)

    def testNothing(self):
        pass

    def __str__(self):
        return self.humanName

class SpecialResult(unittest.TestResult):
    def addSuccess(self, test):
        print ("Test successful: " + str(test))
        test.points = test.maxPts

    def addFailure(self, test, err):
        print ("Test failed: " + str(test) + ": " + str(err))

    def addError(self, test, err):
        print ("Test error: " + str(test) + ": " + str(err))

if __name__ == '__main__':
    suite = unittest.TestSuite()
    tests = [
        TestTree('testNothing', 'Existence', 1), 
        TestTree('testInsert', 'Insert Data', 4),
        ]
    for test in tests:
        suite.addTest(test)

    result = SpecialResult()
    suite.run(result)
    maxPoints = 0
    earnedPoints = 0
    print "\n------------------------------- Line Item Report"
    label = "{:>30} : "
    numf = "{:>3}"
    sep = "   /   "
    for test in tests:
        print(label.format(test.humanName) + numf.format(str(test.points)) + sep + numf.format(str(test.maxPts)))
        maxPoints = maxPoints + test.maxPts
        earnedPoints = earnedPoints + test.points

    print "\n------------------------------- Summary"
    print label.format("Score") + numf.format(str(earnedPoints)) + sep + numf.format(str(maxPoints))

