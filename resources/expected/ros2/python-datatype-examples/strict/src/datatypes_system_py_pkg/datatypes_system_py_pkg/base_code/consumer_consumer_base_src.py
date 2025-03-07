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

class consumer_consumer_base(Node):
    def __init__(self):
        super().__init__("consumer_consumer")

        self.cb_group_ = ReentrantCallbackGroup()

        MsgType = Union[Boolean, Integer64, Float64, Character, String, Integer8, Integer16, Integer32, Unsigned8, Unsigned16, Unsigned32, Unsigned64, Float32, MyEnum, MyStructi, MyArrayOneDim, MyArrayUnbounded, MyArrayTwoDim]
        self.lock_ = threading.Lock()

        # Setting up connections
        self.consumer_consumer_myBoolean_subscription_ = self.create_subscription(
            Boolean,
            "consumer_consumer_myBoolean",
            self.accept_myBoolean,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myInteger_subscription_ = self.create_subscription(
            Integer64,
            "consumer_consumer_myInteger",
            self.accept_myInteger,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myFloat_subscription_ = self.create_subscription(
            Float64,
            "consumer_consumer_myFloat",
            self.accept_myFloat,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myCharacter_subscription_ = self.create_subscription(
            Character,
            "consumer_consumer_myCharacter",
            self.accept_myCharacter,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myString_subscription_ = self.create_subscription(
            String,
            "consumer_consumer_myString",
            self.accept_myString,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myInt8_subscription_ = self.create_subscription(
            Integer8,
            "consumer_consumer_myInt8",
            self.accept_myInt8,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myInt16_subscription_ = self.create_subscription(
            Integer16,
            "consumer_consumer_myInt16",
            self.accept_myInt16,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myInt32_subscription_ = self.create_subscription(
            Integer32,
            "consumer_consumer_myInt32",
            self.accept_myInt32,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myInt64_subscription_ = self.create_subscription(
            Integer64,
            "consumer_consumer_myInt64",
            self.accept_myInt64,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myUInt8_subscription_ = self.create_subscription(
            Unsigned8,
            "consumer_consumer_myUInt8",
            self.accept_myUInt8,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myUInt16_subscription_ = self.create_subscription(
            Unsigned16,
            "consumer_consumer_myUInt16",
            self.accept_myUInt16,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myUInt32_subscription_ = self.create_subscription(
            Unsigned32,
            "consumer_consumer_myUInt32",
            self.accept_myUInt32,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myUInt64_subscription_ = self.create_subscription(
            Unsigned64,
            "consumer_consumer_myUInt64",
            self.accept_myUInt64,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myFloat32_subscription_ = self.create_subscription(
            Float32,
            "consumer_consumer_myFloat32",
            self.accept_myFloat32,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myFloat64_subscription_ = self.create_subscription(
            Float64,
            "consumer_consumer_myFloat64",
            self.accept_myFloat64,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myEnum_subscription_ = self.create_subscription(
            MyEnum,
            "consumer_consumer_myEnum",
            self.accept_myEnum,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myStruct_subscription_ = self.create_subscription(
            MyStructi,
            "consumer_consumer_myStruct",
            self.accept_myStruct,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myArray1_subscription_ = self.create_subscription(
            MyArrayOneDim,
            "consumer_consumer_myArray1",
            self.accept_myArray1,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myArray2_subscription_ = self.create_subscription(
            MyArrayUnbounded,
            "consumer_consumer_myArray2",
            self.accept_myArray2,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myArray3_subscription_ = self.create_subscription(
            MyArrayTwoDim,
            "consumer_consumer_myArray3",
            self.accept_myArray3,
            1,
            callback_group=self.cb_group_)

        # Used by receiveInputs
        self.inDataPortTupleVector = [
         ]

        # Used by sendOutputs
        self.outPortTupleVector = [
         ]

        self.infrastructureIn_myBoolean = Queue()
        self.applicationIn_myBoolean = Queue()
        self.infrastructureIn_myInteger = Queue()
        self.applicationIn_myInteger = Queue()
        self.infrastructureIn_myFloat = Queue()
        self.applicationIn_myFloat = Queue()
        self.infrastructureIn_myCharacter = Queue()
        self.applicationIn_myCharacter = Queue()
        self.infrastructureIn_myString = Queue()
        self.applicationIn_myString = Queue()
        self.infrastructureIn_myInt8 = Queue()
        self.applicationIn_myInt8 = Queue()
        self.infrastructureIn_myInt16 = Queue()
        self.applicationIn_myInt16 = Queue()
        self.infrastructureIn_myInt32 = Queue()
        self.applicationIn_myInt32 = Queue()
        self.infrastructureIn_myInt64 = Queue()
        self.applicationIn_myInt64 = Queue()
        self.infrastructureIn_myUInt8 = Queue()
        self.applicationIn_myUInt8 = Queue()
        self.infrastructureIn_myUInt16 = Queue()
        self.applicationIn_myUInt16 = Queue()
        self.infrastructureIn_myUInt32 = Queue()
        self.applicationIn_myUInt32 = Queue()
        self.infrastructureIn_myUInt64 = Queue()
        self.applicationIn_myUInt64 = Queue()
        self.infrastructureIn_myFloat32 = Queue()
        self.applicationIn_myFloat32 = Queue()
        self.infrastructureIn_myFloat64 = Queue()
        self.applicationIn_myFloat64 = Queue()
        self.infrastructureIn_myEnum = Queue()
        self.applicationIn_myEnum = Queue()
        self.infrastructureIn_myStruct = Queue()
        self.applicationIn_myStruct = Queue()
        self.infrastructureIn_myArray1 = Queue()
        self.applicationIn_myArray1 = Queue()
        self.infrastructureIn_myArray2 = Queue()
        self.applicationIn_myArray2 = Queue()
        self.infrastructureIn_myArray3 = Queue()
        self.applicationIn_myArray3 = Queue()

#=================================================
#  C o m m u n i c a t i o n
#=================================================

    def myBoolean_thread(self):
        with self.lock_:
            self.receiveInputs(self.infrastructureIn_myBoolean, self.applicationIn_myBoolean)
            if self.applicationIn_myBoolean.empty(): return
            self.handle_myBoolean_base(self.applicationIn_myBoolean.front())
            self.applicationIn_myBoolean.pop()
            self.sendOutputs()

    def accept_myBoolean(self, msg):
        typedMsg = Boolean()
        typedMsg.data = msg
        self.enqueue(self.infrastructureIn_myBoolean, msg)
        thread = threading.Thread(target=myBoolean_thread)
        thread.daemon = True
        thread.start()


    def myInteger_thread(self):
        with self.lock_:
            self.receiveInputs(self.infrastructureIn_myInteger, self.applicationIn_myInteger)
            if self.applicationIn_myInteger.empty(): return
            self.handle_myInteger_base(self.applicationIn_myInteger.front())
            self.applicationIn_myInteger.pop()
            self.sendOutputs()

    def accept_myInteger(self, msg):
        typedMsg = Integer64()
        typedMsg.data = msg
        self.enqueue(self.infrastructureIn_myInteger, msg)
        thread = threading.Thread(target=myInteger_thread)
        thread.daemon = True
        thread.start()


    def myFloat_thread(self):
        with self.lock_:
            self.receiveInputs(self.infrastructureIn_myFloat, self.applicationIn_myFloat)
            if self.applicationIn_myFloat.empty(): return
            self.handle_myFloat_base(self.applicationIn_myFloat.front())
            self.applicationIn_myFloat.pop()
            self.sendOutputs()

    def accept_myFloat(self, msg):
        typedMsg = Float64()
        typedMsg.data = msg
        self.enqueue(self.infrastructureIn_myFloat, msg)
        thread = threading.Thread(target=myFloat_thread)
        thread.daemon = True
        thread.start()


    def myCharacter_thread(self):
        with self.lock_:
            self.receiveInputs(self.infrastructureIn_myCharacter, self.applicationIn_myCharacter)
            if self.applicationIn_myCharacter.empty(): return
            self.handle_myCharacter_base(self.applicationIn_myCharacter.front())
            self.applicationIn_myCharacter.pop()
            self.sendOutputs()

    def accept_myCharacter(self, msg):
        typedMsg = Character()
        typedMsg.data = msg
        self.enqueue(self.infrastructureIn_myCharacter, msg)
        thread = threading.Thread(target=myCharacter_thread)
        thread.daemon = True
        thread.start()


    def myString_thread(self):
        with self.lock_:
            self.receiveInputs(self.infrastructureIn_myString, self.applicationIn_myString)
            if self.applicationIn_myString.empty(): return
            self.handle_myString_base(self.applicationIn_myString.front())
            self.applicationIn_myString.pop()
            self.sendOutputs()

    def accept_myString(self, msg):
        typedMsg = String()
        typedMsg.data = msg
        self.enqueue(self.infrastructureIn_myString, msg)
        thread = threading.Thread(target=myString_thread)
        thread.daemon = True
        thread.start()


    def myInt8_thread(self):
        with self.lock_:
            self.receiveInputs(self.infrastructureIn_myInt8, self.applicationIn_myInt8)
            if self.applicationIn_myInt8.empty(): return
            self.handle_myInt8_base(self.applicationIn_myInt8.front())
            self.applicationIn_myInt8.pop()
            self.sendOutputs()

    def accept_myInt8(self, msg):
        typedMsg = Integer8()
        typedMsg.data = msg
        self.enqueue(self.infrastructureIn_myInt8, msg)
        thread = threading.Thread(target=myInt8_thread)
        thread.daemon = True
        thread.start()


    def myInt16_thread(self):
        with self.lock_:
            self.receiveInputs(self.infrastructureIn_myInt16, self.applicationIn_myInt16)
            if self.applicationIn_myInt16.empty(): return
            self.handle_myInt16_base(self.applicationIn_myInt16.front())
            self.applicationIn_myInt16.pop()
            self.sendOutputs()

    def accept_myInt16(self, msg):
        typedMsg = Integer16()
        typedMsg.data = msg
        self.enqueue(self.infrastructureIn_myInt16, msg)
        thread = threading.Thread(target=myInt16_thread)
        thread.daemon = True
        thread.start()


    def myInt32_thread(self):
        with self.lock_:
            self.receiveInputs(self.infrastructureIn_myInt32, self.applicationIn_myInt32)
            if self.applicationIn_myInt32.empty(): return
            self.handle_myInt32_base(self.applicationIn_myInt32.front())
            self.applicationIn_myInt32.pop()
            self.sendOutputs()

    def accept_myInt32(self, msg):
        typedMsg = Integer32()
        typedMsg.data = msg
        self.enqueue(self.infrastructureIn_myInt32, msg)
        thread = threading.Thread(target=myInt32_thread)
        thread.daemon = True
        thread.start()


    def myInt64_thread(self):
        with self.lock_:
            self.receiveInputs(self.infrastructureIn_myInt64, self.applicationIn_myInt64)
            if self.applicationIn_myInt64.empty(): return
            self.handle_myInt64_base(self.applicationIn_myInt64.front())
            self.applicationIn_myInt64.pop()
            self.sendOutputs()

    def accept_myInt64(self, msg):
        typedMsg = Integer64()
        typedMsg.data = msg
        self.enqueue(self.infrastructureIn_myInt64, msg)
        thread = threading.Thread(target=myInt64_thread)
        thread.daemon = True
        thread.start()


    def myUInt8_thread(self):
        with self.lock_:
            self.receiveInputs(self.infrastructureIn_myUInt8, self.applicationIn_myUInt8)
            if self.applicationIn_myUInt8.empty(): return
            self.handle_myUInt8_base(self.applicationIn_myUInt8.front())
            self.applicationIn_myUInt8.pop()
            self.sendOutputs()

    def accept_myUInt8(self, msg):
        typedMsg = Unsigned8()
        typedMsg.data = msg
        self.enqueue(self.infrastructureIn_myUInt8, msg)
        thread = threading.Thread(target=myUInt8_thread)
        thread.daemon = True
        thread.start()


    def myUInt16_thread(self):
        with self.lock_:
            self.receiveInputs(self.infrastructureIn_myUInt16, self.applicationIn_myUInt16)
            if self.applicationIn_myUInt16.empty(): return
            self.handle_myUInt16_base(self.applicationIn_myUInt16.front())
            self.applicationIn_myUInt16.pop()
            self.sendOutputs()

    def accept_myUInt16(self, msg):
        typedMsg = Unsigned16()
        typedMsg.data = msg
        self.enqueue(self.infrastructureIn_myUInt16, msg)
        thread = threading.Thread(target=myUInt16_thread)
        thread.daemon = True
        thread.start()


    def myUInt32_thread(self):
        with self.lock_:
            self.receiveInputs(self.infrastructureIn_myUInt32, self.applicationIn_myUInt32)
            if self.applicationIn_myUInt32.empty(): return
            self.handle_myUInt32_base(self.applicationIn_myUInt32.front())
            self.applicationIn_myUInt32.pop()
            self.sendOutputs()

    def accept_myUInt32(self, msg):
        typedMsg = Unsigned32()
        typedMsg.data = msg
        self.enqueue(self.infrastructureIn_myUInt32, msg)
        thread = threading.Thread(target=myUInt32_thread)
        thread.daemon = True
        thread.start()


    def myUInt64_thread(self):
        with self.lock_:
            self.receiveInputs(self.infrastructureIn_myUInt64, self.applicationIn_myUInt64)
            if self.applicationIn_myUInt64.empty(): return
            self.handle_myUInt64_base(self.applicationIn_myUInt64.front())
            self.applicationIn_myUInt64.pop()
            self.sendOutputs()

    def accept_myUInt64(self, msg):
        typedMsg = Unsigned64()
        typedMsg.data = msg
        self.enqueue(self.infrastructureIn_myUInt64, msg)
        thread = threading.Thread(target=myUInt64_thread)
        thread.daemon = True
        thread.start()


    def myFloat32_thread(self):
        with self.lock_:
            self.receiveInputs(self.infrastructureIn_myFloat32, self.applicationIn_myFloat32)
            if self.applicationIn_myFloat32.empty(): return
            self.handle_myFloat32_base(self.applicationIn_myFloat32.front())
            self.applicationIn_myFloat32.pop()
            self.sendOutputs()

    def accept_myFloat32(self, msg):
        typedMsg = Float32()
        typedMsg.data = msg
        self.enqueue(self.infrastructureIn_myFloat32, msg)
        thread = threading.Thread(target=myFloat32_thread)
        thread.daemon = True
        thread.start()


    def myFloat64_thread(self):
        with self.lock_:
            self.receiveInputs(self.infrastructureIn_myFloat64, self.applicationIn_myFloat64)
            if self.applicationIn_myFloat64.empty(): return
            self.handle_myFloat64_base(self.applicationIn_myFloat64.front())
            self.applicationIn_myFloat64.pop()
            self.sendOutputs()

    def accept_myFloat64(self, msg):
        typedMsg = Float64()
        typedMsg.data = msg
        self.enqueue(self.infrastructureIn_myFloat64, msg)
        thread = threading.Thread(target=myFloat64_thread)
        thread.daemon = True
        thread.start()


    def myEnum_thread(self):
        with self.lock_:
            self.receiveInputs(self.infrastructureIn_myEnum, self.applicationIn_myEnum)
            if self.applicationIn_myEnum.empty(): return
            self.handle_myEnum_base(self.applicationIn_myEnum.front())
            self.applicationIn_myEnum.pop()
            self.sendOutputs()

    def accept_myEnum(self, msg):
        typedMsg = MyEnum()
        typedMsg.data = msg
        self.enqueue(self.infrastructureIn_myEnum, msg)
        thread = threading.Thread(target=myEnum_thread)
        thread.daemon = True
        thread.start()


    def myStruct_thread(self):
        with self.lock_:
            self.receiveInputs(self.infrastructureIn_myStruct, self.applicationIn_myStruct)
            if self.applicationIn_myStruct.empty(): return
            self.handle_myStruct_base(self.applicationIn_myStruct.front())
            self.applicationIn_myStruct.pop()
            self.sendOutputs()

    def accept_myStruct(self, msg):
        typedMsg = MyStructi()
        typedMsg.data = msg
        self.enqueue(self.infrastructureIn_myStruct, msg)
        thread = threading.Thread(target=myStruct_thread)
        thread.daemon = True
        thread.start()


    def myArray1_thread(self):
        with self.lock_:
            self.receiveInputs(self.infrastructureIn_myArray1, self.applicationIn_myArray1)
            if self.applicationIn_myArray1.empty(): return
            self.handle_myArray1_base(self.applicationIn_myArray1.front())
            self.applicationIn_myArray1.pop()
            self.sendOutputs()

    def accept_myArray1(self, msg):
        typedMsg = MyArrayOneDim()
        typedMsg.data = msg
        self.enqueue(self.infrastructureIn_myArray1, msg)
        thread = threading.Thread(target=myArray1_thread)
        thread.daemon = True
        thread.start()


    def myArray2_thread(self):
        with self.lock_:
            self.receiveInputs(self.infrastructureIn_myArray2, self.applicationIn_myArray2)
            if self.applicationIn_myArray2.empty(): return
            self.handle_myArray2_base(self.applicationIn_myArray2.front())
            self.applicationIn_myArray2.pop()
            self.sendOutputs()

    def accept_myArray2(self, msg):
        typedMsg = MyArrayUnbounded()
        typedMsg.data = msg
        self.enqueue(self.infrastructureIn_myArray2, msg)
        thread = threading.Thread(target=myArray2_thread)
        thread.daemon = True
        thread.start()


    def myArray3_thread(self):
        with self.lock_:
            self.receiveInputs(self.infrastructureIn_myArray3, self.applicationIn_myArray3)
            if self.applicationIn_myArray3.empty(): return
            self.handle_myArray3_base(self.applicationIn_myArray3.front())
            self.applicationIn_myArray3.pop()
            self.sendOutputs()

    def accept_myArray3(self, msg):
        typedMsg = MyArrayTwoDim()
        typedMsg.data = msg
        self.enqueue(self.infrastructureIn_myArray3, msg)
        thread = threading.Thread(target=myArray3_thread)
        thread.daemon = True
        thread.start()


    def handle_myBoolean_base(self, msg):
        if type(msg) is Boolean:
            typedMsg = Boolean()
            typedMsg.data = msg
            self.handle_myBoolean(typedMsg)
        else:
            self.get_logger.error("Receiving wrong type of variable on port myBoolean.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def handle_myInteger_base(self, msg):
        if type(msg) is Integer64:
            typedMsg = Integer64()
            typedMsg.data = msg
            self.handle_myInteger(typedMsg)
        else:
            self.get_logger.error("Receiving wrong type of variable on port myInteger.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def handle_myFloat_base(self, msg):
        if type(msg) is Float64:
            typedMsg = Float64()
            typedMsg.data = msg
            self.handle_myFloat(typedMsg)
        else:
            self.get_logger.error("Receiving wrong type of variable on port myFloat.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def handle_myCharacter_base(self, msg):
        if type(msg) is Character:
            typedMsg = Character()
            typedMsg.data = msg
            self.handle_myCharacter(typedMsg)
        else:
            self.get_logger.error("Receiving wrong type of variable on port myCharacter.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def handle_myString_base(self, msg):
        if type(msg) is String:
            typedMsg = String()
            typedMsg.data = msg
            self.handle_myString(typedMsg)
        else:
            self.get_logger.error("Receiving wrong type of variable on port myString.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def handle_myInt8_base(self, msg):
        if type(msg) is Integer8:
            typedMsg = Integer8()
            typedMsg.data = msg
            self.handle_myInt8(typedMsg)
        else:
            self.get_logger.error("Receiving wrong type of variable on port myInt8.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def handle_myInt16_base(self, msg):
        if type(msg) is Integer16:
            typedMsg = Integer16()
            typedMsg.data = msg
            self.handle_myInt16(typedMsg)
        else:
            self.get_logger.error("Receiving wrong type of variable on port myInt16.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def handle_myInt32_base(self, msg):
        if type(msg) is Integer32:
            typedMsg = Integer32()
            typedMsg.data = msg
            self.handle_myInt32(typedMsg)
        else:
            self.get_logger.error("Receiving wrong type of variable on port myInt32.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def handle_myInt64_base(self, msg):
        if type(msg) is Integer64:
            typedMsg = Integer64()
            typedMsg.data = msg
            self.handle_myInt64(typedMsg)
        else:
            self.get_logger.error("Receiving wrong type of variable on port myInt64.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def handle_myUInt8_base(self, msg):
        if type(msg) is Unsigned8:
            typedMsg = Unsigned8()
            typedMsg.data = msg
            self.handle_myUInt8(typedMsg)
        else:
            self.get_logger.error("Receiving wrong type of variable on port myUInt8.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def handle_myUInt16_base(self, msg):
        if type(msg) is Unsigned16:
            typedMsg = Unsigned16()
            typedMsg.data = msg
            self.handle_myUInt16(typedMsg)
        else:
            self.get_logger.error("Receiving wrong type of variable on port myUInt16.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def handle_myUInt32_base(self, msg):
        if type(msg) is Unsigned32:
            typedMsg = Unsigned32()
            typedMsg.data = msg
            self.handle_myUInt32(typedMsg)
        else:
            self.get_logger.error("Receiving wrong type of variable on port myUInt32.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def handle_myUInt64_base(self, msg):
        if type(msg) is Unsigned64:
            typedMsg = Unsigned64()
            typedMsg.data = msg
            self.handle_myUInt64(typedMsg)
        else:
            self.get_logger.error("Receiving wrong type of variable on port myUInt64.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def handle_myFloat32_base(self, msg):
        if type(msg) is Float32:
            typedMsg = Float32()
            typedMsg.data = msg
            self.handle_myFloat32(typedMsg)
        else:
            self.get_logger.error("Receiving wrong type of variable on port myFloat32.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def handle_myFloat64_base(self, msg):
        if type(msg) is Float64:
            typedMsg = Float64()
            typedMsg.data = msg
            self.handle_myFloat64(typedMsg)
        else:
            self.get_logger.error("Receiving wrong type of variable on port myFloat64.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def handle_myEnum_base(self, msg):
        if type(msg) is MyEnum:
            typedMsg = MyEnum()
            typedMsg.data = msg
            self.handle_myEnum(typedMsg)
        else:
            self.get_logger.error("Receiving wrong type of variable on port myEnum.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def handle_myStruct_base(self, msg):
        if type(msg) is MyStructi:
            typedMsg = MyStructi()
            typedMsg.data = msg
            self.handle_myStruct(typedMsg)
        else:
            self.get_logger.error("Receiving wrong type of variable on port myStruct.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def handle_myArray1_base(self, msg):
        if type(msg) is MyArrayOneDim:
            typedMsg = MyArrayOneDim()
            typedMsg.data = msg
            self.handle_myArray1(typedMsg)
        else:
            self.get_logger.error("Receiving wrong type of variable on port myArray1.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def handle_myArray2_base(self, msg):
        if type(msg) is MyArrayUnbounded:
            typedMsg = MyArrayUnbounded()
            typedMsg.data = msg
            self.handle_myArray2(typedMsg)
        else:
            self.get_logger.error("Receiving wrong type of variable on port myArray2.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def handle_myArray3_base(self, msg):
        if type(msg) is MyArrayTwoDim:
            typedMsg = MyArrayTwoDim()
            typedMsg.data = msg
            self.handle_myArray3(typedMsg)
        else:
            self.get_logger.error("Receiving wrong type of variable on port myArray3.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def receiveInputs(self, infrastructureQueue, applicationQueue):
        if not(infrastructureQueue.empty()):
            eventMsg = infrastructureQueue.front()
            infrastructureQueue.pop()
            self.enqueue(applicationQueue, eventMsg)

        for port in self.inDataPortTupleVector:
            infrastructureQueue = port[0]
            if not(infrastructureQueue.empty()):
                msg = infrastructureQueue.front()
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
