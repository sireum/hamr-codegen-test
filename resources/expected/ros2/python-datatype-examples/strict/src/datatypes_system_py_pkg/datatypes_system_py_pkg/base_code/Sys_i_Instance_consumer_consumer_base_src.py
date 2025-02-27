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

class Sys_i_Instance_consumer_consumer_base(Node):
   def __init__(self):
       super().__init__("Sys_i_Instance_consumer_consumer")

       cb_group_ = this.create_callback_group(Reentrant)

    MsgType = Union[Boolean, Integer64, Float64, Character, String, Integer8, Integer16, Integer32, Unsigned8, Unsigned16, Unsigned32, Unsigned64, Float32, MyEnum, MyStructi, MyArrayOneDim, MyArrayUnbounded, MyArrayTwoDim]

  subscription_options_.callback_group = cb_group_

  # Setting up connections
  self.Sys_i_Instance_consumer_consumer_myBoolean_subscription_ = self.create_subscription(
                                    Boolean,
                                    "Sys_i_Instance_consumer_consumer_myBoolean",
                                    self.self.enqueue(infrastructureIn_myBoolean, msg);
                                         std::thread([this]() {
                                             threading.Lock()
                                             self.receiveInputs(infrastructureIn_myBoolean, applicationIn_myBoolean);
                                             if (applicationIn_myBoolean.empty()) return;
                                             self.handle_myBoolean_base(applicationIn_myBoolean.front());
                                             applicationIn_myBoolean.pop();
                                             self.sendOutputs();
                                         }).detach();,
                                    1,
                                    callback_group=self.subscription_options_)

  self.Sys_i_Instance_consumer_consumer_myInteger_subscription_ = self.create_subscription(
                                    Integer64,
                                    "Sys_i_Instance_consumer_consumer_myInteger",
                                    self.self.enqueue(infrastructureIn_myInteger, msg);
                                         std::thread([this]() {
                                             threading.Lock()
                                             self.receiveInputs(infrastructureIn_myInteger, applicationIn_myInteger);
                                             if (applicationIn_myInteger.empty()) return;
                                             self.handle_myInteger_base(applicationIn_myInteger.front());
                                             applicationIn_myInteger.pop();
                                             self.sendOutputs();
                                         }).detach();,
                                    1,
                                    callback_group=self.subscription_options_)

  self.Sys_i_Instance_consumer_consumer_myFloat_subscription_ = self.create_subscription(
                                    Float64,
                                    "Sys_i_Instance_consumer_consumer_myFloat",
                                    self.self.enqueue(infrastructureIn_myFloat, msg);
                                         std::thread([this]() {
                                             threading.Lock()
                                             self.receiveInputs(infrastructureIn_myFloat, applicationIn_myFloat);
                                             if (applicationIn_myFloat.empty()) return;
                                             self.handle_myFloat_base(applicationIn_myFloat.front());
                                             applicationIn_myFloat.pop();
                                             self.sendOutputs();
                                         }).detach();,
                                    1,
                                    callback_group=self.subscription_options_)

  self.Sys_i_Instance_consumer_consumer_myCharacter_subscription_ = self.create_subscription(
                                    Character,
                                    "Sys_i_Instance_consumer_consumer_myCharacter",
                                    self.self.enqueue(infrastructureIn_myCharacter, msg);
                                         std::thread([this]() {
                                             threading.Lock()
                                             self.receiveInputs(infrastructureIn_myCharacter, applicationIn_myCharacter);
                                             if (applicationIn_myCharacter.empty()) return;
                                             self.handle_myCharacter_base(applicationIn_myCharacter.front());
                                             applicationIn_myCharacter.pop();
                                             self.sendOutputs();
                                         }).detach();,
                                    1,
                                    callback_group=self.subscription_options_)

  self.Sys_i_Instance_consumer_consumer_myString_subscription_ = self.create_subscription(
                                    String,
                                    "Sys_i_Instance_consumer_consumer_myString",
                                    self.self.enqueue(infrastructureIn_myString, msg);
                                         std::thread([this]() {
                                             threading.Lock()
                                             self.receiveInputs(infrastructureIn_myString, applicationIn_myString);
                                             if (applicationIn_myString.empty()) return;
                                             self.handle_myString_base(applicationIn_myString.front());
                                             applicationIn_myString.pop();
                                             self.sendOutputs();
                                         }).detach();,
                                    1,
                                    callback_group=self.subscription_options_)

  self.Sys_i_Instance_consumer_consumer_myInt8_subscription_ = self.create_subscription(
                                    Integer8,
                                    "Sys_i_Instance_consumer_consumer_myInt8",
                                    self.self.enqueue(infrastructureIn_myInt8, msg);
                                         std::thread([this]() {
                                             threading.Lock()
                                             self.receiveInputs(infrastructureIn_myInt8, applicationIn_myInt8);
                                             if (applicationIn_myInt8.empty()) return;
                                             self.handle_myInt8_base(applicationIn_myInt8.front());
                                             applicationIn_myInt8.pop();
                                             self.sendOutputs();
                                         }).detach();,
                                    1,
                                    callback_group=self.subscription_options_)

  self.Sys_i_Instance_consumer_consumer_myInt16_subscription_ = self.create_subscription(
                                    Integer16,
                                    "Sys_i_Instance_consumer_consumer_myInt16",
                                    self.self.enqueue(infrastructureIn_myInt16, msg);
                                         std::thread([this]() {
                                             threading.Lock()
                                             self.receiveInputs(infrastructureIn_myInt16, applicationIn_myInt16);
                                             if (applicationIn_myInt16.empty()) return;
                                             self.handle_myInt16_base(applicationIn_myInt16.front());
                                             applicationIn_myInt16.pop();
                                             self.sendOutputs();
                                         }).detach();,
                                    1,
                                    callback_group=self.subscription_options_)

  self.Sys_i_Instance_consumer_consumer_myInt32_subscription_ = self.create_subscription(
                                    Integer32,
                                    "Sys_i_Instance_consumer_consumer_myInt32",
                                    self.self.enqueue(infrastructureIn_myInt32, msg);
                                         std::thread([this]() {
                                             threading.Lock()
                                             self.receiveInputs(infrastructureIn_myInt32, applicationIn_myInt32);
                                             if (applicationIn_myInt32.empty()) return;
                                             self.handle_myInt32_base(applicationIn_myInt32.front());
                                             applicationIn_myInt32.pop();
                                             self.sendOutputs();
                                         }).detach();,
                                    1,
                                    callback_group=self.subscription_options_)

  self.Sys_i_Instance_consumer_consumer_myInt64_subscription_ = self.create_subscription(
                                    Integer64,
                                    "Sys_i_Instance_consumer_consumer_myInt64",
                                    self.self.enqueue(infrastructureIn_myInt64, msg);
                                         std::thread([this]() {
                                             threading.Lock()
                                             self.receiveInputs(infrastructureIn_myInt64, applicationIn_myInt64);
                                             if (applicationIn_myInt64.empty()) return;
                                             self.handle_myInt64_base(applicationIn_myInt64.front());
                                             applicationIn_myInt64.pop();
                                             self.sendOutputs();
                                         }).detach();,
                                    1,
                                    callback_group=self.subscription_options_)

  self.Sys_i_Instance_consumer_consumer_myUInt8_subscription_ = self.create_subscription(
                                    Unsigned8,
                                    "Sys_i_Instance_consumer_consumer_myUInt8",
                                    self.self.enqueue(infrastructureIn_myUInt8, msg);
                                         std::thread([this]() {
                                             threading.Lock()
                                             self.receiveInputs(infrastructureIn_myUInt8, applicationIn_myUInt8);
                                             if (applicationIn_myUInt8.empty()) return;
                                             self.handle_myUInt8_base(applicationIn_myUInt8.front());
                                             applicationIn_myUInt8.pop();
                                             self.sendOutputs();
                                         }).detach();,
                                    1,
                                    callback_group=self.subscription_options_)

  self.Sys_i_Instance_consumer_consumer_myUInt16_subscription_ = self.create_subscription(
                                    Unsigned16,
                                    "Sys_i_Instance_consumer_consumer_myUInt16",
                                    self.self.enqueue(infrastructureIn_myUInt16, msg);
                                         std::thread([this]() {
                                             threading.Lock()
                                             self.receiveInputs(infrastructureIn_myUInt16, applicationIn_myUInt16);
                                             if (applicationIn_myUInt16.empty()) return;
                                             self.handle_myUInt16_base(applicationIn_myUInt16.front());
                                             applicationIn_myUInt16.pop();
                                             self.sendOutputs();
                                         }).detach();,
                                    1,
                                    callback_group=self.subscription_options_)

  self.Sys_i_Instance_consumer_consumer_myUInt32_subscription_ = self.create_subscription(
                                    Unsigned32,
                                    "Sys_i_Instance_consumer_consumer_myUInt32",
                                    self.self.enqueue(infrastructureIn_myUInt32, msg);
                                         std::thread([this]() {
                                             threading.Lock()
                                             self.receiveInputs(infrastructureIn_myUInt32, applicationIn_myUInt32);
                                             if (applicationIn_myUInt32.empty()) return;
                                             self.handle_myUInt32_base(applicationIn_myUInt32.front());
                                             applicationIn_myUInt32.pop();
                                             self.sendOutputs();
                                         }).detach();,
                                    1,
                                    callback_group=self.subscription_options_)

  self.Sys_i_Instance_consumer_consumer_myUInt64_subscription_ = self.create_subscription(
                                    Unsigned64,
                                    "Sys_i_Instance_consumer_consumer_myUInt64",
                                    self.self.enqueue(infrastructureIn_myUInt64, msg);
                                         std::thread([this]() {
                                             threading.Lock()
                                             self.receiveInputs(infrastructureIn_myUInt64, applicationIn_myUInt64);
                                             if (applicationIn_myUInt64.empty()) return;
                                             self.handle_myUInt64_base(applicationIn_myUInt64.front());
                                             applicationIn_myUInt64.pop();
                                             self.sendOutputs();
                                         }).detach();,
                                    1,
                                    callback_group=self.subscription_options_)

  self.Sys_i_Instance_consumer_consumer_myFloat32_subscription_ = self.create_subscription(
                                    Float32,
                                    "Sys_i_Instance_consumer_consumer_myFloat32",
                                    self.self.enqueue(infrastructureIn_myFloat32, msg);
                                         std::thread([this]() {
                                             threading.Lock()
                                             self.receiveInputs(infrastructureIn_myFloat32, applicationIn_myFloat32);
                                             if (applicationIn_myFloat32.empty()) return;
                                             self.handle_myFloat32_base(applicationIn_myFloat32.front());
                                             applicationIn_myFloat32.pop();
                                             self.sendOutputs();
                                         }).detach();,
                                    1,
                                    callback_group=self.subscription_options_)

  self.Sys_i_Instance_consumer_consumer_myFloat64_subscription_ = self.create_subscription(
                                    Float64,
                                    "Sys_i_Instance_consumer_consumer_myFloat64",
                                    self.self.enqueue(infrastructureIn_myFloat64, msg);
                                         std::thread([this]() {
                                             threading.Lock()
                                             self.receiveInputs(infrastructureIn_myFloat64, applicationIn_myFloat64);
                                             if (applicationIn_myFloat64.empty()) return;
                                             self.handle_myFloat64_base(applicationIn_myFloat64.front());
                                             applicationIn_myFloat64.pop();
                                             self.sendOutputs();
                                         }).detach();,
                                    1,
                                    callback_group=self.subscription_options_)

  self.Sys_i_Instance_consumer_consumer_myEnum_subscription_ = self.create_subscription(
                                    MyEnum,
                                    "Sys_i_Instance_consumer_consumer_myEnum",
                                    self.self.enqueue(infrastructureIn_myEnum, msg);
                                         std::thread([this]() {
                                             threading.Lock()
                                             self.receiveInputs(infrastructureIn_myEnum, applicationIn_myEnum);
                                             if (applicationIn_myEnum.empty()) return;
                                             self.handle_myEnum_base(applicationIn_myEnum.front());
                                             applicationIn_myEnum.pop();
                                             self.sendOutputs();
                                         }).detach();,
                                    1,
                                    callback_group=self.subscription_options_)

  self.Sys_i_Instance_consumer_consumer_myStruct_subscription_ = self.create_subscription(
                                    MyStructi,
                                    "Sys_i_Instance_consumer_consumer_myStruct",
                                    self.self.enqueue(infrastructureIn_myStruct, msg);
                                         std::thread([this]() {
                                             threading.Lock()
                                             self.receiveInputs(infrastructureIn_myStruct, applicationIn_myStruct);
                                             if (applicationIn_myStruct.empty()) return;
                                             self.handle_myStruct_base(applicationIn_myStruct.front());
                                             applicationIn_myStruct.pop();
                                             self.sendOutputs();
                                         }).detach();,
                                    1,
                                    callback_group=self.subscription_options_)

  self.Sys_i_Instance_consumer_consumer_myArray1_subscription_ = self.create_subscription(
                                    MyArrayOneDim,
                                    "Sys_i_Instance_consumer_consumer_myArray1",
                                    self.self.enqueue(infrastructureIn_myArray1, msg);
                                         std::thread([this]() {
                                             threading.Lock()
                                             self.receiveInputs(infrastructureIn_myArray1, applicationIn_myArray1);
                                             if (applicationIn_myArray1.empty()) return;
                                             self.handle_myArray1_base(applicationIn_myArray1.front());
                                             applicationIn_myArray1.pop();
                                             self.sendOutputs();
                                         }).detach();,
                                    1,
                                    callback_group=self.subscription_options_)

  self.Sys_i_Instance_consumer_consumer_myArray2_subscription_ = self.create_subscription(
                                    MyArrayUnbounded,
                                    "Sys_i_Instance_consumer_consumer_myArray2",
                                    self.self.enqueue(infrastructureIn_myArray2, msg);
                                         std::thread([this]() {
                                             threading.Lock()
                                             self.receiveInputs(infrastructureIn_myArray2, applicationIn_myArray2);
                                             if (applicationIn_myArray2.empty()) return;
                                             self.handle_myArray2_base(applicationIn_myArray2.front());
                                             applicationIn_myArray2.pop();
                                             self.sendOutputs();
                                         }).detach();,
                                    1,
                                    callback_group=self.subscription_options_)

  self.Sys_i_Instance_consumer_consumer_myArray3_subscription_ = self.create_subscription(
                                    MyArrayTwoDim,
                                    "Sys_i_Instance_consumer_consumer_myArray3",
                                    self.self.enqueue(infrastructureIn_myArray3, msg);
                                         std::thread([this]() {
                                             threading.Lock()
                                             self.receiveInputs(infrastructureIn_myArray3, applicationIn_myArray3);
                                             if (applicationIn_myArray3.empty()) return;
                                             self.handle_myArray3_base(applicationIn_myArray3.front());
                                             applicationIn_myArray3.pop();
                                             self.sendOutputs();
                                         }).detach();,
                                    1,
                                    callback_group=self.subscription_options_)

  # Used by receiveInputs
  inDataPortTupleVector = [
   ]

  # Used by sendOutputs
  outPortTupleVector = [
   ]

def receiveInputs(self, infrastructureQueue, applicationQueue):
 if !infrastructureQueue.empty():
   eventMsg = infrastructureQueue.front()
   infrastructureQueue.pop()
   self.enqueue(applicationQueue, eventMsg)

 for port in inDataPortTupleVector:
   infrastructureQueue = port[0]
   if !infrastructureQueue.empty():
      msg = infrastructureQueue.front()
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
