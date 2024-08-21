// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  ConsoleOUTTest.cpp
 * @brief ModuleDescription (test code)
 *
 */
// </rtc-template>

#include "ConsoleOUTTest.h"

// Module specification
// <rtc-template block="module_spec">
#if RTM_MAJOR_VERSION >= 2
static const char* const consoleout_spec[] =
#else
static const char* consoleout_spec[] =
#endif
  {
    "implementation_id", "ConsoleOUTTest",
    "type_name",         "ConsoleOUTTest",
    "description",       "ModuleDescription",
    "version",           "1.0.0",
    "vendor",            "VenderName",
    "category",          "Test",
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
ConsoleOUTTest::ConsoleOUTTest(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_str_inOut("str_in", m_str_in),
    m_num_inOut("num_in", m_num_in),
    m_str_outIn("str_out", m_str_out),
    m_num_outIn("num_out", m_num_out)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
ConsoleOUTTest::~ConsoleOUTTest()
{
}



RTC::ReturnCode_t ConsoleOUTTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("str_out", m_str_outIn);
  addInPort("num_out", m_num_outIn);
  
  // Set OutPort buffer
  addOutPort("str_in", m_str_inOut);
  addOutPort("num_in", m_num_inOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t ConsoleOUTTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/


//RTC::ReturnCode_t ConsoleOUTTest::onStartup(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t ConsoleOUTTest::onShutdown(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


RTC::ReturnCode_t ConsoleOUTTest::onActivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t ConsoleOUTTest::onDeactivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t ConsoleOUTTest::onExecute(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


//RTC::ReturnCode_t ConsoleOUTTest::onAborting(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t ConsoleOUTTest::onError(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t ConsoleOUTTest::onReset(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t ConsoleOUTTest::onStateUpdate(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t ConsoleOUTTest::onRateChanged(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


bool ConsoleOUTTest::runTest()
{
    return true;
}


extern "C"
{
 
  void ConsoleOUTTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(consoleout_spec);
    manager->registerFactory(profile,
                             RTC::Create<ConsoleOUTTest>,
                             RTC::Delete<ConsoleOUTTest>);
  }
  
}
