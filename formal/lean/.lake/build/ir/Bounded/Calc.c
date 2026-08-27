// Lean compiler output
// Module: Bounded.Calc
// Imports: public import Init public meta import Init public import Bounded.Perm
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
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
extern lean_object* lp_bounded_Bounded_allKeys;
extern lean_object* lp_bounded_Bounded_allSlots;
lean_object* lean_nat_mod(lean_object*, lean_object*);
lean_object* l_instDecidableEqFin___boxed(lean_object*, lean_object*, lean_object*);
uint8_t l_Option_instDecidableEq___redArg(lean_object*, lean_object*, lean_object*);
lean_object* lean_mk_empty_array_with_capacity(lean_object*);
uint64_t lean_uint64_mix_hash(uint64_t, uint64_t);
uint64_t lean_uint64_of_nat(lean_object*);
lean_object* lp_bounded_Bounded_finList(lean_object*);
lean_object* l_List_mapTR_loop___redArg(lean_object*, lean_object*, lean_object*);
lean_object* l___private_Init_Data_List_Impl_0__List_flatMapTR_go___redArg(lean_object*, lean_object*, lean_object*);
uint8_t l_instDecidableEqList___redArg(lean_object*, lean_object*, lean_object*);
lean_object* l_Nat_reprFast(lean_object*);
lean_object* l_Repr_addAppParen(lean_object*, lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
lean_object* lean_nat_to_int(lean_object*);
uint8_t l_Nat_decidableForallFin___redArg(lean_object*, lean_object*);
lean_object* lean_string_length(lean_object*);
lean_object* l_Bool_repr___redArg(uint8_t);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
lean_object* l_List_appendTR___redArg(lean_object*, lean_object*);
lean_object* lean_nat_sub(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqKMap_decEq___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqKMap_decEq___redArg___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqKMap_decEq(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqKMap_decEq___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqKMap___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqKMap___redArg___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqKMap(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqKMap___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object lp_bounded_Bounded_instReprKMap_repr___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "{ "};
static const lean_object* lp_bounded_Bounded_instReprKMap_repr___redArg___closed__0 = (const lean_object*)&lp_bounded_Bounded_instReprKMap_repr___redArg___closed__0_value;
static const lean_string_object lp_bounded_Bounded_instReprKMap_repr___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "k0"};
static const lean_object* lp_bounded_Bounded_instReprKMap_repr___redArg___closed__1 = (const lean_object*)&lp_bounded_Bounded_instReprKMap_repr___redArg___closed__1_value;
static const lean_ctor_object lp_bounded_Bounded_instReprKMap_repr___redArg___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprKMap_repr___redArg___closed__1_value)}};
static const lean_object* lp_bounded_Bounded_instReprKMap_repr___redArg___closed__2 = (const lean_object*)&lp_bounded_Bounded_instReprKMap_repr___redArg___closed__2_value;
static const lean_ctor_object lp_bounded_Bounded_instReprKMap_repr___redArg___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_bounded_Bounded_instReprKMap_repr___redArg___closed__2_value)}};
static const lean_object* lp_bounded_Bounded_instReprKMap_repr___redArg___closed__3 = (const lean_object*)&lp_bounded_Bounded_instReprKMap_repr___redArg___closed__3_value;
static const lean_string_object lp_bounded_Bounded_instReprKMap_repr___redArg___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = " := "};
static const lean_object* lp_bounded_Bounded_instReprKMap_repr___redArg___closed__4 = (const lean_object*)&lp_bounded_Bounded_instReprKMap_repr___redArg___closed__4_value;
static const lean_ctor_object lp_bounded_Bounded_instReprKMap_repr___redArg___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprKMap_repr___redArg___closed__4_value)}};
static const lean_object* lp_bounded_Bounded_instReprKMap_repr___redArg___closed__5 = (const lean_object*)&lp_bounded_Bounded_instReprKMap_repr___redArg___closed__5_value;
static const lean_ctor_object lp_bounded_Bounded_instReprKMap_repr___redArg___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprKMap_repr___redArg___closed__3_value),((lean_object*)&lp_bounded_Bounded_instReprKMap_repr___redArg___closed__5_value)}};
static const lean_object* lp_bounded_Bounded_instReprKMap_repr___redArg___closed__6 = (const lean_object*)&lp_bounded_Bounded_instReprKMap_repr___redArg___closed__6_value;
static lean_once_cell_t lp_bounded_Bounded_instReprKMap_repr___redArg___closed__7_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_instReprKMap_repr___redArg___closed__7;
static const lean_string_object lp_bounded_Bounded_instReprKMap_repr___redArg___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = ","};
static const lean_object* lp_bounded_Bounded_instReprKMap_repr___redArg___closed__8 = (const lean_object*)&lp_bounded_Bounded_instReprKMap_repr___redArg___closed__8_value;
static const lean_ctor_object lp_bounded_Bounded_instReprKMap_repr___redArg___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprKMap_repr___redArg___closed__8_value)}};
static const lean_object* lp_bounded_Bounded_instReprKMap_repr___redArg___closed__9 = (const lean_object*)&lp_bounded_Bounded_instReprKMap_repr___redArg___closed__9_value;
static const lean_string_object lp_bounded_Bounded_instReprKMap_repr___redArg___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "k1"};
static const lean_object* lp_bounded_Bounded_instReprKMap_repr___redArg___closed__10 = (const lean_object*)&lp_bounded_Bounded_instReprKMap_repr___redArg___closed__10_value;
static const lean_ctor_object lp_bounded_Bounded_instReprKMap_repr___redArg___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprKMap_repr___redArg___closed__10_value)}};
static const lean_object* lp_bounded_Bounded_instReprKMap_repr___redArg___closed__11 = (const lean_object*)&lp_bounded_Bounded_instReprKMap_repr___redArg___closed__11_value;
static const lean_string_object lp_bounded_Bounded_instReprKMap_repr___redArg___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = " }"};
static const lean_object* lp_bounded_Bounded_instReprKMap_repr___redArg___closed__12 = (const lean_object*)&lp_bounded_Bounded_instReprKMap_repr___redArg___closed__12_value;
static lean_once_cell_t lp_bounded_Bounded_instReprKMap_repr___redArg___closed__13_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_instReprKMap_repr___redArg___closed__13;
static lean_once_cell_t lp_bounded_Bounded_instReprKMap_repr___redArg___closed__14_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_instReprKMap_repr___redArg___closed__14;
static const lean_ctor_object lp_bounded_Bounded_instReprKMap_repr___redArg___closed__15_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprKMap_repr___redArg___closed__0_value)}};
static const lean_object* lp_bounded_Bounded_instReprKMap_repr___redArg___closed__15 = (const lean_object*)&lp_bounded_Bounded_instReprKMap_repr___redArg___closed__15_value;
static const lean_ctor_object lp_bounded_Bounded_instReprKMap_repr___redArg___closed__16_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprKMap_repr___redArg___closed__12_value)}};
static const lean_object* lp_bounded_Bounded_instReprKMap_repr___redArg___closed__16 = (const lean_object*)&lp_bounded_Bounded_instReprKMap_repr___redArg___closed__16_value;
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprKMap_repr___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprKMap_repr(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprKMap_repr___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprKMap___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprKMap(lean_object*, lean_object*);
LEAN_EXPORT uint64_t lp_bounded_Bounded_instHashableKMap_hash___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instHashableKMap_hash___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint64_t lp_bounded_Bounded_instHashableKMap_hash(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instHashableKMap_hash___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instHashableKMap___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instHashableKMap(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_KMap_get___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_KMap_get___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_KMap_get(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_KMap_get___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_KMap_set___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_KMap_set___redArg___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_KMap_set(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_KMap_set___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_KMap_const___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_KMap_const(lean_object*, lean_object*);
static lean_once_cell_t lp_bounded_Bounded_KMap_ofFun___redArg___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_KMap_ofFun___redArg___closed__0;
static lean_once_cell_t lp_bounded_Bounded_KMap_ofFun___redArg___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_KMap_ofFun___redArg___closed__1;
LEAN_EXPORT lean_object* lp_bounded_Bounded_KMap_ofFun___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_KMap_ofFun(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_KMap_kswap___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_KMap_kswap(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_KMap_map___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_KMap_map(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumKMap___redArg___lam__0(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumKMap___redArg___lam__1(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumKMap___redArg___lam__2(lean_object*, lean_object*);
static const lean_closure_object lp_bounded_Bounded_instFinEnumKMap___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_bounded_Bounded_instFinEnumKMap___redArg___lam__0, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_bounded_Bounded_instFinEnumKMap___redArg___closed__0 = (const lean_object*)&lp_bounded_Bounded_instFinEnumKMap___redArg___closed__0_value;
static const lean_array_object lp_bounded_Bounded_instFinEnumKMap___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* lp_bounded_Bounded_instFinEnumKMap___redArg___closed__1 = (const lean_object*)&lp_bounded_Bounded_instFinEnumKMap___redArg___closed__1_value;
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumKMap___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumKMap(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqSMap_decEq___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqSMap_decEq___redArg___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqSMap_decEq(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqSMap_decEq___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqSMap___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqSMap___redArg___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqSMap(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqSMap___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object lp_bounded_Bounded_instReprSMap_repr___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "s0"};
static const lean_object* lp_bounded_Bounded_instReprSMap_repr___redArg___closed__0 = (const lean_object*)&lp_bounded_Bounded_instReprSMap_repr___redArg___closed__0_value;
static const lean_ctor_object lp_bounded_Bounded_instReprSMap_repr___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprSMap_repr___redArg___closed__0_value)}};
static const lean_object* lp_bounded_Bounded_instReprSMap_repr___redArg___closed__1 = (const lean_object*)&lp_bounded_Bounded_instReprSMap_repr___redArg___closed__1_value;
static const lean_ctor_object lp_bounded_Bounded_instReprSMap_repr___redArg___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_bounded_Bounded_instReprSMap_repr___redArg___closed__1_value)}};
static const lean_object* lp_bounded_Bounded_instReprSMap_repr___redArg___closed__2 = (const lean_object*)&lp_bounded_Bounded_instReprSMap_repr___redArg___closed__2_value;
static const lean_ctor_object lp_bounded_Bounded_instReprSMap_repr___redArg___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprSMap_repr___redArg___closed__2_value),((lean_object*)&lp_bounded_Bounded_instReprKMap_repr___redArg___closed__5_value)}};
static const lean_object* lp_bounded_Bounded_instReprSMap_repr___redArg___closed__3 = (const lean_object*)&lp_bounded_Bounded_instReprSMap_repr___redArg___closed__3_value;
static const lean_string_object lp_bounded_Bounded_instReprSMap_repr___redArg___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "s1"};
static const lean_object* lp_bounded_Bounded_instReprSMap_repr___redArg___closed__4 = (const lean_object*)&lp_bounded_Bounded_instReprSMap_repr___redArg___closed__4_value;
static const lean_ctor_object lp_bounded_Bounded_instReprSMap_repr___redArg___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprSMap_repr___redArg___closed__4_value)}};
static const lean_object* lp_bounded_Bounded_instReprSMap_repr___redArg___closed__5 = (const lean_object*)&lp_bounded_Bounded_instReprSMap_repr___redArg___closed__5_value;
static const lean_string_object lp_bounded_Bounded_instReprSMap_repr___redArg___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "s2"};
static const lean_object* lp_bounded_Bounded_instReprSMap_repr___redArg___closed__6 = (const lean_object*)&lp_bounded_Bounded_instReprSMap_repr___redArg___closed__6_value;
static const lean_ctor_object lp_bounded_Bounded_instReprSMap_repr___redArg___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprSMap_repr___redArg___closed__6_value)}};
static const lean_object* lp_bounded_Bounded_instReprSMap_repr___redArg___closed__7 = (const lean_object*)&lp_bounded_Bounded_instReprSMap_repr___redArg___closed__7_value;
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprSMap_repr___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprSMap_repr(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprSMap_repr___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprSMap___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprSMap(lean_object*, lean_object*);
LEAN_EXPORT uint64_t lp_bounded_Bounded_instHashableSMap_hash___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instHashableSMap_hash___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint64_t lp_bounded_Bounded_instHashableSMap_hash(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instHashableSMap_hash___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instHashableSMap___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instHashableSMap(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_SMap_get___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_SMap_get___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_SMap_get(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_SMap_get___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_SMap_set___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_SMap_set___redArg___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_SMap_set(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_SMap_set___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_SMap_const___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_SMap_const(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumSMap___redArg___lam__0(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumSMap___redArg___lam__0___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumSMap___redArg___lam__3(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumSMap___redArg___lam__1(lean_object*, lean_object*, lean_object*);
static const lean_closure_object lp_bounded_Bounded_instFinEnumSMap___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_bounded_Bounded_instFinEnumSMap___redArg___lam__0___boxed, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_bounded_Bounded_instFinEnumSMap___redArg___closed__0 = (const lean_object*)&lp_bounded_Bounded_instFinEnumSMap___redArg___closed__0_value;
static const lean_array_object lp_bounded_Bounded_instFinEnumSMap___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* lp_bounded_Bounded_instFinEnumSMap___redArg___closed__1 = (const lean_object*)&lp_bounded_Bounded_instFinEnumSMap___redArg___closed__1_value;
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumSMap___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumSMap(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Step_ctorIdx(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Step_ctorIdx___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Step_ctorElim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Step_ctorElim(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Step_ctorElim___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Step_provide_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Step_provide_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Step_track_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Step_track_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Step_read_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Step_read_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Step_setval_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Step_setval_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Step_register_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Step_register_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Step_raise_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Step_raise_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqStep_decEq(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqStep_decEq___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqStep(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqStep___boxed(lean_object*, lean_object*);
static const lean_string_object lp_bounded_Bounded_instReprStep_repr___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 22, .m_capacity = 22, .m_length = 21, .m_data = "Bounded.Step.register"};
static const lean_object* lp_bounded_Bounded_instReprStep_repr___closed__0 = (const lean_object*)&lp_bounded_Bounded_instReprStep_repr___closed__0_value;
static const lean_ctor_object lp_bounded_Bounded_instReprStep_repr___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprStep_repr___closed__0_value)}};
static const lean_object* lp_bounded_Bounded_instReprStep_repr___closed__1 = (const lean_object*)&lp_bounded_Bounded_instReprStep_repr___closed__1_value;
static const lean_string_object lp_bounded_Bounded_instReprStep_repr___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 19, .m_capacity = 19, .m_length = 18, .m_data = "Bounded.Step.raise"};
static const lean_object* lp_bounded_Bounded_instReprStep_repr___closed__2 = (const lean_object*)&lp_bounded_Bounded_instReprStep_repr___closed__2_value;
static const lean_ctor_object lp_bounded_Bounded_instReprStep_repr___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprStep_repr___closed__2_value)}};
static const lean_object* lp_bounded_Bounded_instReprStep_repr___closed__3 = (const lean_object*)&lp_bounded_Bounded_instReprStep_repr___closed__3_value;
static const lean_string_object lp_bounded_Bounded_instReprStep_repr___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 21, .m_capacity = 21, .m_length = 20, .m_data = "Bounded.Step.provide"};
static const lean_object* lp_bounded_Bounded_instReprStep_repr___closed__4 = (const lean_object*)&lp_bounded_Bounded_instReprStep_repr___closed__4_value;
static const lean_ctor_object lp_bounded_Bounded_instReprStep_repr___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprStep_repr___closed__4_value)}};
static const lean_object* lp_bounded_Bounded_instReprStep_repr___closed__5 = (const lean_object*)&lp_bounded_Bounded_instReprStep_repr___closed__5_value;
static const lean_ctor_object lp_bounded_Bounded_instReprStep_repr___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprStep_repr___closed__5_value),((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* lp_bounded_Bounded_instReprStep_repr___closed__6 = (const lean_object*)&lp_bounded_Bounded_instReprStep_repr___closed__6_value;
static lean_once_cell_t lp_bounded_Bounded_instReprStep_repr___closed__7_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_instReprStep_repr___closed__7;
static lean_once_cell_t lp_bounded_Bounded_instReprStep_repr___closed__8_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_instReprStep_repr___closed__8;
static const lean_string_object lp_bounded_Bounded_instReprStep_repr___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 19, .m_capacity = 19, .m_length = 18, .m_data = "Bounded.Step.track"};
static const lean_object* lp_bounded_Bounded_instReprStep_repr___closed__9 = (const lean_object*)&lp_bounded_Bounded_instReprStep_repr___closed__9_value;
static const lean_ctor_object lp_bounded_Bounded_instReprStep_repr___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprStep_repr___closed__9_value)}};
static const lean_object* lp_bounded_Bounded_instReprStep_repr___closed__10 = (const lean_object*)&lp_bounded_Bounded_instReprStep_repr___closed__10_value;
static const lean_ctor_object lp_bounded_Bounded_instReprStep_repr___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprStep_repr___closed__10_value),((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* lp_bounded_Bounded_instReprStep_repr___closed__11 = (const lean_object*)&lp_bounded_Bounded_instReprStep_repr___closed__11_value;
static const lean_string_object lp_bounded_Bounded_instReprStep_repr___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 18, .m_capacity = 18, .m_length = 17, .m_data = "Bounded.Step.read"};
static const lean_object* lp_bounded_Bounded_instReprStep_repr___closed__12 = (const lean_object*)&lp_bounded_Bounded_instReprStep_repr___closed__12_value;
static const lean_ctor_object lp_bounded_Bounded_instReprStep_repr___closed__13_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprStep_repr___closed__12_value)}};
static const lean_object* lp_bounded_Bounded_instReprStep_repr___closed__13 = (const lean_object*)&lp_bounded_Bounded_instReprStep_repr___closed__13_value;
static const lean_ctor_object lp_bounded_Bounded_instReprStep_repr___closed__14_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprStep_repr___closed__13_value),((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* lp_bounded_Bounded_instReprStep_repr___closed__14 = (const lean_object*)&lp_bounded_Bounded_instReprStep_repr___closed__14_value;
static const lean_string_object lp_bounded_Bounded_instReprStep_repr___closed__15_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 20, .m_capacity = 20, .m_length = 19, .m_data = "Bounded.Step.setval"};
static const lean_object* lp_bounded_Bounded_instReprStep_repr___closed__15 = (const lean_object*)&lp_bounded_Bounded_instReprStep_repr___closed__15_value;
static const lean_ctor_object lp_bounded_Bounded_instReprStep_repr___closed__16_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprStep_repr___closed__15_value)}};
static const lean_object* lp_bounded_Bounded_instReprStep_repr___closed__16 = (const lean_object*)&lp_bounded_Bounded_instReprStep_repr___closed__16_value;
static const lean_ctor_object lp_bounded_Bounded_instReprStep_repr___closed__17_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprStep_repr___closed__16_value),((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* lp_bounded_Bounded_instReprStep_repr___closed__17 = (const lean_object*)&lp_bounded_Bounded_instReprStep_repr___closed__17_value;
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprStep_repr(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprStep_repr___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_bounded_Bounded_instReprStep___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_bounded_Bounded_instReprStep_repr___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_bounded_Bounded_instReprStep___closed__0 = (const lean_object*)&lp_bounded_Bounded_instReprStep___closed__0_value;
LEAN_EXPORT const lean_object* lp_bounded_Bounded_instReprStep = (const lean_object*)&lp_bounded_Bounded_instReprStep___closed__0_value;
LEAN_EXPORT uint64_t lp_bounded_Bounded_instHashableStep_hash(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instHashableStep_hash___boxed(lean_object*);
static const lean_closure_object lp_bounded_Bounded_instHashableStep___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_bounded_Bounded_instHashableStep_hash___boxed, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_bounded_Bounded_instHashableStep___closed__0 = (const lean_object*)&lp_bounded_Bounded_instHashableStep___closed__0_value;
LEAN_EXPORT const lean_object* lp_bounded_Bounded_instHashableStep = (const lean_object*)&lp_bounded_Bounded_instHashableStep___closed__0_value;
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumStep___lam__0(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumStep___lam__1(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumStep___lam__2(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumStep___lam__3(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumStep___lam__4(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumStep___lam__5(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumStep___lam__5___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_bounded_Bounded_instFinEnumStep___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_bounded_Bounded_instFinEnumStep___lam__0, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_bounded_Bounded_instFinEnumStep___closed__0 = (const lean_object*)&lp_bounded_Bounded_instFinEnumStep___closed__0_value;
static const lean_closure_object lp_bounded_Bounded_instFinEnumStep___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_bounded_Bounded_instFinEnumStep___lam__1, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_bounded_Bounded_instFinEnumStep___closed__1 = (const lean_object*)&lp_bounded_Bounded_instFinEnumStep___closed__1_value;
static const lean_closure_object lp_bounded_Bounded_instFinEnumStep___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_bounded_Bounded_instFinEnumStep___lam__2, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_bounded_Bounded_instFinEnumStep___closed__2 = (const lean_object*)&lp_bounded_Bounded_instFinEnumStep___closed__2_value;
static const lean_closure_object lp_bounded_Bounded_instFinEnumStep___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_bounded_Bounded_instFinEnumStep___lam__3, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_bounded_Bounded_instFinEnumStep___closed__3 = (const lean_object*)&lp_bounded_Bounded_instFinEnumStep___closed__3_value;
static const lean_closure_object lp_bounded_Bounded_instFinEnumStep___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*1, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_bounded_Bounded_instFinEnumStep___lam__5___boxed, .m_arity = 2, .m_num_fixed = 1, .m_objs = {((lean_object*)(((size_t)(2) << 1) | 1))} };
static const lean_object* lp_bounded_Bounded_instFinEnumStep___closed__4 = (const lean_object*)&lp_bounded_Bounded_instFinEnumStep___closed__4_value;
static lean_once_cell_t lp_bounded_Bounded_instFinEnumStep___closed__5_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_instFinEnumStep___closed__5;
static const lean_array_object lp_bounded_Bounded_instFinEnumStep___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* lp_bounded_Bounded_instFinEnumStep___closed__6 = (const lean_object*)&lp_bounded_Bounded_instFinEnumStep___closed__6_value;
static lean_once_cell_t lp_bounded_Bounded_instFinEnumStep___closed__7_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_instFinEnumStep___closed__7;
static lean_once_cell_t lp_bounded_Bounded_instFinEnumStep___closed__8_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_instFinEnumStep___closed__8;
static lean_once_cell_t lp_bounded_Bounded_instFinEnumStep___closed__9_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_instFinEnumStep___closed__9;
static lean_once_cell_t lp_bounded_Bounded_instFinEnumStep___closed__10_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_instFinEnumStep___closed__10;
static lean_once_cell_t lp_bounded_Bounded_instFinEnumStep___closed__11_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_instFinEnumStep___closed__11;
static lean_once_cell_t lp_bounded_Bounded_instFinEnumStep___closed__12_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_instFinEnumStep___closed__12;
static lean_once_cell_t lp_bounded_Bounded_instFinEnumStep___closed__13_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_instFinEnumStep___closed__13;
static lean_once_cell_t lp_bounded_Bounded_instFinEnumStep___closed__14_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_instFinEnumStep___closed__14;
static const lean_ctor_object lp_bounded_Bounded_instFinEnumStep___closed__15_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(5) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_bounded_Bounded_instFinEnumStep___closed__15 = (const lean_object*)&lp_bounded_Bounded_instFinEnumStep___closed__15_value;
static const lean_ctor_object lp_bounded_Bounded_instFinEnumStep___closed__16_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(4) << 1) | 1)),((lean_object*)&lp_bounded_Bounded_instFinEnumStep___closed__15_value)}};
static const lean_object* lp_bounded_Bounded_instFinEnumStep___closed__16 = (const lean_object*)&lp_bounded_Bounded_instFinEnumStep___closed__16_value;
static lean_once_cell_t lp_bounded_Bounded_instFinEnumStep___closed__17_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_instFinEnumStep___closed__17;
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumStep;
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqComponent_decEq___lam__0(uint8_t, uint8_t);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqComponent_decEq___lam__0___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_bounded_Bounded_instDecidableEqComponent_decEq___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_bounded_Bounded_instDecidableEqComponent_decEq___lam__0___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_bounded_Bounded_instDecidableEqComponent_decEq___closed__0 = (const lean_object*)&lp_bounded_Bounded_instDecidableEqComponent_decEq___closed__0_value;
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqComponent_decEq(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqComponent_decEq___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqComponent(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqComponent___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint64_t lp_bounded_Bounded_instHashableKMap_hash___at___00Bounded_instHashableComponent_hash_spec__0(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instHashableKMap_hash___at___00Bounded_instHashableComponent_hash_spec__0___boxed(lean_object*);
LEAN_EXPORT uint64_t lp_bounded_List_foldl___at___00Bounded_instHashableComponent_hash_spec__1(uint64_t, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_List_foldl___at___00Bounded_instHashableComponent_hash_spec__1___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint64_t lp_bounded_Bounded_instHashableComponent_hash(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instHashableComponent_hash___boxed(lean_object*);
static const lean_closure_object lp_bounded_Bounded_instHashableComponent___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_bounded_Bounded_instHashableComponent_hash___boxed, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_bounded_Bounded_instHashableComponent___closed__0 = (const lean_object*)&lp_bounded_Bounded_instHashableComponent___closed__0_value;
LEAN_EXPORT const lean_object* lp_bounded_Bounded_instHashableComponent = (const lean_object*)&lp_bounded_Bounded_instHashableComponent___closed__0_value;
LEAN_EXPORT lean_object* lp_bounded_Bounded_Outcome_ctorIdx(uint8_t);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Outcome_ctorIdx___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Outcome_toCtorIdx(uint8_t);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Outcome_toCtorIdx___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Outcome_ctorElim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Outcome_ctorElim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Outcome_ctorElim(lean_object*, lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Outcome_ctorElim___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Outcome_ok_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Outcome_ok_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Outcome_ok_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Outcome_ok_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Outcome_err_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Outcome_err_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Outcome_err_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Outcome_err_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_Outcome_ofNat(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Outcome_ofNat___boxed(lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqOutcome(uint8_t, uint8_t);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqOutcome___boxed(lean_object*, lean_object*);
static const lean_string_object lp_bounded_Bounded_instReprOutcome_repr___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 19, .m_capacity = 19, .m_length = 18, .m_data = "Bounded.Outcome.ok"};
static const lean_object* lp_bounded_Bounded_instReprOutcome_repr___closed__0 = (const lean_object*)&lp_bounded_Bounded_instReprOutcome_repr___closed__0_value;
static const lean_ctor_object lp_bounded_Bounded_instReprOutcome_repr___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprOutcome_repr___closed__0_value)}};
static const lean_object* lp_bounded_Bounded_instReprOutcome_repr___closed__1 = (const lean_object*)&lp_bounded_Bounded_instReprOutcome_repr___closed__1_value;
static const lean_string_object lp_bounded_Bounded_instReprOutcome_repr___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 20, .m_capacity = 20, .m_length = 19, .m_data = "Bounded.Outcome.err"};
static const lean_object* lp_bounded_Bounded_instReprOutcome_repr___closed__2 = (const lean_object*)&lp_bounded_Bounded_instReprOutcome_repr___closed__2_value;
static const lean_ctor_object lp_bounded_Bounded_instReprOutcome_repr___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprOutcome_repr___closed__2_value)}};
static const lean_object* lp_bounded_Bounded_instReprOutcome_repr___closed__3 = (const lean_object*)&lp_bounded_Bounded_instReprOutcome_repr___closed__3_value;
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprOutcome_repr(uint8_t, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprOutcome_repr___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_bounded_Bounded_instReprOutcome___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_bounded_Bounded_instReprOutcome_repr___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_bounded_Bounded_instReprOutcome___closed__0 = (const lean_object*)&lp_bounded_Bounded_instReprOutcome___closed__0_value;
LEAN_EXPORT const lean_object* lp_bounded_Bounded_instReprOutcome = (const lean_object*)&lp_bounded_Bounded_instReprOutcome___closed__0_value;
LEAN_EXPORT uint64_t lp_bounded_Bounded_instHashableOutcome_hash(uint8_t);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instHashableOutcome_hash___boxed(lean_object*);
static const lean_closure_object lp_bounded_Bounded_instHashableOutcome___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_bounded_Bounded_instHashableOutcome_hash___boxed, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_bounded_Bounded_instHashableOutcome___closed__0 = (const lean_object*)&lp_bounded_Bounded_instHashableOutcome___closed__0_value;
LEAN_EXPORT const lean_object* lp_bounded_Bounded_instHashableOutcome = (const lean_object*)&lp_bounded_Bounded_instHashableOutcome___closed__0_value;
LEAN_EXPORT lean_object* lp_bounded_Bounded_Inv_ctorIdx(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Inv_ctorIdx___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Inv_ctorElim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Inv_ctorElim(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Inv_ctorElim___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Inv_unprovide_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Inv_unprovide_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Inv_untrack_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Inv_untrack_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Inv_retireChild_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Inv_retireChild_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqInv_decEq(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqInv_decEq___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqInv(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqInv___boxed(lean_object*, lean_object*);
static const lean_string_object lp_bounded_Bounded_instReprInv_repr___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 22, .m_capacity = 22, .m_length = 21, .m_data = "Bounded.Inv.unprovide"};
static const lean_object* lp_bounded_Bounded_instReprInv_repr___closed__0 = (const lean_object*)&lp_bounded_Bounded_instReprInv_repr___closed__0_value;
static const lean_ctor_object lp_bounded_Bounded_instReprInv_repr___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprInv_repr___closed__0_value)}};
static const lean_object* lp_bounded_Bounded_instReprInv_repr___closed__1 = (const lean_object*)&lp_bounded_Bounded_instReprInv_repr___closed__1_value;
static const lean_ctor_object lp_bounded_Bounded_instReprInv_repr___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprInv_repr___closed__1_value),((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* lp_bounded_Bounded_instReprInv_repr___closed__2 = (const lean_object*)&lp_bounded_Bounded_instReprInv_repr___closed__2_value;
static const lean_string_object lp_bounded_Bounded_instReprInv_repr___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 20, .m_capacity = 20, .m_length = 19, .m_data = "Bounded.Inv.untrack"};
static const lean_object* lp_bounded_Bounded_instReprInv_repr___closed__3 = (const lean_object*)&lp_bounded_Bounded_instReprInv_repr___closed__3_value;
static const lean_ctor_object lp_bounded_Bounded_instReprInv_repr___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprInv_repr___closed__3_value)}};
static const lean_object* lp_bounded_Bounded_instReprInv_repr___closed__4 = (const lean_object*)&lp_bounded_Bounded_instReprInv_repr___closed__4_value;
static const lean_ctor_object lp_bounded_Bounded_instReprInv_repr___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprInv_repr___closed__4_value),((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* lp_bounded_Bounded_instReprInv_repr___closed__5 = (const lean_object*)&lp_bounded_Bounded_instReprInv_repr___closed__5_value;
static const lean_string_object lp_bounded_Bounded_instReprInv_repr___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 24, .m_capacity = 24, .m_length = 23, .m_data = "Bounded.Inv.retireChild"};
static const lean_object* lp_bounded_Bounded_instReprInv_repr___closed__6 = (const lean_object*)&lp_bounded_Bounded_instReprInv_repr___closed__6_value;
static const lean_ctor_object lp_bounded_Bounded_instReprInv_repr___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprInv_repr___closed__6_value)}};
static const lean_object* lp_bounded_Bounded_instReprInv_repr___closed__7 = (const lean_object*)&lp_bounded_Bounded_instReprInv_repr___closed__7_value;
static const lean_ctor_object lp_bounded_Bounded_instReprInv_repr___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprInv_repr___closed__7_value),((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* lp_bounded_Bounded_instReprInv_repr___closed__8 = (const lean_object*)&lp_bounded_Bounded_instReprInv_repr___closed__8_value;
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprInv_repr(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprInv_repr___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_bounded_Bounded_instReprInv___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_bounded_Bounded_instReprInv_repr___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_bounded_Bounded_instReprInv___closed__0 = (const lean_object*)&lp_bounded_Bounded_instReprInv___closed__0_value;
LEAN_EXPORT const lean_object* lp_bounded_Bounded_instReprInv = (const lean_object*)&lp_bounded_Bounded_instReprInv___closed__0_value;
LEAN_EXPORT uint64_t lp_bounded_Bounded_instHashableInv_hash(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instHashableInv_hash___boxed(lean_object*);
static const lean_closure_object lp_bounded_Bounded_instHashableInv___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_bounded_Bounded_instHashableInv_hash___boxed, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_bounded_Bounded_instHashableInv___closed__0 = (const lean_object*)&lp_bounded_Bounded_instHashableInv___closed__0_value;
LEAN_EXPORT const lean_object* lp_bounded_Bounded_instHashableInv = (const lean_object*)&lp_bounded_Bounded_instHashableInv___closed__0_value;
LEAN_EXPORT lean_object* lp_bounded_Bounded_LState_ctorIdx(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_LState_ctorIdx___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_LState_ctorElim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_LState_ctorElim(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_LState_ctorElim___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_LState_inactive_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_LState_inactive_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_LState_reloading_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_LState_reloading_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_LState_active_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_LState_active_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_LState_unloading_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_LState_unloading_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqLState_decEq___lam__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqLState_decEq___lam__0___boxed(lean_object*, lean_object*, lean_object*);
static const lean_closure_object lp_bounded_Bounded_instDecidableEqLState_decEq___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*1, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_bounded_Bounded_instDecidableEqLState_decEq___lam__0___boxed, .m_arity = 3, .m_num_fixed = 1, .m_objs = {((lean_object*)(((size_t)(3) << 1) | 1))} };
static const lean_object* lp_bounded_Bounded_instDecidableEqLState_decEq___closed__0 = (const lean_object*)&lp_bounded_Bounded_instDecidableEqLState_decEq___closed__0_value;
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqLState_decEq(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqLState_decEq___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqLState(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqLState___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint64_t lp_bounded_Bounded_instHashableKMap_hash___at___00Bounded_instHashableLState_hash_spec__1(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instHashableKMap_hash___at___00Bounded_instHashableLState_hash_spec__1___boxed(lean_object*);
LEAN_EXPORT uint64_t lp_bounded_List_foldl___at___00Bounded_instHashableLState_hash_spec__0(uint64_t, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_List_foldl___at___00Bounded_instHashableLState_hash_spec__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint64_t lp_bounded_Bounded_instHashableLState_hash(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instHashableLState_hash___boxed(lean_object*);
static const lean_closure_object lp_bounded_Bounded_instHashableLState___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_bounded_Bounded_instHashableLState_hash___boxed, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_bounded_Bounded_instHashableLState___closed__0 = (const lean_object*)&lp_bounded_Bounded_instHashableLState___closed__0_value;
LEAN_EXPORT const lean_object* lp_bounded_Bounded_instHashableLState = (const lean_object*)&lp_bounded_Bounded_instHashableLState___closed__0_value;
LEAN_EXPORT uint8_t lp_bounded_Bounded_LState_isActive(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_LState_isActive___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_LState_viewOf(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_LState_viewOf___boxed(lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_LState_isInstalled(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_LState_isInstalled___boxed(lean_object*);
static const lean_closure_object lp_bounded_Bounded_instDecidableEqFiber_decEq___lam__0___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*1, .m_other = 0, .m_tag = 245}, .m_fun = (void*)l_instDecidableEqFin___boxed, .m_arity = 3, .m_num_fixed = 1, .m_objs = {((lean_object*)(((size_t)(2) << 1) | 1))} };
static const lean_object* lp_bounded_Bounded_instDecidableEqFiber_decEq___lam__0___closed__0 = (const lean_object*)&lp_bounded_Bounded_instDecidableEqFiber_decEq___lam__0___closed__0_value;
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqFiber_decEq___lam__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqFiber_decEq___lam__0___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_bounded_Bounded_instDecidableEqFiber_decEq___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*1, .m_other = 0, .m_tag = 245}, .m_fun = (void*)l_instDecidableEqFin___boxed, .m_arity = 3, .m_num_fixed = 1, .m_objs = {((lean_object*)(((size_t)(3) << 1) | 1))} };
static const lean_object* lp_bounded_Bounded_instDecidableEqFiber_decEq___closed__0 = (const lean_object*)&lp_bounded_Bounded_instDecidableEqFiber_decEq___closed__0_value;
static const lean_closure_object lp_bounded_Bounded_instDecidableEqFiber_decEq___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_bounded_Bounded_instDecidableEqFiber_decEq___lam__0___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_bounded_Bounded_instDecidableEqFiber_decEq___closed__1 = (const lean_object*)&lp_bounded_Bounded_instDecidableEqFiber_decEq___closed__1_value;
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqFiber_decEq(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqFiber_decEq___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqFiber(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqFiber___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint64_t lp_bounded_Bounded_instHashableKMap_hash___at___00Bounded_instHashableFiber_hash_spec__0(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instHashableKMap_hash___at___00Bounded_instHashableFiber_hash_spec__0___boxed(lean_object*);
LEAN_EXPORT uint64_t lp_bounded_Bounded_instHashableFiber_hash(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instHashableFiber_hash___boxed(lean_object*);
static const lean_closure_object lp_bounded_Bounded_instHashableFiber___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_bounded_Bounded_instHashableFiber_hash___boxed, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_bounded_Bounded_instHashableFiber___closed__0 = (const lean_object*)&lp_bounded_Bounded_instHashableFiber___closed__0_value;
LEAN_EXPORT const lean_object* lp_bounded_Bounded_instHashableFiber = (const lean_object*)&lp_bounded_Bounded_instHashableFiber___closed__0_value;
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqConfig___aux__1___lam__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqConfig___aux__1___lam__0___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_bounded_Bounded_instDecidableEqConfig___aux__1___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_bounded_Bounded_instDecidableEqConfig___aux__1___lam__0___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_bounded_Bounded_instDecidableEqConfig___aux__1___closed__0 = (const lean_object*)&lp_bounded_Bounded_instDecidableEqConfig___aux__1___closed__0_value;
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqConfig___aux__1(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqConfig___aux__1___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqConfig(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqConfig___boxed(lean_object*, lean_object*);
static const lean_ctor_object lp_bounded_Bounded_emptyConfig___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*3 + 0, .m_other = 3, .m_tag = 0}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_bounded_Bounded_emptyConfig___closed__0 = (const lean_object*)&lp_bounded_Bounded_emptyConfig___closed__0_value;
LEAN_EXPORT const lean_object* lp_bounded_Bounded_emptyConfig = (const lean_object*)&lp_bounded_Bounded_emptyConfig___closed__0_value;
LEAN_EXPORT lean_object* lp_bounded_Bounded_Config_get(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Config_get___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_upd(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_upd___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_provP(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_provP___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_List_find_x3f___at___00Bounded_providerOf_spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_List_find_x3f___at___00Bounded_providerOf_spec__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_providerOf(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_providerOf___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_storeOf(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_storeOf___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidablePredConfigWF___aux__1___lam__0(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidablePredConfigWF___aux__1___lam__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidablePredConfigWF___aux__1___lam__1(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidablePredConfigWF___aux__1___lam__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidablePredConfigWF___aux__1___lam__2(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidablePredConfigWF___aux__1___lam__2___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidablePredConfigWF___aux__1(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidablePredConfigWF___aux__1___boxed(lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidablePredConfigWF(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidablePredConfigWF___boxed(lean_object*);
LEAN_EXPORT uint8_t lp_bounded_List_all___at___00Bounded_satisfied_spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_List_all___at___00Bounded_satisfied_spec__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_satisfied(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_satisfied___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_partialTarget___lam__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_partialTarget___lam__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_partialTarget(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_targetOf(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_targetOf___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Option_instBEq_beq___at___00Bounded_reliedUpon_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Option_instBEq_beq___at___00Bounded_reliedUpon_spec__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_List_any___at___00Bounded_reliedUpon_spec__1(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_List_any___at___00Bounded_reliedUpon_spec__1___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_List_any___at___00Bounded_reliedUpon_spec__2(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_List_any___at___00Bounded_reliedUpon_spec__2___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_reliedUpon(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_reliedUpon___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_List_any___at___00Bounded_hasChild_spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_List_any___at___00Bounded_hasChild_spec__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_hasChild(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_hasChild___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_quietAt___lam__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_quietAt___lam__0___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_bounded_Bounded_quietAt___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_bounded_Bounded_quietAt___lam__0___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_bounded_Bounded_quietAt___closed__0 = (const lean_object*)&lp_bounded_Bounded_quietAt___closed__0_value;
LEAN_EXPORT uint8_t lp_bounded_Bounded_quietAt(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_quietAt___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_List_all___at___00Bounded_quiet_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_List_all___at___00Bounded_quiet_spec__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_quiet(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_quiet___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadRes_ctorIdx(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadRes_ctorIdx___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadRes_ctorElim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadRes_ctorElim(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadRes_ctorElim___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadRes_ok_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadRes_ok_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadRes_ia_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadRes_ia_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadRes_ud_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadRes_ud_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqReadRes_decEq(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqReadRes_decEq___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqReadRes(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqReadRes___boxed(lean_object*, lean_object*);
static const lean_string_object lp_bounded_Bounded_instReprReadRes_repr___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 19, .m_capacity = 19, .m_length = 18, .m_data = "Bounded.ReadRes.ia"};
static const lean_object* lp_bounded_Bounded_instReprReadRes_repr___closed__0 = (const lean_object*)&lp_bounded_Bounded_instReprReadRes_repr___closed__0_value;
static const lean_ctor_object lp_bounded_Bounded_instReprReadRes_repr___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprReadRes_repr___closed__0_value)}};
static const lean_object* lp_bounded_Bounded_instReprReadRes_repr___closed__1 = (const lean_object*)&lp_bounded_Bounded_instReprReadRes_repr___closed__1_value;
static const lean_string_object lp_bounded_Bounded_instReprReadRes_repr___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 19, .m_capacity = 19, .m_length = 18, .m_data = "Bounded.ReadRes.ud"};
static const lean_object* lp_bounded_Bounded_instReprReadRes_repr___closed__2 = (const lean_object*)&lp_bounded_Bounded_instReprReadRes_repr___closed__2_value;
static const lean_ctor_object lp_bounded_Bounded_instReprReadRes_repr___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprReadRes_repr___closed__2_value)}};
static const lean_object* lp_bounded_Bounded_instReprReadRes_repr___closed__3 = (const lean_object*)&lp_bounded_Bounded_instReprReadRes_repr___closed__3_value;
static const lean_string_object lp_bounded_Bounded_instReprReadRes_repr___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 19, .m_capacity = 19, .m_length = 18, .m_data = "Bounded.ReadRes.ok"};
static const lean_object* lp_bounded_Bounded_instReprReadRes_repr___closed__4 = (const lean_object*)&lp_bounded_Bounded_instReprReadRes_repr___closed__4_value;
static const lean_ctor_object lp_bounded_Bounded_instReprReadRes_repr___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprReadRes_repr___closed__4_value)}};
static const lean_object* lp_bounded_Bounded_instReprReadRes_repr___closed__5 = (const lean_object*)&lp_bounded_Bounded_instReprReadRes_repr___closed__5_value;
static const lean_ctor_object lp_bounded_Bounded_instReprReadRes_repr___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprReadRes_repr___closed__5_value),((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* lp_bounded_Bounded_instReprReadRes_repr___closed__6 = (const lean_object*)&lp_bounded_Bounded_instReprReadRes_repr___closed__6_value;
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprReadRes_repr(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprReadRes_repr___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_bounded_Bounded_instReprReadRes___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_bounded_Bounded_instReprReadRes_repr___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_bounded_Bounded_instReprReadRes___closed__0 = (const lean_object*)&lp_bounded_Bounded_instReprReadRes___closed__0_value;
LEAN_EXPORT const lean_object* lp_bounded_Bounded_instReprReadRes = (const lean_object*)&lp_bounded_Bounded_instReprReadRes___closed__0_value;
LEAN_EXPORT uint64_t lp_bounded_Bounded_instHashableReadRes_hash(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instHashableReadRes_hash___boxed(lean_object*);
static const lean_closure_object lp_bounded_Bounded_instHashableReadRes___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_bounded_Bounded_instHashableReadRes_hash___boxed, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_bounded_Bounded_instHashableReadRes___closed__0 = (const lean_object*)&lp_bounded_Bounded_instHashableReadRes___closed__0_value;
LEAN_EXPORT const lean_object* lp_bounded_Bounded_instHashableReadRes = (const lean_object*)&lp_bounded_Bounded_instHashableReadRes___closed__0_value;
LEAN_EXPORT lean_object* lp_bounded_Bounded_readC(lean_object*, lean_object*, lean_object*, lean_object*, uint8_t);
LEAN_EXPORT lean_object* lp_bounded_Bounded_readC___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqKMap_decEq___redArg(lean_object* v_inst_1_, lean_object* v_x_2_, lean_object* v_x_3_){
_start:
{
lean_object* v_k0_4_; lean_object* v_k1_5_; lean_object* v_k0_6_; lean_object* v_k1_7_; lean_object* v___x_8_; uint8_t v___x_9_; 
v_k0_4_ = lean_ctor_get(v_x_2_, 0);
lean_inc(v_k0_4_);
v_k1_5_ = lean_ctor_get(v_x_2_, 1);
lean_inc(v_k1_5_);
lean_dec_ref(v_x_2_);
v_k0_6_ = lean_ctor_get(v_x_3_, 0);
lean_inc(v_k0_6_);
v_k1_7_ = lean_ctor_get(v_x_3_, 1);
lean_inc(v_k1_7_);
lean_dec_ref(v_x_3_);
lean_inc_ref(v_inst_1_);
v___x_8_ = lean_apply_2(v_inst_1_, v_k0_4_, v_k0_6_);
v___x_9_ = lean_unbox(v___x_8_);
if (v___x_9_ == 0)
{
uint8_t v___x_10_; 
lean_dec(v_k1_7_);
lean_dec(v_k1_5_);
lean_dec_ref(v_inst_1_);
v___x_10_ = lean_unbox(v___x_8_);
return v___x_10_;
}
else
{
lean_object* v___x_11_; uint8_t v___x_12_; 
v___x_11_ = lean_apply_2(v_inst_1_, v_k1_5_, v_k1_7_);
v___x_12_ = lean_unbox(v___x_11_);
return v___x_12_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqKMap_decEq___redArg___boxed(lean_object* v_inst_13_, lean_object* v_x_14_, lean_object* v_x_15_){
_start:
{
uint8_t v_res_16_; lean_object* v_r_17_; 
v_res_16_ = lp_bounded_Bounded_instDecidableEqKMap_decEq___redArg(v_inst_13_, v_x_14_, v_x_15_);
v_r_17_ = lean_box(v_res_16_);
return v_r_17_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqKMap_decEq(lean_object* v_00_u03b1_18_, lean_object* v_inst_19_, lean_object* v_x_20_, lean_object* v_x_21_){
_start:
{
uint8_t v___x_22_; 
v___x_22_ = lp_bounded_Bounded_instDecidableEqKMap_decEq___redArg(v_inst_19_, v_x_20_, v_x_21_);
return v___x_22_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqKMap_decEq___boxed(lean_object* v_00_u03b1_23_, lean_object* v_inst_24_, lean_object* v_x_25_, lean_object* v_x_26_){
_start:
{
uint8_t v_res_27_; lean_object* v_r_28_; 
v_res_27_ = lp_bounded_Bounded_instDecidableEqKMap_decEq(v_00_u03b1_23_, v_inst_24_, v_x_25_, v_x_26_);
v_r_28_ = lean_box(v_res_27_);
return v_r_28_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqKMap___redArg(lean_object* v_inst_29_, lean_object* v_x_30_, lean_object* v_x_31_){
_start:
{
uint8_t v___x_32_; 
v___x_32_ = lp_bounded_Bounded_instDecidableEqKMap_decEq___redArg(v_inst_29_, v_x_30_, v_x_31_);
return v___x_32_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqKMap___redArg___boxed(lean_object* v_inst_33_, lean_object* v_x_34_, lean_object* v_x_35_){
_start:
{
uint8_t v_res_36_; lean_object* v_r_37_; 
v_res_36_ = lp_bounded_Bounded_instDecidableEqKMap___redArg(v_inst_33_, v_x_34_, v_x_35_);
v_r_37_ = lean_box(v_res_36_);
return v_r_37_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqKMap(lean_object* v_00_u03b1_38_, lean_object* v_inst_39_, lean_object* v_x_40_, lean_object* v_x_41_){
_start:
{
uint8_t v___x_42_; 
v___x_42_ = lp_bounded_Bounded_instDecidableEqKMap_decEq___redArg(v_inst_39_, v_x_40_, v_x_41_);
return v___x_42_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqKMap___boxed(lean_object* v_00_u03b1_43_, lean_object* v_inst_44_, lean_object* v_x_45_, lean_object* v_x_46_){
_start:
{
uint8_t v_res_47_; lean_object* v_r_48_; 
v_res_47_ = lp_bounded_Bounded_instDecidableEqKMap(v_00_u03b1_43_, v_inst_44_, v_x_45_, v_x_46_);
v_r_48_ = lean_box(v_res_47_);
return v_r_48_;
}
}
static lean_object* _init_lp_bounded_Bounded_instReprKMap_repr___redArg___closed__7(void){
_start:
{
lean_object* v___x_62_; lean_object* v___x_63_; 
v___x_62_ = lean_unsigned_to_nat(6u);
v___x_63_ = lean_nat_to_int(v___x_62_);
return v___x_63_;
}
}
static lean_object* _init_lp_bounded_Bounded_instReprKMap_repr___redArg___closed__13(void){
_start:
{
lean_object* v___x_71_; lean_object* v___x_72_; 
v___x_71_ = ((lean_object*)(lp_bounded_Bounded_instReprKMap_repr___redArg___closed__0));
v___x_72_ = lean_string_length(v___x_71_);
return v___x_72_;
}
}
static lean_object* _init_lp_bounded_Bounded_instReprKMap_repr___redArg___closed__14(void){
_start:
{
lean_object* v___x_73_; lean_object* v___x_74_; 
v___x_73_ = lean_obj_once(&lp_bounded_Bounded_instReprKMap_repr___redArg___closed__13, &lp_bounded_Bounded_instReprKMap_repr___redArg___closed__13_once, _init_lp_bounded_Bounded_instReprKMap_repr___redArg___closed__13);
v___x_74_ = lean_nat_to_int(v___x_73_);
return v___x_74_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprKMap_repr___redArg(lean_object* v_inst_79_, lean_object* v_x_80_){
_start:
{
lean_object* v_k0_81_; lean_object* v_k1_82_; lean_object* v___x_84_; uint8_t v_isShared_85_; uint8_t v_isSharedCheck_115_; 
v_k0_81_ = lean_ctor_get(v_x_80_, 0);
v_k1_82_ = lean_ctor_get(v_x_80_, 1);
v_isSharedCheck_115_ = !lean_is_exclusive(v_x_80_);
if (v_isSharedCheck_115_ == 0)
{
v___x_84_ = v_x_80_;
v_isShared_85_ = v_isSharedCheck_115_;
goto v_resetjp_83_;
}
else
{
lean_inc(v_k1_82_);
lean_inc(v_k0_81_);
lean_dec(v_x_80_);
v___x_84_ = lean_box(0);
v_isShared_85_ = v_isSharedCheck_115_;
goto v_resetjp_83_;
}
v_resetjp_83_:
{
lean_object* v___x_86_; lean_object* v___x_87_; lean_object* v___x_88_; lean_object* v___x_89_; lean_object* v___x_90_; lean_object* v___x_92_; 
v___x_86_ = ((lean_object*)(lp_bounded_Bounded_instReprKMap_repr___redArg___closed__5));
v___x_87_ = ((lean_object*)(lp_bounded_Bounded_instReprKMap_repr___redArg___closed__6));
v___x_88_ = lean_obj_once(&lp_bounded_Bounded_instReprKMap_repr___redArg___closed__7, &lp_bounded_Bounded_instReprKMap_repr___redArg___closed__7_once, _init_lp_bounded_Bounded_instReprKMap_repr___redArg___closed__7);
v___x_89_ = lean_unsigned_to_nat(0u);
lean_inc_ref(v_inst_79_);
v___x_90_ = lean_apply_2(v_inst_79_, v_k0_81_, v___x_89_);
if (v_isShared_85_ == 0)
{
lean_ctor_set_tag(v___x_84_, 4);
lean_ctor_set(v___x_84_, 1, v___x_90_);
lean_ctor_set(v___x_84_, 0, v___x_88_);
v___x_92_ = v___x_84_;
goto v_reusejp_91_;
}
else
{
lean_object* v_reuseFailAlloc_114_; 
v_reuseFailAlloc_114_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v_reuseFailAlloc_114_, 0, v___x_88_);
lean_ctor_set(v_reuseFailAlloc_114_, 1, v___x_90_);
v___x_92_ = v_reuseFailAlloc_114_;
goto v_reusejp_91_;
}
v_reusejp_91_:
{
uint8_t v___x_93_; lean_object* v___x_94_; lean_object* v___x_95_; lean_object* v___x_96_; lean_object* v___x_97_; lean_object* v___x_98_; lean_object* v___x_99_; lean_object* v___x_100_; lean_object* v___x_101_; lean_object* v___x_102_; lean_object* v___x_103_; lean_object* v___x_104_; lean_object* v___x_105_; lean_object* v___x_106_; lean_object* v___x_107_; lean_object* v___x_108_; lean_object* v___x_109_; lean_object* v___x_110_; lean_object* v___x_111_; lean_object* v___x_112_; lean_object* v___x_113_; 
v___x_93_ = 0;
v___x_94_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_94_, 0, v___x_92_);
lean_ctor_set_uint8(v___x_94_, sizeof(void*)*1, v___x_93_);
v___x_95_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_95_, 0, v___x_87_);
lean_ctor_set(v___x_95_, 1, v___x_94_);
v___x_96_ = ((lean_object*)(lp_bounded_Bounded_instReprKMap_repr___redArg___closed__9));
v___x_97_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_97_, 0, v___x_95_);
lean_ctor_set(v___x_97_, 1, v___x_96_);
v___x_98_ = lean_box(1);
v___x_99_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_99_, 0, v___x_97_);
lean_ctor_set(v___x_99_, 1, v___x_98_);
v___x_100_ = ((lean_object*)(lp_bounded_Bounded_instReprKMap_repr___redArg___closed__11));
v___x_101_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_101_, 0, v___x_99_);
lean_ctor_set(v___x_101_, 1, v___x_100_);
v___x_102_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_102_, 0, v___x_101_);
lean_ctor_set(v___x_102_, 1, v___x_86_);
v___x_103_ = lean_apply_2(v_inst_79_, v_k1_82_, v___x_89_);
v___x_104_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_104_, 0, v___x_88_);
lean_ctor_set(v___x_104_, 1, v___x_103_);
v___x_105_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_105_, 0, v___x_104_);
lean_ctor_set_uint8(v___x_105_, sizeof(void*)*1, v___x_93_);
v___x_106_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_106_, 0, v___x_102_);
lean_ctor_set(v___x_106_, 1, v___x_105_);
v___x_107_ = lean_obj_once(&lp_bounded_Bounded_instReprKMap_repr___redArg___closed__14, &lp_bounded_Bounded_instReprKMap_repr___redArg___closed__14_once, _init_lp_bounded_Bounded_instReprKMap_repr___redArg___closed__14);
v___x_108_ = ((lean_object*)(lp_bounded_Bounded_instReprKMap_repr___redArg___closed__15));
v___x_109_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_109_, 0, v___x_108_);
lean_ctor_set(v___x_109_, 1, v___x_106_);
v___x_110_ = ((lean_object*)(lp_bounded_Bounded_instReprKMap_repr___redArg___closed__16));
v___x_111_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_111_, 0, v___x_109_);
lean_ctor_set(v___x_111_, 1, v___x_110_);
v___x_112_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_112_, 0, v___x_107_);
lean_ctor_set(v___x_112_, 1, v___x_111_);
v___x_113_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_113_, 0, v___x_112_);
lean_ctor_set_uint8(v___x_113_, sizeof(void*)*1, v___x_93_);
return v___x_113_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprKMap_repr(lean_object* v_00_u03b1_116_, lean_object* v_inst_117_, lean_object* v_x_118_, lean_object* v_prec_119_){
_start:
{
lean_object* v___x_120_; 
v___x_120_ = lp_bounded_Bounded_instReprKMap_repr___redArg(v_inst_117_, v_x_118_);
return v___x_120_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprKMap_repr___boxed(lean_object* v_00_u03b1_121_, lean_object* v_inst_122_, lean_object* v_x_123_, lean_object* v_prec_124_){
_start:
{
lean_object* v_res_125_; 
v_res_125_ = lp_bounded_Bounded_instReprKMap_repr(v_00_u03b1_121_, v_inst_122_, v_x_123_, v_prec_124_);
lean_dec(v_prec_124_);
return v_res_125_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprKMap___redArg(lean_object* v_inst_126_){
_start:
{
lean_object* v___x_127_; 
v___x_127_ = lean_alloc_closure((void*)(lp_bounded_Bounded_instReprKMap_repr___boxed), 4, 2);
lean_closure_set(v___x_127_, 0, lean_box(0));
lean_closure_set(v___x_127_, 1, v_inst_126_);
return v___x_127_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprKMap(lean_object* v_00_u03b1_128_, lean_object* v_inst_129_){
_start:
{
lean_object* v___x_130_; 
v___x_130_ = lean_alloc_closure((void*)(lp_bounded_Bounded_instReprKMap_repr___boxed), 4, 2);
lean_closure_set(v___x_130_, 0, lean_box(0));
lean_closure_set(v___x_130_, 1, v_inst_129_);
return v___x_130_;
}
}
LEAN_EXPORT uint64_t lp_bounded_Bounded_instHashableKMap_hash___redArg(lean_object* v_inst_131_, lean_object* v_x_132_){
_start:
{
lean_object* v_k0_133_; lean_object* v_k1_134_; uint64_t v___x_135_; lean_object* v___x_136_; uint64_t v___x_137_; uint64_t v___x_138_; lean_object* v___x_139_; uint64_t v___x_140_; uint64_t v___x_141_; 
v_k0_133_ = lean_ctor_get(v_x_132_, 0);
lean_inc(v_k0_133_);
v_k1_134_ = lean_ctor_get(v_x_132_, 1);
lean_inc(v_k1_134_);
lean_dec_ref(v_x_132_);
v___x_135_ = 0ULL;
lean_inc_ref(v_inst_131_);
v___x_136_ = lean_apply_1(v_inst_131_, v_k0_133_);
v___x_137_ = lean_unbox_uint64(v___x_136_);
lean_dec_ref(v___x_136_);
v___x_138_ = lean_uint64_mix_hash(v___x_135_, v___x_137_);
v___x_139_ = lean_apply_1(v_inst_131_, v_k1_134_);
v___x_140_ = lean_unbox_uint64(v___x_139_);
lean_dec_ref(v___x_139_);
v___x_141_ = lean_uint64_mix_hash(v___x_138_, v___x_140_);
return v___x_141_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instHashableKMap_hash___redArg___boxed(lean_object* v_inst_142_, lean_object* v_x_143_){
_start:
{
uint64_t v_res_144_; lean_object* v_r_145_; 
v_res_144_ = lp_bounded_Bounded_instHashableKMap_hash___redArg(v_inst_142_, v_x_143_);
v_r_145_ = lean_box_uint64(v_res_144_);
return v_r_145_;
}
}
LEAN_EXPORT uint64_t lp_bounded_Bounded_instHashableKMap_hash(lean_object* v_00_u03b1_146_, lean_object* v_inst_147_, lean_object* v_x_148_){
_start:
{
uint64_t v___x_149_; 
v___x_149_ = lp_bounded_Bounded_instHashableKMap_hash___redArg(v_inst_147_, v_x_148_);
return v___x_149_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instHashableKMap_hash___boxed(lean_object* v_00_u03b1_150_, lean_object* v_inst_151_, lean_object* v_x_152_){
_start:
{
uint64_t v_res_153_; lean_object* v_r_154_; 
v_res_153_ = lp_bounded_Bounded_instHashableKMap_hash(v_00_u03b1_150_, v_inst_151_, v_x_152_);
v_r_154_ = lean_box_uint64(v_res_153_);
return v_r_154_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instHashableKMap___redArg(lean_object* v_inst_155_){
_start:
{
lean_object* v___x_156_; 
v___x_156_ = lean_alloc_closure((void*)(lp_bounded_Bounded_instHashableKMap_hash___boxed), 3, 2);
lean_closure_set(v___x_156_, 0, lean_box(0));
lean_closure_set(v___x_156_, 1, v_inst_155_);
return v___x_156_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instHashableKMap(lean_object* v_00_u03b1_157_, lean_object* v_inst_158_){
_start:
{
lean_object* v___x_159_; 
v___x_159_ = lean_alloc_closure((void*)(lp_bounded_Bounded_instHashableKMap_hash___boxed), 3, 2);
lean_closure_set(v___x_159_, 0, lean_box(0));
lean_closure_set(v___x_159_, 1, v_inst_158_);
return v___x_159_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_KMap_get___redArg(lean_object* v_m_160_, lean_object* v_k_161_){
_start:
{
lean_object* v___x_162_; uint8_t v___x_163_; 
v___x_162_ = lean_unsigned_to_nat(0u);
v___x_163_ = lean_nat_dec_eq(v_k_161_, v___x_162_);
if (v___x_163_ == 0)
{
lean_object* v_k1_164_; 
v_k1_164_ = lean_ctor_get(v_m_160_, 1);
lean_inc(v_k1_164_);
return v_k1_164_;
}
else
{
lean_object* v_k0_165_; 
v_k0_165_ = lean_ctor_get(v_m_160_, 0);
lean_inc(v_k0_165_);
return v_k0_165_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_KMap_get___redArg___boxed(lean_object* v_m_166_, lean_object* v_k_167_){
_start:
{
lean_object* v_res_168_; 
v_res_168_ = lp_bounded_Bounded_KMap_get___redArg(v_m_166_, v_k_167_);
lean_dec(v_k_167_);
lean_dec_ref(v_m_166_);
return v_res_168_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_KMap_get(lean_object* v_00_u03b1_169_, lean_object* v_m_170_, lean_object* v_k_171_){
_start:
{
lean_object* v___x_172_; 
v___x_172_ = lp_bounded_Bounded_KMap_get___redArg(v_m_170_, v_k_171_);
return v___x_172_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_KMap_get___boxed(lean_object* v_00_u03b1_173_, lean_object* v_m_174_, lean_object* v_k_175_){
_start:
{
lean_object* v_res_176_; 
v_res_176_ = lp_bounded_Bounded_KMap_get(v_00_u03b1_173_, v_m_174_, v_k_175_);
lean_dec(v_k_175_);
lean_dec_ref(v_m_174_);
return v_res_176_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_KMap_set___redArg(lean_object* v_m_177_, lean_object* v_k_178_, lean_object* v_v_179_){
_start:
{
lean_object* v___x_180_; uint8_t v___x_181_; 
v___x_180_ = lean_unsigned_to_nat(0u);
v___x_181_ = lean_nat_dec_eq(v_k_178_, v___x_180_);
if (v___x_181_ == 0)
{
lean_object* v_k0_182_; lean_object* v___x_184_; uint8_t v_isShared_185_; uint8_t v_isSharedCheck_189_; 
v_k0_182_ = lean_ctor_get(v_m_177_, 0);
v_isSharedCheck_189_ = !lean_is_exclusive(v_m_177_);
if (v_isSharedCheck_189_ == 0)
{
lean_object* v_unused_190_; 
v_unused_190_ = lean_ctor_get(v_m_177_, 1);
lean_dec(v_unused_190_);
v___x_184_ = v_m_177_;
v_isShared_185_ = v_isSharedCheck_189_;
goto v_resetjp_183_;
}
else
{
lean_inc(v_k0_182_);
lean_dec(v_m_177_);
v___x_184_ = lean_box(0);
v_isShared_185_ = v_isSharedCheck_189_;
goto v_resetjp_183_;
}
v_resetjp_183_:
{
lean_object* v___x_187_; 
if (v_isShared_185_ == 0)
{
lean_ctor_set(v___x_184_, 1, v_v_179_);
v___x_187_ = v___x_184_;
goto v_reusejp_186_;
}
else
{
lean_object* v_reuseFailAlloc_188_; 
v_reuseFailAlloc_188_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_188_, 0, v_k0_182_);
lean_ctor_set(v_reuseFailAlloc_188_, 1, v_v_179_);
v___x_187_ = v_reuseFailAlloc_188_;
goto v_reusejp_186_;
}
v_reusejp_186_:
{
return v___x_187_;
}
}
}
else
{
lean_object* v_k1_191_; lean_object* v___x_193_; uint8_t v_isShared_194_; uint8_t v_isSharedCheck_198_; 
v_k1_191_ = lean_ctor_get(v_m_177_, 1);
v_isSharedCheck_198_ = !lean_is_exclusive(v_m_177_);
if (v_isSharedCheck_198_ == 0)
{
lean_object* v_unused_199_; 
v_unused_199_ = lean_ctor_get(v_m_177_, 0);
lean_dec(v_unused_199_);
v___x_193_ = v_m_177_;
v_isShared_194_ = v_isSharedCheck_198_;
goto v_resetjp_192_;
}
else
{
lean_inc(v_k1_191_);
lean_dec(v_m_177_);
v___x_193_ = lean_box(0);
v_isShared_194_ = v_isSharedCheck_198_;
goto v_resetjp_192_;
}
v_resetjp_192_:
{
lean_object* v___x_196_; 
if (v_isShared_194_ == 0)
{
lean_ctor_set(v___x_193_, 0, v_v_179_);
v___x_196_ = v___x_193_;
goto v_reusejp_195_;
}
else
{
lean_object* v_reuseFailAlloc_197_; 
v_reuseFailAlloc_197_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_197_, 0, v_v_179_);
lean_ctor_set(v_reuseFailAlloc_197_, 1, v_k1_191_);
v___x_196_ = v_reuseFailAlloc_197_;
goto v_reusejp_195_;
}
v_reusejp_195_:
{
return v___x_196_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_KMap_set___redArg___boxed(lean_object* v_m_200_, lean_object* v_k_201_, lean_object* v_v_202_){
_start:
{
lean_object* v_res_203_; 
v_res_203_ = lp_bounded_Bounded_KMap_set___redArg(v_m_200_, v_k_201_, v_v_202_);
lean_dec(v_k_201_);
return v_res_203_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_KMap_set(lean_object* v_00_u03b1_204_, lean_object* v_m_205_, lean_object* v_k_206_, lean_object* v_v_207_){
_start:
{
lean_object* v___x_208_; 
v___x_208_ = lp_bounded_Bounded_KMap_set___redArg(v_m_205_, v_k_206_, v_v_207_);
return v___x_208_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_KMap_set___boxed(lean_object* v_00_u03b1_209_, lean_object* v_m_210_, lean_object* v_k_211_, lean_object* v_v_212_){
_start:
{
lean_object* v_res_213_; 
v_res_213_ = lp_bounded_Bounded_KMap_set(v_00_u03b1_209_, v_m_210_, v_k_211_, v_v_212_);
lean_dec(v_k_211_);
return v_res_213_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_KMap_const___redArg(lean_object* v_v_214_){
_start:
{
lean_object* v___x_215_; 
lean_inc(v_v_214_);
v___x_215_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_215_, 0, v_v_214_);
lean_ctor_set(v___x_215_, 1, v_v_214_);
return v___x_215_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_KMap_const(lean_object* v_00_u03b1_216_, lean_object* v_v_217_){
_start:
{
lean_object* v___x_218_; 
lean_inc(v_v_217_);
v___x_218_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_218_, 0, v_v_217_);
lean_ctor_set(v___x_218_, 1, v_v_217_);
return v___x_218_;
}
}
static lean_object* _init_lp_bounded_Bounded_KMap_ofFun___redArg___closed__0(void){
_start:
{
lean_object* v___x_219_; lean_object* v___x_220_; lean_object* v___x_221_; 
v___x_219_ = lean_unsigned_to_nat(2u);
v___x_220_ = lean_unsigned_to_nat(0u);
v___x_221_ = lean_nat_mod(v___x_220_, v___x_219_);
return v___x_221_;
}
}
static lean_object* _init_lp_bounded_Bounded_KMap_ofFun___redArg___closed__1(void){
_start:
{
lean_object* v___x_222_; lean_object* v___x_223_; lean_object* v___x_224_; 
v___x_222_ = lean_unsigned_to_nat(2u);
v___x_223_ = lean_unsigned_to_nat(1u);
v___x_224_ = lean_nat_mod(v___x_223_, v___x_222_);
return v___x_224_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_KMap_ofFun___redArg(lean_object* v_g_225_){
_start:
{
lean_object* v___x_226_; lean_object* v___x_227_; lean_object* v___x_228_; lean_object* v___x_229_; lean_object* v___x_230_; 
v___x_226_ = lean_obj_once(&lp_bounded_Bounded_KMap_ofFun___redArg___closed__0, &lp_bounded_Bounded_KMap_ofFun___redArg___closed__0_once, _init_lp_bounded_Bounded_KMap_ofFun___redArg___closed__0);
lean_inc(v_g_225_);
v___x_227_ = lean_apply_1(v_g_225_, v___x_226_);
v___x_228_ = lean_obj_once(&lp_bounded_Bounded_KMap_ofFun___redArg___closed__1, &lp_bounded_Bounded_KMap_ofFun___redArg___closed__1_once, _init_lp_bounded_Bounded_KMap_ofFun___redArg___closed__1);
v___x_229_ = lean_apply_1(v_g_225_, v___x_228_);
v___x_230_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_230_, 0, v___x_227_);
lean_ctor_set(v___x_230_, 1, v___x_229_);
return v___x_230_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_KMap_ofFun(lean_object* v_00_u03b1_231_, lean_object* v_g_232_){
_start:
{
lean_object* v___x_233_; 
v___x_233_ = lp_bounded_Bounded_KMap_ofFun___redArg(v_g_232_);
return v___x_233_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_KMap_kswap___redArg(lean_object* v_m_234_){
_start:
{
lean_object* v_k0_235_; lean_object* v_k1_236_; lean_object* v___x_238_; uint8_t v_isShared_239_; uint8_t v_isSharedCheck_243_; 
v_k0_235_ = lean_ctor_get(v_m_234_, 0);
v_k1_236_ = lean_ctor_get(v_m_234_, 1);
v_isSharedCheck_243_ = !lean_is_exclusive(v_m_234_);
if (v_isSharedCheck_243_ == 0)
{
v___x_238_ = v_m_234_;
v_isShared_239_ = v_isSharedCheck_243_;
goto v_resetjp_237_;
}
else
{
lean_inc(v_k1_236_);
lean_inc(v_k0_235_);
lean_dec(v_m_234_);
v___x_238_ = lean_box(0);
v_isShared_239_ = v_isSharedCheck_243_;
goto v_resetjp_237_;
}
v_resetjp_237_:
{
lean_object* v___x_241_; 
if (v_isShared_239_ == 0)
{
lean_ctor_set(v___x_238_, 1, v_k0_235_);
lean_ctor_set(v___x_238_, 0, v_k1_236_);
v___x_241_ = v___x_238_;
goto v_reusejp_240_;
}
else
{
lean_object* v_reuseFailAlloc_242_; 
v_reuseFailAlloc_242_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_242_, 0, v_k1_236_);
lean_ctor_set(v_reuseFailAlloc_242_, 1, v_k0_235_);
v___x_241_ = v_reuseFailAlloc_242_;
goto v_reusejp_240_;
}
v_reusejp_240_:
{
return v___x_241_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_KMap_kswap(lean_object* v_00_u03b1_244_, lean_object* v_m_245_){
_start:
{
lean_object* v___x_246_; 
v___x_246_ = lp_bounded_Bounded_KMap_kswap___redArg(v_m_245_);
return v___x_246_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_KMap_map___redArg(lean_object* v_f_247_, lean_object* v_m_248_){
_start:
{
lean_object* v_k0_249_; lean_object* v_k1_250_; lean_object* v___x_252_; uint8_t v_isShared_253_; uint8_t v_isSharedCheck_259_; 
v_k0_249_ = lean_ctor_get(v_m_248_, 0);
v_k1_250_ = lean_ctor_get(v_m_248_, 1);
v_isSharedCheck_259_ = !lean_is_exclusive(v_m_248_);
if (v_isSharedCheck_259_ == 0)
{
v___x_252_ = v_m_248_;
v_isShared_253_ = v_isSharedCheck_259_;
goto v_resetjp_251_;
}
else
{
lean_inc(v_k1_250_);
lean_inc(v_k0_249_);
lean_dec(v_m_248_);
v___x_252_ = lean_box(0);
v_isShared_253_ = v_isSharedCheck_259_;
goto v_resetjp_251_;
}
v_resetjp_251_:
{
lean_object* v___x_254_; lean_object* v___x_255_; lean_object* v___x_257_; 
lean_inc(v_f_247_);
v___x_254_ = lean_apply_1(v_f_247_, v_k0_249_);
v___x_255_ = lean_apply_1(v_f_247_, v_k1_250_);
if (v_isShared_253_ == 0)
{
lean_ctor_set(v___x_252_, 1, v___x_255_);
lean_ctor_set(v___x_252_, 0, v___x_254_);
v___x_257_ = v___x_252_;
goto v_reusejp_256_;
}
else
{
lean_object* v_reuseFailAlloc_258_; 
v_reuseFailAlloc_258_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_258_, 0, v___x_254_);
lean_ctor_set(v_reuseFailAlloc_258_, 1, v___x_255_);
v___x_257_ = v_reuseFailAlloc_258_;
goto v_reusejp_256_;
}
v_reusejp_256_:
{
return v___x_257_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_KMap_map(lean_object* v_00_u03b1_260_, lean_object* v_00_u03b2_261_, lean_object* v_f_262_, lean_object* v_m_263_){
_start:
{
lean_object* v___x_264_; 
v___x_264_ = lp_bounded_Bounded_KMap_map___redArg(v_f_262_, v_m_263_);
return v___x_264_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumKMap___redArg___lam__0(lean_object* v_p_265_){
_start:
{
lean_object* v_fst_266_; lean_object* v_snd_267_; lean_object* v___x_269_; uint8_t v_isShared_270_; uint8_t v_isSharedCheck_274_; 
v_fst_266_ = lean_ctor_get(v_p_265_, 0);
v_snd_267_ = lean_ctor_get(v_p_265_, 1);
v_isSharedCheck_274_ = !lean_is_exclusive(v_p_265_);
if (v_isSharedCheck_274_ == 0)
{
v___x_269_ = v_p_265_;
v_isShared_270_ = v_isSharedCheck_274_;
goto v_resetjp_268_;
}
else
{
lean_inc(v_snd_267_);
lean_inc(v_fst_266_);
lean_dec(v_p_265_);
v___x_269_ = lean_box(0);
v_isShared_270_ = v_isSharedCheck_274_;
goto v_resetjp_268_;
}
v_resetjp_268_:
{
lean_object* v___x_272_; 
if (v_isShared_270_ == 0)
{
v___x_272_ = v___x_269_;
goto v_reusejp_271_;
}
else
{
lean_object* v_reuseFailAlloc_273_; 
v_reuseFailAlloc_273_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_273_, 0, v_fst_266_);
lean_ctor_set(v_reuseFailAlloc_273_, 1, v_snd_267_);
v___x_272_ = v_reuseFailAlloc_273_;
goto v_reusejp_271_;
}
v_reusejp_271_:
{
return v___x_272_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumKMap___redArg___lam__1(lean_object* v_a_275_, lean_object* v_b_276_){
_start:
{
lean_object* v___x_277_; 
v___x_277_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_277_, 0, v_a_275_);
lean_ctor_set(v___x_277_, 1, v_b_276_);
return v___x_277_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumKMap___redArg___lam__2(lean_object* v_inst_278_, lean_object* v_a_279_){
_start:
{
lean_object* v___f_280_; lean_object* v___x_281_; lean_object* v___x_282_; 
v___f_280_ = lean_alloc_closure((void*)(lp_bounded_Bounded_instFinEnumKMap___redArg___lam__1), 2, 1);
lean_closure_set(v___f_280_, 0, v_a_279_);
v___x_281_ = lean_box(0);
v___x_282_ = l_List_mapTR_loop___redArg(v___f_280_, v_inst_278_, v___x_281_);
return v___x_282_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumKMap___redArg(lean_object* v_inst_286_){
_start:
{
lean_object* v___f_287_; lean_object* v___f_288_; lean_object* v___x_289_; lean_object* v___x_290_; lean_object* v___x_291_; lean_object* v___x_292_; 
v___f_287_ = ((lean_object*)(lp_bounded_Bounded_instFinEnumKMap___redArg___closed__0));
lean_inc(v_inst_286_);
v___f_288_ = lean_alloc_closure((void*)(lp_bounded_Bounded_instFinEnumKMap___redArg___lam__2), 2, 1);
lean_closure_set(v___f_288_, 0, v_inst_286_);
v___x_289_ = ((lean_object*)(lp_bounded_Bounded_instFinEnumKMap___redArg___closed__1));
v___x_290_ = l___private_Init_Data_List_Impl_0__List_flatMapTR_go___redArg(v___f_288_, v_inst_286_, v___x_289_);
v___x_291_ = lean_box(0);
v___x_292_ = l_List_mapTR_loop___redArg(v___f_287_, v___x_290_, v___x_291_);
return v___x_292_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumKMap(lean_object* v_00_u03b1_293_, lean_object* v_inst_294_){
_start:
{
lean_object* v___x_295_; 
v___x_295_ = lp_bounded_Bounded_instFinEnumKMap___redArg(v_inst_294_);
return v___x_295_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqSMap_decEq___redArg(lean_object* v_inst_296_, lean_object* v_x_297_, lean_object* v_x_298_){
_start:
{
lean_object* v_s0_299_; lean_object* v_s1_300_; lean_object* v_s2_301_; lean_object* v_s0_302_; lean_object* v_s1_303_; lean_object* v_s2_304_; lean_object* v___x_305_; uint8_t v___x_306_; 
v_s0_299_ = lean_ctor_get(v_x_297_, 0);
lean_inc(v_s0_299_);
v_s1_300_ = lean_ctor_get(v_x_297_, 1);
lean_inc(v_s1_300_);
v_s2_301_ = lean_ctor_get(v_x_297_, 2);
lean_inc(v_s2_301_);
lean_dec_ref(v_x_297_);
v_s0_302_ = lean_ctor_get(v_x_298_, 0);
lean_inc(v_s0_302_);
v_s1_303_ = lean_ctor_get(v_x_298_, 1);
lean_inc(v_s1_303_);
v_s2_304_ = lean_ctor_get(v_x_298_, 2);
lean_inc(v_s2_304_);
lean_dec_ref(v_x_298_);
lean_inc_ref(v_inst_296_);
v___x_305_ = lean_apply_2(v_inst_296_, v_s0_299_, v_s0_302_);
v___x_306_ = lean_unbox(v___x_305_);
if (v___x_306_ == 0)
{
uint8_t v___x_307_; 
lean_dec(v_s2_304_);
lean_dec(v_s1_303_);
lean_dec(v_s2_301_);
lean_dec(v_s1_300_);
lean_dec_ref(v_inst_296_);
v___x_307_ = lean_unbox(v___x_305_);
return v___x_307_;
}
else
{
lean_object* v___x_308_; uint8_t v___x_309_; 
lean_inc_ref(v_inst_296_);
v___x_308_ = lean_apply_2(v_inst_296_, v_s1_300_, v_s1_303_);
v___x_309_ = lean_unbox(v___x_308_);
if (v___x_309_ == 0)
{
uint8_t v___x_310_; 
lean_dec(v_s2_304_);
lean_dec(v_s2_301_);
lean_dec_ref(v_inst_296_);
v___x_310_ = lean_unbox(v___x_308_);
return v___x_310_;
}
else
{
lean_object* v___x_311_; uint8_t v___x_312_; 
v___x_311_ = lean_apply_2(v_inst_296_, v_s2_301_, v_s2_304_);
v___x_312_ = lean_unbox(v___x_311_);
return v___x_312_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqSMap_decEq___redArg___boxed(lean_object* v_inst_313_, lean_object* v_x_314_, lean_object* v_x_315_){
_start:
{
uint8_t v_res_316_; lean_object* v_r_317_; 
v_res_316_ = lp_bounded_Bounded_instDecidableEqSMap_decEq___redArg(v_inst_313_, v_x_314_, v_x_315_);
v_r_317_ = lean_box(v_res_316_);
return v_r_317_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqSMap_decEq(lean_object* v_00_u03b1_318_, lean_object* v_inst_319_, lean_object* v_x_320_, lean_object* v_x_321_){
_start:
{
uint8_t v___x_322_; 
v___x_322_ = lp_bounded_Bounded_instDecidableEqSMap_decEq___redArg(v_inst_319_, v_x_320_, v_x_321_);
return v___x_322_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqSMap_decEq___boxed(lean_object* v_00_u03b1_323_, lean_object* v_inst_324_, lean_object* v_x_325_, lean_object* v_x_326_){
_start:
{
uint8_t v_res_327_; lean_object* v_r_328_; 
v_res_327_ = lp_bounded_Bounded_instDecidableEqSMap_decEq(v_00_u03b1_323_, v_inst_324_, v_x_325_, v_x_326_);
v_r_328_ = lean_box(v_res_327_);
return v_r_328_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqSMap___redArg(lean_object* v_inst_329_, lean_object* v_x_330_, lean_object* v_x_331_){
_start:
{
uint8_t v___x_332_; 
v___x_332_ = lp_bounded_Bounded_instDecidableEqSMap_decEq___redArg(v_inst_329_, v_x_330_, v_x_331_);
return v___x_332_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqSMap___redArg___boxed(lean_object* v_inst_333_, lean_object* v_x_334_, lean_object* v_x_335_){
_start:
{
uint8_t v_res_336_; lean_object* v_r_337_; 
v_res_336_ = lp_bounded_Bounded_instDecidableEqSMap___redArg(v_inst_333_, v_x_334_, v_x_335_);
v_r_337_ = lean_box(v_res_336_);
return v_r_337_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqSMap(lean_object* v_00_u03b1_338_, lean_object* v_inst_339_, lean_object* v_x_340_, lean_object* v_x_341_){
_start:
{
uint8_t v___x_342_; 
v___x_342_ = lp_bounded_Bounded_instDecidableEqSMap_decEq___redArg(v_inst_339_, v_x_340_, v_x_341_);
return v___x_342_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqSMap___boxed(lean_object* v_00_u03b1_343_, lean_object* v_inst_344_, lean_object* v_x_345_, lean_object* v_x_346_){
_start:
{
uint8_t v_res_347_; lean_object* v_r_348_; 
v_res_347_ = lp_bounded_Bounded_instDecidableEqSMap(v_00_u03b1_343_, v_inst_344_, v_x_345_, v_x_346_);
v_r_348_ = lean_box(v_res_347_);
return v_r_348_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprSMap_repr___redArg(lean_object* v_inst_364_, lean_object* v_x_365_){
_start:
{
lean_object* v_s0_366_; lean_object* v_s1_367_; lean_object* v_s2_368_; lean_object* v___x_369_; lean_object* v___x_370_; lean_object* v___x_371_; lean_object* v___x_372_; lean_object* v___x_373_; lean_object* v___x_374_; uint8_t v___x_375_; lean_object* v___x_376_; lean_object* v___x_377_; lean_object* v___x_378_; lean_object* v___x_379_; lean_object* v___x_380_; lean_object* v___x_381_; lean_object* v___x_382_; lean_object* v___x_383_; lean_object* v___x_384_; lean_object* v___x_385_; lean_object* v___x_386_; lean_object* v___x_387_; lean_object* v___x_388_; lean_object* v___x_389_; lean_object* v___x_390_; lean_object* v___x_391_; lean_object* v___x_392_; lean_object* v___x_393_; lean_object* v___x_394_; lean_object* v___x_395_; lean_object* v___x_396_; lean_object* v___x_397_; lean_object* v___x_398_; lean_object* v___x_399_; lean_object* v___x_400_; lean_object* v___x_401_; lean_object* v___x_402_; lean_object* v___x_403_; lean_object* v___x_404_; 
v_s0_366_ = lean_ctor_get(v_x_365_, 0);
lean_inc(v_s0_366_);
v_s1_367_ = lean_ctor_get(v_x_365_, 1);
lean_inc(v_s1_367_);
v_s2_368_ = lean_ctor_get(v_x_365_, 2);
lean_inc(v_s2_368_);
lean_dec_ref(v_x_365_);
v___x_369_ = ((lean_object*)(lp_bounded_Bounded_instReprKMap_repr___redArg___closed__5));
v___x_370_ = ((lean_object*)(lp_bounded_Bounded_instReprSMap_repr___redArg___closed__3));
v___x_371_ = lean_obj_once(&lp_bounded_Bounded_instReprKMap_repr___redArg___closed__7, &lp_bounded_Bounded_instReprKMap_repr___redArg___closed__7_once, _init_lp_bounded_Bounded_instReprKMap_repr___redArg___closed__7);
v___x_372_ = lean_unsigned_to_nat(0u);
lean_inc_ref_n(v_inst_364_, 2);
v___x_373_ = lean_apply_2(v_inst_364_, v_s0_366_, v___x_372_);
v___x_374_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_374_, 0, v___x_371_);
lean_ctor_set(v___x_374_, 1, v___x_373_);
v___x_375_ = 0;
v___x_376_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_376_, 0, v___x_374_);
lean_ctor_set_uint8(v___x_376_, sizeof(void*)*1, v___x_375_);
v___x_377_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_377_, 0, v___x_370_);
lean_ctor_set(v___x_377_, 1, v___x_376_);
v___x_378_ = ((lean_object*)(lp_bounded_Bounded_instReprKMap_repr___redArg___closed__9));
v___x_379_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_379_, 0, v___x_377_);
lean_ctor_set(v___x_379_, 1, v___x_378_);
v___x_380_ = lean_box(1);
v___x_381_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_381_, 0, v___x_379_);
lean_ctor_set(v___x_381_, 1, v___x_380_);
v___x_382_ = ((lean_object*)(lp_bounded_Bounded_instReprSMap_repr___redArg___closed__5));
v___x_383_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_383_, 0, v___x_381_);
lean_ctor_set(v___x_383_, 1, v___x_382_);
v___x_384_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_384_, 0, v___x_383_);
lean_ctor_set(v___x_384_, 1, v___x_369_);
v___x_385_ = lean_apply_2(v_inst_364_, v_s1_367_, v___x_372_);
v___x_386_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_386_, 0, v___x_371_);
lean_ctor_set(v___x_386_, 1, v___x_385_);
v___x_387_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_387_, 0, v___x_386_);
lean_ctor_set_uint8(v___x_387_, sizeof(void*)*1, v___x_375_);
v___x_388_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_388_, 0, v___x_384_);
lean_ctor_set(v___x_388_, 1, v___x_387_);
v___x_389_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_389_, 0, v___x_388_);
lean_ctor_set(v___x_389_, 1, v___x_378_);
v___x_390_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_390_, 0, v___x_389_);
lean_ctor_set(v___x_390_, 1, v___x_380_);
v___x_391_ = ((lean_object*)(lp_bounded_Bounded_instReprSMap_repr___redArg___closed__7));
v___x_392_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_392_, 0, v___x_390_);
lean_ctor_set(v___x_392_, 1, v___x_391_);
v___x_393_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_393_, 0, v___x_392_);
lean_ctor_set(v___x_393_, 1, v___x_369_);
v___x_394_ = lean_apply_2(v_inst_364_, v_s2_368_, v___x_372_);
v___x_395_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_395_, 0, v___x_371_);
lean_ctor_set(v___x_395_, 1, v___x_394_);
v___x_396_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_396_, 0, v___x_395_);
lean_ctor_set_uint8(v___x_396_, sizeof(void*)*1, v___x_375_);
v___x_397_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_397_, 0, v___x_393_);
lean_ctor_set(v___x_397_, 1, v___x_396_);
v___x_398_ = lean_obj_once(&lp_bounded_Bounded_instReprKMap_repr___redArg___closed__14, &lp_bounded_Bounded_instReprKMap_repr___redArg___closed__14_once, _init_lp_bounded_Bounded_instReprKMap_repr___redArg___closed__14);
v___x_399_ = ((lean_object*)(lp_bounded_Bounded_instReprKMap_repr___redArg___closed__15));
v___x_400_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_400_, 0, v___x_399_);
lean_ctor_set(v___x_400_, 1, v___x_397_);
v___x_401_ = ((lean_object*)(lp_bounded_Bounded_instReprKMap_repr___redArg___closed__16));
v___x_402_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_402_, 0, v___x_400_);
lean_ctor_set(v___x_402_, 1, v___x_401_);
v___x_403_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_403_, 0, v___x_398_);
lean_ctor_set(v___x_403_, 1, v___x_402_);
v___x_404_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_404_, 0, v___x_403_);
lean_ctor_set_uint8(v___x_404_, sizeof(void*)*1, v___x_375_);
return v___x_404_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprSMap_repr(lean_object* v_00_u03b1_405_, lean_object* v_inst_406_, lean_object* v_x_407_, lean_object* v_prec_408_){
_start:
{
lean_object* v___x_409_; 
v___x_409_ = lp_bounded_Bounded_instReprSMap_repr___redArg(v_inst_406_, v_x_407_);
return v___x_409_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprSMap_repr___boxed(lean_object* v_00_u03b1_410_, lean_object* v_inst_411_, lean_object* v_x_412_, lean_object* v_prec_413_){
_start:
{
lean_object* v_res_414_; 
v_res_414_ = lp_bounded_Bounded_instReprSMap_repr(v_00_u03b1_410_, v_inst_411_, v_x_412_, v_prec_413_);
lean_dec(v_prec_413_);
return v_res_414_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprSMap___redArg(lean_object* v_inst_415_){
_start:
{
lean_object* v___x_416_; 
v___x_416_ = lean_alloc_closure((void*)(lp_bounded_Bounded_instReprSMap_repr___boxed), 4, 2);
lean_closure_set(v___x_416_, 0, lean_box(0));
lean_closure_set(v___x_416_, 1, v_inst_415_);
return v___x_416_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprSMap(lean_object* v_00_u03b1_417_, lean_object* v_inst_418_){
_start:
{
lean_object* v___x_419_; 
v___x_419_ = lean_alloc_closure((void*)(lp_bounded_Bounded_instReprSMap_repr___boxed), 4, 2);
lean_closure_set(v___x_419_, 0, lean_box(0));
lean_closure_set(v___x_419_, 1, v_inst_418_);
return v___x_419_;
}
}
LEAN_EXPORT uint64_t lp_bounded_Bounded_instHashableSMap_hash___redArg(lean_object* v_inst_420_, lean_object* v_x_421_){
_start:
{
lean_object* v_s0_422_; lean_object* v_s1_423_; lean_object* v_s2_424_; uint64_t v___x_425_; lean_object* v___x_426_; uint64_t v___x_427_; uint64_t v___x_428_; lean_object* v___x_429_; uint64_t v___x_430_; uint64_t v___x_431_; lean_object* v___x_432_; uint64_t v___x_433_; uint64_t v___x_434_; 
v_s0_422_ = lean_ctor_get(v_x_421_, 0);
lean_inc(v_s0_422_);
v_s1_423_ = lean_ctor_get(v_x_421_, 1);
lean_inc(v_s1_423_);
v_s2_424_ = lean_ctor_get(v_x_421_, 2);
lean_inc(v_s2_424_);
lean_dec_ref(v_x_421_);
v___x_425_ = 0ULL;
lean_inc_ref_n(v_inst_420_, 2);
v___x_426_ = lean_apply_1(v_inst_420_, v_s0_422_);
v___x_427_ = lean_unbox_uint64(v___x_426_);
lean_dec_ref(v___x_426_);
v___x_428_ = lean_uint64_mix_hash(v___x_425_, v___x_427_);
v___x_429_ = lean_apply_1(v_inst_420_, v_s1_423_);
v___x_430_ = lean_unbox_uint64(v___x_429_);
lean_dec_ref(v___x_429_);
v___x_431_ = lean_uint64_mix_hash(v___x_428_, v___x_430_);
v___x_432_ = lean_apply_1(v_inst_420_, v_s2_424_);
v___x_433_ = lean_unbox_uint64(v___x_432_);
lean_dec_ref(v___x_432_);
v___x_434_ = lean_uint64_mix_hash(v___x_431_, v___x_433_);
return v___x_434_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instHashableSMap_hash___redArg___boxed(lean_object* v_inst_435_, lean_object* v_x_436_){
_start:
{
uint64_t v_res_437_; lean_object* v_r_438_; 
v_res_437_ = lp_bounded_Bounded_instHashableSMap_hash___redArg(v_inst_435_, v_x_436_);
v_r_438_ = lean_box_uint64(v_res_437_);
return v_r_438_;
}
}
LEAN_EXPORT uint64_t lp_bounded_Bounded_instHashableSMap_hash(lean_object* v_00_u03b1_439_, lean_object* v_inst_440_, lean_object* v_x_441_){
_start:
{
uint64_t v___x_442_; 
v___x_442_ = lp_bounded_Bounded_instHashableSMap_hash___redArg(v_inst_440_, v_x_441_);
return v___x_442_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instHashableSMap_hash___boxed(lean_object* v_00_u03b1_443_, lean_object* v_inst_444_, lean_object* v_x_445_){
_start:
{
uint64_t v_res_446_; lean_object* v_r_447_; 
v_res_446_ = lp_bounded_Bounded_instHashableSMap_hash(v_00_u03b1_443_, v_inst_444_, v_x_445_);
v_r_447_ = lean_box_uint64(v_res_446_);
return v_r_447_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instHashableSMap___redArg(lean_object* v_inst_448_){
_start:
{
lean_object* v___x_449_; 
v___x_449_ = lean_alloc_closure((void*)(lp_bounded_Bounded_instHashableSMap_hash___boxed), 3, 2);
lean_closure_set(v___x_449_, 0, lean_box(0));
lean_closure_set(v___x_449_, 1, v_inst_448_);
return v___x_449_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instHashableSMap(lean_object* v_00_u03b1_450_, lean_object* v_inst_451_){
_start:
{
lean_object* v___x_452_; 
v___x_452_ = lean_alloc_closure((void*)(lp_bounded_Bounded_instHashableSMap_hash___boxed), 3, 2);
lean_closure_set(v___x_452_, 0, lean_box(0));
lean_closure_set(v___x_452_, 1, v_inst_451_);
return v___x_452_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_SMap_get___redArg(lean_object* v_m_453_, lean_object* v_n_454_){
_start:
{
lean_object* v___x_455_; uint8_t v___x_456_; 
v___x_455_ = lean_unsigned_to_nat(0u);
v___x_456_ = lean_nat_dec_eq(v_n_454_, v___x_455_);
if (v___x_456_ == 0)
{
lean_object* v___x_457_; uint8_t v___x_458_; 
v___x_457_ = lean_unsigned_to_nat(1u);
v___x_458_ = lean_nat_dec_eq(v_n_454_, v___x_457_);
if (v___x_458_ == 0)
{
lean_object* v_s2_459_; 
v_s2_459_ = lean_ctor_get(v_m_453_, 2);
lean_inc(v_s2_459_);
return v_s2_459_;
}
else
{
lean_object* v_s1_460_; 
v_s1_460_ = lean_ctor_get(v_m_453_, 1);
lean_inc(v_s1_460_);
return v_s1_460_;
}
}
else
{
lean_object* v_s0_461_; 
v_s0_461_ = lean_ctor_get(v_m_453_, 0);
lean_inc(v_s0_461_);
return v_s0_461_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_SMap_get___redArg___boxed(lean_object* v_m_462_, lean_object* v_n_463_){
_start:
{
lean_object* v_res_464_; 
v_res_464_ = lp_bounded_Bounded_SMap_get___redArg(v_m_462_, v_n_463_);
lean_dec(v_n_463_);
lean_dec_ref(v_m_462_);
return v_res_464_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_SMap_get(lean_object* v_00_u03b1_465_, lean_object* v_m_466_, lean_object* v_n_467_){
_start:
{
lean_object* v___x_468_; 
v___x_468_ = lp_bounded_Bounded_SMap_get___redArg(v_m_466_, v_n_467_);
return v___x_468_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_SMap_get___boxed(lean_object* v_00_u03b1_469_, lean_object* v_m_470_, lean_object* v_n_471_){
_start:
{
lean_object* v_res_472_; 
v_res_472_ = lp_bounded_Bounded_SMap_get(v_00_u03b1_469_, v_m_470_, v_n_471_);
lean_dec(v_n_471_);
lean_dec_ref(v_m_470_);
return v_res_472_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_SMap_set___redArg(lean_object* v_m_473_, lean_object* v_n_474_, lean_object* v_v_475_){
_start:
{
lean_object* v___x_476_; uint8_t v___x_477_; 
v___x_476_ = lean_unsigned_to_nat(0u);
v___x_477_ = lean_nat_dec_eq(v_n_474_, v___x_476_);
if (v___x_477_ == 0)
{
lean_object* v___x_478_; uint8_t v___x_479_; 
v___x_478_ = lean_unsigned_to_nat(1u);
v___x_479_ = lean_nat_dec_eq(v_n_474_, v___x_478_);
if (v___x_479_ == 0)
{
lean_object* v_s0_480_; lean_object* v_s1_481_; lean_object* v___x_483_; uint8_t v_isShared_484_; uint8_t v_isSharedCheck_488_; 
v_s0_480_ = lean_ctor_get(v_m_473_, 0);
v_s1_481_ = lean_ctor_get(v_m_473_, 1);
v_isSharedCheck_488_ = !lean_is_exclusive(v_m_473_);
if (v_isSharedCheck_488_ == 0)
{
lean_object* v_unused_489_; 
v_unused_489_ = lean_ctor_get(v_m_473_, 2);
lean_dec(v_unused_489_);
v___x_483_ = v_m_473_;
v_isShared_484_ = v_isSharedCheck_488_;
goto v_resetjp_482_;
}
else
{
lean_inc(v_s1_481_);
lean_inc(v_s0_480_);
lean_dec(v_m_473_);
v___x_483_ = lean_box(0);
v_isShared_484_ = v_isSharedCheck_488_;
goto v_resetjp_482_;
}
v_resetjp_482_:
{
lean_object* v___x_486_; 
if (v_isShared_484_ == 0)
{
lean_ctor_set(v___x_483_, 2, v_v_475_);
v___x_486_ = v___x_483_;
goto v_reusejp_485_;
}
else
{
lean_object* v_reuseFailAlloc_487_; 
v_reuseFailAlloc_487_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v_reuseFailAlloc_487_, 0, v_s0_480_);
lean_ctor_set(v_reuseFailAlloc_487_, 1, v_s1_481_);
lean_ctor_set(v_reuseFailAlloc_487_, 2, v_v_475_);
v___x_486_ = v_reuseFailAlloc_487_;
goto v_reusejp_485_;
}
v_reusejp_485_:
{
return v___x_486_;
}
}
}
else
{
lean_object* v_s0_490_; lean_object* v_s2_491_; lean_object* v___x_493_; uint8_t v_isShared_494_; uint8_t v_isSharedCheck_498_; 
v_s0_490_ = lean_ctor_get(v_m_473_, 0);
v_s2_491_ = lean_ctor_get(v_m_473_, 2);
v_isSharedCheck_498_ = !lean_is_exclusive(v_m_473_);
if (v_isSharedCheck_498_ == 0)
{
lean_object* v_unused_499_; 
v_unused_499_ = lean_ctor_get(v_m_473_, 1);
lean_dec(v_unused_499_);
v___x_493_ = v_m_473_;
v_isShared_494_ = v_isSharedCheck_498_;
goto v_resetjp_492_;
}
else
{
lean_inc(v_s2_491_);
lean_inc(v_s0_490_);
lean_dec(v_m_473_);
v___x_493_ = lean_box(0);
v_isShared_494_ = v_isSharedCheck_498_;
goto v_resetjp_492_;
}
v_resetjp_492_:
{
lean_object* v___x_496_; 
if (v_isShared_494_ == 0)
{
lean_ctor_set(v___x_493_, 1, v_v_475_);
v___x_496_ = v___x_493_;
goto v_reusejp_495_;
}
else
{
lean_object* v_reuseFailAlloc_497_; 
v_reuseFailAlloc_497_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v_reuseFailAlloc_497_, 0, v_s0_490_);
lean_ctor_set(v_reuseFailAlloc_497_, 1, v_v_475_);
lean_ctor_set(v_reuseFailAlloc_497_, 2, v_s2_491_);
v___x_496_ = v_reuseFailAlloc_497_;
goto v_reusejp_495_;
}
v_reusejp_495_:
{
return v___x_496_;
}
}
}
}
else
{
lean_object* v_s1_500_; lean_object* v_s2_501_; lean_object* v___x_503_; uint8_t v_isShared_504_; uint8_t v_isSharedCheck_508_; 
v_s1_500_ = lean_ctor_get(v_m_473_, 1);
v_s2_501_ = lean_ctor_get(v_m_473_, 2);
v_isSharedCheck_508_ = !lean_is_exclusive(v_m_473_);
if (v_isSharedCheck_508_ == 0)
{
lean_object* v_unused_509_; 
v_unused_509_ = lean_ctor_get(v_m_473_, 0);
lean_dec(v_unused_509_);
v___x_503_ = v_m_473_;
v_isShared_504_ = v_isSharedCheck_508_;
goto v_resetjp_502_;
}
else
{
lean_inc(v_s2_501_);
lean_inc(v_s1_500_);
lean_dec(v_m_473_);
v___x_503_ = lean_box(0);
v_isShared_504_ = v_isSharedCheck_508_;
goto v_resetjp_502_;
}
v_resetjp_502_:
{
lean_object* v___x_506_; 
if (v_isShared_504_ == 0)
{
lean_ctor_set(v___x_503_, 0, v_v_475_);
v___x_506_ = v___x_503_;
goto v_reusejp_505_;
}
else
{
lean_object* v_reuseFailAlloc_507_; 
v_reuseFailAlloc_507_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v_reuseFailAlloc_507_, 0, v_v_475_);
lean_ctor_set(v_reuseFailAlloc_507_, 1, v_s1_500_);
lean_ctor_set(v_reuseFailAlloc_507_, 2, v_s2_501_);
v___x_506_ = v_reuseFailAlloc_507_;
goto v_reusejp_505_;
}
v_reusejp_505_:
{
return v___x_506_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_SMap_set___redArg___boxed(lean_object* v_m_510_, lean_object* v_n_511_, lean_object* v_v_512_){
_start:
{
lean_object* v_res_513_; 
v_res_513_ = lp_bounded_Bounded_SMap_set___redArg(v_m_510_, v_n_511_, v_v_512_);
lean_dec(v_n_511_);
return v_res_513_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_SMap_set(lean_object* v_00_u03b1_514_, lean_object* v_m_515_, lean_object* v_n_516_, lean_object* v_v_517_){
_start:
{
lean_object* v___x_518_; 
v___x_518_ = lp_bounded_Bounded_SMap_set___redArg(v_m_515_, v_n_516_, v_v_517_);
return v___x_518_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_SMap_set___boxed(lean_object* v_00_u03b1_519_, lean_object* v_m_520_, lean_object* v_n_521_, lean_object* v_v_522_){
_start:
{
lean_object* v_res_523_; 
v_res_523_ = lp_bounded_Bounded_SMap_set(v_00_u03b1_519_, v_m_520_, v_n_521_, v_v_522_);
lean_dec(v_n_521_);
return v_res_523_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_SMap_const___redArg(lean_object* v_v_524_){
_start:
{
lean_object* v___x_525_; 
lean_inc_n(v_v_524_, 2);
v___x_525_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_525_, 0, v_v_524_);
lean_ctor_set(v___x_525_, 1, v_v_524_);
lean_ctor_set(v___x_525_, 2, v_v_524_);
return v___x_525_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_SMap_const(lean_object* v_00_u03b1_526_, lean_object* v_v_527_){
_start:
{
lean_object* v___x_528_; 
lean_inc_n(v_v_527_, 2);
v___x_528_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_528_, 0, v_v_527_);
lean_ctor_set(v___x_528_, 1, v_v_527_);
lean_ctor_set(v___x_528_, 2, v_v_527_);
return v___x_528_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumSMap___redArg___lam__0(lean_object* v_p_529_){
_start:
{
lean_object* v_snd_530_; lean_object* v_fst_531_; lean_object* v_fst_532_; lean_object* v_snd_533_; lean_object* v___x_534_; 
v_snd_530_ = lean_ctor_get(v_p_529_, 1);
v_fst_531_ = lean_ctor_get(v_p_529_, 0);
v_fst_532_ = lean_ctor_get(v_snd_530_, 0);
v_snd_533_ = lean_ctor_get(v_snd_530_, 1);
lean_inc(v_snd_533_);
lean_inc(v_fst_532_);
lean_inc(v_fst_531_);
v___x_534_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_534_, 0, v_fst_531_);
lean_ctor_set(v___x_534_, 1, v_fst_532_);
lean_ctor_set(v___x_534_, 2, v_snd_533_);
return v___x_534_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumSMap___redArg___lam__0___boxed(lean_object* v_p_535_){
_start:
{
lean_object* v_res_536_; 
v_res_536_ = lp_bounded_Bounded_instFinEnumSMap___redArg___lam__0(v_p_535_);
lean_dec_ref(v_p_535_);
return v_res_536_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumSMap___redArg___lam__3(lean_object* v_a_537_, lean_object* v_b_538_){
_start:
{
lean_object* v___x_539_; 
v___x_539_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_539_, 0, v_a_537_);
lean_ctor_set(v___x_539_, 1, v_b_538_);
return v___x_539_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumSMap___redArg___lam__1(lean_object* v___f_540_, lean_object* v_inst_541_, lean_object* v_a_542_){
_start:
{
lean_object* v___f_543_; lean_object* v___x_544_; lean_object* v___x_545_; lean_object* v___x_546_; lean_object* v___x_547_; 
v___f_543_ = lean_alloc_closure((void*)(lp_bounded_Bounded_instFinEnumSMap___redArg___lam__3), 2, 1);
lean_closure_set(v___f_543_, 0, v_a_542_);
v___x_544_ = ((lean_object*)(lp_bounded_Bounded_instFinEnumKMap___redArg___closed__1));
v___x_545_ = l___private_Init_Data_List_Impl_0__List_flatMapTR_go___redArg(v___f_540_, v_inst_541_, v___x_544_);
v___x_546_ = lean_box(0);
v___x_547_ = l_List_mapTR_loop___redArg(v___f_543_, v___x_545_, v___x_546_);
return v___x_547_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumSMap___redArg(lean_object* v_inst_551_){
_start:
{
lean_object* v___f_552_; lean_object* v___f_553_; lean_object* v___f_554_; lean_object* v___x_555_; lean_object* v___x_556_; lean_object* v___x_557_; lean_object* v___x_558_; 
v___f_552_ = ((lean_object*)(lp_bounded_Bounded_instFinEnumSMap___redArg___closed__0));
lean_inc_n(v_inst_551_, 2);
v___f_553_ = lean_alloc_closure((void*)(lp_bounded_Bounded_instFinEnumKMap___redArg___lam__2), 2, 1);
lean_closure_set(v___f_553_, 0, v_inst_551_);
v___f_554_ = lean_alloc_closure((void*)(lp_bounded_Bounded_instFinEnumSMap___redArg___lam__1), 3, 2);
lean_closure_set(v___f_554_, 0, v___f_553_);
lean_closure_set(v___f_554_, 1, v_inst_551_);
v___x_555_ = ((lean_object*)(lp_bounded_Bounded_instFinEnumSMap___redArg___closed__1));
v___x_556_ = l___private_Init_Data_List_Impl_0__List_flatMapTR_go___redArg(v___f_554_, v_inst_551_, v___x_555_);
v___x_557_ = lean_box(0);
v___x_558_ = l_List_mapTR_loop___redArg(v___f_552_, v___x_556_, v___x_557_);
return v___x_558_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumSMap(lean_object* v_00_u03b1_559_, lean_object* v_inst_560_){
_start:
{
lean_object* v___x_561_; 
v___x_561_ = lp_bounded_Bounded_instFinEnumSMap___redArg(v_inst_560_);
return v___x_561_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Step_ctorIdx(lean_object* v_x_562_){
_start:
{
switch(lean_obj_tag(v_x_562_))
{
case 0:
{
lean_object* v___x_563_; 
v___x_563_ = lean_unsigned_to_nat(0u);
return v___x_563_;
}
case 1:
{
lean_object* v___x_564_; 
v___x_564_ = lean_unsigned_to_nat(1u);
return v___x_564_;
}
case 2:
{
lean_object* v___x_565_; 
v___x_565_ = lean_unsigned_to_nat(2u);
return v___x_565_;
}
case 3:
{
lean_object* v___x_566_; 
v___x_566_ = lean_unsigned_to_nat(3u);
return v___x_566_;
}
case 4:
{
lean_object* v___x_567_; 
v___x_567_ = lean_unsigned_to_nat(4u);
return v___x_567_;
}
default: 
{
lean_object* v___x_568_; 
v___x_568_ = lean_unsigned_to_nat(5u);
return v___x_568_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Step_ctorIdx___boxed(lean_object* v_x_569_){
_start:
{
lean_object* v_res_570_; 
v_res_570_ = lp_bounded_Bounded_Step_ctorIdx(v_x_569_);
lean_dec(v_x_569_);
return v_res_570_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Step_ctorElim___redArg(lean_object* v_t_571_, lean_object* v_k_572_){
_start:
{
switch(lean_obj_tag(v_t_571_))
{
case 0:
{
lean_object* v_k_573_; lean_object* v_v_574_; lean_object* v___x_575_; 
v_k_573_ = lean_ctor_get(v_t_571_, 0);
lean_inc(v_k_573_);
v_v_574_ = lean_ctor_get(v_t_571_, 1);
lean_inc(v_v_574_);
lean_dec_ref_known(v_t_571_, 2);
v___x_575_ = lean_apply_2(v_k_572_, v_k_573_, v_v_574_);
return v___x_575_;
}
case 1:
{
lean_object* v_t_576_; lean_object* v___x_577_; 
v_t_576_ = lean_ctor_get(v_t_571_, 0);
lean_inc(v_t_576_);
lean_dec_ref_known(v_t_571_, 1);
v___x_577_ = lean_apply_1(v_k_572_, v_t_576_);
return v___x_577_;
}
case 2:
{
lean_object* v_k_578_; lean_object* v___x_579_; 
v_k_578_ = lean_ctor_get(v_t_571_, 0);
lean_inc(v_k_578_);
lean_dec_ref_known(v_t_571_, 1);
v___x_579_ = lean_apply_1(v_k_572_, v_k_578_);
return v___x_579_;
}
case 3:
{
lean_object* v_k_580_; lean_object* v_v_581_; lean_object* v___x_582_; 
v_k_580_ = lean_ctor_get(v_t_571_, 0);
lean_inc(v_k_580_);
v_v_581_ = lean_ctor_get(v_t_571_, 1);
lean_inc(v_v_581_);
lean_dec_ref_known(v_t_571_, 2);
v___x_582_ = lean_apply_2(v_k_572_, v_k_580_, v_v_581_);
return v___x_582_;
}
default: 
{
lean_dec(v_t_571_);
return v_k_572_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Step_ctorElim(lean_object* v_motive_583_, lean_object* v_ctorIdx_584_, lean_object* v_t_585_, lean_object* v_h_586_, lean_object* v_k_587_){
_start:
{
lean_object* v___x_588_; 
v___x_588_ = lp_bounded_Bounded_Step_ctorElim___redArg(v_t_585_, v_k_587_);
return v___x_588_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Step_ctorElim___boxed(lean_object* v_motive_589_, lean_object* v_ctorIdx_590_, lean_object* v_t_591_, lean_object* v_h_592_, lean_object* v_k_593_){
_start:
{
lean_object* v_res_594_; 
v_res_594_ = lp_bounded_Bounded_Step_ctorElim(v_motive_589_, v_ctorIdx_590_, v_t_591_, v_h_592_, v_k_593_);
lean_dec(v_ctorIdx_590_);
return v_res_594_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Step_provide_elim___redArg(lean_object* v_t_595_, lean_object* v_provide_596_){
_start:
{
lean_object* v___x_597_; 
v___x_597_ = lp_bounded_Bounded_Step_ctorElim___redArg(v_t_595_, v_provide_596_);
return v___x_597_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Step_provide_elim(lean_object* v_motive_598_, lean_object* v_t_599_, lean_object* v_h_600_, lean_object* v_provide_601_){
_start:
{
lean_object* v___x_602_; 
v___x_602_ = lp_bounded_Bounded_Step_ctorElim___redArg(v_t_599_, v_provide_601_);
return v___x_602_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Step_track_elim___redArg(lean_object* v_t_603_, lean_object* v_track_604_){
_start:
{
lean_object* v___x_605_; 
v___x_605_ = lp_bounded_Bounded_Step_ctorElim___redArg(v_t_603_, v_track_604_);
return v___x_605_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Step_track_elim(lean_object* v_motive_606_, lean_object* v_t_607_, lean_object* v_h_608_, lean_object* v_track_609_){
_start:
{
lean_object* v___x_610_; 
v___x_610_ = lp_bounded_Bounded_Step_ctorElim___redArg(v_t_607_, v_track_609_);
return v___x_610_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Step_read_elim___redArg(lean_object* v_t_611_, lean_object* v_read_612_){
_start:
{
lean_object* v___x_613_; 
v___x_613_ = lp_bounded_Bounded_Step_ctorElim___redArg(v_t_611_, v_read_612_);
return v___x_613_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Step_read_elim(lean_object* v_motive_614_, lean_object* v_t_615_, lean_object* v_h_616_, lean_object* v_read_617_){
_start:
{
lean_object* v___x_618_; 
v___x_618_ = lp_bounded_Bounded_Step_ctorElim___redArg(v_t_615_, v_read_617_);
return v___x_618_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Step_setval_elim___redArg(lean_object* v_t_619_, lean_object* v_setval_620_){
_start:
{
lean_object* v___x_621_; 
v___x_621_ = lp_bounded_Bounded_Step_ctorElim___redArg(v_t_619_, v_setval_620_);
return v___x_621_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Step_setval_elim(lean_object* v_motive_622_, lean_object* v_t_623_, lean_object* v_h_624_, lean_object* v_setval_625_){
_start:
{
lean_object* v___x_626_; 
v___x_626_ = lp_bounded_Bounded_Step_ctorElim___redArg(v_t_623_, v_setval_625_);
return v___x_626_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Step_register_elim___redArg(lean_object* v_t_627_, lean_object* v_register_628_){
_start:
{
lean_object* v___x_629_; 
v___x_629_ = lp_bounded_Bounded_Step_ctorElim___redArg(v_t_627_, v_register_628_);
return v___x_629_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Step_register_elim(lean_object* v_motive_630_, lean_object* v_t_631_, lean_object* v_h_632_, lean_object* v_register_633_){
_start:
{
lean_object* v___x_634_; 
v___x_634_ = lp_bounded_Bounded_Step_ctorElim___redArg(v_t_631_, v_register_633_);
return v___x_634_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Step_raise_elim___redArg(lean_object* v_t_635_, lean_object* v_raise_636_){
_start:
{
lean_object* v___x_637_; 
v___x_637_ = lp_bounded_Bounded_Step_ctorElim___redArg(v_t_635_, v_raise_636_);
return v___x_637_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Step_raise_elim(lean_object* v_motive_638_, lean_object* v_t_639_, lean_object* v_h_640_, lean_object* v_raise_641_){
_start:
{
lean_object* v___x_642_; 
v___x_642_ = lp_bounded_Bounded_Step_ctorElim___redArg(v_t_639_, v_raise_641_);
return v___x_642_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqStep_decEq(lean_object* v_x_643_, lean_object* v_x_644_){
_start:
{
switch(lean_obj_tag(v_x_643_))
{
case 0:
{
lean_object* v_k_645_; lean_object* v_v_646_; uint8_t v___x_647_; 
v_k_645_ = lean_ctor_get(v_x_643_, 0);
v_v_646_ = lean_ctor_get(v_x_643_, 1);
v___x_647_ = 0;
switch(lean_obj_tag(v_x_644_))
{
case 0:
{
lean_object* v_k_648_; lean_object* v_v_649_; uint8_t v___x_650_; 
v_k_648_ = lean_ctor_get(v_x_644_, 0);
v_v_649_ = lean_ctor_get(v_x_644_, 1);
v___x_650_ = lean_nat_dec_eq(v_k_645_, v_k_648_);
if (v___x_650_ == 0)
{
return v___x_647_;
}
else
{
uint8_t v___x_651_; 
v___x_651_ = lean_nat_dec_eq(v_v_646_, v_v_649_);
if (v___x_651_ == 0)
{
return v___x_647_;
}
else
{
return v___x_651_;
}
}
}
case 4:
{
return v___x_647_;
}
case 5:
{
return v___x_647_;
}
default: 
{
return v___x_647_;
}
}
}
case 1:
{
lean_object* v_t_652_; uint8_t v___x_653_; 
v_t_652_ = lean_ctor_get(v_x_643_, 0);
v___x_653_ = 0;
switch(lean_obj_tag(v_x_644_))
{
case 1:
{
lean_object* v_t_654_; uint8_t v___x_655_; 
v_t_654_ = lean_ctor_get(v_x_644_, 0);
v___x_655_ = lean_nat_dec_eq(v_t_652_, v_t_654_);
if (v___x_655_ == 0)
{
return v___x_653_;
}
else
{
return v___x_655_;
}
}
case 4:
{
return v___x_653_;
}
case 5:
{
return v___x_653_;
}
default: 
{
return v___x_653_;
}
}
}
case 2:
{
lean_object* v_k_656_; uint8_t v___x_657_; 
v_k_656_ = lean_ctor_get(v_x_643_, 0);
v___x_657_ = 0;
switch(lean_obj_tag(v_x_644_))
{
case 2:
{
lean_object* v_k_658_; uint8_t v___x_659_; 
v_k_658_ = lean_ctor_get(v_x_644_, 0);
v___x_659_ = lean_nat_dec_eq(v_k_656_, v_k_658_);
if (v___x_659_ == 0)
{
return v___x_657_;
}
else
{
return v___x_659_;
}
}
case 4:
{
return v___x_657_;
}
case 5:
{
return v___x_657_;
}
default: 
{
return v___x_657_;
}
}
}
case 3:
{
lean_object* v_k_660_; lean_object* v_v_661_; uint8_t v___x_662_; 
v_k_660_ = lean_ctor_get(v_x_643_, 0);
v_v_661_ = lean_ctor_get(v_x_643_, 1);
v___x_662_ = 0;
switch(lean_obj_tag(v_x_644_))
{
case 3:
{
lean_object* v_k_663_; lean_object* v_v_664_; uint8_t v___x_665_; 
v_k_663_ = lean_ctor_get(v_x_644_, 0);
v_v_664_ = lean_ctor_get(v_x_644_, 1);
v___x_665_ = lean_nat_dec_eq(v_k_660_, v_k_663_);
if (v___x_665_ == 0)
{
return v___x_662_;
}
else
{
uint8_t v___x_666_; 
v___x_666_ = lean_nat_dec_eq(v_v_661_, v_v_664_);
if (v___x_666_ == 0)
{
return v___x_662_;
}
else
{
return v___x_666_;
}
}
}
case 4:
{
return v___x_662_;
}
case 5:
{
return v___x_662_;
}
default: 
{
return v___x_662_;
}
}
}
case 4:
{
switch(lean_obj_tag(v_x_644_))
{
case 4:
{
uint8_t v___x_667_; 
v___x_667_ = 1;
return v___x_667_;
}
case 5:
{
uint8_t v___x_668_; 
v___x_668_ = 0;
return v___x_668_;
}
default: 
{
uint8_t v___x_669_; 
v___x_669_ = 0;
return v___x_669_;
}
}
}
default: 
{
switch(lean_obj_tag(v_x_644_))
{
case 4:
{
uint8_t v___x_670_; 
v___x_670_ = 0;
return v___x_670_;
}
case 5:
{
uint8_t v___x_671_; 
v___x_671_ = 1;
return v___x_671_;
}
default: 
{
uint8_t v___x_672_; 
v___x_672_ = 0;
return v___x_672_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqStep_decEq___boxed(lean_object* v_x_673_, lean_object* v_x_674_){
_start:
{
uint8_t v_res_675_; lean_object* v_r_676_; 
v_res_675_ = lp_bounded_Bounded_instDecidableEqStep_decEq(v_x_673_, v_x_674_);
lean_dec(v_x_674_);
lean_dec(v_x_673_);
v_r_676_ = lean_box(v_res_675_);
return v_r_676_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqStep(lean_object* v_x_677_, lean_object* v_x_678_){
_start:
{
uint8_t v___x_679_; 
v___x_679_ = lp_bounded_Bounded_instDecidableEqStep_decEq(v_x_677_, v_x_678_);
return v___x_679_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqStep___boxed(lean_object* v_x_680_, lean_object* v_x_681_){
_start:
{
uint8_t v_res_682_; lean_object* v_r_683_; 
v_res_682_ = lp_bounded_Bounded_instDecidableEqStep(v_x_680_, v_x_681_);
lean_dec(v_x_681_);
lean_dec(v_x_680_);
v_r_683_ = lean_box(v_res_682_);
return v_r_683_;
}
}
static lean_object* _init_lp_bounded_Bounded_instReprStep_repr___closed__7(void){
_start:
{
lean_object* v___x_696_; lean_object* v___x_697_; 
v___x_696_ = lean_unsigned_to_nat(2u);
v___x_697_ = lean_nat_to_int(v___x_696_);
return v___x_697_;
}
}
static lean_object* _init_lp_bounded_Bounded_instReprStep_repr___closed__8(void){
_start:
{
lean_object* v___x_698_; lean_object* v___x_699_; 
v___x_698_ = lean_unsigned_to_nat(1u);
v___x_699_ = lean_nat_to_int(v___x_698_);
return v___x_699_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprStep_repr(lean_object* v_x_718_, lean_object* v_prec_719_){
_start:
{
lean_object* v___y_721_; lean_object* v___y_728_; 
switch(lean_obj_tag(v_x_718_))
{
case 0:
{
lean_object* v_k_734_; lean_object* v_v_735_; lean_object* v___x_737_; uint8_t v_isShared_738_; uint8_t v_isSharedCheck_760_; 
v_k_734_ = lean_ctor_get(v_x_718_, 0);
v_v_735_ = lean_ctor_get(v_x_718_, 1);
v_isSharedCheck_760_ = !lean_is_exclusive(v_x_718_);
if (v_isSharedCheck_760_ == 0)
{
v___x_737_ = v_x_718_;
v_isShared_738_ = v_isSharedCheck_760_;
goto v_resetjp_736_;
}
else
{
lean_inc(v_v_735_);
lean_inc(v_k_734_);
lean_dec(v_x_718_);
v___x_737_ = lean_box(0);
v_isShared_738_ = v_isSharedCheck_760_;
goto v_resetjp_736_;
}
v_resetjp_736_:
{
lean_object* v___y_740_; lean_object* v___x_756_; uint8_t v___x_757_; 
v___x_756_ = lean_unsigned_to_nat(1024u);
v___x_757_ = lean_nat_dec_le(v___x_756_, v_prec_719_);
if (v___x_757_ == 0)
{
lean_object* v___x_758_; 
v___x_758_ = lean_obj_once(&lp_bounded_Bounded_instReprStep_repr___closed__7, &lp_bounded_Bounded_instReprStep_repr___closed__7_once, _init_lp_bounded_Bounded_instReprStep_repr___closed__7);
v___y_740_ = v___x_758_;
goto v___jp_739_;
}
else
{
lean_object* v___x_759_; 
v___x_759_ = lean_obj_once(&lp_bounded_Bounded_instReprStep_repr___closed__8, &lp_bounded_Bounded_instReprStep_repr___closed__8_once, _init_lp_bounded_Bounded_instReprStep_repr___closed__8);
v___y_740_ = v___x_759_;
goto v___jp_739_;
}
v___jp_739_:
{
lean_object* v___x_741_; lean_object* v___x_742_; lean_object* v___x_743_; lean_object* v___x_744_; lean_object* v___x_746_; 
v___x_741_ = lean_box(1);
v___x_742_ = ((lean_object*)(lp_bounded_Bounded_instReprStep_repr___closed__6));
v___x_743_ = l_Nat_reprFast(v_k_734_);
v___x_744_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_744_, 0, v___x_743_);
if (v_isShared_738_ == 0)
{
lean_ctor_set_tag(v___x_737_, 5);
lean_ctor_set(v___x_737_, 1, v___x_744_);
lean_ctor_set(v___x_737_, 0, v___x_742_);
v___x_746_ = v___x_737_;
goto v_reusejp_745_;
}
else
{
lean_object* v_reuseFailAlloc_755_; 
v_reuseFailAlloc_755_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v_reuseFailAlloc_755_, 0, v___x_742_);
lean_ctor_set(v_reuseFailAlloc_755_, 1, v___x_744_);
v___x_746_ = v_reuseFailAlloc_755_;
goto v_reusejp_745_;
}
v_reusejp_745_:
{
lean_object* v___x_747_; lean_object* v___x_748_; lean_object* v___x_749_; lean_object* v___x_750_; lean_object* v___x_751_; uint8_t v___x_752_; lean_object* v___x_753_; lean_object* v___x_754_; 
v___x_747_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_747_, 0, v___x_746_);
lean_ctor_set(v___x_747_, 1, v___x_741_);
v___x_748_ = l_Nat_reprFast(v_v_735_);
v___x_749_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_749_, 0, v___x_748_);
v___x_750_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_750_, 0, v___x_747_);
lean_ctor_set(v___x_750_, 1, v___x_749_);
lean_inc(v___y_740_);
v___x_751_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_751_, 0, v___y_740_);
lean_ctor_set(v___x_751_, 1, v___x_750_);
v___x_752_ = 0;
v___x_753_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_753_, 0, v___x_751_);
lean_ctor_set_uint8(v___x_753_, sizeof(void*)*1, v___x_752_);
v___x_754_ = l_Repr_addAppParen(v___x_753_, v_prec_719_);
return v___x_754_;
}
}
}
}
case 1:
{
lean_object* v_t_761_; lean_object* v___x_763_; uint8_t v_isShared_764_; uint8_t v_isSharedCheck_781_; 
v_t_761_ = lean_ctor_get(v_x_718_, 0);
v_isSharedCheck_781_ = !lean_is_exclusive(v_x_718_);
if (v_isSharedCheck_781_ == 0)
{
v___x_763_ = v_x_718_;
v_isShared_764_ = v_isSharedCheck_781_;
goto v_resetjp_762_;
}
else
{
lean_inc(v_t_761_);
lean_dec(v_x_718_);
v___x_763_ = lean_box(0);
v_isShared_764_ = v_isSharedCheck_781_;
goto v_resetjp_762_;
}
v_resetjp_762_:
{
lean_object* v___y_766_; lean_object* v___x_777_; uint8_t v___x_778_; 
v___x_777_ = lean_unsigned_to_nat(1024u);
v___x_778_ = lean_nat_dec_le(v___x_777_, v_prec_719_);
if (v___x_778_ == 0)
{
lean_object* v___x_779_; 
v___x_779_ = lean_obj_once(&lp_bounded_Bounded_instReprStep_repr___closed__7, &lp_bounded_Bounded_instReprStep_repr___closed__7_once, _init_lp_bounded_Bounded_instReprStep_repr___closed__7);
v___y_766_ = v___x_779_;
goto v___jp_765_;
}
else
{
lean_object* v___x_780_; 
v___x_780_ = lean_obj_once(&lp_bounded_Bounded_instReprStep_repr___closed__8, &lp_bounded_Bounded_instReprStep_repr___closed__8_once, _init_lp_bounded_Bounded_instReprStep_repr___closed__8);
v___y_766_ = v___x_780_;
goto v___jp_765_;
}
v___jp_765_:
{
lean_object* v___x_767_; lean_object* v___x_768_; lean_object* v___x_770_; 
v___x_767_ = ((lean_object*)(lp_bounded_Bounded_instReprStep_repr___closed__11));
v___x_768_ = l_Nat_reprFast(v_t_761_);
if (v_isShared_764_ == 0)
{
lean_ctor_set_tag(v___x_763_, 3);
lean_ctor_set(v___x_763_, 0, v___x_768_);
v___x_770_ = v___x_763_;
goto v_reusejp_769_;
}
else
{
lean_object* v_reuseFailAlloc_776_; 
v_reuseFailAlloc_776_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v_reuseFailAlloc_776_, 0, v___x_768_);
v___x_770_ = v_reuseFailAlloc_776_;
goto v_reusejp_769_;
}
v_reusejp_769_:
{
lean_object* v___x_771_; lean_object* v___x_772_; uint8_t v___x_773_; lean_object* v___x_774_; lean_object* v___x_775_; 
v___x_771_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_771_, 0, v___x_767_);
lean_ctor_set(v___x_771_, 1, v___x_770_);
lean_inc(v___y_766_);
v___x_772_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_772_, 0, v___y_766_);
lean_ctor_set(v___x_772_, 1, v___x_771_);
v___x_773_ = 0;
v___x_774_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_774_, 0, v___x_772_);
lean_ctor_set_uint8(v___x_774_, sizeof(void*)*1, v___x_773_);
v___x_775_ = l_Repr_addAppParen(v___x_774_, v_prec_719_);
return v___x_775_;
}
}
}
}
case 2:
{
lean_object* v_k_782_; lean_object* v___x_784_; uint8_t v_isShared_785_; uint8_t v_isSharedCheck_802_; 
v_k_782_ = lean_ctor_get(v_x_718_, 0);
v_isSharedCheck_802_ = !lean_is_exclusive(v_x_718_);
if (v_isSharedCheck_802_ == 0)
{
v___x_784_ = v_x_718_;
v_isShared_785_ = v_isSharedCheck_802_;
goto v_resetjp_783_;
}
else
{
lean_inc(v_k_782_);
lean_dec(v_x_718_);
v___x_784_ = lean_box(0);
v_isShared_785_ = v_isSharedCheck_802_;
goto v_resetjp_783_;
}
v_resetjp_783_:
{
lean_object* v___y_787_; lean_object* v___x_798_; uint8_t v___x_799_; 
v___x_798_ = lean_unsigned_to_nat(1024u);
v___x_799_ = lean_nat_dec_le(v___x_798_, v_prec_719_);
if (v___x_799_ == 0)
{
lean_object* v___x_800_; 
v___x_800_ = lean_obj_once(&lp_bounded_Bounded_instReprStep_repr___closed__7, &lp_bounded_Bounded_instReprStep_repr___closed__7_once, _init_lp_bounded_Bounded_instReprStep_repr___closed__7);
v___y_787_ = v___x_800_;
goto v___jp_786_;
}
else
{
lean_object* v___x_801_; 
v___x_801_ = lean_obj_once(&lp_bounded_Bounded_instReprStep_repr___closed__8, &lp_bounded_Bounded_instReprStep_repr___closed__8_once, _init_lp_bounded_Bounded_instReprStep_repr___closed__8);
v___y_787_ = v___x_801_;
goto v___jp_786_;
}
v___jp_786_:
{
lean_object* v___x_788_; lean_object* v___x_789_; lean_object* v___x_791_; 
v___x_788_ = ((lean_object*)(lp_bounded_Bounded_instReprStep_repr___closed__14));
v___x_789_ = l_Nat_reprFast(v_k_782_);
if (v_isShared_785_ == 0)
{
lean_ctor_set_tag(v___x_784_, 3);
lean_ctor_set(v___x_784_, 0, v___x_789_);
v___x_791_ = v___x_784_;
goto v_reusejp_790_;
}
else
{
lean_object* v_reuseFailAlloc_797_; 
v_reuseFailAlloc_797_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v_reuseFailAlloc_797_, 0, v___x_789_);
v___x_791_ = v_reuseFailAlloc_797_;
goto v_reusejp_790_;
}
v_reusejp_790_:
{
lean_object* v___x_792_; lean_object* v___x_793_; uint8_t v___x_794_; lean_object* v___x_795_; lean_object* v___x_796_; 
v___x_792_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_792_, 0, v___x_788_);
lean_ctor_set(v___x_792_, 1, v___x_791_);
lean_inc(v___y_787_);
v___x_793_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_793_, 0, v___y_787_);
lean_ctor_set(v___x_793_, 1, v___x_792_);
v___x_794_ = 0;
v___x_795_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_795_, 0, v___x_793_);
lean_ctor_set_uint8(v___x_795_, sizeof(void*)*1, v___x_794_);
v___x_796_ = l_Repr_addAppParen(v___x_795_, v_prec_719_);
return v___x_796_;
}
}
}
}
case 3:
{
lean_object* v_k_803_; lean_object* v_v_804_; lean_object* v___x_806_; uint8_t v_isShared_807_; uint8_t v_isSharedCheck_829_; 
v_k_803_ = lean_ctor_get(v_x_718_, 0);
v_v_804_ = lean_ctor_get(v_x_718_, 1);
v_isSharedCheck_829_ = !lean_is_exclusive(v_x_718_);
if (v_isSharedCheck_829_ == 0)
{
v___x_806_ = v_x_718_;
v_isShared_807_ = v_isSharedCheck_829_;
goto v_resetjp_805_;
}
else
{
lean_inc(v_v_804_);
lean_inc(v_k_803_);
lean_dec(v_x_718_);
v___x_806_ = lean_box(0);
v_isShared_807_ = v_isSharedCheck_829_;
goto v_resetjp_805_;
}
v_resetjp_805_:
{
lean_object* v___y_809_; lean_object* v___x_825_; uint8_t v___x_826_; 
v___x_825_ = lean_unsigned_to_nat(1024u);
v___x_826_ = lean_nat_dec_le(v___x_825_, v_prec_719_);
if (v___x_826_ == 0)
{
lean_object* v___x_827_; 
v___x_827_ = lean_obj_once(&lp_bounded_Bounded_instReprStep_repr___closed__7, &lp_bounded_Bounded_instReprStep_repr___closed__7_once, _init_lp_bounded_Bounded_instReprStep_repr___closed__7);
v___y_809_ = v___x_827_;
goto v___jp_808_;
}
else
{
lean_object* v___x_828_; 
v___x_828_ = lean_obj_once(&lp_bounded_Bounded_instReprStep_repr___closed__8, &lp_bounded_Bounded_instReprStep_repr___closed__8_once, _init_lp_bounded_Bounded_instReprStep_repr___closed__8);
v___y_809_ = v___x_828_;
goto v___jp_808_;
}
v___jp_808_:
{
lean_object* v___x_810_; lean_object* v___x_811_; lean_object* v___x_812_; lean_object* v___x_813_; lean_object* v___x_815_; 
v___x_810_ = lean_box(1);
v___x_811_ = ((lean_object*)(lp_bounded_Bounded_instReprStep_repr___closed__17));
v___x_812_ = l_Nat_reprFast(v_k_803_);
v___x_813_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_813_, 0, v___x_812_);
if (v_isShared_807_ == 0)
{
lean_ctor_set_tag(v___x_806_, 5);
lean_ctor_set(v___x_806_, 1, v___x_813_);
lean_ctor_set(v___x_806_, 0, v___x_811_);
v___x_815_ = v___x_806_;
goto v_reusejp_814_;
}
else
{
lean_object* v_reuseFailAlloc_824_; 
v_reuseFailAlloc_824_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v_reuseFailAlloc_824_, 0, v___x_811_);
lean_ctor_set(v_reuseFailAlloc_824_, 1, v___x_813_);
v___x_815_ = v_reuseFailAlloc_824_;
goto v_reusejp_814_;
}
v_reusejp_814_:
{
lean_object* v___x_816_; lean_object* v___x_817_; lean_object* v___x_818_; lean_object* v___x_819_; lean_object* v___x_820_; uint8_t v___x_821_; lean_object* v___x_822_; lean_object* v___x_823_; 
v___x_816_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_816_, 0, v___x_815_);
lean_ctor_set(v___x_816_, 1, v___x_810_);
v___x_817_ = l_Nat_reprFast(v_v_804_);
v___x_818_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_818_, 0, v___x_817_);
v___x_819_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_819_, 0, v___x_816_);
lean_ctor_set(v___x_819_, 1, v___x_818_);
lean_inc(v___y_809_);
v___x_820_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_820_, 0, v___y_809_);
lean_ctor_set(v___x_820_, 1, v___x_819_);
v___x_821_ = 0;
v___x_822_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_822_, 0, v___x_820_);
lean_ctor_set_uint8(v___x_822_, sizeof(void*)*1, v___x_821_);
v___x_823_ = l_Repr_addAppParen(v___x_822_, v_prec_719_);
return v___x_823_;
}
}
}
}
case 4:
{
lean_object* v___x_830_; uint8_t v___x_831_; 
v___x_830_ = lean_unsigned_to_nat(1024u);
v___x_831_ = lean_nat_dec_le(v___x_830_, v_prec_719_);
if (v___x_831_ == 0)
{
lean_object* v___x_832_; 
v___x_832_ = lean_obj_once(&lp_bounded_Bounded_instReprStep_repr___closed__7, &lp_bounded_Bounded_instReprStep_repr___closed__7_once, _init_lp_bounded_Bounded_instReprStep_repr___closed__7);
v___y_721_ = v___x_832_;
goto v___jp_720_;
}
else
{
lean_object* v___x_833_; 
v___x_833_ = lean_obj_once(&lp_bounded_Bounded_instReprStep_repr___closed__8, &lp_bounded_Bounded_instReprStep_repr___closed__8_once, _init_lp_bounded_Bounded_instReprStep_repr___closed__8);
v___y_721_ = v___x_833_;
goto v___jp_720_;
}
}
default: 
{
lean_object* v___x_834_; uint8_t v___x_835_; 
v___x_834_ = lean_unsigned_to_nat(1024u);
v___x_835_ = lean_nat_dec_le(v___x_834_, v_prec_719_);
if (v___x_835_ == 0)
{
lean_object* v___x_836_; 
v___x_836_ = lean_obj_once(&lp_bounded_Bounded_instReprStep_repr___closed__7, &lp_bounded_Bounded_instReprStep_repr___closed__7_once, _init_lp_bounded_Bounded_instReprStep_repr___closed__7);
v___y_728_ = v___x_836_;
goto v___jp_727_;
}
else
{
lean_object* v___x_837_; 
v___x_837_ = lean_obj_once(&lp_bounded_Bounded_instReprStep_repr___closed__8, &lp_bounded_Bounded_instReprStep_repr___closed__8_once, _init_lp_bounded_Bounded_instReprStep_repr___closed__8);
v___y_728_ = v___x_837_;
goto v___jp_727_;
}
}
}
v___jp_720_:
{
lean_object* v___x_722_; lean_object* v___x_723_; uint8_t v___x_724_; lean_object* v___x_725_; lean_object* v___x_726_; 
v___x_722_ = ((lean_object*)(lp_bounded_Bounded_instReprStep_repr___closed__1));
lean_inc(v___y_721_);
v___x_723_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_723_, 0, v___y_721_);
lean_ctor_set(v___x_723_, 1, v___x_722_);
v___x_724_ = 0;
v___x_725_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_725_, 0, v___x_723_);
lean_ctor_set_uint8(v___x_725_, sizeof(void*)*1, v___x_724_);
v___x_726_ = l_Repr_addAppParen(v___x_725_, v_prec_719_);
return v___x_726_;
}
v___jp_727_:
{
lean_object* v___x_729_; lean_object* v___x_730_; uint8_t v___x_731_; lean_object* v___x_732_; lean_object* v___x_733_; 
v___x_729_ = ((lean_object*)(lp_bounded_Bounded_instReprStep_repr___closed__3));
lean_inc(v___y_728_);
v___x_730_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_730_, 0, v___y_728_);
lean_ctor_set(v___x_730_, 1, v___x_729_);
v___x_731_ = 0;
v___x_732_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_732_, 0, v___x_730_);
lean_ctor_set_uint8(v___x_732_, sizeof(void*)*1, v___x_731_);
v___x_733_ = l_Repr_addAppParen(v___x_732_, v_prec_719_);
return v___x_733_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprStep_repr___boxed(lean_object* v_x_838_, lean_object* v_prec_839_){
_start:
{
lean_object* v_res_840_; 
v_res_840_ = lp_bounded_Bounded_instReprStep_repr(v_x_838_, v_prec_839_);
lean_dec(v_prec_839_);
return v_res_840_;
}
}
LEAN_EXPORT uint64_t lp_bounded_Bounded_instHashableStep_hash(lean_object* v_x_843_){
_start:
{
switch(lean_obj_tag(v_x_843_))
{
case 0:
{
lean_object* v_k_844_; lean_object* v_v_845_; uint64_t v___x_846_; uint64_t v___x_847_; uint64_t v___x_848_; uint64_t v___x_849_; uint64_t v___x_850_; 
v_k_844_ = lean_ctor_get(v_x_843_, 0);
v_v_845_ = lean_ctor_get(v_x_843_, 1);
v___x_846_ = 0ULL;
v___x_847_ = lean_uint64_of_nat(v_k_844_);
v___x_848_ = lean_uint64_mix_hash(v___x_846_, v___x_847_);
v___x_849_ = lean_uint64_of_nat(v_v_845_);
v___x_850_ = lean_uint64_mix_hash(v___x_848_, v___x_849_);
return v___x_850_;
}
case 1:
{
lean_object* v_t_851_; uint64_t v___x_852_; uint64_t v___x_853_; uint64_t v___x_854_; 
v_t_851_ = lean_ctor_get(v_x_843_, 0);
v___x_852_ = 1ULL;
v___x_853_ = lean_uint64_of_nat(v_t_851_);
v___x_854_ = lean_uint64_mix_hash(v___x_852_, v___x_853_);
return v___x_854_;
}
case 2:
{
lean_object* v_k_855_; uint64_t v___x_856_; uint64_t v___x_857_; uint64_t v___x_858_; 
v_k_855_ = lean_ctor_get(v_x_843_, 0);
v___x_856_ = 2ULL;
v___x_857_ = lean_uint64_of_nat(v_k_855_);
v___x_858_ = lean_uint64_mix_hash(v___x_856_, v___x_857_);
return v___x_858_;
}
case 3:
{
lean_object* v_k_859_; lean_object* v_v_860_; uint64_t v___x_861_; uint64_t v___x_862_; uint64_t v___x_863_; uint64_t v___x_864_; uint64_t v___x_865_; 
v_k_859_ = lean_ctor_get(v_x_843_, 0);
v_v_860_ = lean_ctor_get(v_x_843_, 1);
v___x_861_ = 3ULL;
v___x_862_ = lean_uint64_of_nat(v_k_859_);
v___x_863_ = lean_uint64_mix_hash(v___x_861_, v___x_862_);
v___x_864_ = lean_uint64_of_nat(v_v_860_);
v___x_865_ = lean_uint64_mix_hash(v___x_863_, v___x_864_);
return v___x_865_;
}
case 4:
{
uint64_t v___x_866_; 
v___x_866_ = 4ULL;
return v___x_866_;
}
default: 
{
uint64_t v___x_867_; 
v___x_867_ = 5ULL;
return v___x_867_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instHashableStep_hash___boxed(lean_object* v_x_868_){
_start:
{
uint64_t v_res_869_; lean_object* v_r_870_; 
v_res_869_ = lp_bounded_Bounded_instHashableStep_hash(v_x_868_);
lean_dec(v_x_868_);
v_r_870_ = lean_box_uint64(v_res_869_);
return v_r_870_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumStep___lam__0(lean_object* v_p_873_){
_start:
{
lean_object* v_fst_874_; lean_object* v_snd_875_; lean_object* v___x_877_; uint8_t v_isShared_878_; uint8_t v_isSharedCheck_882_; 
v_fst_874_ = lean_ctor_get(v_p_873_, 0);
v_snd_875_ = lean_ctor_get(v_p_873_, 1);
v_isSharedCheck_882_ = !lean_is_exclusive(v_p_873_);
if (v_isSharedCheck_882_ == 0)
{
v___x_877_ = v_p_873_;
v_isShared_878_ = v_isSharedCheck_882_;
goto v_resetjp_876_;
}
else
{
lean_inc(v_snd_875_);
lean_inc(v_fst_874_);
lean_dec(v_p_873_);
v___x_877_ = lean_box(0);
v_isShared_878_ = v_isSharedCheck_882_;
goto v_resetjp_876_;
}
v_resetjp_876_:
{
lean_object* v___x_880_; 
if (v_isShared_878_ == 0)
{
v___x_880_ = v___x_877_;
goto v_reusejp_879_;
}
else
{
lean_object* v_reuseFailAlloc_881_; 
v_reuseFailAlloc_881_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_881_, 0, v_fst_874_);
lean_ctor_set(v_reuseFailAlloc_881_, 1, v_snd_875_);
v___x_880_ = v_reuseFailAlloc_881_;
goto v_reusejp_879_;
}
v_reusejp_879_:
{
return v___x_880_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumStep___lam__1(lean_object* v_t_883_){
_start:
{
lean_object* v___x_884_; 
v___x_884_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_884_, 0, v_t_883_);
return v___x_884_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumStep___lam__2(lean_object* v_k_885_){
_start:
{
lean_object* v___x_886_; 
v___x_886_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_886_, 0, v_k_885_);
return v___x_886_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumStep___lam__3(lean_object* v_p_887_){
_start:
{
lean_object* v_fst_888_; lean_object* v_snd_889_; lean_object* v___x_891_; uint8_t v_isShared_892_; uint8_t v_isSharedCheck_896_; 
v_fst_888_ = lean_ctor_get(v_p_887_, 0);
v_snd_889_ = lean_ctor_get(v_p_887_, 1);
v_isSharedCheck_896_ = !lean_is_exclusive(v_p_887_);
if (v_isSharedCheck_896_ == 0)
{
v___x_891_ = v_p_887_;
v_isShared_892_ = v_isSharedCheck_896_;
goto v_resetjp_890_;
}
else
{
lean_inc(v_snd_889_);
lean_inc(v_fst_888_);
lean_dec(v_p_887_);
v___x_891_ = lean_box(0);
v_isShared_892_ = v_isSharedCheck_896_;
goto v_resetjp_890_;
}
v_resetjp_890_:
{
lean_object* v___x_894_; 
if (v_isShared_892_ == 0)
{
lean_ctor_set_tag(v___x_891_, 3);
v___x_894_ = v___x_891_;
goto v_reusejp_893_;
}
else
{
lean_object* v_reuseFailAlloc_895_; 
v_reuseFailAlloc_895_ = lean_alloc_ctor(3, 2, 0);
lean_ctor_set(v_reuseFailAlloc_895_, 0, v_fst_888_);
lean_ctor_set(v_reuseFailAlloc_895_, 1, v_snd_889_);
v___x_894_ = v_reuseFailAlloc_895_;
goto v_reusejp_893_;
}
v_reusejp_893_:
{
return v___x_894_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumStep___lam__4(lean_object* v_a_897_, lean_object* v_b_898_){
_start:
{
lean_object* v___x_899_; 
v___x_899_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_899_, 0, v_a_897_);
lean_ctor_set(v___x_899_, 1, v_b_898_);
return v___x_899_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumStep___lam__5(lean_object* v___x_900_, lean_object* v_a_901_){
_start:
{
lean_object* v___f_902_; lean_object* v___x_903_; lean_object* v___x_904_; lean_object* v___x_905_; 
v___f_902_ = lean_alloc_closure((void*)(lp_bounded_Bounded_instFinEnumStep___lam__4), 2, 1);
lean_closure_set(v___f_902_, 0, v_a_901_);
v___x_903_ = lp_bounded_Bounded_finList(v___x_900_);
v___x_904_ = lean_box(0);
v___x_905_ = l_List_mapTR_loop___redArg(v___f_902_, v___x_903_, v___x_904_);
return v___x_905_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumStep___lam__5___boxed(lean_object* v___x_906_, lean_object* v_a_907_){
_start:
{
lean_object* v_res_908_; 
v_res_908_ = lp_bounded_Bounded_instFinEnumStep___lam__5(v___x_906_, v_a_907_);
lean_dec(v___x_906_);
return v_res_908_;
}
}
static lean_object* _init_lp_bounded_Bounded_instFinEnumStep___closed__5(void){
_start:
{
lean_object* v___x_915_; lean_object* v___x_916_; 
v___x_915_ = lean_unsigned_to_nat(2u);
v___x_916_ = lp_bounded_Bounded_finList(v___x_915_);
return v___x_916_;
}
}
static lean_object* _init_lp_bounded_Bounded_instFinEnumStep___closed__7(void){
_start:
{
lean_object* v___x_919_; lean_object* v___x_920_; lean_object* v___f_921_; lean_object* v___x_922_; 
v___x_919_ = ((lean_object*)(lp_bounded_Bounded_instFinEnumStep___closed__6));
v___x_920_ = lean_obj_once(&lp_bounded_Bounded_instFinEnumStep___closed__5, &lp_bounded_Bounded_instFinEnumStep___closed__5_once, _init_lp_bounded_Bounded_instFinEnumStep___closed__5);
v___f_921_ = ((lean_object*)(lp_bounded_Bounded_instFinEnumStep___closed__4));
v___x_922_ = l___private_Init_Data_List_Impl_0__List_flatMapTR_go___redArg(v___f_921_, v___x_920_, v___x_919_);
return v___x_922_;
}
}
static lean_object* _init_lp_bounded_Bounded_instFinEnumStep___closed__8(void){
_start:
{
lean_object* v___x_923_; lean_object* v___x_924_; lean_object* v___f_925_; lean_object* v___x_926_; 
v___x_923_ = lean_box(0);
v___x_924_ = lean_obj_once(&lp_bounded_Bounded_instFinEnumStep___closed__7, &lp_bounded_Bounded_instFinEnumStep___closed__7_once, _init_lp_bounded_Bounded_instFinEnumStep___closed__7);
v___f_925_ = ((lean_object*)(lp_bounded_Bounded_instFinEnumStep___closed__0));
v___x_926_ = l_List_mapTR_loop___redArg(v___f_925_, v___x_924_, v___x_923_);
return v___x_926_;
}
}
static lean_object* _init_lp_bounded_Bounded_instFinEnumStep___closed__9(void){
_start:
{
lean_object* v___x_927_; lean_object* v___x_928_; lean_object* v___f_929_; lean_object* v___x_930_; 
v___x_927_ = lean_box(0);
v___x_928_ = lean_obj_once(&lp_bounded_Bounded_instFinEnumStep___closed__5, &lp_bounded_Bounded_instFinEnumStep___closed__5_once, _init_lp_bounded_Bounded_instFinEnumStep___closed__5);
v___f_929_ = ((lean_object*)(lp_bounded_Bounded_instFinEnumStep___closed__1));
v___x_930_ = l_List_mapTR_loop___redArg(v___f_929_, v___x_928_, v___x_927_);
return v___x_930_;
}
}
static lean_object* _init_lp_bounded_Bounded_instFinEnumStep___closed__10(void){
_start:
{
lean_object* v___x_931_; lean_object* v___x_932_; lean_object* v___x_933_; 
v___x_931_ = lean_obj_once(&lp_bounded_Bounded_instFinEnumStep___closed__9, &lp_bounded_Bounded_instFinEnumStep___closed__9_once, _init_lp_bounded_Bounded_instFinEnumStep___closed__9);
v___x_932_ = lean_obj_once(&lp_bounded_Bounded_instFinEnumStep___closed__8, &lp_bounded_Bounded_instFinEnumStep___closed__8_once, _init_lp_bounded_Bounded_instFinEnumStep___closed__8);
v___x_933_ = l_List_appendTR___redArg(v___x_932_, v___x_931_);
return v___x_933_;
}
}
static lean_object* _init_lp_bounded_Bounded_instFinEnumStep___closed__11(void){
_start:
{
lean_object* v___x_934_; lean_object* v___x_935_; lean_object* v___f_936_; lean_object* v___x_937_; 
v___x_934_ = lean_box(0);
v___x_935_ = lean_obj_once(&lp_bounded_Bounded_instFinEnumStep___closed__5, &lp_bounded_Bounded_instFinEnumStep___closed__5_once, _init_lp_bounded_Bounded_instFinEnumStep___closed__5);
v___f_936_ = ((lean_object*)(lp_bounded_Bounded_instFinEnumStep___closed__2));
v___x_937_ = l_List_mapTR_loop___redArg(v___f_936_, v___x_935_, v___x_934_);
return v___x_937_;
}
}
static lean_object* _init_lp_bounded_Bounded_instFinEnumStep___closed__12(void){
_start:
{
lean_object* v___x_938_; lean_object* v___x_939_; lean_object* v___x_940_; 
v___x_938_ = lean_obj_once(&lp_bounded_Bounded_instFinEnumStep___closed__11, &lp_bounded_Bounded_instFinEnumStep___closed__11_once, _init_lp_bounded_Bounded_instFinEnumStep___closed__11);
v___x_939_ = lean_obj_once(&lp_bounded_Bounded_instFinEnumStep___closed__10, &lp_bounded_Bounded_instFinEnumStep___closed__10_once, _init_lp_bounded_Bounded_instFinEnumStep___closed__10);
v___x_940_ = l_List_appendTR___redArg(v___x_939_, v___x_938_);
return v___x_940_;
}
}
static lean_object* _init_lp_bounded_Bounded_instFinEnumStep___closed__13(void){
_start:
{
lean_object* v___x_941_; lean_object* v___x_942_; lean_object* v___f_943_; lean_object* v___x_944_; 
v___x_941_ = lean_box(0);
v___x_942_ = lean_obj_once(&lp_bounded_Bounded_instFinEnumStep___closed__7, &lp_bounded_Bounded_instFinEnumStep___closed__7_once, _init_lp_bounded_Bounded_instFinEnumStep___closed__7);
v___f_943_ = ((lean_object*)(lp_bounded_Bounded_instFinEnumStep___closed__3));
v___x_944_ = l_List_mapTR_loop___redArg(v___f_943_, v___x_942_, v___x_941_);
return v___x_944_;
}
}
static lean_object* _init_lp_bounded_Bounded_instFinEnumStep___closed__14(void){
_start:
{
lean_object* v___x_945_; lean_object* v___x_946_; lean_object* v___x_947_; 
v___x_945_ = lean_obj_once(&lp_bounded_Bounded_instFinEnumStep___closed__13, &lp_bounded_Bounded_instFinEnumStep___closed__13_once, _init_lp_bounded_Bounded_instFinEnumStep___closed__13);
v___x_946_ = lean_obj_once(&lp_bounded_Bounded_instFinEnumStep___closed__12, &lp_bounded_Bounded_instFinEnumStep___closed__12_once, _init_lp_bounded_Bounded_instFinEnumStep___closed__12);
v___x_947_ = l_List_appendTR___redArg(v___x_946_, v___x_945_);
return v___x_947_;
}
}
static lean_object* _init_lp_bounded_Bounded_instFinEnumStep___closed__17(void){
_start:
{
lean_object* v___x_954_; lean_object* v___x_955_; lean_object* v___x_956_; 
v___x_954_ = ((lean_object*)(lp_bounded_Bounded_instFinEnumStep___closed__16));
v___x_955_ = lean_obj_once(&lp_bounded_Bounded_instFinEnumStep___closed__14, &lp_bounded_Bounded_instFinEnumStep___closed__14_once, _init_lp_bounded_Bounded_instFinEnumStep___closed__14);
v___x_956_ = l_List_appendTR___redArg(v___x_955_, v___x_954_);
return v___x_956_;
}
}
static lean_object* _init_lp_bounded_Bounded_instFinEnumStep(void){
_start:
{
lean_object* v___x_957_; 
v___x_957_ = lean_obj_once(&lp_bounded_Bounded_instFinEnumStep___closed__17, &lp_bounded_Bounded_instFinEnumStep___closed__17_once, _init_lp_bounded_Bounded_instFinEnumStep___closed__17);
return v___x_957_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqComponent_decEq___lam__0(uint8_t v___y_958_, uint8_t v___y_959_){
_start:
{
if (v___y_958_ == 0)
{
if (v___y_959_ == 0)
{
uint8_t v___x_960_; 
v___x_960_ = 1;
return v___x_960_;
}
else
{
return v___y_958_;
}
}
else
{
return v___y_959_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqComponent_decEq___lam__0___boxed(lean_object* v___y_961_, lean_object* v___y_962_){
_start:
{
uint8_t v___y_72__boxed_963_; uint8_t v___y_73__boxed_964_; uint8_t v_res_965_; lean_object* v_r_966_; 
v___y_72__boxed_963_ = lean_unbox(v___y_961_);
v___y_73__boxed_964_ = lean_unbox(v___y_962_);
v_res_965_ = lp_bounded_Bounded_instDecidableEqComponent_decEq___lam__0(v___y_72__boxed_963_, v___y_73__boxed_964_);
v_r_966_ = lean_box(v_res_965_);
return v_r_966_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqComponent_decEq(lean_object* v_x_968_, lean_object* v_x_969_){
_start:
{
lean_object* v_deps_970_; lean_object* v_provs_971_; lean_object* v_script_972_; lean_object* v_deps_973_; lean_object* v_provs_974_; lean_object* v_script_975_; lean_object* v___f_976_; uint8_t v___x_977_; 
v_deps_970_ = lean_ctor_get(v_x_968_, 0);
lean_inc_ref(v_deps_970_);
v_provs_971_ = lean_ctor_get(v_x_968_, 1);
lean_inc_ref(v_provs_971_);
v_script_972_ = lean_ctor_get(v_x_968_, 2);
lean_inc(v_script_972_);
lean_dec_ref(v_x_968_);
v_deps_973_ = lean_ctor_get(v_x_969_, 0);
lean_inc_ref(v_deps_973_);
v_provs_974_ = lean_ctor_get(v_x_969_, 1);
lean_inc_ref(v_provs_974_);
v_script_975_ = lean_ctor_get(v_x_969_, 2);
lean_inc(v_script_975_);
lean_dec_ref(v_x_969_);
v___f_976_ = ((lean_object*)(lp_bounded_Bounded_instDecidableEqComponent_decEq___closed__0));
v___x_977_ = lp_bounded_Bounded_instDecidableEqKMap_decEq___redArg(v___f_976_, v_deps_970_, v_deps_973_);
if (v___x_977_ == 0)
{
lean_dec(v_script_975_);
lean_dec_ref(v_provs_974_);
lean_dec(v_script_972_);
lean_dec_ref(v_provs_971_);
return v___x_977_;
}
else
{
uint8_t v___x_978_; 
v___x_978_ = lp_bounded_Bounded_instDecidableEqKMap_decEq___redArg(v___f_976_, v_provs_971_, v_provs_974_);
if (v___x_978_ == 0)
{
lean_dec(v_script_975_);
lean_dec(v_script_972_);
return v___x_978_;
}
else
{
lean_object* v___x_979_; uint8_t v___x_980_; 
v___x_979_ = lean_alloc_closure((void*)(lp_bounded_Bounded_instDecidableEqStep___boxed), 2, 0);
v___x_980_ = l_instDecidableEqList___redArg(v___x_979_, v_script_972_, v_script_975_);
return v___x_980_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqComponent_decEq___boxed(lean_object* v_x_981_, lean_object* v_x_982_){
_start:
{
uint8_t v_res_983_; lean_object* v_r_984_; 
v_res_983_ = lp_bounded_Bounded_instDecidableEqComponent_decEq(v_x_981_, v_x_982_);
v_r_984_ = lean_box(v_res_983_);
return v_r_984_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqComponent(lean_object* v_x_985_, lean_object* v_x_986_){
_start:
{
uint8_t v___x_987_; 
v___x_987_ = lp_bounded_Bounded_instDecidableEqComponent_decEq(v_x_985_, v_x_986_);
return v___x_987_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqComponent___boxed(lean_object* v_x_988_, lean_object* v_x_989_){
_start:
{
uint8_t v_res_990_; lean_object* v_r_991_; 
v_res_990_ = lp_bounded_Bounded_instDecidableEqComponent(v_x_988_, v_x_989_);
v_r_991_ = lean_box(v_res_990_);
return v_r_991_;
}
}
LEAN_EXPORT uint64_t lp_bounded_Bounded_instHashableKMap_hash___at___00Bounded_instHashableComponent_hash_spec__0(lean_object* v_x_992_){
_start:
{
lean_object* v_k0_993_; lean_object* v_k1_994_; uint64_t v___x_995_; uint64_t v___y_997_; uint8_t v___x_1004_; 
v_k0_993_ = lean_ctor_get(v_x_992_, 0);
v_k1_994_ = lean_ctor_get(v_x_992_, 1);
v___x_995_ = 0ULL;
v___x_1004_ = lean_unbox(v_k0_993_);
if (v___x_1004_ == 0)
{
uint64_t v___x_1005_; 
v___x_1005_ = 13ULL;
v___y_997_ = v___x_1005_;
goto v___jp_996_;
}
else
{
uint64_t v___x_1006_; 
v___x_1006_ = 11ULL;
v___y_997_ = v___x_1006_;
goto v___jp_996_;
}
v___jp_996_:
{
uint64_t v___x_998_; uint8_t v___x_999_; 
v___x_998_ = lean_uint64_mix_hash(v___x_995_, v___y_997_);
v___x_999_ = lean_unbox(v_k1_994_);
if (v___x_999_ == 0)
{
uint64_t v___x_1000_; uint64_t v___x_1001_; 
v___x_1000_ = 13ULL;
v___x_1001_ = lean_uint64_mix_hash(v___x_998_, v___x_1000_);
return v___x_1001_;
}
else
{
uint64_t v___x_1002_; uint64_t v___x_1003_; 
v___x_1002_ = 11ULL;
v___x_1003_ = lean_uint64_mix_hash(v___x_998_, v___x_1002_);
return v___x_1003_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instHashableKMap_hash___at___00Bounded_instHashableComponent_hash_spec__0___boxed(lean_object* v_x_1007_){
_start:
{
uint64_t v_res_1008_; lean_object* v_r_1009_; 
v_res_1008_ = lp_bounded_Bounded_instHashableKMap_hash___at___00Bounded_instHashableComponent_hash_spec__0(v_x_1007_);
lean_dec_ref(v_x_1007_);
v_r_1009_ = lean_box_uint64(v_res_1008_);
return v_r_1009_;
}
}
LEAN_EXPORT uint64_t lp_bounded_List_foldl___at___00Bounded_instHashableComponent_hash_spec__1(uint64_t v_x_1010_, lean_object* v_x_1011_){
_start:
{
if (lean_obj_tag(v_x_1011_) == 0)
{
return v_x_1010_;
}
else
{
lean_object* v_head_1012_; lean_object* v_tail_1013_; uint64_t v___x_1014_; uint64_t v___x_1015_; 
v_head_1012_ = lean_ctor_get(v_x_1011_, 0);
v_tail_1013_ = lean_ctor_get(v_x_1011_, 1);
v___x_1014_ = lp_bounded_Bounded_instHashableStep_hash(v_head_1012_);
v___x_1015_ = lean_uint64_mix_hash(v_x_1010_, v___x_1014_);
v_x_1010_ = v___x_1015_;
v_x_1011_ = v_tail_1013_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_List_foldl___at___00Bounded_instHashableComponent_hash_spec__1___boxed(lean_object* v_x_1017_, lean_object* v_x_1018_){
_start:
{
uint64_t v_x_148__boxed_1019_; uint64_t v_res_1020_; lean_object* v_r_1021_; 
v_x_148__boxed_1019_ = lean_unbox_uint64(v_x_1017_);
lean_dec_ref(v_x_1017_);
v_res_1020_ = lp_bounded_List_foldl___at___00Bounded_instHashableComponent_hash_spec__1(v_x_148__boxed_1019_, v_x_1018_);
lean_dec(v_x_1018_);
v_r_1021_ = lean_box_uint64(v_res_1020_);
return v_r_1021_;
}
}
LEAN_EXPORT uint64_t lp_bounded_Bounded_instHashableComponent_hash(lean_object* v_x_1022_){
_start:
{
lean_object* v_deps_1023_; lean_object* v_provs_1024_; lean_object* v_script_1025_; uint64_t v___x_1026_; uint64_t v___x_1027_; uint64_t v___x_1028_; uint64_t v___x_1029_; uint64_t v___x_1030_; uint64_t v___x_1031_; uint64_t v___x_1032_; uint64_t v___x_1033_; 
v_deps_1023_ = lean_ctor_get(v_x_1022_, 0);
v_provs_1024_ = lean_ctor_get(v_x_1022_, 1);
v_script_1025_ = lean_ctor_get(v_x_1022_, 2);
v___x_1026_ = 0ULL;
v___x_1027_ = lp_bounded_Bounded_instHashableKMap_hash___at___00Bounded_instHashableComponent_hash_spec__0(v_deps_1023_);
v___x_1028_ = lean_uint64_mix_hash(v___x_1026_, v___x_1027_);
v___x_1029_ = lp_bounded_Bounded_instHashableKMap_hash___at___00Bounded_instHashableComponent_hash_spec__0(v_provs_1024_);
v___x_1030_ = lean_uint64_mix_hash(v___x_1028_, v___x_1029_);
v___x_1031_ = 7ULL;
v___x_1032_ = lp_bounded_List_foldl___at___00Bounded_instHashableComponent_hash_spec__1(v___x_1031_, v_script_1025_);
v___x_1033_ = lean_uint64_mix_hash(v___x_1030_, v___x_1032_);
return v___x_1033_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instHashableComponent_hash___boxed(lean_object* v_x_1034_){
_start:
{
uint64_t v_res_1035_; lean_object* v_r_1036_; 
v_res_1035_ = lp_bounded_Bounded_instHashableComponent_hash(v_x_1034_);
lean_dec_ref(v_x_1034_);
v_r_1036_ = lean_box_uint64(v_res_1035_);
return v_r_1036_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Outcome_ctorIdx(uint8_t v_x_1039_){
_start:
{
if (v_x_1039_ == 0)
{
lean_object* v___x_1040_; 
v___x_1040_ = lean_unsigned_to_nat(0u);
return v___x_1040_;
}
else
{
lean_object* v___x_1041_; 
v___x_1041_ = lean_unsigned_to_nat(1u);
return v___x_1041_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Outcome_ctorIdx___boxed(lean_object* v_x_1042_){
_start:
{
uint8_t v_x_boxed_1043_; lean_object* v_res_1044_; 
v_x_boxed_1043_ = lean_unbox(v_x_1042_);
v_res_1044_ = lp_bounded_Bounded_Outcome_ctorIdx(v_x_boxed_1043_);
return v_res_1044_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Outcome_toCtorIdx(uint8_t v_x_1045_){
_start:
{
lean_object* v___x_1046_; 
v___x_1046_ = lp_bounded_Bounded_Outcome_ctorIdx(v_x_1045_);
return v___x_1046_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Outcome_toCtorIdx___boxed(lean_object* v_x_1047_){
_start:
{
uint8_t v_x_4__boxed_1048_; lean_object* v_res_1049_; 
v_x_4__boxed_1048_ = lean_unbox(v_x_1047_);
v_res_1049_ = lp_bounded_Bounded_Outcome_toCtorIdx(v_x_4__boxed_1048_);
return v_res_1049_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Outcome_ctorElim___redArg(lean_object* v_k_1050_){
_start:
{
lean_inc(v_k_1050_);
return v_k_1050_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Outcome_ctorElim___redArg___boxed(lean_object* v_k_1051_){
_start:
{
lean_object* v_res_1052_; 
v_res_1052_ = lp_bounded_Bounded_Outcome_ctorElim___redArg(v_k_1051_);
lean_dec(v_k_1051_);
return v_res_1052_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Outcome_ctorElim(lean_object* v_motive_1053_, lean_object* v_ctorIdx_1054_, uint8_t v_t_1055_, lean_object* v_h_1056_, lean_object* v_k_1057_){
_start:
{
lean_inc(v_k_1057_);
return v_k_1057_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Outcome_ctorElim___boxed(lean_object* v_motive_1058_, lean_object* v_ctorIdx_1059_, lean_object* v_t_1060_, lean_object* v_h_1061_, lean_object* v_k_1062_){
_start:
{
uint8_t v_t_boxed_1063_; lean_object* v_res_1064_; 
v_t_boxed_1063_ = lean_unbox(v_t_1060_);
v_res_1064_ = lp_bounded_Bounded_Outcome_ctorElim(v_motive_1058_, v_ctorIdx_1059_, v_t_boxed_1063_, v_h_1061_, v_k_1062_);
lean_dec(v_k_1062_);
lean_dec(v_ctorIdx_1059_);
return v_res_1064_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Outcome_ok_elim___redArg(lean_object* v_ok_1065_){
_start:
{
lean_inc(v_ok_1065_);
return v_ok_1065_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Outcome_ok_elim___redArg___boxed(lean_object* v_ok_1066_){
_start:
{
lean_object* v_res_1067_; 
v_res_1067_ = lp_bounded_Bounded_Outcome_ok_elim___redArg(v_ok_1066_);
lean_dec(v_ok_1066_);
return v_res_1067_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Outcome_ok_elim(lean_object* v_motive_1068_, uint8_t v_t_1069_, lean_object* v_h_1070_, lean_object* v_ok_1071_){
_start:
{
lean_inc(v_ok_1071_);
return v_ok_1071_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Outcome_ok_elim___boxed(lean_object* v_motive_1072_, lean_object* v_t_1073_, lean_object* v_h_1074_, lean_object* v_ok_1075_){
_start:
{
uint8_t v_t_boxed_1076_; lean_object* v_res_1077_; 
v_t_boxed_1076_ = lean_unbox(v_t_1073_);
v_res_1077_ = lp_bounded_Bounded_Outcome_ok_elim(v_motive_1072_, v_t_boxed_1076_, v_h_1074_, v_ok_1075_);
lean_dec(v_ok_1075_);
return v_res_1077_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Outcome_err_elim___redArg(lean_object* v_err_1078_){
_start:
{
lean_inc(v_err_1078_);
return v_err_1078_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Outcome_err_elim___redArg___boxed(lean_object* v_err_1079_){
_start:
{
lean_object* v_res_1080_; 
v_res_1080_ = lp_bounded_Bounded_Outcome_err_elim___redArg(v_err_1079_);
lean_dec(v_err_1079_);
return v_res_1080_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Outcome_err_elim(lean_object* v_motive_1081_, uint8_t v_t_1082_, lean_object* v_h_1083_, lean_object* v_err_1084_){
_start:
{
lean_inc(v_err_1084_);
return v_err_1084_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Outcome_err_elim___boxed(lean_object* v_motive_1085_, lean_object* v_t_1086_, lean_object* v_h_1087_, lean_object* v_err_1088_){
_start:
{
uint8_t v_t_boxed_1089_; lean_object* v_res_1090_; 
v_t_boxed_1089_ = lean_unbox(v_t_1086_);
v_res_1090_ = lp_bounded_Bounded_Outcome_err_elim(v_motive_1085_, v_t_boxed_1089_, v_h_1087_, v_err_1088_);
lean_dec(v_err_1088_);
return v_res_1090_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_Outcome_ofNat(lean_object* v_n_1091_){
_start:
{
lean_object* v___x_1092_; uint8_t v___x_1093_; 
v___x_1092_ = lean_unsigned_to_nat(0u);
v___x_1093_ = lean_nat_dec_le(v_n_1091_, v___x_1092_);
if (v___x_1093_ == 0)
{
uint8_t v___x_1094_; 
v___x_1094_ = 1;
return v___x_1094_;
}
else
{
uint8_t v___x_1095_; 
v___x_1095_ = 0;
return v___x_1095_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Outcome_ofNat___boxed(lean_object* v_n_1096_){
_start:
{
uint8_t v_res_1097_; lean_object* v_r_1098_; 
v_res_1097_ = lp_bounded_Bounded_Outcome_ofNat(v_n_1096_);
lean_dec(v_n_1096_);
v_r_1098_ = lean_box(v_res_1097_);
return v_r_1098_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqOutcome(uint8_t v_x_1099_, uint8_t v_y_1100_){
_start:
{
lean_object* v___x_1101_; lean_object* v___x_1102_; uint8_t v___x_1103_; 
v___x_1101_ = lp_bounded_Bounded_Outcome_ctorIdx(v_x_1099_);
v___x_1102_ = lp_bounded_Bounded_Outcome_ctorIdx(v_y_1100_);
v___x_1103_ = lean_nat_dec_eq(v___x_1101_, v___x_1102_);
lean_dec(v___x_1102_);
lean_dec(v___x_1101_);
return v___x_1103_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqOutcome___boxed(lean_object* v_x_1104_, lean_object* v_y_1105_){
_start:
{
uint8_t v_x_13__boxed_1106_; uint8_t v_y_14__boxed_1107_; uint8_t v_res_1108_; lean_object* v_r_1109_; 
v_x_13__boxed_1106_ = lean_unbox(v_x_1104_);
v_y_14__boxed_1107_ = lean_unbox(v_y_1105_);
v_res_1108_ = lp_bounded_Bounded_instDecidableEqOutcome(v_x_13__boxed_1106_, v_y_14__boxed_1107_);
v_r_1109_ = lean_box(v_res_1108_);
return v_r_1109_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprOutcome_repr(uint8_t v_x_1116_, lean_object* v_prec_1117_){
_start:
{
lean_object* v___y_1119_; lean_object* v___y_1126_; 
if (v_x_1116_ == 0)
{
lean_object* v___x_1132_; uint8_t v___x_1133_; 
v___x_1132_ = lean_unsigned_to_nat(1024u);
v___x_1133_ = lean_nat_dec_le(v___x_1132_, v_prec_1117_);
if (v___x_1133_ == 0)
{
lean_object* v___x_1134_; 
v___x_1134_ = lean_obj_once(&lp_bounded_Bounded_instReprStep_repr___closed__7, &lp_bounded_Bounded_instReprStep_repr___closed__7_once, _init_lp_bounded_Bounded_instReprStep_repr___closed__7);
v___y_1119_ = v___x_1134_;
goto v___jp_1118_;
}
else
{
lean_object* v___x_1135_; 
v___x_1135_ = lean_obj_once(&lp_bounded_Bounded_instReprStep_repr___closed__8, &lp_bounded_Bounded_instReprStep_repr___closed__8_once, _init_lp_bounded_Bounded_instReprStep_repr___closed__8);
v___y_1119_ = v___x_1135_;
goto v___jp_1118_;
}
}
else
{
lean_object* v___x_1136_; uint8_t v___x_1137_; 
v___x_1136_ = lean_unsigned_to_nat(1024u);
v___x_1137_ = lean_nat_dec_le(v___x_1136_, v_prec_1117_);
if (v___x_1137_ == 0)
{
lean_object* v___x_1138_; 
v___x_1138_ = lean_obj_once(&lp_bounded_Bounded_instReprStep_repr___closed__7, &lp_bounded_Bounded_instReprStep_repr___closed__7_once, _init_lp_bounded_Bounded_instReprStep_repr___closed__7);
v___y_1126_ = v___x_1138_;
goto v___jp_1125_;
}
else
{
lean_object* v___x_1139_; 
v___x_1139_ = lean_obj_once(&lp_bounded_Bounded_instReprStep_repr___closed__8, &lp_bounded_Bounded_instReprStep_repr___closed__8_once, _init_lp_bounded_Bounded_instReprStep_repr___closed__8);
v___y_1126_ = v___x_1139_;
goto v___jp_1125_;
}
}
v___jp_1118_:
{
lean_object* v___x_1120_; lean_object* v___x_1121_; uint8_t v___x_1122_; lean_object* v___x_1123_; lean_object* v___x_1124_; 
v___x_1120_ = ((lean_object*)(lp_bounded_Bounded_instReprOutcome_repr___closed__1));
lean_inc(v___y_1119_);
v___x_1121_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_1121_, 0, v___y_1119_);
lean_ctor_set(v___x_1121_, 1, v___x_1120_);
v___x_1122_ = 0;
v___x_1123_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_1123_, 0, v___x_1121_);
lean_ctor_set_uint8(v___x_1123_, sizeof(void*)*1, v___x_1122_);
v___x_1124_ = l_Repr_addAppParen(v___x_1123_, v_prec_1117_);
return v___x_1124_;
}
v___jp_1125_:
{
lean_object* v___x_1127_; lean_object* v___x_1128_; uint8_t v___x_1129_; lean_object* v___x_1130_; lean_object* v___x_1131_; 
v___x_1127_ = ((lean_object*)(lp_bounded_Bounded_instReprOutcome_repr___closed__3));
lean_inc(v___y_1126_);
v___x_1128_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_1128_, 0, v___y_1126_);
lean_ctor_set(v___x_1128_, 1, v___x_1127_);
v___x_1129_ = 0;
v___x_1130_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_1130_, 0, v___x_1128_);
lean_ctor_set_uint8(v___x_1130_, sizeof(void*)*1, v___x_1129_);
v___x_1131_ = l_Repr_addAppParen(v___x_1130_, v_prec_1117_);
return v___x_1131_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprOutcome_repr___boxed(lean_object* v_x_1140_, lean_object* v_prec_1141_){
_start:
{
uint8_t v_x_117__boxed_1142_; lean_object* v_res_1143_; 
v_x_117__boxed_1142_ = lean_unbox(v_x_1140_);
v_res_1143_ = lp_bounded_Bounded_instReprOutcome_repr(v_x_117__boxed_1142_, v_prec_1141_);
lean_dec(v_prec_1141_);
return v_res_1143_;
}
}
LEAN_EXPORT uint64_t lp_bounded_Bounded_instHashableOutcome_hash(uint8_t v_x_1146_){
_start:
{
if (v_x_1146_ == 0)
{
uint64_t v___x_1147_; 
v___x_1147_ = 0ULL;
return v___x_1147_;
}
else
{
uint64_t v___x_1148_; 
v___x_1148_ = 1ULL;
return v___x_1148_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instHashableOutcome_hash___boxed(lean_object* v_x_1149_){
_start:
{
uint8_t v_x_28__boxed_1150_; uint64_t v_res_1151_; lean_object* v_r_1152_; 
v_x_28__boxed_1150_ = lean_unbox(v_x_1149_);
v_res_1151_ = lp_bounded_Bounded_instHashableOutcome_hash(v_x_28__boxed_1150_);
v_r_1152_ = lean_box_uint64(v_res_1151_);
return v_r_1152_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Inv_ctorIdx(lean_object* v_x_1155_){
_start:
{
switch(lean_obj_tag(v_x_1155_))
{
case 0:
{
lean_object* v___x_1156_; 
v___x_1156_ = lean_unsigned_to_nat(0u);
return v___x_1156_;
}
case 1:
{
lean_object* v___x_1157_; 
v___x_1157_ = lean_unsigned_to_nat(1u);
return v___x_1157_;
}
default: 
{
lean_object* v___x_1158_; 
v___x_1158_ = lean_unsigned_to_nat(2u);
return v___x_1158_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Inv_ctorIdx___boxed(lean_object* v_x_1159_){
_start:
{
lean_object* v_res_1160_; 
v_res_1160_ = lp_bounded_Bounded_Inv_ctorIdx(v_x_1159_);
lean_dec_ref(v_x_1159_);
return v_res_1160_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Inv_ctorElim___redArg(lean_object* v_t_1161_, lean_object* v_k_1162_){
_start:
{
lean_object* v_k_1163_; lean_object* v___x_1164_; 
v_k_1163_ = lean_ctor_get(v_t_1161_, 0);
lean_inc(v_k_1163_);
lean_dec_ref(v_t_1161_);
v___x_1164_ = lean_apply_1(v_k_1162_, v_k_1163_);
return v___x_1164_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Inv_ctorElim(lean_object* v_motive_1165_, lean_object* v_ctorIdx_1166_, lean_object* v_t_1167_, lean_object* v_h_1168_, lean_object* v_k_1169_){
_start:
{
lean_object* v___x_1170_; 
v___x_1170_ = lp_bounded_Bounded_Inv_ctorElim___redArg(v_t_1167_, v_k_1169_);
return v___x_1170_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Inv_ctorElim___boxed(lean_object* v_motive_1171_, lean_object* v_ctorIdx_1172_, lean_object* v_t_1173_, lean_object* v_h_1174_, lean_object* v_k_1175_){
_start:
{
lean_object* v_res_1176_; 
v_res_1176_ = lp_bounded_Bounded_Inv_ctorElim(v_motive_1171_, v_ctorIdx_1172_, v_t_1173_, v_h_1174_, v_k_1175_);
lean_dec(v_ctorIdx_1172_);
return v_res_1176_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Inv_unprovide_elim___redArg(lean_object* v_t_1177_, lean_object* v_unprovide_1178_){
_start:
{
lean_object* v___x_1179_; 
v___x_1179_ = lp_bounded_Bounded_Inv_ctorElim___redArg(v_t_1177_, v_unprovide_1178_);
return v___x_1179_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Inv_unprovide_elim(lean_object* v_motive_1180_, lean_object* v_t_1181_, lean_object* v_h_1182_, lean_object* v_unprovide_1183_){
_start:
{
lean_object* v___x_1184_; 
v___x_1184_ = lp_bounded_Bounded_Inv_ctorElim___redArg(v_t_1181_, v_unprovide_1183_);
return v___x_1184_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Inv_untrack_elim___redArg(lean_object* v_t_1185_, lean_object* v_untrack_1186_){
_start:
{
lean_object* v___x_1187_; 
v___x_1187_ = lp_bounded_Bounded_Inv_ctorElim___redArg(v_t_1185_, v_untrack_1186_);
return v___x_1187_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Inv_untrack_elim(lean_object* v_motive_1188_, lean_object* v_t_1189_, lean_object* v_h_1190_, lean_object* v_untrack_1191_){
_start:
{
lean_object* v___x_1192_; 
v___x_1192_ = lp_bounded_Bounded_Inv_ctorElim___redArg(v_t_1189_, v_untrack_1191_);
return v___x_1192_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Inv_retireChild_elim___redArg(lean_object* v_t_1193_, lean_object* v_retireChild_1194_){
_start:
{
lean_object* v___x_1195_; 
v___x_1195_ = lp_bounded_Bounded_Inv_ctorElim___redArg(v_t_1193_, v_retireChild_1194_);
return v___x_1195_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Inv_retireChild_elim(lean_object* v_motive_1196_, lean_object* v_t_1197_, lean_object* v_h_1198_, lean_object* v_retireChild_1199_){
_start:
{
lean_object* v___x_1200_; 
v___x_1200_ = lp_bounded_Bounded_Inv_ctorElim___redArg(v_t_1197_, v_retireChild_1199_);
return v___x_1200_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqInv_decEq(lean_object* v_x_1201_, lean_object* v_x_1202_){
_start:
{
switch(lean_obj_tag(v_x_1201_))
{
case 0:
{
if (lean_obj_tag(v_x_1202_) == 0)
{
lean_object* v_k_1203_; lean_object* v_k_1204_; uint8_t v___x_1205_; 
v_k_1203_ = lean_ctor_get(v_x_1201_, 0);
v_k_1204_ = lean_ctor_get(v_x_1202_, 0);
v___x_1205_ = lean_nat_dec_eq(v_k_1203_, v_k_1204_);
return v___x_1205_;
}
else
{
uint8_t v___x_1206_; 
v___x_1206_ = 0;
return v___x_1206_;
}
}
case 1:
{
if (lean_obj_tag(v_x_1202_) == 1)
{
lean_object* v_t_1207_; lean_object* v_t_1208_; uint8_t v___x_1209_; 
v_t_1207_ = lean_ctor_get(v_x_1201_, 0);
v_t_1208_ = lean_ctor_get(v_x_1202_, 0);
v___x_1209_ = lean_nat_dec_eq(v_t_1207_, v_t_1208_);
return v___x_1209_;
}
else
{
uint8_t v___x_1210_; 
v___x_1210_ = 0;
return v___x_1210_;
}
}
default: 
{
if (lean_obj_tag(v_x_1202_) == 2)
{
lean_object* v_s_1211_; lean_object* v_s_1212_; uint8_t v___x_1213_; 
v_s_1211_ = lean_ctor_get(v_x_1201_, 0);
v_s_1212_ = lean_ctor_get(v_x_1202_, 0);
v___x_1213_ = lean_nat_dec_eq(v_s_1211_, v_s_1212_);
return v___x_1213_;
}
else
{
uint8_t v___x_1214_; 
v___x_1214_ = 0;
return v___x_1214_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqInv_decEq___boxed(lean_object* v_x_1215_, lean_object* v_x_1216_){
_start:
{
uint8_t v_res_1217_; lean_object* v_r_1218_; 
v_res_1217_ = lp_bounded_Bounded_instDecidableEqInv_decEq(v_x_1215_, v_x_1216_);
lean_dec_ref(v_x_1216_);
lean_dec_ref(v_x_1215_);
v_r_1218_ = lean_box(v_res_1217_);
return v_r_1218_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqInv(lean_object* v_x_1219_, lean_object* v_x_1220_){
_start:
{
uint8_t v___x_1221_; 
v___x_1221_ = lp_bounded_Bounded_instDecidableEqInv_decEq(v_x_1219_, v_x_1220_);
return v___x_1221_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqInv___boxed(lean_object* v_x_1222_, lean_object* v_x_1223_){
_start:
{
uint8_t v_res_1224_; lean_object* v_r_1225_; 
v_res_1224_ = lp_bounded_Bounded_instDecidableEqInv(v_x_1222_, v_x_1223_);
lean_dec_ref(v_x_1223_);
lean_dec_ref(v_x_1222_);
v_r_1225_ = lean_box(v_res_1224_);
return v_r_1225_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprInv_repr(lean_object* v_x_1244_, lean_object* v_prec_1245_){
_start:
{
switch(lean_obj_tag(v_x_1244_))
{
case 0:
{
lean_object* v_k_1246_; lean_object* v___x_1248_; uint8_t v_isShared_1249_; uint8_t v_isSharedCheck_1266_; 
v_k_1246_ = lean_ctor_get(v_x_1244_, 0);
v_isSharedCheck_1266_ = !lean_is_exclusive(v_x_1244_);
if (v_isSharedCheck_1266_ == 0)
{
v___x_1248_ = v_x_1244_;
v_isShared_1249_ = v_isSharedCheck_1266_;
goto v_resetjp_1247_;
}
else
{
lean_inc(v_k_1246_);
lean_dec(v_x_1244_);
v___x_1248_ = lean_box(0);
v_isShared_1249_ = v_isSharedCheck_1266_;
goto v_resetjp_1247_;
}
v_resetjp_1247_:
{
lean_object* v___y_1251_; lean_object* v___x_1262_; uint8_t v___x_1263_; 
v___x_1262_ = lean_unsigned_to_nat(1024u);
v___x_1263_ = lean_nat_dec_le(v___x_1262_, v_prec_1245_);
if (v___x_1263_ == 0)
{
lean_object* v___x_1264_; 
v___x_1264_ = lean_obj_once(&lp_bounded_Bounded_instReprStep_repr___closed__7, &lp_bounded_Bounded_instReprStep_repr___closed__7_once, _init_lp_bounded_Bounded_instReprStep_repr___closed__7);
v___y_1251_ = v___x_1264_;
goto v___jp_1250_;
}
else
{
lean_object* v___x_1265_; 
v___x_1265_ = lean_obj_once(&lp_bounded_Bounded_instReprStep_repr___closed__8, &lp_bounded_Bounded_instReprStep_repr___closed__8_once, _init_lp_bounded_Bounded_instReprStep_repr___closed__8);
v___y_1251_ = v___x_1265_;
goto v___jp_1250_;
}
v___jp_1250_:
{
lean_object* v___x_1252_; lean_object* v___x_1253_; lean_object* v___x_1255_; 
v___x_1252_ = ((lean_object*)(lp_bounded_Bounded_instReprInv_repr___closed__2));
v___x_1253_ = l_Nat_reprFast(v_k_1246_);
if (v_isShared_1249_ == 0)
{
lean_ctor_set_tag(v___x_1248_, 3);
lean_ctor_set(v___x_1248_, 0, v___x_1253_);
v___x_1255_ = v___x_1248_;
goto v_reusejp_1254_;
}
else
{
lean_object* v_reuseFailAlloc_1261_; 
v_reuseFailAlloc_1261_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1261_, 0, v___x_1253_);
v___x_1255_ = v_reuseFailAlloc_1261_;
goto v_reusejp_1254_;
}
v_reusejp_1254_:
{
lean_object* v___x_1256_; lean_object* v___x_1257_; uint8_t v___x_1258_; lean_object* v___x_1259_; lean_object* v___x_1260_; 
v___x_1256_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_1256_, 0, v___x_1252_);
lean_ctor_set(v___x_1256_, 1, v___x_1255_);
lean_inc(v___y_1251_);
v___x_1257_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_1257_, 0, v___y_1251_);
lean_ctor_set(v___x_1257_, 1, v___x_1256_);
v___x_1258_ = 0;
v___x_1259_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_1259_, 0, v___x_1257_);
lean_ctor_set_uint8(v___x_1259_, sizeof(void*)*1, v___x_1258_);
v___x_1260_ = l_Repr_addAppParen(v___x_1259_, v_prec_1245_);
return v___x_1260_;
}
}
}
}
case 1:
{
lean_object* v_t_1267_; lean_object* v___x_1269_; uint8_t v_isShared_1270_; uint8_t v_isSharedCheck_1287_; 
v_t_1267_ = lean_ctor_get(v_x_1244_, 0);
v_isSharedCheck_1287_ = !lean_is_exclusive(v_x_1244_);
if (v_isSharedCheck_1287_ == 0)
{
v___x_1269_ = v_x_1244_;
v_isShared_1270_ = v_isSharedCheck_1287_;
goto v_resetjp_1268_;
}
else
{
lean_inc(v_t_1267_);
lean_dec(v_x_1244_);
v___x_1269_ = lean_box(0);
v_isShared_1270_ = v_isSharedCheck_1287_;
goto v_resetjp_1268_;
}
v_resetjp_1268_:
{
lean_object* v___y_1272_; lean_object* v___x_1283_; uint8_t v___x_1284_; 
v___x_1283_ = lean_unsigned_to_nat(1024u);
v___x_1284_ = lean_nat_dec_le(v___x_1283_, v_prec_1245_);
if (v___x_1284_ == 0)
{
lean_object* v___x_1285_; 
v___x_1285_ = lean_obj_once(&lp_bounded_Bounded_instReprStep_repr___closed__7, &lp_bounded_Bounded_instReprStep_repr___closed__7_once, _init_lp_bounded_Bounded_instReprStep_repr___closed__7);
v___y_1272_ = v___x_1285_;
goto v___jp_1271_;
}
else
{
lean_object* v___x_1286_; 
v___x_1286_ = lean_obj_once(&lp_bounded_Bounded_instReprStep_repr___closed__8, &lp_bounded_Bounded_instReprStep_repr___closed__8_once, _init_lp_bounded_Bounded_instReprStep_repr___closed__8);
v___y_1272_ = v___x_1286_;
goto v___jp_1271_;
}
v___jp_1271_:
{
lean_object* v___x_1273_; lean_object* v___x_1274_; lean_object* v___x_1276_; 
v___x_1273_ = ((lean_object*)(lp_bounded_Bounded_instReprInv_repr___closed__5));
v___x_1274_ = l_Nat_reprFast(v_t_1267_);
if (v_isShared_1270_ == 0)
{
lean_ctor_set_tag(v___x_1269_, 3);
lean_ctor_set(v___x_1269_, 0, v___x_1274_);
v___x_1276_ = v___x_1269_;
goto v_reusejp_1275_;
}
else
{
lean_object* v_reuseFailAlloc_1282_; 
v_reuseFailAlloc_1282_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1282_, 0, v___x_1274_);
v___x_1276_ = v_reuseFailAlloc_1282_;
goto v_reusejp_1275_;
}
v_reusejp_1275_:
{
lean_object* v___x_1277_; lean_object* v___x_1278_; uint8_t v___x_1279_; lean_object* v___x_1280_; lean_object* v___x_1281_; 
v___x_1277_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_1277_, 0, v___x_1273_);
lean_ctor_set(v___x_1277_, 1, v___x_1276_);
lean_inc(v___y_1272_);
v___x_1278_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_1278_, 0, v___y_1272_);
lean_ctor_set(v___x_1278_, 1, v___x_1277_);
v___x_1279_ = 0;
v___x_1280_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_1280_, 0, v___x_1278_);
lean_ctor_set_uint8(v___x_1280_, sizeof(void*)*1, v___x_1279_);
v___x_1281_ = l_Repr_addAppParen(v___x_1280_, v_prec_1245_);
return v___x_1281_;
}
}
}
}
default: 
{
lean_object* v_s_1288_; lean_object* v___x_1290_; uint8_t v_isShared_1291_; uint8_t v_isSharedCheck_1308_; 
v_s_1288_ = lean_ctor_get(v_x_1244_, 0);
v_isSharedCheck_1308_ = !lean_is_exclusive(v_x_1244_);
if (v_isSharedCheck_1308_ == 0)
{
v___x_1290_ = v_x_1244_;
v_isShared_1291_ = v_isSharedCheck_1308_;
goto v_resetjp_1289_;
}
else
{
lean_inc(v_s_1288_);
lean_dec(v_x_1244_);
v___x_1290_ = lean_box(0);
v_isShared_1291_ = v_isSharedCheck_1308_;
goto v_resetjp_1289_;
}
v_resetjp_1289_:
{
lean_object* v___y_1293_; lean_object* v___x_1304_; uint8_t v___x_1305_; 
v___x_1304_ = lean_unsigned_to_nat(1024u);
v___x_1305_ = lean_nat_dec_le(v___x_1304_, v_prec_1245_);
if (v___x_1305_ == 0)
{
lean_object* v___x_1306_; 
v___x_1306_ = lean_obj_once(&lp_bounded_Bounded_instReprStep_repr___closed__7, &lp_bounded_Bounded_instReprStep_repr___closed__7_once, _init_lp_bounded_Bounded_instReprStep_repr___closed__7);
v___y_1293_ = v___x_1306_;
goto v___jp_1292_;
}
else
{
lean_object* v___x_1307_; 
v___x_1307_ = lean_obj_once(&lp_bounded_Bounded_instReprStep_repr___closed__8, &lp_bounded_Bounded_instReprStep_repr___closed__8_once, _init_lp_bounded_Bounded_instReprStep_repr___closed__8);
v___y_1293_ = v___x_1307_;
goto v___jp_1292_;
}
v___jp_1292_:
{
lean_object* v___x_1294_; lean_object* v___x_1295_; lean_object* v___x_1297_; 
v___x_1294_ = ((lean_object*)(lp_bounded_Bounded_instReprInv_repr___closed__8));
v___x_1295_ = l_Nat_reprFast(v_s_1288_);
if (v_isShared_1291_ == 0)
{
lean_ctor_set_tag(v___x_1290_, 3);
lean_ctor_set(v___x_1290_, 0, v___x_1295_);
v___x_1297_ = v___x_1290_;
goto v_reusejp_1296_;
}
else
{
lean_object* v_reuseFailAlloc_1303_; 
v_reuseFailAlloc_1303_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1303_, 0, v___x_1295_);
v___x_1297_ = v_reuseFailAlloc_1303_;
goto v_reusejp_1296_;
}
v_reusejp_1296_:
{
lean_object* v___x_1298_; lean_object* v___x_1299_; uint8_t v___x_1300_; lean_object* v___x_1301_; lean_object* v___x_1302_; 
v___x_1298_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_1298_, 0, v___x_1294_);
lean_ctor_set(v___x_1298_, 1, v___x_1297_);
lean_inc(v___y_1293_);
v___x_1299_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_1299_, 0, v___y_1293_);
lean_ctor_set(v___x_1299_, 1, v___x_1298_);
v___x_1300_ = 0;
v___x_1301_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_1301_, 0, v___x_1299_);
lean_ctor_set_uint8(v___x_1301_, sizeof(void*)*1, v___x_1300_);
v___x_1302_ = l_Repr_addAppParen(v___x_1301_, v_prec_1245_);
return v___x_1302_;
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprInv_repr___boxed(lean_object* v_x_1309_, lean_object* v_prec_1310_){
_start:
{
lean_object* v_res_1311_; 
v_res_1311_ = lp_bounded_Bounded_instReprInv_repr(v_x_1309_, v_prec_1310_);
lean_dec(v_prec_1310_);
return v_res_1311_;
}
}
LEAN_EXPORT uint64_t lp_bounded_Bounded_instHashableInv_hash(lean_object* v_x_1314_){
_start:
{
switch(lean_obj_tag(v_x_1314_))
{
case 0:
{
lean_object* v_k_1315_; uint64_t v___x_1316_; uint64_t v___x_1317_; uint64_t v___x_1318_; 
v_k_1315_ = lean_ctor_get(v_x_1314_, 0);
v___x_1316_ = 0ULL;
v___x_1317_ = lean_uint64_of_nat(v_k_1315_);
v___x_1318_ = lean_uint64_mix_hash(v___x_1316_, v___x_1317_);
return v___x_1318_;
}
case 1:
{
lean_object* v_t_1319_; uint64_t v___x_1320_; uint64_t v___x_1321_; uint64_t v___x_1322_; 
v_t_1319_ = lean_ctor_get(v_x_1314_, 0);
v___x_1320_ = 1ULL;
v___x_1321_ = lean_uint64_of_nat(v_t_1319_);
v___x_1322_ = lean_uint64_mix_hash(v___x_1320_, v___x_1321_);
return v___x_1322_;
}
default: 
{
lean_object* v_s_1323_; uint64_t v___x_1324_; uint64_t v___x_1325_; uint64_t v___x_1326_; 
v_s_1323_ = lean_ctor_get(v_x_1314_, 0);
v___x_1324_ = 2ULL;
v___x_1325_ = lean_uint64_of_nat(v_s_1323_);
v___x_1326_ = lean_uint64_mix_hash(v___x_1324_, v___x_1325_);
return v___x_1326_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instHashableInv_hash___boxed(lean_object* v_x_1327_){
_start:
{
uint64_t v_res_1328_; lean_object* v_r_1329_; 
v_res_1328_ = lp_bounded_Bounded_instHashableInv_hash(v_x_1327_);
lean_dec_ref(v_x_1327_);
v_r_1329_ = lean_box_uint64(v_res_1328_);
return v_r_1329_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_LState_ctorIdx(lean_object* v_x_1332_){
_start:
{
switch(lean_obj_tag(v_x_1332_))
{
case 0:
{
lean_object* v___x_1333_; 
v___x_1333_ = lean_unsigned_to_nat(0u);
return v___x_1333_;
}
case 1:
{
lean_object* v___x_1334_; 
v___x_1334_ = lean_unsigned_to_nat(1u);
return v___x_1334_;
}
case 2:
{
lean_object* v___x_1335_; 
v___x_1335_ = lean_unsigned_to_nat(2u);
return v___x_1335_;
}
default: 
{
lean_object* v___x_1336_; 
v___x_1336_ = lean_unsigned_to_nat(3u);
return v___x_1336_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_LState_ctorIdx___boxed(lean_object* v_x_1337_){
_start:
{
lean_object* v_res_1338_; 
v_res_1338_ = lp_bounded_Bounded_LState_ctorIdx(v_x_1337_);
lean_dec_ref(v_x_1337_);
return v_res_1338_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_LState_ctorElim___redArg(lean_object* v_t_1339_, lean_object* v_k_1340_){
_start:
{
switch(lean_obj_tag(v_t_1339_))
{
case 0:
{
uint8_t v_o_1341_; lean_object* v___x_1342_; lean_object* v___x_1343_; 
v_o_1341_ = lean_ctor_get_uint8(v_t_1339_, 0);
lean_dec_ref_known(v_t_1339_, 0);
v___x_1342_ = lean_box(v_o_1341_);
v___x_1343_ = lean_apply_1(v_k_1340_, v___x_1342_);
return v___x_1343_;
}
case 1:
{
lean_object* v_remaining_1344_; lean_object* v_acc_1345_; lean_object* v_view_1346_; lean_object* v___x_1347_; 
v_remaining_1344_ = lean_ctor_get(v_t_1339_, 0);
lean_inc(v_remaining_1344_);
v_acc_1345_ = lean_ctor_get(v_t_1339_, 1);
lean_inc(v_acc_1345_);
v_view_1346_ = lean_ctor_get(v_t_1339_, 2);
lean_inc_ref(v_view_1346_);
lean_dec_ref_known(v_t_1339_, 3);
v___x_1347_ = lean_apply_3(v_k_1340_, v_remaining_1344_, v_acc_1345_, v_view_1346_);
return v___x_1347_;
}
case 2:
{
lean_object* v_acc_1348_; lean_object* v_view_1349_; lean_object* v___x_1350_; 
v_acc_1348_ = lean_ctor_get(v_t_1339_, 0);
lean_inc(v_acc_1348_);
v_view_1349_ = lean_ctor_get(v_t_1339_, 1);
lean_inc_ref(v_view_1349_);
lean_dec_ref_known(v_t_1339_, 2);
v___x_1350_ = lean_apply_2(v_k_1340_, v_acc_1348_, v_view_1349_);
return v___x_1350_;
}
default: 
{
lean_object* v_acc_1351_; lean_object* v_view_1352_; uint8_t v_o_1353_; lean_object* v___x_1354_; lean_object* v___x_1355_; 
v_acc_1351_ = lean_ctor_get(v_t_1339_, 0);
lean_inc(v_acc_1351_);
v_view_1352_ = lean_ctor_get(v_t_1339_, 1);
lean_inc_ref(v_view_1352_);
v_o_1353_ = lean_ctor_get_uint8(v_t_1339_, sizeof(void*)*2);
lean_dec_ref_known(v_t_1339_, 2);
v___x_1354_ = lean_box(v_o_1353_);
v___x_1355_ = lean_apply_3(v_k_1340_, v_acc_1351_, v_view_1352_, v___x_1354_);
return v___x_1355_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_LState_ctorElim(lean_object* v_motive_1356_, lean_object* v_ctorIdx_1357_, lean_object* v_t_1358_, lean_object* v_h_1359_, lean_object* v_k_1360_){
_start:
{
lean_object* v___x_1361_; 
v___x_1361_ = lp_bounded_Bounded_LState_ctorElim___redArg(v_t_1358_, v_k_1360_);
return v___x_1361_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_LState_ctorElim___boxed(lean_object* v_motive_1362_, lean_object* v_ctorIdx_1363_, lean_object* v_t_1364_, lean_object* v_h_1365_, lean_object* v_k_1366_){
_start:
{
lean_object* v_res_1367_; 
v_res_1367_ = lp_bounded_Bounded_LState_ctorElim(v_motive_1362_, v_ctorIdx_1363_, v_t_1364_, v_h_1365_, v_k_1366_);
lean_dec(v_ctorIdx_1363_);
return v_res_1367_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_LState_inactive_elim___redArg(lean_object* v_t_1368_, lean_object* v_inactive_1369_){
_start:
{
lean_object* v___x_1370_; 
v___x_1370_ = lp_bounded_Bounded_LState_ctorElim___redArg(v_t_1368_, v_inactive_1369_);
return v___x_1370_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_LState_inactive_elim(lean_object* v_motive_1371_, lean_object* v_t_1372_, lean_object* v_h_1373_, lean_object* v_inactive_1374_){
_start:
{
lean_object* v___x_1375_; 
v___x_1375_ = lp_bounded_Bounded_LState_ctorElim___redArg(v_t_1372_, v_inactive_1374_);
return v___x_1375_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_LState_reloading_elim___redArg(lean_object* v_t_1376_, lean_object* v_reloading_1377_){
_start:
{
lean_object* v___x_1378_; 
v___x_1378_ = lp_bounded_Bounded_LState_ctorElim___redArg(v_t_1376_, v_reloading_1377_);
return v___x_1378_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_LState_reloading_elim(lean_object* v_motive_1379_, lean_object* v_t_1380_, lean_object* v_h_1381_, lean_object* v_reloading_1382_){
_start:
{
lean_object* v___x_1383_; 
v___x_1383_ = lp_bounded_Bounded_LState_ctorElim___redArg(v_t_1380_, v_reloading_1382_);
return v___x_1383_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_LState_active_elim___redArg(lean_object* v_t_1384_, lean_object* v_active_1385_){
_start:
{
lean_object* v___x_1386_; 
v___x_1386_ = lp_bounded_Bounded_LState_ctorElim___redArg(v_t_1384_, v_active_1385_);
return v___x_1386_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_LState_active_elim(lean_object* v_motive_1387_, lean_object* v_t_1388_, lean_object* v_h_1389_, lean_object* v_active_1390_){
_start:
{
lean_object* v___x_1391_; 
v___x_1391_ = lp_bounded_Bounded_LState_ctorElim___redArg(v_t_1388_, v_active_1390_);
return v___x_1391_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_LState_unloading_elim___redArg(lean_object* v_t_1392_, lean_object* v_unloading_1393_){
_start:
{
lean_object* v___x_1394_; 
v___x_1394_ = lp_bounded_Bounded_LState_ctorElim___redArg(v_t_1392_, v_unloading_1393_);
return v___x_1394_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_LState_unloading_elim(lean_object* v_motive_1395_, lean_object* v_t_1396_, lean_object* v_h_1397_, lean_object* v_unloading_1398_){
_start:
{
lean_object* v___x_1399_; 
v___x_1399_ = lp_bounded_Bounded_LState_ctorElim___redArg(v_t_1396_, v_unloading_1398_);
return v___x_1399_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqLState_decEq___lam__0(lean_object* v___x_1400_, lean_object* v_a_1401_, lean_object* v_b_1402_){
_start:
{
lean_object* v___x_1403_; uint8_t v___x_1404_; 
v___x_1403_ = lean_alloc_closure((void*)(l_instDecidableEqFin___boxed), 3, 1);
lean_closure_set(v___x_1403_, 0, v___x_1400_);
v___x_1404_ = l_Option_instDecidableEq___redArg(v___x_1403_, v_a_1401_, v_b_1402_);
return v___x_1404_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqLState_decEq___lam__0___boxed(lean_object* v___x_1405_, lean_object* v_a_1406_, lean_object* v_b_1407_){
_start:
{
uint8_t v_res_1408_; lean_object* v_r_1409_; 
v_res_1408_ = lp_bounded_Bounded_instDecidableEqLState_decEq___lam__0(v___x_1405_, v_a_1406_, v_b_1407_);
v_r_1409_ = lean_box(v_res_1408_);
return v_r_1409_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqLState_decEq(lean_object* v_x_1412_, lean_object* v_x_1413_){
_start:
{
switch(lean_obj_tag(v_x_1412_))
{
case 0:
{
if (lean_obj_tag(v_x_1413_) == 0)
{
uint8_t v_o_1414_; uint8_t v_o_1415_; uint8_t v___x_1416_; 
v_o_1414_ = lean_ctor_get_uint8(v_x_1412_, 0);
lean_dec_ref_known(v_x_1412_, 0);
v_o_1415_ = lean_ctor_get_uint8(v_x_1413_, 0);
lean_dec_ref_known(v_x_1413_, 0);
v___x_1416_ = lp_bounded_Bounded_instDecidableEqOutcome(v_o_1414_, v_o_1415_);
return v___x_1416_;
}
else
{
uint8_t v___x_1417_; 
lean_dec_ref_known(v_x_1412_, 0);
lean_dec_ref(v_x_1413_);
v___x_1417_ = 0;
return v___x_1417_;
}
}
case 1:
{
if (lean_obj_tag(v_x_1413_) == 1)
{
lean_object* v_remaining_1418_; lean_object* v_acc_1419_; lean_object* v_view_1420_; lean_object* v_remaining_1421_; lean_object* v_acc_1422_; lean_object* v_view_1423_; lean_object* v___x_1424_; uint8_t v___x_1425_; 
v_remaining_1418_ = lean_ctor_get(v_x_1412_, 0);
lean_inc(v_remaining_1418_);
v_acc_1419_ = lean_ctor_get(v_x_1412_, 1);
lean_inc(v_acc_1419_);
v_view_1420_ = lean_ctor_get(v_x_1412_, 2);
lean_inc_ref(v_view_1420_);
lean_dec_ref_known(v_x_1412_, 3);
v_remaining_1421_ = lean_ctor_get(v_x_1413_, 0);
lean_inc(v_remaining_1421_);
v_acc_1422_ = lean_ctor_get(v_x_1413_, 1);
lean_inc(v_acc_1422_);
v_view_1423_ = lean_ctor_get(v_x_1413_, 2);
lean_inc_ref(v_view_1423_);
lean_dec_ref_known(v_x_1413_, 3);
v___x_1424_ = lean_alloc_closure((void*)(lp_bounded_Bounded_instDecidableEqStep___boxed), 2, 0);
v___x_1425_ = l_instDecidableEqList___redArg(v___x_1424_, v_remaining_1418_, v_remaining_1421_);
if (v___x_1425_ == 0)
{
lean_dec_ref(v_view_1423_);
lean_dec(v_acc_1422_);
lean_dec_ref(v_view_1420_);
lean_dec(v_acc_1419_);
return v___x_1425_;
}
else
{
lean_object* v___x_1426_; uint8_t v___x_1427_; 
v___x_1426_ = lean_alloc_closure((void*)(lp_bounded_Bounded_instDecidableEqInv___boxed), 2, 0);
v___x_1427_ = l_instDecidableEqList___redArg(v___x_1426_, v_acc_1419_, v_acc_1422_);
if (v___x_1427_ == 0)
{
lean_dec_ref(v_view_1423_);
lean_dec_ref(v_view_1420_);
return v___x_1427_;
}
else
{
lean_object* v___f_1428_; uint8_t v___x_1429_; 
v___f_1428_ = ((lean_object*)(lp_bounded_Bounded_instDecidableEqLState_decEq___closed__0));
v___x_1429_ = lp_bounded_Bounded_instDecidableEqKMap_decEq___redArg(v___f_1428_, v_view_1420_, v_view_1423_);
return v___x_1429_;
}
}
}
else
{
uint8_t v___x_1430_; 
lean_dec_ref_known(v_x_1412_, 3);
lean_dec_ref(v_x_1413_);
v___x_1430_ = 0;
return v___x_1430_;
}
}
case 2:
{
if (lean_obj_tag(v_x_1413_) == 2)
{
lean_object* v_acc_1431_; lean_object* v_view_1432_; lean_object* v_acc_1433_; lean_object* v_view_1434_; lean_object* v___x_1435_; uint8_t v___x_1436_; 
v_acc_1431_ = lean_ctor_get(v_x_1412_, 0);
lean_inc(v_acc_1431_);
v_view_1432_ = lean_ctor_get(v_x_1412_, 1);
lean_inc_ref(v_view_1432_);
lean_dec_ref_known(v_x_1412_, 2);
v_acc_1433_ = lean_ctor_get(v_x_1413_, 0);
lean_inc(v_acc_1433_);
v_view_1434_ = lean_ctor_get(v_x_1413_, 1);
lean_inc_ref(v_view_1434_);
lean_dec_ref_known(v_x_1413_, 2);
v___x_1435_ = lean_alloc_closure((void*)(lp_bounded_Bounded_instDecidableEqInv___boxed), 2, 0);
v___x_1436_ = l_instDecidableEqList___redArg(v___x_1435_, v_acc_1431_, v_acc_1433_);
if (v___x_1436_ == 0)
{
lean_dec_ref(v_view_1434_);
lean_dec_ref(v_view_1432_);
return v___x_1436_;
}
else
{
lean_object* v___f_1437_; uint8_t v___x_1438_; 
v___f_1437_ = ((lean_object*)(lp_bounded_Bounded_instDecidableEqLState_decEq___closed__0));
v___x_1438_ = lp_bounded_Bounded_instDecidableEqKMap_decEq___redArg(v___f_1437_, v_view_1432_, v_view_1434_);
return v___x_1438_;
}
}
else
{
uint8_t v___x_1439_; 
lean_dec_ref_known(v_x_1412_, 2);
lean_dec_ref(v_x_1413_);
v___x_1439_ = 0;
return v___x_1439_;
}
}
default: 
{
if (lean_obj_tag(v_x_1413_) == 3)
{
lean_object* v_acc_1440_; lean_object* v_view_1441_; uint8_t v_o_1442_; lean_object* v_acc_1443_; lean_object* v_view_1444_; uint8_t v_o_1445_; lean_object* v___x_1446_; uint8_t v___x_1447_; 
v_acc_1440_ = lean_ctor_get(v_x_1412_, 0);
lean_inc(v_acc_1440_);
v_view_1441_ = lean_ctor_get(v_x_1412_, 1);
lean_inc_ref(v_view_1441_);
v_o_1442_ = lean_ctor_get_uint8(v_x_1412_, sizeof(void*)*2);
lean_dec_ref_known(v_x_1412_, 2);
v_acc_1443_ = lean_ctor_get(v_x_1413_, 0);
lean_inc(v_acc_1443_);
v_view_1444_ = lean_ctor_get(v_x_1413_, 1);
lean_inc_ref(v_view_1444_);
v_o_1445_ = lean_ctor_get_uint8(v_x_1413_, sizeof(void*)*2);
lean_dec_ref_known(v_x_1413_, 2);
v___x_1446_ = lean_alloc_closure((void*)(lp_bounded_Bounded_instDecidableEqInv___boxed), 2, 0);
v___x_1447_ = l_instDecidableEqList___redArg(v___x_1446_, v_acc_1440_, v_acc_1443_);
if (v___x_1447_ == 0)
{
lean_dec_ref(v_view_1444_);
lean_dec_ref(v_view_1441_);
return v___x_1447_;
}
else
{
lean_object* v___f_1448_; uint8_t v___x_1449_; 
v___f_1448_ = ((lean_object*)(lp_bounded_Bounded_instDecidableEqLState_decEq___closed__0));
v___x_1449_ = lp_bounded_Bounded_instDecidableEqKMap_decEq___redArg(v___f_1448_, v_view_1441_, v_view_1444_);
if (v___x_1449_ == 0)
{
return v___x_1449_;
}
else
{
uint8_t v___x_1450_; 
v___x_1450_ = lp_bounded_Bounded_instDecidableEqOutcome(v_o_1442_, v_o_1445_);
return v___x_1450_;
}
}
}
else
{
uint8_t v___x_1451_; 
lean_dec_ref_known(v_x_1412_, 2);
lean_dec_ref(v_x_1413_);
v___x_1451_ = 0;
return v___x_1451_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqLState_decEq___boxed(lean_object* v_x_1452_, lean_object* v_x_1453_){
_start:
{
uint8_t v_res_1454_; lean_object* v_r_1455_; 
v_res_1454_ = lp_bounded_Bounded_instDecidableEqLState_decEq(v_x_1452_, v_x_1453_);
v_r_1455_ = lean_box(v_res_1454_);
return v_r_1455_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqLState(lean_object* v_x_1456_, lean_object* v_x_1457_){
_start:
{
uint8_t v___x_1458_; 
v___x_1458_ = lp_bounded_Bounded_instDecidableEqLState_decEq(v_x_1456_, v_x_1457_);
return v___x_1458_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqLState___boxed(lean_object* v_x_1459_, lean_object* v_x_1460_){
_start:
{
uint8_t v_res_1461_; lean_object* v_r_1462_; 
v_res_1461_ = lp_bounded_Bounded_instDecidableEqLState(v_x_1459_, v_x_1460_);
v_r_1462_ = lean_box(v_res_1461_);
return v_r_1462_;
}
}
LEAN_EXPORT uint64_t lp_bounded_Bounded_instHashableKMap_hash___at___00Bounded_instHashableLState_hash_spec__1(lean_object* v_x_1463_){
_start:
{
lean_object* v_k0_1464_; lean_object* v_k1_1465_; uint64_t v___x_1466_; uint64_t v___y_1468_; 
v_k0_1464_ = lean_ctor_get(v_x_1463_, 0);
v_k1_1465_ = lean_ctor_get(v_x_1463_, 1);
v___x_1466_ = 0ULL;
if (lean_obj_tag(v_k0_1464_) == 0)
{
uint64_t v___x_1477_; 
v___x_1477_ = 11ULL;
v___y_1468_ = v___x_1477_;
goto v___jp_1467_;
}
else
{
lean_object* v_val_1478_; uint64_t v___x_1479_; uint64_t v___x_1480_; uint64_t v___x_1481_; 
v_val_1478_ = lean_ctor_get(v_k0_1464_, 0);
v___x_1479_ = lean_uint64_of_nat(v_val_1478_);
v___x_1480_ = 13ULL;
v___x_1481_ = lean_uint64_mix_hash(v___x_1479_, v___x_1480_);
v___y_1468_ = v___x_1481_;
goto v___jp_1467_;
}
v___jp_1467_:
{
uint64_t v___x_1469_; 
v___x_1469_ = lean_uint64_mix_hash(v___x_1466_, v___y_1468_);
if (lean_obj_tag(v_k1_1465_) == 0)
{
uint64_t v___x_1470_; uint64_t v___x_1471_; 
v___x_1470_ = 11ULL;
v___x_1471_ = lean_uint64_mix_hash(v___x_1469_, v___x_1470_);
return v___x_1471_;
}
else
{
lean_object* v_val_1472_; uint64_t v___x_1473_; uint64_t v___x_1474_; uint64_t v___x_1475_; uint64_t v___x_1476_; 
v_val_1472_ = lean_ctor_get(v_k1_1465_, 0);
v___x_1473_ = lean_uint64_of_nat(v_val_1472_);
v___x_1474_ = 13ULL;
v___x_1475_ = lean_uint64_mix_hash(v___x_1473_, v___x_1474_);
v___x_1476_ = lean_uint64_mix_hash(v___x_1469_, v___x_1475_);
return v___x_1476_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instHashableKMap_hash___at___00Bounded_instHashableLState_hash_spec__1___boxed(lean_object* v_x_1482_){
_start:
{
uint64_t v_res_1483_; lean_object* v_r_1484_; 
v_res_1483_ = lp_bounded_Bounded_instHashableKMap_hash___at___00Bounded_instHashableLState_hash_spec__1(v_x_1482_);
lean_dec_ref(v_x_1482_);
v_r_1484_ = lean_box_uint64(v_res_1483_);
return v_r_1484_;
}
}
LEAN_EXPORT uint64_t lp_bounded_List_foldl___at___00Bounded_instHashableLState_hash_spec__0(uint64_t v_x_1485_, lean_object* v_x_1486_){
_start:
{
if (lean_obj_tag(v_x_1486_) == 0)
{
return v_x_1485_;
}
else
{
lean_object* v_head_1487_; lean_object* v_tail_1488_; uint64_t v___x_1489_; uint64_t v___x_1490_; 
v_head_1487_ = lean_ctor_get(v_x_1486_, 0);
v_tail_1488_ = lean_ctor_get(v_x_1486_, 1);
v___x_1489_ = lp_bounded_Bounded_instHashableInv_hash(v_head_1487_);
v___x_1490_ = lean_uint64_mix_hash(v_x_1485_, v___x_1489_);
v_x_1485_ = v___x_1490_;
v_x_1486_ = v_tail_1488_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_List_foldl___at___00Bounded_instHashableLState_hash_spec__0___boxed(lean_object* v_x_1492_, lean_object* v_x_1493_){
_start:
{
uint64_t v_x_353__boxed_1494_; uint64_t v_res_1495_; lean_object* v_r_1496_; 
v_x_353__boxed_1494_ = lean_unbox_uint64(v_x_1492_);
lean_dec_ref(v_x_1492_);
v_res_1495_ = lp_bounded_List_foldl___at___00Bounded_instHashableLState_hash_spec__0(v_x_353__boxed_1494_, v_x_1493_);
lean_dec(v_x_1493_);
v_r_1496_ = lean_box_uint64(v_res_1495_);
return v_r_1496_;
}
}
LEAN_EXPORT uint64_t lp_bounded_Bounded_instHashableLState_hash(lean_object* v_x_1497_){
_start:
{
switch(lean_obj_tag(v_x_1497_))
{
case 0:
{
uint8_t v_o_1498_; uint64_t v___x_1499_; uint64_t v___x_1500_; uint64_t v___x_1501_; 
v_o_1498_ = lean_ctor_get_uint8(v_x_1497_, 0);
v___x_1499_ = 0ULL;
v___x_1500_ = lp_bounded_Bounded_instHashableOutcome_hash(v_o_1498_);
v___x_1501_ = lean_uint64_mix_hash(v___x_1499_, v___x_1500_);
return v___x_1501_;
}
case 1:
{
lean_object* v_remaining_1502_; lean_object* v_acc_1503_; lean_object* v_view_1504_; uint64_t v___x_1505_; uint64_t v___x_1506_; uint64_t v___x_1507_; uint64_t v___x_1508_; uint64_t v___x_1509_; uint64_t v___x_1510_; uint64_t v___x_1511_; uint64_t v___x_1512_; 
v_remaining_1502_ = lean_ctor_get(v_x_1497_, 0);
v_acc_1503_ = lean_ctor_get(v_x_1497_, 1);
v_view_1504_ = lean_ctor_get(v_x_1497_, 2);
v___x_1505_ = 1ULL;
v___x_1506_ = 7ULL;
v___x_1507_ = lp_bounded_List_foldl___at___00Bounded_instHashableComponent_hash_spec__1(v___x_1506_, v_remaining_1502_);
v___x_1508_ = lean_uint64_mix_hash(v___x_1505_, v___x_1507_);
v___x_1509_ = lp_bounded_List_foldl___at___00Bounded_instHashableLState_hash_spec__0(v___x_1506_, v_acc_1503_);
v___x_1510_ = lean_uint64_mix_hash(v___x_1508_, v___x_1509_);
v___x_1511_ = lp_bounded_Bounded_instHashableKMap_hash___at___00Bounded_instHashableLState_hash_spec__1(v_view_1504_);
v___x_1512_ = lean_uint64_mix_hash(v___x_1510_, v___x_1511_);
return v___x_1512_;
}
case 2:
{
lean_object* v_acc_1513_; lean_object* v_view_1514_; uint64_t v___x_1515_; uint64_t v___x_1516_; uint64_t v___x_1517_; uint64_t v___x_1518_; uint64_t v___x_1519_; uint64_t v___x_1520_; 
v_acc_1513_ = lean_ctor_get(v_x_1497_, 0);
v_view_1514_ = lean_ctor_get(v_x_1497_, 1);
v___x_1515_ = 2ULL;
v___x_1516_ = 7ULL;
v___x_1517_ = lp_bounded_List_foldl___at___00Bounded_instHashableLState_hash_spec__0(v___x_1516_, v_acc_1513_);
v___x_1518_ = lean_uint64_mix_hash(v___x_1515_, v___x_1517_);
v___x_1519_ = lp_bounded_Bounded_instHashableKMap_hash___at___00Bounded_instHashableLState_hash_spec__1(v_view_1514_);
v___x_1520_ = lean_uint64_mix_hash(v___x_1518_, v___x_1519_);
return v___x_1520_;
}
default: 
{
lean_object* v_acc_1521_; lean_object* v_view_1522_; uint8_t v_o_1523_; uint64_t v___x_1524_; uint64_t v___x_1525_; uint64_t v___x_1526_; uint64_t v___x_1527_; uint64_t v___x_1528_; uint64_t v___x_1529_; uint64_t v___x_1530_; uint64_t v___x_1531_; 
v_acc_1521_ = lean_ctor_get(v_x_1497_, 0);
v_view_1522_ = lean_ctor_get(v_x_1497_, 1);
v_o_1523_ = lean_ctor_get_uint8(v_x_1497_, sizeof(void*)*2);
v___x_1524_ = 3ULL;
v___x_1525_ = 7ULL;
v___x_1526_ = lp_bounded_List_foldl___at___00Bounded_instHashableLState_hash_spec__0(v___x_1525_, v_acc_1521_);
v___x_1527_ = lean_uint64_mix_hash(v___x_1524_, v___x_1526_);
v___x_1528_ = lp_bounded_Bounded_instHashableKMap_hash___at___00Bounded_instHashableLState_hash_spec__1(v_view_1522_);
v___x_1529_ = lean_uint64_mix_hash(v___x_1527_, v___x_1528_);
v___x_1530_ = lp_bounded_Bounded_instHashableOutcome_hash(v_o_1523_);
v___x_1531_ = lean_uint64_mix_hash(v___x_1529_, v___x_1530_);
return v___x_1531_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instHashableLState_hash___boxed(lean_object* v_x_1532_){
_start:
{
uint64_t v_res_1533_; lean_object* v_r_1534_; 
v_res_1533_ = lp_bounded_Bounded_instHashableLState_hash(v_x_1532_);
lean_dec_ref(v_x_1532_);
v_r_1534_ = lean_box_uint64(v_res_1533_);
return v_r_1534_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_LState_isActive(lean_object* v_x_1537_){
_start:
{
if (lean_obj_tag(v_x_1537_) == 2)
{
uint8_t v___x_1538_; 
v___x_1538_ = 1;
return v___x_1538_;
}
else
{
uint8_t v___x_1539_; 
v___x_1539_ = 0;
return v___x_1539_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_LState_isActive___boxed(lean_object* v_x_1540_){
_start:
{
uint8_t v_res_1541_; lean_object* v_r_1542_; 
v_res_1541_ = lp_bounded_Bounded_LState_isActive(v_x_1540_);
lean_dec_ref(v_x_1540_);
v_r_1542_ = lean_box(v_res_1541_);
return v_r_1542_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_LState_viewOf(lean_object* v_x_1543_){
_start:
{
switch(lean_obj_tag(v_x_1543_))
{
case 0:
{
lean_object* v___x_1544_; 
v___x_1544_ = lean_box(0);
return v___x_1544_;
}
case 1:
{
lean_object* v_view_1545_; lean_object* v___x_1546_; 
v_view_1545_ = lean_ctor_get(v_x_1543_, 2);
lean_inc_ref(v_view_1545_);
v___x_1546_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_1546_, 0, v_view_1545_);
return v___x_1546_;
}
default: 
{
lean_object* v_view_1547_; lean_object* v___x_1548_; 
v_view_1547_ = lean_ctor_get(v_x_1543_, 1);
lean_inc_ref(v_view_1547_);
v___x_1548_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_1548_, 0, v_view_1547_);
return v___x_1548_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_LState_viewOf___boxed(lean_object* v_x_1549_){
_start:
{
lean_object* v_res_1550_; 
v_res_1550_ = lp_bounded_Bounded_LState_viewOf(v_x_1549_);
lean_dec_ref(v_x_1549_);
return v_res_1550_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_LState_isInstalled(lean_object* v_s_1551_){
_start:
{
lean_object* v___x_1552_; 
v___x_1552_ = lp_bounded_Bounded_LState_viewOf(v_s_1551_);
if (lean_obj_tag(v___x_1552_) == 0)
{
uint8_t v___x_1553_; 
v___x_1553_ = 0;
return v___x_1553_;
}
else
{
uint8_t v___x_1554_; 
lean_dec_ref_known(v___x_1552_, 1);
v___x_1554_ = 1;
return v___x_1554_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_LState_isInstalled___boxed(lean_object* v_s_1555_){
_start:
{
uint8_t v_res_1556_; lean_object* v_r_1557_; 
v_res_1556_ = lp_bounded_Bounded_LState_isInstalled(v_s_1555_);
lean_dec_ref(v_s_1555_);
v_r_1557_ = lean_box(v_res_1556_);
return v_r_1557_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqFiber_decEq___lam__0(lean_object* v_a_1560_, lean_object* v_b_1561_){
_start:
{
lean_object* v___x_1562_; uint8_t v___x_1563_; 
v___x_1562_ = ((lean_object*)(lp_bounded_Bounded_instDecidableEqFiber_decEq___lam__0___closed__0));
v___x_1563_ = l_Option_instDecidableEq___redArg(v___x_1562_, v_a_1560_, v_b_1561_);
return v___x_1563_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqFiber_decEq___lam__0___boxed(lean_object* v_a_1564_, lean_object* v_b_1565_){
_start:
{
uint8_t v_res_1566_; lean_object* v_r_1567_; 
v_res_1566_ = lp_bounded_Bounded_instDecidableEqFiber_decEq___lam__0(v_a_1564_, v_b_1565_);
v_r_1567_ = lean_box(v_res_1566_);
return v_r_1567_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqFiber_decEq(lean_object* v_x_1571_, lean_object* v_x_1572_){
_start:
{
lean_object* v_comp_1573_; lean_object* v_parent_1574_; uint8_t v_retired_1575_; lean_object* v_table_1576_; lean_object* v_st_1577_; lean_object* v_comp_1578_; lean_object* v_parent_1579_; uint8_t v_retired_1580_; lean_object* v_table_1581_; lean_object* v_st_1582_; uint8_t v___x_1583_; 
v_comp_1573_ = lean_ctor_get(v_x_1571_, 0);
lean_inc_ref(v_comp_1573_);
v_parent_1574_ = lean_ctor_get(v_x_1571_, 1);
lean_inc(v_parent_1574_);
v_retired_1575_ = lean_ctor_get_uint8(v_x_1571_, sizeof(void*)*4);
v_table_1576_ = lean_ctor_get(v_x_1571_, 2);
lean_inc_ref(v_table_1576_);
v_st_1577_ = lean_ctor_get(v_x_1571_, 3);
lean_inc_ref(v_st_1577_);
lean_dec_ref(v_x_1571_);
v_comp_1578_ = lean_ctor_get(v_x_1572_, 0);
lean_inc_ref(v_comp_1578_);
v_parent_1579_ = lean_ctor_get(v_x_1572_, 1);
lean_inc(v_parent_1579_);
v_retired_1580_ = lean_ctor_get_uint8(v_x_1572_, sizeof(void*)*4);
v_table_1581_ = lean_ctor_get(v_x_1572_, 2);
lean_inc_ref(v_table_1581_);
v_st_1582_ = lean_ctor_get(v_x_1572_, 3);
lean_inc_ref(v_st_1582_);
lean_dec_ref(v_x_1572_);
v___x_1583_ = lp_bounded_Bounded_instDecidableEqComponent_decEq(v_comp_1573_, v_comp_1578_);
if (v___x_1583_ == 0)
{
lean_dec_ref(v_st_1582_);
lean_dec_ref(v_table_1581_);
lean_dec(v_parent_1579_);
lean_dec_ref(v_st_1577_);
lean_dec_ref(v_table_1576_);
lean_dec(v_parent_1574_);
return v___x_1583_;
}
else
{
lean_object* v___x_1584_; uint8_t v___x_1585_; 
v___x_1584_ = ((lean_object*)(lp_bounded_Bounded_instDecidableEqFiber_decEq___closed__0));
v___x_1585_ = l_Option_instDecidableEq___redArg(v___x_1584_, v_parent_1574_, v_parent_1579_);
if (v___x_1585_ == 0)
{
lean_dec_ref(v_st_1582_);
lean_dec_ref(v_table_1581_);
lean_dec_ref(v_st_1577_);
lean_dec_ref(v_table_1576_);
return v___x_1585_;
}
else
{
lean_object* v___f_1586_; 
v___f_1586_ = ((lean_object*)(lp_bounded_Bounded_instDecidableEqFiber_decEq___closed__1));
if (v_retired_1575_ == 0)
{
if (v_retired_1580_ == 0)
{
goto v___jp_1587_;
}
else
{
lean_dec_ref(v_st_1582_);
lean_dec_ref(v_table_1581_);
lean_dec_ref(v_st_1577_);
lean_dec_ref(v_table_1576_);
return v_retired_1575_;
}
}
else
{
if (v_retired_1580_ == 0)
{
lean_dec_ref(v_st_1582_);
lean_dec_ref(v_table_1581_);
lean_dec_ref(v_st_1577_);
lean_dec_ref(v_table_1576_);
return v_retired_1580_;
}
else
{
goto v___jp_1587_;
}
}
v___jp_1587_:
{
uint8_t v___x_1588_; 
v___x_1588_ = lp_bounded_Bounded_instDecidableEqKMap_decEq___redArg(v___f_1586_, v_table_1576_, v_table_1581_);
if (v___x_1588_ == 0)
{
lean_dec_ref(v_st_1582_);
lean_dec_ref(v_st_1577_);
return v___x_1588_;
}
else
{
uint8_t v___x_1589_; 
v___x_1589_ = lp_bounded_Bounded_instDecidableEqLState_decEq(v_st_1577_, v_st_1582_);
return v___x_1589_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqFiber_decEq___boxed(lean_object* v_x_1590_, lean_object* v_x_1591_){
_start:
{
uint8_t v_res_1592_; lean_object* v_r_1593_; 
v_res_1592_ = lp_bounded_Bounded_instDecidableEqFiber_decEq(v_x_1590_, v_x_1591_);
v_r_1593_ = lean_box(v_res_1592_);
return v_r_1593_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqFiber(lean_object* v_x_1594_, lean_object* v_x_1595_){
_start:
{
uint8_t v___x_1596_; 
v___x_1596_ = lp_bounded_Bounded_instDecidableEqFiber_decEq(v_x_1594_, v_x_1595_);
return v___x_1596_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqFiber___boxed(lean_object* v_x_1597_, lean_object* v_x_1598_){
_start:
{
uint8_t v_res_1599_; lean_object* v_r_1600_; 
v_res_1599_ = lp_bounded_Bounded_instDecidableEqFiber(v_x_1597_, v_x_1598_);
v_r_1600_ = lean_box(v_res_1599_);
return v_r_1600_;
}
}
LEAN_EXPORT uint64_t lp_bounded_Bounded_instHashableKMap_hash___at___00Bounded_instHashableFiber_hash_spec__0(lean_object* v_x_1601_){
_start:
{
lean_object* v_k0_1602_; lean_object* v_k1_1603_; uint64_t v___x_1604_; uint64_t v___y_1606_; 
v_k0_1602_ = lean_ctor_get(v_x_1601_, 0);
v_k1_1603_ = lean_ctor_get(v_x_1601_, 1);
v___x_1604_ = 0ULL;
if (lean_obj_tag(v_k0_1602_) == 0)
{
uint64_t v___x_1615_; 
v___x_1615_ = 11ULL;
v___y_1606_ = v___x_1615_;
goto v___jp_1605_;
}
else
{
lean_object* v_val_1616_; uint64_t v___x_1617_; uint64_t v___x_1618_; uint64_t v___x_1619_; 
v_val_1616_ = lean_ctor_get(v_k0_1602_, 0);
v___x_1617_ = lean_uint64_of_nat(v_val_1616_);
v___x_1618_ = 13ULL;
v___x_1619_ = lean_uint64_mix_hash(v___x_1617_, v___x_1618_);
v___y_1606_ = v___x_1619_;
goto v___jp_1605_;
}
v___jp_1605_:
{
uint64_t v___x_1607_; 
v___x_1607_ = lean_uint64_mix_hash(v___x_1604_, v___y_1606_);
if (lean_obj_tag(v_k1_1603_) == 0)
{
uint64_t v___x_1608_; uint64_t v___x_1609_; 
v___x_1608_ = 11ULL;
v___x_1609_ = lean_uint64_mix_hash(v___x_1607_, v___x_1608_);
return v___x_1609_;
}
else
{
lean_object* v_val_1610_; uint64_t v___x_1611_; uint64_t v___x_1612_; uint64_t v___x_1613_; uint64_t v___x_1614_; 
v_val_1610_ = lean_ctor_get(v_k1_1603_, 0);
v___x_1611_ = lean_uint64_of_nat(v_val_1610_);
v___x_1612_ = 13ULL;
v___x_1613_ = lean_uint64_mix_hash(v___x_1611_, v___x_1612_);
v___x_1614_ = lean_uint64_mix_hash(v___x_1607_, v___x_1613_);
return v___x_1614_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instHashableKMap_hash___at___00Bounded_instHashableFiber_hash_spec__0___boxed(lean_object* v_x_1620_){
_start:
{
uint64_t v_res_1621_; lean_object* v_r_1622_; 
v_res_1621_ = lp_bounded_Bounded_instHashableKMap_hash___at___00Bounded_instHashableFiber_hash_spec__0(v_x_1620_);
lean_dec_ref(v_x_1620_);
v_r_1622_ = lean_box_uint64(v_res_1621_);
return v_r_1622_;
}
}
LEAN_EXPORT uint64_t lp_bounded_Bounded_instHashableFiber_hash(lean_object* v_x_1623_){
_start:
{
lean_object* v_comp_1624_; lean_object* v_parent_1625_; uint8_t v_retired_1626_; lean_object* v_table_1627_; lean_object* v_st_1628_; uint64_t v___y_1630_; uint64_t v___y_1631_; uint64_t v___x_1637_; uint64_t v___x_1638_; uint64_t v___x_1639_; uint64_t v___y_1641_; 
v_comp_1624_ = lean_ctor_get(v_x_1623_, 0);
v_parent_1625_ = lean_ctor_get(v_x_1623_, 1);
v_retired_1626_ = lean_ctor_get_uint8(v_x_1623_, sizeof(void*)*4);
v_table_1627_ = lean_ctor_get(v_x_1623_, 2);
v_st_1628_ = lean_ctor_get(v_x_1623_, 3);
v___x_1637_ = 0ULL;
v___x_1638_ = lp_bounded_Bounded_instHashableComponent_hash(v_comp_1624_);
v___x_1639_ = lean_uint64_mix_hash(v___x_1637_, v___x_1638_);
if (lean_obj_tag(v_parent_1625_) == 0)
{
uint64_t v___x_1645_; 
v___x_1645_ = 11ULL;
v___y_1641_ = v___x_1645_;
goto v___jp_1640_;
}
else
{
lean_object* v_val_1646_; uint64_t v___x_1647_; uint64_t v___x_1648_; uint64_t v___x_1649_; 
v_val_1646_ = lean_ctor_get(v_parent_1625_, 0);
v___x_1647_ = lean_uint64_of_nat(v_val_1646_);
v___x_1648_ = 13ULL;
v___x_1649_ = lean_uint64_mix_hash(v___x_1647_, v___x_1648_);
v___y_1641_ = v___x_1649_;
goto v___jp_1640_;
}
v___jp_1629_:
{
uint64_t v___x_1632_; uint64_t v___x_1633_; uint64_t v___x_1634_; uint64_t v___x_1635_; uint64_t v___x_1636_; 
v___x_1632_ = lean_uint64_mix_hash(v___y_1630_, v___y_1631_);
v___x_1633_ = lp_bounded_Bounded_instHashableKMap_hash___at___00Bounded_instHashableFiber_hash_spec__0(v_table_1627_);
v___x_1634_ = lean_uint64_mix_hash(v___x_1632_, v___x_1633_);
v___x_1635_ = lp_bounded_Bounded_instHashableLState_hash(v_st_1628_);
v___x_1636_ = lean_uint64_mix_hash(v___x_1634_, v___x_1635_);
return v___x_1636_;
}
v___jp_1640_:
{
uint64_t v___x_1642_; 
v___x_1642_ = lean_uint64_mix_hash(v___x_1639_, v___y_1641_);
if (v_retired_1626_ == 0)
{
uint64_t v___x_1643_; 
v___x_1643_ = 13ULL;
v___y_1630_ = v___x_1642_;
v___y_1631_ = v___x_1643_;
goto v___jp_1629_;
}
else
{
uint64_t v___x_1644_; 
v___x_1644_ = 11ULL;
v___y_1630_ = v___x_1642_;
v___y_1631_ = v___x_1644_;
goto v___jp_1629_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instHashableFiber_hash___boxed(lean_object* v_x_1650_){
_start:
{
uint64_t v_res_1651_; lean_object* v_r_1652_; 
v_res_1651_ = lp_bounded_Bounded_instHashableFiber_hash(v_x_1650_);
lean_dec_ref(v_x_1650_);
v_r_1652_ = lean_box_uint64(v_res_1651_);
return v_r_1652_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqConfig___aux__1___lam__0(lean_object* v_a_1655_, lean_object* v_b_1656_){
_start:
{
lean_object* v___x_1657_; uint8_t v___x_1658_; 
v___x_1657_ = lean_alloc_closure((void*)(lp_bounded_Bounded_instDecidableEqFiber___boxed), 2, 0);
v___x_1658_ = l_Option_instDecidableEq___redArg(v___x_1657_, v_a_1655_, v_b_1656_);
return v___x_1658_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqConfig___aux__1___lam__0___boxed(lean_object* v_a_1659_, lean_object* v_b_1660_){
_start:
{
uint8_t v_res_1661_; lean_object* v_r_1662_; 
v_res_1661_ = lp_bounded_Bounded_instDecidableEqConfig___aux__1___lam__0(v_a_1659_, v_b_1660_);
v_r_1662_ = lean_box(v_res_1661_);
return v_r_1662_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqConfig___aux__1(lean_object* v_a_1664_, lean_object* v_b_1665_){
_start:
{
lean_object* v___f_1666_; uint8_t v___x_1667_; 
v___f_1666_ = ((lean_object*)(lp_bounded_Bounded_instDecidableEqConfig___aux__1___closed__0));
v___x_1667_ = lp_bounded_Bounded_instDecidableEqSMap_decEq___redArg(v___f_1666_, v_a_1664_, v_b_1665_);
return v___x_1667_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqConfig___aux__1___boxed(lean_object* v_a_1668_, lean_object* v_b_1669_){
_start:
{
uint8_t v_res_1670_; lean_object* v_r_1671_; 
v_res_1670_ = lp_bounded_Bounded_instDecidableEqConfig___aux__1(v_a_1668_, v_b_1669_);
v_r_1671_ = lean_box(v_res_1670_);
return v_r_1671_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqConfig(lean_object* v_a_1672_, lean_object* v_b_1673_){
_start:
{
uint8_t v___x_1674_; 
v___x_1674_ = lp_bounded_Bounded_instDecidableEqConfig___aux__1(v_a_1672_, v_b_1673_);
return v___x_1674_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqConfig___boxed(lean_object* v_a_1675_, lean_object* v_b_1676_){
_start:
{
uint8_t v_res_1677_; lean_object* v_r_1678_; 
v_res_1677_ = lp_bounded_Bounded_instDecidableEqConfig(v_a_1675_, v_b_1676_);
v_r_1678_ = lean_box(v_res_1677_);
return v_r_1678_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Config_get(lean_object* v_00_u03b3_1682_, lean_object* v_n_1683_){
_start:
{
lean_object* v___x_1684_; 
v___x_1684_ = lp_bounded_Bounded_SMap_get___redArg(v_00_u03b3_1682_, v_n_1683_);
return v___x_1684_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Config_get___boxed(lean_object* v_00_u03b3_1685_, lean_object* v_n_1686_){
_start:
{
lean_object* v_res_1687_; 
v_res_1687_ = lp_bounded_Bounded_Config_get(v_00_u03b3_1685_, v_n_1686_);
lean_dec(v_n_1686_);
lean_dec_ref(v_00_u03b3_1685_);
return v_res_1687_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_upd(lean_object* v_00_u03b3_1688_, lean_object* v_n_1689_, lean_object* v_x_1690_){
_start:
{
lean_object* v___x_1691_; 
v___x_1691_ = lp_bounded_Bounded_SMap_set___redArg(v_00_u03b3_1688_, v_n_1689_, v_x_1690_);
return v___x_1691_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_upd___boxed(lean_object* v_00_u03b3_1692_, lean_object* v_n_1693_, lean_object* v_x_1694_){
_start:
{
lean_object* v_res_1695_; 
v_res_1695_ = lp_bounded_Bounded_upd(v_00_u03b3_1692_, v_n_1693_, v_x_1694_);
lean_dec(v_n_1693_);
return v_res_1695_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_provP(lean_object* v_00_u03b3_1696_, lean_object* v_n_1697_, lean_object* v_k_1698_){
_start:
{
lean_object* v___x_1699_; 
v___x_1699_ = lp_bounded_Bounded_SMap_get___redArg(v_00_u03b3_1696_, v_n_1697_);
if (lean_obj_tag(v___x_1699_) == 0)
{
uint8_t v___x_1700_; 
v___x_1700_ = 0;
return v___x_1700_;
}
else
{
lean_object* v_val_1701_; lean_object* v_table_1702_; lean_object* v_st_1703_; uint8_t v___x_1704_; 
v_val_1701_ = lean_ctor_get(v___x_1699_, 0);
lean_inc(v_val_1701_);
lean_dec_ref_known(v___x_1699_, 1);
v_table_1702_ = lean_ctor_get(v_val_1701_, 2);
lean_inc_ref(v_table_1702_);
v_st_1703_ = lean_ctor_get(v_val_1701_, 3);
lean_inc_ref(v_st_1703_);
lean_dec(v_val_1701_);
v___x_1704_ = lp_bounded_Bounded_LState_isActive(v_st_1703_);
lean_dec_ref(v_st_1703_);
if (v___x_1704_ == 0)
{
lean_dec_ref(v_table_1702_);
return v___x_1704_;
}
else
{
lean_object* v___x_1705_; 
v___x_1705_ = lp_bounded_Bounded_KMap_get___redArg(v_table_1702_, v_k_1698_);
lean_dec_ref(v_table_1702_);
if (lean_obj_tag(v___x_1705_) == 0)
{
uint8_t v___x_1706_; 
v___x_1706_ = 0;
return v___x_1706_;
}
else
{
lean_dec_ref_known(v___x_1705_, 1);
return v___x_1704_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_provP___boxed(lean_object* v_00_u03b3_1707_, lean_object* v_n_1708_, lean_object* v_k_1709_){
_start:
{
uint8_t v_res_1710_; lean_object* v_r_1711_; 
v_res_1710_ = lp_bounded_Bounded_provP(v_00_u03b3_1707_, v_n_1708_, v_k_1709_);
lean_dec(v_k_1709_);
lean_dec(v_n_1708_);
lean_dec_ref(v_00_u03b3_1707_);
v_r_1711_ = lean_box(v_res_1710_);
return v_r_1711_;
}
}
LEAN_EXPORT lean_object* lp_bounded_List_find_x3f___at___00Bounded_providerOf_spec__0(lean_object* v_00_u03b3_1712_, lean_object* v_k_1713_, lean_object* v_x_1714_){
_start:
{
if (lean_obj_tag(v_x_1714_) == 0)
{
lean_object* v___x_1715_; 
v___x_1715_ = lean_box(0);
return v___x_1715_;
}
else
{
lean_object* v_head_1716_; lean_object* v_tail_1717_; uint8_t v___x_1718_; 
v_head_1716_ = lean_ctor_get(v_x_1714_, 0);
v_tail_1717_ = lean_ctor_get(v_x_1714_, 1);
v___x_1718_ = lp_bounded_Bounded_provP(v_00_u03b3_1712_, v_head_1716_, v_k_1713_);
if (v___x_1718_ == 0)
{
v_x_1714_ = v_tail_1717_;
goto _start;
}
else
{
lean_object* v___x_1720_; 
lean_inc(v_head_1716_);
v___x_1720_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_1720_, 0, v_head_1716_);
return v___x_1720_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_List_find_x3f___at___00Bounded_providerOf_spec__0___boxed(lean_object* v_00_u03b3_1721_, lean_object* v_k_1722_, lean_object* v_x_1723_){
_start:
{
lean_object* v_res_1724_; 
v_res_1724_ = lp_bounded_List_find_x3f___at___00Bounded_providerOf_spec__0(v_00_u03b3_1721_, v_k_1722_, v_x_1723_);
lean_dec(v_x_1723_);
lean_dec(v_k_1722_);
lean_dec_ref(v_00_u03b3_1721_);
return v_res_1724_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_providerOf(lean_object* v_00_u03b3_1725_, lean_object* v_k_1726_){
_start:
{
lean_object* v___x_1727_; lean_object* v___x_1728_; 
v___x_1727_ = lp_bounded_Bounded_allSlots;
v___x_1728_ = lp_bounded_List_find_x3f___at___00Bounded_providerOf_spec__0(v_00_u03b3_1725_, v_k_1726_, v___x_1727_);
return v___x_1728_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_providerOf___boxed(lean_object* v_00_u03b3_1729_, lean_object* v_k_1730_){
_start:
{
lean_object* v_res_1731_; 
v_res_1731_ = lp_bounded_Bounded_providerOf(v_00_u03b3_1729_, v_k_1730_);
lean_dec(v_k_1730_);
lean_dec_ref(v_00_u03b3_1729_);
return v_res_1731_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_storeOf(lean_object* v_00_u03b3_1732_, lean_object* v_k_1733_){
_start:
{
lean_object* v___x_1734_; 
v___x_1734_ = lp_bounded_Bounded_providerOf(v_00_u03b3_1732_, v_k_1733_);
if (lean_obj_tag(v___x_1734_) == 0)
{
return v___x_1734_;
}
else
{
lean_object* v_val_1735_; lean_object* v___x_1736_; 
v_val_1735_ = lean_ctor_get(v___x_1734_, 0);
lean_inc(v_val_1735_);
lean_dec_ref_known(v___x_1734_, 1);
v___x_1736_ = lp_bounded_Bounded_SMap_get___redArg(v_00_u03b3_1732_, v_val_1735_);
lean_dec(v_val_1735_);
if (lean_obj_tag(v___x_1736_) == 0)
{
lean_object* v___x_1737_; 
v___x_1737_ = lean_box(0);
return v___x_1737_;
}
else
{
lean_object* v_val_1738_; lean_object* v_table_1739_; lean_object* v___x_1740_; 
v_val_1738_ = lean_ctor_get(v___x_1736_, 0);
lean_inc(v_val_1738_);
lean_dec_ref_known(v___x_1736_, 1);
v_table_1739_ = lean_ctor_get(v_val_1738_, 2);
lean_inc_ref(v_table_1739_);
lean_dec(v_val_1738_);
v___x_1740_ = lp_bounded_Bounded_KMap_get___redArg(v_table_1739_, v_k_1733_);
lean_dec_ref(v_table_1739_);
return v___x_1740_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_storeOf___boxed(lean_object* v_00_u03b3_1741_, lean_object* v_k_1742_){
_start:
{
lean_object* v_res_1743_; 
v_res_1743_ = lp_bounded_Bounded_storeOf(v_00_u03b3_1741_, v_k_1742_);
lean_dec(v_k_1742_);
lean_dec_ref(v_00_u03b3_1741_);
return v_res_1743_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidablePredConfigWF___aux__1___lam__0(lean_object* v_00_u03b3_1744_, lean_object* v_a_1745_, lean_object* v_a_1746_, lean_object* v_a_1747_){
_start:
{
uint8_t v___x_1748_; 
v___x_1748_ = lp_bounded_Bounded_provP(v_00_u03b3_1744_, v_a_1745_, v_a_1746_);
if (v___x_1748_ == 0)
{
uint8_t v___x_1749_; 
v___x_1749_ = 1;
return v___x_1749_;
}
else
{
uint8_t v___x_1750_; 
v___x_1750_ = lp_bounded_Bounded_provP(v_00_u03b3_1744_, v_a_1747_, v_a_1746_);
if (v___x_1750_ == 0)
{
return v___x_1748_;
}
else
{
uint8_t v___x_1751_; 
v___x_1751_ = lean_nat_dec_eq(v_a_1745_, v_a_1747_);
return v___x_1751_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidablePredConfigWF___aux__1___lam__0___boxed(lean_object* v_00_u03b3_1752_, lean_object* v_a_1753_, lean_object* v_a_1754_, lean_object* v_a_1755_){
_start:
{
uint8_t v_res_1756_; lean_object* v_r_1757_; 
v_res_1756_ = lp_bounded_Bounded_instDecidablePredConfigWF___aux__1___lam__0(v_00_u03b3_1752_, v_a_1753_, v_a_1754_, v_a_1755_);
lean_dec(v_a_1755_);
lean_dec(v_a_1754_);
lean_dec(v_a_1753_);
lean_dec_ref(v_00_u03b3_1752_);
v_r_1757_ = lean_box(v_res_1756_);
return v_r_1757_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidablePredConfigWF___aux__1___lam__1(lean_object* v_00_u03b3_1758_, lean_object* v_a_1759_, lean_object* v___x_1760_, lean_object* v_a_1761_){
_start:
{
lean_object* v___f_1762_; uint8_t v___x_1763_; 
v___f_1762_ = lean_alloc_closure((void*)(lp_bounded_Bounded_instDecidablePredConfigWF___aux__1___lam__0___boxed), 4, 3);
lean_closure_set(v___f_1762_, 0, v_00_u03b3_1758_);
lean_closure_set(v___f_1762_, 1, v_a_1761_);
lean_closure_set(v___f_1762_, 2, v_a_1759_);
v___x_1763_ = l_Nat_decidableForallFin___redArg(v___x_1760_, v___f_1762_);
return v___x_1763_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidablePredConfigWF___aux__1___lam__1___boxed(lean_object* v_00_u03b3_1764_, lean_object* v_a_1765_, lean_object* v___x_1766_, lean_object* v_a_1767_){
_start:
{
uint8_t v_res_1768_; lean_object* v_r_1769_; 
v_res_1768_ = lp_bounded_Bounded_instDecidablePredConfigWF___aux__1___lam__1(v_00_u03b3_1764_, v_a_1765_, v___x_1766_, v_a_1767_);
v_r_1769_ = lean_box(v_res_1768_);
return v_r_1769_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidablePredConfigWF___aux__1___lam__2(lean_object* v_00_u03b3_1770_, lean_object* v_a_1771_){
_start:
{
lean_object* v___x_1772_; lean_object* v___f_1773_; uint8_t v___x_1774_; 
v___x_1772_ = lean_unsigned_to_nat(3u);
v___f_1773_ = lean_alloc_closure((void*)(lp_bounded_Bounded_instDecidablePredConfigWF___aux__1___lam__1___boxed), 4, 3);
lean_closure_set(v___f_1773_, 0, v_00_u03b3_1770_);
lean_closure_set(v___f_1773_, 1, v_a_1771_);
lean_closure_set(v___f_1773_, 2, v___x_1772_);
v___x_1774_ = l_Nat_decidableForallFin___redArg(v___x_1772_, v___f_1773_);
return v___x_1774_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidablePredConfigWF___aux__1___lam__2___boxed(lean_object* v_00_u03b3_1775_, lean_object* v_a_1776_){
_start:
{
uint8_t v_res_1777_; lean_object* v_r_1778_; 
v_res_1777_ = lp_bounded_Bounded_instDecidablePredConfigWF___aux__1___lam__2(v_00_u03b3_1775_, v_a_1776_);
v_r_1778_ = lean_box(v_res_1777_);
return v_r_1778_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidablePredConfigWF___aux__1(lean_object* v_00_u03b3_1779_){
_start:
{
lean_object* v___f_1780_; lean_object* v___x_1781_; uint8_t v___x_1782_; 
v___f_1780_ = lean_alloc_closure((void*)(lp_bounded_Bounded_instDecidablePredConfigWF___aux__1___lam__2___boxed), 2, 1);
lean_closure_set(v___f_1780_, 0, v_00_u03b3_1779_);
v___x_1781_ = lean_unsigned_to_nat(2u);
v___x_1782_ = l_Nat_decidableForallFin___redArg(v___x_1781_, v___f_1780_);
return v___x_1782_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidablePredConfigWF___aux__1___boxed(lean_object* v_00_u03b3_1783_){
_start:
{
uint8_t v_res_1784_; lean_object* v_r_1785_; 
v_res_1784_ = lp_bounded_Bounded_instDecidablePredConfigWF___aux__1(v_00_u03b3_1783_);
v_r_1785_ = lean_box(v_res_1784_);
return v_r_1785_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidablePredConfigWF(lean_object* v_00_u03b3_1786_){
_start:
{
uint8_t v___x_1787_; 
v___x_1787_ = lp_bounded_Bounded_instDecidablePredConfigWF___aux__1(v_00_u03b3_1786_);
return v___x_1787_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidablePredConfigWF___boxed(lean_object* v_00_u03b3_1788_){
_start:
{
uint8_t v_res_1789_; lean_object* v_r_1790_; 
v_res_1789_ = lp_bounded_Bounded_instDecidablePredConfigWF(v_00_u03b3_1788_);
v_r_1790_ = lean_box(v_res_1789_);
return v_r_1790_;
}
}
LEAN_EXPORT uint8_t lp_bounded_List_all___at___00Bounded_satisfied_spec__0(lean_object* v_f_1791_, lean_object* v_00_u03b3_1792_, lean_object* v_x_1793_){
_start:
{
if (lean_obj_tag(v_x_1793_) == 0)
{
uint8_t v___x_1794_; 
v___x_1794_ = 1;
return v___x_1794_;
}
else
{
lean_object* v_comp_1795_; lean_object* v_head_1796_; lean_object* v_tail_1797_; lean_object* v_deps_1798_; lean_object* v___x_1799_; uint8_t v___x_1800_; 
v_comp_1795_ = lean_ctor_get(v_f_1791_, 0);
v_head_1796_ = lean_ctor_get(v_x_1793_, 0);
v_tail_1797_ = lean_ctor_get(v_x_1793_, 1);
v_deps_1798_ = lean_ctor_get(v_comp_1795_, 0);
v___x_1799_ = lp_bounded_Bounded_KMap_get___redArg(v_deps_1798_, v_head_1796_);
v___x_1800_ = lean_unbox(v___x_1799_);
if (v___x_1800_ == 0)
{
lean_dec(v___x_1799_);
v_x_1793_ = v_tail_1797_;
goto _start;
}
else
{
lean_object* v___x_1802_; 
v___x_1802_ = lp_bounded_Bounded_providerOf(v_00_u03b3_1792_, v_head_1796_);
if (lean_obj_tag(v___x_1802_) == 0)
{
uint8_t v___x_1803_; 
lean_dec(v___x_1799_);
v___x_1803_ = 0;
return v___x_1803_;
}
else
{
uint8_t v___x_1804_; 
lean_dec_ref_known(v___x_1802_, 1);
v___x_1804_ = lean_unbox(v___x_1799_);
if (v___x_1804_ == 0)
{
uint8_t v___x_1805_; 
v___x_1805_ = lean_unbox(v___x_1799_);
lean_dec(v___x_1799_);
return v___x_1805_;
}
else
{
lean_dec(v___x_1799_);
v_x_1793_ = v_tail_1797_;
goto _start;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_List_all___at___00Bounded_satisfied_spec__0___boxed(lean_object* v_f_1807_, lean_object* v_00_u03b3_1808_, lean_object* v_x_1809_){
_start:
{
uint8_t v_res_1810_; lean_object* v_r_1811_; 
v_res_1810_ = lp_bounded_List_all___at___00Bounded_satisfied_spec__0(v_f_1807_, v_00_u03b3_1808_, v_x_1809_);
lean_dec(v_x_1809_);
lean_dec_ref(v_00_u03b3_1808_);
lean_dec_ref(v_f_1807_);
v_r_1811_ = lean_box(v_res_1810_);
return v_r_1811_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_satisfied(lean_object* v_00_u03b3_1812_, lean_object* v_f_1813_){
_start:
{
lean_object* v___x_1814_; uint8_t v___x_1815_; 
v___x_1814_ = lp_bounded_Bounded_allKeys;
v___x_1815_ = lp_bounded_List_all___at___00Bounded_satisfied_spec__0(v_f_1813_, v_00_u03b3_1812_, v___x_1814_);
return v___x_1815_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_satisfied___boxed(lean_object* v_00_u03b3_1816_, lean_object* v_f_1817_){
_start:
{
uint8_t v_res_1818_; lean_object* v_r_1819_; 
v_res_1818_ = lp_bounded_Bounded_satisfied(v_00_u03b3_1816_, v_f_1817_);
lean_dec_ref(v_f_1817_);
lean_dec_ref(v_00_u03b3_1816_);
v_r_1819_ = lean_box(v_res_1818_);
return v_r_1819_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_partialTarget___lam__0(lean_object* v_f_1820_, lean_object* v_00_u03b3_1821_, lean_object* v_k_1822_){
_start:
{
lean_object* v_comp_1823_; lean_object* v_deps_1824_; lean_object* v___x_1825_; uint8_t v___x_1826_; 
v_comp_1823_ = lean_ctor_get(v_f_1820_, 0);
v_deps_1824_ = lean_ctor_get(v_comp_1823_, 0);
v___x_1825_ = lp_bounded_Bounded_KMap_get___redArg(v_deps_1824_, v_k_1822_);
v___x_1826_ = lean_unbox(v___x_1825_);
lean_dec(v___x_1825_);
if (v___x_1826_ == 0)
{
lean_object* v___x_1827_; 
v___x_1827_ = lean_box(0);
return v___x_1827_;
}
else
{
lean_object* v___x_1828_; 
v___x_1828_ = lp_bounded_Bounded_providerOf(v_00_u03b3_1821_, v_k_1822_);
return v___x_1828_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_partialTarget___lam__0___boxed(lean_object* v_f_1829_, lean_object* v_00_u03b3_1830_, lean_object* v_k_1831_){
_start:
{
lean_object* v_res_1832_; 
v_res_1832_ = lp_bounded_Bounded_partialTarget___lam__0(v_f_1829_, v_00_u03b3_1830_, v_k_1831_);
lean_dec(v_k_1831_);
lean_dec_ref(v_00_u03b3_1830_);
lean_dec_ref(v_f_1829_);
return v_res_1832_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_partialTarget(lean_object* v_00_u03b3_1833_, lean_object* v_f_1834_){
_start:
{
lean_object* v___f_1835_; lean_object* v___x_1836_; 
v___f_1835_ = lean_alloc_closure((void*)(lp_bounded_Bounded_partialTarget___lam__0___boxed), 3, 2);
lean_closure_set(v___f_1835_, 0, v_f_1834_);
lean_closure_set(v___f_1835_, 1, v_00_u03b3_1833_);
v___x_1836_ = lp_bounded_Bounded_KMap_ofFun___redArg(v___f_1835_);
return v___x_1836_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_targetOf(lean_object* v_00_u03b3_1837_, lean_object* v_n_1838_){
_start:
{
lean_object* v___x_1839_; 
v___x_1839_ = lp_bounded_Bounded_SMap_get___redArg(v_00_u03b3_1837_, v_n_1838_);
if (lean_obj_tag(v___x_1839_) == 0)
{
lean_object* v___x_1840_; 
lean_dec_ref(v_00_u03b3_1837_);
v___x_1840_ = lean_box(0);
return v___x_1840_;
}
else
{
lean_object* v_val_1841_; lean_object* v___x_1843_; uint8_t v_isShared_1844_; uint8_t v_isSharedCheck_1853_; 
v_val_1841_ = lean_ctor_get(v___x_1839_, 0);
v_isSharedCheck_1853_ = !lean_is_exclusive(v___x_1839_);
if (v_isSharedCheck_1853_ == 0)
{
v___x_1843_ = v___x_1839_;
v_isShared_1844_ = v_isSharedCheck_1853_;
goto v_resetjp_1842_;
}
else
{
lean_inc(v_val_1841_);
lean_dec(v___x_1839_);
v___x_1843_ = lean_box(0);
v_isShared_1844_ = v_isSharedCheck_1853_;
goto v_resetjp_1842_;
}
v_resetjp_1842_:
{
uint8_t v_retired_1845_; 
v_retired_1845_ = lean_ctor_get_uint8(v_val_1841_, sizeof(void*)*4);
if (v_retired_1845_ == 0)
{
uint8_t v___x_1846_; 
v___x_1846_ = lp_bounded_Bounded_satisfied(v_00_u03b3_1837_, v_val_1841_);
if (v___x_1846_ == 0)
{
lean_object* v___x_1847_; 
lean_del_object(v___x_1843_);
lean_dec(v_val_1841_);
lean_dec_ref(v_00_u03b3_1837_);
v___x_1847_ = lean_box(0);
return v___x_1847_;
}
else
{
lean_object* v___x_1848_; lean_object* v___x_1850_; 
v___x_1848_ = lp_bounded_Bounded_partialTarget(v_00_u03b3_1837_, v_val_1841_);
if (v_isShared_1844_ == 0)
{
lean_ctor_set(v___x_1843_, 0, v___x_1848_);
v___x_1850_ = v___x_1843_;
goto v_reusejp_1849_;
}
else
{
lean_object* v_reuseFailAlloc_1851_; 
v_reuseFailAlloc_1851_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1851_, 0, v___x_1848_);
v___x_1850_ = v_reuseFailAlloc_1851_;
goto v_reusejp_1849_;
}
v_reusejp_1849_:
{
return v___x_1850_;
}
}
}
else
{
lean_object* v___x_1852_; 
lean_del_object(v___x_1843_);
lean_dec(v_val_1841_);
lean_dec_ref(v_00_u03b3_1837_);
v___x_1852_ = lean_box(0);
return v___x_1852_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_targetOf___boxed(lean_object* v_00_u03b3_1854_, lean_object* v_n_1855_){
_start:
{
lean_object* v_res_1856_; 
v_res_1856_ = lp_bounded_Bounded_targetOf(v_00_u03b3_1854_, v_n_1855_);
lean_dec(v_n_1855_);
return v_res_1856_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Option_instBEq_beq___at___00Bounded_reliedUpon_spec__0(lean_object* v_x_1857_, lean_object* v_x_1858_){
_start:
{
if (lean_obj_tag(v_x_1857_) == 0)
{
if (lean_obj_tag(v_x_1858_) == 0)
{
uint8_t v___x_1859_; 
v___x_1859_ = 1;
return v___x_1859_;
}
else
{
uint8_t v___x_1860_; 
v___x_1860_ = 0;
return v___x_1860_;
}
}
else
{
if (lean_obj_tag(v_x_1858_) == 0)
{
uint8_t v___x_1861_; 
v___x_1861_ = 0;
return v___x_1861_;
}
else
{
lean_object* v_val_1862_; lean_object* v_val_1863_; uint8_t v___x_1864_; 
v_val_1862_ = lean_ctor_get(v_x_1857_, 0);
v_val_1863_ = lean_ctor_get(v_x_1858_, 0);
v___x_1864_ = lean_nat_dec_eq(v_val_1862_, v_val_1863_);
return v___x_1864_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Option_instBEq_beq___at___00Bounded_reliedUpon_spec__0___boxed(lean_object* v_x_1865_, lean_object* v_x_1866_){
_start:
{
uint8_t v_res_1867_; lean_object* v_r_1868_; 
v_res_1867_ = lp_bounded_Option_instBEq_beq___at___00Bounded_reliedUpon_spec__0(v_x_1865_, v_x_1866_);
lean_dec(v_x_1866_);
lean_dec(v_x_1865_);
v_r_1868_ = lean_box(v_res_1867_);
return v_r_1868_;
}
}
LEAN_EXPORT uint8_t lp_bounded_List_any___at___00Bounded_reliedUpon_spec__1(lean_object* v_val_1869_, lean_object* v_n_1870_, lean_object* v_x_1871_){
_start:
{
if (lean_obj_tag(v_x_1871_) == 0)
{
uint8_t v___x_1872_; 
lean_dec(v_n_1870_);
v___x_1872_ = 0;
return v___x_1872_;
}
else
{
lean_object* v_head_1873_; lean_object* v_tail_1874_; lean_object* v___x_1875_; lean_object* v___x_1876_; uint8_t v___x_1877_; 
v_head_1873_ = lean_ctor_get(v_x_1871_, 0);
v_tail_1874_ = lean_ctor_get(v_x_1871_, 1);
v___x_1875_ = lp_bounded_Bounded_KMap_get___redArg(v_val_1869_, v_head_1873_);
lean_inc(v_n_1870_);
v___x_1876_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_1876_, 0, v_n_1870_);
v___x_1877_ = lp_bounded_Option_instBEq_beq___at___00Bounded_reliedUpon_spec__0(v___x_1875_, v___x_1876_);
lean_dec_ref_known(v___x_1876_, 1);
lean_dec(v___x_1875_);
if (v___x_1877_ == 0)
{
v_x_1871_ = v_tail_1874_;
goto _start;
}
else
{
lean_dec(v_n_1870_);
return v___x_1877_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_List_any___at___00Bounded_reliedUpon_spec__1___boxed(lean_object* v_val_1879_, lean_object* v_n_1880_, lean_object* v_x_1881_){
_start:
{
uint8_t v_res_1882_; lean_object* v_r_1883_; 
v_res_1882_ = lp_bounded_List_any___at___00Bounded_reliedUpon_spec__1(v_val_1879_, v_n_1880_, v_x_1881_);
lean_dec(v_x_1881_);
lean_dec_ref(v_val_1879_);
v_r_1883_ = lean_box(v_res_1882_);
return v_r_1883_;
}
}
LEAN_EXPORT uint8_t lp_bounded_List_any___at___00Bounded_reliedUpon_spec__2(lean_object* v_n_1884_, lean_object* v_00_u03b3_1885_, lean_object* v_x_1886_){
_start:
{
if (lean_obj_tag(v_x_1886_) == 0)
{
uint8_t v___x_1887_; 
lean_dec(v_n_1884_);
v___x_1887_ = 0;
return v___x_1887_;
}
else
{
lean_object* v_head_1888_; lean_object* v_tail_1889_; uint8_t v___y_1891_; uint8_t v___x_1893_; 
v_head_1888_ = lean_ctor_get(v_x_1886_, 0);
v_tail_1889_ = lean_ctor_get(v_x_1886_, 1);
v___x_1893_ = lean_nat_dec_eq(v_head_1888_, v_n_1884_);
if (v___x_1893_ == 0)
{
lean_object* v___x_1894_; 
v___x_1894_ = lp_bounded_Bounded_SMap_get___redArg(v_00_u03b3_1885_, v_head_1888_);
if (lean_obj_tag(v___x_1894_) == 0)
{
v___y_1891_ = v___x_1893_;
goto v___jp_1890_;
}
else
{
lean_object* v_val_1895_; lean_object* v_st_1896_; lean_object* v___x_1897_; 
v_val_1895_ = lean_ctor_get(v___x_1894_, 0);
lean_inc(v_val_1895_);
lean_dec_ref_known(v___x_1894_, 1);
v_st_1896_ = lean_ctor_get(v_val_1895_, 3);
lean_inc_ref(v_st_1896_);
lean_dec(v_val_1895_);
v___x_1897_ = lp_bounded_Bounded_LState_viewOf(v_st_1896_);
lean_dec_ref(v_st_1896_);
if (lean_obj_tag(v___x_1897_) == 0)
{
v___y_1891_ = v___x_1893_;
goto v___jp_1890_;
}
else
{
lean_object* v_val_1898_; lean_object* v___x_1899_; uint8_t v___x_1900_; 
v_val_1898_ = lean_ctor_get(v___x_1897_, 0);
lean_inc(v_val_1898_);
lean_dec_ref_known(v___x_1897_, 1);
v___x_1899_ = lp_bounded_Bounded_allKeys;
lean_inc(v_n_1884_);
v___x_1900_ = lp_bounded_List_any___at___00Bounded_reliedUpon_spec__1(v_val_1898_, v_n_1884_, v___x_1899_);
lean_dec(v_val_1898_);
v___y_1891_ = v___x_1900_;
goto v___jp_1890_;
}
}
}
else
{
v_x_1886_ = v_tail_1889_;
goto _start;
}
v___jp_1890_:
{
if (v___y_1891_ == 0)
{
v_x_1886_ = v_tail_1889_;
goto _start;
}
else
{
lean_dec(v_n_1884_);
return v___y_1891_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_List_any___at___00Bounded_reliedUpon_spec__2___boxed(lean_object* v_n_1902_, lean_object* v_00_u03b3_1903_, lean_object* v_x_1904_){
_start:
{
uint8_t v_res_1905_; lean_object* v_r_1906_; 
v_res_1905_ = lp_bounded_List_any___at___00Bounded_reliedUpon_spec__2(v_n_1902_, v_00_u03b3_1903_, v_x_1904_);
lean_dec(v_x_1904_);
lean_dec_ref(v_00_u03b3_1903_);
v_r_1906_ = lean_box(v_res_1905_);
return v_r_1906_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_reliedUpon(lean_object* v_00_u03b3_1907_, lean_object* v_n_1908_){
_start:
{
lean_object* v___x_1909_; uint8_t v___x_1910_; 
v___x_1909_ = lp_bounded_Bounded_allSlots;
v___x_1910_ = lp_bounded_List_any___at___00Bounded_reliedUpon_spec__2(v_n_1908_, v_00_u03b3_1907_, v___x_1909_);
return v___x_1910_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_reliedUpon___boxed(lean_object* v_00_u03b3_1911_, lean_object* v_n_1912_){
_start:
{
uint8_t v_res_1913_; lean_object* v_r_1914_; 
v_res_1913_ = lp_bounded_Bounded_reliedUpon(v_00_u03b3_1911_, v_n_1912_);
lean_dec_ref(v_00_u03b3_1911_);
v_r_1914_ = lean_box(v_res_1913_);
return v_r_1914_;
}
}
LEAN_EXPORT uint8_t lp_bounded_List_any___at___00Bounded_hasChild_spec__0(lean_object* v_00_u03b3_1915_, lean_object* v_n_1916_, lean_object* v_x_1917_){
_start:
{
if (lean_obj_tag(v_x_1917_) == 0)
{
uint8_t v___x_1918_; 
lean_dec(v_n_1916_);
v___x_1918_ = 0;
return v___x_1918_;
}
else
{
lean_object* v_head_1919_; lean_object* v_tail_1920_; lean_object* v___x_1921_; 
v_head_1919_ = lean_ctor_get(v_x_1917_, 0);
v_tail_1920_ = lean_ctor_get(v_x_1917_, 1);
v___x_1921_ = lp_bounded_Bounded_SMap_get___redArg(v_00_u03b3_1915_, v_head_1919_);
if (lean_obj_tag(v___x_1921_) == 0)
{
v_x_1917_ = v_tail_1920_;
goto _start;
}
else
{
lean_object* v_val_1923_; lean_object* v___x_1925_; uint8_t v_isShared_1926_; uint8_t v_isSharedCheck_1933_; 
v_val_1923_ = lean_ctor_get(v___x_1921_, 0);
v_isSharedCheck_1933_ = !lean_is_exclusive(v___x_1921_);
if (v_isSharedCheck_1933_ == 0)
{
v___x_1925_ = v___x_1921_;
v_isShared_1926_ = v_isSharedCheck_1933_;
goto v_resetjp_1924_;
}
else
{
lean_inc(v_val_1923_);
lean_dec(v___x_1921_);
v___x_1925_ = lean_box(0);
v_isShared_1926_ = v_isSharedCheck_1933_;
goto v_resetjp_1924_;
}
v_resetjp_1924_:
{
lean_object* v_parent_1927_; lean_object* v___x_1929_; 
v_parent_1927_ = lean_ctor_get(v_val_1923_, 1);
lean_inc(v_parent_1927_);
lean_dec(v_val_1923_);
lean_inc(v_n_1916_);
if (v_isShared_1926_ == 0)
{
lean_ctor_set(v___x_1925_, 0, v_n_1916_);
v___x_1929_ = v___x_1925_;
goto v_reusejp_1928_;
}
else
{
lean_object* v_reuseFailAlloc_1932_; 
v_reuseFailAlloc_1932_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1932_, 0, v_n_1916_);
v___x_1929_ = v_reuseFailAlloc_1932_;
goto v_reusejp_1928_;
}
v_reusejp_1928_:
{
uint8_t v___x_1930_; 
v___x_1930_ = lp_bounded_Option_instBEq_beq___at___00Bounded_reliedUpon_spec__0(v_parent_1927_, v___x_1929_);
lean_dec_ref(v___x_1929_);
lean_dec(v_parent_1927_);
if (v___x_1930_ == 0)
{
v_x_1917_ = v_tail_1920_;
goto _start;
}
else
{
lean_dec(v_n_1916_);
return v___x_1930_;
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_List_any___at___00Bounded_hasChild_spec__0___boxed(lean_object* v_00_u03b3_1934_, lean_object* v_n_1935_, lean_object* v_x_1936_){
_start:
{
uint8_t v_res_1937_; lean_object* v_r_1938_; 
v_res_1937_ = lp_bounded_List_any___at___00Bounded_hasChild_spec__0(v_00_u03b3_1934_, v_n_1935_, v_x_1936_);
lean_dec(v_x_1936_);
lean_dec_ref(v_00_u03b3_1934_);
v_r_1938_ = lean_box(v_res_1937_);
return v_r_1938_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_hasChild(lean_object* v_00_u03b3_1939_, lean_object* v_n_1940_){
_start:
{
lean_object* v___x_1941_; uint8_t v___x_1942_; 
v___x_1941_ = lp_bounded_Bounded_allSlots;
v___x_1942_ = lp_bounded_List_any___at___00Bounded_hasChild_spec__0(v_00_u03b3_1939_, v_n_1940_, v___x_1941_);
return v___x_1942_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_hasChild___boxed(lean_object* v_00_u03b3_1943_, lean_object* v_n_1944_){
_start:
{
uint8_t v_res_1945_; lean_object* v_r_1946_; 
v_res_1945_ = lp_bounded_Bounded_hasChild(v_00_u03b3_1943_, v_n_1944_);
lean_dec_ref(v_00_u03b3_1943_);
v_r_1946_ = lean_box(v_res_1945_);
return v_r_1946_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_quietAt___lam__0(lean_object* v_a_1947_, lean_object* v_b_1948_){
_start:
{
lean_object* v___x_1949_; uint8_t v___x_1950_; 
v___x_1949_ = ((lean_object*)(lp_bounded_Bounded_instDecidableEqFiber_decEq___closed__0));
v___x_1950_ = l_Option_instDecidableEq___redArg(v___x_1949_, v_a_1947_, v_b_1948_);
return v___x_1950_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_quietAt___lam__0___boxed(lean_object* v_a_1951_, lean_object* v_b_1952_){
_start:
{
uint8_t v_res_1953_; lean_object* v_r_1954_; 
v_res_1953_ = lp_bounded_Bounded_quietAt___lam__0(v_a_1951_, v_b_1952_);
v_r_1954_ = lean_box(v_res_1953_);
return v_r_1954_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_quietAt(lean_object* v_00_u03b3_1956_, lean_object* v_n_1957_){
_start:
{
lean_object* v___x_1958_; 
v___x_1958_ = lp_bounded_Bounded_SMap_get___redArg(v_00_u03b3_1956_, v_n_1957_);
if (lean_obj_tag(v___x_1958_) == 0)
{
uint8_t v___x_1959_; 
lean_dec_ref(v_00_u03b3_1956_);
v___x_1959_ = 1;
return v___x_1959_;
}
else
{
lean_object* v_val_1960_; lean_object* v_st_1961_; 
v_val_1960_ = lean_ctor_get(v___x_1958_, 0);
lean_inc(v_val_1960_);
lean_dec_ref_known(v___x_1958_, 1);
v_st_1961_ = lean_ctor_get(v_val_1960_, 3);
lean_inc_ref(v_st_1961_);
lean_dec(v_val_1960_);
switch(lean_obj_tag(v_st_1961_))
{
case 0:
{
uint8_t v_o_1962_; uint8_t v___x_1963_; uint8_t v___x_1964_; 
v_o_1962_ = lean_ctor_get_uint8(v_st_1961_, 0);
lean_dec_ref_known(v_st_1961_, 0);
v___x_1963_ = 1;
v___x_1964_ = lp_bounded_Bounded_instDecidableEqOutcome(v_o_1962_, v___x_1963_);
if (v___x_1964_ == 0)
{
lean_object* v___x_1965_; 
v___x_1965_ = lp_bounded_Bounded_targetOf(v_00_u03b3_1956_, v_n_1957_);
if (lean_obj_tag(v___x_1965_) == 0)
{
uint8_t v___x_1966_; 
v___x_1966_ = 1;
return v___x_1966_;
}
else
{
lean_dec_ref_known(v___x_1965_, 1);
return v___x_1964_;
}
}
else
{
lean_dec_ref(v_00_u03b3_1956_);
return v___x_1964_;
}
}
case 2:
{
lean_object* v_view_1967_; lean_object* v___x_1968_; 
v_view_1967_ = lean_ctor_get(v_st_1961_, 1);
lean_inc_ref(v_view_1967_);
lean_dec_ref_known(v_st_1961_, 2);
v___x_1968_ = lp_bounded_Bounded_targetOf(v_00_u03b3_1956_, v_n_1957_);
if (lean_obj_tag(v___x_1968_) == 0)
{
uint8_t v___x_1969_; 
lean_dec_ref(v_view_1967_);
v___x_1969_ = 0;
return v___x_1969_;
}
else
{
lean_object* v_val_1970_; lean_object* v___f_1971_; uint8_t v___x_1972_; 
v_val_1970_ = lean_ctor_get(v___x_1968_, 0);
lean_inc(v_val_1970_);
lean_dec_ref_known(v___x_1968_, 1);
v___f_1971_ = ((lean_object*)(lp_bounded_Bounded_quietAt___closed__0));
v___x_1972_ = lp_bounded_Bounded_instDecidableEqKMap_decEq___redArg(v___f_1971_, v_val_1970_, v_view_1967_);
return v___x_1972_;
}
}
default: 
{
uint8_t v___x_1973_; 
lean_dec_ref(v_st_1961_);
lean_dec_ref(v_00_u03b3_1956_);
v___x_1973_ = 0;
return v___x_1973_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_quietAt___boxed(lean_object* v_00_u03b3_1974_, lean_object* v_n_1975_){
_start:
{
uint8_t v_res_1976_; lean_object* v_r_1977_; 
v_res_1976_ = lp_bounded_Bounded_quietAt(v_00_u03b3_1974_, v_n_1975_);
lean_dec(v_n_1975_);
v_r_1977_ = lean_box(v_res_1976_);
return v_r_1977_;
}
}
LEAN_EXPORT uint8_t lp_bounded_List_all___at___00Bounded_quiet_spec__0(lean_object* v_00_u03b3_1978_, lean_object* v_x_1979_){
_start:
{
if (lean_obj_tag(v_x_1979_) == 0)
{
uint8_t v___x_1980_; 
lean_dec_ref(v_00_u03b3_1978_);
v___x_1980_ = 1;
return v___x_1980_;
}
else
{
lean_object* v_head_1981_; lean_object* v_tail_1982_; uint8_t v___x_1983_; 
v_head_1981_ = lean_ctor_get(v_x_1979_, 0);
v_tail_1982_ = lean_ctor_get(v_x_1979_, 1);
lean_inc_ref(v_00_u03b3_1978_);
v___x_1983_ = lp_bounded_Bounded_quietAt(v_00_u03b3_1978_, v_head_1981_);
if (v___x_1983_ == 0)
{
lean_dec_ref(v_00_u03b3_1978_);
return v___x_1983_;
}
else
{
v_x_1979_ = v_tail_1982_;
goto _start;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_List_all___at___00Bounded_quiet_spec__0___boxed(lean_object* v_00_u03b3_1985_, lean_object* v_x_1986_){
_start:
{
uint8_t v_res_1987_; lean_object* v_r_1988_; 
v_res_1987_ = lp_bounded_List_all___at___00Bounded_quiet_spec__0(v_00_u03b3_1985_, v_x_1986_);
lean_dec(v_x_1986_);
v_r_1988_ = lean_box(v_res_1987_);
return v_r_1988_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_quiet(lean_object* v_00_u03b3_1989_){
_start:
{
lean_object* v___x_1990_; uint8_t v___x_1991_; 
v___x_1990_ = lp_bounded_Bounded_allSlots;
v___x_1991_ = lp_bounded_List_all___at___00Bounded_quiet_spec__0(v_00_u03b3_1989_, v___x_1990_);
return v___x_1991_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_quiet___boxed(lean_object* v_00_u03b3_1992_){
_start:
{
uint8_t v_res_1993_; lean_object* v_r_1994_; 
v_res_1993_ = lp_bounded_Bounded_quiet(v_00_u03b3_1992_);
v_r_1994_ = lean_box(v_res_1993_);
return v_r_1994_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadRes_ctorIdx(lean_object* v_x_1995_){
_start:
{
switch(lean_obj_tag(v_x_1995_))
{
case 0:
{
lean_object* v___x_1996_; 
v___x_1996_ = lean_unsigned_to_nat(0u);
return v___x_1996_;
}
case 1:
{
lean_object* v___x_1997_; 
v___x_1997_ = lean_unsigned_to_nat(1u);
return v___x_1997_;
}
default: 
{
lean_object* v___x_1998_; 
v___x_1998_ = lean_unsigned_to_nat(2u);
return v___x_1998_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadRes_ctorIdx___boxed(lean_object* v_x_1999_){
_start:
{
lean_object* v_res_2000_; 
v_res_2000_ = lp_bounded_Bounded_ReadRes_ctorIdx(v_x_1999_);
lean_dec(v_x_1999_);
return v_res_2000_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadRes_ctorElim___redArg(lean_object* v_t_2001_, lean_object* v_k_2002_){
_start:
{
if (lean_obj_tag(v_t_2001_) == 0)
{
lean_object* v_v_2003_; uint8_t v_ancestor_2004_; lean_object* v___x_2005_; lean_object* v___x_2006_; 
v_v_2003_ = lean_ctor_get(v_t_2001_, 0);
lean_inc(v_v_2003_);
v_ancestor_2004_ = lean_ctor_get_uint8(v_t_2001_, sizeof(void*)*1);
lean_dec_ref_known(v_t_2001_, 1);
v___x_2005_ = lean_box(v_ancestor_2004_);
v___x_2006_ = lean_apply_2(v_k_2002_, v_v_2003_, v___x_2005_);
return v___x_2006_;
}
else
{
lean_dec(v_t_2001_);
return v_k_2002_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadRes_ctorElim(lean_object* v_motive_2007_, lean_object* v_ctorIdx_2008_, lean_object* v_t_2009_, lean_object* v_h_2010_, lean_object* v_k_2011_){
_start:
{
lean_object* v___x_2012_; 
v___x_2012_ = lp_bounded_Bounded_ReadRes_ctorElim___redArg(v_t_2009_, v_k_2011_);
return v___x_2012_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadRes_ctorElim___boxed(lean_object* v_motive_2013_, lean_object* v_ctorIdx_2014_, lean_object* v_t_2015_, lean_object* v_h_2016_, lean_object* v_k_2017_){
_start:
{
lean_object* v_res_2018_; 
v_res_2018_ = lp_bounded_Bounded_ReadRes_ctorElim(v_motive_2013_, v_ctorIdx_2014_, v_t_2015_, v_h_2016_, v_k_2017_);
lean_dec(v_ctorIdx_2014_);
return v_res_2018_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadRes_ok_elim___redArg(lean_object* v_t_2019_, lean_object* v_ok_2020_){
_start:
{
lean_object* v___x_2021_; 
v___x_2021_ = lp_bounded_Bounded_ReadRes_ctorElim___redArg(v_t_2019_, v_ok_2020_);
return v___x_2021_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadRes_ok_elim(lean_object* v_motive_2022_, lean_object* v_t_2023_, lean_object* v_h_2024_, lean_object* v_ok_2025_){
_start:
{
lean_object* v___x_2026_; 
v___x_2026_ = lp_bounded_Bounded_ReadRes_ctorElim___redArg(v_t_2023_, v_ok_2025_);
return v___x_2026_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadRes_ia_elim___redArg(lean_object* v_t_2027_, lean_object* v_ia_2028_){
_start:
{
lean_object* v___x_2029_; 
v___x_2029_ = lp_bounded_Bounded_ReadRes_ctorElim___redArg(v_t_2027_, v_ia_2028_);
return v___x_2029_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadRes_ia_elim(lean_object* v_motive_2030_, lean_object* v_t_2031_, lean_object* v_h_2032_, lean_object* v_ia_2033_){
_start:
{
lean_object* v___x_2034_; 
v___x_2034_ = lp_bounded_Bounded_ReadRes_ctorElim___redArg(v_t_2031_, v_ia_2033_);
return v___x_2034_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadRes_ud_elim___redArg(lean_object* v_t_2035_, lean_object* v_ud_2036_){
_start:
{
lean_object* v___x_2037_; 
v___x_2037_ = lp_bounded_Bounded_ReadRes_ctorElim___redArg(v_t_2035_, v_ud_2036_);
return v___x_2037_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadRes_ud_elim(lean_object* v_motive_2038_, lean_object* v_t_2039_, lean_object* v_h_2040_, lean_object* v_ud_2041_){
_start:
{
lean_object* v___x_2042_; 
v___x_2042_ = lp_bounded_Bounded_ReadRes_ctorElim___redArg(v_t_2039_, v_ud_2041_);
return v___x_2042_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqReadRes_decEq(lean_object* v_x_2043_, lean_object* v_x_2044_){
_start:
{
switch(lean_obj_tag(v_x_2043_))
{
case 0:
{
lean_object* v_v_2045_; uint8_t v_ancestor_2046_; uint8_t v___x_2047_; 
v_v_2045_ = lean_ctor_get(v_x_2043_, 0);
v_ancestor_2046_ = lean_ctor_get_uint8(v_x_2043_, sizeof(void*)*1);
v___x_2047_ = 0;
if (lean_obj_tag(v_x_2044_) == 0)
{
lean_object* v_v_2048_; uint8_t v_ancestor_2049_; uint8_t v___x_2050_; 
v_v_2048_ = lean_ctor_get(v_x_2044_, 0);
v_ancestor_2049_ = lean_ctor_get_uint8(v_x_2044_, sizeof(void*)*1);
v___x_2050_ = lean_nat_dec_eq(v_v_2045_, v_v_2048_);
if (v___x_2050_ == 0)
{
return v___x_2047_;
}
else
{
if (v_ancestor_2046_ == 0)
{
if (v_ancestor_2049_ == 0)
{
return v___x_2050_;
}
else
{
return v___x_2047_;
}
}
else
{
if (v_ancestor_2049_ == 0)
{
return v___x_2047_;
}
else
{
return v_ancestor_2049_;
}
}
}
}
else
{
return v___x_2047_;
}
}
case 1:
{
if (lean_obj_tag(v_x_2044_) == 1)
{
uint8_t v___x_2051_; 
v___x_2051_ = 1;
return v___x_2051_;
}
else
{
uint8_t v___x_2052_; 
v___x_2052_ = 0;
return v___x_2052_;
}
}
default: 
{
if (lean_obj_tag(v_x_2044_) == 2)
{
uint8_t v___x_2053_; 
v___x_2053_ = 1;
return v___x_2053_;
}
else
{
uint8_t v___x_2054_; 
v___x_2054_ = 0;
return v___x_2054_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqReadRes_decEq___boxed(lean_object* v_x_2055_, lean_object* v_x_2056_){
_start:
{
uint8_t v_res_2057_; lean_object* v_r_2058_; 
v_res_2057_ = lp_bounded_Bounded_instDecidableEqReadRes_decEq(v_x_2055_, v_x_2056_);
lean_dec(v_x_2056_);
lean_dec(v_x_2055_);
v_r_2058_ = lean_box(v_res_2057_);
return v_r_2058_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqReadRes(lean_object* v_x_2059_, lean_object* v_x_2060_){
_start:
{
uint8_t v___x_2061_; 
v___x_2061_ = lp_bounded_Bounded_instDecidableEqReadRes_decEq(v_x_2059_, v_x_2060_);
return v___x_2061_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqReadRes___boxed(lean_object* v_x_2062_, lean_object* v_x_2063_){
_start:
{
uint8_t v_res_2064_; lean_object* v_r_2065_; 
v_res_2064_ = lp_bounded_Bounded_instDecidableEqReadRes(v_x_2062_, v_x_2063_);
lean_dec(v_x_2063_);
lean_dec(v_x_2062_);
v_r_2065_ = lean_box(v_res_2064_);
return v_r_2065_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprReadRes_repr(lean_object* v_x_2078_, lean_object* v_prec_2079_){
_start:
{
lean_object* v___y_2081_; lean_object* v___y_2088_; 
switch(lean_obj_tag(v_x_2078_))
{
case 0:
{
lean_object* v_v_2094_; uint8_t v_ancestor_2095_; lean_object* v___x_2097_; uint8_t v_isShared_2098_; uint8_t v_isSharedCheck_2119_; 
v_v_2094_ = lean_ctor_get(v_x_2078_, 0);
v_ancestor_2095_ = lean_ctor_get_uint8(v_x_2078_, sizeof(void*)*1);
v_isSharedCheck_2119_ = !lean_is_exclusive(v_x_2078_);
if (v_isSharedCheck_2119_ == 0)
{
v___x_2097_ = v_x_2078_;
v_isShared_2098_ = v_isSharedCheck_2119_;
goto v_resetjp_2096_;
}
else
{
lean_inc(v_v_2094_);
lean_dec(v_x_2078_);
v___x_2097_ = lean_box(0);
v_isShared_2098_ = v_isSharedCheck_2119_;
goto v_resetjp_2096_;
}
v_resetjp_2096_:
{
lean_object* v___y_2100_; lean_object* v___x_2115_; uint8_t v___x_2116_; 
v___x_2115_ = lean_unsigned_to_nat(1024u);
v___x_2116_ = lean_nat_dec_le(v___x_2115_, v_prec_2079_);
if (v___x_2116_ == 0)
{
lean_object* v___x_2117_; 
v___x_2117_ = lean_obj_once(&lp_bounded_Bounded_instReprStep_repr___closed__7, &lp_bounded_Bounded_instReprStep_repr___closed__7_once, _init_lp_bounded_Bounded_instReprStep_repr___closed__7);
v___y_2100_ = v___x_2117_;
goto v___jp_2099_;
}
else
{
lean_object* v___x_2118_; 
v___x_2118_ = lean_obj_once(&lp_bounded_Bounded_instReprStep_repr___closed__8, &lp_bounded_Bounded_instReprStep_repr___closed__8_once, _init_lp_bounded_Bounded_instReprStep_repr___closed__8);
v___y_2100_ = v___x_2118_;
goto v___jp_2099_;
}
v___jp_2099_:
{
lean_object* v___x_2101_; lean_object* v___x_2102_; lean_object* v___x_2103_; lean_object* v___x_2104_; lean_object* v___x_2105_; lean_object* v___x_2106_; lean_object* v___x_2107_; lean_object* v___x_2108_; lean_object* v___x_2109_; uint8_t v___x_2110_; lean_object* v___x_2112_; 
v___x_2101_ = lean_box(1);
v___x_2102_ = ((lean_object*)(lp_bounded_Bounded_instReprReadRes_repr___closed__6));
v___x_2103_ = l_Nat_reprFast(v_v_2094_);
v___x_2104_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_2104_, 0, v___x_2103_);
v___x_2105_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2105_, 0, v___x_2102_);
lean_ctor_set(v___x_2105_, 1, v___x_2104_);
v___x_2106_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2106_, 0, v___x_2105_);
lean_ctor_set(v___x_2106_, 1, v___x_2101_);
v___x_2107_ = l_Bool_repr___redArg(v_ancestor_2095_);
v___x_2108_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2108_, 0, v___x_2106_);
lean_ctor_set(v___x_2108_, 1, v___x_2107_);
lean_inc(v___y_2100_);
v___x_2109_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_2109_, 0, v___y_2100_);
lean_ctor_set(v___x_2109_, 1, v___x_2108_);
v___x_2110_ = 0;
if (v_isShared_2098_ == 0)
{
lean_ctor_set_tag(v___x_2097_, 6);
lean_ctor_set(v___x_2097_, 0, v___x_2109_);
v___x_2112_ = v___x_2097_;
goto v_reusejp_2111_;
}
else
{
lean_object* v_reuseFailAlloc_2114_; 
v_reuseFailAlloc_2114_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v_reuseFailAlloc_2114_, 0, v___x_2109_);
v___x_2112_ = v_reuseFailAlloc_2114_;
goto v_reusejp_2111_;
}
v_reusejp_2111_:
{
lean_object* v___x_2113_; 
lean_ctor_set_uint8(v___x_2112_, sizeof(void*)*1, v___x_2110_);
v___x_2113_ = l_Repr_addAppParen(v___x_2112_, v_prec_2079_);
return v___x_2113_;
}
}
}
}
case 1:
{
lean_object* v___x_2120_; uint8_t v___x_2121_; 
v___x_2120_ = lean_unsigned_to_nat(1024u);
v___x_2121_ = lean_nat_dec_le(v___x_2120_, v_prec_2079_);
if (v___x_2121_ == 0)
{
lean_object* v___x_2122_; 
v___x_2122_ = lean_obj_once(&lp_bounded_Bounded_instReprStep_repr___closed__7, &lp_bounded_Bounded_instReprStep_repr___closed__7_once, _init_lp_bounded_Bounded_instReprStep_repr___closed__7);
v___y_2081_ = v___x_2122_;
goto v___jp_2080_;
}
else
{
lean_object* v___x_2123_; 
v___x_2123_ = lean_obj_once(&lp_bounded_Bounded_instReprStep_repr___closed__8, &lp_bounded_Bounded_instReprStep_repr___closed__8_once, _init_lp_bounded_Bounded_instReprStep_repr___closed__8);
v___y_2081_ = v___x_2123_;
goto v___jp_2080_;
}
}
default: 
{
lean_object* v___x_2124_; uint8_t v___x_2125_; 
v___x_2124_ = lean_unsigned_to_nat(1024u);
v___x_2125_ = lean_nat_dec_le(v___x_2124_, v_prec_2079_);
if (v___x_2125_ == 0)
{
lean_object* v___x_2126_; 
v___x_2126_ = lean_obj_once(&lp_bounded_Bounded_instReprStep_repr___closed__7, &lp_bounded_Bounded_instReprStep_repr___closed__7_once, _init_lp_bounded_Bounded_instReprStep_repr___closed__7);
v___y_2088_ = v___x_2126_;
goto v___jp_2087_;
}
else
{
lean_object* v___x_2127_; 
v___x_2127_ = lean_obj_once(&lp_bounded_Bounded_instReprStep_repr___closed__8, &lp_bounded_Bounded_instReprStep_repr___closed__8_once, _init_lp_bounded_Bounded_instReprStep_repr___closed__8);
v___y_2088_ = v___x_2127_;
goto v___jp_2087_;
}
}
}
v___jp_2080_:
{
lean_object* v___x_2082_; lean_object* v___x_2083_; uint8_t v___x_2084_; lean_object* v___x_2085_; lean_object* v___x_2086_; 
v___x_2082_ = ((lean_object*)(lp_bounded_Bounded_instReprReadRes_repr___closed__1));
lean_inc(v___y_2081_);
v___x_2083_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_2083_, 0, v___y_2081_);
lean_ctor_set(v___x_2083_, 1, v___x_2082_);
v___x_2084_ = 0;
v___x_2085_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_2085_, 0, v___x_2083_);
lean_ctor_set_uint8(v___x_2085_, sizeof(void*)*1, v___x_2084_);
v___x_2086_ = l_Repr_addAppParen(v___x_2085_, v_prec_2079_);
return v___x_2086_;
}
v___jp_2087_:
{
lean_object* v___x_2089_; lean_object* v___x_2090_; uint8_t v___x_2091_; lean_object* v___x_2092_; lean_object* v___x_2093_; 
v___x_2089_ = ((lean_object*)(lp_bounded_Bounded_instReprReadRes_repr___closed__3));
lean_inc(v___y_2088_);
v___x_2090_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_2090_, 0, v___y_2088_);
lean_ctor_set(v___x_2090_, 1, v___x_2089_);
v___x_2091_ = 0;
v___x_2092_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_2092_, 0, v___x_2090_);
lean_ctor_set_uint8(v___x_2092_, sizeof(void*)*1, v___x_2091_);
v___x_2093_ = l_Repr_addAppParen(v___x_2092_, v_prec_2079_);
return v___x_2093_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprReadRes_repr___boxed(lean_object* v_x_2128_, lean_object* v_prec_2129_){
_start:
{
lean_object* v_res_2130_; 
v_res_2130_ = lp_bounded_Bounded_instReprReadRes_repr(v_x_2128_, v_prec_2129_);
lean_dec(v_prec_2129_);
return v_res_2130_;
}
}
LEAN_EXPORT uint64_t lp_bounded_Bounded_instHashableReadRes_hash(lean_object* v_x_2133_){
_start:
{
switch(lean_obj_tag(v_x_2133_))
{
case 0:
{
lean_object* v_v_2134_; uint8_t v_ancestor_2135_; uint64_t v___x_2136_; uint64_t v___x_2137_; uint64_t v___x_2138_; 
v_v_2134_ = lean_ctor_get(v_x_2133_, 0);
v_ancestor_2135_ = lean_ctor_get_uint8(v_x_2133_, sizeof(void*)*1);
v___x_2136_ = 0ULL;
v___x_2137_ = lean_uint64_of_nat(v_v_2134_);
v___x_2138_ = lean_uint64_mix_hash(v___x_2136_, v___x_2137_);
if (v_ancestor_2135_ == 0)
{
uint64_t v___x_2139_; uint64_t v___x_2140_; 
v___x_2139_ = 13ULL;
v___x_2140_ = lean_uint64_mix_hash(v___x_2138_, v___x_2139_);
return v___x_2140_;
}
else
{
uint64_t v___x_2141_; uint64_t v___x_2142_; 
v___x_2141_ = 11ULL;
v___x_2142_ = lean_uint64_mix_hash(v___x_2138_, v___x_2141_);
return v___x_2142_;
}
}
case 1:
{
uint64_t v___x_2143_; 
v___x_2143_ = 1ULL;
return v___x_2143_;
}
default: 
{
uint64_t v___x_2144_; 
v___x_2144_ = 2ULL;
return v___x_2144_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instHashableReadRes_hash___boxed(lean_object* v_x_2145_){
_start:
{
uint64_t v_res_2146_; lean_object* v_r_2147_; 
v_res_2146_ = lp_bounded_Bounded_instHashableReadRes_hash(v_x_2145_);
lean_dec(v_x_2145_);
v_r_2147_ = lean_box_uint64(v_res_2146_);
return v_r_2147_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_readC(lean_object* v_00_u03b3_2150_, lean_object* v_x_2151_, lean_object* v_x_2152_, lean_object* v_x_2153_, uint8_t v_x_2154_){
_start:
{
lean_object* v_zero_2155_; uint8_t v_isZero_2156_; 
v_zero_2155_ = lean_unsigned_to_nat(0u);
v_isZero_2156_ = lean_nat_dec_eq(v_x_2151_, v_zero_2155_);
if (v_isZero_2156_ == 1)
{
lean_object* v___x_2157_; 
v___x_2157_ = lean_box(2);
return v___x_2157_;
}
else
{
lean_object* v___x_2158_; 
v___x_2158_ = lp_bounded_Bounded_SMap_get___redArg(v_00_u03b3_2150_, v_x_2152_);
if (lean_obj_tag(v___x_2158_) == 0)
{
lean_object* v___x_2159_; 
v___x_2159_ = lean_box(2);
return v___x_2159_;
}
else
{
lean_object* v_val_2160_; lean_object* v_comp_2161_; lean_object* v_parent_2162_; lean_object* v_st_2163_; lean_object* v___y_2165_; lean_object* v_deps_2178_; lean_object* v___x_2179_; uint8_t v___x_2180_; 
v_val_2160_ = lean_ctor_get(v___x_2158_, 0);
lean_inc(v_val_2160_);
lean_dec_ref_known(v___x_2158_, 1);
v_comp_2161_ = lean_ctor_get(v_val_2160_, 0);
lean_inc_ref(v_comp_2161_);
v_parent_2162_ = lean_ctor_get(v_val_2160_, 1);
lean_inc(v_parent_2162_);
v_st_2163_ = lean_ctor_get(v_val_2160_, 3);
lean_inc_ref(v_st_2163_);
lean_dec(v_val_2160_);
v_deps_2178_ = lean_ctor_get(v_comp_2161_, 0);
lean_inc_ref(v_deps_2178_);
lean_dec_ref(v_comp_2161_);
v___x_2179_ = lp_bounded_Bounded_KMap_get___redArg(v_deps_2178_, v_x_2153_);
lean_dec_ref(v_deps_2178_);
v___x_2180_ = lean_unbox(v___x_2179_);
lean_dec(v___x_2179_);
if (v___x_2180_ == 0)
{
if (lean_obj_tag(v_parent_2162_) == 0)
{
lean_object* v___x_2181_; 
v___x_2181_ = lean_box(2);
v___y_2165_ = v___x_2181_;
goto v___jp_2164_;
}
else
{
lean_object* v_val_2182_; lean_object* v_one_2183_; lean_object* v_n_2184_; uint8_t v___x_2185_; lean_object* v___x_2186_; 
v_val_2182_ = lean_ctor_get(v_parent_2162_, 0);
lean_inc(v_val_2182_);
lean_dec_ref_known(v_parent_2162_, 1);
v_one_2183_ = lean_unsigned_to_nat(1u);
v_n_2184_ = lean_nat_sub(v_x_2151_, v_one_2183_);
v___x_2185_ = 1;
v___x_2186_ = lp_bounded_Bounded_readC(v_00_u03b3_2150_, v_n_2184_, v_val_2182_, v_x_2153_, v___x_2185_);
lean_dec(v_val_2182_);
lean_dec(v_n_2184_);
v___y_2165_ = v___x_2186_;
goto v___jp_2164_;
}
}
else
{
lean_object* v___x_2187_; 
lean_dec(v_parent_2162_);
v___x_2187_ = lean_box(1);
v___y_2165_ = v___x_2187_;
goto v___jp_2164_;
}
v___jp_2164_:
{
lean_object* v___x_2166_; 
v___x_2166_ = lp_bounded_Bounded_LState_viewOf(v_st_2163_);
lean_dec_ref(v_st_2163_);
if (lean_obj_tag(v___x_2166_) == 0)
{
return v___y_2165_;
}
else
{
lean_object* v_val_2167_; lean_object* v___x_2168_; 
v_val_2167_ = lean_ctor_get(v___x_2166_, 0);
lean_inc(v_val_2167_);
lean_dec_ref_known(v___x_2166_, 1);
v___x_2168_ = lp_bounded_Bounded_KMap_get___redArg(v_val_2167_, v_x_2153_);
lean_dec(v_val_2167_);
if (lean_obj_tag(v___x_2168_) == 0)
{
return v___y_2165_;
}
else
{
lean_object* v_val_2169_; lean_object* v___x_2170_; 
lean_dec(v___y_2165_);
v_val_2169_ = lean_ctor_get(v___x_2168_, 0);
lean_inc(v_val_2169_);
lean_dec_ref_known(v___x_2168_, 1);
v___x_2170_ = lp_bounded_Bounded_SMap_get___redArg(v_00_u03b3_2150_, v_val_2169_);
lean_dec(v_val_2169_);
if (lean_obj_tag(v___x_2170_) == 0)
{
lean_object* v___x_2171_; 
v___x_2171_ = lean_box(1);
return v___x_2171_;
}
else
{
lean_object* v_val_2172_; lean_object* v_table_2173_; lean_object* v___x_2174_; 
v_val_2172_ = lean_ctor_get(v___x_2170_, 0);
lean_inc(v_val_2172_);
lean_dec_ref_known(v___x_2170_, 1);
v_table_2173_ = lean_ctor_get(v_val_2172_, 2);
lean_inc_ref(v_table_2173_);
lean_dec(v_val_2172_);
v___x_2174_ = lp_bounded_Bounded_KMap_get___redArg(v_table_2173_, v_x_2153_);
lean_dec_ref(v_table_2173_);
if (lean_obj_tag(v___x_2174_) == 0)
{
lean_object* v___x_2175_; 
v___x_2175_ = lean_box(1);
return v___x_2175_;
}
else
{
lean_object* v_val_2176_; lean_object* v___x_2177_; 
v_val_2176_ = lean_ctor_get(v___x_2174_, 0);
lean_inc(v_val_2176_);
lean_dec_ref_known(v___x_2174_, 1);
v___x_2177_ = lean_alloc_ctor(0, 1, 1);
lean_ctor_set(v___x_2177_, 0, v_val_2176_);
lean_ctor_set_uint8(v___x_2177_, sizeof(void*)*1, v_x_2154_);
return v___x_2177_;
}
}
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_readC___boxed(lean_object* v_00_u03b3_2188_, lean_object* v_x_2189_, lean_object* v_x_2190_, lean_object* v_x_2191_, lean_object* v_x_2192_){
_start:
{
uint8_t v_x_263__boxed_2193_; lean_object* v_res_2194_; 
v_x_263__boxed_2193_ = lean_unbox(v_x_2192_);
v_res_2194_ = lp_bounded_Bounded_readC(v_00_u03b3_2188_, v_x_2189_, v_x_2190_, v_x_2191_, v_x_263__boxed_2193_);
lean_dec(v_x_2191_);
lean_dec(v_x_2190_);
lean_dec(v_x_2189_);
lean_dec_ref(v_00_u03b3_2188_);
return v_res_2194_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_bounded_Bounded_Perm(uint8_t builtin);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_bounded_Bounded_Calc(uint8_t builtin) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_bounded_Bounded_Perm(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
lp_bounded_Bounded_instFinEnumStep = _init_lp_bounded_Bounded_instFinEnumStep();
lean_mark_persistent(lp_bounded_Bounded_instFinEnumStep);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
