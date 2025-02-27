#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

class Sys_i_Instance_producer_producer_base(Node):
   def __init__(self):
       super().__init__("Sys_i_Instance_producer_producer")

       cb_group_ = this.create_callback_group(Reentrant)

  // Setting up connections
  self.Sys_i_Instance_producer_producer_myBoolean_publisher_ = self.create_publisher(
                                Int32,
                                "Sys_i_Instance_consumer_consumer_myBoolean",
                                1)

  self.Sys_i_Instance_producer_producer_myInteger_publisher_ = self.create_publisher(
                                Int32,
                                "Sys_i_Instance_consumer_consumer_myInteger",
                                1)

  self.Sys_i_Instance_producer_producer_myFloat_publisher_ = self.create_publisher(
                                Int32,
                                "Sys_i_Instance_consumer_consumer_myFloat",
                                1)

  self.Sys_i_Instance_producer_producer_myCharacter_publisher_ = self.create_publisher(
                                Int32,
                                "Sys_i_Instance_consumer_consumer_myCharacter",
                                1)

  self.Sys_i_Instance_producer_producer_myString_publisher_ = self.create_publisher(
                                Int32,
                                "Sys_i_Instance_consumer_consumer_myString",
                                1)

  self.Sys_i_Instance_producer_producer_myInt8_publisher_ = self.create_publisher(
                                Int32,
                                "Sys_i_Instance_consumer_consumer_myInt8",
                                1)

  self.Sys_i_Instance_producer_producer_myInt16_publisher_ = self.create_publisher(
                                Int32,
                                "Sys_i_Instance_consumer_consumer_myInt16",
                                1)

  self.Sys_i_Instance_producer_producer_myInt32_publisher_ = self.create_publisher(
                                Int32,
                                "Sys_i_Instance_consumer_consumer_myInt32",
                                1)

  self.Sys_i_Instance_producer_producer_myInt64_publisher_ = self.create_publisher(
                                Int32,
                                "Sys_i_Instance_consumer_consumer_myInt64",
                                1)

  self.Sys_i_Instance_producer_producer_myUInt8_publisher_ = self.create_publisher(
                                Int32,
                                "Sys_i_Instance_consumer_consumer_myUInt8",
                                1)

  self.Sys_i_Instance_producer_producer_myUInt16_publisher_ = self.create_publisher(
                                Int32,
                                "Sys_i_Instance_consumer_consumer_myUInt16",
                                1)

  self.Sys_i_Instance_producer_producer_myUInt32_publisher_ = self.create_publisher(
                                Int32,
                                "Sys_i_Instance_consumer_consumer_myUInt32",
                                1)

  self.Sys_i_Instance_producer_producer_myUInt64_publisher_ = self.create_publisher(
                                Int32,
                                "Sys_i_Instance_consumer_consumer_myUInt64",
                                1)

  self.Sys_i_Instance_producer_producer_myFloat32_publisher_ = self.create_publisher(
                                Int32,
                                "Sys_i_Instance_consumer_consumer_myFloat32",
                                1)

  self.Sys_i_Instance_producer_producer_myFloat64_publisher_ = self.create_publisher(
                                Int32,
                                "Sys_i_Instance_consumer_consumer_myFloat64",
                                1)

  self.Sys_i_Instance_producer_producer_myEnum_publisher_ = self.create_publisher(
                                Int32,
                                "Sys_i_Instance_consumer_consumer_myEnum",
                                1)

  self.Sys_i_Instance_producer_producer_myStruct_publisher_ = self.create_publisher(
                                Int32,
                                "Sys_i_Instance_consumer_consumer_myStruct",
                                1)

  self.Sys_i_Instance_producer_producer_myArray1_publisher_ = self.create_publisher(
                                Int32,
                                "Sys_i_Instance_consumer_consumer_myArray1",
                                1)

  self.Sys_i_Instance_producer_producer_myArray2_publisher_ = self.create_publisher(
                                Int32,
                                "Sys_i_Instance_consumer_consumer_myArray2",
                                1)

  self.Sys_i_Instance_producer_producer_myArray3_publisher_ = self.create_publisher(
                                Int32,
                                "Sys_i_Instance_consumer_consumer_myArray3",
                                1)

  // timeTriggered callback timer
  self.periodTimer_ = self.create_wall_timer(1000, self.timeTriggered, cb_group_)

//=================================================
//  C o m m u n i c a t i o n
//=================================================

def put_myBoolean(self, msg):
  self.Sys_i_Instance_producer_producer_myBoolean_publisher_.publish(msg)

def put_myInteger(self, msg):
  self.Sys_i_Instance_producer_producer_myInteger_publisher_.publish(msg)

def put_myFloat(self, msg):
  self.Sys_i_Instance_producer_producer_myFloat_publisher_.publish(msg)

def put_myCharacter(self, msg):
  self.Sys_i_Instance_producer_producer_myCharacter_publisher_.publish(msg)

def put_myString(self, msg):
  self.Sys_i_Instance_producer_producer_myString_publisher_.publish(msg)

def put_myInt8(self, msg):
  self.Sys_i_Instance_producer_producer_myInt8_publisher_.publish(msg)

def put_myInt16(self, msg):
  self.Sys_i_Instance_producer_producer_myInt16_publisher_.publish(msg)

def put_myInt32(self, msg):
  self.Sys_i_Instance_producer_producer_myInt32_publisher_.publish(msg)

def put_myInt64(self, msg):
  self.Sys_i_Instance_producer_producer_myInt64_publisher_.publish(msg)

def put_myUInt8(self, msg):
  self.Sys_i_Instance_producer_producer_myUInt8_publisher_.publish(msg)

def put_myUInt16(self, msg):
  self.Sys_i_Instance_producer_producer_myUInt16_publisher_.publish(msg)

def put_myUInt32(self, msg):
  self.Sys_i_Instance_producer_producer_myUInt32_publisher_.publish(msg)

def put_myUInt64(self, msg):
  self.Sys_i_Instance_producer_producer_myUInt64_publisher_.publish(msg)

def put_myFloat32(self, msg):
  self.Sys_i_Instance_producer_producer_myFloat32_publisher_.publish(msg)

def put_myFloat64(self, msg):
  self.Sys_i_Instance_producer_producer_myFloat64_publisher_.publish(msg)

def put_myEnum(self, msg):
  self.Sys_i_Instance_producer_producer_myEnum_publisher_.publish(msg)

def put_myStruct(self, msg):
  self.Sys_i_Instance_producer_producer_myStruct_publisher_.publish(msg)

def put_myArray1(self, msg):
  self.Sys_i_Instance_producer_producer_myArray1_publisher_.publish(msg)

def put_myArray2(self, msg):
  self.Sys_i_Instance_producer_producer_myArray2_publisher_.publish(msg)

def put_myArray3(self, msg):
  self.Sys_i_Instance_producer_producer_myArray3_publisher_.publish(msg)

