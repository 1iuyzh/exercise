## 4.35
```c
char cval; int ival; unsigned int uival;
float fval; double dval;
(a) cval = 'a' + 3; (b) fval = uival - ival * 1.0
(c) dval = uival * fval; (d) cval = ival + fval + dval;
```
(a) 'a' converted to int, ('a' + 3)(int) converted to char  
(b) ival and uival converted to double, (uival - ival * 1.0)(double) converted to float  
(c) uival converted to float, (uival * fval)(float) converted to double  
(d) ival converted to float, (ival + fval)(float) converted to double, that double converted to char  
