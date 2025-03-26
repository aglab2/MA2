union double_long 
{
  double d;
  struct {
      long upper;
      unsigned long lower;
    } l;
};

union float_long {
  float f;
  long l;
};

union long_double_long
{
  long double ld;
  struct
    {
      long upper;
      unsigned long middle;
      unsigned long lower;
    } l;
};

/* convert float to double */
double
__extendsfdf2 (float a1)
{
  register union float_long fl1;
  register union double_long dl;

  fl1.f = a1;
  dl.l.lower = fl1.l;
  return dl.d;
}

/* convert double to float */
float
__truncdfsf2 (double a1)
{
  register union float_long fl;
  register union double_long dl1;

  dl1.d = a1;
  fl.l = dl1.l.lower;
  return fl.f;
}
