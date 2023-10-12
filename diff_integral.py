# Differentiation/Integration Calc

import sympy as sp
x, y, z = sp.symbols('x y z')
sp.init_printing(use_unicode=True)

res_diff = sp.diff(15*x**4-sp.tan(x), x)
print(res_diff)

res_int = sp.integrate(15*x**4-sp.tan(x), x)
print(res_int)