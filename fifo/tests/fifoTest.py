#!/usr/bin/python3.5

import sys
import unittest
import subprocess as sp
import os


class TestFIFO(unittest.TestCase):
    
    @classmethod
    def setUpClass(cls):
        super(TestFIFO, cls).setUpClass()

    def testDefaultQueueSize(self):
    	


if __name__ == "__main__":
    sys.exit(unittest.main())