/*
 *  Copyright (C) 2013 Free Software Foundation, Inc.
 *
 *  introduce the fractional data type.
 *
 *  Gaius Mulley <gaius.mulley@southwales.ac.uk>
 */

#if !defined(SFRACTH)
#  define SFRACTH

#include <fract.h>
#include <iostream>

typedef enum fract_type_t {value_t, pi_t, e_t, r2_t, r3_t, r6_t,
			   add_t, sub_t, mult_t, div_t, neg_t, power_t,
			   sin_t, cos_t, tan_t} fract_type;

typedef long unsigned int longcard;

class sfract;


class sfract_data
{
 private:
  fract value;
  fract_type_t kind;
  sfract_data *left;
  sfract_data *right;
  friend std::ostream& operator<< (std::ostream& os, const sfract_data *d);
  void assign_value (sfract_data *expr);
  void assign_value (fract v);
  void assign_value (sfract expr);
  void assign (sfract expr);
  void assign_binary (sfract expr);
  void assign_unary (sfract expr);
  bool are_equal (sfract_data *l, sfract_data *r);
  bool are_equal (sfract l, sfract_data *r);
  bool are_equal (sfract_data *l, sfract r);
  bool is_rational (void);
  bool is_value (void);

#if 0
  sfract_data simplify (void);
  bool is_positive (void);
  bool is_negative (void);
  sfract_data inc (sfract_data right);
  sfract_data dec (sfract_data right);
  sfract_data negate (void);
  bool is_zero (void);
  sfract_data reciprocal (void);
#endif
 public:
  sfract_data (void);
  ~sfract_data (void);  // destructor
  sfract_data (int);
  sfract_data (int, int);
  sfract_data (longcard w);
  sfract_data (longcard n, longcard d);
  sfract_data (fract_type type, sfract_data *l, sfract_data *r);
  sfract_data (fract_type type, sfract_data *value);
  sfract_data (fract_type type);
  sfract_data (const sfract_data &from);  // copy
  sfract_data& operator= (const sfract_data &from);  // assignment
  sfract_data (sfract_data *d);

  bool map_angle (sfract_data *angle, sfract value, sfract result);
  sfract_data *dup (void);
  bool do_add (void);
  bool do_sub (void);
  bool do_mult (void);
  bool do_div (void);
  bool do_neg (void);
  bool do_power (void);
  bool do_sin (void);
  bool do_cos (void);
  bool do_tan (void);
  bool do_rules (void);
  void simplify (void);
};


class sfract
{
 private:
  friend std::ostream& operator<< (std::ostream& os, const sfract& f);
  
 public:
  sfract_data *data;
  sfract (void);
  ~sfract (void);  // destructor
  sfract (const sfract &from);  // copy
  sfract& operator= (const sfract &from);  // assignment
  sfract (int);
  sfract (int, int);
  sfract (longcard w);
  sfract (longcard n, longcard d);
  sfract (sfract_data *expr);
  sfract record (void);
  sfract unrecord (void);

  /* binary + */
  sfract operator+ (const sfract &right);
  sfract operator+ (int right);
  friend sfract operator+ (int left, const sfract &right);  // friend to int
  sfract operator+ (const fract right);
  friend sfract operator+ (fract left, const sfract &right);  // friend to int

  /* binary / */
  sfract operator/ (const sfract &right);
  sfract operator/ (int right);
  friend sfract operator/ (int left, const sfract &right);  // friend to int
  sfract operator/ (const fract right);
  friend sfract operator/ (fract left, const sfract &right);  // friend to int

  /* binary * */
  sfract operator* (const sfract &right);
  sfract operator* (int right);
  friend sfract operator* (int left, const sfract &right);  // friend to int
  sfract operator* (const fract right);
  friend sfract operator* (fract left, const sfract &right);  // friend to int

  /* binary - */
  sfract operator- (const sfract &right);
  sfract operator- (int right);
  friend sfract operator- (int left, const sfract &right);  // friend to int
  sfract operator- (const fract right);
  friend sfract operator- (fract left, const sfract &right);  // friend to int

  sfract operator- (void);     /* unary - */
  sfract operator() (void);    /* call operator */

  sfract pi (void);
  sfract r2 (void);
  sfract e (void);
  sfract r3 (void);
  sfract r6 (void);
  sfract sin (void);
  sfract cos (void);
  sfract tan (void);
};


sfract zero (void);
sfract one (void);
sfract two (void);
sfract half (void);
sfract third (void);
sfract quarter (void);

sfract pi (void);
sfract r2 (void);
sfract r3 (void);
sfract r6 (void);
sfract sin (sfract radians);
sfract cos (sfract radians);
sfract tan (sfract radians);

#endif
