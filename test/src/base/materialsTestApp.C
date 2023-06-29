//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "materialsTestApp.h"
#include "materialsApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
materialsTestApp::validParams()
{
  InputParameters params = materialsApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

materialsTestApp::materialsTestApp(InputParameters parameters) : MooseApp(parameters)
{
  materialsTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

materialsTestApp::~materialsTestApp() {}

void
materialsTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  materialsApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"materialsTestApp"});
    Registry::registerActionsTo(af, {"materialsTestApp"});
  }
}

void
materialsTestApp::registerApps()
{
  registerApp(materialsApp);
  registerApp(materialsTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
materialsTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  materialsTestApp::registerAll(f, af, s);
}
extern "C" void
materialsTestApp__registerApps()
{
  materialsTestApp::registerApps();
}
