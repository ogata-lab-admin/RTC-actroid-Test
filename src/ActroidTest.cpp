// -*- C++ -*-
/*!
 * @file  ActroidTest.cpp
 * @brief Actroid RTC
 * @date $Date$
 *
 * $Id$
 */

#include "ActroidTest.h"

// Module specification
// <rtc-template block="module_spec">
static const char* actroidtest_spec[] =
  {
    "implementation_id", "ActroidTest",
    "type_name",         "ActroidTest",
    "description",       "Actroid RTC",
    "version",           "1.0.0",
    "vendor",            "Ogata Lab",
    "category",          "Experimenta",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.debug", "1",
    "conf.default.port", "COM1",
    // Widget
    "conf.__widget__.debug", "text",
    "conf.__widget__.port", "text",
    // Constraints
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
ActroidTest::ActroidTest(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_currentJointIn("currentJoint", m_currentJoint),
    m_targetJointOut("targetJoint", m_targetJoint)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
ActroidTest::~ActroidTest()
{
}



RTC::ReturnCode_t ActroidTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("currentJoint", m_currentJointIn);
  
  // Set OutPort buffer
  addOutPort("targetJoint", m_targetJointOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("debug", m_debug, "1");
  bindParameter("port", m_port, "COM1");
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t ActroidTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ActroidTest::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ActroidTest::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t ActroidTest::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t ActroidTest::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t ActroidTest::onExecute(RTC::UniqueId ec_id)
{
	m_targetJoint.data.length(24);
	for(int i = 0;i < 24;i++) {
		m_targetJoint.data[i] = 0;
	}
	m_targetJointOut.write();
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t ActroidTest::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ActroidTest::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t ActroidTest::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t ActroidTest::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ActroidTest::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void ActroidTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(actroidtest_spec);
    manager->registerFactory(profile,
                             RTC::Create<ActroidTest>,
                             RTC::Delete<ActroidTest>);
  }
  
};


