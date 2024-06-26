// #Sireum

package tc.CoolingFan

import org.sireum._
import tc.util.Profile
import tc.util.EmptyContainer
import tc.RandomLib

// Do not edit this file as it will be overwritten if HAMR codegen is rerun

// Profile for initialise entrypoint
@msig trait Fan_s_tcproc_fan_Profile_Trait extends Profile

@record class Fan_s_tcproc_fan_Profile (
  val name: String,
) extends Fan_s_tcproc_fan_Profile_Trait {

  override def next: EmptyContainer = {
    return EmptyContainer()
  }
}

// Profile with generators for incoming ports
@msig trait Fan_s_tcproc_fan_Profile_P_Trait extends Profile {
  def api_fanCmd: RandomLib // random lib for generating CoolingFan.FanCmd
}

@record class Fan_s_tcproc_fan_Profile_P(
  val name: String,
  var api_fanCmd: RandomLib // random lib for generating CoolingFan.FanCmd
  ) extends Fan_s_tcproc_fan_Profile_P_Trait {

  override def next: Fan_s_tcproc_fan_PreState_Container_P = {
    return (Fan_s_tcproc_fan_PreState_Container_P (
      api_fanCmd = api_fanCmd.nextOptionCoolingFanFanCmdType()))
  }
}

// Profile with generators for state variables and incoming ports
@msig trait Fan_s_tcproc_fan_Profile_PS_Trait extends Fan_s_tcproc_fan_Profile_P_Trait {
  def api_fanCmd: RandomLib // random lib for generating CoolingFan.FanCmd
}

@record class Fan_s_tcproc_fan_Profile_PS(
  val name: String,
  var api_fanCmd: RandomLib // random lib for generating CoolingFan.FanCmd
  ) extends Fan_s_tcproc_fan_Profile_PS_Trait {

  override def next: Fan_s_tcproc_fan_PreState_Container_PS = {
    return (Fan_s_tcproc_fan_PreState_Container_PS (
      api_fanCmd = api_fanCmd.nextOptionCoolingFanFanCmdType()))
  }
}
