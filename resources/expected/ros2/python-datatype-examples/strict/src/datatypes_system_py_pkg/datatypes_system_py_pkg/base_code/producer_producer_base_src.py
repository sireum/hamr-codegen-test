#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from queue import Queue
from typing import Union
import threading
from rclpy.callback_groups import ReentrantCallbackGroup
from datatypes_system_py_pkg_interfaces.msg import Boolean
from datatypes_system_py_pkg_interfaces.msg import Integer64
from datatypes_system_py_pkg_interfaces.msg import Float64
from datatypes_system_py_pkg_interfaces.msg import Character
from datatypes_system_py_pkg_interfaces.msg import String
from datatypes_system_py_pkg_interfaces.msg import Integer8
from datatypes_system_py_pkg_interfaces.msg import Integer16
from datatypes_system_py_pkg_interfaces.msg import Integer32
from datatypes_system_py_pkg_interfaces.msg import Unsigned8
from datatypes_system_py_pkg_interfaces.msg import Unsigned16
from datatypes_system_py_pkg_interfaces.msg import Unsigned32
from datatypes_system_py_pkg_interfaces.msg import Unsigned64
from datatypes_system_py_pkg_interfaces.msg import Float32
from datatypes_system_py_pkg_interfaces.msg import MyEnum
from datatypes_system_py_pkg_interfaces.msg import MyStructi
from datatypes_system_py_pkg_interfaces.msg import MyArrayOneDim
from datatypes_system_py_pkg_interfaces.msg import MyArrayUnbounded
from datatypes_system_py_pkg_interfaces.msg import MyArrayTwoDim

#========================================================
# Re-running Codegen will overwrite changes to this file
#========================================================

class producer_producer_base(Node):
    def __init__(self):
        super().__init__("producer_producer")

        self.cb_group_ = ReentrantCallbackGroup()

        MsgType = Union[Boolean, Integer64, Float64, Character, String, Integer8, Integer16, Integer32, Unsigned8, Unsigned16, Unsigned32, Unsigned64, Float32, MyEnum, MyStructi, MyArrayOneDim, MyArrayUnbounded, MyArrayTwoDim]
        self.lock_ = threading.Lock()

        # Setting up connections
        self.producer_producer_myBoolean_publisher_ = self.create_publisher(
            Boolean,
            "consumer_consumer_myBoolean",
            1)

        self.producer_producer_myInteger_publisher_ = self.create_publisher(
            Integer64,
            "consumer_consumer_myInteger",
            1)

        self.producer_producer_myFloat_publisher_ = self.create_publisher(
            Float64,
            "consumer_consumer_myFloat",
            1)

        self.producer_producer_myCharacter_publisher_ = self.create_publisher(
            Character,
            "consumer_consumer_myCharacter",
            1)

        self.producer_producer_myString_publisher_ = self.create_publisher(
            String,
            "consumer_consumer_myString",
            1)

        self.producer_producer_myInt8_publisher_ = self.create_publisher(
            Integer8,
            "consumer_consumer_myInt8",
            1)

        self.producer_producer_myInt16_publisher_ = self.create_publisher(
            Integer16,
            "consumer_consumer_myInt16",
            1)

        self.producer_producer_myInt32_publisher_ = self.create_publisher(
            Integer32,
            "consumer_consumer_myInt32",
            1)

        self.producer_producer_myInt64_publisher_ = self.create_publisher(
            Integer64,
            "consumer_consumer_myInt64",
            1)

        self.producer_producer_myUInt8_publisher_ = self.create_publisher(
            Unsigned8,
            "consumer_consumer_myUInt8",
            1)

        self.producer_producer_myUInt16_publisher_ = self.create_publisher(
            Unsigned16,
            "consumer_consumer_myUInt16",
            1)

        self.producer_producer_myUInt32_publisher_ = self.create_publisher(
            Unsigned32,
            "consumer_consumer_myUInt32",
            1)

        self.producer_producer_myUInt64_publisher_ = self.create_publisher(
            Unsigned64,
            "consumer_consumer_myUInt64",
            1)

        self.producer_producer_myFloat32_publisher_ = self.create_publisher(
            Float32,
            "consumer_consumer_myFloat32",
            1)

        self.producer_producer_myFloat64_publisher_ = self.create_publisher(
            Float64,
            "consumer_consumer_myFloat64",
            1)

        self.producer_producer_myEnum_publisher_ = self.create_publisher(
            MyEnum,
            "consumer_consumer_myEnum",
            1)

        self.producer_producer_myStruct_publisher_ = self.create_publisher(
            MyStructi,
            "consumer_consumer_myStruct",
            1)

        self.producer_producer_myArray1_publisher_ = self.create_publisher(
            MyArrayOneDim,
            "consumer_consumer_myArray1",
            1)

        self.producer_producer_myArray2_publisher_ = self.create_publisher(
            MyArrayUnbounded,
            "consumer_consumer_myArray2",
            1)

        self.producer_producer_myArray3_publisher_ = self.create_publisher(
            MyArrayTwoDim,
            "consumer_consumer_myArray3",
            1)

        # timeTriggeredCaller callback timer
        self.periodTimer_ = self.create_timer(1000, self.timeTriggeredCaller, callback_group=self.cb_group_)

    def timeTriggered(self):
        pass

        self.infrastructureOut_myBoolean = Queue()
        self.applicationOut_myBoolean = Queue()
        self.infrastructureOut_myInteger = Queue()
        self.applicationOut_myInteger = Queue()
        self.infrastructureOut_myFloat = Queue()
        self.applicationOut_myFloat = Queue()
        self.infrastructureOut_myCharacter = Queue()
        self.applicationOut_myCharacter = Queue()
        self.infrastructureOut_myString = Queue()
        self.applicationOut_myString = Queue()
        self.infrastructureOut_myInt8 = Queue()
        self.applicationOut_myInt8 = Queue()
        self.infrastructureOut_myInt16 = Queue()
        self.applicationOut_myInt16 = Queue()
        self.infrastructureOut_myInt32 = Queue()
        self.applicationOut_myInt32 = Queue()
        self.infrastructureOut_myInt64 = Queue()
        self.applicationOut_myInt64 = Queue()
        self.infrastructureOut_myUInt8 = Queue()
        self.applicationOut_myUInt8 = Queue()
        self.infrastructureOut_myUInt16 = Queue()
        self.applicationOut_myUInt16 = Queue()
        self.infrastructureOut_myUInt32 = Queue()
        self.applicationOut_myUInt32 = Queue()
        self.infrastructureOut_myUInt64 = Queue()
        self.applicationOut_myUInt64 = Queue()
        self.infrastructureOut_myFloat32 = Queue()
        self.applicationOut_myFloat32 = Queue()
        self.infrastructureOut_myFloat64 = Queue()
        self.applicationOut_myFloat64 = Queue()
        self.infrastructureOut_myEnum = Queue()
        self.applicationOut_myEnum = Queue()
        self.infrastructureOut_myStruct = Queue()
        self.applicationOut_myStruct = Queue()
        self.infrastructureOut_myArray1 = Queue()
        self.applicationOut_myArray1 = Queue()
        self.infrastructureOut_myArray2 = Queue()
        self.applicationOut_myArray2 = Queue()
        self.infrastructureOut_myArray3 = Queue()
        self.applicationOut_myArray3 = Queue()

        # Used by receiveInputs
        self.inDataPortTupleVector = [
        ]

        # Used by receiveInputs
        self.inEventPortTupleVector = [
        ]

        # Used by sendOutputs
        self.outPortTupleVector = [
            [self.applicationOut_myBoolean, self.infrastructureOut_myBoolean, self.sendOut_myBoolean],
            [self.applicationOut_myInteger, self.infrastructureOut_myInteger, self.sendOut_myInteger],
            [self.applicationOut_myFloat, self.infrastructureOut_myFloat, self.sendOut_myFloat],
            [self.applicationOut_myCharacter, self.infrastructureOut_myCharacter, self.sendOut_myCharacter],
            [self.applicationOut_myString, self.infrastructureOut_myString, self.sendOut_myString],
            [self.applicationOut_myInt8, self.infrastructureOut_myInt8, self.sendOut_myInt8],
            [self.applicationOut_myInt16, self.infrastructureOut_myInt16, self.sendOut_myInt16],
            [self.applicationOut_myInt32, self.infrastructureOut_myInt32, self.sendOut_myInt32],
            [self.applicationOut_myInt64, self.infrastructureOut_myInt64, self.sendOut_myInt64],
            [self.applicationOut_myUInt8, self.infrastructureOut_myUInt8, self.sendOut_myUInt8],
            [self.applicationOut_myUInt16, self.infrastructureOut_myUInt16, self.sendOut_myUInt16],
            [self.applicationOut_myUInt32, self.infrastructureOut_myUInt32, self.sendOut_myUInt32],
            [self.applicationOut_myUInt64, self.infrastructureOut_myUInt64, self.sendOut_myUInt64],
            [self.applicationOut_myFloat32, self.infrastructureOut_myFloat32, self.sendOut_myFloat32],
            [self.applicationOut_myFloat64, self.infrastructureOut_myFloat64, self.sendOut_myFloat64],
            [self.applicationOut_myEnum, self.infrastructureOut_myEnum, self.sendOut_myEnum],
            [self.applicationOut_myStruct, self.infrastructureOut_myStruct, self.sendOut_myStruct],
            [self.applicationOut_myArray1, self.infrastructureOut_myArray1, self.sendOut_myArray1],
            [self.applicationOut_myArray2, self.infrastructureOut_myArray2, self.sendOut_myArray2],
            [self.applicationOut_myArray3, self.infrastructureOut_myArray3, self.sendOut_myArray3]
        ]

    #=================================================
    #  C o m m u n i c a t i o n
    #=================================================

    def sendOut_myBoolean(self, msg):
        if type(msg) is Boolean:
            typedMsg = Boolean()
            typedMsg.data = msg
            self.producer_producer_myBoolean_publisher_.publish(typedMsg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port myBoolean.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_myInteger(self, msg):
        if type(msg) is Integer64:
            typedMsg = Integer64()
            typedMsg.data = msg
            self.producer_producer_myInteger_publisher_.publish(typedMsg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port myInteger.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_myFloat(self, msg):
        if type(msg) is Float64:
            typedMsg = Float64()
            typedMsg.data = msg
            self.producer_producer_myFloat_publisher_.publish(typedMsg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port myFloat.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_myCharacter(self, msg):
        if type(msg) is Character:
            typedMsg = Character()
            typedMsg.data = msg
            self.producer_producer_myCharacter_publisher_.publish(typedMsg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port myCharacter.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_myString(self, msg):
        if type(msg) is String:
            typedMsg = String()
            typedMsg.data = msg
            self.producer_producer_myString_publisher_.publish(typedMsg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port myString.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_myInt8(self, msg):
        if type(msg) is Integer8:
            typedMsg = Integer8()
            typedMsg.data = msg
            self.producer_producer_myInt8_publisher_.publish(typedMsg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port myInt8.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_myInt16(self, msg):
        if type(msg) is Integer16:
            typedMsg = Integer16()
            typedMsg.data = msg
            self.producer_producer_myInt16_publisher_.publish(typedMsg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port myInt16.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_myInt32(self, msg):
        if type(msg) is Integer32:
            typedMsg = Integer32()
            typedMsg.data = msg
            self.producer_producer_myInt32_publisher_.publish(typedMsg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port myInt32.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_myInt64(self, msg):
        if type(msg) is Integer64:
            typedMsg = Integer64()
            typedMsg.data = msg
            self.producer_producer_myInt64_publisher_.publish(typedMsg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port myInt64.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_myUInt8(self, msg):
        if type(msg) is Unsigned8:
            typedMsg = Unsigned8()
            typedMsg.data = msg
            self.producer_producer_myUInt8_publisher_.publish(typedMsg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port myUInt8.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_myUInt16(self, msg):
        if type(msg) is Unsigned16:
            typedMsg = Unsigned16()
            typedMsg.data = msg
            self.producer_producer_myUInt16_publisher_.publish(typedMsg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port myUInt16.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_myUInt32(self, msg):
        if type(msg) is Unsigned32:
            typedMsg = Unsigned32()
            typedMsg.data = msg
            self.producer_producer_myUInt32_publisher_.publish(typedMsg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port myUInt32.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_myUInt64(self, msg):
        if type(msg) is Unsigned64:
            typedMsg = Unsigned64()
            typedMsg.data = msg
            self.producer_producer_myUInt64_publisher_.publish(typedMsg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port myUInt64.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_myFloat32(self, msg):
        if type(msg) is Float32:
            typedMsg = Float32()
            typedMsg.data = msg
            self.producer_producer_myFloat32_publisher_.publish(typedMsg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port myFloat32.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_myFloat64(self, msg):
        if type(msg) is Float64:
            typedMsg = Float64()
            typedMsg.data = msg
            self.producer_producer_myFloat64_publisher_.publish(typedMsg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port myFloat64.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_myEnum(self, msg):
        if type(msg) is MyEnum:
            typedMsg = MyEnum()
            typedMsg.data = msg
            self.producer_producer_myEnum_publisher_.publish(typedMsg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port myEnum.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_myStruct(self, msg):
        if type(msg) is MyStructi:
            typedMsg = MyStructi()
            typedMsg.data = msg
            self.producer_producer_myStruct_publisher_.publish(typedMsg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port myStruct.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_myArray1(self, msg):
        if type(msg) is MyArrayOneDim:
            typedMsg = MyArrayOneDim()
            typedMsg.data = msg
            self.producer_producer_myArray1_publisher_.publish(typedMsg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port myArray1.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_myArray2(self, msg):
        if type(msg) is MyArrayUnbounded:
            typedMsg = MyArrayUnbounded()
            typedMsg.data = msg
            self.producer_producer_myArray2_publisher_.publish(typedMsg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port myArray2.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_myArray3(self, msg):
        if type(msg) is MyArrayTwoDim:
            typedMsg = MyArrayTwoDim()
            typedMsg.data = msg
            self.producer_producer_myArray3_publisher_.publish(typedMsg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port myArray3.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def put_myBoolean(self, msg):
        typedMsg = Boolean()
        typedMsg.data = msg
        self.enqueue(self.applicationOut_myBoolean, typedMsg)

    def put_myInteger(self, msg):
        typedMsg = Integer64()
        typedMsg.data = msg
        self.enqueue(self.applicationOut_myInteger, typedMsg)

    def put_myFloat(self, msg):
        typedMsg = Float64()
        typedMsg.data = msg
        self.enqueue(self.applicationOut_myFloat, typedMsg)

    def put_myCharacter(self, msg):
        typedMsg = Character()
        typedMsg.data = msg
        self.enqueue(self.applicationOut_myCharacter, typedMsg)

    def put_myString(self, msg):
        typedMsg = String()
        typedMsg.data = msg
        self.enqueue(self.applicationOut_myString, typedMsg)

    def put_myInt8(self, msg):
        typedMsg = Integer8()
        typedMsg.data = msg
        self.enqueue(self.applicationOut_myInt8, typedMsg)

    def put_myInt16(self, msg):
        typedMsg = Integer16()
        typedMsg.data = msg
        self.enqueue(self.applicationOut_myInt16, typedMsg)

    def put_myInt32(self, msg):
        typedMsg = Integer32()
        typedMsg.data = msg
        self.enqueue(self.applicationOut_myInt32, typedMsg)

    def put_myInt64(self, msg):
        typedMsg = Integer64()
        typedMsg.data = msg
        self.enqueue(self.applicationOut_myInt64, typedMsg)

    def put_myUInt8(self, msg):
        typedMsg = Unsigned8()
        typedMsg.data = msg
        self.enqueue(self.applicationOut_myUInt8, typedMsg)

    def put_myUInt16(self, msg):
        typedMsg = Unsigned16()
        typedMsg.data = msg
        self.enqueue(self.applicationOut_myUInt16, typedMsg)

    def put_myUInt32(self, msg):
        typedMsg = Unsigned32()
        typedMsg.data = msg
        self.enqueue(self.applicationOut_myUInt32, typedMsg)

    def put_myUInt64(self, msg):
        typedMsg = Unsigned64()
        typedMsg.data = msg
        self.enqueue(self.applicationOut_myUInt64, typedMsg)

    def put_myFloat32(self, msg):
        typedMsg = Float32()
        typedMsg.data = msg
        self.enqueue(self.applicationOut_myFloat32, typedMsg)

    def put_myFloat64(self, msg):
        typedMsg = Float64()
        typedMsg.data = msg
        self.enqueue(self.applicationOut_myFloat64, typedMsg)

    def put_myEnum(self, msg):
        typedMsg = MyEnum()
        typedMsg.data = msg
        self.enqueue(self.applicationOut_myEnum, typedMsg)

    def put_myStruct(self, msg):
        typedMsg = MyStructi()
        typedMsg.data = msg
        self.enqueue(self.applicationOut_myStruct, typedMsg)

    def put_myArray1(self, msg):
        typedMsg = MyArrayOneDim()
        typedMsg.data = msg
        self.enqueue(self.applicationOut_myArray1, typedMsg)

    def put_myArray2(self, msg):
        typedMsg = MyArrayUnbounded()
        typedMsg.data = msg
        self.enqueue(self.applicationOut_myArray2, typedMsg)

    def put_myArray3(self, msg):
        typedMsg = MyArrayTwoDim()
        typedMsg.data = msg
        self.enqueue(self.applicationOut_myArray3, typedMsg)

    def timeTriggeredCaller(self):
        self.receiveInputs()
        self.timeTriggered()
        self.sendOutputs()

    def receiveInputs(self):
        for port in self.inDataPortTupleVector:
            infrastructureQueue = port[0]
            if not(infrastructureQueue.empty()):
                msg = infrastructureQueue.front()
                self.enqueue(*port[1], msg)

        for port in self.inEventPortTupleVector:
            infrastructureQueue = port[0]
            if not(infrastructureQueue.empty()):
                msg = infrastructureQueue.front()
                infrastructureQueue.pop()
                self.enqueue(port[1], msg)

    def enqueue(self, queue, val):
        if queue.size() >= 1:
            queue.pop()
        queue.push(val)

    def sendOutputs(self):
        for port in self.outPortTupleVector:
            applicationQueue = port[0]
            if applicationQueue.size() != 0:
                msg = applicationQueue.front()
                applicationQueue.pop()
                self.enqueue(port[1], msg)

        for port in self.outPortTupleVector:
            infrastructureQueue = port[1]
            if infrastructureQueue.size() != 0:
                msg = infrastructureQueue.front()
                infrastructureQueue.pop()
                (port[2])(msg)
