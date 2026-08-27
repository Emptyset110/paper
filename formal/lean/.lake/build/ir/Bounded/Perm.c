// Lean compiler output
// Module: Bounded.Perm
// Imports: public import Init public meta import Init public import Bounded.Basic
#include <lean/lean.h>
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wunused-label"
#elif defined(__GNUC__) && !defined(__CLANG__)
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif
#ifdef __cplusplus
extern "C" {
#endif
lean_object* lean_nat_mod(lean_object*, lean_object*);
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
lean_object* lean_nat_to_int(lean_object*);
lean_object* lp_bounded_Bounded_finList(lean_object*);
lean_object* l_Repr_addAppParen(lean_object*, lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
static lean_once_cell_t lp_bounded_Bounded_allSlots___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_allSlots___closed__0;
LEAN_EXPORT lean_object* lp_bounded_Bounded_allSlots;
static lean_once_cell_t lp_bounded_Bounded_allKeys___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_allKeys___closed__0;
LEAN_EXPORT lean_object* lp_bounded_Bounded_allKeys;
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_ctorIdx(uint8_t);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_ctorIdx___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_toCtorIdx(uint8_t);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_toCtorIdx___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_ctorElim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_ctorElim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_ctorElim(lean_object*, lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_ctorElim___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_id_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_id_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_id_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_id_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_s01_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_s01_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_s01_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_s01_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_s02_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_s02_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_s02_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_s02_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_s12_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_s12_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_s12_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_s12_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_c012_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_c012_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_c012_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_c012_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_c021_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_c021_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_c021_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_c021_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_Perm3_ofNat(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_ofNat___boxed(lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqPerm3(uint8_t, uint8_t);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqPerm3___boxed(lean_object*, lean_object*);
static const lean_string_object lp_bounded_Bounded_instReprPerm3_repr___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 17, .m_capacity = 17, .m_length = 16, .m_data = "Bounded.Perm3.id"};
static const lean_object* lp_bounded_Bounded_instReprPerm3_repr___closed__0 = (const lean_object*)&lp_bounded_Bounded_instReprPerm3_repr___closed__0_value;
static const lean_ctor_object lp_bounded_Bounded_instReprPerm3_repr___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprPerm3_repr___closed__0_value)}};
static const lean_object* lp_bounded_Bounded_instReprPerm3_repr___closed__1 = (const lean_object*)&lp_bounded_Bounded_instReprPerm3_repr___closed__1_value;
static const lean_string_object lp_bounded_Bounded_instReprPerm3_repr___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 18, .m_capacity = 18, .m_length = 17, .m_data = "Bounded.Perm3.s01"};
static const lean_object* lp_bounded_Bounded_instReprPerm3_repr___closed__2 = (const lean_object*)&lp_bounded_Bounded_instReprPerm3_repr___closed__2_value;
static const lean_ctor_object lp_bounded_Bounded_instReprPerm3_repr___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprPerm3_repr___closed__2_value)}};
static const lean_object* lp_bounded_Bounded_instReprPerm3_repr___closed__3 = (const lean_object*)&lp_bounded_Bounded_instReprPerm3_repr___closed__3_value;
static const lean_string_object lp_bounded_Bounded_instReprPerm3_repr___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 18, .m_capacity = 18, .m_length = 17, .m_data = "Bounded.Perm3.s02"};
static const lean_object* lp_bounded_Bounded_instReprPerm3_repr___closed__4 = (const lean_object*)&lp_bounded_Bounded_instReprPerm3_repr___closed__4_value;
static const lean_ctor_object lp_bounded_Bounded_instReprPerm3_repr___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprPerm3_repr___closed__4_value)}};
static const lean_object* lp_bounded_Bounded_instReprPerm3_repr___closed__5 = (const lean_object*)&lp_bounded_Bounded_instReprPerm3_repr___closed__5_value;
static const lean_string_object lp_bounded_Bounded_instReprPerm3_repr___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 18, .m_capacity = 18, .m_length = 17, .m_data = "Bounded.Perm3.s12"};
static const lean_object* lp_bounded_Bounded_instReprPerm3_repr___closed__6 = (const lean_object*)&lp_bounded_Bounded_instReprPerm3_repr___closed__6_value;
static const lean_ctor_object lp_bounded_Bounded_instReprPerm3_repr___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprPerm3_repr___closed__6_value)}};
static const lean_object* lp_bounded_Bounded_instReprPerm3_repr___closed__7 = (const lean_object*)&lp_bounded_Bounded_instReprPerm3_repr___closed__7_value;
static const lean_string_object lp_bounded_Bounded_instReprPerm3_repr___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 19, .m_capacity = 19, .m_length = 18, .m_data = "Bounded.Perm3.c012"};
static const lean_object* lp_bounded_Bounded_instReprPerm3_repr___closed__8 = (const lean_object*)&lp_bounded_Bounded_instReprPerm3_repr___closed__8_value;
static const lean_ctor_object lp_bounded_Bounded_instReprPerm3_repr___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprPerm3_repr___closed__8_value)}};
static const lean_object* lp_bounded_Bounded_instReprPerm3_repr___closed__9 = (const lean_object*)&lp_bounded_Bounded_instReprPerm3_repr___closed__9_value;
static const lean_string_object lp_bounded_Bounded_instReprPerm3_repr___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 19, .m_capacity = 19, .m_length = 18, .m_data = "Bounded.Perm3.c021"};
static const lean_object* lp_bounded_Bounded_instReprPerm3_repr___closed__10 = (const lean_object*)&lp_bounded_Bounded_instReprPerm3_repr___closed__10_value;
static const lean_ctor_object lp_bounded_Bounded_instReprPerm3_repr___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprPerm3_repr___closed__10_value)}};
static const lean_object* lp_bounded_Bounded_instReprPerm3_repr___closed__11 = (const lean_object*)&lp_bounded_Bounded_instReprPerm3_repr___closed__11_value;
static lean_once_cell_t lp_bounded_Bounded_instReprPerm3_repr___closed__12_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_instReprPerm3_repr___closed__12;
static lean_once_cell_t lp_bounded_Bounded_instReprPerm3_repr___closed__13_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_instReprPerm3_repr___closed__13;
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprPerm3_repr(uint8_t, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprPerm3_repr___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_bounded_Bounded_instReprPerm3___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_bounded_Bounded_instReprPerm3_repr___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_bounded_Bounded_instReprPerm3___closed__0 = (const lean_object*)&lp_bounded_Bounded_instReprPerm3___closed__0_value;
LEAN_EXPORT const lean_object* lp_bounded_Bounded_instReprPerm3 = (const lean_object*)&lp_bounded_Bounded_instReprPerm3___closed__0_value;
static const lean_ctor_object lp_bounded_Bounded_instFinEnumPerm3___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(5) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_bounded_Bounded_instFinEnumPerm3___closed__0 = (const lean_object*)&lp_bounded_Bounded_instFinEnumPerm3___closed__0_value;
static const lean_ctor_object lp_bounded_Bounded_instFinEnumPerm3___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(4) << 1) | 1)),((lean_object*)&lp_bounded_Bounded_instFinEnumPerm3___closed__0_value)}};
static const lean_object* lp_bounded_Bounded_instFinEnumPerm3___closed__1 = (const lean_object*)&lp_bounded_Bounded_instFinEnumPerm3___closed__1_value;
static const lean_ctor_object lp_bounded_Bounded_instFinEnumPerm3___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(3) << 1) | 1)),((lean_object*)&lp_bounded_Bounded_instFinEnumPerm3___closed__1_value)}};
static const lean_object* lp_bounded_Bounded_instFinEnumPerm3___closed__2 = (const lean_object*)&lp_bounded_Bounded_instFinEnumPerm3___closed__2_value;
static const lean_ctor_object lp_bounded_Bounded_instFinEnumPerm3___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(2) << 1) | 1)),((lean_object*)&lp_bounded_Bounded_instFinEnumPerm3___closed__2_value)}};
static const lean_object* lp_bounded_Bounded_instFinEnumPerm3___closed__3 = (const lean_object*)&lp_bounded_Bounded_instFinEnumPerm3___closed__3_value;
static const lean_ctor_object lp_bounded_Bounded_instFinEnumPerm3___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(1) << 1) | 1)),((lean_object*)&lp_bounded_Bounded_instFinEnumPerm3___closed__3_value)}};
static const lean_object* lp_bounded_Bounded_instFinEnumPerm3___closed__4 = (const lean_object*)&lp_bounded_Bounded_instFinEnumPerm3___closed__4_value;
static const lean_ctor_object lp_bounded_Bounded_instFinEnumPerm3___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_bounded_Bounded_instFinEnumPerm3___closed__4_value)}};
static const lean_object* lp_bounded_Bounded_instFinEnumPerm3___closed__5 = (const lean_object*)&lp_bounded_Bounded_instFinEnumPerm3___closed__5_value;
LEAN_EXPORT const lean_object* lp_bounded_Bounded_instFinEnumPerm3 = (const lean_object*)&lp_bounded_Bounded_instFinEnumPerm3___closed__5_value;
static lean_once_cell_t lp_bounded_Bounded_Perm3_ap___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_Perm3_ap___closed__0;
static lean_once_cell_t lp_bounded_Bounded_Perm3_ap___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_Perm3_ap___closed__1;
static lean_once_cell_t lp_bounded_Bounded_Perm3_ap___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_Perm3_ap___closed__2;
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_ap(uint8_t, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_ap___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_Perm3_inv(uint8_t);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_inv___boxed(lean_object*);
static lean_once_cell_t lp_bounded_Bounded_swap2___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_swap2___closed__0;
static lean_once_cell_t lp_bounded_Bounded_swap2___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_swap2___closed__1;
LEAN_EXPORT lean_object* lp_bounded_Bounded_swap2(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_swap2___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_ap2(uint8_t, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_ap2___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Ren_slot(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Ren_slot___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Ren_slotInv(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Ren_slotInv___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Ren_key(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Ren_key___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Ren_val(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Ren_val___boxed(lean_object*, lean_object*);
static lean_object* _init_lp_bounded_Bounded_allSlots___closed__0(void){
_start:
{
lean_object* v___x_1_; lean_object* v___x_2_; 
v___x_1_ = lean_unsigned_to_nat(3u);
v___x_2_ = lp_bounded_Bounded_finList(v___x_1_);
return v___x_2_;
}
}
static lean_object* _init_lp_bounded_Bounded_allSlots(void){
_start:
{
lean_object* v___x_3_; 
v___x_3_ = lean_obj_once(&lp_bounded_Bounded_allSlots___closed__0, &lp_bounded_Bounded_allSlots___closed__0_once, _init_lp_bounded_Bounded_allSlots___closed__0);
return v___x_3_;
}
}
static lean_object* _init_lp_bounded_Bounded_allKeys___closed__0(void){
_start:
{
lean_object* v___x_4_; lean_object* v___x_5_; 
v___x_4_ = lean_unsigned_to_nat(2u);
v___x_5_ = lp_bounded_Bounded_finList(v___x_4_);
return v___x_5_;
}
}
static lean_object* _init_lp_bounded_Bounded_allKeys(void){
_start:
{
lean_object* v___x_6_; 
v___x_6_ = lean_obj_once(&lp_bounded_Bounded_allKeys___closed__0, &lp_bounded_Bounded_allKeys___closed__0_once, _init_lp_bounded_Bounded_allKeys___closed__0);
return v___x_6_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_ctorIdx(uint8_t v_x_7_){
_start:
{
switch(v_x_7_)
{
case 0:
{
lean_object* v___x_8_; 
v___x_8_ = lean_unsigned_to_nat(0u);
return v___x_8_;
}
case 1:
{
lean_object* v___x_9_; 
v___x_9_ = lean_unsigned_to_nat(1u);
return v___x_9_;
}
case 2:
{
lean_object* v___x_10_; 
v___x_10_ = lean_unsigned_to_nat(2u);
return v___x_10_;
}
case 3:
{
lean_object* v___x_11_; 
v___x_11_ = lean_unsigned_to_nat(3u);
return v___x_11_;
}
case 4:
{
lean_object* v___x_12_; 
v___x_12_ = lean_unsigned_to_nat(4u);
return v___x_12_;
}
default: 
{
lean_object* v___x_13_; 
v___x_13_ = lean_unsigned_to_nat(5u);
return v___x_13_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_ctorIdx___boxed(lean_object* v_x_14_){
_start:
{
uint8_t v_x_boxed_15_; lean_object* v_res_16_; 
v_x_boxed_15_ = lean_unbox(v_x_14_);
v_res_16_ = lp_bounded_Bounded_Perm3_ctorIdx(v_x_boxed_15_);
return v_res_16_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_toCtorIdx(uint8_t v_x_17_){
_start:
{
lean_object* v___x_18_; 
v___x_18_ = lp_bounded_Bounded_Perm3_ctorIdx(v_x_17_);
return v___x_18_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_toCtorIdx___boxed(lean_object* v_x_19_){
_start:
{
uint8_t v_x_4__boxed_20_; lean_object* v_res_21_; 
v_x_4__boxed_20_ = lean_unbox(v_x_19_);
v_res_21_ = lp_bounded_Bounded_Perm3_toCtorIdx(v_x_4__boxed_20_);
return v_res_21_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_ctorElim___redArg(lean_object* v_k_22_){
_start:
{
lean_inc(v_k_22_);
return v_k_22_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_ctorElim___redArg___boxed(lean_object* v_k_23_){
_start:
{
lean_object* v_res_24_; 
v_res_24_ = lp_bounded_Bounded_Perm3_ctorElim___redArg(v_k_23_);
lean_dec(v_k_23_);
return v_res_24_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_ctorElim(lean_object* v_motive_25_, lean_object* v_ctorIdx_26_, uint8_t v_t_27_, lean_object* v_h_28_, lean_object* v_k_29_){
_start:
{
lean_inc(v_k_29_);
return v_k_29_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_ctorElim___boxed(lean_object* v_motive_30_, lean_object* v_ctorIdx_31_, lean_object* v_t_32_, lean_object* v_h_33_, lean_object* v_k_34_){
_start:
{
uint8_t v_t_boxed_35_; lean_object* v_res_36_; 
v_t_boxed_35_ = lean_unbox(v_t_32_);
v_res_36_ = lp_bounded_Bounded_Perm3_ctorElim(v_motive_30_, v_ctorIdx_31_, v_t_boxed_35_, v_h_33_, v_k_34_);
lean_dec(v_k_34_);
lean_dec(v_ctorIdx_31_);
return v_res_36_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_id_elim___redArg(lean_object* v_id_37_){
_start:
{
lean_inc(v_id_37_);
return v_id_37_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_id_elim___redArg___boxed(lean_object* v_id_38_){
_start:
{
lean_object* v_res_39_; 
v_res_39_ = lp_bounded_Bounded_Perm3_id_elim___redArg(v_id_38_);
lean_dec(v_id_38_);
return v_res_39_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_id_elim(lean_object* v_motive_40_, uint8_t v_t_41_, lean_object* v_h_42_, lean_object* v_id_43_){
_start:
{
lean_inc(v_id_43_);
return v_id_43_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_id_elim___boxed(lean_object* v_motive_44_, lean_object* v_t_45_, lean_object* v_h_46_, lean_object* v_id_47_){
_start:
{
uint8_t v_t_boxed_48_; lean_object* v_res_49_; 
v_t_boxed_48_ = lean_unbox(v_t_45_);
v_res_49_ = lp_bounded_Bounded_Perm3_id_elim(v_motive_44_, v_t_boxed_48_, v_h_46_, v_id_47_);
lean_dec(v_id_47_);
return v_res_49_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_s01_elim___redArg(lean_object* v_s01_50_){
_start:
{
lean_inc(v_s01_50_);
return v_s01_50_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_s01_elim___redArg___boxed(lean_object* v_s01_51_){
_start:
{
lean_object* v_res_52_; 
v_res_52_ = lp_bounded_Bounded_Perm3_s01_elim___redArg(v_s01_51_);
lean_dec(v_s01_51_);
return v_res_52_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_s01_elim(lean_object* v_motive_53_, uint8_t v_t_54_, lean_object* v_h_55_, lean_object* v_s01_56_){
_start:
{
lean_inc(v_s01_56_);
return v_s01_56_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_s01_elim___boxed(lean_object* v_motive_57_, lean_object* v_t_58_, lean_object* v_h_59_, lean_object* v_s01_60_){
_start:
{
uint8_t v_t_boxed_61_; lean_object* v_res_62_; 
v_t_boxed_61_ = lean_unbox(v_t_58_);
v_res_62_ = lp_bounded_Bounded_Perm3_s01_elim(v_motive_57_, v_t_boxed_61_, v_h_59_, v_s01_60_);
lean_dec(v_s01_60_);
return v_res_62_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_s02_elim___redArg(lean_object* v_s02_63_){
_start:
{
lean_inc(v_s02_63_);
return v_s02_63_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_s02_elim___redArg___boxed(lean_object* v_s02_64_){
_start:
{
lean_object* v_res_65_; 
v_res_65_ = lp_bounded_Bounded_Perm3_s02_elim___redArg(v_s02_64_);
lean_dec(v_s02_64_);
return v_res_65_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_s02_elim(lean_object* v_motive_66_, uint8_t v_t_67_, lean_object* v_h_68_, lean_object* v_s02_69_){
_start:
{
lean_inc(v_s02_69_);
return v_s02_69_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_s02_elim___boxed(lean_object* v_motive_70_, lean_object* v_t_71_, lean_object* v_h_72_, lean_object* v_s02_73_){
_start:
{
uint8_t v_t_boxed_74_; lean_object* v_res_75_; 
v_t_boxed_74_ = lean_unbox(v_t_71_);
v_res_75_ = lp_bounded_Bounded_Perm3_s02_elim(v_motive_70_, v_t_boxed_74_, v_h_72_, v_s02_73_);
lean_dec(v_s02_73_);
return v_res_75_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_s12_elim___redArg(lean_object* v_s12_76_){
_start:
{
lean_inc(v_s12_76_);
return v_s12_76_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_s12_elim___redArg___boxed(lean_object* v_s12_77_){
_start:
{
lean_object* v_res_78_; 
v_res_78_ = lp_bounded_Bounded_Perm3_s12_elim___redArg(v_s12_77_);
lean_dec(v_s12_77_);
return v_res_78_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_s12_elim(lean_object* v_motive_79_, uint8_t v_t_80_, lean_object* v_h_81_, lean_object* v_s12_82_){
_start:
{
lean_inc(v_s12_82_);
return v_s12_82_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_s12_elim___boxed(lean_object* v_motive_83_, lean_object* v_t_84_, lean_object* v_h_85_, lean_object* v_s12_86_){
_start:
{
uint8_t v_t_boxed_87_; lean_object* v_res_88_; 
v_t_boxed_87_ = lean_unbox(v_t_84_);
v_res_88_ = lp_bounded_Bounded_Perm3_s12_elim(v_motive_83_, v_t_boxed_87_, v_h_85_, v_s12_86_);
lean_dec(v_s12_86_);
return v_res_88_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_c012_elim___redArg(lean_object* v_c012_89_){
_start:
{
lean_inc(v_c012_89_);
return v_c012_89_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_c012_elim___redArg___boxed(lean_object* v_c012_90_){
_start:
{
lean_object* v_res_91_; 
v_res_91_ = lp_bounded_Bounded_Perm3_c012_elim___redArg(v_c012_90_);
lean_dec(v_c012_90_);
return v_res_91_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_c012_elim(lean_object* v_motive_92_, uint8_t v_t_93_, lean_object* v_h_94_, lean_object* v_c012_95_){
_start:
{
lean_inc(v_c012_95_);
return v_c012_95_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_c012_elim___boxed(lean_object* v_motive_96_, lean_object* v_t_97_, lean_object* v_h_98_, lean_object* v_c012_99_){
_start:
{
uint8_t v_t_boxed_100_; lean_object* v_res_101_; 
v_t_boxed_100_ = lean_unbox(v_t_97_);
v_res_101_ = lp_bounded_Bounded_Perm3_c012_elim(v_motive_96_, v_t_boxed_100_, v_h_98_, v_c012_99_);
lean_dec(v_c012_99_);
return v_res_101_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_c021_elim___redArg(lean_object* v_c021_102_){
_start:
{
lean_inc(v_c021_102_);
return v_c021_102_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_c021_elim___redArg___boxed(lean_object* v_c021_103_){
_start:
{
lean_object* v_res_104_; 
v_res_104_ = lp_bounded_Bounded_Perm3_c021_elim___redArg(v_c021_103_);
lean_dec(v_c021_103_);
return v_res_104_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_c021_elim(lean_object* v_motive_105_, uint8_t v_t_106_, lean_object* v_h_107_, lean_object* v_c021_108_){
_start:
{
lean_inc(v_c021_108_);
return v_c021_108_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_c021_elim___boxed(lean_object* v_motive_109_, lean_object* v_t_110_, lean_object* v_h_111_, lean_object* v_c021_112_){
_start:
{
uint8_t v_t_boxed_113_; lean_object* v_res_114_; 
v_t_boxed_113_ = lean_unbox(v_t_110_);
v_res_114_ = lp_bounded_Bounded_Perm3_c021_elim(v_motive_109_, v_t_boxed_113_, v_h_111_, v_c021_112_);
lean_dec(v_c021_112_);
return v_res_114_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_Perm3_ofNat(lean_object* v_n_115_){
_start:
{
lean_object* v___x_116_; uint8_t v___x_117_; 
v___x_116_ = lean_unsigned_to_nat(2u);
v___x_117_ = lean_nat_dec_le(v_n_115_, v___x_116_);
if (v___x_117_ == 0)
{
lean_object* v___x_118_; uint8_t v___x_119_; 
v___x_118_ = lean_unsigned_to_nat(3u);
v___x_119_ = lean_nat_dec_le(v_n_115_, v___x_118_);
if (v___x_119_ == 0)
{
lean_object* v___x_120_; uint8_t v___x_121_; 
v___x_120_ = lean_unsigned_to_nat(4u);
v___x_121_ = lean_nat_dec_le(v_n_115_, v___x_120_);
if (v___x_121_ == 0)
{
uint8_t v___x_122_; 
v___x_122_ = 5;
return v___x_122_;
}
else
{
uint8_t v___x_123_; 
v___x_123_ = 4;
return v___x_123_;
}
}
else
{
uint8_t v___x_124_; 
v___x_124_ = 3;
return v___x_124_;
}
}
else
{
lean_object* v___x_125_; uint8_t v___x_126_; 
v___x_125_ = lean_unsigned_to_nat(0u);
v___x_126_ = lean_nat_dec_le(v_n_115_, v___x_125_);
if (v___x_126_ == 0)
{
lean_object* v___x_127_; uint8_t v___x_128_; 
v___x_127_ = lean_unsigned_to_nat(1u);
v___x_128_ = lean_nat_dec_le(v_n_115_, v___x_127_);
if (v___x_128_ == 0)
{
uint8_t v___x_129_; 
v___x_129_ = 2;
return v___x_129_;
}
else
{
uint8_t v___x_130_; 
v___x_130_ = 1;
return v___x_130_;
}
}
else
{
uint8_t v___x_131_; 
v___x_131_ = 0;
return v___x_131_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_ofNat___boxed(lean_object* v_n_132_){
_start:
{
uint8_t v_res_133_; lean_object* v_r_134_; 
v_res_133_ = lp_bounded_Bounded_Perm3_ofNat(v_n_132_);
lean_dec(v_n_132_);
v_r_134_ = lean_box(v_res_133_);
return v_r_134_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqPerm3(uint8_t v_x_135_, uint8_t v_y_136_){
_start:
{
lean_object* v___x_137_; lean_object* v___x_138_; uint8_t v___x_139_; 
v___x_137_ = lp_bounded_Bounded_Perm3_ctorIdx(v_x_135_);
v___x_138_ = lp_bounded_Bounded_Perm3_ctorIdx(v_y_136_);
v___x_139_ = lean_nat_dec_eq(v___x_137_, v___x_138_);
lean_dec(v___x_138_);
lean_dec(v___x_137_);
return v___x_139_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqPerm3___boxed(lean_object* v_x_140_, lean_object* v_y_141_){
_start:
{
uint8_t v_x_13__boxed_142_; uint8_t v_y_14__boxed_143_; uint8_t v_res_144_; lean_object* v_r_145_; 
v_x_13__boxed_142_ = lean_unbox(v_x_140_);
v_y_14__boxed_143_ = lean_unbox(v_y_141_);
v_res_144_ = lp_bounded_Bounded_instDecidableEqPerm3(v_x_13__boxed_142_, v_y_14__boxed_143_);
v_r_145_ = lean_box(v_res_144_);
return v_r_145_;
}
}
static lean_object* _init_lp_bounded_Bounded_instReprPerm3_repr___closed__12(void){
_start:
{
lean_object* v___x_164_; lean_object* v___x_165_; 
v___x_164_ = lean_unsigned_to_nat(2u);
v___x_165_ = lean_nat_to_int(v___x_164_);
return v___x_165_;
}
}
static lean_object* _init_lp_bounded_Bounded_instReprPerm3_repr___closed__13(void){
_start:
{
lean_object* v___x_166_; lean_object* v___x_167_; 
v___x_166_ = lean_unsigned_to_nat(1u);
v___x_167_ = lean_nat_to_int(v___x_166_);
return v___x_167_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprPerm3_repr(uint8_t v_x_168_, lean_object* v_prec_169_){
_start:
{
lean_object* v___y_171_; lean_object* v___y_178_; lean_object* v___y_185_; lean_object* v___y_192_; lean_object* v___y_199_; lean_object* v___y_206_; 
switch(v_x_168_)
{
case 0:
{
lean_object* v___x_212_; uint8_t v___x_213_; 
v___x_212_ = lean_unsigned_to_nat(1024u);
v___x_213_ = lean_nat_dec_le(v___x_212_, v_prec_169_);
if (v___x_213_ == 0)
{
lean_object* v___x_214_; 
v___x_214_ = lean_obj_once(&lp_bounded_Bounded_instReprPerm3_repr___closed__12, &lp_bounded_Bounded_instReprPerm3_repr___closed__12_once, _init_lp_bounded_Bounded_instReprPerm3_repr___closed__12);
v___y_171_ = v___x_214_;
goto v___jp_170_;
}
else
{
lean_object* v___x_215_; 
v___x_215_ = lean_obj_once(&lp_bounded_Bounded_instReprPerm3_repr___closed__13, &lp_bounded_Bounded_instReprPerm3_repr___closed__13_once, _init_lp_bounded_Bounded_instReprPerm3_repr___closed__13);
v___y_171_ = v___x_215_;
goto v___jp_170_;
}
}
case 1:
{
lean_object* v___x_216_; uint8_t v___x_217_; 
v___x_216_ = lean_unsigned_to_nat(1024u);
v___x_217_ = lean_nat_dec_le(v___x_216_, v_prec_169_);
if (v___x_217_ == 0)
{
lean_object* v___x_218_; 
v___x_218_ = lean_obj_once(&lp_bounded_Bounded_instReprPerm3_repr___closed__12, &lp_bounded_Bounded_instReprPerm3_repr___closed__12_once, _init_lp_bounded_Bounded_instReprPerm3_repr___closed__12);
v___y_178_ = v___x_218_;
goto v___jp_177_;
}
else
{
lean_object* v___x_219_; 
v___x_219_ = lean_obj_once(&lp_bounded_Bounded_instReprPerm3_repr___closed__13, &lp_bounded_Bounded_instReprPerm3_repr___closed__13_once, _init_lp_bounded_Bounded_instReprPerm3_repr___closed__13);
v___y_178_ = v___x_219_;
goto v___jp_177_;
}
}
case 2:
{
lean_object* v___x_220_; uint8_t v___x_221_; 
v___x_220_ = lean_unsigned_to_nat(1024u);
v___x_221_ = lean_nat_dec_le(v___x_220_, v_prec_169_);
if (v___x_221_ == 0)
{
lean_object* v___x_222_; 
v___x_222_ = lean_obj_once(&lp_bounded_Bounded_instReprPerm3_repr___closed__12, &lp_bounded_Bounded_instReprPerm3_repr___closed__12_once, _init_lp_bounded_Bounded_instReprPerm3_repr___closed__12);
v___y_185_ = v___x_222_;
goto v___jp_184_;
}
else
{
lean_object* v___x_223_; 
v___x_223_ = lean_obj_once(&lp_bounded_Bounded_instReprPerm3_repr___closed__13, &lp_bounded_Bounded_instReprPerm3_repr___closed__13_once, _init_lp_bounded_Bounded_instReprPerm3_repr___closed__13);
v___y_185_ = v___x_223_;
goto v___jp_184_;
}
}
case 3:
{
lean_object* v___x_224_; uint8_t v___x_225_; 
v___x_224_ = lean_unsigned_to_nat(1024u);
v___x_225_ = lean_nat_dec_le(v___x_224_, v_prec_169_);
if (v___x_225_ == 0)
{
lean_object* v___x_226_; 
v___x_226_ = lean_obj_once(&lp_bounded_Bounded_instReprPerm3_repr___closed__12, &lp_bounded_Bounded_instReprPerm3_repr___closed__12_once, _init_lp_bounded_Bounded_instReprPerm3_repr___closed__12);
v___y_192_ = v___x_226_;
goto v___jp_191_;
}
else
{
lean_object* v___x_227_; 
v___x_227_ = lean_obj_once(&lp_bounded_Bounded_instReprPerm3_repr___closed__13, &lp_bounded_Bounded_instReprPerm3_repr___closed__13_once, _init_lp_bounded_Bounded_instReprPerm3_repr___closed__13);
v___y_192_ = v___x_227_;
goto v___jp_191_;
}
}
case 4:
{
lean_object* v___x_228_; uint8_t v___x_229_; 
v___x_228_ = lean_unsigned_to_nat(1024u);
v___x_229_ = lean_nat_dec_le(v___x_228_, v_prec_169_);
if (v___x_229_ == 0)
{
lean_object* v___x_230_; 
v___x_230_ = lean_obj_once(&lp_bounded_Bounded_instReprPerm3_repr___closed__12, &lp_bounded_Bounded_instReprPerm3_repr___closed__12_once, _init_lp_bounded_Bounded_instReprPerm3_repr___closed__12);
v___y_199_ = v___x_230_;
goto v___jp_198_;
}
else
{
lean_object* v___x_231_; 
v___x_231_ = lean_obj_once(&lp_bounded_Bounded_instReprPerm3_repr___closed__13, &lp_bounded_Bounded_instReprPerm3_repr___closed__13_once, _init_lp_bounded_Bounded_instReprPerm3_repr___closed__13);
v___y_199_ = v___x_231_;
goto v___jp_198_;
}
}
default: 
{
lean_object* v___x_232_; uint8_t v___x_233_; 
v___x_232_ = lean_unsigned_to_nat(1024u);
v___x_233_ = lean_nat_dec_le(v___x_232_, v_prec_169_);
if (v___x_233_ == 0)
{
lean_object* v___x_234_; 
v___x_234_ = lean_obj_once(&lp_bounded_Bounded_instReprPerm3_repr___closed__12, &lp_bounded_Bounded_instReprPerm3_repr___closed__12_once, _init_lp_bounded_Bounded_instReprPerm3_repr___closed__12);
v___y_206_ = v___x_234_;
goto v___jp_205_;
}
else
{
lean_object* v___x_235_; 
v___x_235_ = lean_obj_once(&lp_bounded_Bounded_instReprPerm3_repr___closed__13, &lp_bounded_Bounded_instReprPerm3_repr___closed__13_once, _init_lp_bounded_Bounded_instReprPerm3_repr___closed__13);
v___y_206_ = v___x_235_;
goto v___jp_205_;
}
}
}
v___jp_170_:
{
lean_object* v___x_172_; lean_object* v___x_173_; uint8_t v___x_174_; lean_object* v___x_175_; lean_object* v___x_176_; 
v___x_172_ = ((lean_object*)(lp_bounded_Bounded_instReprPerm3_repr___closed__1));
lean_inc(v___y_171_);
v___x_173_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_173_, 0, v___y_171_);
lean_ctor_set(v___x_173_, 1, v___x_172_);
v___x_174_ = 0;
v___x_175_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_175_, 0, v___x_173_);
lean_ctor_set_uint8(v___x_175_, sizeof(void*)*1, v___x_174_);
v___x_176_ = l_Repr_addAppParen(v___x_175_, v_prec_169_);
return v___x_176_;
}
v___jp_177_:
{
lean_object* v___x_179_; lean_object* v___x_180_; uint8_t v___x_181_; lean_object* v___x_182_; lean_object* v___x_183_; 
v___x_179_ = ((lean_object*)(lp_bounded_Bounded_instReprPerm3_repr___closed__3));
lean_inc(v___y_178_);
v___x_180_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_180_, 0, v___y_178_);
lean_ctor_set(v___x_180_, 1, v___x_179_);
v___x_181_ = 0;
v___x_182_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_182_, 0, v___x_180_);
lean_ctor_set_uint8(v___x_182_, sizeof(void*)*1, v___x_181_);
v___x_183_ = l_Repr_addAppParen(v___x_182_, v_prec_169_);
return v___x_183_;
}
v___jp_184_:
{
lean_object* v___x_186_; lean_object* v___x_187_; uint8_t v___x_188_; lean_object* v___x_189_; lean_object* v___x_190_; 
v___x_186_ = ((lean_object*)(lp_bounded_Bounded_instReprPerm3_repr___closed__5));
lean_inc(v___y_185_);
v___x_187_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_187_, 0, v___y_185_);
lean_ctor_set(v___x_187_, 1, v___x_186_);
v___x_188_ = 0;
v___x_189_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_189_, 0, v___x_187_);
lean_ctor_set_uint8(v___x_189_, sizeof(void*)*1, v___x_188_);
v___x_190_ = l_Repr_addAppParen(v___x_189_, v_prec_169_);
return v___x_190_;
}
v___jp_191_:
{
lean_object* v___x_193_; lean_object* v___x_194_; uint8_t v___x_195_; lean_object* v___x_196_; lean_object* v___x_197_; 
v___x_193_ = ((lean_object*)(lp_bounded_Bounded_instReprPerm3_repr___closed__7));
lean_inc(v___y_192_);
v___x_194_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_194_, 0, v___y_192_);
lean_ctor_set(v___x_194_, 1, v___x_193_);
v___x_195_ = 0;
v___x_196_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_196_, 0, v___x_194_);
lean_ctor_set_uint8(v___x_196_, sizeof(void*)*1, v___x_195_);
v___x_197_ = l_Repr_addAppParen(v___x_196_, v_prec_169_);
return v___x_197_;
}
v___jp_198_:
{
lean_object* v___x_200_; lean_object* v___x_201_; uint8_t v___x_202_; lean_object* v___x_203_; lean_object* v___x_204_; 
v___x_200_ = ((lean_object*)(lp_bounded_Bounded_instReprPerm3_repr___closed__9));
lean_inc(v___y_199_);
v___x_201_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_201_, 0, v___y_199_);
lean_ctor_set(v___x_201_, 1, v___x_200_);
v___x_202_ = 0;
v___x_203_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_203_, 0, v___x_201_);
lean_ctor_set_uint8(v___x_203_, sizeof(void*)*1, v___x_202_);
v___x_204_ = l_Repr_addAppParen(v___x_203_, v_prec_169_);
return v___x_204_;
}
v___jp_205_:
{
lean_object* v___x_207_; lean_object* v___x_208_; uint8_t v___x_209_; lean_object* v___x_210_; lean_object* v___x_211_; 
v___x_207_ = ((lean_object*)(lp_bounded_Bounded_instReprPerm3_repr___closed__11));
lean_inc(v___y_206_);
v___x_208_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_208_, 0, v___y_206_);
lean_ctor_set(v___x_208_, 1, v___x_207_);
v___x_209_ = 0;
v___x_210_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_210_, 0, v___x_208_);
lean_ctor_set_uint8(v___x_210_, sizeof(void*)*1, v___x_209_);
v___x_211_ = l_Repr_addAppParen(v___x_210_, v_prec_169_);
return v___x_211_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprPerm3_repr___boxed(lean_object* v_x_236_, lean_object* v_prec_237_){
_start:
{
uint8_t v_x_345__boxed_238_; lean_object* v_res_239_; 
v_x_345__boxed_238_ = lean_unbox(v_x_236_);
v_res_239_ = lp_bounded_Bounded_instReprPerm3_repr(v_x_345__boxed_238_, v_prec_237_);
lean_dec(v_prec_237_);
return v_res_239_;
}
}
static lean_object* _init_lp_bounded_Bounded_Perm3_ap___closed__0(void){
_start:
{
lean_object* v___x_267_; lean_object* v___x_268_; lean_object* v___x_269_; 
v___x_267_ = lean_unsigned_to_nat(3u);
v___x_268_ = lean_unsigned_to_nat(1u);
v___x_269_ = lean_nat_mod(v___x_268_, v___x_267_);
return v___x_269_;
}
}
static lean_object* _init_lp_bounded_Bounded_Perm3_ap___closed__1(void){
_start:
{
lean_object* v___x_270_; lean_object* v___x_271_; lean_object* v___x_272_; 
v___x_270_ = lean_unsigned_to_nat(3u);
v___x_271_ = lean_unsigned_to_nat(0u);
v___x_272_ = lean_nat_mod(v___x_271_, v___x_270_);
return v___x_272_;
}
}
static lean_object* _init_lp_bounded_Bounded_Perm3_ap___closed__2(void){
_start:
{
lean_object* v___x_273_; lean_object* v___x_274_; lean_object* v___x_275_; 
v___x_273_ = lean_unsigned_to_nat(3u);
v___x_274_ = lean_unsigned_to_nat(2u);
v___x_275_ = lean_nat_mod(v___x_274_, v___x_273_);
return v___x_275_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_ap(uint8_t v_x_276_, lean_object* v_x_277_){
_start:
{
switch(v_x_276_)
{
case 0:
{
lean_inc(v_x_277_);
return v_x_277_;
}
case 1:
{
lean_object* v___x_290_; uint8_t v___x_291_; 
v___x_290_ = lean_unsigned_to_nat(0u);
v___x_291_ = lean_nat_dec_eq(v_x_277_, v___x_290_);
if (v___x_291_ == 0)
{
lean_object* v___x_292_; uint8_t v___x_293_; 
v___x_292_ = lean_unsigned_to_nat(1u);
v___x_293_ = lean_nat_dec_eq(v_x_277_, v___x_292_);
if (v___x_293_ == 0)
{
lean_inc(v_x_277_);
return v_x_277_;
}
else
{
goto v___jp_280_;
}
}
else
{
goto v___jp_278_;
}
}
case 2:
{
lean_object* v___x_294_; uint8_t v___x_295_; 
v___x_294_ = lean_unsigned_to_nat(0u);
v___x_295_ = lean_nat_dec_eq(v_x_277_, v___x_294_);
if (v___x_295_ == 0)
{
lean_object* v___x_296_; uint8_t v___x_297_; 
v___x_296_ = lean_unsigned_to_nat(2u);
v___x_297_ = lean_nat_dec_eq(v_x_277_, v___x_296_);
if (v___x_297_ == 0)
{
lean_inc(v_x_277_);
return v_x_277_;
}
else
{
goto v___jp_284_;
}
}
else
{
goto v___jp_282_;
}
}
case 3:
{
lean_object* v___x_298_; uint8_t v___x_299_; 
v___x_298_ = lean_unsigned_to_nat(1u);
v___x_299_ = lean_nat_dec_eq(v_x_277_, v___x_298_);
if (v___x_299_ == 0)
{
lean_object* v___x_300_; uint8_t v___x_301_; 
v___x_300_ = lean_unsigned_to_nat(2u);
v___x_301_ = lean_nat_dec_eq(v_x_277_, v___x_300_);
if (v___x_301_ == 0)
{
lean_inc(v_x_277_);
return v_x_277_;
}
else
{
goto v___jp_288_;
}
}
else
{
goto v___jp_286_;
}
}
case 4:
{
lean_object* v___x_302_; uint8_t v___x_303_; 
v___x_302_ = lean_unsigned_to_nat(0u);
v___x_303_ = lean_nat_dec_eq(v_x_277_, v___x_302_);
if (v___x_303_ == 0)
{
lean_object* v___x_304_; uint8_t v___x_305_; 
v___x_304_ = lean_unsigned_to_nat(1u);
v___x_305_ = lean_nat_dec_eq(v_x_277_, v___x_304_);
if (v___x_305_ == 0)
{
lean_object* v___x_306_; uint8_t v___x_307_; 
v___x_306_ = lean_unsigned_to_nat(2u);
v___x_307_ = lean_nat_dec_eq(v_x_277_, v___x_306_);
if (v___x_307_ == 0)
{
lean_inc(v_x_277_);
return v_x_277_;
}
else
{
goto v___jp_284_;
}
}
else
{
goto v___jp_286_;
}
}
else
{
goto v___jp_278_;
}
}
default: 
{
lean_object* v___x_308_; uint8_t v___x_309_; 
v___x_308_ = lean_unsigned_to_nat(0u);
v___x_309_ = lean_nat_dec_eq(v_x_277_, v___x_308_);
if (v___x_309_ == 0)
{
lean_object* v___x_310_; uint8_t v___x_311_; 
v___x_310_ = lean_unsigned_to_nat(1u);
v___x_311_ = lean_nat_dec_eq(v_x_277_, v___x_310_);
if (v___x_311_ == 0)
{
lean_object* v___x_312_; uint8_t v___x_313_; 
v___x_312_ = lean_unsigned_to_nat(2u);
v___x_313_ = lean_nat_dec_eq(v_x_277_, v___x_312_);
if (v___x_313_ == 0)
{
lean_inc(v_x_277_);
return v_x_277_;
}
else
{
goto v___jp_288_;
}
}
else
{
goto v___jp_280_;
}
}
else
{
goto v___jp_282_;
}
}
}
v___jp_278_:
{
lean_object* v___x_279_; 
v___x_279_ = lean_obj_once(&lp_bounded_Bounded_Perm3_ap___closed__0, &lp_bounded_Bounded_Perm3_ap___closed__0_once, _init_lp_bounded_Bounded_Perm3_ap___closed__0);
return v___x_279_;
}
v___jp_280_:
{
lean_object* v___x_281_; 
v___x_281_ = lean_obj_once(&lp_bounded_Bounded_Perm3_ap___closed__1, &lp_bounded_Bounded_Perm3_ap___closed__1_once, _init_lp_bounded_Bounded_Perm3_ap___closed__1);
return v___x_281_;
}
v___jp_282_:
{
lean_object* v___x_283_; 
v___x_283_ = lean_obj_once(&lp_bounded_Bounded_Perm3_ap___closed__2, &lp_bounded_Bounded_Perm3_ap___closed__2_once, _init_lp_bounded_Bounded_Perm3_ap___closed__2);
return v___x_283_;
}
v___jp_284_:
{
lean_object* v___x_285_; 
v___x_285_ = lean_obj_once(&lp_bounded_Bounded_Perm3_ap___closed__1, &lp_bounded_Bounded_Perm3_ap___closed__1_once, _init_lp_bounded_Bounded_Perm3_ap___closed__1);
return v___x_285_;
}
v___jp_286_:
{
lean_object* v___x_287_; 
v___x_287_ = lean_obj_once(&lp_bounded_Bounded_Perm3_ap___closed__2, &lp_bounded_Bounded_Perm3_ap___closed__2_once, _init_lp_bounded_Bounded_Perm3_ap___closed__2);
return v___x_287_;
}
v___jp_288_:
{
lean_object* v___x_289_; 
v___x_289_ = lean_obj_once(&lp_bounded_Bounded_Perm3_ap___closed__0, &lp_bounded_Bounded_Perm3_ap___closed__0_once, _init_lp_bounded_Bounded_Perm3_ap___closed__0);
return v___x_289_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_ap___boxed(lean_object* v_x_314_, lean_object* v_x_315_){
_start:
{
uint8_t v_x_331__boxed_316_; lean_object* v_res_317_; 
v_x_331__boxed_316_ = lean_unbox(v_x_314_);
v_res_317_ = lp_bounded_Bounded_Perm3_ap(v_x_331__boxed_316_, v_x_315_);
lean_dec(v_x_315_);
return v_res_317_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_Perm3_inv(uint8_t v_x_318_){
_start:
{
switch(v_x_318_)
{
case 4:
{
uint8_t v___x_319_; 
v___x_319_ = 5;
return v___x_319_;
}
case 5:
{
uint8_t v___x_320_; 
v___x_320_ = 4;
return v___x_320_;
}
default: 
{
return v_x_318_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Perm3_inv___boxed(lean_object* v_x_321_){
_start:
{
uint8_t v_x_46__boxed_322_; uint8_t v_res_323_; lean_object* v_r_324_; 
v_x_46__boxed_322_ = lean_unbox(v_x_321_);
v_res_323_ = lp_bounded_Bounded_Perm3_inv(v_x_46__boxed_322_);
v_r_324_ = lean_box(v_res_323_);
return v_r_324_;
}
}
static lean_object* _init_lp_bounded_Bounded_swap2___closed__0(void){
_start:
{
lean_object* v___x_325_; lean_object* v___x_326_; lean_object* v___x_327_; 
v___x_325_ = lean_unsigned_to_nat(2u);
v___x_326_ = lean_unsigned_to_nat(0u);
v___x_327_ = lean_nat_mod(v___x_326_, v___x_325_);
return v___x_327_;
}
}
static lean_object* _init_lp_bounded_Bounded_swap2___closed__1(void){
_start:
{
lean_object* v___x_328_; lean_object* v___x_329_; lean_object* v___x_330_; 
v___x_328_ = lean_unsigned_to_nat(2u);
v___x_329_ = lean_unsigned_to_nat(1u);
v___x_330_ = lean_nat_mod(v___x_329_, v___x_328_);
return v___x_330_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_swap2(lean_object* v_x_331_){
_start:
{
lean_object* v___x_332_; uint8_t v___x_333_; 
v___x_332_ = lean_unsigned_to_nat(0u);
v___x_333_ = lean_nat_dec_eq(v_x_331_, v___x_332_);
if (v___x_333_ == 0)
{
lean_object* v___x_334_; uint8_t v___x_335_; 
v___x_334_ = lean_unsigned_to_nat(1u);
v___x_335_ = lean_nat_dec_eq(v_x_331_, v___x_334_);
if (v___x_335_ == 0)
{
lean_inc(v_x_331_);
return v_x_331_;
}
else
{
lean_object* v___x_336_; 
v___x_336_ = lean_obj_once(&lp_bounded_Bounded_swap2___closed__0, &lp_bounded_Bounded_swap2___closed__0_once, _init_lp_bounded_Bounded_swap2___closed__0);
return v___x_336_;
}
}
else
{
lean_object* v___x_337_; 
v___x_337_ = lean_obj_once(&lp_bounded_Bounded_swap2___closed__1, &lp_bounded_Bounded_swap2___closed__1_once, _init_lp_bounded_Bounded_swap2___closed__1);
return v___x_337_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_swap2___boxed(lean_object* v_x_338_){
_start:
{
lean_object* v_res_339_; 
v_res_339_ = lp_bounded_Bounded_swap2(v_x_338_);
lean_dec(v_x_338_);
return v_res_339_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_ap2(uint8_t v_b_340_, lean_object* v_k_341_){
_start:
{
if (v_b_340_ == 0)
{
lean_inc(v_k_341_);
return v_k_341_;
}
else
{
lean_object* v___x_342_; 
v___x_342_ = lp_bounded_Bounded_swap2(v_k_341_);
return v___x_342_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_ap2___boxed(lean_object* v_b_343_, lean_object* v_k_344_){
_start:
{
uint8_t v_b_boxed_345_; lean_object* v_res_346_; 
v_b_boxed_345_ = lean_unbox(v_b_343_);
v_res_346_ = lp_bounded_Bounded_ap2(v_b_boxed_345_, v_k_344_);
lean_dec(v_k_344_);
return v_res_346_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Ren_slot(lean_object* v_r_347_, lean_object* v_n_348_){
_start:
{
uint8_t v_sp_349_; lean_object* v___x_350_; 
v_sp_349_ = lean_ctor_get_uint8(v_r_347_, 0);
v___x_350_ = lp_bounded_Bounded_Perm3_ap(v_sp_349_, v_n_348_);
return v___x_350_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Ren_slot___boxed(lean_object* v_r_351_, lean_object* v_n_352_){
_start:
{
lean_object* v_res_353_; 
v_res_353_ = lp_bounded_Bounded_Ren_slot(v_r_351_, v_n_352_);
lean_dec(v_n_352_);
lean_dec_ref(v_r_351_);
return v_res_353_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Ren_slotInv(lean_object* v_r_354_, lean_object* v_n_355_){
_start:
{
uint8_t v_sp_356_; uint8_t v___x_357_; lean_object* v___x_358_; 
v_sp_356_ = lean_ctor_get_uint8(v_r_354_, 0);
v___x_357_ = lp_bounded_Bounded_Perm3_inv(v_sp_356_);
v___x_358_ = lp_bounded_Bounded_Perm3_ap(v___x_357_, v_n_355_);
return v___x_358_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Ren_slotInv___boxed(lean_object* v_r_359_, lean_object* v_n_360_){
_start:
{
lean_object* v_res_361_; 
v_res_361_ = lp_bounded_Bounded_Ren_slotInv(v_r_359_, v_n_360_);
lean_dec(v_n_360_);
lean_dec_ref(v_r_359_);
return v_res_361_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Ren_key(lean_object* v_r_362_, lean_object* v_k_363_){
_start:
{
uint8_t v_kp_364_; lean_object* v___x_365_; 
v_kp_364_ = lean_ctor_get_uint8(v_r_362_, 1);
v___x_365_ = lp_bounded_Bounded_ap2(v_kp_364_, v_k_363_);
return v___x_365_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Ren_key___boxed(lean_object* v_r_366_, lean_object* v_k_367_){
_start:
{
lean_object* v_res_368_; 
v_res_368_ = lp_bounded_Bounded_Ren_key(v_r_366_, v_k_367_);
lean_dec(v_k_367_);
lean_dec_ref(v_r_366_);
return v_res_368_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Ren_val(lean_object* v_r_369_, lean_object* v_v_370_){
_start:
{
uint8_t v_vp_371_; lean_object* v___x_372_; 
v_vp_371_ = lean_ctor_get_uint8(v_r_369_, 2);
v___x_372_ = lp_bounded_Bounded_ap2(v_vp_371_, v_v_370_);
return v___x_372_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Ren_val___boxed(lean_object* v_r_373_, lean_object* v_v_374_){
_start:
{
lean_object* v_res_375_; 
v_res_375_ = lp_bounded_Bounded_Ren_val(v_r_373_, v_v_374_);
lean_dec(v_v_374_);
lean_dec_ref(v_r_373_);
return v_res_375_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_bounded_Bounded_Basic(uint8_t builtin);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_bounded_Bounded_Perm(uint8_t builtin) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_bounded_Bounded_Basic(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
lp_bounded_Bounded_allSlots = _init_lp_bounded_Bounded_allSlots();
lean_mark_persistent(lp_bounded_Bounded_allSlots);
lp_bounded_Bounded_allKeys = _init_lp_bounded_Bounded_allKeys();
lean_mark_persistent(lp_bounded_Bounded_allKeys);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
