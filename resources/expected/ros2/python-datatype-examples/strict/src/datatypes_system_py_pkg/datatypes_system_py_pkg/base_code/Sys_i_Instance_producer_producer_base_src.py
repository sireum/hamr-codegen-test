#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from queue import Queue
from typing import Union
import threading
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

#=================================================
#  D O   N O T   E D I T   T H I S   F I L E
#=================================================

class Sys_i_Instance_producer_producer_base(Node):
   def __init__(self):
       super().__init__("Sys_i_Instance_producer_producer")

       cb_group_ = this.create_callback_group(Reentrant)

    MsgType = Union[Boolean, Integer64, Float64, Character, String, Integer8, Integer16, Integer32, Unsigned8, Unsigned16, Unsigned32, Unsigned64, Float32, MyEnum, MyStructi, MyArrayOneDim, MyArrayUnbounded, MyArrayTwoDim]

  # Setting up connections
  self.Sys_i_Instance_producer_producer_myBoolean_publisher_ = self.create_publisher(
                                Boolean,
                                "Sys_i_Instance_consumer_consumer_myBoolean",
                                1)

  self.Sys_i_Instance_producer_producer_myInteger_publisher_ = self.create_publisher(
                                Integer64,
                                "Sys_i_Instance_consumer_consumer_myInteger",
                                1)

  self.Sys_i_Instance_producer_producer_myFloat_publisher_ = self.create_publisher(
                                Float64,
                                "Sys_i_Instance_consumer_consumer_myFloat",
                                1)

  self.Sys_i_Instance_producer_producer_myCharacter_publisher_ = self.create_publisher(
                                Character,
                                "Sys_i_Instance_consumer_consumer_myCharacter",
                                1)

  self.Sys_i_Instance_producer_producer_myString_publisher_ = self.create_publisher(
                                String,
                                "Sys_i_Instance_consumer_consumer_myString",
                                1)

  self.Sys_i_Instance_producer_producer_myInt8_publisher_ = self.create_publisher(
                                Integer8,
                                "Sys_i_Instance_consumer_consumer_myInt8",
                                1)

  self.Sys_i_Instance_producer_producer_myInt16_publisher_ = self.create_publisher(
                                Integer16,
                                "Sys_i_Instance_consumer_consumer_myInt16",
                                1)

  self.Sys_i_Instance_producer_producer_myInt32_publisher_ = self.create_publisher(
                                Integer32,
                                "Sys_i_Instance_consumer_consumer_myInt32",
                                1)

  self.Sys_i_Instance_producer_producer_myInt64_publisher_ = self.create_publisher(
                                Integer64,
                                "Sys_i_Instance_consumer_consumer_myInt64",
                                1)

  self.Sys_i_Instance_producer_producer_myUInt8_publisher_ = self.create_publisher(
                                Unsigned8,
                                "Sys_i_Instance_consumer_consumer_myUInt8",
                                1)

  self.Sys_i_Instance_producer_producer_myUInt16_publisher_ = self.create_publisher(
                                Unsigned16,
                                "Sys_i_Instance_consumer_consumer_myUInt16",
                                1)

  self.Sys_i_Instance_producer_producer_myUInt32_publisher_ = self.create_publisher(
                                Unsigned32,
                                "Sys_i_Instance_consumer_consumer_myUInt32",
                                1)

  self.Sys_i_Instance_producer_producer_myUInt64_publisher_ = self.create_publisher(
                                Unsigned64,
                                "Sys_i_Instance_consumer_consumer_myUInt64",
                                1)

  self.Sys_i_Instance_producer_producer_myFloat32_publisher_ = self.create_publisher(
                                Float32,
                                "Sys_i_Instance_consumer_consumer_myFloat32",
                                1)

  self.Sys_i_Instance_producer_producer_myFloat64_publisher_ = self.create_publisher(
                                Float64,
                                "Sys_i_Instance_consumer_consumer_myFloat64",
                                1)

  self.Sys_i_Instance_producer_producer_myEnum_publisher_ = self.create_publisher(
                                MyEnum,
                                "Sys_i_Instance_consumer_consumer_myEnum",
                                1)

  self.Sys_i_Instance_producer_producer_myStruct_publisher_ = self.create_publisher(
                                MyStructi,
                                "Sys_i_Instance_consumer_consumer_myStruct",
                                1)

  self.Sys_i_Instance_producer_producer_myArray1_publisher_ = self.create_publisher(
                                MyArrayOneDim,
                                "Sys_i_Instance_consumer_consumer_myArray1",
                                1)

  self.Sys_i_Instance_producer_producer_myArray2_publisher_ = self.create_publisher(
                                MyArrayUnbounded,
                                "Sys_i_Instance_consumer_consumer_myArray2",
                                1)

  self.Sys_i_Instance_producer_producer_myArray3_publisher_ = self.create_publisher(
                                MyArrayTwoDim,
                                "Sys_i_Instance_consumer_consumer_myArray3",
                                1)

  # timeTriggeredCaller callback timer
  self.periodTimer_ = self.create_wall_timer(1000, self.timeTriggeredCaller, callback_group=self.cb_group_)

  # Used by receiveInputs
  inDataPortTupleVector = [
   ]

  # Used by receiveInputs
  inEventPortTupleVector = [
    ]

  # Used by sendOutputs
  outPortTupleVector = [
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
  if isinstance(get_if<Boolean>(&msg), Int32):
    self.Sys_i_Instance_producer_producer_myBoolean_publisher_.publish(*typedMsg)
   else:
    this.get_logger().error("Sending out wrong type of variable on port myBoolean.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

def sendOut_myInteger(self, msg):
  if isinstance(get_if<Integer64>(&msg), Int32):
    self.Sys_i_Instance_producer_producer_myInteger_publisher_.publish(*typedMsg)
   else:
    this.get_logger().error("Sending out wrong type of variable on port myInteger.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

def sendOut_myFloat(self, msg):
  if isinstance(get_if<Float64>(&msg), Int32):
    self.Sys_i_Instance_producer_producer_myFloat_publisher_.publish(*typedMsg)
   else:
    this.get_logger().error("Sending out wrong type of variable on port myFloat.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

def sendOut_myCharacter(self, msg):
  if isinstance(get_if<Character>(&msg), Int32):
    self.Sys_i_Instance_producer_producer_myCharacter_publisher_.publish(*typedMsg)
   else:
    this.get_logger().error("Sending out wrong type of variable on port myCharacter.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

def sendOut_myString(self, msg):
  if isinstance(get_if<String>(&msg), Int32):
    self.Sys_i_Instance_producer_producer_myString_publisher_.publish(*typedMsg)
   else:
    this.get_logger().error("Sending out wrong type of variable on port myString.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

def sendOut_myInt8(self, msg):
  if isinstance(get_if<Integer8>(&msg), Int32):
    self.Sys_i_Instance_producer_producer_myInt8_publisher_.publish(*typedMsg)
   else:
    this.get_logger().error("Sending out wrong type of variable on port myInt8.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

def sendOut_myInt16(self, msg):
  if isinstance(get_if<Integer16>(&msg), Int32):
    self.Sys_i_Instance_producer_producer_myInt16_publisher_.publish(*typedMsg)
   else:
    this.get_logger().error("Sending out wrong type of variable on port myInt16.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

def sendOut_myInt32(self, msg):
  if isinstance(get_if<Integer32>(&msg), Int32):
    self.Sys_i_Instance_producer_producer_myInt32_publisher_.publish(*typedMsg)
   else:
    this.get_logger().error("Sending out wrong type of variable on port myInt32.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

def sendOut_myInt64(self, msg):
  if isinstance(get_if<Integer64>(&msg), Int32):
    self.Sys_i_Instance_producer_producer_myInt64_publisher_.publish(*typedMsg)
   else:
    this.get_logger().error("Sending out wrong type of variable on port myInt64.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

def sendOut_myUInt8(self, msg):
  if isinstance(get_if<Unsigned8>(&msg), Int32):
    self.Sys_i_Instance_producer_producer_myUInt8_publisher_.publish(*typedMsg)
   else:
    this.get_logger().error("Sending out wrong type of variable on port myUInt8.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

def sendOut_myUInt16(self, msg):
  if isinstance(get_if<Unsigned16>(&msg), Int32):
    self.Sys_i_Instance_producer_producer_myUInt16_publisher_.publish(*typedMsg)
   else:
    this.get_logger().error("Sending out wrong type of variable on port myUInt16.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

def sendOut_myUInt32(self, msg):
  if isinstance(get_if<Unsigned32>(&msg), Int32):
    self.Sys_i_Instance_producer_producer_myUInt32_publisher_.publish(*typedMsg)
   else:
    this.get_logger().error("Sending out wrong type of variable on port myUInt32.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

def sendOut_myUInt64(self, msg):
  if isinstance(get_if<Unsigned64>(&msg), Int32):
    self.Sys_i_Instance_producer_producer_myUInt64_publisher_.publish(*typedMsg)
   else:
    this.get_logger().error("Sending out wrong type of variable on port myUInt64.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

def sendOut_myFloat32(self, msg):
  if isinstance(get_if<Float32>(&msg), Int32):
    self.Sys_i_Instance_producer_producer_myFloat32_publisher_.publish(*typedMsg)
   else:
    this.get_logger().error("Sending out wrong type of variable on port myFloat32.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

def sendOut_myFloat64(self, msg):
  if isinstance(get_if<Float64>(&msg), Int32):
    self.Sys_i_Instance_producer_producer_myFloat64_publisher_.publish(*typedMsg)
   else:
    this.get_logger().error("Sending out wrong type of variable on port myFloat64.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

def sendOut_myEnum(self, msg):
  if isinstance(get_if<MyEnum>(&msg), Int32):
    self.Sys_i_Instance_producer_producer_myEnum_publisher_.publish(*typedMsg)
   else:
    this.get_logger().error("Sending out wrong type of variable on port myEnum.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

def sendOut_myStruct(self, msg):
  if isinstance(get_if<MyStructi>(&msg), Int32):
    self.Sys_i_Instance_producer_producer_myStruct_publisher_.publish(*typedMsg)
   else:
    this.get_logger().error("Sending out wrong type of variable on port myStruct.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

def sendOut_myArray1(self, msg):
  if isinstance(get_if<MyArrayOneDim>(&msg), Int32):
    self.Sys_i_Instance_producer_producer_myArray1_publisher_.publish(*typedMsg)
   else:
    this.get_logger().error("Sending out wrong type of variable on port myArray1.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

def sendOut_myArray2(self, msg):
  if isinstance(get_if<MyArrayUnbounded>(&msg), Int32):
    self.Sys_i_Instance_producer_producer_myArray2_publisher_.publish(*typedMsg)
   else:
    this.get_logger().error("Sending out wrong type of variable on port myArray2.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

def sendOut_myArray3(self, msg):
  if isinstance(get_if<MyArrayTwoDim>(&msg), Int32):
    self.Sys_i_Instance_producer_producer_myArray3_publisher_.publish(*typedMsg)
   else:
    this.get_logger().error("Sending out wrong type of variable on port myArray3.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

def put_myBoolean(self, msg):
  self.enqueue(applicationOut_myBoolean, msg)

def put_myInteger(self, msg):
  self.enqueue(applicationOut_myInteger, msg)

def put_myFloat(self, msg):
  self.enqueue(applicationOut_myFloat, msg)

def put_myCharacter(self, msg):
  self.enqueue(applicationOut_myCharacter, msg)

def put_myString(self, msg):
  self.enqueue(applicationOut_myString, msg)

def put_myInt8(self, msg):
  self.enqueue(applicationOut_myInt8, msg)

def put_myInt16(self, msg):
  self.enqueue(applicationOut_myInt16, msg)

def put_myInt32(self, msg):
  self.enqueue(applicationOut_myInt32, msg)

def put_myInt64(self, msg):
  self.enqueue(applicationOut_myInt64, msg)

def put_myUInt8(self, msg):
  self.enqueue(applicationOut_myUInt8, msg)

def put_myUInt16(self, msg):
  self.enqueue(applicationOut_myUInt16, msg)

def put_myUInt32(self, msg):
  self.enqueue(applicationOut_myUInt32, msg)

def put_myUInt64(self, msg):
  self.enqueue(applicationOut_myUInt64, msg)

def put_myFloat32(self, msg):
  self.enqueue(applicationOut_myFloat32, msg)

def put_myFloat64(self, msg):
  self.enqueue(applicationOut_myFloat64, msg)

def put_myEnum(self, msg):
  self.enqueue(applicationOut_myEnum, msg)

def put_myStruct(self, msg):
  self.enqueue(applicationOut_myStruct, msg)

def put_myArray1(self, msg):
  self.enqueue(applicationOut_myArray1, msg)

def put_myArray2(self, msg):
  self.enqueue(applicationOut_myArray2, msg)

def put_myArray3(self, msg):
  self.enqueue(applicationOut_myArray3, msg)

def timeTriggeredCaller(self):
 self.receiveInputs()
 timeTriggered()
 self.sendOutputs()

def receiveInputs(self):
 for port in inDataPortTupleVector:
   infrastructureQueue = port[0]
   if !infrastructureQueue.empty():
     msg = infrastructureQueue.front()
     self.enqueue(*port[1], msg)

 for port in inEventPortTupleVector:
   infrastructureQueue = port[0]
   if !infrastructureQueue.empty():
     msg = infrastructureQueue.front()
     infrastructureQueue.pop()
     self.enqueue(*port[1], msg)

def enqueue(self, queue, val):
 if queue.size() >= 1:
   queue.pop()
 queue.push(val)

def sendOutputs(self):
 for port in outPortTupleVector:
   applicationQueue = port[0]
   if applicationQueue.size() != 0:
     msg = applicationQueue.front()
     applicationQueue.pop()
     enqueue(*port[1], msg)

 for port in outPortTupleVector:
   infrastructureQueue = port[1]
   if infrastructureQueue.size() != 0:
     msg = infrastructureQueue.front()
     infrastructureQueue.pop()
     (this->*port[2])(msg)
