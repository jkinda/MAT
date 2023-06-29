#include "materialsApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
materialsApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

materialsApp::materialsApp(InputParameters parameters) : MooseApp(parameters)
{
  materialsApp::registerAll(_factory, _action_factory, _syntax);
}

materialsApp::~materialsApp() {}

void 
materialsApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<materialsApp>(f, af, s);
  Registry::registerObjectsTo(f, {"materialsApp"});
  Registry::registerActionsTo(af, {"materialsApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
materialsApp::registerApps()
{
  registerApp(materialsApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
materialsApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  materialsApp::registerAll(f, af, s);
}
extern "C" void
materialsApp__registerApps()
{
  materialsApp::registerApps();
}
