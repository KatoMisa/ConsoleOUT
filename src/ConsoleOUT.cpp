// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  ConsoleOUT.cpp
 * @brief ModuleDescription
 *
 */
// </rtc-template>

#include "ConsoleOUT.h"

// Module specification
// <rtc-template block="module_spec">
#if RTM_MAJOR_VERSION >= 2
static const char* const consoleout_spec[] =
#else
static const char* consoleout_spec[] =
#endif
  {
    "implementation_id", "ConsoleOUT",
    "type_name",         "ConsoleOUT",
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
ConsoleOUT::ConsoleOUT(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_str_inIn("str_in", m_str_in),
    m_num_inIn("num_in", m_num_in),
    m_str_outOut("str_out", m_str_out),
    m_num_outOut("num_out", m_num_out)
    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
ConsoleOUT::~ConsoleOUT()
{
}



RTC::ReturnCode_t ConsoleOUT::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("str_in", m_str_inIn);
  addInPort("num_in", m_num_inIn);
  
  // Set OutPort buffer
  addOutPort("str_out", m_str_outOut);
  addOutPort("num_out", m_num_outOut);

  
  return RTC::RTC_OK;
}


RTC::ReturnCode_t ConsoleOUT::onActivated(RTC::UniqueId /*ec_id*/)
{
  std::cout << "Activate ";
  return RTC::RTC_OK;
}


RTC::ReturnCode_t ConsoleOUT::onDeactivated(RTC::UniqueId /*ec_id*/)
{
  std::cout << "Deactivate ";
  return RTC::RTC_OK;
}


RTC::ReturnCode_t ConsoleOUT::onExecute(RTC::UniqueId /*ec_id*/)
{
  if (m_num_inIn.isNew())
    {
     m_num_inIn.read();
     std::cout << "Received: " << m_num_in.data << std::endl;
   }  

  if (m_str_inIn.isNew())
    {
     m_str_inIn.read();
     std::cout << "Received: " << m_str_in.data << std::endl;
   }  


  return RTC::RTC_OK;
}





extern "C"
{
 
  void ConsoleOUTInit(RTC::Manager* manager)
  {
    coil::Properties profile(consoleout_spec);
    manager->registerFactory(profile,
                             RTC::Create<ConsoleOUT>,
                             RTC::Delete<ConsoleOUT>);
  }
  
}
