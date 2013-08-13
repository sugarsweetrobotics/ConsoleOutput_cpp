// -*- C++ -*-
/*!
 * @file  ConsoleOutput.cpp
 * @brief Console Output Component
 * @date $Date$
 *
 * $Id$
 */

#include "ConsoleOutput.h"

// Module specification
// <rtc-template block="module_spec">
static const char* consoleoutput_spec[] =
  {
    "implementation_id", "ConsoleOutput",
    "type_name",         "ConsoleOutput",
    "description",       "Console Output Component",
    "version",           "1.0.0",
    "vendor",            "Sugar Sweet Robotics",
    "category",          "Tutorial",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
ConsoleOutput::ConsoleOutput(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_inIn("in", m_in)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
ConsoleOutput::~ConsoleOutput()
{
}



RTC::ReturnCode_t ConsoleOutput::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("in", m_inIn);
  
  // Set OutPort buffer
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t ConsoleOutput::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConsoleOutput::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConsoleOutput::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t ConsoleOutput::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t ConsoleOutput::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t ConsoleOutput::onExecute(RTC::UniqueId ec_id)
{
  if(m_inIn.isNew()) {
    m_inIn.read();
    std::cout << "Received: " << m_in.data << std::endl;
  }
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t ConsoleOutput::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConsoleOutput::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConsoleOutput::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConsoleOutput::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConsoleOutput::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void ConsoleOutputInit(RTC::Manager* manager)
  {
    coil::Properties profile(consoleoutput_spec);
    manager->registerFactory(profile,
                             RTC::Create<ConsoleOutput>,
                             RTC::Delete<ConsoleOutput>);
  }
  
};


