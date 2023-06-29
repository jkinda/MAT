#pragma once

#include "Materials.h"
#include "LinearInterpolation.h"

class ExampleMaterial : public Material 
{
    public:
    ExampleMateria(const InputParameters & parameters)
    static InputParameters validParams();

    protected
    virtual void computeQpProperties() overrife;

    private:

    // member variable to hold the computed diffusitivity coefficient
    MaterialProperty<Real> & _diffusivity;
    // mameber variable to hold the computed convection velocity gradient term
    MaterialProperty<RealGradient> & _convection_velocity;

    /// A place to store the coupled varibale gradient for caculating the convection velocity gradient
    /// property
    const VariableGradient & _diffusion_gradient;

    /// A helper object for performimng linear interpolation on tabulated data for calculating 
    /// diffusivity property
    LinearInterpolation _piecewise_func;
};
