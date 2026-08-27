// Lean compiler output
// Module: Bounded.SigDec
// Imports: public import Init public meta import Init public import Bounded.Calc
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
lean_object* l_List_mapTR_loop___redArg(lean_object*, lean_object*, lean_object*);
lean_object* lean_string_length(lean_object*);
lean_object* lean_nat_to_int(lean_object*);
extern lean_object* lp_bounded_Bounded_allSlots;
lean_object* lp_bounded_Bounded_SMap_get___redArg(lean_object*, lean_object*);
extern lean_object* lp_bounded_Bounded_allKeys;
lean_object* lp_bounded_Bounded_KMap_get___redArg(lean_object*, lean_object*);
uint8_t lp_bounded_Bounded_hasChild(lean_object*, lean_object*);
lean_object* lp_bounded_Bounded_targetOf(lean_object*, lean_object*);
lean_object* lp_bounded_Bounded_LState_viewOf(lean_object*);
lean_object* l_instDecidableEqFin___boxed(lean_object*, lean_object*, lean_object*);
uint8_t l_Option_instDecidableEq___redArg(lean_object*, lean_object*, lean_object*);
uint8_t lp_bounded_Bounded_instDecidableEqKMap_decEq___redArg(lean_object*, lean_object*, lean_object*);
lean_object* lp_bounded_Bounded_providerOf(lean_object*, lean_object*);
uint8_t lp_bounded_Bounded_LState_isInstalled(lean_object*);
uint8_t l_List_isEmpty___redArg(lean_object*);
lean_object* l_List_head_x3f___redArg(lean_object*);
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
lean_object* lp_bounded_Bounded_readC(lean_object*, lean_object*, lean_object*, lean_object*, uint8_t);
uint8_t lp_bounded_Bounded_reliedUpon(lean_object*, lean_object*);
lean_object* lean_nat_mod(lean_object*, lean_object*);
lean_object* l_List_reverse___redArg(lean_object*);
lean_object* lean_mk_empty_array_with_capacity(lean_object*);
lean_object* lean_array_to_list(lean_object*);
lean_object* l_List_foldl___at___00Array_appendList_spec__0___redArg(lean_object*, lean_object*);
lean_object* l_List_appendTR___redArg(lean_object*, lean_object*);
uint8_t l_instDecidableEqProd___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Repr_addAppParen(lean_object*, lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
lean_object* l_Bool_repr___redArg(uint8_t);
lean_object* l_Std_Format_joinSep___at___00Lean_Syntax_formatStxAux_spec__2(lean_object*, lean_object*);
lean_object* lp_bounded_Bounded_storeOf___boxed(lean_object*, lean_object*);
lean_object* lp_bounded_Bounded_KMap_ofFun___redArg(lean_object*);
uint8_t lp_bounded_Bounded_quiet(lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
lean_object* l_Nat_reprFast(lean_object*);
uint8_t lp_bounded_Bounded_instDecidableEqComponent_decEq(lean_object*, lean_object*);
uint8_t lp_bounded_Bounded_instDecidableEqSMap_decEq___redArg(lean_object*, lean_object*, lean_object*);
lean_object* lp_bounded_Bounded_KMap_set___redArg(lean_object*, lean_object*, lean_object*);
lean_object* lp_bounded_Bounded_SMap_set___redArg(lean_object*, lean_object*, lean_object*);
lean_object* lp_bounded_Bounded_BList_push___redArg(lean_object*, lean_object*, lean_object*);
lean_object* lp_bounded_Bounded_partialTarget(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_ctorIdx(uint8_t);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_ctorIdx___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_toCtorIdx(uint8_t);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_toCtorIdx___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_ctorElim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_ctorElim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_ctorElim(lean_object*, lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_ctorElim___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_oInsert_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_oInsert_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_oInsert_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_oInsert_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_oRetire_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_oRetire_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_oRetire_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_oRetire_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_oRemove_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_oRemove_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_oRemove_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_oRemove_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lBegin_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lBegin_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lBegin_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lBegin_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lIter_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lIter_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lIter_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lIter_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lFinish_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lFinish_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lFinish_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lFinish_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lDivert_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lDivert_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lDivert_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lDivert_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lRaise_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lRaise_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lRaise_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lRaise_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lLeave_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lLeave_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lLeave_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lLeave_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lUnload_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lUnload_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lUnload_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lUnload_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_Rule_ofNat(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_ofNat___boxed(lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqRule(uint8_t, uint8_t);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqRule___boxed(lean_object*, lean_object*);
static const lean_string_object lp_bounded_Bounded_instReprRule_repr___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 21, .m_capacity = 21, .m_length = 20, .m_data = "Bounded.Rule.oInsert"};
static const lean_object* lp_bounded_Bounded_instReprRule_repr___closed__0 = (const lean_object*)&lp_bounded_Bounded_instReprRule_repr___closed__0_value;
static const lean_ctor_object lp_bounded_Bounded_instReprRule_repr___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprRule_repr___closed__0_value)}};
static const lean_object* lp_bounded_Bounded_instReprRule_repr___closed__1 = (const lean_object*)&lp_bounded_Bounded_instReprRule_repr___closed__1_value;
static const lean_string_object lp_bounded_Bounded_instReprRule_repr___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 21, .m_capacity = 21, .m_length = 20, .m_data = "Bounded.Rule.oRetire"};
static const lean_object* lp_bounded_Bounded_instReprRule_repr___closed__2 = (const lean_object*)&lp_bounded_Bounded_instReprRule_repr___closed__2_value;
static const lean_ctor_object lp_bounded_Bounded_instReprRule_repr___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprRule_repr___closed__2_value)}};
static const lean_object* lp_bounded_Bounded_instReprRule_repr___closed__3 = (const lean_object*)&lp_bounded_Bounded_instReprRule_repr___closed__3_value;
static const lean_string_object lp_bounded_Bounded_instReprRule_repr___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 21, .m_capacity = 21, .m_length = 20, .m_data = "Bounded.Rule.oRemove"};
static const lean_object* lp_bounded_Bounded_instReprRule_repr___closed__4 = (const lean_object*)&lp_bounded_Bounded_instReprRule_repr___closed__4_value;
static const lean_ctor_object lp_bounded_Bounded_instReprRule_repr___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprRule_repr___closed__4_value)}};
static const lean_object* lp_bounded_Bounded_instReprRule_repr___closed__5 = (const lean_object*)&lp_bounded_Bounded_instReprRule_repr___closed__5_value;
static const lean_string_object lp_bounded_Bounded_instReprRule_repr___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 20, .m_capacity = 20, .m_length = 19, .m_data = "Bounded.Rule.lBegin"};
static const lean_object* lp_bounded_Bounded_instReprRule_repr___closed__6 = (const lean_object*)&lp_bounded_Bounded_instReprRule_repr___closed__6_value;
static const lean_ctor_object lp_bounded_Bounded_instReprRule_repr___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprRule_repr___closed__6_value)}};
static const lean_object* lp_bounded_Bounded_instReprRule_repr___closed__7 = (const lean_object*)&lp_bounded_Bounded_instReprRule_repr___closed__7_value;
static const lean_string_object lp_bounded_Bounded_instReprRule_repr___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 19, .m_capacity = 19, .m_length = 18, .m_data = "Bounded.Rule.lIter"};
static const lean_object* lp_bounded_Bounded_instReprRule_repr___closed__8 = (const lean_object*)&lp_bounded_Bounded_instReprRule_repr___closed__8_value;
static const lean_ctor_object lp_bounded_Bounded_instReprRule_repr___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprRule_repr___closed__8_value)}};
static const lean_object* lp_bounded_Bounded_instReprRule_repr___closed__9 = (const lean_object*)&lp_bounded_Bounded_instReprRule_repr___closed__9_value;
static const lean_string_object lp_bounded_Bounded_instReprRule_repr___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 21, .m_capacity = 21, .m_length = 20, .m_data = "Bounded.Rule.lFinish"};
static const lean_object* lp_bounded_Bounded_instReprRule_repr___closed__10 = (const lean_object*)&lp_bounded_Bounded_instReprRule_repr___closed__10_value;
static const lean_ctor_object lp_bounded_Bounded_instReprRule_repr___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprRule_repr___closed__10_value)}};
static const lean_object* lp_bounded_Bounded_instReprRule_repr___closed__11 = (const lean_object*)&lp_bounded_Bounded_instReprRule_repr___closed__11_value;
static const lean_string_object lp_bounded_Bounded_instReprRule_repr___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 21, .m_capacity = 21, .m_length = 20, .m_data = "Bounded.Rule.lDivert"};
static const lean_object* lp_bounded_Bounded_instReprRule_repr___closed__12 = (const lean_object*)&lp_bounded_Bounded_instReprRule_repr___closed__12_value;
static const lean_ctor_object lp_bounded_Bounded_instReprRule_repr___closed__13_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprRule_repr___closed__12_value)}};
static const lean_object* lp_bounded_Bounded_instReprRule_repr___closed__13 = (const lean_object*)&lp_bounded_Bounded_instReprRule_repr___closed__13_value;
static const lean_string_object lp_bounded_Bounded_instReprRule_repr___closed__14_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 20, .m_capacity = 20, .m_length = 19, .m_data = "Bounded.Rule.lRaise"};
static const lean_object* lp_bounded_Bounded_instReprRule_repr___closed__14 = (const lean_object*)&lp_bounded_Bounded_instReprRule_repr___closed__14_value;
static const lean_ctor_object lp_bounded_Bounded_instReprRule_repr___closed__15_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprRule_repr___closed__14_value)}};
static const lean_object* lp_bounded_Bounded_instReprRule_repr___closed__15 = (const lean_object*)&lp_bounded_Bounded_instReprRule_repr___closed__15_value;
static const lean_string_object lp_bounded_Bounded_instReprRule_repr___closed__16_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 20, .m_capacity = 20, .m_length = 19, .m_data = "Bounded.Rule.lLeave"};
static const lean_object* lp_bounded_Bounded_instReprRule_repr___closed__16 = (const lean_object*)&lp_bounded_Bounded_instReprRule_repr___closed__16_value;
static const lean_ctor_object lp_bounded_Bounded_instReprRule_repr___closed__17_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprRule_repr___closed__16_value)}};
static const lean_object* lp_bounded_Bounded_instReprRule_repr___closed__17 = (const lean_object*)&lp_bounded_Bounded_instReprRule_repr___closed__17_value;
static const lean_string_object lp_bounded_Bounded_instReprRule_repr___closed__18_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 21, .m_capacity = 21, .m_length = 20, .m_data = "Bounded.Rule.lUnload"};
static const lean_object* lp_bounded_Bounded_instReprRule_repr___closed__18 = (const lean_object*)&lp_bounded_Bounded_instReprRule_repr___closed__18_value;
static const lean_ctor_object lp_bounded_Bounded_instReprRule_repr___closed__19_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprRule_repr___closed__18_value)}};
static const lean_object* lp_bounded_Bounded_instReprRule_repr___closed__19 = (const lean_object*)&lp_bounded_Bounded_instReprRule_repr___closed__19_value;
static lean_once_cell_t lp_bounded_Bounded_instReprRule_repr___closed__20_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_instReprRule_repr___closed__20;
static lean_once_cell_t lp_bounded_Bounded_instReprRule_repr___closed__21_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_instReprRule_repr___closed__21;
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprRule_repr(uint8_t, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprRule_repr___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_bounded_Bounded_instReprRule___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_bounded_Bounded_instReprRule_repr___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_bounded_Bounded_instReprRule___closed__0 = (const lean_object*)&lp_bounded_Bounded_instReprRule___closed__0_value;
LEAN_EXPORT const lean_object* lp_bounded_Bounded_instReprRule = (const lean_object*)&lp_bounded_Bounded_instReprRule___closed__0_value;
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_ctorIdx(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_ctorIdx___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_ctorElim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_ctorElim(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_ctorElim___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_oInsert_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_oInsert_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_oRetire_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_oRetire_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_oRemove_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_oRemove_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_lBegin_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_lBegin_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_lIter_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_lIter_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_lFinish_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_lFinish_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_lDivert_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_lDivert_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_lRaise_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_lRaise_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_lLeave_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_lLeave_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_lUnload_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_lUnload_elim(lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_closure_object lp_bounded_Bounded_instDecidableEqAct_decEq___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*1, .m_other = 0, .m_tag = 245}, .m_fun = (void*)l_instDecidableEqFin___boxed, .m_arity = 3, .m_num_fixed = 1, .m_objs = {((lean_object*)(((size_t)(3) << 1) | 1))} };
static const lean_object* lp_bounded_Bounded_instDecidableEqAct_decEq___closed__0 = (const lean_object*)&lp_bounded_Bounded_instDecidableEqAct_decEq___closed__0_value;
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqAct_decEq(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqAct_decEq___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqAct(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqAct___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_Act_rule(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_rule___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_ctorIdx(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_ctorIdx___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_ctorElim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_ctorElim(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_ctorElim___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_inserted_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_inserted_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_retiredEv_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_retiredEv_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_removedEv_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_removedEv_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_began_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_began_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_provided_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_provided_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_applied_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_applied_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_readOk_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_readOk_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_readFail_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_readFail_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_setv_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_setv_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_registered_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_registered_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_raised_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_raised_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_activated_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_activated_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_diverted_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_diverted_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_leftEv_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_leftEv_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_reverted_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_reverted_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_unprovided_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_unprovided_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_childRetired_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_childRetired_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_deactivated_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_deactivated_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqEvent_decEq(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqEvent_decEq___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqEvent(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqEvent___boxed(lean_object*, lean_object*);
static const lean_string_object lp_bounded_Bounded_instReprEvent_repr___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 23, .m_capacity = 23, .m_length = 22, .m_data = "Bounded.Event.inserted"};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__0 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__0_value;
static const lean_ctor_object lp_bounded_Bounded_instReprEvent_repr___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__0_value)}};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__1 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__1_value;
static const lean_ctor_object lp_bounded_Bounded_instReprEvent_repr___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__1_value),((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__2 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__2_value;
static const lean_string_object lp_bounded_Bounded_instReprEvent_repr___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 24, .m_capacity = 24, .m_length = 23, .m_data = "Bounded.Event.retiredEv"};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__3 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__3_value;
static const lean_ctor_object lp_bounded_Bounded_instReprEvent_repr___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__3_value)}};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__4 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__4_value;
static const lean_ctor_object lp_bounded_Bounded_instReprEvent_repr___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__4_value),((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__5 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__5_value;
static const lean_string_object lp_bounded_Bounded_instReprEvent_repr___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 24, .m_capacity = 24, .m_length = 23, .m_data = "Bounded.Event.removedEv"};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__6 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__6_value;
static const lean_ctor_object lp_bounded_Bounded_instReprEvent_repr___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__6_value)}};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__7 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__7_value;
static const lean_ctor_object lp_bounded_Bounded_instReprEvent_repr___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__7_value),((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__8 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__8_value;
static const lean_string_object lp_bounded_Bounded_instReprEvent_repr___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 20, .m_capacity = 20, .m_length = 19, .m_data = "Bounded.Event.began"};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__9 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__9_value;
static const lean_ctor_object lp_bounded_Bounded_instReprEvent_repr___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__9_value)}};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__10 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__10_value;
static const lean_ctor_object lp_bounded_Bounded_instReprEvent_repr___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__10_value),((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__11 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__11_value;
static const lean_string_object lp_bounded_Bounded_instReprEvent_repr___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 23, .m_capacity = 23, .m_length = 22, .m_data = "Bounded.Event.provided"};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__12 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__12_value;
static const lean_ctor_object lp_bounded_Bounded_instReprEvent_repr___closed__13_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__12_value)}};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__13 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__13_value;
static const lean_ctor_object lp_bounded_Bounded_instReprEvent_repr___closed__14_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__13_value),((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__14 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__14_value;
static const lean_string_object lp_bounded_Bounded_instReprEvent_repr___closed__15_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 22, .m_capacity = 22, .m_length = 21, .m_data = "Bounded.Event.applied"};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__15 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__15_value;
static const lean_ctor_object lp_bounded_Bounded_instReprEvent_repr___closed__16_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__15_value)}};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__16 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__16_value;
static const lean_ctor_object lp_bounded_Bounded_instReprEvent_repr___closed__17_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__16_value),((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__17 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__17_value;
static const lean_string_object lp_bounded_Bounded_instReprEvent_repr___closed__18_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 21, .m_capacity = 21, .m_length = 20, .m_data = "Bounded.Event.readOk"};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__18 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__18_value;
static const lean_ctor_object lp_bounded_Bounded_instReprEvent_repr___closed__19_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__18_value)}};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__19 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__19_value;
static const lean_ctor_object lp_bounded_Bounded_instReprEvent_repr___closed__20_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__19_value),((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__20 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__20_value;
static const lean_string_object lp_bounded_Bounded_instReprEvent_repr___closed__21_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 23, .m_capacity = 23, .m_length = 22, .m_data = "Bounded.Event.readFail"};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__21 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__21_value;
static const lean_ctor_object lp_bounded_Bounded_instReprEvent_repr___closed__22_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__21_value)}};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__22 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__22_value;
static const lean_ctor_object lp_bounded_Bounded_instReprEvent_repr___closed__23_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__22_value),((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__23 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__23_value;
static const lean_string_object lp_bounded_Bounded_instReprEvent_repr___closed__24_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 19, .m_capacity = 19, .m_length = 18, .m_data = "Bounded.Event.setv"};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__24 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__24_value;
static const lean_ctor_object lp_bounded_Bounded_instReprEvent_repr___closed__25_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__24_value)}};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__25 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__25_value;
static const lean_ctor_object lp_bounded_Bounded_instReprEvent_repr___closed__26_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__25_value),((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__26 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__26_value;
static const lean_string_object lp_bounded_Bounded_instReprEvent_repr___closed__27_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 25, .m_capacity = 25, .m_length = 24, .m_data = "Bounded.Event.registered"};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__27 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__27_value;
static const lean_ctor_object lp_bounded_Bounded_instReprEvent_repr___closed__28_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__27_value)}};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__28 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__28_value;
static const lean_ctor_object lp_bounded_Bounded_instReprEvent_repr___closed__29_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__28_value),((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__29 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__29_value;
static const lean_string_object lp_bounded_Bounded_instReprEvent_repr___closed__30_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 21, .m_capacity = 21, .m_length = 20, .m_data = "Bounded.Event.raised"};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__30 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__30_value;
static const lean_ctor_object lp_bounded_Bounded_instReprEvent_repr___closed__31_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__30_value)}};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__31 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__31_value;
static const lean_ctor_object lp_bounded_Bounded_instReprEvent_repr___closed__32_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__31_value),((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__32 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__32_value;
static const lean_string_object lp_bounded_Bounded_instReprEvent_repr___closed__33_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 24, .m_capacity = 24, .m_length = 23, .m_data = "Bounded.Event.activated"};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__33 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__33_value;
static const lean_ctor_object lp_bounded_Bounded_instReprEvent_repr___closed__34_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__33_value)}};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__34 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__34_value;
static const lean_ctor_object lp_bounded_Bounded_instReprEvent_repr___closed__35_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__34_value),((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__35 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__35_value;
static const lean_string_object lp_bounded_Bounded_instReprEvent_repr___closed__36_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 23, .m_capacity = 23, .m_length = 22, .m_data = "Bounded.Event.diverted"};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__36 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__36_value;
static const lean_ctor_object lp_bounded_Bounded_instReprEvent_repr___closed__37_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__36_value)}};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__37 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__37_value;
static const lean_ctor_object lp_bounded_Bounded_instReprEvent_repr___closed__38_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__37_value),((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__38 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__38_value;
static const lean_string_object lp_bounded_Bounded_instReprEvent_repr___closed__39_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 21, .m_capacity = 21, .m_length = 20, .m_data = "Bounded.Event.leftEv"};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__39 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__39_value;
static const lean_ctor_object lp_bounded_Bounded_instReprEvent_repr___closed__40_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__39_value)}};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__40 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__40_value;
static const lean_ctor_object lp_bounded_Bounded_instReprEvent_repr___closed__41_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__40_value),((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__41 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__41_value;
static const lean_string_object lp_bounded_Bounded_instReprEvent_repr___closed__42_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 23, .m_capacity = 23, .m_length = 22, .m_data = "Bounded.Event.reverted"};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__42 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__42_value;
static const lean_ctor_object lp_bounded_Bounded_instReprEvent_repr___closed__43_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__42_value)}};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__43 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__43_value;
static const lean_ctor_object lp_bounded_Bounded_instReprEvent_repr___closed__44_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__43_value),((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__44 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__44_value;
static const lean_string_object lp_bounded_Bounded_instReprEvent_repr___closed__45_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 25, .m_capacity = 25, .m_length = 24, .m_data = "Bounded.Event.unprovided"};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__45 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__45_value;
static const lean_ctor_object lp_bounded_Bounded_instReprEvent_repr___closed__46_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__45_value)}};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__46 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__46_value;
static const lean_ctor_object lp_bounded_Bounded_instReprEvent_repr___closed__47_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__46_value),((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__47 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__47_value;
static const lean_string_object lp_bounded_Bounded_instReprEvent_repr___closed__48_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 27, .m_capacity = 27, .m_length = 26, .m_data = "Bounded.Event.childRetired"};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__48 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__48_value;
static const lean_ctor_object lp_bounded_Bounded_instReprEvent_repr___closed__49_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__48_value)}};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__49 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__49_value;
static const lean_ctor_object lp_bounded_Bounded_instReprEvent_repr___closed__50_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__49_value),((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__50 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__50_value;
static const lean_string_object lp_bounded_Bounded_instReprEvent_repr___closed__51_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 26, .m_capacity = 26, .m_length = 25, .m_data = "Bounded.Event.deactivated"};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__51 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__51_value;
static const lean_ctor_object lp_bounded_Bounded_instReprEvent_repr___closed__52_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__51_value)}};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__52 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__52_value;
static const lean_ctor_object lp_bounded_Bounded_instReprEvent_repr___closed__53_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__52_value),((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* lp_bounded_Bounded_instReprEvent_repr___closed__53 = (const lean_object*)&lp_bounded_Bounded_instReprEvent_repr___closed__53_value;
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprEvent_repr(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprEvent_repr___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_bounded_Bounded_instReprEvent___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_bounded_Bounded_instReprEvent_repr___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_bounded_Bounded_instReprEvent___closed__0 = (const lean_object*)&lp_bounded_Bounded_instReprEvent___closed__0_value;
LEAN_EXPORT const lean_object* lp_bounded_Bounded_instReprEvent = (const lean_object*)&lp_bounded_Bounded_instReprEvent___closed__0_value;
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_ctorIdx(uint8_t);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_ctorIdx___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_toCtorIdx(uint8_t);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_toCtorIdx___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_ctorElim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_ctorElim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_ctorElim(lean_object*, lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_ctorElim___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_absent_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_absent_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_absent_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_absent_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_inactOk_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_inactOk_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_inactOk_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_inactOk_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_inactErr_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_inactErr_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_inactErr_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_inactErr_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_reload_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_reload_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_reload_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_reload_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_activeS_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_activeS_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_activeS_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_activeS_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_unloadOk_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_unloadOk_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_unloadOk_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_unloadOk_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_unloadErr_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_unloadErr_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_unloadErr_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_unloadErr_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_StCls_ofNat(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_ofNat___boxed(lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqStCls(uint8_t, uint8_t);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqStCls___boxed(lean_object*, lean_object*);
static const lean_string_object lp_bounded_Bounded_instReprStCls_repr___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 21, .m_capacity = 21, .m_length = 20, .m_data = "Bounded.StCls.absent"};
static const lean_object* lp_bounded_Bounded_instReprStCls_repr___closed__0 = (const lean_object*)&lp_bounded_Bounded_instReprStCls_repr___closed__0_value;
static const lean_ctor_object lp_bounded_Bounded_instReprStCls_repr___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprStCls_repr___closed__0_value)}};
static const lean_object* lp_bounded_Bounded_instReprStCls_repr___closed__1 = (const lean_object*)&lp_bounded_Bounded_instReprStCls_repr___closed__1_value;
static const lean_string_object lp_bounded_Bounded_instReprStCls_repr___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 22, .m_capacity = 22, .m_length = 21, .m_data = "Bounded.StCls.inactOk"};
static const lean_object* lp_bounded_Bounded_instReprStCls_repr___closed__2 = (const lean_object*)&lp_bounded_Bounded_instReprStCls_repr___closed__2_value;
static const lean_ctor_object lp_bounded_Bounded_instReprStCls_repr___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprStCls_repr___closed__2_value)}};
static const lean_object* lp_bounded_Bounded_instReprStCls_repr___closed__3 = (const lean_object*)&lp_bounded_Bounded_instReprStCls_repr___closed__3_value;
static const lean_string_object lp_bounded_Bounded_instReprStCls_repr___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 23, .m_capacity = 23, .m_length = 22, .m_data = "Bounded.StCls.inactErr"};
static const lean_object* lp_bounded_Bounded_instReprStCls_repr___closed__4 = (const lean_object*)&lp_bounded_Bounded_instReprStCls_repr___closed__4_value;
static const lean_ctor_object lp_bounded_Bounded_instReprStCls_repr___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprStCls_repr___closed__4_value)}};
static const lean_object* lp_bounded_Bounded_instReprStCls_repr___closed__5 = (const lean_object*)&lp_bounded_Bounded_instReprStCls_repr___closed__5_value;
static const lean_string_object lp_bounded_Bounded_instReprStCls_repr___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 21, .m_capacity = 21, .m_length = 20, .m_data = "Bounded.StCls.reload"};
static const lean_object* lp_bounded_Bounded_instReprStCls_repr___closed__6 = (const lean_object*)&lp_bounded_Bounded_instReprStCls_repr___closed__6_value;
static const lean_ctor_object lp_bounded_Bounded_instReprStCls_repr___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprStCls_repr___closed__6_value)}};
static const lean_object* lp_bounded_Bounded_instReprStCls_repr___closed__7 = (const lean_object*)&lp_bounded_Bounded_instReprStCls_repr___closed__7_value;
static const lean_string_object lp_bounded_Bounded_instReprStCls_repr___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 22, .m_capacity = 22, .m_length = 21, .m_data = "Bounded.StCls.activeS"};
static const lean_object* lp_bounded_Bounded_instReprStCls_repr___closed__8 = (const lean_object*)&lp_bounded_Bounded_instReprStCls_repr___closed__8_value;
static const lean_ctor_object lp_bounded_Bounded_instReprStCls_repr___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprStCls_repr___closed__8_value)}};
static const lean_object* lp_bounded_Bounded_instReprStCls_repr___closed__9 = (const lean_object*)&lp_bounded_Bounded_instReprStCls_repr___closed__9_value;
static const lean_string_object lp_bounded_Bounded_instReprStCls_repr___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 23, .m_capacity = 23, .m_length = 22, .m_data = "Bounded.StCls.unloadOk"};
static const lean_object* lp_bounded_Bounded_instReprStCls_repr___closed__10 = (const lean_object*)&lp_bounded_Bounded_instReprStCls_repr___closed__10_value;
static const lean_ctor_object lp_bounded_Bounded_instReprStCls_repr___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprStCls_repr___closed__10_value)}};
static const lean_object* lp_bounded_Bounded_instReprStCls_repr___closed__11 = (const lean_object*)&lp_bounded_Bounded_instReprStCls_repr___closed__11_value;
static const lean_string_object lp_bounded_Bounded_instReprStCls_repr___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 24, .m_capacity = 24, .m_length = 23, .m_data = "Bounded.StCls.unloadErr"};
static const lean_object* lp_bounded_Bounded_instReprStCls_repr___closed__12 = (const lean_object*)&lp_bounded_Bounded_instReprStCls_repr___closed__12_value;
static const lean_ctor_object lp_bounded_Bounded_instReprStCls_repr___closed__13_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprStCls_repr___closed__12_value)}};
static const lean_object* lp_bounded_Bounded_instReprStCls_repr___closed__13 = (const lean_object*)&lp_bounded_Bounded_instReprStCls_repr___closed__13_value;
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprStCls_repr(uint8_t, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprStCls_repr___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_bounded_Bounded_instReprStCls___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_bounded_Bounded_instReprStCls_repr___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_bounded_Bounded_instReprStCls___closed__0 = (const lean_object*)&lp_bounded_Bounded_instReprStCls___closed__0_value;
LEAN_EXPORT const lean_object* lp_bounded_Bounded_instReprStCls = (const lean_object*)&lp_bounded_Bounded_instReprStCls___closed__0_value;
LEAN_EXPORT uint8_t lp_bounded_Bounded_stClsOf(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_stClsOf___boxed(lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_retiredOf(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_retiredOf___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_TRel_ctorIdx(uint8_t);
LEAN_EXPORT lean_object* lp_bounded_Bounded_TRel_ctorIdx___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_TRel_toCtorIdx(uint8_t);
LEAN_EXPORT lean_object* lp_bounded_Bounded_TRel_toCtorIdx___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_TRel_ctorElim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_TRel_ctorElim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_TRel_ctorElim(lean_object*, lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_TRel_ctorElim___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_TRel_bot_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_TRel_bot_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_TRel_bot_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_TRel_bot_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_TRel_eq_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_TRel_eq_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_TRel_eq_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_TRel_eq_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_TRel_ne_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_TRel_ne_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_TRel_ne_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_TRel_ne_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_TRel_ofNat(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_TRel_ofNat___boxed(lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqTRel(uint8_t, uint8_t);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqTRel___boxed(lean_object*, lean_object*);
static const lean_string_object lp_bounded_Bounded_instReprTRel_repr___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 17, .m_capacity = 17, .m_length = 16, .m_data = "Bounded.TRel.bot"};
static const lean_object* lp_bounded_Bounded_instReprTRel_repr___closed__0 = (const lean_object*)&lp_bounded_Bounded_instReprTRel_repr___closed__0_value;
static const lean_ctor_object lp_bounded_Bounded_instReprTRel_repr___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprTRel_repr___closed__0_value)}};
static const lean_object* lp_bounded_Bounded_instReprTRel_repr___closed__1 = (const lean_object*)&lp_bounded_Bounded_instReprTRel_repr___closed__1_value;
static const lean_string_object lp_bounded_Bounded_instReprTRel_repr___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 16, .m_capacity = 16, .m_length = 15, .m_data = "Bounded.TRel.eq"};
static const lean_object* lp_bounded_Bounded_instReprTRel_repr___closed__2 = (const lean_object*)&lp_bounded_Bounded_instReprTRel_repr___closed__2_value;
static const lean_ctor_object lp_bounded_Bounded_instReprTRel_repr___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprTRel_repr___closed__2_value)}};
static const lean_object* lp_bounded_Bounded_instReprTRel_repr___closed__3 = (const lean_object*)&lp_bounded_Bounded_instReprTRel_repr___closed__3_value;
static const lean_string_object lp_bounded_Bounded_instReprTRel_repr___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 16, .m_capacity = 16, .m_length = 15, .m_data = "Bounded.TRel.ne"};
static const lean_object* lp_bounded_Bounded_instReprTRel_repr___closed__4 = (const lean_object*)&lp_bounded_Bounded_instReprTRel_repr___closed__4_value;
static const lean_ctor_object lp_bounded_Bounded_instReprTRel_repr___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprTRel_repr___closed__4_value)}};
static const lean_object* lp_bounded_Bounded_instReprTRel_repr___closed__5 = (const lean_object*)&lp_bounded_Bounded_instReprTRel_repr___closed__5_value;
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprTRel_repr(uint8_t, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprTRel_repr___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_bounded_Bounded_instReprTRel___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_bounded_Bounded_instReprTRel_repr___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_bounded_Bounded_instReprTRel___closed__0 = (const lean_object*)&lp_bounded_Bounded_instReprTRel___closed__0_value;
LEAN_EXPORT const lean_object* lp_bounded_Bounded_instReprTRel = (const lean_object*)&lp_bounded_Bounded_instReprTRel___closed__0_value;
LEAN_EXPORT uint8_t lp_bounded_Bounded_tRelOf___lam__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_tRelOf___lam__0___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_bounded_Bounded_tRelOf___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_bounded_Bounded_tRelOf___lam__0___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_bounded_Bounded_tRelOf___closed__0 = (const lean_object*)&lp_bounded_Bounded_tRelOf___closed__0_value;
LEAN_EXPORT uint8_t lp_bounded_Bounded_tRelOf(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_tRelOf___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadCls_ctorIdx(uint8_t);
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadCls_ctorIdx___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadCls_toCtorIdx(uint8_t);
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadCls_toCtorIdx___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadCls_ctorElim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadCls_ctorElim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadCls_ctorElim(lean_object*, lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadCls_ctorElim___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadCls_own_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadCls_own_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadCls_own_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadCls_own_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadCls_ancestor_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadCls_ancestor_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadCls_ancestor_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadCls_ancestor_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadCls_ia_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadCls_ia_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadCls_ia_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadCls_ia_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadCls_ud_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadCls_ud_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadCls_ud_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadCls_ud_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_ReadCls_ofNat(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadCls_ofNat___boxed(lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqReadCls(uint8_t, uint8_t);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqReadCls___boxed(lean_object*, lean_object*);
static const lean_string_object lp_bounded_Bounded_instReprReadCls_repr___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 20, .m_capacity = 20, .m_length = 19, .m_data = "Bounded.ReadCls.own"};
static const lean_object* lp_bounded_Bounded_instReprReadCls_repr___closed__0 = (const lean_object*)&lp_bounded_Bounded_instReprReadCls_repr___closed__0_value;
static const lean_ctor_object lp_bounded_Bounded_instReprReadCls_repr___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprReadCls_repr___closed__0_value)}};
static const lean_object* lp_bounded_Bounded_instReprReadCls_repr___closed__1 = (const lean_object*)&lp_bounded_Bounded_instReprReadCls_repr___closed__1_value;
static const lean_string_object lp_bounded_Bounded_instReprReadCls_repr___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 25, .m_capacity = 25, .m_length = 24, .m_data = "Bounded.ReadCls.ancestor"};
static const lean_object* lp_bounded_Bounded_instReprReadCls_repr___closed__2 = (const lean_object*)&lp_bounded_Bounded_instReprReadCls_repr___closed__2_value;
static const lean_ctor_object lp_bounded_Bounded_instReprReadCls_repr___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprReadCls_repr___closed__2_value)}};
static const lean_object* lp_bounded_Bounded_instReprReadCls_repr___closed__3 = (const lean_object*)&lp_bounded_Bounded_instReprReadCls_repr___closed__3_value;
static const lean_string_object lp_bounded_Bounded_instReprReadCls_repr___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 19, .m_capacity = 19, .m_length = 18, .m_data = "Bounded.ReadCls.ia"};
static const lean_object* lp_bounded_Bounded_instReprReadCls_repr___closed__4 = (const lean_object*)&lp_bounded_Bounded_instReprReadCls_repr___closed__4_value;
static const lean_ctor_object lp_bounded_Bounded_instReprReadCls_repr___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprReadCls_repr___closed__4_value)}};
static const lean_object* lp_bounded_Bounded_instReprReadCls_repr___closed__5 = (const lean_object*)&lp_bounded_Bounded_instReprReadCls_repr___closed__5_value;
static const lean_string_object lp_bounded_Bounded_instReprReadCls_repr___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 19, .m_capacity = 19, .m_length = 18, .m_data = "Bounded.ReadCls.ud"};
static const lean_object* lp_bounded_Bounded_instReprReadCls_repr___closed__6 = (const lean_object*)&lp_bounded_Bounded_instReprReadCls_repr___closed__6_value;
static const lean_ctor_object lp_bounded_Bounded_instReprReadCls_repr___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprReadCls_repr___closed__6_value)}};
static const lean_object* lp_bounded_Bounded_instReprReadCls_repr___closed__7 = (const lean_object*)&lp_bounded_Bounded_instReprReadCls_repr___closed__7_value;
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprReadCls_repr(uint8_t, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprReadCls_repr___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_bounded_Bounded_instReprReadCls___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_bounded_Bounded_instReprReadCls_repr___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_bounded_Bounded_instReprReadCls___closed__0 = (const lean_object*)&lp_bounded_Bounded_instReprReadCls___closed__0_value;
LEAN_EXPORT const lean_object* lp_bounded_Bounded_instReprReadCls = (const lean_object*)&lp_bounded_Bounded_instReprReadCls___closed__0_value;
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_ctorIdx(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_ctorIdx___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_ctorElim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_ctorElim___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_ctorElim(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_ctorElim___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_provideFresh_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_provideFresh_elim___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_provideFresh_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_provideFresh_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_provideConflict_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_provideConflict_elim___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_provideConflict_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_provideConflict_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_trackC_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_trackC_elim___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_trackC_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_trackC_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_readCls_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_readCls_elim___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_readCls_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_readCls_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_setOwn_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_setOwn_elim___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_setOwn_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_setOwn_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_setMissing_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_setMissing_elim___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_setMissing_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_setMissing_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_regOk_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_regOk_elim___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_regOk_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_regOk_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_regBad_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_regBad_elim___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_regBad_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_regBad_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_raiseC_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_raiseC_elim___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_raiseC_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_raiseC_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_mismatch_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_mismatch_elim___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_mismatch_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_mismatch_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqStepSig_decEq(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqStepSig_decEq___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqStepSig(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqStepSig___boxed(lean_object*, lean_object*);
static const lean_string_object lp_bounded_Bounded_instReprStepSig_repr___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 23, .m_capacity = 23, .m_length = 22, .m_data = "Bounded.StepSig.trackC"};
static const lean_object* lp_bounded_Bounded_instReprStepSig_repr___closed__0 = (const lean_object*)&lp_bounded_Bounded_instReprStepSig_repr___closed__0_value;
static const lean_ctor_object lp_bounded_Bounded_instReprStepSig_repr___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprStepSig_repr___closed__0_value)}};
static const lean_object* lp_bounded_Bounded_instReprStepSig_repr___closed__1 = (const lean_object*)&lp_bounded_Bounded_instReprStepSig_repr___closed__1_value;
static const lean_string_object lp_bounded_Bounded_instReprStepSig_repr___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 32, .m_capacity = 32, .m_length = 31, .m_data = "Bounded.StepSig.provideConflict"};
static const lean_object* lp_bounded_Bounded_instReprStepSig_repr___closed__2 = (const lean_object*)&lp_bounded_Bounded_instReprStepSig_repr___closed__2_value;
static const lean_ctor_object lp_bounded_Bounded_instReprStepSig_repr___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprStepSig_repr___closed__2_value)}};
static const lean_object* lp_bounded_Bounded_instReprStepSig_repr___closed__3 = (const lean_object*)&lp_bounded_Bounded_instReprStepSig_repr___closed__3_value;
static const lean_string_object lp_bounded_Bounded_instReprStepSig_repr___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 29, .m_capacity = 29, .m_length = 28, .m_data = "Bounded.StepSig.provideFresh"};
static const lean_object* lp_bounded_Bounded_instReprStepSig_repr___closed__4 = (const lean_object*)&lp_bounded_Bounded_instReprStepSig_repr___closed__4_value;
static const lean_ctor_object lp_bounded_Bounded_instReprStepSig_repr___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprStepSig_repr___closed__4_value)}};
static const lean_object* lp_bounded_Bounded_instReprStepSig_repr___closed__5 = (const lean_object*)&lp_bounded_Bounded_instReprStepSig_repr___closed__5_value;
static const lean_string_object lp_bounded_Bounded_instReprStepSig_repr___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 23, .m_capacity = 23, .m_length = 22, .m_data = "Bounded.StepSig.setOwn"};
static const lean_object* lp_bounded_Bounded_instReprStepSig_repr___closed__6 = (const lean_object*)&lp_bounded_Bounded_instReprStepSig_repr___closed__6_value;
static const lean_ctor_object lp_bounded_Bounded_instReprStepSig_repr___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprStepSig_repr___closed__6_value)}};
static const lean_object* lp_bounded_Bounded_instReprStepSig_repr___closed__7 = (const lean_object*)&lp_bounded_Bounded_instReprStepSig_repr___closed__7_value;
static const lean_string_object lp_bounded_Bounded_instReprStepSig_repr___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 27, .m_capacity = 27, .m_length = 26, .m_data = "Bounded.StepSig.setMissing"};
static const lean_object* lp_bounded_Bounded_instReprStepSig_repr___closed__8 = (const lean_object*)&lp_bounded_Bounded_instReprStepSig_repr___closed__8_value;
static const lean_ctor_object lp_bounded_Bounded_instReprStepSig_repr___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprStepSig_repr___closed__8_value)}};
static const lean_object* lp_bounded_Bounded_instReprStepSig_repr___closed__9 = (const lean_object*)&lp_bounded_Bounded_instReprStepSig_repr___closed__9_value;
static const lean_string_object lp_bounded_Bounded_instReprStepSig_repr___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 22, .m_capacity = 22, .m_length = 21, .m_data = "Bounded.StepSig.regOk"};
static const lean_object* lp_bounded_Bounded_instReprStepSig_repr___closed__10 = (const lean_object*)&lp_bounded_Bounded_instReprStepSig_repr___closed__10_value;
static const lean_ctor_object lp_bounded_Bounded_instReprStepSig_repr___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprStepSig_repr___closed__10_value)}};
static const lean_object* lp_bounded_Bounded_instReprStepSig_repr___closed__11 = (const lean_object*)&lp_bounded_Bounded_instReprStepSig_repr___closed__11_value;
static const lean_string_object lp_bounded_Bounded_instReprStepSig_repr___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 23, .m_capacity = 23, .m_length = 22, .m_data = "Bounded.StepSig.regBad"};
static const lean_object* lp_bounded_Bounded_instReprStepSig_repr___closed__12 = (const lean_object*)&lp_bounded_Bounded_instReprStepSig_repr___closed__12_value;
static const lean_ctor_object lp_bounded_Bounded_instReprStepSig_repr___closed__13_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprStepSig_repr___closed__12_value)}};
static const lean_object* lp_bounded_Bounded_instReprStepSig_repr___closed__13 = (const lean_object*)&lp_bounded_Bounded_instReprStepSig_repr___closed__13_value;
static const lean_string_object lp_bounded_Bounded_instReprStepSig_repr___closed__14_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 23, .m_capacity = 23, .m_length = 22, .m_data = "Bounded.StepSig.raiseC"};
static const lean_object* lp_bounded_Bounded_instReprStepSig_repr___closed__14 = (const lean_object*)&lp_bounded_Bounded_instReprStepSig_repr___closed__14_value;
static const lean_ctor_object lp_bounded_Bounded_instReprStepSig_repr___closed__15_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprStepSig_repr___closed__14_value)}};
static const lean_object* lp_bounded_Bounded_instReprStepSig_repr___closed__15 = (const lean_object*)&lp_bounded_Bounded_instReprStepSig_repr___closed__15_value;
static const lean_string_object lp_bounded_Bounded_instReprStepSig_repr___closed__16_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 25, .m_capacity = 25, .m_length = 24, .m_data = "Bounded.StepSig.mismatch"};
static const lean_object* lp_bounded_Bounded_instReprStepSig_repr___closed__16 = (const lean_object*)&lp_bounded_Bounded_instReprStepSig_repr___closed__16_value;
static const lean_ctor_object lp_bounded_Bounded_instReprStepSig_repr___closed__17_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprStepSig_repr___closed__16_value)}};
static const lean_object* lp_bounded_Bounded_instReprStepSig_repr___closed__17 = (const lean_object*)&lp_bounded_Bounded_instReprStepSig_repr___closed__17_value;
static const lean_string_object lp_bounded_Bounded_instReprStepSig_repr___closed__18_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 24, .m_capacity = 24, .m_length = 23, .m_data = "Bounded.StepSig.readCls"};
static const lean_object* lp_bounded_Bounded_instReprStepSig_repr___closed__18 = (const lean_object*)&lp_bounded_Bounded_instReprStepSig_repr___closed__18_value;
static const lean_ctor_object lp_bounded_Bounded_instReprStepSig_repr___closed__19_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprStepSig_repr___closed__18_value)}};
static const lean_object* lp_bounded_Bounded_instReprStepSig_repr___closed__19 = (const lean_object*)&lp_bounded_Bounded_instReprStepSig_repr___closed__19_value;
static const lean_ctor_object lp_bounded_Bounded_instReprStepSig_repr___closed__20_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprStepSig_repr___closed__19_value),((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* lp_bounded_Bounded_instReprStepSig_repr___closed__20 = (const lean_object*)&lp_bounded_Bounded_instReprStepSig_repr___closed__20_value;
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprStepSig_repr(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprStepSig_repr___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_bounded_Bounded_instReprStepSig___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_bounded_Bounded_instReprStepSig_repr___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_bounded_Bounded_instReprStepSig___closed__0 = (const lean_object*)&lp_bounded_Bounded_instReprStepSig___closed__0_value;
LEAN_EXPORT const lean_object* lp_bounded_Bounded_instReprStepSig = (const lean_object*)&lp_bounded_Bounded_instReprStepSig___closed__0_value;
LEAN_EXPORT uint8_t lp_bounded_List_any___at___00Bounded_dynConflict_spec__0(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_List_any___at___00Bounded_dynConflict_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_dynConflict(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_dynConflict___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_List_any___at___00Bounded_classifyCore_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_List_any___at___00Bounded_classifyCore_spec__0___boxed(lean_object*, lean_object*);
static const lean_ctor_object lp_bounded_Bounded_classifyCore___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*0 + 8, .m_other = 0, .m_tag = 3}, .m_objs = {LEAN_SCALAR_PTR_LITERAL(0, 0, 0, 0, 0, 0, 0, 0)}};
static const lean_object* lp_bounded_Bounded_classifyCore___closed__0 = (const lean_object*)&lp_bounded_Bounded_classifyCore___closed__0_value;
static const lean_ctor_object lp_bounded_Bounded_classifyCore___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*0 + 8, .m_other = 0, .m_tag = 3}, .m_objs = {LEAN_SCALAR_PTR_LITERAL(1, 0, 0, 0, 0, 0, 0, 0)}};
static const lean_object* lp_bounded_Bounded_classifyCore___closed__1 = (const lean_object*)&lp_bounded_Bounded_classifyCore___closed__1_value;
static const lean_ctor_object lp_bounded_Bounded_classifyCore___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*0 + 8, .m_other = 0, .m_tag = 3}, .m_objs = {LEAN_SCALAR_PTR_LITERAL(2, 0, 0, 0, 0, 0, 0, 0)}};
static const lean_object* lp_bounded_Bounded_classifyCore___closed__2 = (const lean_object*)&lp_bounded_Bounded_classifyCore___closed__2_value;
static const lean_ctor_object lp_bounded_Bounded_classifyCore___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*0 + 8, .m_other = 0, .m_tag = 3}, .m_objs = {LEAN_SCALAR_PTR_LITERAL(3, 0, 0, 0, 0, 0, 0, 0)}};
static const lean_object* lp_bounded_Bounded_classifyCore___closed__3 = (const lean_object*)&lp_bounded_Bounded_classifyCore___closed__3_value;
LEAN_EXPORT lean_object* lp_bounded_Bounded_classifyCore(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_classifyCore___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_classifyIter(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_classifyIter___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_List_any___at___00Bounded_instProvided_spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_List_any___at___00Bounded_instProvided_spec__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_instProvided(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instProvided___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_List_any___at___00Bounded_satClsOf_spec__2(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_List_any___at___00Bounded_satClsOf_spec__2___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_List_any___at___00Bounded_satClsOf_spec__1(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_List_any___at___00Bounded_satClsOf_spec__1___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_List_any___at___00Bounded_satClsOf_spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_List_any___at___00Bounded_satClsOf_spec__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_satClsOf(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_satClsOf___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_isUnprovideI(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_isUnprovideI___boxed(lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_isUntrackI(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_isUntrackI___boxed(lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_isRetireChildI(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_isRetireChildI___boxed(lean_object*);
LEAN_EXPORT uint8_t lp_bounded_List_any___at___00Bounded_accClsOf_spec__1(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_List_any___at___00Bounded_accClsOf_spec__1___boxed(lean_object*);
LEAN_EXPORT uint8_t lp_bounded_List_any___at___00Bounded_accClsOf_spec__0(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_List_any___at___00Bounded_accClsOf_spec__0___boxed(lean_object*);
LEAN_EXPORT uint8_t lp_bounded_List_any___at___00Bounded_accClsOf_spec__2(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_List_any___at___00Bounded_accClsOf_spec__2___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_accClsOf(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_accClsOf___boxed(lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqSigR_decEq___lam__0(uint8_t, uint8_t, uint8_t);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqSigR_decEq___lam__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqSigR_decEq___lam__1(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqSigR_decEq___lam__1___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqSigR_decEq(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqSigR_decEq___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqSigR(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqSigR___boxed(lean_object*, lean_object*);
static const lean_string_object lp_bounded_Option_repr___at___00Bounded_instReprSigR_repr_spec__0___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "none"};
static const lean_object* lp_bounded_Option_repr___at___00Bounded_instReprSigR_repr_spec__0___closed__0 = (const lean_object*)&lp_bounded_Option_repr___at___00Bounded_instReprSigR_repr_spec__0___closed__0_value;
static const lean_ctor_object lp_bounded_Option_repr___at___00Bounded_instReprSigR_repr_spec__0___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Option_repr___at___00Bounded_instReprSigR_repr_spec__0___closed__0_value)}};
static const lean_object* lp_bounded_Option_repr___at___00Bounded_instReprSigR_repr_spec__0___closed__1 = (const lean_object*)&lp_bounded_Option_repr___at___00Bounded_instReprSigR_repr_spec__0___closed__1_value;
static const lean_string_object lp_bounded_Option_repr___at___00Bounded_instReprSigR_repr_spec__0___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "some "};
static const lean_object* lp_bounded_Option_repr___at___00Bounded_instReprSigR_repr_spec__0___closed__2 = (const lean_object*)&lp_bounded_Option_repr___at___00Bounded_instReprSigR_repr_spec__0___closed__2_value;
static const lean_ctor_object lp_bounded_Option_repr___at___00Bounded_instReprSigR_repr_spec__0___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Option_repr___at___00Bounded_instReprSigR_repr_spec__0___closed__2_value)}};
static const lean_object* lp_bounded_Option_repr___at___00Bounded_instReprSigR_repr_spec__0___closed__3 = (const lean_object*)&lp_bounded_Option_repr___at___00Bounded_instReprSigR_repr_spec__0___closed__3_value;
LEAN_EXPORT lean_object* lp_bounded_Option_repr___at___00Bounded_instReprSigR_repr_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Option_repr___at___00Bounded_instReprSigR_repr_spec__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Prod_reprTuple___at___00Prod_repr___at___00Bounded_instReprSigR_repr_spec__1_spec__1(lean_object*, lean_object*);
static const lean_string_object lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = "("};
static const lean_object* lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg___closed__0 = (const lean_object*)&lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg___closed__0_value;
static const lean_string_object lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = ","};
static const lean_object* lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg___closed__1 = (const lean_object*)&lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg___closed__1_value;
static const lean_ctor_object lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg___closed__1_value)}};
static const lean_object* lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg___closed__2 = (const lean_object*)&lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg___closed__2_value;
static const lean_ctor_object lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg___closed__2_value),((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg___closed__3 = (const lean_object*)&lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg___closed__3_value;
static const lean_string_object lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = ")"};
static const lean_object* lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg___closed__4 = (const lean_object*)&lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg___closed__4_value;
static lean_once_cell_t lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg___closed__5_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg___closed__5;
static lean_once_cell_t lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg___closed__6_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg___closed__6;
static const lean_ctor_object lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg___closed__0_value)}};
static const lean_object* lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg___closed__7 = (const lean_object*)&lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg___closed__7_value;
static const lean_ctor_object lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg___closed__4_value)}};
static const lean_object* lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg___closed__8 = (const lean_object*)&lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg___closed__8_value;
LEAN_EXPORT lean_object* lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg(lean_object*);
static const lean_string_object lp_bounded_Bounded_instReprSigR_repr___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "{ "};
static const lean_object* lp_bounded_Bounded_instReprSigR_repr___redArg___closed__0 = (const lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__0_value;
static const lean_string_object lp_bounded_Bounded_instReprSigR_repr___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "rule"};
static const lean_object* lp_bounded_Bounded_instReprSigR_repr___redArg___closed__1 = (const lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__1_value;
static const lean_ctor_object lp_bounded_Bounded_instReprSigR_repr___redArg___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__1_value)}};
static const lean_object* lp_bounded_Bounded_instReprSigR_repr___redArg___closed__2 = (const lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__2_value;
static const lean_ctor_object lp_bounded_Bounded_instReprSigR_repr___redArg___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__2_value)}};
static const lean_object* lp_bounded_Bounded_instReprSigR_repr___redArg___closed__3 = (const lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__3_value;
static const lean_string_object lp_bounded_Bounded_instReprSigR_repr___redArg___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = " := "};
static const lean_object* lp_bounded_Bounded_instReprSigR_repr___redArg___closed__4 = (const lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__4_value;
static const lean_ctor_object lp_bounded_Bounded_instReprSigR_repr___redArg___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__4_value)}};
static const lean_object* lp_bounded_Bounded_instReprSigR_repr___redArg___closed__5 = (const lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__5_value;
static const lean_ctor_object lp_bounded_Bounded_instReprSigR_repr___redArg___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__3_value),((lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__5_value)}};
static const lean_object* lp_bounded_Bounded_instReprSigR_repr___redArg___closed__6 = (const lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__6_value;
static lean_once_cell_t lp_bounded_Bounded_instReprSigR_repr___redArg___closed__7_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_instReprSigR_repr___redArg___closed__7;
static const lean_string_object lp_bounded_Bounded_instReprSigR_repr___redArg___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "present"};
static const lean_object* lp_bounded_Bounded_instReprSigR_repr___redArg___closed__8 = (const lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__8_value;
static const lean_ctor_object lp_bounded_Bounded_instReprSigR_repr___redArg___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__8_value)}};
static const lean_object* lp_bounded_Bounded_instReprSigR_repr___redArg___closed__9 = (const lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__9_value;
static lean_once_cell_t lp_bounded_Bounded_instReprSigR_repr___redArg___closed__10_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_instReprSigR_repr___redArg___closed__10;
static const lean_string_object lp_bounded_Bounded_instReprSigR_repr___redArg___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "stCls"};
static const lean_object* lp_bounded_Bounded_instReprSigR_repr___redArg___closed__11 = (const lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__11_value;
static const lean_ctor_object lp_bounded_Bounded_instReprSigR_repr___redArg___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__11_value)}};
static const lean_object* lp_bounded_Bounded_instReprSigR_repr___redArg___closed__12 = (const lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__12_value;
static lean_once_cell_t lp_bounded_Bounded_instReprSigR_repr___redArg___closed__13_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_instReprSigR_repr___redArg___closed__13;
static const lean_string_object lp_bounded_Bounded_instReprSigR_repr___redArg___closed__14_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "retiredB"};
static const lean_object* lp_bounded_Bounded_instReprSigR_repr___redArg___closed__14 = (const lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__14_value;
static const lean_ctor_object lp_bounded_Bounded_instReprSigR_repr___redArg___closed__15_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__14_value)}};
static const lean_object* lp_bounded_Bounded_instReprSigR_repr___redArg___closed__15 = (const lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__15_value;
static lean_once_cell_t lp_bounded_Bounded_instReprSigR_repr___redArg___closed__16_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_instReprSigR_repr___redArg___closed__16;
static const lean_string_object lp_bounded_Bounded_instReprSigR_repr___redArg___closed__17_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "tRel"};
static const lean_object* lp_bounded_Bounded_instReprSigR_repr___redArg___closed__17 = (const lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__17_value;
static const lean_ctor_object lp_bounded_Bounded_instReprSigR_repr___redArg___closed__18_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__17_value)}};
static const lean_object* lp_bounded_Bounded_instReprSigR_repr___redArg___closed__18 = (const lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__18_value;
static const lean_string_object lp_bounded_Bounded_instReprSigR_repr___redArg___closed__19_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "headStep"};
static const lean_object* lp_bounded_Bounded_instReprSigR_repr___redArg___closed__19 = (const lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__19_value;
static const lean_ctor_object lp_bounded_Bounded_instReprSigR_repr___redArg___closed__20_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__19_value)}};
static const lean_object* lp_bounded_Bounded_instReprSigR_repr___redArg___closed__20 = (const lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__20_value;
static const lean_string_object lp_bounded_Bounded_instReprSigR_repr___redArg___closed__21_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "remEmpty"};
static const lean_object* lp_bounded_Bounded_instReprSigR_repr___redArg___closed__21 = (const lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__21_value;
static const lean_ctor_object lp_bounded_Bounded_instReprSigR_repr___redArg___closed__22_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__21_value)}};
static const lean_object* lp_bounded_Bounded_instReprSigR_repr___redArg___closed__22 = (const lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__22_value;
static const lean_string_object lp_bounded_Bounded_instReprSigR_repr___redArg___closed__23_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "reliedB"};
static const lean_object* lp_bounded_Bounded_instReprSigR_repr___redArg___closed__23 = (const lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__23_value;
static const lean_ctor_object lp_bounded_Bounded_instReprSigR_repr___redArg___closed__24_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__23_value)}};
static const lean_object* lp_bounded_Bounded_instReprSigR_repr___redArg___closed__24 = (const lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__24_value;
static const lean_string_object lp_bounded_Bounded_instReprSigR_repr___redArg___closed__25_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "hasChild"};
static const lean_object* lp_bounded_Bounded_instReprSigR_repr___redArg___closed__25 = (const lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__25_value;
static const lean_ctor_object lp_bounded_Bounded_instReprSigR_repr___redArg___closed__26_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__25_value)}};
static const lean_object* lp_bounded_Bounded_instReprSigR_repr___redArg___closed__26 = (const lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__26_value;
static const lean_string_object lp_bounded_Bounded_instReprSigR_repr___redArg___closed__27_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "slotFree"};
static const lean_object* lp_bounded_Bounded_instReprSigR_repr___redArg___closed__27 = (const lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__27_value;
static const lean_ctor_object lp_bounded_Bounded_instReprSigR_repr___redArg___closed__28_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__27_value)}};
static const lean_object* lp_bounded_Bounded_instReprSigR_repr___redArg___closed__28 = (const lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__28_value;
static const lean_string_object lp_bounded_Bounded_instReprSigR_repr___redArg___closed__29_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "provConf"};
static const lean_object* lp_bounded_Bounded_instReprSigR_repr___redArg___closed__29 = (const lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__29_value;
static const lean_ctor_object lp_bounded_Bounded_instReprSigR_repr___redArg___closed__30_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__29_value)}};
static const lean_object* lp_bounded_Bounded_instReprSigR_repr___redArg___closed__30 = (const lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__30_value;
static const lean_string_object lp_bounded_Bounded_instReprSigR_repr___redArg___closed__31_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "parentLive"};
static const lean_object* lp_bounded_Bounded_instReprSigR_repr___redArg___closed__31 = (const lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__31_value;
static const lean_ctor_object lp_bounded_Bounded_instReprSigR_repr___redArg___closed__32_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__31_value)}};
static const lean_object* lp_bounded_Bounded_instReprSigR_repr___redArg___closed__32 = (const lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__32_value;
static lean_once_cell_t lp_bounded_Bounded_instReprSigR_repr___redArg___closed__33_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_instReprSigR_repr___redArg___closed__33;
static const lean_string_object lp_bounded_Bounded_instReprSigR_repr___redArg___closed__34_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "accCls"};
static const lean_object* lp_bounded_Bounded_instReprSigR_repr___redArg___closed__34 = (const lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__34_value;
static const lean_ctor_object lp_bounded_Bounded_instReprSigR_repr___redArg___closed__35_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__34_value)}};
static const lean_object* lp_bounded_Bounded_instReprSigR_repr___redArg___closed__35 = (const lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__35_value;
static lean_once_cell_t lp_bounded_Bounded_instReprSigR_repr___redArg___closed__36_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_instReprSigR_repr___redArg___closed__36;
static const lean_string_object lp_bounded_Bounded_instReprSigR_repr___redArg___closed__37_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "satCls"};
static const lean_object* lp_bounded_Bounded_instReprSigR_repr___redArg___closed__37 = (const lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__37_value;
static const lean_ctor_object lp_bounded_Bounded_instReprSigR_repr___redArg___closed__38_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__37_value)}};
static const lean_object* lp_bounded_Bounded_instReprSigR_repr___redArg___closed__38 = (const lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__38_value;
static const lean_string_object lp_bounded_Bounded_instReprSigR_repr___redArg___closed__39_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = " }"};
static const lean_object* lp_bounded_Bounded_instReprSigR_repr___redArg___closed__39 = (const lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__39_value;
static lean_once_cell_t lp_bounded_Bounded_instReprSigR_repr___redArg___closed__40_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_instReprSigR_repr___redArg___closed__40;
static lean_once_cell_t lp_bounded_Bounded_instReprSigR_repr___redArg___closed__41_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_instReprSigR_repr___redArg___closed__41;
static const lean_ctor_object lp_bounded_Bounded_instReprSigR_repr___redArg___closed__42_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__0_value)}};
static const lean_object* lp_bounded_Bounded_instReprSigR_repr___redArg___closed__42 = (const lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__42_value;
static const lean_ctor_object lp_bounded_Bounded_instReprSigR_repr___redArg___closed__43_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__39_value)}};
static const lean_object* lp_bounded_Bounded_instReprSigR_repr___redArg___closed__43 = (const lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__43_value;
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprSigR_repr___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprSigR_repr(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprSigR_repr___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_bounded_Bounded_instReprSigR___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_bounded_Bounded_instReprSigR_repr___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_bounded_Bounded_instReprSigR___closed__0 = (const lean_object*)&lp_bounded_Bounded_instReprSigR___closed__0_value;
LEAN_EXPORT const lean_object* lp_bounded_Bounded_instReprSigR = (const lean_object*)&lp_bounded_Bounded_instReprSigR___closed__0_value;
LEAN_EXPORT lean_object* lp_bounded_Bounded_remOf(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_accOf(lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_remEmptyOf(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_remEmptyOf___boxed(lean_object*);
static const lean_ctor_object lp_bounded_Bounded_accClsOfOpt___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_bounded_Bounded_accClsOfOpt___closed__0 = (const lean_object*)&lp_bounded_Bounded_accClsOfOpt___closed__0_value;
static const lean_ctor_object lp_bounded_Bounded_accClsOfOpt___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_bounded_Bounded_accClsOfOpt___closed__0_value)}};
static const lean_object* lp_bounded_Bounded_accClsOfOpt___closed__1 = (const lean_object*)&lp_bounded_Bounded_accClsOfOpt___closed__1_value;
LEAN_EXPORT lean_object* lp_bounded_Bounded_accClsOfOpt(lean_object*);
LEAN_EXPORT uint8_t lp_bounded_List_any___at___00Bounded_sig_spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_List_any___at___00Bounded_sig_spec__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_List_any___at___00Bounded_sig_spec__1(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_List_any___at___00Bounded_sig_spec__1___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_sig(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Variant_ctorIdx(uint8_t);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Variant_ctorIdx___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Variant_toCtorIdx(uint8_t);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Variant_toCtorIdx___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Variant_ctorElim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Variant_ctorElim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Variant_ctorElim(lean_object*, lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Variant_ctorElim___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Variant_std_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Variant_std_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Variant_std_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Variant_std_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Variant_fifoAcc_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Variant_fifoAcc_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Variant_fifoAcc_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Variant_fifoAcc_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Variant_dropAcc_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Variant_dropAcc_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Variant_dropAcc_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Variant_dropAcc_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_Variant_ofNat(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Variant_ofNat___boxed(lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqVariant(uint8_t, uint8_t);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqVariant___boxed(lean_object*, lean_object*);
static const lean_string_object lp_bounded_Bounded_instReprVariant_repr___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 20, .m_capacity = 20, .m_length = 19, .m_data = "Bounded.Variant.std"};
static const lean_object* lp_bounded_Bounded_instReprVariant_repr___closed__0 = (const lean_object*)&lp_bounded_Bounded_instReprVariant_repr___closed__0_value;
static const lean_ctor_object lp_bounded_Bounded_instReprVariant_repr___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprVariant_repr___closed__0_value)}};
static const lean_object* lp_bounded_Bounded_instReprVariant_repr___closed__1 = (const lean_object*)&lp_bounded_Bounded_instReprVariant_repr___closed__1_value;
static const lean_string_object lp_bounded_Bounded_instReprVariant_repr___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 24, .m_capacity = 24, .m_length = 23, .m_data = "Bounded.Variant.fifoAcc"};
static const lean_object* lp_bounded_Bounded_instReprVariant_repr___closed__2 = (const lean_object*)&lp_bounded_Bounded_instReprVariant_repr___closed__2_value;
static const lean_ctor_object lp_bounded_Bounded_instReprVariant_repr___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprVariant_repr___closed__2_value)}};
static const lean_object* lp_bounded_Bounded_instReprVariant_repr___closed__3 = (const lean_object*)&lp_bounded_Bounded_instReprVariant_repr___closed__3_value;
static const lean_string_object lp_bounded_Bounded_instReprVariant_repr___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 24, .m_capacity = 24, .m_length = 23, .m_data = "Bounded.Variant.dropAcc"};
static const lean_object* lp_bounded_Bounded_instReprVariant_repr___closed__4 = (const lean_object*)&lp_bounded_Bounded_instReprVariant_repr___closed__4_value;
static const lean_ctor_object lp_bounded_Bounded_instReprVariant_repr___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprVariant_repr___closed__4_value)}};
static const lean_object* lp_bounded_Bounded_instReprVariant_repr___closed__5 = (const lean_object*)&lp_bounded_Bounded_instReprVariant_repr___closed__5_value;
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprVariant_repr(uint8_t, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprVariant_repr___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_bounded_Bounded_instReprVariant___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_bounded_Bounded_instReprVariant_repr___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_bounded_Bounded_instReprVariant___closed__0 = (const lean_object*)&lp_bounded_Bounded_instReprVariant___closed__0_value;
LEAN_EXPORT const lean_object* lp_bounded_Bounded_instReprVariant = (const lean_object*)&lp_bounded_Bounded_instReprVariant___closed__0_value;
LEAN_EXPORT lean_object* lp_bounded_Bounded_Dec_ctorIdx(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Dec_ctorIdx___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Dec_ctorElim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Dec_ctorElim___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Dec_ctorElim(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Dec_ctorElim___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Dec_disabled_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Dec_disabled_elim___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Dec_disabled_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Dec_disabled_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Dec_fire_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Dec_fire_elim___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Dec_fire_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Dec_fire_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqDec_decEq(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqDec_decEq___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqDec(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqDec___boxed(lean_object*, lean_object*);
static const lean_string_object lp_bounded_Bounded_instReprDec_repr___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 21, .m_capacity = 21, .m_length = 20, .m_data = "Bounded.Dec.disabled"};
static const lean_object* lp_bounded_Bounded_instReprDec_repr___closed__0 = (const lean_object*)&lp_bounded_Bounded_instReprDec_repr___closed__0_value;
static const lean_ctor_object lp_bounded_Bounded_instReprDec_repr___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprDec_repr___closed__0_value)}};
static const lean_object* lp_bounded_Bounded_instReprDec_repr___closed__1 = (const lean_object*)&lp_bounded_Bounded_instReprDec_repr___closed__1_value;
static const lean_string_object lp_bounded_Bounded_instReprDec_repr___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 17, .m_capacity = 17, .m_length = 16, .m_data = "Bounded.Dec.fire"};
static const lean_object* lp_bounded_Bounded_instReprDec_repr___closed__2 = (const lean_object*)&lp_bounded_Bounded_instReprDec_repr___closed__2_value;
static const lean_ctor_object lp_bounded_Bounded_instReprDec_repr___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprDec_repr___closed__2_value)}};
static const lean_object* lp_bounded_Bounded_instReprDec_repr___closed__3 = (const lean_object*)&lp_bounded_Bounded_instReprDec_repr___closed__3_value;
static const lean_ctor_object lp_bounded_Bounded_instReprDec_repr___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprDec_repr___closed__3_value),((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* lp_bounded_Bounded_instReprDec_repr___closed__4 = (const lean_object*)&lp_bounded_Bounded_instReprDec_repr___closed__4_value;
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprDec_repr(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprDec_repr___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_bounded_Bounded_instReprDec___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_bounded_Bounded_instReprDec_repr___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_bounded_Bounded_instReprDec___closed__0 = (const lean_object*)&lp_bounded_Bounded_instReprDec___closed__0_value;
LEAN_EXPORT const lean_object* lp_bounded_Bounded_instReprDec = (const lean_object*)&lp_bounded_Bounded_instReprDec___closed__0_value;
static const lean_ctor_object lp_bounded_Bounded_instFinEnumVariant___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(2) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_bounded_Bounded_instFinEnumVariant___closed__0 = (const lean_object*)&lp_bounded_Bounded_instFinEnumVariant___closed__0_value;
static const lean_ctor_object lp_bounded_Bounded_instFinEnumVariant___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(1) << 1) | 1)),((lean_object*)&lp_bounded_Bounded_instFinEnumVariant___closed__0_value)}};
static const lean_object* lp_bounded_Bounded_instFinEnumVariant___closed__1 = (const lean_object*)&lp_bounded_Bounded_instFinEnumVariant___closed__1_value;
static const lean_ctor_object lp_bounded_Bounded_instFinEnumVariant___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_bounded_Bounded_instFinEnumVariant___closed__1_value)}};
static const lean_object* lp_bounded_Bounded_instFinEnumVariant___closed__2 = (const lean_object*)&lp_bounded_Bounded_instFinEnumVariant___closed__2_value;
LEAN_EXPORT const lean_object* lp_bounded_Bounded_instFinEnumVariant = (const lean_object*)&lp_bounded_Bounded_instFinEnumVariant___closed__2_value;
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumDec___lam__0(uint8_t);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumDec___lam__0___boxed(lean_object*);
static const lean_closure_object lp_bounded_Bounded_instFinEnumDec___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_bounded_Bounded_instFinEnumDec___lam__0___boxed, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_bounded_Bounded_instFinEnumDec___closed__0 = (const lean_object*)&lp_bounded_Bounded_instFinEnumDec___closed__0_value;
static lean_once_cell_t lp_bounded_Bounded_instFinEnumDec___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_instFinEnumDec___closed__1;
static lean_once_cell_t lp_bounded_Bounded_instFinEnumDec___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_instFinEnumDec___closed__2;
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumDec;
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_allDecs_spec__0(lean_object*, lean_object*);
static lean_once_cell_t lp_bounded_Bounded_allDecs___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_allDecs___closed__0;
static lean_once_cell_t lp_bounded_Bounded_allDecs___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_allDecs___closed__1;
LEAN_EXPORT lean_object* lp_bounded_Bounded_allDecs;
LEAN_EXPORT uint8_t lp_bounded_Bounded_headOkB(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_headOkB___boxed(lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_headFailB(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_headFailB___boxed(lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_enabledS(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_enabledS___boxed(lean_object*);
static const lean_ctor_object lp_bounded_Bounded_fS___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*0 + 8, .m_other = 0, .m_tag = 1}, .m_objs = {LEAN_SCALAR_PTR_LITERAL(0, 0, 0, 0, 0, 0, 0, 0)}};
static const lean_object* lp_bounded_Bounded_fS___closed__0 = (const lean_object*)&lp_bounded_Bounded_fS___closed__0_value;
LEAN_EXPORT lean_object* lp_bounded_Bounded_fS(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_fS___boxed(lean_object*);
static const lean_ctor_object lp_bounded_Bounded_freshFiber___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_bounded_Bounded_freshFiber___closed__0 = (const lean_object*)&lp_bounded_Bounded_freshFiber___closed__0_value;
static const lean_ctor_object lp_bounded_Bounded_freshFiber___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*0 + 8, .m_other = 0, .m_tag = 0}, .m_objs = {LEAN_SCALAR_PTR_LITERAL(0, 0, 0, 0, 0, 0, 0, 0)}};
static const lean_object* lp_bounded_Bounded_freshFiber___closed__1 = (const lean_object*)&lp_bounded_Bounded_freshFiber___closed__1_value;
LEAN_EXPORT lean_object* lp_bounded_Bounded_freshFiber(lean_object*, lean_object*);
static const lean_ctor_object lp_bounded_Bounded_childComp___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_bounded_Bounded_childComp___closed__0 = (const lean_object*)&lp_bounded_Bounded_childComp___closed__0_value;
static lean_once_cell_t lp_bounded_Bounded_childComp___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_childComp___closed__1;
static lean_once_cell_t lp_bounded_Bounded_childComp___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_childComp___closed__2;
static lean_once_cell_t lp_bounded_Bounded_childComp___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_childComp___closed__3;
static const lean_ctor_object lp_bounded_Bounded_childComp___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(5) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_bounded_Bounded_childComp___closed__4 = (const lean_object*)&lp_bounded_Bounded_childComp___closed__4_value;
static lean_once_cell_t lp_bounded_Bounded_childComp___closed__5_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_childComp___closed__5;
static lean_once_cell_t lp_bounded_Bounded_childComp___closed__6_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_childComp___closed__6;
static lean_once_cell_t lp_bounded_Bounded_childComp___closed__7_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_childComp___closed__7;
LEAN_EXPORT lean_object* lp_bounded_Bounded_childComp;
LEAN_EXPORT lean_object* lp_bounded_Bounded_execStep(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_applyInv(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_applyInv___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_List_foldl___at___00Bounded_liftStep_spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_List_foldl___at___00Bounded_liftStep_spec__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_liftStep(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_specStep(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_ctorIdx(uint8_t);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_ctorIdx___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_toCtorIdx(uint8_t);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_toCtorIdx___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_ctorElim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_ctorElim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_ctorElim(lean_object*, lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_ctorElim___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_absent_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_absent_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_absent_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_absent_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_pending_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_pending_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_pending_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_pending_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_failed_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_failed_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_failed_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_failed_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_loading_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_loading_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_loading_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_loading_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_activeS_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_activeS_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_activeS_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_activeS_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_unloadingS_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_unloadingS_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_unloadingS_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_unloadingS_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_Status_ofNat(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_ofNat___boxed(lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqStatus(uint8_t, uint8_t);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqStatus___boxed(lean_object*, lean_object*);
static const lean_string_object lp_bounded_Bounded_instReprStatus_repr___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 22, .m_capacity = 22, .m_length = 21, .m_data = "Bounded.Status.absent"};
static const lean_object* lp_bounded_Bounded_instReprStatus_repr___closed__0 = (const lean_object*)&lp_bounded_Bounded_instReprStatus_repr___closed__0_value;
static const lean_ctor_object lp_bounded_Bounded_instReprStatus_repr___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprStatus_repr___closed__0_value)}};
static const lean_object* lp_bounded_Bounded_instReprStatus_repr___closed__1 = (const lean_object*)&lp_bounded_Bounded_instReprStatus_repr___closed__1_value;
static const lean_string_object lp_bounded_Bounded_instReprStatus_repr___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 23, .m_capacity = 23, .m_length = 22, .m_data = "Bounded.Status.pending"};
static const lean_object* lp_bounded_Bounded_instReprStatus_repr___closed__2 = (const lean_object*)&lp_bounded_Bounded_instReprStatus_repr___closed__2_value;
static const lean_ctor_object lp_bounded_Bounded_instReprStatus_repr___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprStatus_repr___closed__2_value)}};
static const lean_object* lp_bounded_Bounded_instReprStatus_repr___closed__3 = (const lean_object*)&lp_bounded_Bounded_instReprStatus_repr___closed__3_value;
static const lean_string_object lp_bounded_Bounded_instReprStatus_repr___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 22, .m_capacity = 22, .m_length = 21, .m_data = "Bounded.Status.failed"};
static const lean_object* lp_bounded_Bounded_instReprStatus_repr___closed__4 = (const lean_object*)&lp_bounded_Bounded_instReprStatus_repr___closed__4_value;
static const lean_ctor_object lp_bounded_Bounded_instReprStatus_repr___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprStatus_repr___closed__4_value)}};
static const lean_object* lp_bounded_Bounded_instReprStatus_repr___closed__5 = (const lean_object*)&lp_bounded_Bounded_instReprStatus_repr___closed__5_value;
static const lean_string_object lp_bounded_Bounded_instReprStatus_repr___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 23, .m_capacity = 23, .m_length = 22, .m_data = "Bounded.Status.loading"};
static const lean_object* lp_bounded_Bounded_instReprStatus_repr___closed__6 = (const lean_object*)&lp_bounded_Bounded_instReprStatus_repr___closed__6_value;
static const lean_ctor_object lp_bounded_Bounded_instReprStatus_repr___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprStatus_repr___closed__6_value)}};
static const lean_object* lp_bounded_Bounded_instReprStatus_repr___closed__7 = (const lean_object*)&lp_bounded_Bounded_instReprStatus_repr___closed__7_value;
static const lean_string_object lp_bounded_Bounded_instReprStatus_repr___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 23, .m_capacity = 23, .m_length = 22, .m_data = "Bounded.Status.activeS"};
static const lean_object* lp_bounded_Bounded_instReprStatus_repr___closed__8 = (const lean_object*)&lp_bounded_Bounded_instReprStatus_repr___closed__8_value;
static const lean_ctor_object lp_bounded_Bounded_instReprStatus_repr___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprStatus_repr___closed__8_value)}};
static const lean_object* lp_bounded_Bounded_instReprStatus_repr___closed__9 = (const lean_object*)&lp_bounded_Bounded_instReprStatus_repr___closed__9_value;
static const lean_string_object lp_bounded_Bounded_instReprStatus_repr___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 26, .m_capacity = 26, .m_length = 25, .m_data = "Bounded.Status.unloadingS"};
static const lean_object* lp_bounded_Bounded_instReprStatus_repr___closed__10 = (const lean_object*)&lp_bounded_Bounded_instReprStatus_repr___closed__10_value;
static const lean_ctor_object lp_bounded_Bounded_instReprStatus_repr___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprStatus_repr___closed__10_value)}};
static const lean_object* lp_bounded_Bounded_instReprStatus_repr___closed__11 = (const lean_object*)&lp_bounded_Bounded_instReprStatus_repr___closed__11_value;
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprStatus_repr(uint8_t, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprStatus_repr___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_bounded_Bounded_instReprStatus___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_bounded_Bounded_instReprStatus_repr___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_bounded_Bounded_instReprStatus___closed__0 = (const lean_object*)&lp_bounded_Bounded_instReprStatus___closed__0_value;
LEAN_EXPORT const lean_object* lp_bounded_Bounded_instReprStatus = (const lean_object*)&lp_bounded_Bounded_instReprStatus___closed__0_value;
static const lean_ctor_object lp_bounded_Bounded_statusOf___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_bounded_Bounded_statusOf___closed__0 = (const lean_object*)&lp_bounded_Bounded_statusOf___closed__0_value;
LEAN_EXPORT lean_object* lp_bounded_Bounded_statusOf(lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqObs_decEq___lam__0(uint8_t, uint8_t);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqObs_decEq___lam__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqObs_decEq___lam__1(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqObs_decEq___lam__1___boxed(lean_object*, lean_object*, lean_object*);
static const lean_closure_object lp_bounded_Bounded_instDecidableEqObs_decEq___lam__2___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*1, .m_other = 0, .m_tag = 245}, .m_fun = (void*)l_instDecidableEqFin___boxed, .m_arity = 3, .m_num_fixed = 1, .m_objs = {((lean_object*)(((size_t)(2) << 1) | 1))} };
static const lean_object* lp_bounded_Bounded_instDecidableEqObs_decEq___lam__2___closed__0 = (const lean_object*)&lp_bounded_Bounded_instDecidableEqObs_decEq___lam__2___closed__0_value;
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqObs_decEq___lam__2(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqObs_decEq___lam__2___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_bounded_Bounded_instDecidableEqObs_decEq___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_bounded_Bounded_instDecidableEqObs_decEq___lam__0___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_bounded_Bounded_instDecidableEqObs_decEq___closed__0 = (const lean_object*)&lp_bounded_Bounded_instDecidableEqObs_decEq___closed__0_value;
static const lean_closure_object lp_bounded_Bounded_instDecidableEqObs_decEq___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*1, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_bounded_Bounded_instDecidableEqObs_decEq___lam__1___boxed, .m_arity = 3, .m_num_fixed = 1, .m_objs = {((lean_object*)&lp_bounded_Bounded_instDecidableEqObs_decEq___closed__0_value)} };
static const lean_object* lp_bounded_Bounded_instDecidableEqObs_decEq___closed__1 = (const lean_object*)&lp_bounded_Bounded_instDecidableEqObs_decEq___closed__1_value;
static const lean_closure_object lp_bounded_Bounded_instDecidableEqObs_decEq___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_bounded_Bounded_instDecidableEqObs_decEq___lam__2___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_bounded_Bounded_instDecidableEqObs_decEq___closed__2 = (const lean_object*)&lp_bounded_Bounded_instDecidableEqObs_decEq___closed__2_value;
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqObs_decEq(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqObs_decEq___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqObs(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqObs___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Prod_repr___at___00Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0_spec__0___redArg(lean_object*);
static const lean_string_object lp_bounded_Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "s0"};
static const lean_object* lp_bounded_Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0___redArg___closed__0 = (const lean_object*)&lp_bounded_Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0___redArg___closed__0_value;
static const lean_ctor_object lp_bounded_Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0___redArg___closed__0_value)}};
static const lean_object* lp_bounded_Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0___redArg___closed__1 = (const lean_object*)&lp_bounded_Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0___redArg___closed__1_value;
static const lean_ctor_object lp_bounded_Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0___redArg___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_bounded_Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0___redArg___closed__1_value)}};
static const lean_object* lp_bounded_Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0___redArg___closed__2 = (const lean_object*)&lp_bounded_Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0___redArg___closed__2_value;
static const lean_ctor_object lp_bounded_Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0___redArg___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0___redArg___closed__2_value),((lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__5_value)}};
static const lean_object* lp_bounded_Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0___redArg___closed__3 = (const lean_object*)&lp_bounded_Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0___redArg___closed__3_value;
static lean_once_cell_t lp_bounded_Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0___redArg___closed__4_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0___redArg___closed__4;
static const lean_string_object lp_bounded_Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0___redArg___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "s1"};
static const lean_object* lp_bounded_Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0___redArg___closed__5 = (const lean_object*)&lp_bounded_Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0___redArg___closed__5_value;
static const lean_ctor_object lp_bounded_Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0___redArg___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0___redArg___closed__5_value)}};
static const lean_object* lp_bounded_Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0___redArg___closed__6 = (const lean_object*)&lp_bounded_Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0___redArg___closed__6_value;
static const lean_string_object lp_bounded_Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0___redArg___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "s2"};
static const lean_object* lp_bounded_Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0___redArg___closed__7 = (const lean_object*)&lp_bounded_Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0___redArg___closed__7_value;
static const lean_ctor_object lp_bounded_Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0___redArg___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0___redArg___closed__7_value)}};
static const lean_object* lp_bounded_Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0___redArg___closed__8 = (const lean_object*)&lp_bounded_Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0___redArg___closed__8_value;
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Option_repr___at___00Bounded_instReprKMap_repr___at___00Bounded_instReprObs_repr_spec__1_spec__2(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Option_repr___at___00Bounded_instReprKMap_repr___at___00Bounded_instReprObs_repr_spec__1_spec__2___boxed(lean_object*, lean_object*);
static const lean_string_object lp_bounded_Bounded_instReprKMap_repr___at___00Bounded_instReprObs_repr_spec__1___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "k0"};
static const lean_object* lp_bounded_Bounded_instReprKMap_repr___at___00Bounded_instReprObs_repr_spec__1___redArg___closed__0 = (const lean_object*)&lp_bounded_Bounded_instReprKMap_repr___at___00Bounded_instReprObs_repr_spec__1___redArg___closed__0_value;
static const lean_ctor_object lp_bounded_Bounded_instReprKMap_repr___at___00Bounded_instReprObs_repr_spec__1___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprKMap_repr___at___00Bounded_instReprObs_repr_spec__1___redArg___closed__0_value)}};
static const lean_object* lp_bounded_Bounded_instReprKMap_repr___at___00Bounded_instReprObs_repr_spec__1___redArg___closed__1 = (const lean_object*)&lp_bounded_Bounded_instReprKMap_repr___at___00Bounded_instReprObs_repr_spec__1___redArg___closed__1_value;
static const lean_ctor_object lp_bounded_Bounded_instReprKMap_repr___at___00Bounded_instReprObs_repr_spec__1___redArg___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_bounded_Bounded_instReprKMap_repr___at___00Bounded_instReprObs_repr_spec__1___redArg___closed__1_value)}};
static const lean_object* lp_bounded_Bounded_instReprKMap_repr___at___00Bounded_instReprObs_repr_spec__1___redArg___closed__2 = (const lean_object*)&lp_bounded_Bounded_instReprKMap_repr___at___00Bounded_instReprObs_repr_spec__1___redArg___closed__2_value;
static const lean_ctor_object lp_bounded_Bounded_instReprKMap_repr___at___00Bounded_instReprObs_repr_spec__1___redArg___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprKMap_repr___at___00Bounded_instReprObs_repr_spec__1___redArg___closed__2_value),((lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__5_value)}};
static const lean_object* lp_bounded_Bounded_instReprKMap_repr___at___00Bounded_instReprObs_repr_spec__1___redArg___closed__3 = (const lean_object*)&lp_bounded_Bounded_instReprKMap_repr___at___00Bounded_instReprObs_repr_spec__1___redArg___closed__3_value;
static const lean_string_object lp_bounded_Bounded_instReprKMap_repr___at___00Bounded_instReprObs_repr_spec__1___redArg___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "k1"};
static const lean_object* lp_bounded_Bounded_instReprKMap_repr___at___00Bounded_instReprObs_repr_spec__1___redArg___closed__4 = (const lean_object*)&lp_bounded_Bounded_instReprKMap_repr___at___00Bounded_instReprObs_repr_spec__1___redArg___closed__4_value;
static const lean_ctor_object lp_bounded_Bounded_instReprKMap_repr___at___00Bounded_instReprObs_repr_spec__1___redArg___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprKMap_repr___at___00Bounded_instReprObs_repr_spec__1___redArg___closed__4_value)}};
static const lean_object* lp_bounded_Bounded_instReprKMap_repr___at___00Bounded_instReprObs_repr_spec__1___redArg___closed__5 = (const lean_object*)&lp_bounded_Bounded_instReprKMap_repr___at___00Bounded_instReprObs_repr_spec__1___redArg___closed__5_value;
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprKMap_repr___at___00Bounded_instReprObs_repr_spec__1___redArg(lean_object*);
static const lean_string_object lp_bounded_Bounded_instReprObs_repr___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "statuses"};
static const lean_object* lp_bounded_Bounded_instReprObs_repr___redArg___closed__0 = (const lean_object*)&lp_bounded_Bounded_instReprObs_repr___redArg___closed__0_value;
static const lean_ctor_object lp_bounded_Bounded_instReprObs_repr___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprObs_repr___redArg___closed__0_value)}};
static const lean_object* lp_bounded_Bounded_instReprObs_repr___redArg___closed__1 = (const lean_object*)&lp_bounded_Bounded_instReprObs_repr___redArg___closed__1_value;
static const lean_ctor_object lp_bounded_Bounded_instReprObs_repr___redArg___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_bounded_Bounded_instReprObs_repr___redArg___closed__1_value)}};
static const lean_object* lp_bounded_Bounded_instReprObs_repr___redArg___closed__2 = (const lean_object*)&lp_bounded_Bounded_instReprObs_repr___redArg___closed__2_value;
static const lean_ctor_object lp_bounded_Bounded_instReprObs_repr___redArg___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprObs_repr___redArg___closed__2_value),((lean_object*)&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__5_value)}};
static const lean_object* lp_bounded_Bounded_instReprObs_repr___redArg___closed__3 = (const lean_object*)&lp_bounded_Bounded_instReprObs_repr___redArg___closed__3_value;
static const lean_string_object lp_bounded_Bounded_instReprObs_repr___redArg___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "store"};
static const lean_object* lp_bounded_Bounded_instReprObs_repr___redArg___closed__4 = (const lean_object*)&lp_bounded_Bounded_instReprObs_repr___redArg___closed__4_value;
static const lean_ctor_object lp_bounded_Bounded_instReprObs_repr___redArg___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprObs_repr___redArg___closed__4_value)}};
static const lean_object* lp_bounded_Bounded_instReprObs_repr___redArg___closed__5 = (const lean_object*)&lp_bounded_Bounded_instReprObs_repr___redArg___closed__5_value;
static const lean_string_object lp_bounded_Bounded_instReprObs_repr___redArg___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 10, .m_capacity = 10, .m_length = 9, .m_data = "quiescent"};
static const lean_object* lp_bounded_Bounded_instReprObs_repr___redArg___closed__6 = (const lean_object*)&lp_bounded_Bounded_instReprObs_repr___redArg___closed__6_value;
static const lean_ctor_object lp_bounded_Bounded_instReprObs_repr___redArg___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_bounded_Bounded_instReprObs_repr___redArg___closed__6_value)}};
static const lean_object* lp_bounded_Bounded_instReprObs_repr___redArg___closed__7 = (const lean_object*)&lp_bounded_Bounded_instReprObs_repr___redArg___closed__7_value;
static lean_once_cell_t lp_bounded_Bounded_instReprObs_repr___redArg___closed__8_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_instReprObs_repr___redArg___closed__8;
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprObs_repr___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprObs_repr(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprObs_repr___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprKMap_repr___at___00Bounded_instReprObs_repr_spec__1(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprKMap_repr___at___00Bounded_instReprObs_repr_spec__1___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Prod_repr___at___00Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Prod_repr___at___00Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0_spec__0___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_bounded_Bounded_instReprObs___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_bounded_Bounded_instReprObs_repr___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_bounded_Bounded_instReprObs___closed__0 = (const lean_object*)&lp_bounded_Bounded_instReprObs___closed__0_value;
LEAN_EXPORT const lean_object* lp_bounded_Bounded_instReprObs = (const lean_object*)&lp_bounded_Bounded_instReprObs___closed__0_value;
static lean_once_cell_t lp_bounded_Bounded_obs___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_obs___closed__0;
static lean_once_cell_t lp_bounded_Bounded_obs___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_obs___closed__1;
static lean_once_cell_t lp_bounded_Bounded_obs___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_obs___closed__2;
LEAN_EXPORT lean_object* lp_bounded_Bounded_obs(lean_object*);
LEAN_EXPORT lean_object* lp_bounded_Bounded_obsRow(lean_object*);
static const lean_ctor_object lp_bounded_Bounded_cProv___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)(((size_t)(1) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_bounded_Bounded_cProv___closed__0 = (const lean_object*)&lp_bounded_Bounded_cProv___closed__0_value;
static lean_once_cell_t lp_bounded_Bounded_cProv___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_cProv___closed__1;
static lean_once_cell_t lp_bounded_Bounded_cProv___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_cProv___closed__2;
static lean_once_cell_t lp_bounded_Bounded_cProv___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_cProv___closed__3;
LEAN_EXPORT lean_object* lp_bounded_Bounded_cProv;
static lean_once_cell_t lp_bounded_Bounded_cCons___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_cCons___closed__0;
static lean_once_cell_t lp_bounded_Bounded_cCons___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_cCons___closed__1;
static lean_once_cell_t lp_bounded_Bounded_cCons___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_cCons___closed__2;
static lean_once_cell_t lp_bounded_Bounded_cCons___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_cCons___closed__3;
static lean_once_cell_t lp_bounded_Bounded_cCons___closed__4_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_cCons___closed__4;
static lean_once_cell_t lp_bounded_Bounded_cCons___closed__5_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_cCons___closed__5;
LEAN_EXPORT lean_object* lp_bounded_Bounded_cCons;
static const lean_ctor_object lp_bounded_Bounded_cReg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(4) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_bounded_Bounded_cReg___closed__0 = (const lean_object*)&lp_bounded_Bounded_cReg___closed__0_value;
static const lean_ctor_object lp_bounded_Bounded_cReg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*3 + 0, .m_other = 3, .m_tag = 0}, .m_objs = {((lean_object*)&lp_bounded_Bounded_cProv___closed__0_value),((lean_object*)&lp_bounded_Bounded_childComp___closed__0_value),((lean_object*)&lp_bounded_Bounded_cReg___closed__0_value)}};
static const lean_object* lp_bounded_Bounded_cReg___closed__1 = (const lean_object*)&lp_bounded_Bounded_cReg___closed__1_value;
LEAN_EXPORT const lean_object* lp_bounded_Bounded_cReg = (const lean_object*)&lp_bounded_Bounded_cReg___closed__1_value;
static const lean_ctor_object lp_bounded_Bounded_catalog___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_bounded_Bounded_cReg___closed__1_value),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_bounded_Bounded_catalog___closed__0 = (const lean_object*)&lp_bounded_Bounded_catalog___closed__0_value;
static lean_once_cell_t lp_bounded_Bounded_catalog___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_catalog___closed__1;
static lean_once_cell_t lp_bounded_Bounded_catalog___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_catalog___closed__2;
LEAN_EXPORT lean_object* lp_bounded_Bounded_catalog;
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_catalogActs_spec__12(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_catalogActs_spec__5(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_catalogActs_spec__1(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_catalogActs_spec__2(lean_object*, lean_object*, lean_object*);
static lean_once_cell_t lp_bounded___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Bounded_catalogActs_spec__7___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Bounded_catalogActs_spec__7___closed__0;
static lean_once_cell_t lp_bounded___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Bounded_catalogActs_spec__7___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Bounded_catalogActs_spec__7___closed__1;
LEAN_EXPORT lean_object* lp_bounded___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Bounded_catalogActs_spec__7(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_catalogActs_spec__4(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_catalogActs_spec__11(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_catalogActs_spec__10(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_catalogActs_spec__9(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_catalogActs_spec__8(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_catalogActs_spec__6(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_catalogActs_spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_bounded___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Bounded_catalogActs_spec__3(lean_object*, lean_object*);
static const lean_array_object lp_bounded_Bounded_catalogActs___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* lp_bounded_Bounded_catalogActs___closed__0 = (const lean_object*)&lp_bounded_Bounded_catalogActs___closed__0_value;
static lean_once_cell_t lp_bounded_Bounded_catalogActs___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_catalogActs___closed__1;
static lean_once_cell_t lp_bounded_Bounded_catalogActs___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_catalogActs___closed__2;
static lean_once_cell_t lp_bounded_Bounded_catalogActs___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_catalogActs___closed__3;
static lean_once_cell_t lp_bounded_Bounded_catalogActs___closed__4_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_catalogActs___closed__4;
static lean_once_cell_t lp_bounded_Bounded_catalogActs___closed__5_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_catalogActs___closed__5;
static lean_once_cell_t lp_bounded_Bounded_catalogActs___closed__6_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_catalogActs___closed__6;
static lean_once_cell_t lp_bounded_Bounded_catalogActs___closed__7_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_catalogActs___closed__7;
static lean_once_cell_t lp_bounded_Bounded_catalogActs___closed__8_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_catalogActs___closed__8;
static lean_once_cell_t lp_bounded_Bounded_catalogActs___closed__9_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_catalogActs___closed__9;
static lean_once_cell_t lp_bounded_Bounded_catalogActs___closed__10_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_catalogActs___closed__10;
static lean_once_cell_t lp_bounded_Bounded_catalogActs___closed__11_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_catalogActs___closed__11;
static lean_once_cell_t lp_bounded_Bounded_catalogActs___closed__12_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_catalogActs___closed__12;
static lean_once_cell_t lp_bounded_Bounded_catalogActs___closed__13_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_catalogActs___closed__13;
static lean_once_cell_t lp_bounded_Bounded_catalogActs___closed__14_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_catalogActs___closed__14;
static lean_once_cell_t lp_bounded_Bounded_catalogActs___closed__15_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_catalogActs___closed__15;
static lean_once_cell_t lp_bounded_Bounded_catalogActs___closed__16_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_catalogActs___closed__16;
static lean_once_cell_t lp_bounded_Bounded_catalogActs___closed__17_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_catalogActs___closed__17;
static lean_once_cell_t lp_bounded_Bounded_catalogActs___closed__18_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_catalogActs___closed__18;
static lean_once_cell_t lp_bounded_Bounded_catalogActs___closed__19_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_bounded_Bounded_catalogActs___closed__19;
LEAN_EXPORT lean_object* lp_bounded_Bounded_catalogActs;
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_ctorIdx(uint8_t v_x_1_){
_start:
{
switch(v_x_1_)
{
case 0:
{
lean_object* v___x_2_; 
v___x_2_ = lean_unsigned_to_nat(0u);
return v___x_2_;
}
case 1:
{
lean_object* v___x_3_; 
v___x_3_ = lean_unsigned_to_nat(1u);
return v___x_3_;
}
case 2:
{
lean_object* v___x_4_; 
v___x_4_ = lean_unsigned_to_nat(2u);
return v___x_4_;
}
case 3:
{
lean_object* v___x_5_; 
v___x_5_ = lean_unsigned_to_nat(3u);
return v___x_5_;
}
case 4:
{
lean_object* v___x_6_; 
v___x_6_ = lean_unsigned_to_nat(4u);
return v___x_6_;
}
case 5:
{
lean_object* v___x_7_; 
v___x_7_ = lean_unsigned_to_nat(5u);
return v___x_7_;
}
case 6:
{
lean_object* v___x_8_; 
v___x_8_ = lean_unsigned_to_nat(6u);
return v___x_8_;
}
case 7:
{
lean_object* v___x_9_; 
v___x_9_ = lean_unsigned_to_nat(7u);
return v___x_9_;
}
case 8:
{
lean_object* v___x_10_; 
v___x_10_ = lean_unsigned_to_nat(8u);
return v___x_10_;
}
default: 
{
lean_object* v___x_11_; 
v___x_11_ = lean_unsigned_to_nat(9u);
return v___x_11_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_ctorIdx___boxed(lean_object* v_x_12_){
_start:
{
uint8_t v_x_boxed_13_; lean_object* v_res_14_; 
v_x_boxed_13_ = lean_unbox(v_x_12_);
v_res_14_ = lp_bounded_Bounded_Rule_ctorIdx(v_x_boxed_13_);
return v_res_14_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_toCtorIdx(uint8_t v_x_15_){
_start:
{
lean_object* v___x_16_; 
v___x_16_ = lp_bounded_Bounded_Rule_ctorIdx(v_x_15_);
return v___x_16_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_toCtorIdx___boxed(lean_object* v_x_17_){
_start:
{
uint8_t v_x_4__boxed_18_; lean_object* v_res_19_; 
v_x_4__boxed_18_ = lean_unbox(v_x_17_);
v_res_19_ = lp_bounded_Bounded_Rule_toCtorIdx(v_x_4__boxed_18_);
return v_res_19_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_ctorElim___redArg(lean_object* v_k_20_){
_start:
{
lean_inc(v_k_20_);
return v_k_20_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_ctorElim___redArg___boxed(lean_object* v_k_21_){
_start:
{
lean_object* v_res_22_; 
v_res_22_ = lp_bounded_Bounded_Rule_ctorElim___redArg(v_k_21_);
lean_dec(v_k_21_);
return v_res_22_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_ctorElim(lean_object* v_motive_23_, lean_object* v_ctorIdx_24_, uint8_t v_t_25_, lean_object* v_h_26_, lean_object* v_k_27_){
_start:
{
lean_inc(v_k_27_);
return v_k_27_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_ctorElim___boxed(lean_object* v_motive_28_, lean_object* v_ctorIdx_29_, lean_object* v_t_30_, lean_object* v_h_31_, lean_object* v_k_32_){
_start:
{
uint8_t v_t_boxed_33_; lean_object* v_res_34_; 
v_t_boxed_33_ = lean_unbox(v_t_30_);
v_res_34_ = lp_bounded_Bounded_Rule_ctorElim(v_motive_28_, v_ctorIdx_29_, v_t_boxed_33_, v_h_31_, v_k_32_);
lean_dec(v_k_32_);
lean_dec(v_ctorIdx_29_);
return v_res_34_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_oInsert_elim___redArg(lean_object* v_oInsert_35_){
_start:
{
lean_inc(v_oInsert_35_);
return v_oInsert_35_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_oInsert_elim___redArg___boxed(lean_object* v_oInsert_36_){
_start:
{
lean_object* v_res_37_; 
v_res_37_ = lp_bounded_Bounded_Rule_oInsert_elim___redArg(v_oInsert_36_);
lean_dec(v_oInsert_36_);
return v_res_37_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_oInsert_elim(lean_object* v_motive_38_, uint8_t v_t_39_, lean_object* v_h_40_, lean_object* v_oInsert_41_){
_start:
{
lean_inc(v_oInsert_41_);
return v_oInsert_41_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_oInsert_elim___boxed(lean_object* v_motive_42_, lean_object* v_t_43_, lean_object* v_h_44_, lean_object* v_oInsert_45_){
_start:
{
uint8_t v_t_boxed_46_; lean_object* v_res_47_; 
v_t_boxed_46_ = lean_unbox(v_t_43_);
v_res_47_ = lp_bounded_Bounded_Rule_oInsert_elim(v_motive_42_, v_t_boxed_46_, v_h_44_, v_oInsert_45_);
lean_dec(v_oInsert_45_);
return v_res_47_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_oRetire_elim___redArg(lean_object* v_oRetire_48_){
_start:
{
lean_inc(v_oRetire_48_);
return v_oRetire_48_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_oRetire_elim___redArg___boxed(lean_object* v_oRetire_49_){
_start:
{
lean_object* v_res_50_; 
v_res_50_ = lp_bounded_Bounded_Rule_oRetire_elim___redArg(v_oRetire_49_);
lean_dec(v_oRetire_49_);
return v_res_50_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_oRetire_elim(lean_object* v_motive_51_, uint8_t v_t_52_, lean_object* v_h_53_, lean_object* v_oRetire_54_){
_start:
{
lean_inc(v_oRetire_54_);
return v_oRetire_54_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_oRetire_elim___boxed(lean_object* v_motive_55_, lean_object* v_t_56_, lean_object* v_h_57_, lean_object* v_oRetire_58_){
_start:
{
uint8_t v_t_boxed_59_; lean_object* v_res_60_; 
v_t_boxed_59_ = lean_unbox(v_t_56_);
v_res_60_ = lp_bounded_Bounded_Rule_oRetire_elim(v_motive_55_, v_t_boxed_59_, v_h_57_, v_oRetire_58_);
lean_dec(v_oRetire_58_);
return v_res_60_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_oRemove_elim___redArg(lean_object* v_oRemove_61_){
_start:
{
lean_inc(v_oRemove_61_);
return v_oRemove_61_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_oRemove_elim___redArg___boxed(lean_object* v_oRemove_62_){
_start:
{
lean_object* v_res_63_; 
v_res_63_ = lp_bounded_Bounded_Rule_oRemove_elim___redArg(v_oRemove_62_);
lean_dec(v_oRemove_62_);
return v_res_63_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_oRemove_elim(lean_object* v_motive_64_, uint8_t v_t_65_, lean_object* v_h_66_, lean_object* v_oRemove_67_){
_start:
{
lean_inc(v_oRemove_67_);
return v_oRemove_67_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_oRemove_elim___boxed(lean_object* v_motive_68_, lean_object* v_t_69_, lean_object* v_h_70_, lean_object* v_oRemove_71_){
_start:
{
uint8_t v_t_boxed_72_; lean_object* v_res_73_; 
v_t_boxed_72_ = lean_unbox(v_t_69_);
v_res_73_ = lp_bounded_Bounded_Rule_oRemove_elim(v_motive_68_, v_t_boxed_72_, v_h_70_, v_oRemove_71_);
lean_dec(v_oRemove_71_);
return v_res_73_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lBegin_elim___redArg(lean_object* v_lBegin_74_){
_start:
{
lean_inc(v_lBegin_74_);
return v_lBegin_74_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lBegin_elim___redArg___boxed(lean_object* v_lBegin_75_){
_start:
{
lean_object* v_res_76_; 
v_res_76_ = lp_bounded_Bounded_Rule_lBegin_elim___redArg(v_lBegin_75_);
lean_dec(v_lBegin_75_);
return v_res_76_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lBegin_elim(lean_object* v_motive_77_, uint8_t v_t_78_, lean_object* v_h_79_, lean_object* v_lBegin_80_){
_start:
{
lean_inc(v_lBegin_80_);
return v_lBegin_80_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lBegin_elim___boxed(lean_object* v_motive_81_, lean_object* v_t_82_, lean_object* v_h_83_, lean_object* v_lBegin_84_){
_start:
{
uint8_t v_t_boxed_85_; lean_object* v_res_86_; 
v_t_boxed_85_ = lean_unbox(v_t_82_);
v_res_86_ = lp_bounded_Bounded_Rule_lBegin_elim(v_motive_81_, v_t_boxed_85_, v_h_83_, v_lBegin_84_);
lean_dec(v_lBegin_84_);
return v_res_86_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lIter_elim___redArg(lean_object* v_lIter_87_){
_start:
{
lean_inc(v_lIter_87_);
return v_lIter_87_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lIter_elim___redArg___boxed(lean_object* v_lIter_88_){
_start:
{
lean_object* v_res_89_; 
v_res_89_ = lp_bounded_Bounded_Rule_lIter_elim___redArg(v_lIter_88_);
lean_dec(v_lIter_88_);
return v_res_89_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lIter_elim(lean_object* v_motive_90_, uint8_t v_t_91_, lean_object* v_h_92_, lean_object* v_lIter_93_){
_start:
{
lean_inc(v_lIter_93_);
return v_lIter_93_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lIter_elim___boxed(lean_object* v_motive_94_, lean_object* v_t_95_, lean_object* v_h_96_, lean_object* v_lIter_97_){
_start:
{
uint8_t v_t_boxed_98_; lean_object* v_res_99_; 
v_t_boxed_98_ = lean_unbox(v_t_95_);
v_res_99_ = lp_bounded_Bounded_Rule_lIter_elim(v_motive_94_, v_t_boxed_98_, v_h_96_, v_lIter_97_);
lean_dec(v_lIter_97_);
return v_res_99_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lFinish_elim___redArg(lean_object* v_lFinish_100_){
_start:
{
lean_inc(v_lFinish_100_);
return v_lFinish_100_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lFinish_elim___redArg___boxed(lean_object* v_lFinish_101_){
_start:
{
lean_object* v_res_102_; 
v_res_102_ = lp_bounded_Bounded_Rule_lFinish_elim___redArg(v_lFinish_101_);
lean_dec(v_lFinish_101_);
return v_res_102_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lFinish_elim(lean_object* v_motive_103_, uint8_t v_t_104_, lean_object* v_h_105_, lean_object* v_lFinish_106_){
_start:
{
lean_inc(v_lFinish_106_);
return v_lFinish_106_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lFinish_elim___boxed(lean_object* v_motive_107_, lean_object* v_t_108_, lean_object* v_h_109_, lean_object* v_lFinish_110_){
_start:
{
uint8_t v_t_boxed_111_; lean_object* v_res_112_; 
v_t_boxed_111_ = lean_unbox(v_t_108_);
v_res_112_ = lp_bounded_Bounded_Rule_lFinish_elim(v_motive_107_, v_t_boxed_111_, v_h_109_, v_lFinish_110_);
lean_dec(v_lFinish_110_);
return v_res_112_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lDivert_elim___redArg(lean_object* v_lDivert_113_){
_start:
{
lean_inc(v_lDivert_113_);
return v_lDivert_113_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lDivert_elim___redArg___boxed(lean_object* v_lDivert_114_){
_start:
{
lean_object* v_res_115_; 
v_res_115_ = lp_bounded_Bounded_Rule_lDivert_elim___redArg(v_lDivert_114_);
lean_dec(v_lDivert_114_);
return v_res_115_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lDivert_elim(lean_object* v_motive_116_, uint8_t v_t_117_, lean_object* v_h_118_, lean_object* v_lDivert_119_){
_start:
{
lean_inc(v_lDivert_119_);
return v_lDivert_119_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lDivert_elim___boxed(lean_object* v_motive_120_, lean_object* v_t_121_, lean_object* v_h_122_, lean_object* v_lDivert_123_){
_start:
{
uint8_t v_t_boxed_124_; lean_object* v_res_125_; 
v_t_boxed_124_ = lean_unbox(v_t_121_);
v_res_125_ = lp_bounded_Bounded_Rule_lDivert_elim(v_motive_120_, v_t_boxed_124_, v_h_122_, v_lDivert_123_);
lean_dec(v_lDivert_123_);
return v_res_125_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lRaise_elim___redArg(lean_object* v_lRaise_126_){
_start:
{
lean_inc(v_lRaise_126_);
return v_lRaise_126_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lRaise_elim___redArg___boxed(lean_object* v_lRaise_127_){
_start:
{
lean_object* v_res_128_; 
v_res_128_ = lp_bounded_Bounded_Rule_lRaise_elim___redArg(v_lRaise_127_);
lean_dec(v_lRaise_127_);
return v_res_128_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lRaise_elim(lean_object* v_motive_129_, uint8_t v_t_130_, lean_object* v_h_131_, lean_object* v_lRaise_132_){
_start:
{
lean_inc(v_lRaise_132_);
return v_lRaise_132_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lRaise_elim___boxed(lean_object* v_motive_133_, lean_object* v_t_134_, lean_object* v_h_135_, lean_object* v_lRaise_136_){
_start:
{
uint8_t v_t_boxed_137_; lean_object* v_res_138_; 
v_t_boxed_137_ = lean_unbox(v_t_134_);
v_res_138_ = lp_bounded_Bounded_Rule_lRaise_elim(v_motive_133_, v_t_boxed_137_, v_h_135_, v_lRaise_136_);
lean_dec(v_lRaise_136_);
return v_res_138_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lLeave_elim___redArg(lean_object* v_lLeave_139_){
_start:
{
lean_inc(v_lLeave_139_);
return v_lLeave_139_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lLeave_elim___redArg___boxed(lean_object* v_lLeave_140_){
_start:
{
lean_object* v_res_141_; 
v_res_141_ = lp_bounded_Bounded_Rule_lLeave_elim___redArg(v_lLeave_140_);
lean_dec(v_lLeave_140_);
return v_res_141_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lLeave_elim(lean_object* v_motive_142_, uint8_t v_t_143_, lean_object* v_h_144_, lean_object* v_lLeave_145_){
_start:
{
lean_inc(v_lLeave_145_);
return v_lLeave_145_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lLeave_elim___boxed(lean_object* v_motive_146_, lean_object* v_t_147_, lean_object* v_h_148_, lean_object* v_lLeave_149_){
_start:
{
uint8_t v_t_boxed_150_; lean_object* v_res_151_; 
v_t_boxed_150_ = lean_unbox(v_t_147_);
v_res_151_ = lp_bounded_Bounded_Rule_lLeave_elim(v_motive_146_, v_t_boxed_150_, v_h_148_, v_lLeave_149_);
lean_dec(v_lLeave_149_);
return v_res_151_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lUnload_elim___redArg(lean_object* v_lUnload_152_){
_start:
{
lean_inc(v_lUnload_152_);
return v_lUnload_152_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lUnload_elim___redArg___boxed(lean_object* v_lUnload_153_){
_start:
{
lean_object* v_res_154_; 
v_res_154_ = lp_bounded_Bounded_Rule_lUnload_elim___redArg(v_lUnload_153_);
lean_dec(v_lUnload_153_);
return v_res_154_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lUnload_elim(lean_object* v_motive_155_, uint8_t v_t_156_, lean_object* v_h_157_, lean_object* v_lUnload_158_){
_start:
{
lean_inc(v_lUnload_158_);
return v_lUnload_158_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_lUnload_elim___boxed(lean_object* v_motive_159_, lean_object* v_t_160_, lean_object* v_h_161_, lean_object* v_lUnload_162_){
_start:
{
uint8_t v_t_boxed_163_; lean_object* v_res_164_; 
v_t_boxed_163_ = lean_unbox(v_t_160_);
v_res_164_ = lp_bounded_Bounded_Rule_lUnload_elim(v_motive_159_, v_t_boxed_163_, v_h_161_, v_lUnload_162_);
lean_dec(v_lUnload_162_);
return v_res_164_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_Rule_ofNat(lean_object* v_n_165_){
_start:
{
lean_object* v___x_166_; uint8_t v___x_167_; 
v___x_166_ = lean_unsigned_to_nat(4u);
v___x_167_ = lean_nat_dec_le(v_n_165_, v___x_166_);
if (v___x_167_ == 0)
{
lean_object* v___x_168_; uint8_t v___x_169_; 
v___x_168_ = lean_unsigned_to_nat(6u);
v___x_169_ = lean_nat_dec_le(v_n_165_, v___x_168_);
if (v___x_169_ == 0)
{
lean_object* v___x_170_; uint8_t v___x_171_; 
v___x_170_ = lean_unsigned_to_nat(7u);
v___x_171_ = lean_nat_dec_le(v_n_165_, v___x_170_);
if (v___x_171_ == 0)
{
lean_object* v___x_172_; uint8_t v___x_173_; 
v___x_172_ = lean_unsigned_to_nat(8u);
v___x_173_ = lean_nat_dec_le(v_n_165_, v___x_172_);
if (v___x_173_ == 0)
{
uint8_t v___x_174_; 
v___x_174_ = 9;
return v___x_174_;
}
else
{
uint8_t v___x_175_; 
v___x_175_ = 8;
return v___x_175_;
}
}
else
{
uint8_t v___x_176_; 
v___x_176_ = 7;
return v___x_176_;
}
}
else
{
lean_object* v___x_177_; uint8_t v___x_178_; 
v___x_177_ = lean_unsigned_to_nat(5u);
v___x_178_ = lean_nat_dec_le(v_n_165_, v___x_177_);
if (v___x_178_ == 0)
{
uint8_t v___x_179_; 
v___x_179_ = 6;
return v___x_179_;
}
else
{
uint8_t v___x_180_; 
v___x_180_ = 5;
return v___x_180_;
}
}
}
else
{
lean_object* v___x_181_; uint8_t v___x_182_; 
v___x_181_ = lean_unsigned_to_nat(1u);
v___x_182_ = lean_nat_dec_le(v_n_165_, v___x_181_);
if (v___x_182_ == 0)
{
lean_object* v___x_183_; uint8_t v___x_184_; 
v___x_183_ = lean_unsigned_to_nat(2u);
v___x_184_ = lean_nat_dec_le(v_n_165_, v___x_183_);
if (v___x_184_ == 0)
{
lean_object* v___x_185_; uint8_t v___x_186_; 
v___x_185_ = lean_unsigned_to_nat(3u);
v___x_186_ = lean_nat_dec_le(v_n_165_, v___x_185_);
if (v___x_186_ == 0)
{
uint8_t v___x_187_; 
v___x_187_ = 4;
return v___x_187_;
}
else
{
uint8_t v___x_188_; 
v___x_188_ = 3;
return v___x_188_;
}
}
else
{
uint8_t v___x_189_; 
v___x_189_ = 2;
return v___x_189_;
}
}
else
{
lean_object* v___x_190_; uint8_t v___x_191_; 
v___x_190_ = lean_unsigned_to_nat(0u);
v___x_191_ = lean_nat_dec_le(v_n_165_, v___x_190_);
if (v___x_191_ == 0)
{
uint8_t v___x_192_; 
v___x_192_ = 1;
return v___x_192_;
}
else
{
uint8_t v___x_193_; 
v___x_193_ = 0;
return v___x_193_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Rule_ofNat___boxed(lean_object* v_n_194_){
_start:
{
uint8_t v_res_195_; lean_object* v_r_196_; 
v_res_195_ = lp_bounded_Bounded_Rule_ofNat(v_n_194_);
lean_dec(v_n_194_);
v_r_196_ = lean_box(v_res_195_);
return v_r_196_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqRule(uint8_t v_x_197_, uint8_t v_y_198_){
_start:
{
lean_object* v___x_199_; lean_object* v___x_200_; uint8_t v___x_201_; 
v___x_199_ = lp_bounded_Bounded_Rule_ctorIdx(v_x_197_);
v___x_200_ = lp_bounded_Bounded_Rule_ctorIdx(v_y_198_);
v___x_201_ = lean_nat_dec_eq(v___x_199_, v___x_200_);
lean_dec(v___x_200_);
lean_dec(v___x_199_);
return v___x_201_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqRule___boxed(lean_object* v_x_202_, lean_object* v_y_203_){
_start:
{
uint8_t v_x_13__boxed_204_; uint8_t v_y_14__boxed_205_; uint8_t v_res_206_; lean_object* v_r_207_; 
v_x_13__boxed_204_ = lean_unbox(v_x_202_);
v_y_14__boxed_205_ = lean_unbox(v_y_203_);
v_res_206_ = lp_bounded_Bounded_instDecidableEqRule(v_x_13__boxed_204_, v_y_14__boxed_205_);
v_r_207_ = lean_box(v_res_206_);
return v_r_207_;
}
}
static lean_object* _init_lp_bounded_Bounded_instReprRule_repr___closed__20(void){
_start:
{
lean_object* v___x_238_; lean_object* v___x_239_; 
v___x_238_ = lean_unsigned_to_nat(2u);
v___x_239_ = lean_nat_to_int(v___x_238_);
return v___x_239_;
}
}
static lean_object* _init_lp_bounded_Bounded_instReprRule_repr___closed__21(void){
_start:
{
lean_object* v___x_240_; lean_object* v___x_241_; 
v___x_240_ = lean_unsigned_to_nat(1u);
v___x_241_ = lean_nat_to_int(v___x_240_);
return v___x_241_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprRule_repr(uint8_t v_x_242_, lean_object* v_prec_243_){
_start:
{
lean_object* v___y_245_; lean_object* v___y_252_; lean_object* v___y_259_; lean_object* v___y_266_; lean_object* v___y_273_; lean_object* v___y_280_; lean_object* v___y_287_; lean_object* v___y_294_; lean_object* v___y_301_; lean_object* v___y_308_; 
switch(v_x_242_)
{
case 0:
{
lean_object* v___x_314_; uint8_t v___x_315_; 
v___x_314_ = lean_unsigned_to_nat(1024u);
v___x_315_ = lean_nat_dec_le(v___x_314_, v_prec_243_);
if (v___x_315_ == 0)
{
lean_object* v___x_316_; 
v___x_316_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_245_ = v___x_316_;
goto v___jp_244_;
}
else
{
lean_object* v___x_317_; 
v___x_317_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_245_ = v___x_317_;
goto v___jp_244_;
}
}
case 1:
{
lean_object* v___x_318_; uint8_t v___x_319_; 
v___x_318_ = lean_unsigned_to_nat(1024u);
v___x_319_ = lean_nat_dec_le(v___x_318_, v_prec_243_);
if (v___x_319_ == 0)
{
lean_object* v___x_320_; 
v___x_320_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_252_ = v___x_320_;
goto v___jp_251_;
}
else
{
lean_object* v___x_321_; 
v___x_321_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_252_ = v___x_321_;
goto v___jp_251_;
}
}
case 2:
{
lean_object* v___x_322_; uint8_t v___x_323_; 
v___x_322_ = lean_unsigned_to_nat(1024u);
v___x_323_ = lean_nat_dec_le(v___x_322_, v_prec_243_);
if (v___x_323_ == 0)
{
lean_object* v___x_324_; 
v___x_324_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_259_ = v___x_324_;
goto v___jp_258_;
}
else
{
lean_object* v___x_325_; 
v___x_325_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_259_ = v___x_325_;
goto v___jp_258_;
}
}
case 3:
{
lean_object* v___x_326_; uint8_t v___x_327_; 
v___x_326_ = lean_unsigned_to_nat(1024u);
v___x_327_ = lean_nat_dec_le(v___x_326_, v_prec_243_);
if (v___x_327_ == 0)
{
lean_object* v___x_328_; 
v___x_328_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_266_ = v___x_328_;
goto v___jp_265_;
}
else
{
lean_object* v___x_329_; 
v___x_329_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_266_ = v___x_329_;
goto v___jp_265_;
}
}
case 4:
{
lean_object* v___x_330_; uint8_t v___x_331_; 
v___x_330_ = lean_unsigned_to_nat(1024u);
v___x_331_ = lean_nat_dec_le(v___x_330_, v_prec_243_);
if (v___x_331_ == 0)
{
lean_object* v___x_332_; 
v___x_332_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_273_ = v___x_332_;
goto v___jp_272_;
}
else
{
lean_object* v___x_333_; 
v___x_333_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_273_ = v___x_333_;
goto v___jp_272_;
}
}
case 5:
{
lean_object* v___x_334_; uint8_t v___x_335_; 
v___x_334_ = lean_unsigned_to_nat(1024u);
v___x_335_ = lean_nat_dec_le(v___x_334_, v_prec_243_);
if (v___x_335_ == 0)
{
lean_object* v___x_336_; 
v___x_336_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_280_ = v___x_336_;
goto v___jp_279_;
}
else
{
lean_object* v___x_337_; 
v___x_337_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_280_ = v___x_337_;
goto v___jp_279_;
}
}
case 6:
{
lean_object* v___x_338_; uint8_t v___x_339_; 
v___x_338_ = lean_unsigned_to_nat(1024u);
v___x_339_ = lean_nat_dec_le(v___x_338_, v_prec_243_);
if (v___x_339_ == 0)
{
lean_object* v___x_340_; 
v___x_340_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_287_ = v___x_340_;
goto v___jp_286_;
}
else
{
lean_object* v___x_341_; 
v___x_341_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_287_ = v___x_341_;
goto v___jp_286_;
}
}
case 7:
{
lean_object* v___x_342_; uint8_t v___x_343_; 
v___x_342_ = lean_unsigned_to_nat(1024u);
v___x_343_ = lean_nat_dec_le(v___x_342_, v_prec_243_);
if (v___x_343_ == 0)
{
lean_object* v___x_344_; 
v___x_344_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_294_ = v___x_344_;
goto v___jp_293_;
}
else
{
lean_object* v___x_345_; 
v___x_345_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_294_ = v___x_345_;
goto v___jp_293_;
}
}
case 8:
{
lean_object* v___x_346_; uint8_t v___x_347_; 
v___x_346_ = lean_unsigned_to_nat(1024u);
v___x_347_ = lean_nat_dec_le(v___x_346_, v_prec_243_);
if (v___x_347_ == 0)
{
lean_object* v___x_348_; 
v___x_348_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_301_ = v___x_348_;
goto v___jp_300_;
}
else
{
lean_object* v___x_349_; 
v___x_349_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_301_ = v___x_349_;
goto v___jp_300_;
}
}
default: 
{
lean_object* v___x_350_; uint8_t v___x_351_; 
v___x_350_ = lean_unsigned_to_nat(1024u);
v___x_351_ = lean_nat_dec_le(v___x_350_, v_prec_243_);
if (v___x_351_ == 0)
{
lean_object* v___x_352_; 
v___x_352_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_308_ = v___x_352_;
goto v___jp_307_;
}
else
{
lean_object* v___x_353_; 
v___x_353_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_308_ = v___x_353_;
goto v___jp_307_;
}
}
}
v___jp_244_:
{
lean_object* v___x_246_; lean_object* v___x_247_; uint8_t v___x_248_; lean_object* v___x_249_; lean_object* v___x_250_; 
v___x_246_ = ((lean_object*)(lp_bounded_Bounded_instReprRule_repr___closed__1));
lean_inc(v___y_245_);
v___x_247_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_247_, 0, v___y_245_);
lean_ctor_set(v___x_247_, 1, v___x_246_);
v___x_248_ = 0;
v___x_249_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_249_, 0, v___x_247_);
lean_ctor_set_uint8(v___x_249_, sizeof(void*)*1, v___x_248_);
v___x_250_ = l_Repr_addAppParen(v___x_249_, v_prec_243_);
return v___x_250_;
}
v___jp_251_:
{
lean_object* v___x_253_; lean_object* v___x_254_; uint8_t v___x_255_; lean_object* v___x_256_; lean_object* v___x_257_; 
v___x_253_ = ((lean_object*)(lp_bounded_Bounded_instReprRule_repr___closed__3));
lean_inc(v___y_252_);
v___x_254_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_254_, 0, v___y_252_);
lean_ctor_set(v___x_254_, 1, v___x_253_);
v___x_255_ = 0;
v___x_256_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_256_, 0, v___x_254_);
lean_ctor_set_uint8(v___x_256_, sizeof(void*)*1, v___x_255_);
v___x_257_ = l_Repr_addAppParen(v___x_256_, v_prec_243_);
return v___x_257_;
}
v___jp_258_:
{
lean_object* v___x_260_; lean_object* v___x_261_; uint8_t v___x_262_; lean_object* v___x_263_; lean_object* v___x_264_; 
v___x_260_ = ((lean_object*)(lp_bounded_Bounded_instReprRule_repr___closed__5));
lean_inc(v___y_259_);
v___x_261_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_261_, 0, v___y_259_);
lean_ctor_set(v___x_261_, 1, v___x_260_);
v___x_262_ = 0;
v___x_263_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_263_, 0, v___x_261_);
lean_ctor_set_uint8(v___x_263_, sizeof(void*)*1, v___x_262_);
v___x_264_ = l_Repr_addAppParen(v___x_263_, v_prec_243_);
return v___x_264_;
}
v___jp_265_:
{
lean_object* v___x_267_; lean_object* v___x_268_; uint8_t v___x_269_; lean_object* v___x_270_; lean_object* v___x_271_; 
v___x_267_ = ((lean_object*)(lp_bounded_Bounded_instReprRule_repr___closed__7));
lean_inc(v___y_266_);
v___x_268_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_268_, 0, v___y_266_);
lean_ctor_set(v___x_268_, 1, v___x_267_);
v___x_269_ = 0;
v___x_270_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_270_, 0, v___x_268_);
lean_ctor_set_uint8(v___x_270_, sizeof(void*)*1, v___x_269_);
v___x_271_ = l_Repr_addAppParen(v___x_270_, v_prec_243_);
return v___x_271_;
}
v___jp_272_:
{
lean_object* v___x_274_; lean_object* v___x_275_; uint8_t v___x_276_; lean_object* v___x_277_; lean_object* v___x_278_; 
v___x_274_ = ((lean_object*)(lp_bounded_Bounded_instReprRule_repr___closed__9));
lean_inc(v___y_273_);
v___x_275_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_275_, 0, v___y_273_);
lean_ctor_set(v___x_275_, 1, v___x_274_);
v___x_276_ = 0;
v___x_277_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_277_, 0, v___x_275_);
lean_ctor_set_uint8(v___x_277_, sizeof(void*)*1, v___x_276_);
v___x_278_ = l_Repr_addAppParen(v___x_277_, v_prec_243_);
return v___x_278_;
}
v___jp_279_:
{
lean_object* v___x_281_; lean_object* v___x_282_; uint8_t v___x_283_; lean_object* v___x_284_; lean_object* v___x_285_; 
v___x_281_ = ((lean_object*)(lp_bounded_Bounded_instReprRule_repr___closed__11));
lean_inc(v___y_280_);
v___x_282_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_282_, 0, v___y_280_);
lean_ctor_set(v___x_282_, 1, v___x_281_);
v___x_283_ = 0;
v___x_284_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_284_, 0, v___x_282_);
lean_ctor_set_uint8(v___x_284_, sizeof(void*)*1, v___x_283_);
v___x_285_ = l_Repr_addAppParen(v___x_284_, v_prec_243_);
return v___x_285_;
}
v___jp_286_:
{
lean_object* v___x_288_; lean_object* v___x_289_; uint8_t v___x_290_; lean_object* v___x_291_; lean_object* v___x_292_; 
v___x_288_ = ((lean_object*)(lp_bounded_Bounded_instReprRule_repr___closed__13));
lean_inc(v___y_287_);
v___x_289_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_289_, 0, v___y_287_);
lean_ctor_set(v___x_289_, 1, v___x_288_);
v___x_290_ = 0;
v___x_291_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_291_, 0, v___x_289_);
lean_ctor_set_uint8(v___x_291_, sizeof(void*)*1, v___x_290_);
v___x_292_ = l_Repr_addAppParen(v___x_291_, v_prec_243_);
return v___x_292_;
}
v___jp_293_:
{
lean_object* v___x_295_; lean_object* v___x_296_; uint8_t v___x_297_; lean_object* v___x_298_; lean_object* v___x_299_; 
v___x_295_ = ((lean_object*)(lp_bounded_Bounded_instReprRule_repr___closed__15));
lean_inc(v___y_294_);
v___x_296_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_296_, 0, v___y_294_);
lean_ctor_set(v___x_296_, 1, v___x_295_);
v___x_297_ = 0;
v___x_298_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_298_, 0, v___x_296_);
lean_ctor_set_uint8(v___x_298_, sizeof(void*)*1, v___x_297_);
v___x_299_ = l_Repr_addAppParen(v___x_298_, v_prec_243_);
return v___x_299_;
}
v___jp_300_:
{
lean_object* v___x_302_; lean_object* v___x_303_; uint8_t v___x_304_; lean_object* v___x_305_; lean_object* v___x_306_; 
v___x_302_ = ((lean_object*)(lp_bounded_Bounded_instReprRule_repr___closed__17));
lean_inc(v___y_301_);
v___x_303_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_303_, 0, v___y_301_);
lean_ctor_set(v___x_303_, 1, v___x_302_);
v___x_304_ = 0;
v___x_305_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_305_, 0, v___x_303_);
lean_ctor_set_uint8(v___x_305_, sizeof(void*)*1, v___x_304_);
v___x_306_ = l_Repr_addAppParen(v___x_305_, v_prec_243_);
return v___x_306_;
}
v___jp_307_:
{
lean_object* v___x_309_; lean_object* v___x_310_; uint8_t v___x_311_; lean_object* v___x_312_; lean_object* v___x_313_; 
v___x_309_ = ((lean_object*)(lp_bounded_Bounded_instReprRule_repr___closed__19));
lean_inc(v___y_308_);
v___x_310_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_310_, 0, v___y_308_);
lean_ctor_set(v___x_310_, 1, v___x_309_);
v___x_311_ = 0;
v___x_312_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_312_, 0, v___x_310_);
lean_ctor_set_uint8(v___x_312_, sizeof(void*)*1, v___x_311_);
v___x_313_ = l_Repr_addAppParen(v___x_312_, v_prec_243_);
return v___x_313_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprRule_repr___boxed(lean_object* v_x_354_, lean_object* v_prec_355_){
_start:
{
uint8_t v_x_569__boxed_356_; lean_object* v_res_357_; 
v_x_569__boxed_356_ = lean_unbox(v_x_354_);
v_res_357_ = lp_bounded_Bounded_instReprRule_repr(v_x_569__boxed_356_, v_prec_355_);
lean_dec(v_prec_355_);
return v_res_357_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_ctorIdx(lean_object* v_x_360_){
_start:
{
switch(lean_obj_tag(v_x_360_))
{
case 0:
{
lean_object* v___x_361_; 
v___x_361_ = lean_unsigned_to_nat(0u);
return v___x_361_;
}
case 1:
{
lean_object* v___x_362_; 
v___x_362_ = lean_unsigned_to_nat(1u);
return v___x_362_;
}
case 2:
{
lean_object* v___x_363_; 
v___x_363_ = lean_unsigned_to_nat(2u);
return v___x_363_;
}
case 3:
{
lean_object* v___x_364_; 
v___x_364_ = lean_unsigned_to_nat(3u);
return v___x_364_;
}
case 4:
{
lean_object* v___x_365_; 
v___x_365_ = lean_unsigned_to_nat(4u);
return v___x_365_;
}
case 5:
{
lean_object* v___x_366_; 
v___x_366_ = lean_unsigned_to_nat(5u);
return v___x_366_;
}
case 6:
{
lean_object* v___x_367_; 
v___x_367_ = lean_unsigned_to_nat(6u);
return v___x_367_;
}
case 7:
{
lean_object* v___x_368_; 
v___x_368_ = lean_unsigned_to_nat(7u);
return v___x_368_;
}
case 8:
{
lean_object* v___x_369_; 
v___x_369_ = lean_unsigned_to_nat(8u);
return v___x_369_;
}
default: 
{
lean_object* v___x_370_; 
v___x_370_ = lean_unsigned_to_nat(9u);
return v___x_370_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_ctorIdx___boxed(lean_object* v_x_371_){
_start:
{
lean_object* v_res_372_; 
v_res_372_ = lp_bounded_Bounded_Act_ctorIdx(v_x_371_);
lean_dec_ref(v_x_371_);
return v_res_372_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_ctorElim___redArg(lean_object* v_t_373_, lean_object* v_k_374_){
_start:
{
switch(lean_obj_tag(v_t_373_))
{
case 0:
{
lean_object* v_n_375_; lean_object* v_c_376_; lean_object* v___x_377_; 
v_n_375_ = lean_ctor_get(v_t_373_, 0);
lean_inc(v_n_375_);
v_c_376_ = lean_ctor_get(v_t_373_, 1);
lean_inc_ref(v_c_376_);
lean_dec_ref_known(v_t_373_, 2);
v___x_377_ = lean_apply_2(v_k_374_, v_n_375_, v_c_376_);
return v___x_377_;
}
case 4:
{
lean_object* v_n_378_; lean_object* v_creg_379_; lean_object* v___x_380_; 
v_n_378_ = lean_ctor_get(v_t_373_, 0);
lean_inc(v_n_378_);
v_creg_379_ = lean_ctor_get(v_t_373_, 1);
lean_inc(v_creg_379_);
lean_dec_ref_known(v_t_373_, 2);
v___x_380_ = lean_apply_2(v_k_374_, v_n_378_, v_creg_379_);
return v___x_380_;
}
default: 
{
lean_object* v_n_381_; lean_object* v___x_382_; 
v_n_381_ = lean_ctor_get(v_t_373_, 0);
lean_inc(v_n_381_);
lean_dec_ref(v_t_373_);
v___x_382_ = lean_apply_1(v_k_374_, v_n_381_);
return v___x_382_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_ctorElim(lean_object* v_motive_383_, lean_object* v_ctorIdx_384_, lean_object* v_t_385_, lean_object* v_h_386_, lean_object* v_k_387_){
_start:
{
lean_object* v___x_388_; 
v___x_388_ = lp_bounded_Bounded_Act_ctorElim___redArg(v_t_385_, v_k_387_);
return v___x_388_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_ctorElim___boxed(lean_object* v_motive_389_, lean_object* v_ctorIdx_390_, lean_object* v_t_391_, lean_object* v_h_392_, lean_object* v_k_393_){
_start:
{
lean_object* v_res_394_; 
v_res_394_ = lp_bounded_Bounded_Act_ctorElim(v_motive_389_, v_ctorIdx_390_, v_t_391_, v_h_392_, v_k_393_);
lean_dec(v_ctorIdx_390_);
return v_res_394_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_oInsert_elim___redArg(lean_object* v_t_395_, lean_object* v_oInsert_396_){
_start:
{
lean_object* v___x_397_; 
v___x_397_ = lp_bounded_Bounded_Act_ctorElim___redArg(v_t_395_, v_oInsert_396_);
return v___x_397_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_oInsert_elim(lean_object* v_motive_398_, lean_object* v_t_399_, lean_object* v_h_400_, lean_object* v_oInsert_401_){
_start:
{
lean_object* v___x_402_; 
v___x_402_ = lp_bounded_Bounded_Act_ctorElim___redArg(v_t_399_, v_oInsert_401_);
return v___x_402_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_oRetire_elim___redArg(lean_object* v_t_403_, lean_object* v_oRetire_404_){
_start:
{
lean_object* v___x_405_; 
v___x_405_ = lp_bounded_Bounded_Act_ctorElim___redArg(v_t_403_, v_oRetire_404_);
return v___x_405_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_oRetire_elim(lean_object* v_motive_406_, lean_object* v_t_407_, lean_object* v_h_408_, lean_object* v_oRetire_409_){
_start:
{
lean_object* v___x_410_; 
v___x_410_ = lp_bounded_Bounded_Act_ctorElim___redArg(v_t_407_, v_oRetire_409_);
return v___x_410_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_oRemove_elim___redArg(lean_object* v_t_411_, lean_object* v_oRemove_412_){
_start:
{
lean_object* v___x_413_; 
v___x_413_ = lp_bounded_Bounded_Act_ctorElim___redArg(v_t_411_, v_oRemove_412_);
return v___x_413_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_oRemove_elim(lean_object* v_motive_414_, lean_object* v_t_415_, lean_object* v_h_416_, lean_object* v_oRemove_417_){
_start:
{
lean_object* v___x_418_; 
v___x_418_ = lp_bounded_Bounded_Act_ctorElim___redArg(v_t_415_, v_oRemove_417_);
return v___x_418_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_lBegin_elim___redArg(lean_object* v_t_419_, lean_object* v_lBegin_420_){
_start:
{
lean_object* v___x_421_; 
v___x_421_ = lp_bounded_Bounded_Act_ctorElim___redArg(v_t_419_, v_lBegin_420_);
return v___x_421_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_lBegin_elim(lean_object* v_motive_422_, lean_object* v_t_423_, lean_object* v_h_424_, lean_object* v_lBegin_425_){
_start:
{
lean_object* v___x_426_; 
v___x_426_ = lp_bounded_Bounded_Act_ctorElim___redArg(v_t_423_, v_lBegin_425_);
return v___x_426_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_lIter_elim___redArg(lean_object* v_t_427_, lean_object* v_lIter_428_){
_start:
{
lean_object* v___x_429_; 
v___x_429_ = lp_bounded_Bounded_Act_ctorElim___redArg(v_t_427_, v_lIter_428_);
return v___x_429_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_lIter_elim(lean_object* v_motive_430_, lean_object* v_t_431_, lean_object* v_h_432_, lean_object* v_lIter_433_){
_start:
{
lean_object* v___x_434_; 
v___x_434_ = lp_bounded_Bounded_Act_ctorElim___redArg(v_t_431_, v_lIter_433_);
return v___x_434_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_lFinish_elim___redArg(lean_object* v_t_435_, lean_object* v_lFinish_436_){
_start:
{
lean_object* v___x_437_; 
v___x_437_ = lp_bounded_Bounded_Act_ctorElim___redArg(v_t_435_, v_lFinish_436_);
return v___x_437_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_lFinish_elim(lean_object* v_motive_438_, lean_object* v_t_439_, lean_object* v_h_440_, lean_object* v_lFinish_441_){
_start:
{
lean_object* v___x_442_; 
v___x_442_ = lp_bounded_Bounded_Act_ctorElim___redArg(v_t_439_, v_lFinish_441_);
return v___x_442_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_lDivert_elim___redArg(lean_object* v_t_443_, lean_object* v_lDivert_444_){
_start:
{
lean_object* v___x_445_; 
v___x_445_ = lp_bounded_Bounded_Act_ctorElim___redArg(v_t_443_, v_lDivert_444_);
return v___x_445_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_lDivert_elim(lean_object* v_motive_446_, lean_object* v_t_447_, lean_object* v_h_448_, lean_object* v_lDivert_449_){
_start:
{
lean_object* v___x_450_; 
v___x_450_ = lp_bounded_Bounded_Act_ctorElim___redArg(v_t_447_, v_lDivert_449_);
return v___x_450_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_lRaise_elim___redArg(lean_object* v_t_451_, lean_object* v_lRaise_452_){
_start:
{
lean_object* v___x_453_; 
v___x_453_ = lp_bounded_Bounded_Act_ctorElim___redArg(v_t_451_, v_lRaise_452_);
return v___x_453_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_lRaise_elim(lean_object* v_motive_454_, lean_object* v_t_455_, lean_object* v_h_456_, lean_object* v_lRaise_457_){
_start:
{
lean_object* v___x_458_; 
v___x_458_ = lp_bounded_Bounded_Act_ctorElim___redArg(v_t_455_, v_lRaise_457_);
return v___x_458_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_lLeave_elim___redArg(lean_object* v_t_459_, lean_object* v_lLeave_460_){
_start:
{
lean_object* v___x_461_; 
v___x_461_ = lp_bounded_Bounded_Act_ctorElim___redArg(v_t_459_, v_lLeave_460_);
return v___x_461_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_lLeave_elim(lean_object* v_motive_462_, lean_object* v_t_463_, lean_object* v_h_464_, lean_object* v_lLeave_465_){
_start:
{
lean_object* v___x_466_; 
v___x_466_ = lp_bounded_Bounded_Act_ctorElim___redArg(v_t_463_, v_lLeave_465_);
return v___x_466_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_lUnload_elim___redArg(lean_object* v_t_467_, lean_object* v_lUnload_468_){
_start:
{
lean_object* v___x_469_; 
v___x_469_ = lp_bounded_Bounded_Act_ctorElim___redArg(v_t_467_, v_lUnload_468_);
return v___x_469_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_lUnload_elim(lean_object* v_motive_470_, lean_object* v_t_471_, lean_object* v_h_472_, lean_object* v_lUnload_473_){
_start:
{
lean_object* v___x_474_; 
v___x_474_ = lp_bounded_Bounded_Act_ctorElim___redArg(v_t_471_, v_lUnload_473_);
return v___x_474_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqAct_decEq(lean_object* v_x_477_, lean_object* v_x_478_){
_start:
{
lean_object* v___x_479_; lean_object* v___x_480_; uint8_t v___x_481_; 
v___x_479_ = lp_bounded_Bounded_Act_ctorIdx(v_x_477_);
v___x_480_ = lp_bounded_Bounded_Act_ctorIdx(v_x_478_);
v___x_481_ = lean_nat_dec_eq(v___x_479_, v___x_480_);
lean_dec(v___x_480_);
lean_dec(v___x_479_);
if (v___x_481_ == 0)
{
lean_dec_ref(v_x_478_);
lean_dec_ref(v_x_477_);
return v___x_481_;
}
else
{
switch(lean_obj_tag(v_x_477_))
{
case 0:
{
lean_object* v_n_482_; lean_object* v_c_483_; lean_object* v_n_484_; lean_object* v_c_485_; uint8_t v___x_486_; 
v_n_482_ = lean_ctor_get(v_x_477_, 0);
lean_inc(v_n_482_);
v_c_483_ = lean_ctor_get(v_x_477_, 1);
lean_inc_ref(v_c_483_);
lean_dec_ref_known(v_x_477_, 2);
v_n_484_ = lean_ctor_get(v_x_478_, 0);
lean_inc(v_n_484_);
v_c_485_ = lean_ctor_get(v_x_478_, 1);
lean_inc_ref(v_c_485_);
lean_dec_ref(v_x_478_);
v___x_486_ = lean_nat_dec_eq(v_n_482_, v_n_484_);
lean_dec(v_n_484_);
lean_dec(v_n_482_);
if (v___x_486_ == 0)
{
lean_dec_ref(v_c_485_);
lean_dec_ref(v_c_483_);
return v___x_486_;
}
else
{
uint8_t v___x_487_; 
v___x_487_ = lp_bounded_Bounded_instDecidableEqComponent_decEq(v_c_483_, v_c_485_);
return v___x_487_;
}
}
case 4:
{
lean_object* v_n_488_; lean_object* v_creg_489_; lean_object* v_n_490_; lean_object* v_creg_491_; uint8_t v___x_492_; 
v_n_488_ = lean_ctor_get(v_x_477_, 0);
lean_inc(v_n_488_);
v_creg_489_ = lean_ctor_get(v_x_477_, 1);
lean_inc(v_creg_489_);
lean_dec_ref_known(v_x_477_, 2);
v_n_490_ = lean_ctor_get(v_x_478_, 0);
lean_inc(v_n_490_);
v_creg_491_ = lean_ctor_get(v_x_478_, 1);
lean_inc(v_creg_491_);
lean_dec_ref(v_x_478_);
v___x_492_ = lean_nat_dec_eq(v_n_488_, v_n_490_);
lean_dec(v_n_490_);
lean_dec(v_n_488_);
if (v___x_492_ == 0)
{
lean_dec(v_creg_491_);
lean_dec(v_creg_489_);
return v___x_492_;
}
else
{
lean_object* v___x_493_; uint8_t v___x_494_; 
v___x_493_ = ((lean_object*)(lp_bounded_Bounded_instDecidableEqAct_decEq___closed__0));
v___x_494_ = l_Option_instDecidableEq___redArg(v___x_493_, v_creg_489_, v_creg_491_);
return v___x_494_;
}
}
default: 
{
lean_object* v_n_495_; lean_object* v_n_496_; uint8_t v___x_497_; 
v_n_495_ = lean_ctor_get(v_x_477_, 0);
lean_inc(v_n_495_);
lean_dec_ref(v_x_477_);
v_n_496_ = lean_ctor_get(v_x_478_, 0);
lean_inc(v_n_496_);
lean_dec_ref(v_x_478_);
v___x_497_ = lean_nat_dec_eq(v_n_495_, v_n_496_);
lean_dec(v_n_496_);
lean_dec(v_n_495_);
return v___x_497_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqAct_decEq___boxed(lean_object* v_x_498_, lean_object* v_x_499_){
_start:
{
uint8_t v_res_500_; lean_object* v_r_501_; 
v_res_500_ = lp_bounded_Bounded_instDecidableEqAct_decEq(v_x_498_, v_x_499_);
v_r_501_ = lean_box(v_res_500_);
return v_r_501_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqAct(lean_object* v_x_502_, lean_object* v_x_503_){
_start:
{
uint8_t v___x_504_; 
v___x_504_ = lp_bounded_Bounded_instDecidableEqAct_decEq(v_x_502_, v_x_503_);
return v___x_504_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqAct___boxed(lean_object* v_x_505_, lean_object* v_x_506_){
_start:
{
uint8_t v_res_507_; lean_object* v_r_508_; 
v_res_507_ = lp_bounded_Bounded_instDecidableEqAct(v_x_505_, v_x_506_);
v_r_508_ = lean_box(v_res_507_);
return v_r_508_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_Act_rule(lean_object* v_x_509_){
_start:
{
switch(lean_obj_tag(v_x_509_))
{
case 0:
{
uint8_t v___x_510_; 
v___x_510_ = 0;
return v___x_510_;
}
case 1:
{
uint8_t v___x_511_; 
v___x_511_ = 1;
return v___x_511_;
}
case 2:
{
uint8_t v___x_512_; 
v___x_512_ = 2;
return v___x_512_;
}
case 3:
{
uint8_t v___x_513_; 
v___x_513_ = 3;
return v___x_513_;
}
case 4:
{
uint8_t v___x_514_; 
v___x_514_ = 4;
return v___x_514_;
}
case 5:
{
uint8_t v___x_515_; 
v___x_515_ = 5;
return v___x_515_;
}
case 6:
{
uint8_t v___x_516_; 
v___x_516_ = 6;
return v___x_516_;
}
case 7:
{
uint8_t v___x_517_; 
v___x_517_ = 7;
return v___x_517_;
}
case 8:
{
uint8_t v___x_518_; 
v___x_518_ = 8;
return v___x_518_;
}
default: 
{
uint8_t v___x_519_; 
v___x_519_ = 9;
return v___x_519_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Act_rule___boxed(lean_object* v_x_520_){
_start:
{
uint8_t v_res_521_; lean_object* v_r_522_; 
v_res_521_ = lp_bounded_Bounded_Act_rule(v_x_520_);
lean_dec_ref(v_x_520_);
v_r_522_ = lean_box(v_res_521_);
return v_r_522_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_ctorIdx(lean_object* v_x_523_){
_start:
{
switch(lean_obj_tag(v_x_523_))
{
case 0:
{
lean_object* v___x_524_; 
v___x_524_ = lean_unsigned_to_nat(0u);
return v___x_524_;
}
case 1:
{
lean_object* v___x_525_; 
v___x_525_ = lean_unsigned_to_nat(1u);
return v___x_525_;
}
case 2:
{
lean_object* v___x_526_; 
v___x_526_ = lean_unsigned_to_nat(2u);
return v___x_526_;
}
case 3:
{
lean_object* v___x_527_; 
v___x_527_ = lean_unsigned_to_nat(3u);
return v___x_527_;
}
case 4:
{
lean_object* v___x_528_; 
v___x_528_ = lean_unsigned_to_nat(4u);
return v___x_528_;
}
case 5:
{
lean_object* v___x_529_; 
v___x_529_ = lean_unsigned_to_nat(5u);
return v___x_529_;
}
case 6:
{
lean_object* v___x_530_; 
v___x_530_ = lean_unsigned_to_nat(6u);
return v___x_530_;
}
case 7:
{
lean_object* v___x_531_; 
v___x_531_ = lean_unsigned_to_nat(7u);
return v___x_531_;
}
case 8:
{
lean_object* v___x_532_; 
v___x_532_ = lean_unsigned_to_nat(8u);
return v___x_532_;
}
case 9:
{
lean_object* v___x_533_; 
v___x_533_ = lean_unsigned_to_nat(9u);
return v___x_533_;
}
case 10:
{
lean_object* v___x_534_; 
v___x_534_ = lean_unsigned_to_nat(10u);
return v___x_534_;
}
case 11:
{
lean_object* v___x_535_; 
v___x_535_ = lean_unsigned_to_nat(11u);
return v___x_535_;
}
case 12:
{
lean_object* v___x_536_; 
v___x_536_ = lean_unsigned_to_nat(12u);
return v___x_536_;
}
case 13:
{
lean_object* v___x_537_; 
v___x_537_ = lean_unsigned_to_nat(13u);
return v___x_537_;
}
case 14:
{
lean_object* v___x_538_; 
v___x_538_ = lean_unsigned_to_nat(14u);
return v___x_538_;
}
case 15:
{
lean_object* v___x_539_; 
v___x_539_ = lean_unsigned_to_nat(15u);
return v___x_539_;
}
case 16:
{
lean_object* v___x_540_; 
v___x_540_ = lean_unsigned_to_nat(16u);
return v___x_540_;
}
default: 
{
lean_object* v___x_541_; 
v___x_541_ = lean_unsigned_to_nat(17u);
return v___x_541_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_ctorIdx___boxed(lean_object* v_x_542_){
_start:
{
lean_object* v_res_543_; 
v_res_543_ = lp_bounded_Bounded_Event_ctorIdx(v_x_542_);
lean_dec_ref(v_x_542_);
return v_res_543_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_ctorElim___redArg(lean_object* v_t_544_, lean_object* v_k_545_){
_start:
{
switch(lean_obj_tag(v_t_544_))
{
case 4:
{
lean_object* v_n_546_; lean_object* v_k_547_; lean_object* v___x_548_; 
v_n_546_ = lean_ctor_get(v_t_544_, 0);
lean_inc(v_n_546_);
v_k_547_ = lean_ctor_get(v_t_544_, 1);
lean_inc(v_k_547_);
lean_dec_ref_known(v_t_544_, 2);
v___x_548_ = lean_apply_2(v_k_545_, v_n_546_, v_k_547_);
return v___x_548_;
}
case 5:
{
lean_object* v_n_549_; lean_object* v_t_550_; lean_object* v___x_551_; 
v_n_549_ = lean_ctor_get(v_t_544_, 0);
lean_inc(v_n_549_);
v_t_550_ = lean_ctor_get(v_t_544_, 1);
lean_inc(v_t_550_);
lean_dec_ref_known(v_t_544_, 2);
v___x_551_ = lean_apply_2(v_k_545_, v_n_549_, v_t_550_);
return v___x_551_;
}
case 6:
{
lean_object* v_n_552_; lean_object* v_k_553_; lean_object* v_v_554_; lean_object* v___x_555_; 
v_n_552_ = lean_ctor_get(v_t_544_, 0);
lean_inc(v_n_552_);
v_k_553_ = lean_ctor_get(v_t_544_, 1);
lean_inc(v_k_553_);
v_v_554_ = lean_ctor_get(v_t_544_, 2);
lean_inc(v_v_554_);
lean_dec_ref_known(v_t_544_, 3);
v___x_555_ = lean_apply_3(v_k_545_, v_n_552_, v_k_553_, v_v_554_);
return v___x_555_;
}
case 7:
{
lean_object* v_n_556_; lean_object* v_k_557_; uint8_t v_ia_558_; lean_object* v___x_559_; lean_object* v___x_560_; 
v_n_556_ = lean_ctor_get(v_t_544_, 0);
lean_inc(v_n_556_);
v_k_557_ = lean_ctor_get(v_t_544_, 1);
lean_inc(v_k_557_);
v_ia_558_ = lean_ctor_get_uint8(v_t_544_, sizeof(void*)*2);
lean_dec_ref_known(v_t_544_, 2);
v___x_559_ = lean_box(v_ia_558_);
v___x_560_ = lean_apply_3(v_k_545_, v_n_556_, v_k_557_, v___x_559_);
return v___x_560_;
}
case 8:
{
lean_object* v_n_561_; lean_object* v_k_562_; lean_object* v_v_563_; lean_object* v___x_564_; 
v_n_561_ = lean_ctor_get(v_t_544_, 0);
lean_inc(v_n_561_);
v_k_562_ = lean_ctor_get(v_t_544_, 1);
lean_inc(v_k_562_);
v_v_563_ = lean_ctor_get(v_t_544_, 2);
lean_inc(v_v_563_);
lean_dec_ref_known(v_t_544_, 3);
v___x_564_ = lean_apply_3(v_k_545_, v_n_561_, v_k_562_, v_v_563_);
return v___x_564_;
}
case 9:
{
lean_object* v_n_565_; lean_object* v_child_566_; lean_object* v___x_567_; 
v_n_565_ = lean_ctor_get(v_t_544_, 0);
lean_inc(v_n_565_);
v_child_566_ = lean_ctor_get(v_t_544_, 1);
lean_inc(v_child_566_);
lean_dec_ref_known(v_t_544_, 2);
v___x_567_ = lean_apply_2(v_k_545_, v_n_565_, v_child_566_);
return v___x_567_;
}
case 14:
{
lean_object* v_n_568_; lean_object* v_t_569_; lean_object* v___x_570_; 
v_n_568_ = lean_ctor_get(v_t_544_, 0);
lean_inc(v_n_568_);
v_t_569_ = lean_ctor_get(v_t_544_, 1);
lean_inc(v_t_569_);
lean_dec_ref_known(v_t_544_, 2);
v___x_570_ = lean_apply_2(v_k_545_, v_n_568_, v_t_569_);
return v___x_570_;
}
case 15:
{
lean_object* v_n_571_; lean_object* v_k_572_; lean_object* v___x_573_; 
v_n_571_ = lean_ctor_get(v_t_544_, 0);
lean_inc(v_n_571_);
v_k_572_ = lean_ctor_get(v_t_544_, 1);
lean_inc(v_k_572_);
lean_dec_ref_known(v_t_544_, 2);
v___x_573_ = lean_apply_2(v_k_545_, v_n_571_, v_k_572_);
return v___x_573_;
}
case 16:
{
lean_object* v_n_574_; lean_object* v_child_575_; lean_object* v___x_576_; 
v_n_574_ = lean_ctor_get(v_t_544_, 0);
lean_inc(v_n_574_);
v_child_575_ = lean_ctor_get(v_t_544_, 1);
lean_inc(v_child_575_);
lean_dec_ref_known(v_t_544_, 2);
v___x_576_ = lean_apply_2(v_k_545_, v_n_574_, v_child_575_);
return v___x_576_;
}
default: 
{
lean_object* v_n_577_; lean_object* v___x_578_; 
v_n_577_ = lean_ctor_get(v_t_544_, 0);
lean_inc(v_n_577_);
lean_dec_ref(v_t_544_);
v___x_578_ = lean_apply_1(v_k_545_, v_n_577_);
return v___x_578_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_ctorElim(lean_object* v_motive_579_, lean_object* v_ctorIdx_580_, lean_object* v_t_581_, lean_object* v_h_582_, lean_object* v_k_583_){
_start:
{
lean_object* v___x_584_; 
v___x_584_ = lp_bounded_Bounded_Event_ctorElim___redArg(v_t_581_, v_k_583_);
return v___x_584_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_ctorElim___boxed(lean_object* v_motive_585_, lean_object* v_ctorIdx_586_, lean_object* v_t_587_, lean_object* v_h_588_, lean_object* v_k_589_){
_start:
{
lean_object* v_res_590_; 
v_res_590_ = lp_bounded_Bounded_Event_ctorElim(v_motive_585_, v_ctorIdx_586_, v_t_587_, v_h_588_, v_k_589_);
lean_dec(v_ctorIdx_586_);
return v_res_590_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_inserted_elim___redArg(lean_object* v_t_591_, lean_object* v_inserted_592_){
_start:
{
lean_object* v___x_593_; 
v___x_593_ = lp_bounded_Bounded_Event_ctorElim___redArg(v_t_591_, v_inserted_592_);
return v___x_593_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_inserted_elim(lean_object* v_motive_594_, lean_object* v_t_595_, lean_object* v_h_596_, lean_object* v_inserted_597_){
_start:
{
lean_object* v___x_598_; 
v___x_598_ = lp_bounded_Bounded_Event_ctorElim___redArg(v_t_595_, v_inserted_597_);
return v___x_598_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_retiredEv_elim___redArg(lean_object* v_t_599_, lean_object* v_retiredEv_600_){
_start:
{
lean_object* v___x_601_; 
v___x_601_ = lp_bounded_Bounded_Event_ctorElim___redArg(v_t_599_, v_retiredEv_600_);
return v___x_601_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_retiredEv_elim(lean_object* v_motive_602_, lean_object* v_t_603_, lean_object* v_h_604_, lean_object* v_retiredEv_605_){
_start:
{
lean_object* v___x_606_; 
v___x_606_ = lp_bounded_Bounded_Event_ctorElim___redArg(v_t_603_, v_retiredEv_605_);
return v___x_606_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_removedEv_elim___redArg(lean_object* v_t_607_, lean_object* v_removedEv_608_){
_start:
{
lean_object* v___x_609_; 
v___x_609_ = lp_bounded_Bounded_Event_ctorElim___redArg(v_t_607_, v_removedEv_608_);
return v___x_609_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_removedEv_elim(lean_object* v_motive_610_, lean_object* v_t_611_, lean_object* v_h_612_, lean_object* v_removedEv_613_){
_start:
{
lean_object* v___x_614_; 
v___x_614_ = lp_bounded_Bounded_Event_ctorElim___redArg(v_t_611_, v_removedEv_613_);
return v___x_614_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_began_elim___redArg(lean_object* v_t_615_, lean_object* v_began_616_){
_start:
{
lean_object* v___x_617_; 
v___x_617_ = lp_bounded_Bounded_Event_ctorElim___redArg(v_t_615_, v_began_616_);
return v___x_617_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_began_elim(lean_object* v_motive_618_, lean_object* v_t_619_, lean_object* v_h_620_, lean_object* v_began_621_){
_start:
{
lean_object* v___x_622_; 
v___x_622_ = lp_bounded_Bounded_Event_ctorElim___redArg(v_t_619_, v_began_621_);
return v___x_622_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_provided_elim___redArg(lean_object* v_t_623_, lean_object* v_provided_624_){
_start:
{
lean_object* v___x_625_; 
v___x_625_ = lp_bounded_Bounded_Event_ctorElim___redArg(v_t_623_, v_provided_624_);
return v___x_625_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_provided_elim(lean_object* v_motive_626_, lean_object* v_t_627_, lean_object* v_h_628_, lean_object* v_provided_629_){
_start:
{
lean_object* v___x_630_; 
v___x_630_ = lp_bounded_Bounded_Event_ctorElim___redArg(v_t_627_, v_provided_629_);
return v___x_630_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_applied_elim___redArg(lean_object* v_t_631_, lean_object* v_applied_632_){
_start:
{
lean_object* v___x_633_; 
v___x_633_ = lp_bounded_Bounded_Event_ctorElim___redArg(v_t_631_, v_applied_632_);
return v___x_633_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_applied_elim(lean_object* v_motive_634_, lean_object* v_t_635_, lean_object* v_h_636_, lean_object* v_applied_637_){
_start:
{
lean_object* v___x_638_; 
v___x_638_ = lp_bounded_Bounded_Event_ctorElim___redArg(v_t_635_, v_applied_637_);
return v___x_638_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_readOk_elim___redArg(lean_object* v_t_639_, lean_object* v_readOk_640_){
_start:
{
lean_object* v___x_641_; 
v___x_641_ = lp_bounded_Bounded_Event_ctorElim___redArg(v_t_639_, v_readOk_640_);
return v___x_641_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_readOk_elim(lean_object* v_motive_642_, lean_object* v_t_643_, lean_object* v_h_644_, lean_object* v_readOk_645_){
_start:
{
lean_object* v___x_646_; 
v___x_646_ = lp_bounded_Bounded_Event_ctorElim___redArg(v_t_643_, v_readOk_645_);
return v___x_646_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_readFail_elim___redArg(lean_object* v_t_647_, lean_object* v_readFail_648_){
_start:
{
lean_object* v___x_649_; 
v___x_649_ = lp_bounded_Bounded_Event_ctorElim___redArg(v_t_647_, v_readFail_648_);
return v___x_649_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_readFail_elim(lean_object* v_motive_650_, lean_object* v_t_651_, lean_object* v_h_652_, lean_object* v_readFail_653_){
_start:
{
lean_object* v___x_654_; 
v___x_654_ = lp_bounded_Bounded_Event_ctorElim___redArg(v_t_651_, v_readFail_653_);
return v___x_654_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_setv_elim___redArg(lean_object* v_t_655_, lean_object* v_setv_656_){
_start:
{
lean_object* v___x_657_; 
v___x_657_ = lp_bounded_Bounded_Event_ctorElim___redArg(v_t_655_, v_setv_656_);
return v___x_657_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_setv_elim(lean_object* v_motive_658_, lean_object* v_t_659_, lean_object* v_h_660_, lean_object* v_setv_661_){
_start:
{
lean_object* v___x_662_; 
v___x_662_ = lp_bounded_Bounded_Event_ctorElim___redArg(v_t_659_, v_setv_661_);
return v___x_662_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_registered_elim___redArg(lean_object* v_t_663_, lean_object* v_registered_664_){
_start:
{
lean_object* v___x_665_; 
v___x_665_ = lp_bounded_Bounded_Event_ctorElim___redArg(v_t_663_, v_registered_664_);
return v___x_665_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_registered_elim(lean_object* v_motive_666_, lean_object* v_t_667_, lean_object* v_h_668_, lean_object* v_registered_669_){
_start:
{
lean_object* v___x_670_; 
v___x_670_ = lp_bounded_Bounded_Event_ctorElim___redArg(v_t_667_, v_registered_669_);
return v___x_670_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_raised_elim___redArg(lean_object* v_t_671_, lean_object* v_raised_672_){
_start:
{
lean_object* v___x_673_; 
v___x_673_ = lp_bounded_Bounded_Event_ctorElim___redArg(v_t_671_, v_raised_672_);
return v___x_673_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_raised_elim(lean_object* v_motive_674_, lean_object* v_t_675_, lean_object* v_h_676_, lean_object* v_raised_677_){
_start:
{
lean_object* v___x_678_; 
v___x_678_ = lp_bounded_Bounded_Event_ctorElim___redArg(v_t_675_, v_raised_677_);
return v___x_678_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_activated_elim___redArg(lean_object* v_t_679_, lean_object* v_activated_680_){
_start:
{
lean_object* v___x_681_; 
v___x_681_ = lp_bounded_Bounded_Event_ctorElim___redArg(v_t_679_, v_activated_680_);
return v___x_681_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_activated_elim(lean_object* v_motive_682_, lean_object* v_t_683_, lean_object* v_h_684_, lean_object* v_activated_685_){
_start:
{
lean_object* v___x_686_; 
v___x_686_ = lp_bounded_Bounded_Event_ctorElim___redArg(v_t_683_, v_activated_685_);
return v___x_686_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_diverted_elim___redArg(lean_object* v_t_687_, lean_object* v_diverted_688_){
_start:
{
lean_object* v___x_689_; 
v___x_689_ = lp_bounded_Bounded_Event_ctorElim___redArg(v_t_687_, v_diverted_688_);
return v___x_689_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_diverted_elim(lean_object* v_motive_690_, lean_object* v_t_691_, lean_object* v_h_692_, lean_object* v_diverted_693_){
_start:
{
lean_object* v___x_694_; 
v___x_694_ = lp_bounded_Bounded_Event_ctorElim___redArg(v_t_691_, v_diverted_693_);
return v___x_694_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_leftEv_elim___redArg(lean_object* v_t_695_, lean_object* v_leftEv_696_){
_start:
{
lean_object* v___x_697_; 
v___x_697_ = lp_bounded_Bounded_Event_ctorElim___redArg(v_t_695_, v_leftEv_696_);
return v___x_697_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_leftEv_elim(lean_object* v_motive_698_, lean_object* v_t_699_, lean_object* v_h_700_, lean_object* v_leftEv_701_){
_start:
{
lean_object* v___x_702_; 
v___x_702_ = lp_bounded_Bounded_Event_ctorElim___redArg(v_t_699_, v_leftEv_701_);
return v___x_702_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_reverted_elim___redArg(lean_object* v_t_703_, lean_object* v_reverted_704_){
_start:
{
lean_object* v___x_705_; 
v___x_705_ = lp_bounded_Bounded_Event_ctorElim___redArg(v_t_703_, v_reverted_704_);
return v___x_705_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_reverted_elim(lean_object* v_motive_706_, lean_object* v_t_707_, lean_object* v_h_708_, lean_object* v_reverted_709_){
_start:
{
lean_object* v___x_710_; 
v___x_710_ = lp_bounded_Bounded_Event_ctorElim___redArg(v_t_707_, v_reverted_709_);
return v___x_710_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_unprovided_elim___redArg(lean_object* v_t_711_, lean_object* v_unprovided_712_){
_start:
{
lean_object* v___x_713_; 
v___x_713_ = lp_bounded_Bounded_Event_ctorElim___redArg(v_t_711_, v_unprovided_712_);
return v___x_713_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_unprovided_elim(lean_object* v_motive_714_, lean_object* v_t_715_, lean_object* v_h_716_, lean_object* v_unprovided_717_){
_start:
{
lean_object* v___x_718_; 
v___x_718_ = lp_bounded_Bounded_Event_ctorElim___redArg(v_t_715_, v_unprovided_717_);
return v___x_718_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_childRetired_elim___redArg(lean_object* v_t_719_, lean_object* v_childRetired_720_){
_start:
{
lean_object* v___x_721_; 
v___x_721_ = lp_bounded_Bounded_Event_ctorElim___redArg(v_t_719_, v_childRetired_720_);
return v___x_721_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_childRetired_elim(lean_object* v_motive_722_, lean_object* v_t_723_, lean_object* v_h_724_, lean_object* v_childRetired_725_){
_start:
{
lean_object* v___x_726_; 
v___x_726_ = lp_bounded_Bounded_Event_ctorElim___redArg(v_t_723_, v_childRetired_725_);
return v___x_726_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_deactivated_elim___redArg(lean_object* v_t_727_, lean_object* v_deactivated_728_){
_start:
{
lean_object* v___x_729_; 
v___x_729_ = lp_bounded_Bounded_Event_ctorElim___redArg(v_t_727_, v_deactivated_728_);
return v___x_729_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Event_deactivated_elim(lean_object* v_motive_730_, lean_object* v_t_731_, lean_object* v_h_732_, lean_object* v_deactivated_733_){
_start:
{
lean_object* v___x_734_; 
v___x_734_ = lp_bounded_Bounded_Event_ctorElim___redArg(v_t_731_, v_deactivated_733_);
return v___x_734_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqEvent_decEq(lean_object* v_x_735_, lean_object* v_x_736_){
_start:
{
lean_object* v___x_737_; lean_object* v___x_738_; uint8_t v___x_739_; 
v___x_737_ = lp_bounded_Bounded_Event_ctorIdx(v_x_735_);
v___x_738_ = lp_bounded_Bounded_Event_ctorIdx(v_x_736_);
v___x_739_ = lean_nat_dec_eq(v___x_737_, v___x_738_);
lean_dec(v___x_738_);
lean_dec(v___x_737_);
if (v___x_739_ == 0)
{
return v___x_739_;
}
else
{
switch(lean_obj_tag(v_x_735_))
{
case 4:
{
lean_object* v_n_740_; lean_object* v_k_741_; lean_object* v_n_742_; lean_object* v_k_743_; uint8_t v___x_744_; 
v_n_740_ = lean_ctor_get(v_x_735_, 0);
v_k_741_ = lean_ctor_get(v_x_735_, 1);
v_n_742_ = lean_ctor_get(v_x_736_, 0);
v_k_743_ = lean_ctor_get(v_x_736_, 1);
v___x_744_ = lean_nat_dec_eq(v_n_740_, v_n_742_);
if (v___x_744_ == 0)
{
return v___x_744_;
}
else
{
uint8_t v___x_745_; 
v___x_745_ = lean_nat_dec_eq(v_k_741_, v_k_743_);
return v___x_745_;
}
}
case 5:
{
lean_object* v_n_746_; lean_object* v_t_747_; lean_object* v_n_748_; lean_object* v_t_749_; uint8_t v___x_750_; 
v_n_746_ = lean_ctor_get(v_x_735_, 0);
v_t_747_ = lean_ctor_get(v_x_735_, 1);
v_n_748_ = lean_ctor_get(v_x_736_, 0);
v_t_749_ = lean_ctor_get(v_x_736_, 1);
v___x_750_ = lean_nat_dec_eq(v_n_746_, v_n_748_);
if (v___x_750_ == 0)
{
return v___x_750_;
}
else
{
uint8_t v___x_751_; 
v___x_751_ = lean_nat_dec_eq(v_t_747_, v_t_749_);
return v___x_751_;
}
}
case 6:
{
lean_object* v_n_752_; lean_object* v_k_753_; lean_object* v_v_754_; lean_object* v_n_755_; lean_object* v_k_756_; lean_object* v_v_757_; uint8_t v___x_758_; 
v_n_752_ = lean_ctor_get(v_x_735_, 0);
v_k_753_ = lean_ctor_get(v_x_735_, 1);
v_v_754_ = lean_ctor_get(v_x_735_, 2);
v_n_755_ = lean_ctor_get(v_x_736_, 0);
v_k_756_ = lean_ctor_get(v_x_736_, 1);
v_v_757_ = lean_ctor_get(v_x_736_, 2);
v___x_758_ = lean_nat_dec_eq(v_n_752_, v_n_755_);
if (v___x_758_ == 0)
{
return v___x_758_;
}
else
{
uint8_t v___x_759_; 
v___x_759_ = lean_nat_dec_eq(v_k_753_, v_k_756_);
if (v___x_759_ == 0)
{
return v___x_759_;
}
else
{
uint8_t v___x_760_; 
v___x_760_ = lean_nat_dec_eq(v_v_754_, v_v_757_);
return v___x_760_;
}
}
}
case 7:
{
lean_object* v_n_761_; lean_object* v_k_762_; uint8_t v_ia_763_; lean_object* v_n_764_; lean_object* v_k_765_; uint8_t v_ia_766_; uint8_t v___x_767_; 
v_n_761_ = lean_ctor_get(v_x_735_, 0);
v_k_762_ = lean_ctor_get(v_x_735_, 1);
v_ia_763_ = lean_ctor_get_uint8(v_x_735_, sizeof(void*)*2);
v_n_764_ = lean_ctor_get(v_x_736_, 0);
v_k_765_ = lean_ctor_get(v_x_736_, 1);
v_ia_766_ = lean_ctor_get_uint8(v_x_736_, sizeof(void*)*2);
v___x_767_ = lean_nat_dec_eq(v_n_761_, v_n_764_);
if (v___x_767_ == 0)
{
return v___x_767_;
}
else
{
uint8_t v___x_768_; 
v___x_768_ = lean_nat_dec_eq(v_k_762_, v_k_765_);
if (v___x_768_ == 0)
{
return v___x_768_;
}
else
{
if (v_ia_763_ == 0)
{
if (v_ia_766_ == 0)
{
return v___x_768_;
}
else
{
return v_ia_763_;
}
}
else
{
return v_ia_766_;
}
}
}
}
case 8:
{
lean_object* v_n_769_; lean_object* v_k_770_; lean_object* v_v_771_; lean_object* v_n_772_; lean_object* v_k_773_; lean_object* v_v_774_; uint8_t v___x_775_; 
v_n_769_ = lean_ctor_get(v_x_735_, 0);
v_k_770_ = lean_ctor_get(v_x_735_, 1);
v_v_771_ = lean_ctor_get(v_x_735_, 2);
v_n_772_ = lean_ctor_get(v_x_736_, 0);
v_k_773_ = lean_ctor_get(v_x_736_, 1);
v_v_774_ = lean_ctor_get(v_x_736_, 2);
v___x_775_ = lean_nat_dec_eq(v_n_769_, v_n_772_);
if (v___x_775_ == 0)
{
return v___x_775_;
}
else
{
uint8_t v___x_776_; 
v___x_776_ = lean_nat_dec_eq(v_k_770_, v_k_773_);
if (v___x_776_ == 0)
{
return v___x_776_;
}
else
{
uint8_t v___x_777_; 
v___x_777_ = lean_nat_dec_eq(v_v_771_, v_v_774_);
return v___x_777_;
}
}
}
case 9:
{
lean_object* v_n_778_; lean_object* v_child_779_; lean_object* v_n_780_; lean_object* v_child_781_; uint8_t v___x_782_; 
v_n_778_ = lean_ctor_get(v_x_735_, 0);
v_child_779_ = lean_ctor_get(v_x_735_, 1);
v_n_780_ = lean_ctor_get(v_x_736_, 0);
v_child_781_ = lean_ctor_get(v_x_736_, 1);
v___x_782_ = lean_nat_dec_eq(v_n_778_, v_n_780_);
if (v___x_782_ == 0)
{
return v___x_782_;
}
else
{
uint8_t v___x_783_; 
v___x_783_ = lean_nat_dec_eq(v_child_779_, v_child_781_);
return v___x_783_;
}
}
case 14:
{
lean_object* v_n_784_; lean_object* v_t_785_; lean_object* v_n_786_; lean_object* v_t_787_; uint8_t v___x_788_; 
v_n_784_ = lean_ctor_get(v_x_735_, 0);
v_t_785_ = lean_ctor_get(v_x_735_, 1);
v_n_786_ = lean_ctor_get(v_x_736_, 0);
v_t_787_ = lean_ctor_get(v_x_736_, 1);
v___x_788_ = lean_nat_dec_eq(v_n_784_, v_n_786_);
if (v___x_788_ == 0)
{
return v___x_788_;
}
else
{
uint8_t v___x_789_; 
v___x_789_ = lean_nat_dec_eq(v_t_785_, v_t_787_);
return v___x_789_;
}
}
case 15:
{
lean_object* v_n_790_; lean_object* v_k_791_; lean_object* v_n_792_; lean_object* v_k_793_; uint8_t v___x_794_; 
v_n_790_ = lean_ctor_get(v_x_735_, 0);
v_k_791_ = lean_ctor_get(v_x_735_, 1);
v_n_792_ = lean_ctor_get(v_x_736_, 0);
v_k_793_ = lean_ctor_get(v_x_736_, 1);
v___x_794_ = lean_nat_dec_eq(v_n_790_, v_n_792_);
if (v___x_794_ == 0)
{
return v___x_794_;
}
else
{
uint8_t v___x_795_; 
v___x_795_ = lean_nat_dec_eq(v_k_791_, v_k_793_);
return v___x_795_;
}
}
case 16:
{
lean_object* v_n_796_; lean_object* v_child_797_; lean_object* v_n_798_; lean_object* v_child_799_; uint8_t v___x_800_; 
v_n_796_ = lean_ctor_get(v_x_735_, 0);
v_child_797_ = lean_ctor_get(v_x_735_, 1);
v_n_798_ = lean_ctor_get(v_x_736_, 0);
v_child_799_ = lean_ctor_get(v_x_736_, 1);
v___x_800_ = lean_nat_dec_eq(v_n_796_, v_n_798_);
if (v___x_800_ == 0)
{
return v___x_800_;
}
else
{
uint8_t v___x_801_; 
v___x_801_ = lean_nat_dec_eq(v_child_797_, v_child_799_);
return v___x_801_;
}
}
default: 
{
lean_object* v_n_802_; lean_object* v_n_803_; uint8_t v___x_804_; 
v_n_802_ = lean_ctor_get(v_x_735_, 0);
v_n_803_ = lean_ctor_get(v_x_736_, 0);
v___x_804_ = lean_nat_dec_eq(v_n_802_, v_n_803_);
return v___x_804_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqEvent_decEq___boxed(lean_object* v_x_805_, lean_object* v_x_806_){
_start:
{
uint8_t v_res_807_; lean_object* v_r_808_; 
v_res_807_ = lp_bounded_Bounded_instDecidableEqEvent_decEq(v_x_805_, v_x_806_);
lean_dec_ref(v_x_806_);
lean_dec_ref(v_x_805_);
v_r_808_ = lean_box(v_res_807_);
return v_r_808_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqEvent(lean_object* v_x_809_, lean_object* v_x_810_){
_start:
{
uint8_t v___x_811_; 
v___x_811_ = lp_bounded_Bounded_instDecidableEqEvent_decEq(v_x_809_, v_x_810_);
return v___x_811_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqEvent___boxed(lean_object* v_x_812_, lean_object* v_x_813_){
_start:
{
uint8_t v_res_814_; lean_object* v_r_815_; 
v_res_814_ = lp_bounded_Bounded_instDecidableEqEvent(v_x_812_, v_x_813_);
lean_dec_ref(v_x_813_);
lean_dec_ref(v_x_812_);
v_r_815_ = lean_box(v_res_814_);
return v_r_815_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprEvent_repr(lean_object* v_x_924_, lean_object* v_prec_925_){
_start:
{
switch(lean_obj_tag(v_x_924_))
{
case 0:
{
lean_object* v_n_926_; lean_object* v___x_928_; uint8_t v_isShared_929_; uint8_t v_isSharedCheck_946_; 
v_n_926_ = lean_ctor_get(v_x_924_, 0);
v_isSharedCheck_946_ = !lean_is_exclusive(v_x_924_);
if (v_isSharedCheck_946_ == 0)
{
v___x_928_ = v_x_924_;
v_isShared_929_ = v_isSharedCheck_946_;
goto v_resetjp_927_;
}
else
{
lean_inc(v_n_926_);
lean_dec(v_x_924_);
v___x_928_ = lean_box(0);
v_isShared_929_ = v_isSharedCheck_946_;
goto v_resetjp_927_;
}
v_resetjp_927_:
{
lean_object* v___y_931_; lean_object* v___x_942_; uint8_t v___x_943_; 
v___x_942_ = lean_unsigned_to_nat(1024u);
v___x_943_ = lean_nat_dec_le(v___x_942_, v_prec_925_);
if (v___x_943_ == 0)
{
lean_object* v___x_944_; 
v___x_944_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_931_ = v___x_944_;
goto v___jp_930_;
}
else
{
lean_object* v___x_945_; 
v___x_945_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_931_ = v___x_945_;
goto v___jp_930_;
}
v___jp_930_:
{
lean_object* v___x_932_; lean_object* v___x_933_; lean_object* v___x_935_; 
v___x_932_ = ((lean_object*)(lp_bounded_Bounded_instReprEvent_repr___closed__2));
v___x_933_ = l_Nat_reprFast(v_n_926_);
if (v_isShared_929_ == 0)
{
lean_ctor_set_tag(v___x_928_, 3);
lean_ctor_set(v___x_928_, 0, v___x_933_);
v___x_935_ = v___x_928_;
goto v_reusejp_934_;
}
else
{
lean_object* v_reuseFailAlloc_941_; 
v_reuseFailAlloc_941_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v_reuseFailAlloc_941_, 0, v___x_933_);
v___x_935_ = v_reuseFailAlloc_941_;
goto v_reusejp_934_;
}
v_reusejp_934_:
{
lean_object* v___x_936_; lean_object* v___x_937_; uint8_t v___x_938_; lean_object* v___x_939_; lean_object* v___x_940_; 
v___x_936_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_936_, 0, v___x_932_);
lean_ctor_set(v___x_936_, 1, v___x_935_);
lean_inc(v___y_931_);
v___x_937_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_937_, 0, v___y_931_);
lean_ctor_set(v___x_937_, 1, v___x_936_);
v___x_938_ = 0;
v___x_939_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_939_, 0, v___x_937_);
lean_ctor_set_uint8(v___x_939_, sizeof(void*)*1, v___x_938_);
v___x_940_ = l_Repr_addAppParen(v___x_939_, v_prec_925_);
return v___x_940_;
}
}
}
}
case 1:
{
lean_object* v_n_947_; lean_object* v___x_949_; uint8_t v_isShared_950_; uint8_t v_isSharedCheck_967_; 
v_n_947_ = lean_ctor_get(v_x_924_, 0);
v_isSharedCheck_967_ = !lean_is_exclusive(v_x_924_);
if (v_isSharedCheck_967_ == 0)
{
v___x_949_ = v_x_924_;
v_isShared_950_ = v_isSharedCheck_967_;
goto v_resetjp_948_;
}
else
{
lean_inc(v_n_947_);
lean_dec(v_x_924_);
v___x_949_ = lean_box(0);
v_isShared_950_ = v_isSharedCheck_967_;
goto v_resetjp_948_;
}
v_resetjp_948_:
{
lean_object* v___y_952_; lean_object* v___x_963_; uint8_t v___x_964_; 
v___x_963_ = lean_unsigned_to_nat(1024u);
v___x_964_ = lean_nat_dec_le(v___x_963_, v_prec_925_);
if (v___x_964_ == 0)
{
lean_object* v___x_965_; 
v___x_965_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_952_ = v___x_965_;
goto v___jp_951_;
}
else
{
lean_object* v___x_966_; 
v___x_966_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_952_ = v___x_966_;
goto v___jp_951_;
}
v___jp_951_:
{
lean_object* v___x_953_; lean_object* v___x_954_; lean_object* v___x_956_; 
v___x_953_ = ((lean_object*)(lp_bounded_Bounded_instReprEvent_repr___closed__5));
v___x_954_ = l_Nat_reprFast(v_n_947_);
if (v_isShared_950_ == 0)
{
lean_ctor_set_tag(v___x_949_, 3);
lean_ctor_set(v___x_949_, 0, v___x_954_);
v___x_956_ = v___x_949_;
goto v_reusejp_955_;
}
else
{
lean_object* v_reuseFailAlloc_962_; 
v_reuseFailAlloc_962_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v_reuseFailAlloc_962_, 0, v___x_954_);
v___x_956_ = v_reuseFailAlloc_962_;
goto v_reusejp_955_;
}
v_reusejp_955_:
{
lean_object* v___x_957_; lean_object* v___x_958_; uint8_t v___x_959_; lean_object* v___x_960_; lean_object* v___x_961_; 
v___x_957_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_957_, 0, v___x_953_);
lean_ctor_set(v___x_957_, 1, v___x_956_);
lean_inc(v___y_952_);
v___x_958_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_958_, 0, v___y_952_);
lean_ctor_set(v___x_958_, 1, v___x_957_);
v___x_959_ = 0;
v___x_960_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_960_, 0, v___x_958_);
lean_ctor_set_uint8(v___x_960_, sizeof(void*)*1, v___x_959_);
v___x_961_ = l_Repr_addAppParen(v___x_960_, v_prec_925_);
return v___x_961_;
}
}
}
}
case 2:
{
lean_object* v_n_968_; lean_object* v___x_970_; uint8_t v_isShared_971_; uint8_t v_isSharedCheck_988_; 
v_n_968_ = lean_ctor_get(v_x_924_, 0);
v_isSharedCheck_988_ = !lean_is_exclusive(v_x_924_);
if (v_isSharedCheck_988_ == 0)
{
v___x_970_ = v_x_924_;
v_isShared_971_ = v_isSharedCheck_988_;
goto v_resetjp_969_;
}
else
{
lean_inc(v_n_968_);
lean_dec(v_x_924_);
v___x_970_ = lean_box(0);
v_isShared_971_ = v_isSharedCheck_988_;
goto v_resetjp_969_;
}
v_resetjp_969_:
{
lean_object* v___y_973_; lean_object* v___x_984_; uint8_t v___x_985_; 
v___x_984_ = lean_unsigned_to_nat(1024u);
v___x_985_ = lean_nat_dec_le(v___x_984_, v_prec_925_);
if (v___x_985_ == 0)
{
lean_object* v___x_986_; 
v___x_986_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_973_ = v___x_986_;
goto v___jp_972_;
}
else
{
lean_object* v___x_987_; 
v___x_987_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_973_ = v___x_987_;
goto v___jp_972_;
}
v___jp_972_:
{
lean_object* v___x_974_; lean_object* v___x_975_; lean_object* v___x_977_; 
v___x_974_ = ((lean_object*)(lp_bounded_Bounded_instReprEvent_repr___closed__8));
v___x_975_ = l_Nat_reprFast(v_n_968_);
if (v_isShared_971_ == 0)
{
lean_ctor_set_tag(v___x_970_, 3);
lean_ctor_set(v___x_970_, 0, v___x_975_);
v___x_977_ = v___x_970_;
goto v_reusejp_976_;
}
else
{
lean_object* v_reuseFailAlloc_983_; 
v_reuseFailAlloc_983_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v_reuseFailAlloc_983_, 0, v___x_975_);
v___x_977_ = v_reuseFailAlloc_983_;
goto v_reusejp_976_;
}
v_reusejp_976_:
{
lean_object* v___x_978_; lean_object* v___x_979_; uint8_t v___x_980_; lean_object* v___x_981_; lean_object* v___x_982_; 
v___x_978_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_978_, 0, v___x_974_);
lean_ctor_set(v___x_978_, 1, v___x_977_);
lean_inc(v___y_973_);
v___x_979_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_979_, 0, v___y_973_);
lean_ctor_set(v___x_979_, 1, v___x_978_);
v___x_980_ = 0;
v___x_981_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_981_, 0, v___x_979_);
lean_ctor_set_uint8(v___x_981_, sizeof(void*)*1, v___x_980_);
v___x_982_ = l_Repr_addAppParen(v___x_981_, v_prec_925_);
return v___x_982_;
}
}
}
}
case 3:
{
lean_object* v_n_989_; lean_object* v___x_991_; uint8_t v_isShared_992_; uint8_t v_isSharedCheck_1009_; 
v_n_989_ = lean_ctor_get(v_x_924_, 0);
v_isSharedCheck_1009_ = !lean_is_exclusive(v_x_924_);
if (v_isSharedCheck_1009_ == 0)
{
v___x_991_ = v_x_924_;
v_isShared_992_ = v_isSharedCheck_1009_;
goto v_resetjp_990_;
}
else
{
lean_inc(v_n_989_);
lean_dec(v_x_924_);
v___x_991_ = lean_box(0);
v_isShared_992_ = v_isSharedCheck_1009_;
goto v_resetjp_990_;
}
v_resetjp_990_:
{
lean_object* v___y_994_; lean_object* v___x_1005_; uint8_t v___x_1006_; 
v___x_1005_ = lean_unsigned_to_nat(1024u);
v___x_1006_ = lean_nat_dec_le(v___x_1005_, v_prec_925_);
if (v___x_1006_ == 0)
{
lean_object* v___x_1007_; 
v___x_1007_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_994_ = v___x_1007_;
goto v___jp_993_;
}
else
{
lean_object* v___x_1008_; 
v___x_1008_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_994_ = v___x_1008_;
goto v___jp_993_;
}
v___jp_993_:
{
lean_object* v___x_995_; lean_object* v___x_996_; lean_object* v___x_998_; 
v___x_995_ = ((lean_object*)(lp_bounded_Bounded_instReprEvent_repr___closed__11));
v___x_996_ = l_Nat_reprFast(v_n_989_);
if (v_isShared_992_ == 0)
{
lean_ctor_set(v___x_991_, 0, v___x_996_);
v___x_998_ = v___x_991_;
goto v_reusejp_997_;
}
else
{
lean_object* v_reuseFailAlloc_1004_; 
v_reuseFailAlloc_1004_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1004_, 0, v___x_996_);
v___x_998_ = v_reuseFailAlloc_1004_;
goto v_reusejp_997_;
}
v_reusejp_997_:
{
lean_object* v___x_999_; lean_object* v___x_1000_; uint8_t v___x_1001_; lean_object* v___x_1002_; lean_object* v___x_1003_; 
v___x_999_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_999_, 0, v___x_995_);
lean_ctor_set(v___x_999_, 1, v___x_998_);
lean_inc(v___y_994_);
v___x_1000_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_1000_, 0, v___y_994_);
lean_ctor_set(v___x_1000_, 1, v___x_999_);
v___x_1001_ = 0;
v___x_1002_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_1002_, 0, v___x_1000_);
lean_ctor_set_uint8(v___x_1002_, sizeof(void*)*1, v___x_1001_);
v___x_1003_ = l_Repr_addAppParen(v___x_1002_, v_prec_925_);
return v___x_1003_;
}
}
}
}
case 4:
{
lean_object* v_n_1010_; lean_object* v_k_1011_; lean_object* v___x_1013_; uint8_t v_isShared_1014_; uint8_t v_isSharedCheck_1036_; 
v_n_1010_ = lean_ctor_get(v_x_924_, 0);
v_k_1011_ = lean_ctor_get(v_x_924_, 1);
v_isSharedCheck_1036_ = !lean_is_exclusive(v_x_924_);
if (v_isSharedCheck_1036_ == 0)
{
v___x_1013_ = v_x_924_;
v_isShared_1014_ = v_isSharedCheck_1036_;
goto v_resetjp_1012_;
}
else
{
lean_inc(v_k_1011_);
lean_inc(v_n_1010_);
lean_dec(v_x_924_);
v___x_1013_ = lean_box(0);
v_isShared_1014_ = v_isSharedCheck_1036_;
goto v_resetjp_1012_;
}
v_resetjp_1012_:
{
lean_object* v___y_1016_; lean_object* v___x_1032_; uint8_t v___x_1033_; 
v___x_1032_ = lean_unsigned_to_nat(1024u);
v___x_1033_ = lean_nat_dec_le(v___x_1032_, v_prec_925_);
if (v___x_1033_ == 0)
{
lean_object* v___x_1034_; 
v___x_1034_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_1016_ = v___x_1034_;
goto v___jp_1015_;
}
else
{
lean_object* v___x_1035_; 
v___x_1035_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_1016_ = v___x_1035_;
goto v___jp_1015_;
}
v___jp_1015_:
{
lean_object* v___x_1017_; lean_object* v___x_1018_; lean_object* v___x_1019_; lean_object* v___x_1020_; lean_object* v___x_1022_; 
v___x_1017_ = lean_box(1);
v___x_1018_ = ((lean_object*)(lp_bounded_Bounded_instReprEvent_repr___closed__14));
v___x_1019_ = l_Nat_reprFast(v_n_1010_);
v___x_1020_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_1020_, 0, v___x_1019_);
if (v_isShared_1014_ == 0)
{
lean_ctor_set_tag(v___x_1013_, 5);
lean_ctor_set(v___x_1013_, 1, v___x_1020_);
lean_ctor_set(v___x_1013_, 0, v___x_1018_);
v___x_1022_ = v___x_1013_;
goto v_reusejp_1021_;
}
else
{
lean_object* v_reuseFailAlloc_1031_; 
v_reuseFailAlloc_1031_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1031_, 0, v___x_1018_);
lean_ctor_set(v_reuseFailAlloc_1031_, 1, v___x_1020_);
v___x_1022_ = v_reuseFailAlloc_1031_;
goto v_reusejp_1021_;
}
v_reusejp_1021_:
{
lean_object* v___x_1023_; lean_object* v___x_1024_; lean_object* v___x_1025_; lean_object* v___x_1026_; lean_object* v___x_1027_; uint8_t v___x_1028_; lean_object* v___x_1029_; lean_object* v___x_1030_; 
v___x_1023_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_1023_, 0, v___x_1022_);
lean_ctor_set(v___x_1023_, 1, v___x_1017_);
v___x_1024_ = l_Nat_reprFast(v_k_1011_);
v___x_1025_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_1025_, 0, v___x_1024_);
v___x_1026_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_1026_, 0, v___x_1023_);
lean_ctor_set(v___x_1026_, 1, v___x_1025_);
lean_inc(v___y_1016_);
v___x_1027_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_1027_, 0, v___y_1016_);
lean_ctor_set(v___x_1027_, 1, v___x_1026_);
v___x_1028_ = 0;
v___x_1029_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_1029_, 0, v___x_1027_);
lean_ctor_set_uint8(v___x_1029_, sizeof(void*)*1, v___x_1028_);
v___x_1030_ = l_Repr_addAppParen(v___x_1029_, v_prec_925_);
return v___x_1030_;
}
}
}
}
case 5:
{
lean_object* v_n_1037_; lean_object* v_t_1038_; lean_object* v___x_1040_; uint8_t v_isShared_1041_; uint8_t v_isSharedCheck_1063_; 
v_n_1037_ = lean_ctor_get(v_x_924_, 0);
v_t_1038_ = lean_ctor_get(v_x_924_, 1);
v_isSharedCheck_1063_ = !lean_is_exclusive(v_x_924_);
if (v_isSharedCheck_1063_ == 0)
{
v___x_1040_ = v_x_924_;
v_isShared_1041_ = v_isSharedCheck_1063_;
goto v_resetjp_1039_;
}
else
{
lean_inc(v_t_1038_);
lean_inc(v_n_1037_);
lean_dec(v_x_924_);
v___x_1040_ = lean_box(0);
v_isShared_1041_ = v_isSharedCheck_1063_;
goto v_resetjp_1039_;
}
v_resetjp_1039_:
{
lean_object* v___y_1043_; lean_object* v___x_1059_; uint8_t v___x_1060_; 
v___x_1059_ = lean_unsigned_to_nat(1024u);
v___x_1060_ = lean_nat_dec_le(v___x_1059_, v_prec_925_);
if (v___x_1060_ == 0)
{
lean_object* v___x_1061_; 
v___x_1061_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_1043_ = v___x_1061_;
goto v___jp_1042_;
}
else
{
lean_object* v___x_1062_; 
v___x_1062_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_1043_ = v___x_1062_;
goto v___jp_1042_;
}
v___jp_1042_:
{
lean_object* v___x_1044_; lean_object* v___x_1045_; lean_object* v___x_1046_; lean_object* v___x_1047_; lean_object* v___x_1049_; 
v___x_1044_ = lean_box(1);
v___x_1045_ = ((lean_object*)(lp_bounded_Bounded_instReprEvent_repr___closed__17));
v___x_1046_ = l_Nat_reprFast(v_n_1037_);
v___x_1047_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_1047_, 0, v___x_1046_);
if (v_isShared_1041_ == 0)
{
lean_ctor_set(v___x_1040_, 1, v___x_1047_);
lean_ctor_set(v___x_1040_, 0, v___x_1045_);
v___x_1049_ = v___x_1040_;
goto v_reusejp_1048_;
}
else
{
lean_object* v_reuseFailAlloc_1058_; 
v_reuseFailAlloc_1058_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1058_, 0, v___x_1045_);
lean_ctor_set(v_reuseFailAlloc_1058_, 1, v___x_1047_);
v___x_1049_ = v_reuseFailAlloc_1058_;
goto v_reusejp_1048_;
}
v_reusejp_1048_:
{
lean_object* v___x_1050_; lean_object* v___x_1051_; lean_object* v___x_1052_; lean_object* v___x_1053_; lean_object* v___x_1054_; uint8_t v___x_1055_; lean_object* v___x_1056_; lean_object* v___x_1057_; 
v___x_1050_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_1050_, 0, v___x_1049_);
lean_ctor_set(v___x_1050_, 1, v___x_1044_);
v___x_1051_ = l_Nat_reprFast(v_t_1038_);
v___x_1052_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_1052_, 0, v___x_1051_);
v___x_1053_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_1053_, 0, v___x_1050_);
lean_ctor_set(v___x_1053_, 1, v___x_1052_);
lean_inc(v___y_1043_);
v___x_1054_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_1054_, 0, v___y_1043_);
lean_ctor_set(v___x_1054_, 1, v___x_1053_);
v___x_1055_ = 0;
v___x_1056_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_1056_, 0, v___x_1054_);
lean_ctor_set_uint8(v___x_1056_, sizeof(void*)*1, v___x_1055_);
v___x_1057_ = l_Repr_addAppParen(v___x_1056_, v_prec_925_);
return v___x_1057_;
}
}
}
}
case 6:
{
lean_object* v_n_1064_; lean_object* v_k_1065_; lean_object* v_v_1066_; lean_object* v___y_1068_; lean_object* v___x_1086_; uint8_t v___x_1087_; 
v_n_1064_ = lean_ctor_get(v_x_924_, 0);
lean_inc(v_n_1064_);
v_k_1065_ = lean_ctor_get(v_x_924_, 1);
lean_inc(v_k_1065_);
v_v_1066_ = lean_ctor_get(v_x_924_, 2);
lean_inc(v_v_1066_);
lean_dec_ref_known(v_x_924_, 3);
v___x_1086_ = lean_unsigned_to_nat(1024u);
v___x_1087_ = lean_nat_dec_le(v___x_1086_, v_prec_925_);
if (v___x_1087_ == 0)
{
lean_object* v___x_1088_; 
v___x_1088_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_1068_ = v___x_1088_;
goto v___jp_1067_;
}
else
{
lean_object* v___x_1089_; 
v___x_1089_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_1068_ = v___x_1089_;
goto v___jp_1067_;
}
v___jp_1067_:
{
lean_object* v___x_1069_; lean_object* v___x_1070_; lean_object* v___x_1071_; lean_object* v___x_1072_; lean_object* v___x_1073_; lean_object* v___x_1074_; lean_object* v___x_1075_; lean_object* v___x_1076_; lean_object* v___x_1077_; lean_object* v___x_1078_; lean_object* v___x_1079_; lean_object* v___x_1080_; lean_object* v___x_1081_; lean_object* v___x_1082_; uint8_t v___x_1083_; lean_object* v___x_1084_; lean_object* v___x_1085_; 
v___x_1069_ = lean_box(1);
v___x_1070_ = ((lean_object*)(lp_bounded_Bounded_instReprEvent_repr___closed__20));
v___x_1071_ = l_Nat_reprFast(v_n_1064_);
v___x_1072_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_1072_, 0, v___x_1071_);
v___x_1073_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_1073_, 0, v___x_1070_);
lean_ctor_set(v___x_1073_, 1, v___x_1072_);
v___x_1074_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_1074_, 0, v___x_1073_);
lean_ctor_set(v___x_1074_, 1, v___x_1069_);
v___x_1075_ = l_Nat_reprFast(v_k_1065_);
v___x_1076_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_1076_, 0, v___x_1075_);
v___x_1077_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_1077_, 0, v___x_1074_);
lean_ctor_set(v___x_1077_, 1, v___x_1076_);
v___x_1078_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_1078_, 0, v___x_1077_);
lean_ctor_set(v___x_1078_, 1, v___x_1069_);
v___x_1079_ = l_Nat_reprFast(v_v_1066_);
v___x_1080_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_1080_, 0, v___x_1079_);
v___x_1081_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_1081_, 0, v___x_1078_);
lean_ctor_set(v___x_1081_, 1, v___x_1080_);
lean_inc(v___y_1068_);
v___x_1082_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_1082_, 0, v___y_1068_);
lean_ctor_set(v___x_1082_, 1, v___x_1081_);
v___x_1083_ = 0;
v___x_1084_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_1084_, 0, v___x_1082_);
lean_ctor_set_uint8(v___x_1084_, sizeof(void*)*1, v___x_1083_);
v___x_1085_ = l_Repr_addAppParen(v___x_1084_, v_prec_925_);
return v___x_1085_;
}
}
case 7:
{
lean_object* v_n_1090_; lean_object* v_k_1091_; uint8_t v_ia_1092_; lean_object* v___y_1094_; lean_object* v___x_1111_; uint8_t v___x_1112_; 
v_n_1090_ = lean_ctor_get(v_x_924_, 0);
lean_inc(v_n_1090_);
v_k_1091_ = lean_ctor_get(v_x_924_, 1);
lean_inc(v_k_1091_);
v_ia_1092_ = lean_ctor_get_uint8(v_x_924_, sizeof(void*)*2);
lean_dec_ref_known(v_x_924_, 2);
v___x_1111_ = lean_unsigned_to_nat(1024u);
v___x_1112_ = lean_nat_dec_le(v___x_1111_, v_prec_925_);
if (v___x_1112_ == 0)
{
lean_object* v___x_1113_; 
v___x_1113_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_1094_ = v___x_1113_;
goto v___jp_1093_;
}
else
{
lean_object* v___x_1114_; 
v___x_1114_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_1094_ = v___x_1114_;
goto v___jp_1093_;
}
v___jp_1093_:
{
lean_object* v___x_1095_; lean_object* v___x_1096_; lean_object* v___x_1097_; lean_object* v___x_1098_; lean_object* v___x_1099_; lean_object* v___x_1100_; lean_object* v___x_1101_; lean_object* v___x_1102_; lean_object* v___x_1103_; lean_object* v___x_1104_; lean_object* v___x_1105_; lean_object* v___x_1106_; lean_object* v___x_1107_; uint8_t v___x_1108_; lean_object* v___x_1109_; lean_object* v___x_1110_; 
v___x_1095_ = lean_box(1);
v___x_1096_ = ((lean_object*)(lp_bounded_Bounded_instReprEvent_repr___closed__23));
v___x_1097_ = l_Nat_reprFast(v_n_1090_);
v___x_1098_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_1098_, 0, v___x_1097_);
v___x_1099_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_1099_, 0, v___x_1096_);
lean_ctor_set(v___x_1099_, 1, v___x_1098_);
v___x_1100_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_1100_, 0, v___x_1099_);
lean_ctor_set(v___x_1100_, 1, v___x_1095_);
v___x_1101_ = l_Nat_reprFast(v_k_1091_);
v___x_1102_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_1102_, 0, v___x_1101_);
v___x_1103_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_1103_, 0, v___x_1100_);
lean_ctor_set(v___x_1103_, 1, v___x_1102_);
v___x_1104_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_1104_, 0, v___x_1103_);
lean_ctor_set(v___x_1104_, 1, v___x_1095_);
v___x_1105_ = l_Bool_repr___redArg(v_ia_1092_);
v___x_1106_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_1106_, 0, v___x_1104_);
lean_ctor_set(v___x_1106_, 1, v___x_1105_);
lean_inc(v___y_1094_);
v___x_1107_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_1107_, 0, v___y_1094_);
lean_ctor_set(v___x_1107_, 1, v___x_1106_);
v___x_1108_ = 0;
v___x_1109_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_1109_, 0, v___x_1107_);
lean_ctor_set_uint8(v___x_1109_, sizeof(void*)*1, v___x_1108_);
v___x_1110_ = l_Repr_addAppParen(v___x_1109_, v_prec_925_);
return v___x_1110_;
}
}
case 8:
{
lean_object* v_n_1115_; lean_object* v_k_1116_; lean_object* v_v_1117_; lean_object* v___y_1119_; lean_object* v___x_1137_; uint8_t v___x_1138_; 
v_n_1115_ = lean_ctor_get(v_x_924_, 0);
lean_inc(v_n_1115_);
v_k_1116_ = lean_ctor_get(v_x_924_, 1);
lean_inc(v_k_1116_);
v_v_1117_ = lean_ctor_get(v_x_924_, 2);
lean_inc(v_v_1117_);
lean_dec_ref_known(v_x_924_, 3);
v___x_1137_ = lean_unsigned_to_nat(1024u);
v___x_1138_ = lean_nat_dec_le(v___x_1137_, v_prec_925_);
if (v___x_1138_ == 0)
{
lean_object* v___x_1139_; 
v___x_1139_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_1119_ = v___x_1139_;
goto v___jp_1118_;
}
else
{
lean_object* v___x_1140_; 
v___x_1140_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_1119_ = v___x_1140_;
goto v___jp_1118_;
}
v___jp_1118_:
{
lean_object* v___x_1120_; lean_object* v___x_1121_; lean_object* v___x_1122_; lean_object* v___x_1123_; lean_object* v___x_1124_; lean_object* v___x_1125_; lean_object* v___x_1126_; lean_object* v___x_1127_; lean_object* v___x_1128_; lean_object* v___x_1129_; lean_object* v___x_1130_; lean_object* v___x_1131_; lean_object* v___x_1132_; lean_object* v___x_1133_; uint8_t v___x_1134_; lean_object* v___x_1135_; lean_object* v___x_1136_; 
v___x_1120_ = lean_box(1);
v___x_1121_ = ((lean_object*)(lp_bounded_Bounded_instReprEvent_repr___closed__26));
v___x_1122_ = l_Nat_reprFast(v_n_1115_);
v___x_1123_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_1123_, 0, v___x_1122_);
v___x_1124_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_1124_, 0, v___x_1121_);
lean_ctor_set(v___x_1124_, 1, v___x_1123_);
v___x_1125_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_1125_, 0, v___x_1124_);
lean_ctor_set(v___x_1125_, 1, v___x_1120_);
v___x_1126_ = l_Nat_reprFast(v_k_1116_);
v___x_1127_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_1127_, 0, v___x_1126_);
v___x_1128_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_1128_, 0, v___x_1125_);
lean_ctor_set(v___x_1128_, 1, v___x_1127_);
v___x_1129_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_1129_, 0, v___x_1128_);
lean_ctor_set(v___x_1129_, 1, v___x_1120_);
v___x_1130_ = l_Nat_reprFast(v_v_1117_);
v___x_1131_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_1131_, 0, v___x_1130_);
v___x_1132_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_1132_, 0, v___x_1129_);
lean_ctor_set(v___x_1132_, 1, v___x_1131_);
lean_inc(v___y_1119_);
v___x_1133_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_1133_, 0, v___y_1119_);
lean_ctor_set(v___x_1133_, 1, v___x_1132_);
v___x_1134_ = 0;
v___x_1135_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_1135_, 0, v___x_1133_);
lean_ctor_set_uint8(v___x_1135_, sizeof(void*)*1, v___x_1134_);
v___x_1136_ = l_Repr_addAppParen(v___x_1135_, v_prec_925_);
return v___x_1136_;
}
}
case 9:
{
lean_object* v_n_1141_; lean_object* v_child_1142_; lean_object* v___x_1144_; uint8_t v_isShared_1145_; uint8_t v_isSharedCheck_1167_; 
v_n_1141_ = lean_ctor_get(v_x_924_, 0);
v_child_1142_ = lean_ctor_get(v_x_924_, 1);
v_isSharedCheck_1167_ = !lean_is_exclusive(v_x_924_);
if (v_isSharedCheck_1167_ == 0)
{
v___x_1144_ = v_x_924_;
v_isShared_1145_ = v_isSharedCheck_1167_;
goto v_resetjp_1143_;
}
else
{
lean_inc(v_child_1142_);
lean_inc(v_n_1141_);
lean_dec(v_x_924_);
v___x_1144_ = lean_box(0);
v_isShared_1145_ = v_isSharedCheck_1167_;
goto v_resetjp_1143_;
}
v_resetjp_1143_:
{
lean_object* v___y_1147_; lean_object* v___x_1163_; uint8_t v___x_1164_; 
v___x_1163_ = lean_unsigned_to_nat(1024u);
v___x_1164_ = lean_nat_dec_le(v___x_1163_, v_prec_925_);
if (v___x_1164_ == 0)
{
lean_object* v___x_1165_; 
v___x_1165_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_1147_ = v___x_1165_;
goto v___jp_1146_;
}
else
{
lean_object* v___x_1166_; 
v___x_1166_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_1147_ = v___x_1166_;
goto v___jp_1146_;
}
v___jp_1146_:
{
lean_object* v___x_1148_; lean_object* v___x_1149_; lean_object* v___x_1150_; lean_object* v___x_1151_; lean_object* v___x_1153_; 
v___x_1148_ = lean_box(1);
v___x_1149_ = ((lean_object*)(lp_bounded_Bounded_instReprEvent_repr___closed__29));
v___x_1150_ = l_Nat_reprFast(v_n_1141_);
v___x_1151_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_1151_, 0, v___x_1150_);
if (v_isShared_1145_ == 0)
{
lean_ctor_set_tag(v___x_1144_, 5);
lean_ctor_set(v___x_1144_, 1, v___x_1151_);
lean_ctor_set(v___x_1144_, 0, v___x_1149_);
v___x_1153_ = v___x_1144_;
goto v_reusejp_1152_;
}
else
{
lean_object* v_reuseFailAlloc_1162_; 
v_reuseFailAlloc_1162_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1162_, 0, v___x_1149_);
lean_ctor_set(v_reuseFailAlloc_1162_, 1, v___x_1151_);
v___x_1153_ = v_reuseFailAlloc_1162_;
goto v_reusejp_1152_;
}
v_reusejp_1152_:
{
lean_object* v___x_1154_; lean_object* v___x_1155_; lean_object* v___x_1156_; lean_object* v___x_1157_; lean_object* v___x_1158_; uint8_t v___x_1159_; lean_object* v___x_1160_; lean_object* v___x_1161_; 
v___x_1154_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_1154_, 0, v___x_1153_);
lean_ctor_set(v___x_1154_, 1, v___x_1148_);
v___x_1155_ = l_Nat_reprFast(v_child_1142_);
v___x_1156_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_1156_, 0, v___x_1155_);
v___x_1157_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_1157_, 0, v___x_1154_);
lean_ctor_set(v___x_1157_, 1, v___x_1156_);
lean_inc(v___y_1147_);
v___x_1158_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_1158_, 0, v___y_1147_);
lean_ctor_set(v___x_1158_, 1, v___x_1157_);
v___x_1159_ = 0;
v___x_1160_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_1160_, 0, v___x_1158_);
lean_ctor_set_uint8(v___x_1160_, sizeof(void*)*1, v___x_1159_);
v___x_1161_ = l_Repr_addAppParen(v___x_1160_, v_prec_925_);
return v___x_1161_;
}
}
}
}
case 10:
{
lean_object* v_n_1168_; lean_object* v___x_1170_; uint8_t v_isShared_1171_; uint8_t v_isSharedCheck_1188_; 
v_n_1168_ = lean_ctor_get(v_x_924_, 0);
v_isSharedCheck_1188_ = !lean_is_exclusive(v_x_924_);
if (v_isSharedCheck_1188_ == 0)
{
v___x_1170_ = v_x_924_;
v_isShared_1171_ = v_isSharedCheck_1188_;
goto v_resetjp_1169_;
}
else
{
lean_inc(v_n_1168_);
lean_dec(v_x_924_);
v___x_1170_ = lean_box(0);
v_isShared_1171_ = v_isSharedCheck_1188_;
goto v_resetjp_1169_;
}
v_resetjp_1169_:
{
lean_object* v___y_1173_; lean_object* v___x_1184_; uint8_t v___x_1185_; 
v___x_1184_ = lean_unsigned_to_nat(1024u);
v___x_1185_ = lean_nat_dec_le(v___x_1184_, v_prec_925_);
if (v___x_1185_ == 0)
{
lean_object* v___x_1186_; 
v___x_1186_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_1173_ = v___x_1186_;
goto v___jp_1172_;
}
else
{
lean_object* v___x_1187_; 
v___x_1187_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_1173_ = v___x_1187_;
goto v___jp_1172_;
}
v___jp_1172_:
{
lean_object* v___x_1174_; lean_object* v___x_1175_; lean_object* v___x_1177_; 
v___x_1174_ = ((lean_object*)(lp_bounded_Bounded_instReprEvent_repr___closed__32));
v___x_1175_ = l_Nat_reprFast(v_n_1168_);
if (v_isShared_1171_ == 0)
{
lean_ctor_set_tag(v___x_1170_, 3);
lean_ctor_set(v___x_1170_, 0, v___x_1175_);
v___x_1177_ = v___x_1170_;
goto v_reusejp_1176_;
}
else
{
lean_object* v_reuseFailAlloc_1183_; 
v_reuseFailAlloc_1183_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1183_, 0, v___x_1175_);
v___x_1177_ = v_reuseFailAlloc_1183_;
goto v_reusejp_1176_;
}
v_reusejp_1176_:
{
lean_object* v___x_1178_; lean_object* v___x_1179_; uint8_t v___x_1180_; lean_object* v___x_1181_; lean_object* v___x_1182_; 
v___x_1178_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_1178_, 0, v___x_1174_);
lean_ctor_set(v___x_1178_, 1, v___x_1177_);
lean_inc(v___y_1173_);
v___x_1179_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_1179_, 0, v___y_1173_);
lean_ctor_set(v___x_1179_, 1, v___x_1178_);
v___x_1180_ = 0;
v___x_1181_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_1181_, 0, v___x_1179_);
lean_ctor_set_uint8(v___x_1181_, sizeof(void*)*1, v___x_1180_);
v___x_1182_ = l_Repr_addAppParen(v___x_1181_, v_prec_925_);
return v___x_1182_;
}
}
}
}
case 11:
{
lean_object* v_n_1189_; lean_object* v___x_1191_; uint8_t v_isShared_1192_; uint8_t v_isSharedCheck_1209_; 
v_n_1189_ = lean_ctor_get(v_x_924_, 0);
v_isSharedCheck_1209_ = !lean_is_exclusive(v_x_924_);
if (v_isSharedCheck_1209_ == 0)
{
v___x_1191_ = v_x_924_;
v_isShared_1192_ = v_isSharedCheck_1209_;
goto v_resetjp_1190_;
}
else
{
lean_inc(v_n_1189_);
lean_dec(v_x_924_);
v___x_1191_ = lean_box(0);
v_isShared_1192_ = v_isSharedCheck_1209_;
goto v_resetjp_1190_;
}
v_resetjp_1190_:
{
lean_object* v___y_1194_; lean_object* v___x_1205_; uint8_t v___x_1206_; 
v___x_1205_ = lean_unsigned_to_nat(1024u);
v___x_1206_ = lean_nat_dec_le(v___x_1205_, v_prec_925_);
if (v___x_1206_ == 0)
{
lean_object* v___x_1207_; 
v___x_1207_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_1194_ = v___x_1207_;
goto v___jp_1193_;
}
else
{
lean_object* v___x_1208_; 
v___x_1208_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_1194_ = v___x_1208_;
goto v___jp_1193_;
}
v___jp_1193_:
{
lean_object* v___x_1195_; lean_object* v___x_1196_; lean_object* v___x_1198_; 
v___x_1195_ = ((lean_object*)(lp_bounded_Bounded_instReprEvent_repr___closed__35));
v___x_1196_ = l_Nat_reprFast(v_n_1189_);
if (v_isShared_1192_ == 0)
{
lean_ctor_set_tag(v___x_1191_, 3);
lean_ctor_set(v___x_1191_, 0, v___x_1196_);
v___x_1198_ = v___x_1191_;
goto v_reusejp_1197_;
}
else
{
lean_object* v_reuseFailAlloc_1204_; 
v_reuseFailAlloc_1204_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1204_, 0, v___x_1196_);
v___x_1198_ = v_reuseFailAlloc_1204_;
goto v_reusejp_1197_;
}
v_reusejp_1197_:
{
lean_object* v___x_1199_; lean_object* v___x_1200_; uint8_t v___x_1201_; lean_object* v___x_1202_; lean_object* v___x_1203_; 
v___x_1199_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_1199_, 0, v___x_1195_);
lean_ctor_set(v___x_1199_, 1, v___x_1198_);
lean_inc(v___y_1194_);
v___x_1200_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_1200_, 0, v___y_1194_);
lean_ctor_set(v___x_1200_, 1, v___x_1199_);
v___x_1201_ = 0;
v___x_1202_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_1202_, 0, v___x_1200_);
lean_ctor_set_uint8(v___x_1202_, sizeof(void*)*1, v___x_1201_);
v___x_1203_ = l_Repr_addAppParen(v___x_1202_, v_prec_925_);
return v___x_1203_;
}
}
}
}
case 12:
{
lean_object* v_n_1210_; lean_object* v___x_1212_; uint8_t v_isShared_1213_; uint8_t v_isSharedCheck_1230_; 
v_n_1210_ = lean_ctor_get(v_x_924_, 0);
v_isSharedCheck_1230_ = !lean_is_exclusive(v_x_924_);
if (v_isSharedCheck_1230_ == 0)
{
v___x_1212_ = v_x_924_;
v_isShared_1213_ = v_isSharedCheck_1230_;
goto v_resetjp_1211_;
}
else
{
lean_inc(v_n_1210_);
lean_dec(v_x_924_);
v___x_1212_ = lean_box(0);
v_isShared_1213_ = v_isSharedCheck_1230_;
goto v_resetjp_1211_;
}
v_resetjp_1211_:
{
lean_object* v___y_1215_; lean_object* v___x_1226_; uint8_t v___x_1227_; 
v___x_1226_ = lean_unsigned_to_nat(1024u);
v___x_1227_ = lean_nat_dec_le(v___x_1226_, v_prec_925_);
if (v___x_1227_ == 0)
{
lean_object* v___x_1228_; 
v___x_1228_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_1215_ = v___x_1228_;
goto v___jp_1214_;
}
else
{
lean_object* v___x_1229_; 
v___x_1229_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_1215_ = v___x_1229_;
goto v___jp_1214_;
}
v___jp_1214_:
{
lean_object* v___x_1216_; lean_object* v___x_1217_; lean_object* v___x_1219_; 
v___x_1216_ = ((lean_object*)(lp_bounded_Bounded_instReprEvent_repr___closed__38));
v___x_1217_ = l_Nat_reprFast(v_n_1210_);
if (v_isShared_1213_ == 0)
{
lean_ctor_set_tag(v___x_1212_, 3);
lean_ctor_set(v___x_1212_, 0, v___x_1217_);
v___x_1219_ = v___x_1212_;
goto v_reusejp_1218_;
}
else
{
lean_object* v_reuseFailAlloc_1225_; 
v_reuseFailAlloc_1225_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1225_, 0, v___x_1217_);
v___x_1219_ = v_reuseFailAlloc_1225_;
goto v_reusejp_1218_;
}
v_reusejp_1218_:
{
lean_object* v___x_1220_; lean_object* v___x_1221_; uint8_t v___x_1222_; lean_object* v___x_1223_; lean_object* v___x_1224_; 
v___x_1220_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_1220_, 0, v___x_1216_);
lean_ctor_set(v___x_1220_, 1, v___x_1219_);
lean_inc(v___y_1215_);
v___x_1221_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_1221_, 0, v___y_1215_);
lean_ctor_set(v___x_1221_, 1, v___x_1220_);
v___x_1222_ = 0;
v___x_1223_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_1223_, 0, v___x_1221_);
lean_ctor_set_uint8(v___x_1223_, sizeof(void*)*1, v___x_1222_);
v___x_1224_ = l_Repr_addAppParen(v___x_1223_, v_prec_925_);
return v___x_1224_;
}
}
}
}
case 13:
{
lean_object* v_n_1231_; lean_object* v___x_1233_; uint8_t v_isShared_1234_; uint8_t v_isSharedCheck_1251_; 
v_n_1231_ = lean_ctor_get(v_x_924_, 0);
v_isSharedCheck_1251_ = !lean_is_exclusive(v_x_924_);
if (v_isSharedCheck_1251_ == 0)
{
v___x_1233_ = v_x_924_;
v_isShared_1234_ = v_isSharedCheck_1251_;
goto v_resetjp_1232_;
}
else
{
lean_inc(v_n_1231_);
lean_dec(v_x_924_);
v___x_1233_ = lean_box(0);
v_isShared_1234_ = v_isSharedCheck_1251_;
goto v_resetjp_1232_;
}
v_resetjp_1232_:
{
lean_object* v___y_1236_; lean_object* v___x_1247_; uint8_t v___x_1248_; 
v___x_1247_ = lean_unsigned_to_nat(1024u);
v___x_1248_ = lean_nat_dec_le(v___x_1247_, v_prec_925_);
if (v___x_1248_ == 0)
{
lean_object* v___x_1249_; 
v___x_1249_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_1236_ = v___x_1249_;
goto v___jp_1235_;
}
else
{
lean_object* v___x_1250_; 
v___x_1250_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_1236_ = v___x_1250_;
goto v___jp_1235_;
}
v___jp_1235_:
{
lean_object* v___x_1237_; lean_object* v___x_1238_; lean_object* v___x_1240_; 
v___x_1237_ = ((lean_object*)(lp_bounded_Bounded_instReprEvent_repr___closed__41));
v___x_1238_ = l_Nat_reprFast(v_n_1231_);
if (v_isShared_1234_ == 0)
{
lean_ctor_set_tag(v___x_1233_, 3);
lean_ctor_set(v___x_1233_, 0, v___x_1238_);
v___x_1240_ = v___x_1233_;
goto v_reusejp_1239_;
}
else
{
lean_object* v_reuseFailAlloc_1246_; 
v_reuseFailAlloc_1246_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1246_, 0, v___x_1238_);
v___x_1240_ = v_reuseFailAlloc_1246_;
goto v_reusejp_1239_;
}
v_reusejp_1239_:
{
lean_object* v___x_1241_; lean_object* v___x_1242_; uint8_t v___x_1243_; lean_object* v___x_1244_; lean_object* v___x_1245_; 
v___x_1241_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_1241_, 0, v___x_1237_);
lean_ctor_set(v___x_1241_, 1, v___x_1240_);
lean_inc(v___y_1236_);
v___x_1242_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_1242_, 0, v___y_1236_);
lean_ctor_set(v___x_1242_, 1, v___x_1241_);
v___x_1243_ = 0;
v___x_1244_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_1244_, 0, v___x_1242_);
lean_ctor_set_uint8(v___x_1244_, sizeof(void*)*1, v___x_1243_);
v___x_1245_ = l_Repr_addAppParen(v___x_1244_, v_prec_925_);
return v___x_1245_;
}
}
}
}
case 14:
{
lean_object* v_n_1252_; lean_object* v_t_1253_; lean_object* v___x_1255_; uint8_t v_isShared_1256_; uint8_t v_isSharedCheck_1278_; 
v_n_1252_ = lean_ctor_get(v_x_924_, 0);
v_t_1253_ = lean_ctor_get(v_x_924_, 1);
v_isSharedCheck_1278_ = !lean_is_exclusive(v_x_924_);
if (v_isSharedCheck_1278_ == 0)
{
v___x_1255_ = v_x_924_;
v_isShared_1256_ = v_isSharedCheck_1278_;
goto v_resetjp_1254_;
}
else
{
lean_inc(v_t_1253_);
lean_inc(v_n_1252_);
lean_dec(v_x_924_);
v___x_1255_ = lean_box(0);
v_isShared_1256_ = v_isSharedCheck_1278_;
goto v_resetjp_1254_;
}
v_resetjp_1254_:
{
lean_object* v___y_1258_; lean_object* v___x_1274_; uint8_t v___x_1275_; 
v___x_1274_ = lean_unsigned_to_nat(1024u);
v___x_1275_ = lean_nat_dec_le(v___x_1274_, v_prec_925_);
if (v___x_1275_ == 0)
{
lean_object* v___x_1276_; 
v___x_1276_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_1258_ = v___x_1276_;
goto v___jp_1257_;
}
else
{
lean_object* v___x_1277_; 
v___x_1277_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_1258_ = v___x_1277_;
goto v___jp_1257_;
}
v___jp_1257_:
{
lean_object* v___x_1259_; lean_object* v___x_1260_; lean_object* v___x_1261_; lean_object* v___x_1262_; lean_object* v___x_1264_; 
v___x_1259_ = lean_box(1);
v___x_1260_ = ((lean_object*)(lp_bounded_Bounded_instReprEvent_repr___closed__44));
v___x_1261_ = l_Nat_reprFast(v_n_1252_);
v___x_1262_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_1262_, 0, v___x_1261_);
if (v_isShared_1256_ == 0)
{
lean_ctor_set_tag(v___x_1255_, 5);
lean_ctor_set(v___x_1255_, 1, v___x_1262_);
lean_ctor_set(v___x_1255_, 0, v___x_1260_);
v___x_1264_ = v___x_1255_;
goto v_reusejp_1263_;
}
else
{
lean_object* v_reuseFailAlloc_1273_; 
v_reuseFailAlloc_1273_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1273_, 0, v___x_1260_);
lean_ctor_set(v_reuseFailAlloc_1273_, 1, v___x_1262_);
v___x_1264_ = v_reuseFailAlloc_1273_;
goto v_reusejp_1263_;
}
v_reusejp_1263_:
{
lean_object* v___x_1265_; lean_object* v___x_1266_; lean_object* v___x_1267_; lean_object* v___x_1268_; lean_object* v___x_1269_; uint8_t v___x_1270_; lean_object* v___x_1271_; lean_object* v___x_1272_; 
v___x_1265_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_1265_, 0, v___x_1264_);
lean_ctor_set(v___x_1265_, 1, v___x_1259_);
v___x_1266_ = l_Nat_reprFast(v_t_1253_);
v___x_1267_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_1267_, 0, v___x_1266_);
v___x_1268_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_1268_, 0, v___x_1265_);
lean_ctor_set(v___x_1268_, 1, v___x_1267_);
lean_inc(v___y_1258_);
v___x_1269_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_1269_, 0, v___y_1258_);
lean_ctor_set(v___x_1269_, 1, v___x_1268_);
v___x_1270_ = 0;
v___x_1271_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_1271_, 0, v___x_1269_);
lean_ctor_set_uint8(v___x_1271_, sizeof(void*)*1, v___x_1270_);
v___x_1272_ = l_Repr_addAppParen(v___x_1271_, v_prec_925_);
return v___x_1272_;
}
}
}
}
case 15:
{
lean_object* v_n_1279_; lean_object* v_k_1280_; lean_object* v___x_1282_; uint8_t v_isShared_1283_; uint8_t v_isSharedCheck_1305_; 
v_n_1279_ = lean_ctor_get(v_x_924_, 0);
v_k_1280_ = lean_ctor_get(v_x_924_, 1);
v_isSharedCheck_1305_ = !lean_is_exclusive(v_x_924_);
if (v_isSharedCheck_1305_ == 0)
{
v___x_1282_ = v_x_924_;
v_isShared_1283_ = v_isSharedCheck_1305_;
goto v_resetjp_1281_;
}
else
{
lean_inc(v_k_1280_);
lean_inc(v_n_1279_);
lean_dec(v_x_924_);
v___x_1282_ = lean_box(0);
v_isShared_1283_ = v_isSharedCheck_1305_;
goto v_resetjp_1281_;
}
v_resetjp_1281_:
{
lean_object* v___y_1285_; lean_object* v___x_1301_; uint8_t v___x_1302_; 
v___x_1301_ = lean_unsigned_to_nat(1024u);
v___x_1302_ = lean_nat_dec_le(v___x_1301_, v_prec_925_);
if (v___x_1302_ == 0)
{
lean_object* v___x_1303_; 
v___x_1303_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_1285_ = v___x_1303_;
goto v___jp_1284_;
}
else
{
lean_object* v___x_1304_; 
v___x_1304_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_1285_ = v___x_1304_;
goto v___jp_1284_;
}
v___jp_1284_:
{
lean_object* v___x_1286_; lean_object* v___x_1287_; lean_object* v___x_1288_; lean_object* v___x_1289_; lean_object* v___x_1291_; 
v___x_1286_ = lean_box(1);
v___x_1287_ = ((lean_object*)(lp_bounded_Bounded_instReprEvent_repr___closed__47));
v___x_1288_ = l_Nat_reprFast(v_n_1279_);
v___x_1289_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_1289_, 0, v___x_1288_);
if (v_isShared_1283_ == 0)
{
lean_ctor_set_tag(v___x_1282_, 5);
lean_ctor_set(v___x_1282_, 1, v___x_1289_);
lean_ctor_set(v___x_1282_, 0, v___x_1287_);
v___x_1291_ = v___x_1282_;
goto v_reusejp_1290_;
}
else
{
lean_object* v_reuseFailAlloc_1300_; 
v_reuseFailAlloc_1300_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1300_, 0, v___x_1287_);
lean_ctor_set(v_reuseFailAlloc_1300_, 1, v___x_1289_);
v___x_1291_ = v_reuseFailAlloc_1300_;
goto v_reusejp_1290_;
}
v_reusejp_1290_:
{
lean_object* v___x_1292_; lean_object* v___x_1293_; lean_object* v___x_1294_; lean_object* v___x_1295_; lean_object* v___x_1296_; uint8_t v___x_1297_; lean_object* v___x_1298_; lean_object* v___x_1299_; 
v___x_1292_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_1292_, 0, v___x_1291_);
lean_ctor_set(v___x_1292_, 1, v___x_1286_);
v___x_1293_ = l_Nat_reprFast(v_k_1280_);
v___x_1294_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_1294_, 0, v___x_1293_);
v___x_1295_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_1295_, 0, v___x_1292_);
lean_ctor_set(v___x_1295_, 1, v___x_1294_);
lean_inc(v___y_1285_);
v___x_1296_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_1296_, 0, v___y_1285_);
lean_ctor_set(v___x_1296_, 1, v___x_1295_);
v___x_1297_ = 0;
v___x_1298_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_1298_, 0, v___x_1296_);
lean_ctor_set_uint8(v___x_1298_, sizeof(void*)*1, v___x_1297_);
v___x_1299_ = l_Repr_addAppParen(v___x_1298_, v_prec_925_);
return v___x_1299_;
}
}
}
}
case 16:
{
lean_object* v_n_1306_; lean_object* v_child_1307_; lean_object* v___x_1309_; uint8_t v_isShared_1310_; uint8_t v_isSharedCheck_1332_; 
v_n_1306_ = lean_ctor_get(v_x_924_, 0);
v_child_1307_ = lean_ctor_get(v_x_924_, 1);
v_isSharedCheck_1332_ = !lean_is_exclusive(v_x_924_);
if (v_isSharedCheck_1332_ == 0)
{
v___x_1309_ = v_x_924_;
v_isShared_1310_ = v_isSharedCheck_1332_;
goto v_resetjp_1308_;
}
else
{
lean_inc(v_child_1307_);
lean_inc(v_n_1306_);
lean_dec(v_x_924_);
v___x_1309_ = lean_box(0);
v_isShared_1310_ = v_isSharedCheck_1332_;
goto v_resetjp_1308_;
}
v_resetjp_1308_:
{
lean_object* v___y_1312_; lean_object* v___x_1328_; uint8_t v___x_1329_; 
v___x_1328_ = lean_unsigned_to_nat(1024u);
v___x_1329_ = lean_nat_dec_le(v___x_1328_, v_prec_925_);
if (v___x_1329_ == 0)
{
lean_object* v___x_1330_; 
v___x_1330_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_1312_ = v___x_1330_;
goto v___jp_1311_;
}
else
{
lean_object* v___x_1331_; 
v___x_1331_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_1312_ = v___x_1331_;
goto v___jp_1311_;
}
v___jp_1311_:
{
lean_object* v___x_1313_; lean_object* v___x_1314_; lean_object* v___x_1315_; lean_object* v___x_1316_; lean_object* v___x_1318_; 
v___x_1313_ = lean_box(1);
v___x_1314_ = ((lean_object*)(lp_bounded_Bounded_instReprEvent_repr___closed__50));
v___x_1315_ = l_Nat_reprFast(v_n_1306_);
v___x_1316_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_1316_, 0, v___x_1315_);
if (v_isShared_1310_ == 0)
{
lean_ctor_set_tag(v___x_1309_, 5);
lean_ctor_set(v___x_1309_, 1, v___x_1316_);
lean_ctor_set(v___x_1309_, 0, v___x_1314_);
v___x_1318_ = v___x_1309_;
goto v_reusejp_1317_;
}
else
{
lean_object* v_reuseFailAlloc_1327_; 
v_reuseFailAlloc_1327_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1327_, 0, v___x_1314_);
lean_ctor_set(v_reuseFailAlloc_1327_, 1, v___x_1316_);
v___x_1318_ = v_reuseFailAlloc_1327_;
goto v_reusejp_1317_;
}
v_reusejp_1317_:
{
lean_object* v___x_1319_; lean_object* v___x_1320_; lean_object* v___x_1321_; lean_object* v___x_1322_; lean_object* v___x_1323_; uint8_t v___x_1324_; lean_object* v___x_1325_; lean_object* v___x_1326_; 
v___x_1319_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_1319_, 0, v___x_1318_);
lean_ctor_set(v___x_1319_, 1, v___x_1313_);
v___x_1320_ = l_Nat_reprFast(v_child_1307_);
v___x_1321_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_1321_, 0, v___x_1320_);
v___x_1322_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_1322_, 0, v___x_1319_);
lean_ctor_set(v___x_1322_, 1, v___x_1321_);
lean_inc(v___y_1312_);
v___x_1323_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_1323_, 0, v___y_1312_);
lean_ctor_set(v___x_1323_, 1, v___x_1322_);
v___x_1324_ = 0;
v___x_1325_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_1325_, 0, v___x_1323_);
lean_ctor_set_uint8(v___x_1325_, sizeof(void*)*1, v___x_1324_);
v___x_1326_ = l_Repr_addAppParen(v___x_1325_, v_prec_925_);
return v___x_1326_;
}
}
}
}
default: 
{
lean_object* v_n_1333_; lean_object* v___x_1335_; uint8_t v_isShared_1336_; uint8_t v_isSharedCheck_1353_; 
v_n_1333_ = lean_ctor_get(v_x_924_, 0);
v_isSharedCheck_1353_ = !lean_is_exclusive(v_x_924_);
if (v_isSharedCheck_1353_ == 0)
{
v___x_1335_ = v_x_924_;
v_isShared_1336_ = v_isSharedCheck_1353_;
goto v_resetjp_1334_;
}
else
{
lean_inc(v_n_1333_);
lean_dec(v_x_924_);
v___x_1335_ = lean_box(0);
v_isShared_1336_ = v_isSharedCheck_1353_;
goto v_resetjp_1334_;
}
v_resetjp_1334_:
{
lean_object* v___y_1338_; lean_object* v___x_1349_; uint8_t v___x_1350_; 
v___x_1349_ = lean_unsigned_to_nat(1024u);
v___x_1350_ = lean_nat_dec_le(v___x_1349_, v_prec_925_);
if (v___x_1350_ == 0)
{
lean_object* v___x_1351_; 
v___x_1351_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_1338_ = v___x_1351_;
goto v___jp_1337_;
}
else
{
lean_object* v___x_1352_; 
v___x_1352_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_1338_ = v___x_1352_;
goto v___jp_1337_;
}
v___jp_1337_:
{
lean_object* v___x_1339_; lean_object* v___x_1340_; lean_object* v___x_1342_; 
v___x_1339_ = ((lean_object*)(lp_bounded_Bounded_instReprEvent_repr___closed__53));
v___x_1340_ = l_Nat_reprFast(v_n_1333_);
if (v_isShared_1336_ == 0)
{
lean_ctor_set_tag(v___x_1335_, 3);
lean_ctor_set(v___x_1335_, 0, v___x_1340_);
v___x_1342_ = v___x_1335_;
goto v_reusejp_1341_;
}
else
{
lean_object* v_reuseFailAlloc_1348_; 
v_reuseFailAlloc_1348_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1348_, 0, v___x_1340_);
v___x_1342_ = v_reuseFailAlloc_1348_;
goto v_reusejp_1341_;
}
v_reusejp_1341_:
{
lean_object* v___x_1343_; lean_object* v___x_1344_; uint8_t v___x_1345_; lean_object* v___x_1346_; lean_object* v___x_1347_; 
v___x_1343_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_1343_, 0, v___x_1339_);
lean_ctor_set(v___x_1343_, 1, v___x_1342_);
lean_inc(v___y_1338_);
v___x_1344_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_1344_, 0, v___y_1338_);
lean_ctor_set(v___x_1344_, 1, v___x_1343_);
v___x_1345_ = 0;
v___x_1346_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_1346_, 0, v___x_1344_);
lean_ctor_set_uint8(v___x_1346_, sizeof(void*)*1, v___x_1345_);
v___x_1347_ = l_Repr_addAppParen(v___x_1346_, v_prec_925_);
return v___x_1347_;
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprEvent_repr___boxed(lean_object* v_x_1354_, lean_object* v_prec_1355_){
_start:
{
lean_object* v_res_1356_; 
v_res_1356_ = lp_bounded_Bounded_instReprEvent_repr(v_x_1354_, v_prec_1355_);
lean_dec(v_prec_1355_);
return v_res_1356_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_ctorIdx(uint8_t v_x_1359_){
_start:
{
switch(v_x_1359_)
{
case 0:
{
lean_object* v___x_1360_; 
v___x_1360_ = lean_unsigned_to_nat(0u);
return v___x_1360_;
}
case 1:
{
lean_object* v___x_1361_; 
v___x_1361_ = lean_unsigned_to_nat(1u);
return v___x_1361_;
}
case 2:
{
lean_object* v___x_1362_; 
v___x_1362_ = lean_unsigned_to_nat(2u);
return v___x_1362_;
}
case 3:
{
lean_object* v___x_1363_; 
v___x_1363_ = lean_unsigned_to_nat(3u);
return v___x_1363_;
}
case 4:
{
lean_object* v___x_1364_; 
v___x_1364_ = lean_unsigned_to_nat(4u);
return v___x_1364_;
}
case 5:
{
lean_object* v___x_1365_; 
v___x_1365_ = lean_unsigned_to_nat(5u);
return v___x_1365_;
}
default: 
{
lean_object* v___x_1366_; 
v___x_1366_ = lean_unsigned_to_nat(6u);
return v___x_1366_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_ctorIdx___boxed(lean_object* v_x_1367_){
_start:
{
uint8_t v_x_boxed_1368_; lean_object* v_res_1369_; 
v_x_boxed_1368_ = lean_unbox(v_x_1367_);
v_res_1369_ = lp_bounded_Bounded_StCls_ctorIdx(v_x_boxed_1368_);
return v_res_1369_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_toCtorIdx(uint8_t v_x_1370_){
_start:
{
lean_object* v___x_1371_; 
v___x_1371_ = lp_bounded_Bounded_StCls_ctorIdx(v_x_1370_);
return v___x_1371_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_toCtorIdx___boxed(lean_object* v_x_1372_){
_start:
{
uint8_t v_x_4__boxed_1373_; lean_object* v_res_1374_; 
v_x_4__boxed_1373_ = lean_unbox(v_x_1372_);
v_res_1374_ = lp_bounded_Bounded_StCls_toCtorIdx(v_x_4__boxed_1373_);
return v_res_1374_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_ctorElim___redArg(lean_object* v_k_1375_){
_start:
{
lean_inc(v_k_1375_);
return v_k_1375_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_ctorElim___redArg___boxed(lean_object* v_k_1376_){
_start:
{
lean_object* v_res_1377_; 
v_res_1377_ = lp_bounded_Bounded_StCls_ctorElim___redArg(v_k_1376_);
lean_dec(v_k_1376_);
return v_res_1377_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_ctorElim(lean_object* v_motive_1378_, lean_object* v_ctorIdx_1379_, uint8_t v_t_1380_, lean_object* v_h_1381_, lean_object* v_k_1382_){
_start:
{
lean_inc(v_k_1382_);
return v_k_1382_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_ctorElim___boxed(lean_object* v_motive_1383_, lean_object* v_ctorIdx_1384_, lean_object* v_t_1385_, lean_object* v_h_1386_, lean_object* v_k_1387_){
_start:
{
uint8_t v_t_boxed_1388_; lean_object* v_res_1389_; 
v_t_boxed_1388_ = lean_unbox(v_t_1385_);
v_res_1389_ = lp_bounded_Bounded_StCls_ctorElim(v_motive_1383_, v_ctorIdx_1384_, v_t_boxed_1388_, v_h_1386_, v_k_1387_);
lean_dec(v_k_1387_);
lean_dec(v_ctorIdx_1384_);
return v_res_1389_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_absent_elim___redArg(lean_object* v_absent_1390_){
_start:
{
lean_inc(v_absent_1390_);
return v_absent_1390_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_absent_elim___redArg___boxed(lean_object* v_absent_1391_){
_start:
{
lean_object* v_res_1392_; 
v_res_1392_ = lp_bounded_Bounded_StCls_absent_elim___redArg(v_absent_1391_);
lean_dec(v_absent_1391_);
return v_res_1392_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_absent_elim(lean_object* v_motive_1393_, uint8_t v_t_1394_, lean_object* v_h_1395_, lean_object* v_absent_1396_){
_start:
{
lean_inc(v_absent_1396_);
return v_absent_1396_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_absent_elim___boxed(lean_object* v_motive_1397_, lean_object* v_t_1398_, lean_object* v_h_1399_, lean_object* v_absent_1400_){
_start:
{
uint8_t v_t_boxed_1401_; lean_object* v_res_1402_; 
v_t_boxed_1401_ = lean_unbox(v_t_1398_);
v_res_1402_ = lp_bounded_Bounded_StCls_absent_elim(v_motive_1397_, v_t_boxed_1401_, v_h_1399_, v_absent_1400_);
lean_dec(v_absent_1400_);
return v_res_1402_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_inactOk_elim___redArg(lean_object* v_inactOk_1403_){
_start:
{
lean_inc(v_inactOk_1403_);
return v_inactOk_1403_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_inactOk_elim___redArg___boxed(lean_object* v_inactOk_1404_){
_start:
{
lean_object* v_res_1405_; 
v_res_1405_ = lp_bounded_Bounded_StCls_inactOk_elim___redArg(v_inactOk_1404_);
lean_dec(v_inactOk_1404_);
return v_res_1405_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_inactOk_elim(lean_object* v_motive_1406_, uint8_t v_t_1407_, lean_object* v_h_1408_, lean_object* v_inactOk_1409_){
_start:
{
lean_inc(v_inactOk_1409_);
return v_inactOk_1409_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_inactOk_elim___boxed(lean_object* v_motive_1410_, lean_object* v_t_1411_, lean_object* v_h_1412_, lean_object* v_inactOk_1413_){
_start:
{
uint8_t v_t_boxed_1414_; lean_object* v_res_1415_; 
v_t_boxed_1414_ = lean_unbox(v_t_1411_);
v_res_1415_ = lp_bounded_Bounded_StCls_inactOk_elim(v_motive_1410_, v_t_boxed_1414_, v_h_1412_, v_inactOk_1413_);
lean_dec(v_inactOk_1413_);
return v_res_1415_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_inactErr_elim___redArg(lean_object* v_inactErr_1416_){
_start:
{
lean_inc(v_inactErr_1416_);
return v_inactErr_1416_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_inactErr_elim___redArg___boxed(lean_object* v_inactErr_1417_){
_start:
{
lean_object* v_res_1418_; 
v_res_1418_ = lp_bounded_Bounded_StCls_inactErr_elim___redArg(v_inactErr_1417_);
lean_dec(v_inactErr_1417_);
return v_res_1418_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_inactErr_elim(lean_object* v_motive_1419_, uint8_t v_t_1420_, lean_object* v_h_1421_, lean_object* v_inactErr_1422_){
_start:
{
lean_inc(v_inactErr_1422_);
return v_inactErr_1422_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_inactErr_elim___boxed(lean_object* v_motive_1423_, lean_object* v_t_1424_, lean_object* v_h_1425_, lean_object* v_inactErr_1426_){
_start:
{
uint8_t v_t_boxed_1427_; lean_object* v_res_1428_; 
v_t_boxed_1427_ = lean_unbox(v_t_1424_);
v_res_1428_ = lp_bounded_Bounded_StCls_inactErr_elim(v_motive_1423_, v_t_boxed_1427_, v_h_1425_, v_inactErr_1426_);
lean_dec(v_inactErr_1426_);
return v_res_1428_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_reload_elim___redArg(lean_object* v_reload_1429_){
_start:
{
lean_inc(v_reload_1429_);
return v_reload_1429_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_reload_elim___redArg___boxed(lean_object* v_reload_1430_){
_start:
{
lean_object* v_res_1431_; 
v_res_1431_ = lp_bounded_Bounded_StCls_reload_elim___redArg(v_reload_1430_);
lean_dec(v_reload_1430_);
return v_res_1431_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_reload_elim(lean_object* v_motive_1432_, uint8_t v_t_1433_, lean_object* v_h_1434_, lean_object* v_reload_1435_){
_start:
{
lean_inc(v_reload_1435_);
return v_reload_1435_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_reload_elim___boxed(lean_object* v_motive_1436_, lean_object* v_t_1437_, lean_object* v_h_1438_, lean_object* v_reload_1439_){
_start:
{
uint8_t v_t_boxed_1440_; lean_object* v_res_1441_; 
v_t_boxed_1440_ = lean_unbox(v_t_1437_);
v_res_1441_ = lp_bounded_Bounded_StCls_reload_elim(v_motive_1436_, v_t_boxed_1440_, v_h_1438_, v_reload_1439_);
lean_dec(v_reload_1439_);
return v_res_1441_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_activeS_elim___redArg(lean_object* v_activeS_1442_){
_start:
{
lean_inc(v_activeS_1442_);
return v_activeS_1442_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_activeS_elim___redArg___boxed(lean_object* v_activeS_1443_){
_start:
{
lean_object* v_res_1444_; 
v_res_1444_ = lp_bounded_Bounded_StCls_activeS_elim___redArg(v_activeS_1443_);
lean_dec(v_activeS_1443_);
return v_res_1444_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_activeS_elim(lean_object* v_motive_1445_, uint8_t v_t_1446_, lean_object* v_h_1447_, lean_object* v_activeS_1448_){
_start:
{
lean_inc(v_activeS_1448_);
return v_activeS_1448_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_activeS_elim___boxed(lean_object* v_motive_1449_, lean_object* v_t_1450_, lean_object* v_h_1451_, lean_object* v_activeS_1452_){
_start:
{
uint8_t v_t_boxed_1453_; lean_object* v_res_1454_; 
v_t_boxed_1453_ = lean_unbox(v_t_1450_);
v_res_1454_ = lp_bounded_Bounded_StCls_activeS_elim(v_motive_1449_, v_t_boxed_1453_, v_h_1451_, v_activeS_1452_);
lean_dec(v_activeS_1452_);
return v_res_1454_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_unloadOk_elim___redArg(lean_object* v_unloadOk_1455_){
_start:
{
lean_inc(v_unloadOk_1455_);
return v_unloadOk_1455_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_unloadOk_elim___redArg___boxed(lean_object* v_unloadOk_1456_){
_start:
{
lean_object* v_res_1457_; 
v_res_1457_ = lp_bounded_Bounded_StCls_unloadOk_elim___redArg(v_unloadOk_1456_);
lean_dec(v_unloadOk_1456_);
return v_res_1457_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_unloadOk_elim(lean_object* v_motive_1458_, uint8_t v_t_1459_, lean_object* v_h_1460_, lean_object* v_unloadOk_1461_){
_start:
{
lean_inc(v_unloadOk_1461_);
return v_unloadOk_1461_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_unloadOk_elim___boxed(lean_object* v_motive_1462_, lean_object* v_t_1463_, lean_object* v_h_1464_, lean_object* v_unloadOk_1465_){
_start:
{
uint8_t v_t_boxed_1466_; lean_object* v_res_1467_; 
v_t_boxed_1466_ = lean_unbox(v_t_1463_);
v_res_1467_ = lp_bounded_Bounded_StCls_unloadOk_elim(v_motive_1462_, v_t_boxed_1466_, v_h_1464_, v_unloadOk_1465_);
lean_dec(v_unloadOk_1465_);
return v_res_1467_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_unloadErr_elim___redArg(lean_object* v_unloadErr_1468_){
_start:
{
lean_inc(v_unloadErr_1468_);
return v_unloadErr_1468_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_unloadErr_elim___redArg___boxed(lean_object* v_unloadErr_1469_){
_start:
{
lean_object* v_res_1470_; 
v_res_1470_ = lp_bounded_Bounded_StCls_unloadErr_elim___redArg(v_unloadErr_1469_);
lean_dec(v_unloadErr_1469_);
return v_res_1470_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_unloadErr_elim(lean_object* v_motive_1471_, uint8_t v_t_1472_, lean_object* v_h_1473_, lean_object* v_unloadErr_1474_){
_start:
{
lean_inc(v_unloadErr_1474_);
return v_unloadErr_1474_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_unloadErr_elim___boxed(lean_object* v_motive_1475_, lean_object* v_t_1476_, lean_object* v_h_1477_, lean_object* v_unloadErr_1478_){
_start:
{
uint8_t v_t_boxed_1479_; lean_object* v_res_1480_; 
v_t_boxed_1479_ = lean_unbox(v_t_1476_);
v_res_1480_ = lp_bounded_Bounded_StCls_unloadErr_elim(v_motive_1475_, v_t_boxed_1479_, v_h_1477_, v_unloadErr_1478_);
lean_dec(v_unloadErr_1478_);
return v_res_1480_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_StCls_ofNat(lean_object* v_n_1481_){
_start:
{
lean_object* v___x_1482_; uint8_t v___x_1483_; 
v___x_1482_ = lean_unsigned_to_nat(2u);
v___x_1483_ = lean_nat_dec_le(v_n_1481_, v___x_1482_);
if (v___x_1483_ == 0)
{
lean_object* v___x_1484_; uint8_t v___x_1485_; 
v___x_1484_ = lean_unsigned_to_nat(4u);
v___x_1485_ = lean_nat_dec_le(v_n_1481_, v___x_1484_);
if (v___x_1485_ == 0)
{
lean_object* v___x_1486_; uint8_t v___x_1487_; 
v___x_1486_ = lean_unsigned_to_nat(5u);
v___x_1487_ = lean_nat_dec_le(v_n_1481_, v___x_1486_);
if (v___x_1487_ == 0)
{
uint8_t v___x_1488_; 
v___x_1488_ = 6;
return v___x_1488_;
}
else
{
uint8_t v___x_1489_; 
v___x_1489_ = 5;
return v___x_1489_;
}
}
else
{
lean_object* v___x_1490_; uint8_t v___x_1491_; 
v___x_1490_ = lean_unsigned_to_nat(3u);
v___x_1491_ = lean_nat_dec_le(v_n_1481_, v___x_1490_);
if (v___x_1491_ == 0)
{
uint8_t v___x_1492_; 
v___x_1492_ = 4;
return v___x_1492_;
}
else
{
uint8_t v___x_1493_; 
v___x_1493_ = 3;
return v___x_1493_;
}
}
}
else
{
lean_object* v___x_1494_; uint8_t v___x_1495_; 
v___x_1494_ = lean_unsigned_to_nat(0u);
v___x_1495_ = lean_nat_dec_le(v_n_1481_, v___x_1494_);
if (v___x_1495_ == 0)
{
lean_object* v___x_1496_; uint8_t v___x_1497_; 
v___x_1496_ = lean_unsigned_to_nat(1u);
v___x_1497_ = lean_nat_dec_le(v_n_1481_, v___x_1496_);
if (v___x_1497_ == 0)
{
uint8_t v___x_1498_; 
v___x_1498_ = 2;
return v___x_1498_;
}
else
{
uint8_t v___x_1499_; 
v___x_1499_ = 1;
return v___x_1499_;
}
}
else
{
uint8_t v___x_1500_; 
v___x_1500_ = 0;
return v___x_1500_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StCls_ofNat___boxed(lean_object* v_n_1501_){
_start:
{
uint8_t v_res_1502_; lean_object* v_r_1503_; 
v_res_1502_ = lp_bounded_Bounded_StCls_ofNat(v_n_1501_);
lean_dec(v_n_1501_);
v_r_1503_ = lean_box(v_res_1502_);
return v_r_1503_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqStCls(uint8_t v_x_1504_, uint8_t v_y_1505_){
_start:
{
lean_object* v___x_1506_; lean_object* v___x_1507_; uint8_t v___x_1508_; 
v___x_1506_ = lp_bounded_Bounded_StCls_ctorIdx(v_x_1504_);
v___x_1507_ = lp_bounded_Bounded_StCls_ctorIdx(v_y_1505_);
v___x_1508_ = lean_nat_dec_eq(v___x_1506_, v___x_1507_);
lean_dec(v___x_1507_);
lean_dec(v___x_1506_);
return v___x_1508_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqStCls___boxed(lean_object* v_x_1509_, lean_object* v_y_1510_){
_start:
{
uint8_t v_x_13__boxed_1511_; uint8_t v_y_14__boxed_1512_; uint8_t v_res_1513_; lean_object* v_r_1514_; 
v_x_13__boxed_1511_ = lean_unbox(v_x_1509_);
v_y_14__boxed_1512_ = lean_unbox(v_y_1510_);
v_res_1513_ = lp_bounded_Bounded_instDecidableEqStCls(v_x_13__boxed_1511_, v_y_14__boxed_1512_);
v_r_1514_ = lean_box(v_res_1513_);
return v_r_1514_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprStCls_repr(uint8_t v_x_1536_, lean_object* v_prec_1537_){
_start:
{
lean_object* v___y_1539_; lean_object* v___y_1546_; lean_object* v___y_1553_; lean_object* v___y_1560_; lean_object* v___y_1567_; lean_object* v___y_1574_; lean_object* v___y_1581_; 
switch(v_x_1536_)
{
case 0:
{
lean_object* v___x_1587_; uint8_t v___x_1588_; 
v___x_1587_ = lean_unsigned_to_nat(1024u);
v___x_1588_ = lean_nat_dec_le(v___x_1587_, v_prec_1537_);
if (v___x_1588_ == 0)
{
lean_object* v___x_1589_; 
v___x_1589_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_1539_ = v___x_1589_;
goto v___jp_1538_;
}
else
{
lean_object* v___x_1590_; 
v___x_1590_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_1539_ = v___x_1590_;
goto v___jp_1538_;
}
}
case 1:
{
lean_object* v___x_1591_; uint8_t v___x_1592_; 
v___x_1591_ = lean_unsigned_to_nat(1024u);
v___x_1592_ = lean_nat_dec_le(v___x_1591_, v_prec_1537_);
if (v___x_1592_ == 0)
{
lean_object* v___x_1593_; 
v___x_1593_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_1546_ = v___x_1593_;
goto v___jp_1545_;
}
else
{
lean_object* v___x_1594_; 
v___x_1594_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_1546_ = v___x_1594_;
goto v___jp_1545_;
}
}
case 2:
{
lean_object* v___x_1595_; uint8_t v___x_1596_; 
v___x_1595_ = lean_unsigned_to_nat(1024u);
v___x_1596_ = lean_nat_dec_le(v___x_1595_, v_prec_1537_);
if (v___x_1596_ == 0)
{
lean_object* v___x_1597_; 
v___x_1597_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_1553_ = v___x_1597_;
goto v___jp_1552_;
}
else
{
lean_object* v___x_1598_; 
v___x_1598_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_1553_ = v___x_1598_;
goto v___jp_1552_;
}
}
case 3:
{
lean_object* v___x_1599_; uint8_t v___x_1600_; 
v___x_1599_ = lean_unsigned_to_nat(1024u);
v___x_1600_ = lean_nat_dec_le(v___x_1599_, v_prec_1537_);
if (v___x_1600_ == 0)
{
lean_object* v___x_1601_; 
v___x_1601_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_1560_ = v___x_1601_;
goto v___jp_1559_;
}
else
{
lean_object* v___x_1602_; 
v___x_1602_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_1560_ = v___x_1602_;
goto v___jp_1559_;
}
}
case 4:
{
lean_object* v___x_1603_; uint8_t v___x_1604_; 
v___x_1603_ = lean_unsigned_to_nat(1024u);
v___x_1604_ = lean_nat_dec_le(v___x_1603_, v_prec_1537_);
if (v___x_1604_ == 0)
{
lean_object* v___x_1605_; 
v___x_1605_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_1567_ = v___x_1605_;
goto v___jp_1566_;
}
else
{
lean_object* v___x_1606_; 
v___x_1606_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_1567_ = v___x_1606_;
goto v___jp_1566_;
}
}
case 5:
{
lean_object* v___x_1607_; uint8_t v___x_1608_; 
v___x_1607_ = lean_unsigned_to_nat(1024u);
v___x_1608_ = lean_nat_dec_le(v___x_1607_, v_prec_1537_);
if (v___x_1608_ == 0)
{
lean_object* v___x_1609_; 
v___x_1609_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_1574_ = v___x_1609_;
goto v___jp_1573_;
}
else
{
lean_object* v___x_1610_; 
v___x_1610_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_1574_ = v___x_1610_;
goto v___jp_1573_;
}
}
default: 
{
lean_object* v___x_1611_; uint8_t v___x_1612_; 
v___x_1611_ = lean_unsigned_to_nat(1024u);
v___x_1612_ = lean_nat_dec_le(v___x_1611_, v_prec_1537_);
if (v___x_1612_ == 0)
{
lean_object* v___x_1613_; 
v___x_1613_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_1581_ = v___x_1613_;
goto v___jp_1580_;
}
else
{
lean_object* v___x_1614_; 
v___x_1614_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_1581_ = v___x_1614_;
goto v___jp_1580_;
}
}
}
v___jp_1538_:
{
lean_object* v___x_1540_; lean_object* v___x_1541_; uint8_t v___x_1542_; lean_object* v___x_1543_; lean_object* v___x_1544_; 
v___x_1540_ = ((lean_object*)(lp_bounded_Bounded_instReprStCls_repr___closed__1));
lean_inc(v___y_1539_);
v___x_1541_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_1541_, 0, v___y_1539_);
lean_ctor_set(v___x_1541_, 1, v___x_1540_);
v___x_1542_ = 0;
v___x_1543_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_1543_, 0, v___x_1541_);
lean_ctor_set_uint8(v___x_1543_, sizeof(void*)*1, v___x_1542_);
v___x_1544_ = l_Repr_addAppParen(v___x_1543_, v_prec_1537_);
return v___x_1544_;
}
v___jp_1545_:
{
lean_object* v___x_1547_; lean_object* v___x_1548_; uint8_t v___x_1549_; lean_object* v___x_1550_; lean_object* v___x_1551_; 
v___x_1547_ = ((lean_object*)(lp_bounded_Bounded_instReprStCls_repr___closed__3));
lean_inc(v___y_1546_);
v___x_1548_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_1548_, 0, v___y_1546_);
lean_ctor_set(v___x_1548_, 1, v___x_1547_);
v___x_1549_ = 0;
v___x_1550_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_1550_, 0, v___x_1548_);
lean_ctor_set_uint8(v___x_1550_, sizeof(void*)*1, v___x_1549_);
v___x_1551_ = l_Repr_addAppParen(v___x_1550_, v_prec_1537_);
return v___x_1551_;
}
v___jp_1552_:
{
lean_object* v___x_1554_; lean_object* v___x_1555_; uint8_t v___x_1556_; lean_object* v___x_1557_; lean_object* v___x_1558_; 
v___x_1554_ = ((lean_object*)(lp_bounded_Bounded_instReprStCls_repr___closed__5));
lean_inc(v___y_1553_);
v___x_1555_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_1555_, 0, v___y_1553_);
lean_ctor_set(v___x_1555_, 1, v___x_1554_);
v___x_1556_ = 0;
v___x_1557_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_1557_, 0, v___x_1555_);
lean_ctor_set_uint8(v___x_1557_, sizeof(void*)*1, v___x_1556_);
v___x_1558_ = l_Repr_addAppParen(v___x_1557_, v_prec_1537_);
return v___x_1558_;
}
v___jp_1559_:
{
lean_object* v___x_1561_; lean_object* v___x_1562_; uint8_t v___x_1563_; lean_object* v___x_1564_; lean_object* v___x_1565_; 
v___x_1561_ = ((lean_object*)(lp_bounded_Bounded_instReprStCls_repr___closed__7));
lean_inc(v___y_1560_);
v___x_1562_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_1562_, 0, v___y_1560_);
lean_ctor_set(v___x_1562_, 1, v___x_1561_);
v___x_1563_ = 0;
v___x_1564_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_1564_, 0, v___x_1562_);
lean_ctor_set_uint8(v___x_1564_, sizeof(void*)*1, v___x_1563_);
v___x_1565_ = l_Repr_addAppParen(v___x_1564_, v_prec_1537_);
return v___x_1565_;
}
v___jp_1566_:
{
lean_object* v___x_1568_; lean_object* v___x_1569_; uint8_t v___x_1570_; lean_object* v___x_1571_; lean_object* v___x_1572_; 
v___x_1568_ = ((lean_object*)(lp_bounded_Bounded_instReprStCls_repr___closed__9));
lean_inc(v___y_1567_);
v___x_1569_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_1569_, 0, v___y_1567_);
lean_ctor_set(v___x_1569_, 1, v___x_1568_);
v___x_1570_ = 0;
v___x_1571_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_1571_, 0, v___x_1569_);
lean_ctor_set_uint8(v___x_1571_, sizeof(void*)*1, v___x_1570_);
v___x_1572_ = l_Repr_addAppParen(v___x_1571_, v_prec_1537_);
return v___x_1572_;
}
v___jp_1573_:
{
lean_object* v___x_1575_; lean_object* v___x_1576_; uint8_t v___x_1577_; lean_object* v___x_1578_; lean_object* v___x_1579_; 
v___x_1575_ = ((lean_object*)(lp_bounded_Bounded_instReprStCls_repr___closed__11));
lean_inc(v___y_1574_);
v___x_1576_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_1576_, 0, v___y_1574_);
lean_ctor_set(v___x_1576_, 1, v___x_1575_);
v___x_1577_ = 0;
v___x_1578_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_1578_, 0, v___x_1576_);
lean_ctor_set_uint8(v___x_1578_, sizeof(void*)*1, v___x_1577_);
v___x_1579_ = l_Repr_addAppParen(v___x_1578_, v_prec_1537_);
return v___x_1579_;
}
v___jp_1580_:
{
lean_object* v___x_1582_; lean_object* v___x_1583_; uint8_t v___x_1584_; lean_object* v___x_1585_; lean_object* v___x_1586_; 
v___x_1582_ = ((lean_object*)(lp_bounded_Bounded_instReprStCls_repr___closed__13));
lean_inc(v___y_1581_);
v___x_1583_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_1583_, 0, v___y_1581_);
lean_ctor_set(v___x_1583_, 1, v___x_1582_);
v___x_1584_ = 0;
v___x_1585_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_1585_, 0, v___x_1583_);
lean_ctor_set_uint8(v___x_1585_, sizeof(void*)*1, v___x_1584_);
v___x_1586_ = l_Repr_addAppParen(v___x_1585_, v_prec_1537_);
return v___x_1586_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprStCls_repr___boxed(lean_object* v_x_1615_, lean_object* v_prec_1616_){
_start:
{
uint8_t v_x_397__boxed_1617_; lean_object* v_res_1618_; 
v_x_397__boxed_1617_ = lean_unbox(v_x_1615_);
v_res_1618_ = lp_bounded_Bounded_instReprStCls_repr(v_x_397__boxed_1617_, v_prec_1616_);
lean_dec(v_prec_1616_);
return v_res_1618_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_stClsOf(lean_object* v_x_1621_){
_start:
{
if (lean_obj_tag(v_x_1621_) == 0)
{
uint8_t v___x_1622_; 
v___x_1622_ = 0;
return v___x_1622_;
}
else
{
lean_object* v_val_1623_; lean_object* v_st_1624_; 
v_val_1623_ = lean_ctor_get(v_x_1621_, 0);
v_st_1624_ = lean_ctor_get(v_val_1623_, 3);
switch(lean_obj_tag(v_st_1624_))
{
case 0:
{
uint8_t v_o_1625_; 
v_o_1625_ = lean_ctor_get_uint8(v_st_1624_, 0);
if (v_o_1625_ == 0)
{
uint8_t v___x_1626_; 
v___x_1626_ = 1;
return v___x_1626_;
}
else
{
uint8_t v___x_1627_; 
v___x_1627_ = 2;
return v___x_1627_;
}
}
case 1:
{
uint8_t v___x_1628_; 
v___x_1628_ = 3;
return v___x_1628_;
}
case 2:
{
uint8_t v___x_1629_; 
v___x_1629_ = 4;
return v___x_1629_;
}
default: 
{
uint8_t v_o_1630_; 
v_o_1630_ = lean_ctor_get_uint8(v_st_1624_, sizeof(void*)*2);
if (v_o_1630_ == 0)
{
uint8_t v___x_1631_; 
v___x_1631_ = 5;
return v___x_1631_;
}
else
{
uint8_t v___x_1632_; 
v___x_1632_ = 6;
return v___x_1632_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_stClsOf___boxed(lean_object* v_x_1633_){
_start:
{
uint8_t v_res_1634_; lean_object* v_r_1635_; 
v_res_1634_ = lp_bounded_Bounded_stClsOf(v_x_1633_);
lean_dec(v_x_1633_);
v_r_1635_ = lean_box(v_res_1634_);
return v_r_1635_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_retiredOf(lean_object* v_x_1636_){
_start:
{
if (lean_obj_tag(v_x_1636_) == 0)
{
uint8_t v___x_1637_; 
v___x_1637_ = 0;
return v___x_1637_;
}
else
{
lean_object* v_val_1638_; uint8_t v_retired_1639_; 
v_val_1638_ = lean_ctor_get(v_x_1636_, 0);
v_retired_1639_ = lean_ctor_get_uint8(v_val_1638_, sizeof(void*)*4);
return v_retired_1639_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_retiredOf___boxed(lean_object* v_x_1640_){
_start:
{
uint8_t v_res_1641_; lean_object* v_r_1642_; 
v_res_1641_ = lp_bounded_Bounded_retiredOf(v_x_1640_);
lean_dec(v_x_1640_);
v_r_1642_ = lean_box(v_res_1641_);
return v_r_1642_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_TRel_ctorIdx(uint8_t v_x_1643_){
_start:
{
switch(v_x_1643_)
{
case 0:
{
lean_object* v___x_1644_; 
v___x_1644_ = lean_unsigned_to_nat(0u);
return v___x_1644_;
}
case 1:
{
lean_object* v___x_1645_; 
v___x_1645_ = lean_unsigned_to_nat(1u);
return v___x_1645_;
}
default: 
{
lean_object* v___x_1646_; 
v___x_1646_ = lean_unsigned_to_nat(2u);
return v___x_1646_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_TRel_ctorIdx___boxed(lean_object* v_x_1647_){
_start:
{
uint8_t v_x_boxed_1648_; lean_object* v_res_1649_; 
v_x_boxed_1648_ = lean_unbox(v_x_1647_);
v_res_1649_ = lp_bounded_Bounded_TRel_ctorIdx(v_x_boxed_1648_);
return v_res_1649_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_TRel_toCtorIdx(uint8_t v_x_1650_){
_start:
{
lean_object* v___x_1651_; 
v___x_1651_ = lp_bounded_Bounded_TRel_ctorIdx(v_x_1650_);
return v___x_1651_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_TRel_toCtorIdx___boxed(lean_object* v_x_1652_){
_start:
{
uint8_t v_x_4__boxed_1653_; lean_object* v_res_1654_; 
v_x_4__boxed_1653_ = lean_unbox(v_x_1652_);
v_res_1654_ = lp_bounded_Bounded_TRel_toCtorIdx(v_x_4__boxed_1653_);
return v_res_1654_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_TRel_ctorElim___redArg(lean_object* v_k_1655_){
_start:
{
lean_inc(v_k_1655_);
return v_k_1655_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_TRel_ctorElim___redArg___boxed(lean_object* v_k_1656_){
_start:
{
lean_object* v_res_1657_; 
v_res_1657_ = lp_bounded_Bounded_TRel_ctorElim___redArg(v_k_1656_);
lean_dec(v_k_1656_);
return v_res_1657_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_TRel_ctorElim(lean_object* v_motive_1658_, lean_object* v_ctorIdx_1659_, uint8_t v_t_1660_, lean_object* v_h_1661_, lean_object* v_k_1662_){
_start:
{
lean_inc(v_k_1662_);
return v_k_1662_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_TRel_ctorElim___boxed(lean_object* v_motive_1663_, lean_object* v_ctorIdx_1664_, lean_object* v_t_1665_, lean_object* v_h_1666_, lean_object* v_k_1667_){
_start:
{
uint8_t v_t_boxed_1668_; lean_object* v_res_1669_; 
v_t_boxed_1668_ = lean_unbox(v_t_1665_);
v_res_1669_ = lp_bounded_Bounded_TRel_ctorElim(v_motive_1663_, v_ctorIdx_1664_, v_t_boxed_1668_, v_h_1666_, v_k_1667_);
lean_dec(v_k_1667_);
lean_dec(v_ctorIdx_1664_);
return v_res_1669_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_TRel_bot_elim___redArg(lean_object* v_bot_1670_){
_start:
{
lean_inc(v_bot_1670_);
return v_bot_1670_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_TRel_bot_elim___redArg___boxed(lean_object* v_bot_1671_){
_start:
{
lean_object* v_res_1672_; 
v_res_1672_ = lp_bounded_Bounded_TRel_bot_elim___redArg(v_bot_1671_);
lean_dec(v_bot_1671_);
return v_res_1672_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_TRel_bot_elim(lean_object* v_motive_1673_, uint8_t v_t_1674_, lean_object* v_h_1675_, lean_object* v_bot_1676_){
_start:
{
lean_inc(v_bot_1676_);
return v_bot_1676_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_TRel_bot_elim___boxed(lean_object* v_motive_1677_, lean_object* v_t_1678_, lean_object* v_h_1679_, lean_object* v_bot_1680_){
_start:
{
uint8_t v_t_boxed_1681_; lean_object* v_res_1682_; 
v_t_boxed_1681_ = lean_unbox(v_t_1678_);
v_res_1682_ = lp_bounded_Bounded_TRel_bot_elim(v_motive_1677_, v_t_boxed_1681_, v_h_1679_, v_bot_1680_);
lean_dec(v_bot_1680_);
return v_res_1682_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_TRel_eq_elim___redArg(lean_object* v_eq_1683_){
_start:
{
lean_inc(v_eq_1683_);
return v_eq_1683_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_TRel_eq_elim___redArg___boxed(lean_object* v_eq_1684_){
_start:
{
lean_object* v_res_1685_; 
v_res_1685_ = lp_bounded_Bounded_TRel_eq_elim___redArg(v_eq_1684_);
lean_dec(v_eq_1684_);
return v_res_1685_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_TRel_eq_elim(lean_object* v_motive_1686_, uint8_t v_t_1687_, lean_object* v_h_1688_, lean_object* v_eq_1689_){
_start:
{
lean_inc(v_eq_1689_);
return v_eq_1689_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_TRel_eq_elim___boxed(lean_object* v_motive_1690_, lean_object* v_t_1691_, lean_object* v_h_1692_, lean_object* v_eq_1693_){
_start:
{
uint8_t v_t_boxed_1694_; lean_object* v_res_1695_; 
v_t_boxed_1694_ = lean_unbox(v_t_1691_);
v_res_1695_ = lp_bounded_Bounded_TRel_eq_elim(v_motive_1690_, v_t_boxed_1694_, v_h_1692_, v_eq_1693_);
lean_dec(v_eq_1693_);
return v_res_1695_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_TRel_ne_elim___redArg(lean_object* v_ne_1696_){
_start:
{
lean_inc(v_ne_1696_);
return v_ne_1696_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_TRel_ne_elim___redArg___boxed(lean_object* v_ne_1697_){
_start:
{
lean_object* v_res_1698_; 
v_res_1698_ = lp_bounded_Bounded_TRel_ne_elim___redArg(v_ne_1697_);
lean_dec(v_ne_1697_);
return v_res_1698_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_TRel_ne_elim(lean_object* v_motive_1699_, uint8_t v_t_1700_, lean_object* v_h_1701_, lean_object* v_ne_1702_){
_start:
{
lean_inc(v_ne_1702_);
return v_ne_1702_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_TRel_ne_elim___boxed(lean_object* v_motive_1703_, lean_object* v_t_1704_, lean_object* v_h_1705_, lean_object* v_ne_1706_){
_start:
{
uint8_t v_t_boxed_1707_; lean_object* v_res_1708_; 
v_t_boxed_1707_ = lean_unbox(v_t_1704_);
v_res_1708_ = lp_bounded_Bounded_TRel_ne_elim(v_motive_1703_, v_t_boxed_1707_, v_h_1705_, v_ne_1706_);
lean_dec(v_ne_1706_);
return v_res_1708_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_TRel_ofNat(lean_object* v_n_1709_){
_start:
{
lean_object* v___x_1710_; uint8_t v___x_1711_; 
v___x_1710_ = lean_unsigned_to_nat(0u);
v___x_1711_ = lean_nat_dec_le(v_n_1709_, v___x_1710_);
if (v___x_1711_ == 0)
{
lean_object* v___x_1712_; uint8_t v___x_1713_; 
v___x_1712_ = lean_unsigned_to_nat(1u);
v___x_1713_ = lean_nat_dec_le(v_n_1709_, v___x_1712_);
if (v___x_1713_ == 0)
{
uint8_t v___x_1714_; 
v___x_1714_ = 2;
return v___x_1714_;
}
else
{
uint8_t v___x_1715_; 
v___x_1715_ = 1;
return v___x_1715_;
}
}
else
{
uint8_t v___x_1716_; 
v___x_1716_ = 0;
return v___x_1716_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_TRel_ofNat___boxed(lean_object* v_n_1717_){
_start:
{
uint8_t v_res_1718_; lean_object* v_r_1719_; 
v_res_1718_ = lp_bounded_Bounded_TRel_ofNat(v_n_1717_);
lean_dec(v_n_1717_);
v_r_1719_ = lean_box(v_res_1718_);
return v_r_1719_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqTRel(uint8_t v_x_1720_, uint8_t v_y_1721_){
_start:
{
lean_object* v___x_1722_; lean_object* v___x_1723_; uint8_t v___x_1724_; 
v___x_1722_ = lp_bounded_Bounded_TRel_ctorIdx(v_x_1720_);
v___x_1723_ = lp_bounded_Bounded_TRel_ctorIdx(v_y_1721_);
v___x_1724_ = lean_nat_dec_eq(v___x_1722_, v___x_1723_);
lean_dec(v___x_1723_);
lean_dec(v___x_1722_);
return v___x_1724_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqTRel___boxed(lean_object* v_x_1725_, lean_object* v_y_1726_){
_start:
{
uint8_t v_x_13__boxed_1727_; uint8_t v_y_14__boxed_1728_; uint8_t v_res_1729_; lean_object* v_r_1730_; 
v_x_13__boxed_1727_ = lean_unbox(v_x_1725_);
v_y_14__boxed_1728_ = lean_unbox(v_y_1726_);
v_res_1729_ = lp_bounded_Bounded_instDecidableEqTRel(v_x_13__boxed_1727_, v_y_14__boxed_1728_);
v_r_1730_ = lean_box(v_res_1729_);
return v_r_1730_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprTRel_repr(uint8_t v_x_1740_, lean_object* v_prec_1741_){
_start:
{
lean_object* v___y_1743_; lean_object* v___y_1750_; lean_object* v___y_1757_; 
switch(v_x_1740_)
{
case 0:
{
lean_object* v___x_1763_; uint8_t v___x_1764_; 
v___x_1763_ = lean_unsigned_to_nat(1024u);
v___x_1764_ = lean_nat_dec_le(v___x_1763_, v_prec_1741_);
if (v___x_1764_ == 0)
{
lean_object* v___x_1765_; 
v___x_1765_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_1743_ = v___x_1765_;
goto v___jp_1742_;
}
else
{
lean_object* v___x_1766_; 
v___x_1766_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_1743_ = v___x_1766_;
goto v___jp_1742_;
}
}
case 1:
{
lean_object* v___x_1767_; uint8_t v___x_1768_; 
v___x_1767_ = lean_unsigned_to_nat(1024u);
v___x_1768_ = lean_nat_dec_le(v___x_1767_, v_prec_1741_);
if (v___x_1768_ == 0)
{
lean_object* v___x_1769_; 
v___x_1769_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_1750_ = v___x_1769_;
goto v___jp_1749_;
}
else
{
lean_object* v___x_1770_; 
v___x_1770_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_1750_ = v___x_1770_;
goto v___jp_1749_;
}
}
default: 
{
lean_object* v___x_1771_; uint8_t v___x_1772_; 
v___x_1771_ = lean_unsigned_to_nat(1024u);
v___x_1772_ = lean_nat_dec_le(v___x_1771_, v_prec_1741_);
if (v___x_1772_ == 0)
{
lean_object* v___x_1773_; 
v___x_1773_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_1757_ = v___x_1773_;
goto v___jp_1756_;
}
else
{
lean_object* v___x_1774_; 
v___x_1774_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_1757_ = v___x_1774_;
goto v___jp_1756_;
}
}
}
v___jp_1742_:
{
lean_object* v___x_1744_; lean_object* v___x_1745_; uint8_t v___x_1746_; lean_object* v___x_1747_; lean_object* v___x_1748_; 
v___x_1744_ = ((lean_object*)(lp_bounded_Bounded_instReprTRel_repr___closed__1));
lean_inc(v___y_1743_);
v___x_1745_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_1745_, 0, v___y_1743_);
lean_ctor_set(v___x_1745_, 1, v___x_1744_);
v___x_1746_ = 0;
v___x_1747_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_1747_, 0, v___x_1745_);
lean_ctor_set_uint8(v___x_1747_, sizeof(void*)*1, v___x_1746_);
v___x_1748_ = l_Repr_addAppParen(v___x_1747_, v_prec_1741_);
return v___x_1748_;
}
v___jp_1749_:
{
lean_object* v___x_1751_; lean_object* v___x_1752_; uint8_t v___x_1753_; lean_object* v___x_1754_; lean_object* v___x_1755_; 
v___x_1751_ = ((lean_object*)(lp_bounded_Bounded_instReprTRel_repr___closed__3));
lean_inc(v___y_1750_);
v___x_1752_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_1752_, 0, v___y_1750_);
lean_ctor_set(v___x_1752_, 1, v___x_1751_);
v___x_1753_ = 0;
v___x_1754_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_1754_, 0, v___x_1752_);
lean_ctor_set_uint8(v___x_1754_, sizeof(void*)*1, v___x_1753_);
v___x_1755_ = l_Repr_addAppParen(v___x_1754_, v_prec_1741_);
return v___x_1755_;
}
v___jp_1756_:
{
lean_object* v___x_1758_; lean_object* v___x_1759_; uint8_t v___x_1760_; lean_object* v___x_1761_; lean_object* v___x_1762_; 
v___x_1758_ = ((lean_object*)(lp_bounded_Bounded_instReprTRel_repr___closed__5));
lean_inc(v___y_1757_);
v___x_1759_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_1759_, 0, v___y_1757_);
lean_ctor_set(v___x_1759_, 1, v___x_1758_);
v___x_1760_ = 0;
v___x_1761_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_1761_, 0, v___x_1759_);
lean_ctor_set_uint8(v___x_1761_, sizeof(void*)*1, v___x_1760_);
v___x_1762_ = l_Repr_addAppParen(v___x_1761_, v_prec_1741_);
return v___x_1762_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprTRel_repr___boxed(lean_object* v_x_1775_, lean_object* v_prec_1776_){
_start:
{
uint8_t v_x_173__boxed_1777_; lean_object* v_res_1778_; 
v_x_173__boxed_1777_ = lean_unbox(v_x_1775_);
v_res_1778_ = lp_bounded_Bounded_instReprTRel_repr(v_x_173__boxed_1777_, v_prec_1776_);
lean_dec(v_prec_1776_);
return v_res_1778_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_tRelOf___lam__0(lean_object* v_a_1781_, lean_object* v_b_1782_){
_start:
{
lean_object* v___x_1783_; uint8_t v___x_1784_; 
v___x_1783_ = ((lean_object*)(lp_bounded_Bounded_instDecidableEqAct_decEq___closed__0));
v___x_1784_ = l_Option_instDecidableEq___redArg(v___x_1783_, v_a_1781_, v_b_1782_);
return v___x_1784_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_tRelOf___lam__0___boxed(lean_object* v_a_1785_, lean_object* v_b_1786_){
_start:
{
uint8_t v_res_1787_; lean_object* v_r_1788_; 
v_res_1787_ = lp_bounded_Bounded_tRelOf___lam__0(v_a_1785_, v_b_1786_);
v_r_1788_ = lean_box(v_res_1787_);
return v_r_1788_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_tRelOf(lean_object* v_00_u03b3_1790_, lean_object* v_n_1791_){
_start:
{
lean_object* v___x_1792_; 
v___x_1792_ = lp_bounded_Bounded_SMap_get___redArg(v_00_u03b3_1790_, v_n_1791_);
if (lean_obj_tag(v___x_1792_) == 0)
{
uint8_t v___x_1793_; 
lean_dec_ref(v_00_u03b3_1790_);
v___x_1793_ = 0;
return v___x_1793_;
}
else
{
lean_object* v_val_1794_; lean_object* v___x_1795_; 
v_val_1794_ = lean_ctor_get(v___x_1792_, 0);
lean_inc(v_val_1794_);
lean_dec_ref_known(v___x_1792_, 1);
v___x_1795_ = lp_bounded_Bounded_targetOf(v_00_u03b3_1790_, v_n_1791_);
if (lean_obj_tag(v___x_1795_) == 0)
{
uint8_t v___x_1796_; 
lean_dec(v_val_1794_);
v___x_1796_ = 0;
return v___x_1796_;
}
else
{
lean_object* v_val_1797_; lean_object* v_st_1798_; lean_object* v___x_1799_; 
v_val_1797_ = lean_ctor_get(v___x_1795_, 0);
lean_inc(v_val_1797_);
lean_dec_ref_known(v___x_1795_, 1);
v_st_1798_ = lean_ctor_get(v_val_1794_, 3);
lean_inc_ref(v_st_1798_);
lean_dec(v_val_1794_);
v___x_1799_ = lp_bounded_Bounded_LState_viewOf(v_st_1798_);
lean_dec_ref(v_st_1798_);
if (lean_obj_tag(v___x_1799_) == 0)
{
uint8_t v___x_1800_; 
lean_dec(v_val_1797_);
v___x_1800_ = 2;
return v___x_1800_;
}
else
{
lean_object* v_val_1801_; lean_object* v___f_1802_; uint8_t v___x_1803_; 
v_val_1801_ = lean_ctor_get(v___x_1799_, 0);
lean_inc(v_val_1801_);
lean_dec_ref_known(v___x_1799_, 1);
v___f_1802_ = ((lean_object*)(lp_bounded_Bounded_tRelOf___closed__0));
v___x_1803_ = lp_bounded_Bounded_instDecidableEqKMap_decEq___redArg(v___f_1802_, v_val_1797_, v_val_1801_);
if (v___x_1803_ == 0)
{
uint8_t v___x_1804_; 
v___x_1804_ = 2;
return v___x_1804_;
}
else
{
uint8_t v___x_1805_; 
v___x_1805_ = 1;
return v___x_1805_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_tRelOf___boxed(lean_object* v_00_u03b3_1806_, lean_object* v_n_1807_){
_start:
{
uint8_t v_res_1808_; lean_object* v_r_1809_; 
v_res_1808_ = lp_bounded_Bounded_tRelOf(v_00_u03b3_1806_, v_n_1807_);
lean_dec(v_n_1807_);
v_r_1809_ = lean_box(v_res_1808_);
return v_r_1809_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadCls_ctorIdx(uint8_t v_x_1810_){
_start:
{
switch(v_x_1810_)
{
case 0:
{
lean_object* v___x_1811_; 
v___x_1811_ = lean_unsigned_to_nat(0u);
return v___x_1811_;
}
case 1:
{
lean_object* v___x_1812_; 
v___x_1812_ = lean_unsigned_to_nat(1u);
return v___x_1812_;
}
case 2:
{
lean_object* v___x_1813_; 
v___x_1813_ = lean_unsigned_to_nat(2u);
return v___x_1813_;
}
default: 
{
lean_object* v___x_1814_; 
v___x_1814_ = lean_unsigned_to_nat(3u);
return v___x_1814_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadCls_ctorIdx___boxed(lean_object* v_x_1815_){
_start:
{
uint8_t v_x_boxed_1816_; lean_object* v_res_1817_; 
v_x_boxed_1816_ = lean_unbox(v_x_1815_);
v_res_1817_ = lp_bounded_Bounded_ReadCls_ctorIdx(v_x_boxed_1816_);
return v_res_1817_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadCls_toCtorIdx(uint8_t v_x_1818_){
_start:
{
lean_object* v___x_1819_; 
v___x_1819_ = lp_bounded_Bounded_ReadCls_ctorIdx(v_x_1818_);
return v___x_1819_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadCls_toCtorIdx___boxed(lean_object* v_x_1820_){
_start:
{
uint8_t v_x_4__boxed_1821_; lean_object* v_res_1822_; 
v_x_4__boxed_1821_ = lean_unbox(v_x_1820_);
v_res_1822_ = lp_bounded_Bounded_ReadCls_toCtorIdx(v_x_4__boxed_1821_);
return v_res_1822_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadCls_ctorElim___redArg(lean_object* v_k_1823_){
_start:
{
lean_inc(v_k_1823_);
return v_k_1823_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadCls_ctorElim___redArg___boxed(lean_object* v_k_1824_){
_start:
{
lean_object* v_res_1825_; 
v_res_1825_ = lp_bounded_Bounded_ReadCls_ctorElim___redArg(v_k_1824_);
lean_dec(v_k_1824_);
return v_res_1825_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadCls_ctorElim(lean_object* v_motive_1826_, lean_object* v_ctorIdx_1827_, uint8_t v_t_1828_, lean_object* v_h_1829_, lean_object* v_k_1830_){
_start:
{
lean_inc(v_k_1830_);
return v_k_1830_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadCls_ctorElim___boxed(lean_object* v_motive_1831_, lean_object* v_ctorIdx_1832_, lean_object* v_t_1833_, lean_object* v_h_1834_, lean_object* v_k_1835_){
_start:
{
uint8_t v_t_boxed_1836_; lean_object* v_res_1837_; 
v_t_boxed_1836_ = lean_unbox(v_t_1833_);
v_res_1837_ = lp_bounded_Bounded_ReadCls_ctorElim(v_motive_1831_, v_ctorIdx_1832_, v_t_boxed_1836_, v_h_1834_, v_k_1835_);
lean_dec(v_k_1835_);
lean_dec(v_ctorIdx_1832_);
return v_res_1837_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadCls_own_elim___redArg(lean_object* v_own_1838_){
_start:
{
lean_inc(v_own_1838_);
return v_own_1838_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadCls_own_elim___redArg___boxed(lean_object* v_own_1839_){
_start:
{
lean_object* v_res_1840_; 
v_res_1840_ = lp_bounded_Bounded_ReadCls_own_elim___redArg(v_own_1839_);
lean_dec(v_own_1839_);
return v_res_1840_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadCls_own_elim(lean_object* v_motive_1841_, uint8_t v_t_1842_, lean_object* v_h_1843_, lean_object* v_own_1844_){
_start:
{
lean_inc(v_own_1844_);
return v_own_1844_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadCls_own_elim___boxed(lean_object* v_motive_1845_, lean_object* v_t_1846_, lean_object* v_h_1847_, lean_object* v_own_1848_){
_start:
{
uint8_t v_t_boxed_1849_; lean_object* v_res_1850_; 
v_t_boxed_1849_ = lean_unbox(v_t_1846_);
v_res_1850_ = lp_bounded_Bounded_ReadCls_own_elim(v_motive_1845_, v_t_boxed_1849_, v_h_1847_, v_own_1848_);
lean_dec(v_own_1848_);
return v_res_1850_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadCls_ancestor_elim___redArg(lean_object* v_ancestor_1851_){
_start:
{
lean_inc(v_ancestor_1851_);
return v_ancestor_1851_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadCls_ancestor_elim___redArg___boxed(lean_object* v_ancestor_1852_){
_start:
{
lean_object* v_res_1853_; 
v_res_1853_ = lp_bounded_Bounded_ReadCls_ancestor_elim___redArg(v_ancestor_1852_);
lean_dec(v_ancestor_1852_);
return v_res_1853_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadCls_ancestor_elim(lean_object* v_motive_1854_, uint8_t v_t_1855_, lean_object* v_h_1856_, lean_object* v_ancestor_1857_){
_start:
{
lean_inc(v_ancestor_1857_);
return v_ancestor_1857_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadCls_ancestor_elim___boxed(lean_object* v_motive_1858_, lean_object* v_t_1859_, lean_object* v_h_1860_, lean_object* v_ancestor_1861_){
_start:
{
uint8_t v_t_boxed_1862_; lean_object* v_res_1863_; 
v_t_boxed_1862_ = lean_unbox(v_t_1859_);
v_res_1863_ = lp_bounded_Bounded_ReadCls_ancestor_elim(v_motive_1858_, v_t_boxed_1862_, v_h_1860_, v_ancestor_1861_);
lean_dec(v_ancestor_1861_);
return v_res_1863_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadCls_ia_elim___redArg(lean_object* v_ia_1864_){
_start:
{
lean_inc(v_ia_1864_);
return v_ia_1864_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadCls_ia_elim___redArg___boxed(lean_object* v_ia_1865_){
_start:
{
lean_object* v_res_1866_; 
v_res_1866_ = lp_bounded_Bounded_ReadCls_ia_elim___redArg(v_ia_1865_);
lean_dec(v_ia_1865_);
return v_res_1866_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadCls_ia_elim(lean_object* v_motive_1867_, uint8_t v_t_1868_, lean_object* v_h_1869_, lean_object* v_ia_1870_){
_start:
{
lean_inc(v_ia_1870_);
return v_ia_1870_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadCls_ia_elim___boxed(lean_object* v_motive_1871_, lean_object* v_t_1872_, lean_object* v_h_1873_, lean_object* v_ia_1874_){
_start:
{
uint8_t v_t_boxed_1875_; lean_object* v_res_1876_; 
v_t_boxed_1875_ = lean_unbox(v_t_1872_);
v_res_1876_ = lp_bounded_Bounded_ReadCls_ia_elim(v_motive_1871_, v_t_boxed_1875_, v_h_1873_, v_ia_1874_);
lean_dec(v_ia_1874_);
return v_res_1876_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadCls_ud_elim___redArg(lean_object* v_ud_1877_){
_start:
{
lean_inc(v_ud_1877_);
return v_ud_1877_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadCls_ud_elim___redArg___boxed(lean_object* v_ud_1878_){
_start:
{
lean_object* v_res_1879_; 
v_res_1879_ = lp_bounded_Bounded_ReadCls_ud_elim___redArg(v_ud_1878_);
lean_dec(v_ud_1878_);
return v_res_1879_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadCls_ud_elim(lean_object* v_motive_1880_, uint8_t v_t_1881_, lean_object* v_h_1882_, lean_object* v_ud_1883_){
_start:
{
lean_inc(v_ud_1883_);
return v_ud_1883_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadCls_ud_elim___boxed(lean_object* v_motive_1884_, lean_object* v_t_1885_, lean_object* v_h_1886_, lean_object* v_ud_1887_){
_start:
{
uint8_t v_t_boxed_1888_; lean_object* v_res_1889_; 
v_t_boxed_1888_ = lean_unbox(v_t_1885_);
v_res_1889_ = lp_bounded_Bounded_ReadCls_ud_elim(v_motive_1884_, v_t_boxed_1888_, v_h_1886_, v_ud_1887_);
lean_dec(v_ud_1887_);
return v_res_1889_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_ReadCls_ofNat(lean_object* v_n_1890_){
_start:
{
lean_object* v___x_1891_; uint8_t v___x_1892_; 
v___x_1891_ = lean_unsigned_to_nat(1u);
v___x_1892_ = lean_nat_dec_le(v_n_1890_, v___x_1891_);
if (v___x_1892_ == 0)
{
lean_object* v___x_1893_; uint8_t v___x_1894_; 
v___x_1893_ = lean_unsigned_to_nat(2u);
v___x_1894_ = lean_nat_dec_le(v_n_1890_, v___x_1893_);
if (v___x_1894_ == 0)
{
uint8_t v___x_1895_; 
v___x_1895_ = 3;
return v___x_1895_;
}
else
{
uint8_t v___x_1896_; 
v___x_1896_ = 2;
return v___x_1896_;
}
}
else
{
lean_object* v___x_1897_; uint8_t v___x_1898_; 
v___x_1897_ = lean_unsigned_to_nat(0u);
v___x_1898_ = lean_nat_dec_le(v_n_1890_, v___x_1897_);
if (v___x_1898_ == 0)
{
uint8_t v___x_1899_; 
v___x_1899_ = 1;
return v___x_1899_;
}
else
{
uint8_t v___x_1900_; 
v___x_1900_ = 0;
return v___x_1900_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_ReadCls_ofNat___boxed(lean_object* v_n_1901_){
_start:
{
uint8_t v_res_1902_; lean_object* v_r_1903_; 
v_res_1902_ = lp_bounded_Bounded_ReadCls_ofNat(v_n_1901_);
lean_dec(v_n_1901_);
v_r_1903_ = lean_box(v_res_1902_);
return v_r_1903_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqReadCls(uint8_t v_x_1904_, uint8_t v_y_1905_){
_start:
{
lean_object* v___x_1906_; lean_object* v___x_1907_; uint8_t v___x_1908_; 
v___x_1906_ = lp_bounded_Bounded_ReadCls_ctorIdx(v_x_1904_);
v___x_1907_ = lp_bounded_Bounded_ReadCls_ctorIdx(v_y_1905_);
v___x_1908_ = lean_nat_dec_eq(v___x_1906_, v___x_1907_);
lean_dec(v___x_1907_);
lean_dec(v___x_1906_);
return v___x_1908_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqReadCls___boxed(lean_object* v_x_1909_, lean_object* v_y_1910_){
_start:
{
uint8_t v_x_13__boxed_1911_; uint8_t v_y_14__boxed_1912_; uint8_t v_res_1913_; lean_object* v_r_1914_; 
v_x_13__boxed_1911_ = lean_unbox(v_x_1909_);
v_y_14__boxed_1912_ = lean_unbox(v_y_1910_);
v_res_1913_ = lp_bounded_Bounded_instDecidableEqReadCls(v_x_13__boxed_1911_, v_y_14__boxed_1912_);
v_r_1914_ = lean_box(v_res_1913_);
return v_r_1914_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprReadCls_repr(uint8_t v_x_1927_, lean_object* v_prec_1928_){
_start:
{
lean_object* v___y_1930_; lean_object* v___y_1937_; lean_object* v___y_1944_; lean_object* v___y_1951_; 
switch(v_x_1927_)
{
case 0:
{
lean_object* v___x_1957_; uint8_t v___x_1958_; 
v___x_1957_ = lean_unsigned_to_nat(1024u);
v___x_1958_ = lean_nat_dec_le(v___x_1957_, v_prec_1928_);
if (v___x_1958_ == 0)
{
lean_object* v___x_1959_; 
v___x_1959_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_1930_ = v___x_1959_;
goto v___jp_1929_;
}
else
{
lean_object* v___x_1960_; 
v___x_1960_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_1930_ = v___x_1960_;
goto v___jp_1929_;
}
}
case 1:
{
lean_object* v___x_1961_; uint8_t v___x_1962_; 
v___x_1961_ = lean_unsigned_to_nat(1024u);
v___x_1962_ = lean_nat_dec_le(v___x_1961_, v_prec_1928_);
if (v___x_1962_ == 0)
{
lean_object* v___x_1963_; 
v___x_1963_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_1937_ = v___x_1963_;
goto v___jp_1936_;
}
else
{
lean_object* v___x_1964_; 
v___x_1964_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_1937_ = v___x_1964_;
goto v___jp_1936_;
}
}
case 2:
{
lean_object* v___x_1965_; uint8_t v___x_1966_; 
v___x_1965_ = lean_unsigned_to_nat(1024u);
v___x_1966_ = lean_nat_dec_le(v___x_1965_, v_prec_1928_);
if (v___x_1966_ == 0)
{
lean_object* v___x_1967_; 
v___x_1967_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_1944_ = v___x_1967_;
goto v___jp_1943_;
}
else
{
lean_object* v___x_1968_; 
v___x_1968_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_1944_ = v___x_1968_;
goto v___jp_1943_;
}
}
default: 
{
lean_object* v___x_1969_; uint8_t v___x_1970_; 
v___x_1969_ = lean_unsigned_to_nat(1024u);
v___x_1970_ = lean_nat_dec_le(v___x_1969_, v_prec_1928_);
if (v___x_1970_ == 0)
{
lean_object* v___x_1971_; 
v___x_1971_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_1951_ = v___x_1971_;
goto v___jp_1950_;
}
else
{
lean_object* v___x_1972_; 
v___x_1972_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_1951_ = v___x_1972_;
goto v___jp_1950_;
}
}
}
v___jp_1929_:
{
lean_object* v___x_1931_; lean_object* v___x_1932_; uint8_t v___x_1933_; lean_object* v___x_1934_; lean_object* v___x_1935_; 
v___x_1931_ = ((lean_object*)(lp_bounded_Bounded_instReprReadCls_repr___closed__1));
lean_inc(v___y_1930_);
v___x_1932_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_1932_, 0, v___y_1930_);
lean_ctor_set(v___x_1932_, 1, v___x_1931_);
v___x_1933_ = 0;
v___x_1934_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_1934_, 0, v___x_1932_);
lean_ctor_set_uint8(v___x_1934_, sizeof(void*)*1, v___x_1933_);
v___x_1935_ = l_Repr_addAppParen(v___x_1934_, v_prec_1928_);
return v___x_1935_;
}
v___jp_1936_:
{
lean_object* v___x_1938_; lean_object* v___x_1939_; uint8_t v___x_1940_; lean_object* v___x_1941_; lean_object* v___x_1942_; 
v___x_1938_ = ((lean_object*)(lp_bounded_Bounded_instReprReadCls_repr___closed__3));
lean_inc(v___y_1937_);
v___x_1939_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_1939_, 0, v___y_1937_);
lean_ctor_set(v___x_1939_, 1, v___x_1938_);
v___x_1940_ = 0;
v___x_1941_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_1941_, 0, v___x_1939_);
lean_ctor_set_uint8(v___x_1941_, sizeof(void*)*1, v___x_1940_);
v___x_1942_ = l_Repr_addAppParen(v___x_1941_, v_prec_1928_);
return v___x_1942_;
}
v___jp_1943_:
{
lean_object* v___x_1945_; lean_object* v___x_1946_; uint8_t v___x_1947_; lean_object* v___x_1948_; lean_object* v___x_1949_; 
v___x_1945_ = ((lean_object*)(lp_bounded_Bounded_instReprReadCls_repr___closed__5));
lean_inc(v___y_1944_);
v___x_1946_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_1946_, 0, v___y_1944_);
lean_ctor_set(v___x_1946_, 1, v___x_1945_);
v___x_1947_ = 0;
v___x_1948_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_1948_, 0, v___x_1946_);
lean_ctor_set_uint8(v___x_1948_, sizeof(void*)*1, v___x_1947_);
v___x_1949_ = l_Repr_addAppParen(v___x_1948_, v_prec_1928_);
return v___x_1949_;
}
v___jp_1950_:
{
lean_object* v___x_1952_; lean_object* v___x_1953_; uint8_t v___x_1954_; lean_object* v___x_1955_; lean_object* v___x_1956_; 
v___x_1952_ = ((lean_object*)(lp_bounded_Bounded_instReprReadCls_repr___closed__7));
lean_inc(v___y_1951_);
v___x_1953_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_1953_, 0, v___y_1951_);
lean_ctor_set(v___x_1953_, 1, v___x_1952_);
v___x_1954_ = 0;
v___x_1955_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_1955_, 0, v___x_1953_);
lean_ctor_set_uint8(v___x_1955_, sizeof(void*)*1, v___x_1954_);
v___x_1956_ = l_Repr_addAppParen(v___x_1955_, v_prec_1928_);
return v___x_1956_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprReadCls_repr___boxed(lean_object* v_x_1973_, lean_object* v_prec_1974_){
_start:
{
uint8_t v_x_229__boxed_1975_; lean_object* v_res_1976_; 
v_x_229__boxed_1975_ = lean_unbox(v_x_1973_);
v_res_1976_ = lp_bounded_Bounded_instReprReadCls_repr(v_x_229__boxed_1975_, v_prec_1974_);
lean_dec(v_prec_1974_);
return v_res_1976_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_ctorIdx(lean_object* v_x_1979_){
_start:
{
switch(lean_obj_tag(v_x_1979_))
{
case 0:
{
lean_object* v___x_1980_; 
v___x_1980_ = lean_unsigned_to_nat(0u);
return v___x_1980_;
}
case 1:
{
lean_object* v___x_1981_; 
v___x_1981_ = lean_unsigned_to_nat(1u);
return v___x_1981_;
}
case 2:
{
lean_object* v___x_1982_; 
v___x_1982_ = lean_unsigned_to_nat(2u);
return v___x_1982_;
}
case 3:
{
lean_object* v___x_1983_; 
v___x_1983_ = lean_unsigned_to_nat(3u);
return v___x_1983_;
}
case 4:
{
lean_object* v___x_1984_; 
v___x_1984_ = lean_unsigned_to_nat(4u);
return v___x_1984_;
}
case 5:
{
lean_object* v___x_1985_; 
v___x_1985_ = lean_unsigned_to_nat(5u);
return v___x_1985_;
}
case 6:
{
lean_object* v___x_1986_; 
v___x_1986_ = lean_unsigned_to_nat(6u);
return v___x_1986_;
}
case 7:
{
lean_object* v___x_1987_; 
v___x_1987_ = lean_unsigned_to_nat(7u);
return v___x_1987_;
}
case 8:
{
lean_object* v___x_1988_; 
v___x_1988_ = lean_unsigned_to_nat(8u);
return v___x_1988_;
}
default: 
{
lean_object* v___x_1989_; 
v___x_1989_ = lean_unsigned_to_nat(9u);
return v___x_1989_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_ctorIdx___boxed(lean_object* v_x_1990_){
_start:
{
lean_object* v_res_1991_; 
v_res_1991_ = lp_bounded_Bounded_StepSig_ctorIdx(v_x_1990_);
lean_dec(v_x_1990_);
return v_res_1991_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_ctorElim___redArg(lean_object* v_t_1992_, lean_object* v_k_1993_){
_start:
{
if (lean_obj_tag(v_t_1992_) == 3)
{
uint8_t v_c_1994_; lean_object* v___x_1995_; lean_object* v___x_1996_; 
v_c_1994_ = lean_ctor_get_uint8(v_t_1992_, 0);
v___x_1995_ = lean_box(v_c_1994_);
v___x_1996_ = lean_apply_1(v_k_1993_, v___x_1995_);
return v___x_1996_;
}
else
{
return v_k_1993_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_ctorElim___redArg___boxed(lean_object* v_t_1997_, lean_object* v_k_1998_){
_start:
{
lean_object* v_res_1999_; 
v_res_1999_ = lp_bounded_Bounded_StepSig_ctorElim___redArg(v_t_1997_, v_k_1998_);
lean_dec(v_t_1997_);
return v_res_1999_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_ctorElim(lean_object* v_motive_2000_, lean_object* v_ctorIdx_2001_, lean_object* v_t_2002_, lean_object* v_h_2003_, lean_object* v_k_2004_){
_start:
{
lean_object* v___x_2005_; 
v___x_2005_ = lp_bounded_Bounded_StepSig_ctorElim___redArg(v_t_2002_, v_k_2004_);
return v___x_2005_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_ctorElim___boxed(lean_object* v_motive_2006_, lean_object* v_ctorIdx_2007_, lean_object* v_t_2008_, lean_object* v_h_2009_, lean_object* v_k_2010_){
_start:
{
lean_object* v_res_2011_; 
v_res_2011_ = lp_bounded_Bounded_StepSig_ctorElim(v_motive_2006_, v_ctorIdx_2007_, v_t_2008_, v_h_2009_, v_k_2010_);
lean_dec(v_t_2008_);
lean_dec(v_ctorIdx_2007_);
return v_res_2011_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_provideFresh_elim___redArg(lean_object* v_t_2012_, lean_object* v_provideFresh_2013_){
_start:
{
lean_object* v___x_2014_; 
v___x_2014_ = lp_bounded_Bounded_StepSig_ctorElim___redArg(v_t_2012_, v_provideFresh_2013_);
return v___x_2014_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_provideFresh_elim___redArg___boxed(lean_object* v_t_2015_, lean_object* v_provideFresh_2016_){
_start:
{
lean_object* v_res_2017_; 
v_res_2017_ = lp_bounded_Bounded_StepSig_provideFresh_elim___redArg(v_t_2015_, v_provideFresh_2016_);
lean_dec(v_t_2015_);
return v_res_2017_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_provideFresh_elim(lean_object* v_motive_2018_, lean_object* v_t_2019_, lean_object* v_h_2020_, lean_object* v_provideFresh_2021_){
_start:
{
lean_object* v___x_2022_; 
v___x_2022_ = lp_bounded_Bounded_StepSig_ctorElim___redArg(v_t_2019_, v_provideFresh_2021_);
return v___x_2022_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_provideFresh_elim___boxed(lean_object* v_motive_2023_, lean_object* v_t_2024_, lean_object* v_h_2025_, lean_object* v_provideFresh_2026_){
_start:
{
lean_object* v_res_2027_; 
v_res_2027_ = lp_bounded_Bounded_StepSig_provideFresh_elim(v_motive_2023_, v_t_2024_, v_h_2025_, v_provideFresh_2026_);
lean_dec(v_t_2024_);
return v_res_2027_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_provideConflict_elim___redArg(lean_object* v_t_2028_, lean_object* v_provideConflict_2029_){
_start:
{
lean_object* v___x_2030_; 
v___x_2030_ = lp_bounded_Bounded_StepSig_ctorElim___redArg(v_t_2028_, v_provideConflict_2029_);
return v___x_2030_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_provideConflict_elim___redArg___boxed(lean_object* v_t_2031_, lean_object* v_provideConflict_2032_){
_start:
{
lean_object* v_res_2033_; 
v_res_2033_ = lp_bounded_Bounded_StepSig_provideConflict_elim___redArg(v_t_2031_, v_provideConflict_2032_);
lean_dec(v_t_2031_);
return v_res_2033_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_provideConflict_elim(lean_object* v_motive_2034_, lean_object* v_t_2035_, lean_object* v_h_2036_, lean_object* v_provideConflict_2037_){
_start:
{
lean_object* v___x_2038_; 
v___x_2038_ = lp_bounded_Bounded_StepSig_ctorElim___redArg(v_t_2035_, v_provideConflict_2037_);
return v___x_2038_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_provideConflict_elim___boxed(lean_object* v_motive_2039_, lean_object* v_t_2040_, lean_object* v_h_2041_, lean_object* v_provideConflict_2042_){
_start:
{
lean_object* v_res_2043_; 
v_res_2043_ = lp_bounded_Bounded_StepSig_provideConflict_elim(v_motive_2039_, v_t_2040_, v_h_2041_, v_provideConflict_2042_);
lean_dec(v_t_2040_);
return v_res_2043_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_trackC_elim___redArg(lean_object* v_t_2044_, lean_object* v_trackC_2045_){
_start:
{
lean_object* v___x_2046_; 
v___x_2046_ = lp_bounded_Bounded_StepSig_ctorElim___redArg(v_t_2044_, v_trackC_2045_);
return v___x_2046_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_trackC_elim___redArg___boxed(lean_object* v_t_2047_, lean_object* v_trackC_2048_){
_start:
{
lean_object* v_res_2049_; 
v_res_2049_ = lp_bounded_Bounded_StepSig_trackC_elim___redArg(v_t_2047_, v_trackC_2048_);
lean_dec(v_t_2047_);
return v_res_2049_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_trackC_elim(lean_object* v_motive_2050_, lean_object* v_t_2051_, lean_object* v_h_2052_, lean_object* v_trackC_2053_){
_start:
{
lean_object* v___x_2054_; 
v___x_2054_ = lp_bounded_Bounded_StepSig_ctorElim___redArg(v_t_2051_, v_trackC_2053_);
return v___x_2054_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_trackC_elim___boxed(lean_object* v_motive_2055_, lean_object* v_t_2056_, lean_object* v_h_2057_, lean_object* v_trackC_2058_){
_start:
{
lean_object* v_res_2059_; 
v_res_2059_ = lp_bounded_Bounded_StepSig_trackC_elim(v_motive_2055_, v_t_2056_, v_h_2057_, v_trackC_2058_);
lean_dec(v_t_2056_);
return v_res_2059_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_readCls_elim___redArg(lean_object* v_t_2060_, lean_object* v_readCls_2061_){
_start:
{
lean_object* v___x_2062_; 
v___x_2062_ = lp_bounded_Bounded_StepSig_ctorElim___redArg(v_t_2060_, v_readCls_2061_);
return v___x_2062_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_readCls_elim___redArg___boxed(lean_object* v_t_2063_, lean_object* v_readCls_2064_){
_start:
{
lean_object* v_res_2065_; 
v_res_2065_ = lp_bounded_Bounded_StepSig_readCls_elim___redArg(v_t_2063_, v_readCls_2064_);
lean_dec(v_t_2063_);
return v_res_2065_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_readCls_elim(lean_object* v_motive_2066_, lean_object* v_t_2067_, lean_object* v_h_2068_, lean_object* v_readCls_2069_){
_start:
{
lean_object* v___x_2070_; 
v___x_2070_ = lp_bounded_Bounded_StepSig_ctorElim___redArg(v_t_2067_, v_readCls_2069_);
return v___x_2070_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_readCls_elim___boxed(lean_object* v_motive_2071_, lean_object* v_t_2072_, lean_object* v_h_2073_, lean_object* v_readCls_2074_){
_start:
{
lean_object* v_res_2075_; 
v_res_2075_ = lp_bounded_Bounded_StepSig_readCls_elim(v_motive_2071_, v_t_2072_, v_h_2073_, v_readCls_2074_);
lean_dec(v_t_2072_);
return v_res_2075_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_setOwn_elim___redArg(lean_object* v_t_2076_, lean_object* v_setOwn_2077_){
_start:
{
lean_object* v___x_2078_; 
v___x_2078_ = lp_bounded_Bounded_StepSig_ctorElim___redArg(v_t_2076_, v_setOwn_2077_);
return v___x_2078_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_setOwn_elim___redArg___boxed(lean_object* v_t_2079_, lean_object* v_setOwn_2080_){
_start:
{
lean_object* v_res_2081_; 
v_res_2081_ = lp_bounded_Bounded_StepSig_setOwn_elim___redArg(v_t_2079_, v_setOwn_2080_);
lean_dec(v_t_2079_);
return v_res_2081_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_setOwn_elim(lean_object* v_motive_2082_, lean_object* v_t_2083_, lean_object* v_h_2084_, lean_object* v_setOwn_2085_){
_start:
{
lean_object* v___x_2086_; 
v___x_2086_ = lp_bounded_Bounded_StepSig_ctorElim___redArg(v_t_2083_, v_setOwn_2085_);
return v___x_2086_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_setOwn_elim___boxed(lean_object* v_motive_2087_, lean_object* v_t_2088_, lean_object* v_h_2089_, lean_object* v_setOwn_2090_){
_start:
{
lean_object* v_res_2091_; 
v_res_2091_ = lp_bounded_Bounded_StepSig_setOwn_elim(v_motive_2087_, v_t_2088_, v_h_2089_, v_setOwn_2090_);
lean_dec(v_t_2088_);
return v_res_2091_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_setMissing_elim___redArg(lean_object* v_t_2092_, lean_object* v_setMissing_2093_){
_start:
{
lean_object* v___x_2094_; 
v___x_2094_ = lp_bounded_Bounded_StepSig_ctorElim___redArg(v_t_2092_, v_setMissing_2093_);
return v___x_2094_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_setMissing_elim___redArg___boxed(lean_object* v_t_2095_, lean_object* v_setMissing_2096_){
_start:
{
lean_object* v_res_2097_; 
v_res_2097_ = lp_bounded_Bounded_StepSig_setMissing_elim___redArg(v_t_2095_, v_setMissing_2096_);
lean_dec(v_t_2095_);
return v_res_2097_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_setMissing_elim(lean_object* v_motive_2098_, lean_object* v_t_2099_, lean_object* v_h_2100_, lean_object* v_setMissing_2101_){
_start:
{
lean_object* v___x_2102_; 
v___x_2102_ = lp_bounded_Bounded_StepSig_ctorElim___redArg(v_t_2099_, v_setMissing_2101_);
return v___x_2102_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_setMissing_elim___boxed(lean_object* v_motive_2103_, lean_object* v_t_2104_, lean_object* v_h_2105_, lean_object* v_setMissing_2106_){
_start:
{
lean_object* v_res_2107_; 
v_res_2107_ = lp_bounded_Bounded_StepSig_setMissing_elim(v_motive_2103_, v_t_2104_, v_h_2105_, v_setMissing_2106_);
lean_dec(v_t_2104_);
return v_res_2107_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_regOk_elim___redArg(lean_object* v_t_2108_, lean_object* v_regOk_2109_){
_start:
{
lean_object* v___x_2110_; 
v___x_2110_ = lp_bounded_Bounded_StepSig_ctorElim___redArg(v_t_2108_, v_regOk_2109_);
return v___x_2110_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_regOk_elim___redArg___boxed(lean_object* v_t_2111_, lean_object* v_regOk_2112_){
_start:
{
lean_object* v_res_2113_; 
v_res_2113_ = lp_bounded_Bounded_StepSig_regOk_elim___redArg(v_t_2111_, v_regOk_2112_);
lean_dec(v_t_2111_);
return v_res_2113_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_regOk_elim(lean_object* v_motive_2114_, lean_object* v_t_2115_, lean_object* v_h_2116_, lean_object* v_regOk_2117_){
_start:
{
lean_object* v___x_2118_; 
v___x_2118_ = lp_bounded_Bounded_StepSig_ctorElim___redArg(v_t_2115_, v_regOk_2117_);
return v___x_2118_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_regOk_elim___boxed(lean_object* v_motive_2119_, lean_object* v_t_2120_, lean_object* v_h_2121_, lean_object* v_regOk_2122_){
_start:
{
lean_object* v_res_2123_; 
v_res_2123_ = lp_bounded_Bounded_StepSig_regOk_elim(v_motive_2119_, v_t_2120_, v_h_2121_, v_regOk_2122_);
lean_dec(v_t_2120_);
return v_res_2123_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_regBad_elim___redArg(lean_object* v_t_2124_, lean_object* v_regBad_2125_){
_start:
{
lean_object* v___x_2126_; 
v___x_2126_ = lp_bounded_Bounded_StepSig_ctorElim___redArg(v_t_2124_, v_regBad_2125_);
return v___x_2126_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_regBad_elim___redArg___boxed(lean_object* v_t_2127_, lean_object* v_regBad_2128_){
_start:
{
lean_object* v_res_2129_; 
v_res_2129_ = lp_bounded_Bounded_StepSig_regBad_elim___redArg(v_t_2127_, v_regBad_2128_);
lean_dec(v_t_2127_);
return v_res_2129_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_regBad_elim(lean_object* v_motive_2130_, lean_object* v_t_2131_, lean_object* v_h_2132_, lean_object* v_regBad_2133_){
_start:
{
lean_object* v___x_2134_; 
v___x_2134_ = lp_bounded_Bounded_StepSig_ctorElim___redArg(v_t_2131_, v_regBad_2133_);
return v___x_2134_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_regBad_elim___boxed(lean_object* v_motive_2135_, lean_object* v_t_2136_, lean_object* v_h_2137_, lean_object* v_regBad_2138_){
_start:
{
lean_object* v_res_2139_; 
v_res_2139_ = lp_bounded_Bounded_StepSig_regBad_elim(v_motive_2135_, v_t_2136_, v_h_2137_, v_regBad_2138_);
lean_dec(v_t_2136_);
return v_res_2139_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_raiseC_elim___redArg(lean_object* v_t_2140_, lean_object* v_raiseC_2141_){
_start:
{
lean_object* v___x_2142_; 
v___x_2142_ = lp_bounded_Bounded_StepSig_ctorElim___redArg(v_t_2140_, v_raiseC_2141_);
return v___x_2142_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_raiseC_elim___redArg___boxed(lean_object* v_t_2143_, lean_object* v_raiseC_2144_){
_start:
{
lean_object* v_res_2145_; 
v_res_2145_ = lp_bounded_Bounded_StepSig_raiseC_elim___redArg(v_t_2143_, v_raiseC_2144_);
lean_dec(v_t_2143_);
return v_res_2145_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_raiseC_elim(lean_object* v_motive_2146_, lean_object* v_t_2147_, lean_object* v_h_2148_, lean_object* v_raiseC_2149_){
_start:
{
lean_object* v___x_2150_; 
v___x_2150_ = lp_bounded_Bounded_StepSig_ctorElim___redArg(v_t_2147_, v_raiseC_2149_);
return v___x_2150_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_raiseC_elim___boxed(lean_object* v_motive_2151_, lean_object* v_t_2152_, lean_object* v_h_2153_, lean_object* v_raiseC_2154_){
_start:
{
lean_object* v_res_2155_; 
v_res_2155_ = lp_bounded_Bounded_StepSig_raiseC_elim(v_motive_2151_, v_t_2152_, v_h_2153_, v_raiseC_2154_);
lean_dec(v_t_2152_);
return v_res_2155_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_mismatch_elim___redArg(lean_object* v_t_2156_, lean_object* v_mismatch_2157_){
_start:
{
lean_object* v___x_2158_; 
v___x_2158_ = lp_bounded_Bounded_StepSig_ctorElim___redArg(v_t_2156_, v_mismatch_2157_);
return v___x_2158_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_mismatch_elim___redArg___boxed(lean_object* v_t_2159_, lean_object* v_mismatch_2160_){
_start:
{
lean_object* v_res_2161_; 
v_res_2161_ = lp_bounded_Bounded_StepSig_mismatch_elim___redArg(v_t_2159_, v_mismatch_2160_);
lean_dec(v_t_2159_);
return v_res_2161_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_mismatch_elim(lean_object* v_motive_2162_, lean_object* v_t_2163_, lean_object* v_h_2164_, lean_object* v_mismatch_2165_){
_start:
{
lean_object* v___x_2166_; 
v___x_2166_ = lp_bounded_Bounded_StepSig_ctorElim___redArg(v_t_2163_, v_mismatch_2165_);
return v___x_2166_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_StepSig_mismatch_elim___boxed(lean_object* v_motive_2167_, lean_object* v_t_2168_, lean_object* v_h_2169_, lean_object* v_mismatch_2170_){
_start:
{
lean_object* v_res_2171_; 
v_res_2171_ = lp_bounded_Bounded_StepSig_mismatch_elim(v_motive_2167_, v_t_2168_, v_h_2169_, v_mismatch_2170_);
lean_dec(v_t_2168_);
return v_res_2171_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqStepSig_decEq(lean_object* v_x_2172_, lean_object* v_x_2173_){
_start:
{
lean_object* v___x_2174_; lean_object* v___x_2175_; uint8_t v___x_2176_; 
v___x_2174_ = lp_bounded_Bounded_StepSig_ctorIdx(v_x_2172_);
v___x_2175_ = lp_bounded_Bounded_StepSig_ctorIdx(v_x_2173_);
v___x_2176_ = lean_nat_dec_eq(v___x_2174_, v___x_2175_);
lean_dec(v___x_2175_);
lean_dec(v___x_2174_);
if (v___x_2176_ == 0)
{
return v___x_2176_;
}
else
{
if (lean_obj_tag(v_x_2172_) == 3)
{
uint8_t v_c_2177_; uint8_t v_c_2178_; uint8_t v___x_2179_; 
v_c_2177_ = lean_ctor_get_uint8(v_x_2172_, 0);
v_c_2178_ = lean_ctor_get_uint8(v_x_2173_, 0);
v___x_2179_ = lp_bounded_Bounded_instDecidableEqReadCls(v_c_2177_, v_c_2178_);
return v___x_2179_;
}
else
{
return v___x_2176_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqStepSig_decEq___boxed(lean_object* v_x_2180_, lean_object* v_x_2181_){
_start:
{
uint8_t v_res_2182_; lean_object* v_r_2183_; 
v_res_2182_ = lp_bounded_Bounded_instDecidableEqStepSig_decEq(v_x_2180_, v_x_2181_);
lean_dec(v_x_2181_);
lean_dec(v_x_2180_);
v_r_2183_ = lean_box(v_res_2182_);
return v_r_2183_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqStepSig(lean_object* v_x_2184_, lean_object* v_x_2185_){
_start:
{
uint8_t v___x_2186_; 
v___x_2186_ = lp_bounded_Bounded_instDecidableEqStepSig_decEq(v_x_2184_, v_x_2185_);
return v___x_2186_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqStepSig___boxed(lean_object* v_x_2187_, lean_object* v_x_2188_){
_start:
{
uint8_t v_res_2189_; lean_object* v_r_2190_; 
v_res_2189_ = lp_bounded_Bounded_instDecidableEqStepSig(v_x_2187_, v_x_2188_);
lean_dec(v_x_2188_);
lean_dec(v_x_2187_);
v_r_2190_ = lean_box(v_res_2189_);
return v_r_2190_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprStepSig_repr(lean_object* v_x_2224_, lean_object* v_prec_2225_){
_start:
{
lean_object* v___y_2227_; lean_object* v___y_2234_; lean_object* v___y_2241_; lean_object* v___y_2248_; lean_object* v___y_2255_; lean_object* v___y_2262_; lean_object* v___y_2269_; lean_object* v___y_2276_; lean_object* v___y_2283_; 
switch(lean_obj_tag(v_x_2224_))
{
case 0:
{
lean_object* v___x_2289_; uint8_t v___x_2290_; 
v___x_2289_ = lean_unsigned_to_nat(1024u);
v___x_2290_ = lean_nat_dec_le(v___x_2289_, v_prec_2225_);
if (v___x_2290_ == 0)
{
lean_object* v___x_2291_; 
v___x_2291_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_2241_ = v___x_2291_;
goto v___jp_2240_;
}
else
{
lean_object* v___x_2292_; 
v___x_2292_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_2241_ = v___x_2292_;
goto v___jp_2240_;
}
}
case 1:
{
lean_object* v___x_2293_; uint8_t v___x_2294_; 
v___x_2293_ = lean_unsigned_to_nat(1024u);
v___x_2294_ = lean_nat_dec_le(v___x_2293_, v_prec_2225_);
if (v___x_2294_ == 0)
{
lean_object* v___x_2295_; 
v___x_2295_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_2234_ = v___x_2295_;
goto v___jp_2233_;
}
else
{
lean_object* v___x_2296_; 
v___x_2296_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_2234_ = v___x_2296_;
goto v___jp_2233_;
}
}
case 2:
{
lean_object* v___x_2297_; uint8_t v___x_2298_; 
v___x_2297_ = lean_unsigned_to_nat(1024u);
v___x_2298_ = lean_nat_dec_le(v___x_2297_, v_prec_2225_);
if (v___x_2298_ == 0)
{
lean_object* v___x_2299_; 
v___x_2299_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_2227_ = v___x_2299_;
goto v___jp_2226_;
}
else
{
lean_object* v___x_2300_; 
v___x_2300_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_2227_ = v___x_2300_;
goto v___jp_2226_;
}
}
case 3:
{
uint8_t v_c_2301_; lean_object* v___y_2303_; lean_object* v___x_2312_; uint8_t v___x_2313_; 
v_c_2301_ = lean_ctor_get_uint8(v_x_2224_, 0);
v___x_2312_ = lean_unsigned_to_nat(1024u);
v___x_2313_ = lean_nat_dec_le(v___x_2312_, v_prec_2225_);
if (v___x_2313_ == 0)
{
lean_object* v___x_2314_; 
v___x_2314_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_2303_ = v___x_2314_;
goto v___jp_2302_;
}
else
{
lean_object* v___x_2315_; 
v___x_2315_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_2303_ = v___x_2315_;
goto v___jp_2302_;
}
v___jp_2302_:
{
lean_object* v___x_2304_; lean_object* v___x_2305_; lean_object* v___x_2306_; lean_object* v___x_2307_; lean_object* v___x_2308_; uint8_t v___x_2309_; lean_object* v___x_2310_; lean_object* v___x_2311_; 
v___x_2304_ = ((lean_object*)(lp_bounded_Bounded_instReprStepSig_repr___closed__20));
v___x_2305_ = lean_unsigned_to_nat(1024u);
v___x_2306_ = lp_bounded_Bounded_instReprReadCls_repr(v_c_2301_, v___x_2305_);
v___x_2307_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2307_, 0, v___x_2304_);
lean_ctor_set(v___x_2307_, 1, v___x_2306_);
lean_inc(v___y_2303_);
v___x_2308_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_2308_, 0, v___y_2303_);
lean_ctor_set(v___x_2308_, 1, v___x_2307_);
v___x_2309_ = 0;
v___x_2310_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_2310_, 0, v___x_2308_);
lean_ctor_set_uint8(v___x_2310_, sizeof(void*)*1, v___x_2309_);
v___x_2311_ = l_Repr_addAppParen(v___x_2310_, v_prec_2225_);
return v___x_2311_;
}
}
case 4:
{
lean_object* v___x_2316_; uint8_t v___x_2317_; 
v___x_2316_ = lean_unsigned_to_nat(1024u);
v___x_2317_ = lean_nat_dec_le(v___x_2316_, v_prec_2225_);
if (v___x_2317_ == 0)
{
lean_object* v___x_2318_; 
v___x_2318_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_2248_ = v___x_2318_;
goto v___jp_2247_;
}
else
{
lean_object* v___x_2319_; 
v___x_2319_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_2248_ = v___x_2319_;
goto v___jp_2247_;
}
}
case 5:
{
lean_object* v___x_2320_; uint8_t v___x_2321_; 
v___x_2320_ = lean_unsigned_to_nat(1024u);
v___x_2321_ = lean_nat_dec_le(v___x_2320_, v_prec_2225_);
if (v___x_2321_ == 0)
{
lean_object* v___x_2322_; 
v___x_2322_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_2255_ = v___x_2322_;
goto v___jp_2254_;
}
else
{
lean_object* v___x_2323_; 
v___x_2323_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_2255_ = v___x_2323_;
goto v___jp_2254_;
}
}
case 6:
{
lean_object* v___x_2324_; uint8_t v___x_2325_; 
v___x_2324_ = lean_unsigned_to_nat(1024u);
v___x_2325_ = lean_nat_dec_le(v___x_2324_, v_prec_2225_);
if (v___x_2325_ == 0)
{
lean_object* v___x_2326_; 
v___x_2326_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_2262_ = v___x_2326_;
goto v___jp_2261_;
}
else
{
lean_object* v___x_2327_; 
v___x_2327_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_2262_ = v___x_2327_;
goto v___jp_2261_;
}
}
case 7:
{
lean_object* v___x_2328_; uint8_t v___x_2329_; 
v___x_2328_ = lean_unsigned_to_nat(1024u);
v___x_2329_ = lean_nat_dec_le(v___x_2328_, v_prec_2225_);
if (v___x_2329_ == 0)
{
lean_object* v___x_2330_; 
v___x_2330_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_2269_ = v___x_2330_;
goto v___jp_2268_;
}
else
{
lean_object* v___x_2331_; 
v___x_2331_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_2269_ = v___x_2331_;
goto v___jp_2268_;
}
}
case 8:
{
lean_object* v___x_2332_; uint8_t v___x_2333_; 
v___x_2332_ = lean_unsigned_to_nat(1024u);
v___x_2333_ = lean_nat_dec_le(v___x_2332_, v_prec_2225_);
if (v___x_2333_ == 0)
{
lean_object* v___x_2334_; 
v___x_2334_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_2276_ = v___x_2334_;
goto v___jp_2275_;
}
else
{
lean_object* v___x_2335_; 
v___x_2335_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_2276_ = v___x_2335_;
goto v___jp_2275_;
}
}
default: 
{
lean_object* v___x_2336_; uint8_t v___x_2337_; 
v___x_2336_ = lean_unsigned_to_nat(1024u);
v___x_2337_ = lean_nat_dec_le(v___x_2336_, v_prec_2225_);
if (v___x_2337_ == 0)
{
lean_object* v___x_2338_; 
v___x_2338_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_2283_ = v___x_2338_;
goto v___jp_2282_;
}
else
{
lean_object* v___x_2339_; 
v___x_2339_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_2283_ = v___x_2339_;
goto v___jp_2282_;
}
}
}
v___jp_2226_:
{
lean_object* v___x_2228_; lean_object* v___x_2229_; uint8_t v___x_2230_; lean_object* v___x_2231_; lean_object* v___x_2232_; 
v___x_2228_ = ((lean_object*)(lp_bounded_Bounded_instReprStepSig_repr___closed__1));
lean_inc(v___y_2227_);
v___x_2229_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_2229_, 0, v___y_2227_);
lean_ctor_set(v___x_2229_, 1, v___x_2228_);
v___x_2230_ = 0;
v___x_2231_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_2231_, 0, v___x_2229_);
lean_ctor_set_uint8(v___x_2231_, sizeof(void*)*1, v___x_2230_);
v___x_2232_ = l_Repr_addAppParen(v___x_2231_, v_prec_2225_);
return v___x_2232_;
}
v___jp_2233_:
{
lean_object* v___x_2235_; lean_object* v___x_2236_; uint8_t v___x_2237_; lean_object* v___x_2238_; lean_object* v___x_2239_; 
v___x_2235_ = ((lean_object*)(lp_bounded_Bounded_instReprStepSig_repr___closed__3));
lean_inc(v___y_2234_);
v___x_2236_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_2236_, 0, v___y_2234_);
lean_ctor_set(v___x_2236_, 1, v___x_2235_);
v___x_2237_ = 0;
v___x_2238_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_2238_, 0, v___x_2236_);
lean_ctor_set_uint8(v___x_2238_, sizeof(void*)*1, v___x_2237_);
v___x_2239_ = l_Repr_addAppParen(v___x_2238_, v_prec_2225_);
return v___x_2239_;
}
v___jp_2240_:
{
lean_object* v___x_2242_; lean_object* v___x_2243_; uint8_t v___x_2244_; lean_object* v___x_2245_; lean_object* v___x_2246_; 
v___x_2242_ = ((lean_object*)(lp_bounded_Bounded_instReprStepSig_repr___closed__5));
lean_inc(v___y_2241_);
v___x_2243_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_2243_, 0, v___y_2241_);
lean_ctor_set(v___x_2243_, 1, v___x_2242_);
v___x_2244_ = 0;
v___x_2245_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_2245_, 0, v___x_2243_);
lean_ctor_set_uint8(v___x_2245_, sizeof(void*)*1, v___x_2244_);
v___x_2246_ = l_Repr_addAppParen(v___x_2245_, v_prec_2225_);
return v___x_2246_;
}
v___jp_2247_:
{
lean_object* v___x_2249_; lean_object* v___x_2250_; uint8_t v___x_2251_; lean_object* v___x_2252_; lean_object* v___x_2253_; 
v___x_2249_ = ((lean_object*)(lp_bounded_Bounded_instReprStepSig_repr___closed__7));
lean_inc(v___y_2248_);
v___x_2250_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_2250_, 0, v___y_2248_);
lean_ctor_set(v___x_2250_, 1, v___x_2249_);
v___x_2251_ = 0;
v___x_2252_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_2252_, 0, v___x_2250_);
lean_ctor_set_uint8(v___x_2252_, sizeof(void*)*1, v___x_2251_);
v___x_2253_ = l_Repr_addAppParen(v___x_2252_, v_prec_2225_);
return v___x_2253_;
}
v___jp_2254_:
{
lean_object* v___x_2256_; lean_object* v___x_2257_; uint8_t v___x_2258_; lean_object* v___x_2259_; lean_object* v___x_2260_; 
v___x_2256_ = ((lean_object*)(lp_bounded_Bounded_instReprStepSig_repr___closed__9));
lean_inc(v___y_2255_);
v___x_2257_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_2257_, 0, v___y_2255_);
lean_ctor_set(v___x_2257_, 1, v___x_2256_);
v___x_2258_ = 0;
v___x_2259_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_2259_, 0, v___x_2257_);
lean_ctor_set_uint8(v___x_2259_, sizeof(void*)*1, v___x_2258_);
v___x_2260_ = l_Repr_addAppParen(v___x_2259_, v_prec_2225_);
return v___x_2260_;
}
v___jp_2261_:
{
lean_object* v___x_2263_; lean_object* v___x_2264_; uint8_t v___x_2265_; lean_object* v___x_2266_; lean_object* v___x_2267_; 
v___x_2263_ = ((lean_object*)(lp_bounded_Bounded_instReprStepSig_repr___closed__11));
lean_inc(v___y_2262_);
v___x_2264_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_2264_, 0, v___y_2262_);
lean_ctor_set(v___x_2264_, 1, v___x_2263_);
v___x_2265_ = 0;
v___x_2266_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_2266_, 0, v___x_2264_);
lean_ctor_set_uint8(v___x_2266_, sizeof(void*)*1, v___x_2265_);
v___x_2267_ = l_Repr_addAppParen(v___x_2266_, v_prec_2225_);
return v___x_2267_;
}
v___jp_2268_:
{
lean_object* v___x_2270_; lean_object* v___x_2271_; uint8_t v___x_2272_; lean_object* v___x_2273_; lean_object* v___x_2274_; 
v___x_2270_ = ((lean_object*)(lp_bounded_Bounded_instReprStepSig_repr___closed__13));
lean_inc(v___y_2269_);
v___x_2271_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_2271_, 0, v___y_2269_);
lean_ctor_set(v___x_2271_, 1, v___x_2270_);
v___x_2272_ = 0;
v___x_2273_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_2273_, 0, v___x_2271_);
lean_ctor_set_uint8(v___x_2273_, sizeof(void*)*1, v___x_2272_);
v___x_2274_ = l_Repr_addAppParen(v___x_2273_, v_prec_2225_);
return v___x_2274_;
}
v___jp_2275_:
{
lean_object* v___x_2277_; lean_object* v___x_2278_; uint8_t v___x_2279_; lean_object* v___x_2280_; lean_object* v___x_2281_; 
v___x_2277_ = ((lean_object*)(lp_bounded_Bounded_instReprStepSig_repr___closed__15));
lean_inc(v___y_2276_);
v___x_2278_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_2278_, 0, v___y_2276_);
lean_ctor_set(v___x_2278_, 1, v___x_2277_);
v___x_2279_ = 0;
v___x_2280_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_2280_, 0, v___x_2278_);
lean_ctor_set_uint8(v___x_2280_, sizeof(void*)*1, v___x_2279_);
v___x_2281_ = l_Repr_addAppParen(v___x_2280_, v_prec_2225_);
return v___x_2281_;
}
v___jp_2282_:
{
lean_object* v___x_2284_; lean_object* v___x_2285_; uint8_t v___x_2286_; lean_object* v___x_2287_; lean_object* v___x_2288_; 
v___x_2284_ = ((lean_object*)(lp_bounded_Bounded_instReprStepSig_repr___closed__17));
lean_inc(v___y_2283_);
v___x_2285_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_2285_, 0, v___y_2283_);
lean_ctor_set(v___x_2285_, 1, v___x_2284_);
v___x_2286_ = 0;
v___x_2287_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_2287_, 0, v___x_2285_);
lean_ctor_set_uint8(v___x_2287_, sizeof(void*)*1, v___x_2286_);
v___x_2288_ = l_Repr_addAppParen(v___x_2287_, v_prec_2225_);
return v___x_2288_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprStepSig_repr___boxed(lean_object* v_x_2340_, lean_object* v_prec_2341_){
_start:
{
lean_object* v_res_2342_; 
v_res_2342_ = lp_bounded_Bounded_instReprStepSig_repr(v_x_2340_, v_prec_2341_);
lean_dec(v_prec_2341_);
lean_dec(v_x_2340_);
return v_res_2342_;
}
}
LEAN_EXPORT uint8_t lp_bounded_List_any___at___00Bounded_dynConflict_spec__0(lean_object* v_n_2345_, lean_object* v_00_u03b3_2346_, lean_object* v_k_2347_, lean_object* v_x_2348_){
_start:
{
if (lean_obj_tag(v_x_2348_) == 0)
{
uint8_t v___x_2349_; 
v___x_2349_ = 0;
return v___x_2349_;
}
else
{
lean_object* v_head_2350_; lean_object* v_tail_2351_; uint8_t v___y_2353_; uint8_t v___x_2355_; 
v_head_2350_ = lean_ctor_get(v_x_2348_, 0);
v_tail_2351_ = lean_ctor_get(v_x_2348_, 1);
v___x_2355_ = lean_nat_dec_eq(v_head_2350_, v_n_2345_);
if (v___x_2355_ == 0)
{
lean_object* v___x_2356_; 
v___x_2356_ = lp_bounded_Bounded_SMap_get___redArg(v_00_u03b3_2346_, v_head_2350_);
if (lean_obj_tag(v___x_2356_) == 0)
{
v___y_2353_ = v___x_2355_;
goto v___jp_2352_;
}
else
{
lean_object* v_val_2357_; lean_object* v_table_2358_; lean_object* v___x_2359_; 
v_val_2357_ = lean_ctor_get(v___x_2356_, 0);
lean_inc(v_val_2357_);
lean_dec_ref_known(v___x_2356_, 1);
v_table_2358_ = lean_ctor_get(v_val_2357_, 2);
lean_inc_ref(v_table_2358_);
lean_dec(v_val_2357_);
v___x_2359_ = lp_bounded_Bounded_KMap_get___redArg(v_table_2358_, v_k_2347_);
lean_dec_ref(v_table_2358_);
if (lean_obj_tag(v___x_2359_) == 0)
{
v___y_2353_ = v___x_2355_;
goto v___jp_2352_;
}
else
{
uint8_t v___x_2360_; 
lean_dec_ref_known(v___x_2359_, 1);
v___x_2360_ = 1;
return v___x_2360_;
}
}
}
else
{
v_x_2348_ = v_tail_2351_;
goto _start;
}
v___jp_2352_:
{
if (v___y_2353_ == 0)
{
v_x_2348_ = v_tail_2351_;
goto _start;
}
else
{
return v___y_2353_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_List_any___at___00Bounded_dynConflict_spec__0___boxed(lean_object* v_n_2362_, lean_object* v_00_u03b3_2363_, lean_object* v_k_2364_, lean_object* v_x_2365_){
_start:
{
uint8_t v_res_2366_; lean_object* v_r_2367_; 
v_res_2366_ = lp_bounded_List_any___at___00Bounded_dynConflict_spec__0(v_n_2362_, v_00_u03b3_2363_, v_k_2364_, v_x_2365_);
lean_dec(v_x_2365_);
lean_dec(v_k_2364_);
lean_dec_ref(v_00_u03b3_2363_);
lean_dec(v_n_2362_);
v_r_2367_ = lean_box(v_res_2366_);
return v_r_2367_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_dynConflict(lean_object* v_00_u03b3_2368_, lean_object* v_n_2369_, lean_object* v_k_2370_){
_start:
{
lean_object* v___x_2371_; uint8_t v___x_2372_; 
v___x_2371_ = lp_bounded_Bounded_allSlots;
v___x_2372_ = lp_bounded_List_any___at___00Bounded_dynConflict_spec__0(v_n_2369_, v_00_u03b3_2368_, v_k_2370_, v___x_2371_);
return v___x_2372_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_dynConflict___boxed(lean_object* v_00_u03b3_2373_, lean_object* v_n_2374_, lean_object* v_k_2375_){
_start:
{
uint8_t v_res_2376_; lean_object* v_r_2377_; 
v_res_2376_ = lp_bounded_Bounded_dynConflict(v_00_u03b3_2373_, v_n_2374_, v_k_2375_);
lean_dec(v_k_2375_);
lean_dec(v_n_2374_);
lean_dec_ref(v_00_u03b3_2373_);
v_r_2377_ = lean_box(v_res_2376_);
return v_r_2377_;
}
}
LEAN_EXPORT uint8_t lp_bounded_List_any___at___00Bounded_classifyCore_spec__0(lean_object* v_00_u03b3_2378_, lean_object* v_x_2379_){
_start:
{
if (lean_obj_tag(v_x_2379_) == 0)
{
uint8_t v___x_2380_; 
v___x_2380_ = 0;
return v___x_2380_;
}
else
{
lean_object* v_head_2381_; lean_object* v_tail_2382_; lean_object* v___x_2383_; 
v_head_2381_ = lean_ctor_get(v_x_2379_, 0);
v_tail_2382_ = lean_ctor_get(v_x_2379_, 1);
v___x_2383_ = lp_bounded_Bounded_SMap_get___redArg(v_00_u03b3_2378_, v_head_2381_);
if (lean_obj_tag(v___x_2383_) == 0)
{
uint8_t v___x_2384_; 
v___x_2384_ = 1;
return v___x_2384_;
}
else
{
lean_dec_ref_known(v___x_2383_, 1);
v_x_2379_ = v_tail_2382_;
goto _start;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_List_any___at___00Bounded_classifyCore_spec__0___boxed(lean_object* v_00_u03b3_2386_, lean_object* v_x_2387_){
_start:
{
uint8_t v_res_2388_; lean_object* v_r_2389_; 
v_res_2388_ = lp_bounded_List_any___at___00Bounded_classifyCore_spec__0(v_00_u03b3_2386_, v_x_2387_);
lean_dec(v_x_2387_);
lean_dec_ref(v_00_u03b3_2386_);
v_r_2389_ = lean_box(v_res_2388_);
return v_r_2389_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_classifyCore(lean_object* v_00_u03b3_2398_, lean_object* v_n_2399_, lean_object* v_f_2400_, lean_object* v_x_2401_){
_start:
{
switch(lean_obj_tag(v_x_2401_))
{
case 0:
{
lean_object* v_k_2402_; uint8_t v___x_2403_; 
v_k_2402_ = lean_ctor_get(v_x_2401_, 0);
v___x_2403_ = lp_bounded_Bounded_dynConflict(v_00_u03b3_2398_, v_n_2399_, v_k_2402_);
if (v___x_2403_ == 0)
{
lean_object* v___x_2404_; 
v___x_2404_ = lean_box(0);
return v___x_2404_;
}
else
{
lean_object* v___x_2405_; 
v___x_2405_ = lean_box(1);
return v___x_2405_;
}
}
case 1:
{
lean_object* v___x_2406_; 
v___x_2406_ = lean_box(2);
return v___x_2406_;
}
case 2:
{
lean_object* v_k_2407_; lean_object* v___x_2408_; uint8_t v___x_2409_; lean_object* v___x_2410_; 
v_k_2407_ = lean_ctor_get(v_x_2401_, 0);
v___x_2408_ = lean_unsigned_to_nat(4u);
v___x_2409_ = 0;
v___x_2410_ = lp_bounded_Bounded_readC(v_00_u03b3_2398_, v___x_2408_, v_n_2399_, v_k_2407_, v___x_2409_);
switch(lean_obj_tag(v___x_2410_))
{
case 0:
{
uint8_t v_ancestor_2411_; 
v_ancestor_2411_ = lean_ctor_get_uint8(v___x_2410_, sizeof(void*)*1);
lean_dec_ref_known(v___x_2410_, 1);
if (v_ancestor_2411_ == 0)
{
lean_object* v___x_2412_; 
v___x_2412_ = ((lean_object*)(lp_bounded_Bounded_classifyCore___closed__0));
return v___x_2412_;
}
else
{
lean_object* v___x_2413_; 
v___x_2413_ = ((lean_object*)(lp_bounded_Bounded_classifyCore___closed__1));
return v___x_2413_;
}
}
case 1:
{
lean_object* v___x_2414_; 
v___x_2414_ = ((lean_object*)(lp_bounded_Bounded_classifyCore___closed__2));
return v___x_2414_;
}
default: 
{
lean_object* v___x_2415_; 
v___x_2415_ = ((lean_object*)(lp_bounded_Bounded_classifyCore___closed__3));
return v___x_2415_;
}
}
}
case 3:
{
lean_object* v_k_2416_; lean_object* v_table_2417_; lean_object* v___x_2418_; 
v_k_2416_ = lean_ctor_get(v_x_2401_, 0);
v_table_2417_ = lean_ctor_get(v_f_2400_, 2);
v___x_2418_ = lp_bounded_Bounded_KMap_get___redArg(v_table_2417_, v_k_2416_);
if (lean_obj_tag(v___x_2418_) == 0)
{
lean_object* v___x_2419_; 
v___x_2419_ = lean_box(5);
return v___x_2419_;
}
else
{
lean_object* v___x_2420_; 
lean_dec_ref_known(v___x_2418_, 1);
v___x_2420_ = lean_box(4);
return v___x_2420_;
}
}
case 4:
{
lean_object* v___x_2421_; uint8_t v___x_2422_; 
v___x_2421_ = lp_bounded_Bounded_allSlots;
v___x_2422_ = lp_bounded_List_any___at___00Bounded_classifyCore_spec__0(v_00_u03b3_2398_, v___x_2421_);
if (v___x_2422_ == 0)
{
lean_object* v___x_2423_; 
v___x_2423_ = lean_box(7);
return v___x_2423_;
}
else
{
lean_object* v___x_2424_; 
v___x_2424_ = lean_box(6);
return v___x_2424_;
}
}
default: 
{
lean_object* v___x_2425_; 
v___x_2425_ = lean_box(8);
return v___x_2425_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_classifyCore___boxed(lean_object* v_00_u03b3_2426_, lean_object* v_n_2427_, lean_object* v_f_2428_, lean_object* v_x_2429_){
_start:
{
lean_object* v_res_2430_; 
v_res_2430_ = lp_bounded_Bounded_classifyCore(v_00_u03b3_2426_, v_n_2427_, v_f_2428_, v_x_2429_);
lean_dec(v_x_2429_);
lean_dec_ref(v_f_2428_);
lean_dec(v_n_2427_);
lean_dec_ref(v_00_u03b3_2426_);
return v_res_2430_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_classifyIter(lean_object* v_00_u03b3_2431_, lean_object* v_n_2432_, lean_object* v_f_2433_, lean_object* v_creg_2434_, lean_object* v_x_2435_){
_start:
{
if (lean_obj_tag(v_x_2435_) == 4)
{
if (lean_obj_tag(v_creg_2434_) == 0)
{
lean_object* v___x_2436_; 
v___x_2436_ = lean_box(9);
return v___x_2436_;
}
else
{
lean_object* v_val_2437_; lean_object* v___x_2438_; 
v_val_2437_ = lean_ctor_get(v_creg_2434_, 0);
v___x_2438_ = lp_bounded_Bounded_SMap_get___redArg(v_00_u03b3_2431_, v_val_2437_);
if (lean_obj_tag(v___x_2438_) == 0)
{
lean_object* v___x_2439_; 
v___x_2439_ = lean_box(6);
return v___x_2439_;
}
else
{
lean_object* v___x_2440_; 
lean_dec_ref_known(v___x_2438_, 1);
v___x_2440_ = lean_box(7);
return v___x_2440_;
}
}
}
else
{
if (lean_obj_tag(v_creg_2434_) == 0)
{
lean_object* v___x_2441_; 
v___x_2441_ = lp_bounded_Bounded_classifyCore(v_00_u03b3_2431_, v_n_2432_, v_f_2433_, v_x_2435_);
return v___x_2441_;
}
else
{
lean_object* v___x_2442_; 
v___x_2442_ = lean_box(9);
return v___x_2442_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_classifyIter___boxed(lean_object* v_00_u03b3_2443_, lean_object* v_n_2444_, lean_object* v_f_2445_, lean_object* v_creg_2446_, lean_object* v_x_2447_){
_start:
{
lean_object* v_res_2448_; 
v_res_2448_ = lp_bounded_Bounded_classifyIter(v_00_u03b3_2443_, v_n_2444_, v_f_2445_, v_creg_2446_, v_x_2447_);
lean_dec(v_x_2447_);
lean_dec(v_creg_2446_);
lean_dec_ref(v_f_2445_);
lean_dec(v_n_2444_);
lean_dec_ref(v_00_u03b3_2443_);
return v_res_2448_;
}
}
LEAN_EXPORT uint8_t lp_bounded_List_any___at___00Bounded_instProvided_spec__0(lean_object* v_00_u03b3_2449_, lean_object* v_k_2450_, lean_object* v_x_2451_){
_start:
{
if (lean_obj_tag(v_x_2451_) == 0)
{
uint8_t v___x_2452_; 
v___x_2452_ = 0;
return v___x_2452_;
}
else
{
lean_object* v_head_2453_; lean_object* v_tail_2454_; uint8_t v___y_2456_; lean_object* v___x_2458_; 
v_head_2453_ = lean_ctor_get(v_x_2451_, 0);
v_tail_2454_ = lean_ctor_get(v_x_2451_, 1);
v___x_2458_ = lp_bounded_Bounded_SMap_get___redArg(v_00_u03b3_2449_, v_head_2453_);
if (lean_obj_tag(v___x_2458_) == 0)
{
v_x_2451_ = v_tail_2454_;
goto _start;
}
else
{
lean_object* v_val_2460_; lean_object* v_table_2461_; lean_object* v_st_2462_; uint8_t v___x_2463_; 
v_val_2460_ = lean_ctor_get(v___x_2458_, 0);
lean_inc(v_val_2460_);
lean_dec_ref_known(v___x_2458_, 1);
v_table_2461_ = lean_ctor_get(v_val_2460_, 2);
lean_inc_ref(v_table_2461_);
v_st_2462_ = lean_ctor_get(v_val_2460_, 3);
lean_inc_ref(v_st_2462_);
lean_dec(v_val_2460_);
v___x_2463_ = lp_bounded_Bounded_LState_isInstalled(v_st_2462_);
lean_dec_ref(v_st_2462_);
if (v___x_2463_ == 0)
{
lean_dec_ref(v_table_2461_);
v___y_2456_ = v___x_2463_;
goto v___jp_2455_;
}
else
{
lean_object* v___x_2464_; 
v___x_2464_ = lp_bounded_Bounded_KMap_get___redArg(v_table_2461_, v_k_2450_);
lean_dec_ref(v_table_2461_);
if (lean_obj_tag(v___x_2464_) == 0)
{
v_x_2451_ = v_tail_2454_;
goto _start;
}
else
{
lean_dec_ref_known(v___x_2464_, 1);
v___y_2456_ = v___x_2463_;
goto v___jp_2455_;
}
}
}
v___jp_2455_:
{
if (v___y_2456_ == 0)
{
v_x_2451_ = v_tail_2454_;
goto _start;
}
else
{
return v___y_2456_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_List_any___at___00Bounded_instProvided_spec__0___boxed(lean_object* v_00_u03b3_2466_, lean_object* v_k_2467_, lean_object* v_x_2468_){
_start:
{
uint8_t v_res_2469_; lean_object* v_r_2470_; 
v_res_2469_ = lp_bounded_List_any___at___00Bounded_instProvided_spec__0(v_00_u03b3_2466_, v_k_2467_, v_x_2468_);
lean_dec(v_x_2468_);
lean_dec(v_k_2467_);
lean_dec_ref(v_00_u03b3_2466_);
v_r_2470_ = lean_box(v_res_2469_);
return v_r_2470_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instProvided(lean_object* v_00_u03b3_2471_, lean_object* v_k_2472_){
_start:
{
lean_object* v___x_2473_; uint8_t v___x_2474_; 
v___x_2473_ = lp_bounded_Bounded_allSlots;
v___x_2474_ = lp_bounded_List_any___at___00Bounded_instProvided_spec__0(v_00_u03b3_2471_, v_k_2472_, v___x_2473_);
return v___x_2474_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instProvided___boxed(lean_object* v_00_u03b3_2475_, lean_object* v_k_2476_){
_start:
{
uint8_t v_res_2477_; lean_object* v_r_2478_; 
v_res_2477_ = lp_bounded_Bounded_instProvided(v_00_u03b3_2475_, v_k_2476_);
lean_dec(v_k_2476_);
lean_dec_ref(v_00_u03b3_2475_);
v_r_2478_ = lean_box(v_res_2477_);
return v_r_2478_;
}
}
LEAN_EXPORT uint8_t lp_bounded_List_any___at___00Bounded_satClsOf_spec__2(lean_object* v_00_u03b3_2479_, lean_object* v_f_2480_, lean_object* v_x_2481_){
_start:
{
if (lean_obj_tag(v_x_2481_) == 0)
{
uint8_t v___x_2482_; 
v___x_2482_ = 0;
return v___x_2482_;
}
else
{
lean_object* v_head_2483_; lean_object* v_tail_2484_; uint8_t v___y_2486_; lean_object* v_comp_2490_; lean_object* v_deps_2491_; lean_object* v___x_2492_; uint8_t v___x_2493_; 
v_head_2483_ = lean_ctor_get(v_x_2481_, 0);
v_tail_2484_ = lean_ctor_get(v_x_2481_, 1);
v_comp_2490_ = lean_ctor_get(v_f_2480_, 0);
v_deps_2491_ = lean_ctor_get(v_comp_2490_, 0);
v___x_2492_ = lp_bounded_Bounded_KMap_get___redArg(v_deps_2491_, v_head_2483_);
v___x_2493_ = lean_unbox(v___x_2492_);
if (v___x_2493_ == 0)
{
uint8_t v___x_2494_; 
v___x_2494_ = lean_unbox(v___x_2492_);
lean_dec(v___x_2492_);
v___y_2486_ = v___x_2494_;
goto v___jp_2485_;
}
else
{
lean_object* v___x_2495_; 
v___x_2495_ = lp_bounded_Bounded_providerOf(v_00_u03b3_2479_, v_head_2483_);
if (lean_obj_tag(v___x_2495_) == 0)
{
uint8_t v___x_2496_; 
v___x_2496_ = lean_unbox(v___x_2492_);
lean_dec(v___x_2492_);
v___y_2486_ = v___x_2496_;
goto v___jp_2485_;
}
else
{
lean_dec_ref_known(v___x_2495_, 1);
lean_dec(v___x_2492_);
v_x_2481_ = v_tail_2484_;
goto _start;
}
}
v___jp_2485_:
{
if (v___y_2486_ == 0)
{
v_x_2481_ = v_tail_2484_;
goto _start;
}
else
{
uint8_t v___x_2488_; 
v___x_2488_ = lp_bounded_Bounded_instProvided(v_00_u03b3_2479_, v_head_2483_);
if (v___x_2488_ == 0)
{
return v___y_2486_;
}
else
{
v_x_2481_ = v_tail_2484_;
goto _start;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_List_any___at___00Bounded_satClsOf_spec__2___boxed(lean_object* v_00_u03b3_2498_, lean_object* v_f_2499_, lean_object* v_x_2500_){
_start:
{
uint8_t v_res_2501_; lean_object* v_r_2502_; 
v_res_2501_ = lp_bounded_List_any___at___00Bounded_satClsOf_spec__2(v_00_u03b3_2498_, v_f_2499_, v_x_2500_);
lean_dec(v_x_2500_);
lean_dec_ref(v_f_2499_);
lean_dec_ref(v_00_u03b3_2498_);
v_r_2502_ = lean_box(v_res_2501_);
return v_r_2502_;
}
}
LEAN_EXPORT uint8_t lp_bounded_List_any___at___00Bounded_satClsOf_spec__1(lean_object* v_00_u03b3_2503_, lean_object* v_f_2504_, lean_object* v_x_2505_){
_start:
{
if (lean_obj_tag(v_x_2505_) == 0)
{
uint8_t v___x_2506_; 
v___x_2506_ = 0;
return v___x_2506_;
}
else
{
lean_object* v_head_2507_; lean_object* v_tail_2508_; uint8_t v___y_2510_; lean_object* v_comp_2514_; lean_object* v_deps_2515_; lean_object* v___x_2516_; uint8_t v___x_2517_; 
v_head_2507_ = lean_ctor_get(v_x_2505_, 0);
v_tail_2508_ = lean_ctor_get(v_x_2505_, 1);
v_comp_2514_ = lean_ctor_get(v_f_2504_, 0);
v_deps_2515_ = lean_ctor_get(v_comp_2514_, 0);
v___x_2516_ = lp_bounded_Bounded_KMap_get___redArg(v_deps_2515_, v_head_2507_);
v___x_2517_ = lean_unbox(v___x_2516_);
if (v___x_2517_ == 0)
{
uint8_t v___x_2518_; 
v___x_2518_ = lean_unbox(v___x_2516_);
lean_dec(v___x_2516_);
v___y_2510_ = v___x_2518_;
goto v___jp_2509_;
}
else
{
lean_object* v___x_2519_; 
v___x_2519_ = lp_bounded_Bounded_providerOf(v_00_u03b3_2503_, v_head_2507_);
if (lean_obj_tag(v___x_2519_) == 0)
{
uint8_t v___x_2520_; 
v___x_2520_ = lean_unbox(v___x_2516_);
lean_dec(v___x_2516_);
v___y_2510_ = v___x_2520_;
goto v___jp_2509_;
}
else
{
lean_dec_ref_known(v___x_2519_, 1);
lean_dec(v___x_2516_);
v_x_2505_ = v_tail_2508_;
goto _start;
}
}
v___jp_2509_:
{
if (v___y_2510_ == 0)
{
v_x_2505_ = v_tail_2508_;
goto _start;
}
else
{
uint8_t v___x_2512_; 
v___x_2512_ = lp_bounded_Bounded_instProvided(v_00_u03b3_2503_, v_head_2507_);
if (v___x_2512_ == 0)
{
v_x_2505_ = v_tail_2508_;
goto _start;
}
else
{
return v___x_2512_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_List_any___at___00Bounded_satClsOf_spec__1___boxed(lean_object* v_00_u03b3_2522_, lean_object* v_f_2523_, lean_object* v_x_2524_){
_start:
{
uint8_t v_res_2525_; lean_object* v_r_2526_; 
v_res_2525_ = lp_bounded_List_any___at___00Bounded_satClsOf_spec__1(v_00_u03b3_2522_, v_f_2523_, v_x_2524_);
lean_dec(v_x_2524_);
lean_dec_ref(v_f_2523_);
lean_dec_ref(v_00_u03b3_2522_);
v_r_2526_ = lean_box(v_res_2525_);
return v_r_2526_;
}
}
LEAN_EXPORT uint8_t lp_bounded_List_any___at___00Bounded_satClsOf_spec__0(lean_object* v_f_2527_, lean_object* v_00_u03b3_2528_, lean_object* v_x_2529_){
_start:
{
if (lean_obj_tag(v_x_2529_) == 0)
{
uint8_t v___x_2530_; 
v___x_2530_ = 0;
return v___x_2530_;
}
else
{
lean_object* v_head_2531_; lean_object* v_tail_2532_; uint8_t v___y_2534_; lean_object* v_comp_2536_; lean_object* v_deps_2537_; lean_object* v___x_2538_; uint8_t v___x_2539_; 
v_head_2531_ = lean_ctor_get(v_x_2529_, 0);
v_tail_2532_ = lean_ctor_get(v_x_2529_, 1);
v_comp_2536_ = lean_ctor_get(v_f_2527_, 0);
v_deps_2537_ = lean_ctor_get(v_comp_2536_, 0);
v___x_2538_ = lp_bounded_Bounded_KMap_get___redArg(v_deps_2537_, v_head_2531_);
v___x_2539_ = lean_unbox(v___x_2538_);
if (v___x_2539_ == 0)
{
uint8_t v___x_2540_; 
v___x_2540_ = lean_unbox(v___x_2538_);
lean_dec(v___x_2538_);
v___y_2534_ = v___x_2540_;
goto v___jp_2533_;
}
else
{
lean_object* v___x_2541_; 
v___x_2541_ = lp_bounded_Bounded_providerOf(v_00_u03b3_2528_, v_head_2531_);
if (lean_obj_tag(v___x_2541_) == 0)
{
lean_dec(v___x_2538_);
v_x_2529_ = v_tail_2532_;
goto _start;
}
else
{
uint8_t v___x_2543_; 
lean_dec_ref_known(v___x_2541_, 1);
v___x_2543_ = lean_unbox(v___x_2538_);
lean_dec(v___x_2538_);
v___y_2534_ = v___x_2543_;
goto v___jp_2533_;
}
}
v___jp_2533_:
{
if (v___y_2534_ == 0)
{
v_x_2529_ = v_tail_2532_;
goto _start;
}
else
{
return v___y_2534_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_List_any___at___00Bounded_satClsOf_spec__0___boxed(lean_object* v_f_2544_, lean_object* v_00_u03b3_2545_, lean_object* v_x_2546_){
_start:
{
uint8_t v_res_2547_; lean_object* v_r_2548_; 
v_res_2547_ = lp_bounded_List_any___at___00Bounded_satClsOf_spec__0(v_f_2544_, v_00_u03b3_2545_, v_x_2546_);
lean_dec(v_x_2546_);
lean_dec_ref(v_00_u03b3_2545_);
lean_dec_ref(v_f_2544_);
v_r_2548_ = lean_box(v_res_2547_);
return v_r_2548_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_satClsOf(lean_object* v_00_u03b3_2549_, lean_object* v_f_2550_){
_start:
{
lean_object* v___x_2551_; uint8_t v___x_2552_; uint8_t v___x_2553_; uint8_t v___x_2554_; lean_object* v___x_2555_; lean_object* v___x_2556_; lean_object* v___x_2557_; lean_object* v___x_2558_; lean_object* v___x_2559_; 
v___x_2551_ = lp_bounded_Bounded_allKeys;
v___x_2552_ = lp_bounded_List_any___at___00Bounded_satClsOf_spec__0(v_f_2550_, v_00_u03b3_2549_, v___x_2551_);
v___x_2553_ = lp_bounded_List_any___at___00Bounded_satClsOf_spec__1(v_00_u03b3_2549_, v_f_2550_, v___x_2551_);
v___x_2554_ = lp_bounded_List_any___at___00Bounded_satClsOf_spec__2(v_00_u03b3_2549_, v_f_2550_, v___x_2551_);
v___x_2555_ = lean_box(v___x_2553_);
v___x_2556_ = lean_box(v___x_2554_);
v___x_2557_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2557_, 0, v___x_2555_);
lean_ctor_set(v___x_2557_, 1, v___x_2556_);
v___x_2558_ = lean_box(v___x_2552_);
v___x_2559_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2559_, 0, v___x_2558_);
lean_ctor_set(v___x_2559_, 1, v___x_2557_);
return v___x_2559_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_satClsOf___boxed(lean_object* v_00_u03b3_2560_, lean_object* v_f_2561_){
_start:
{
lean_object* v_res_2562_; 
v_res_2562_ = lp_bounded_Bounded_satClsOf(v_00_u03b3_2560_, v_f_2561_);
lean_dec_ref(v_f_2561_);
lean_dec_ref(v_00_u03b3_2560_);
return v_res_2562_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_isUnprovideI(lean_object* v_x_2563_){
_start:
{
if (lean_obj_tag(v_x_2563_) == 0)
{
uint8_t v___x_2564_; 
v___x_2564_ = 1;
return v___x_2564_;
}
else
{
uint8_t v___x_2565_; 
v___x_2565_ = 0;
return v___x_2565_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_isUnprovideI___boxed(lean_object* v_x_2566_){
_start:
{
uint8_t v_res_2567_; lean_object* v_r_2568_; 
v_res_2567_ = lp_bounded_Bounded_isUnprovideI(v_x_2566_);
lean_dec_ref(v_x_2566_);
v_r_2568_ = lean_box(v_res_2567_);
return v_r_2568_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_isUntrackI(lean_object* v_x_2569_){
_start:
{
if (lean_obj_tag(v_x_2569_) == 1)
{
uint8_t v___x_2570_; 
v___x_2570_ = 1;
return v___x_2570_;
}
else
{
uint8_t v___x_2571_; 
v___x_2571_ = 0;
return v___x_2571_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_isUntrackI___boxed(lean_object* v_x_2572_){
_start:
{
uint8_t v_res_2573_; lean_object* v_r_2574_; 
v_res_2573_ = lp_bounded_Bounded_isUntrackI(v_x_2572_);
lean_dec_ref(v_x_2572_);
v_r_2574_ = lean_box(v_res_2573_);
return v_r_2574_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_isRetireChildI(lean_object* v_x_2575_){
_start:
{
if (lean_obj_tag(v_x_2575_) == 2)
{
uint8_t v___x_2576_; 
v___x_2576_ = 1;
return v___x_2576_;
}
else
{
uint8_t v___x_2577_; 
v___x_2577_ = 0;
return v___x_2577_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_isRetireChildI___boxed(lean_object* v_x_2578_){
_start:
{
uint8_t v_res_2579_; lean_object* v_r_2580_; 
v_res_2579_ = lp_bounded_Bounded_isRetireChildI(v_x_2578_);
lean_dec_ref(v_x_2578_);
v_r_2580_ = lean_box(v_res_2579_);
return v_r_2580_;
}
}
LEAN_EXPORT uint8_t lp_bounded_List_any___at___00Bounded_accClsOf_spec__1(lean_object* v_x_2581_){
_start:
{
if (lean_obj_tag(v_x_2581_) == 0)
{
uint8_t v___x_2582_; 
v___x_2582_ = 0;
return v___x_2582_;
}
else
{
lean_object* v_head_2583_; lean_object* v_tail_2584_; uint8_t v___x_2585_; 
v_head_2583_ = lean_ctor_get(v_x_2581_, 0);
v_tail_2584_ = lean_ctor_get(v_x_2581_, 1);
v___x_2585_ = lp_bounded_Bounded_isUntrackI(v_head_2583_);
if (v___x_2585_ == 0)
{
v_x_2581_ = v_tail_2584_;
goto _start;
}
else
{
return v___x_2585_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_List_any___at___00Bounded_accClsOf_spec__1___boxed(lean_object* v_x_2587_){
_start:
{
uint8_t v_res_2588_; lean_object* v_r_2589_; 
v_res_2588_ = lp_bounded_List_any___at___00Bounded_accClsOf_spec__1(v_x_2587_);
lean_dec(v_x_2587_);
v_r_2589_ = lean_box(v_res_2588_);
return v_r_2589_;
}
}
LEAN_EXPORT uint8_t lp_bounded_List_any___at___00Bounded_accClsOf_spec__0(lean_object* v_x_2590_){
_start:
{
if (lean_obj_tag(v_x_2590_) == 0)
{
uint8_t v___x_2591_; 
v___x_2591_ = 0;
return v___x_2591_;
}
else
{
lean_object* v_head_2592_; lean_object* v_tail_2593_; uint8_t v___x_2594_; 
v_head_2592_ = lean_ctor_get(v_x_2590_, 0);
v_tail_2593_ = lean_ctor_get(v_x_2590_, 1);
v___x_2594_ = lp_bounded_Bounded_isUnprovideI(v_head_2592_);
if (v___x_2594_ == 0)
{
v_x_2590_ = v_tail_2593_;
goto _start;
}
else
{
return v___x_2594_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_List_any___at___00Bounded_accClsOf_spec__0___boxed(lean_object* v_x_2596_){
_start:
{
uint8_t v_res_2597_; lean_object* v_r_2598_; 
v_res_2597_ = lp_bounded_List_any___at___00Bounded_accClsOf_spec__0(v_x_2596_);
lean_dec(v_x_2596_);
v_r_2598_ = lean_box(v_res_2597_);
return v_r_2598_;
}
}
LEAN_EXPORT uint8_t lp_bounded_List_any___at___00Bounded_accClsOf_spec__2(lean_object* v_x_2599_){
_start:
{
if (lean_obj_tag(v_x_2599_) == 0)
{
uint8_t v___x_2600_; 
v___x_2600_ = 0;
return v___x_2600_;
}
else
{
lean_object* v_head_2601_; lean_object* v_tail_2602_; uint8_t v___x_2603_; 
v_head_2601_ = lean_ctor_get(v_x_2599_, 0);
v_tail_2602_ = lean_ctor_get(v_x_2599_, 1);
v___x_2603_ = lp_bounded_Bounded_isRetireChildI(v_head_2601_);
if (v___x_2603_ == 0)
{
v_x_2599_ = v_tail_2602_;
goto _start;
}
else
{
return v___x_2603_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_List_any___at___00Bounded_accClsOf_spec__2___boxed(lean_object* v_x_2605_){
_start:
{
uint8_t v_res_2606_; lean_object* v_r_2607_; 
v_res_2606_ = lp_bounded_List_any___at___00Bounded_accClsOf_spec__2(v_x_2605_);
lean_dec(v_x_2605_);
v_r_2607_ = lean_box(v_res_2606_);
return v_r_2607_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_accClsOf(lean_object* v_acc_2608_){
_start:
{
uint8_t v___x_2609_; uint8_t v___x_2610_; uint8_t v___x_2611_; lean_object* v___x_2612_; lean_object* v___x_2613_; lean_object* v___x_2614_; lean_object* v___x_2615_; lean_object* v___x_2616_; 
v___x_2609_ = lp_bounded_List_any___at___00Bounded_accClsOf_spec__0(v_acc_2608_);
v___x_2610_ = lp_bounded_List_any___at___00Bounded_accClsOf_spec__1(v_acc_2608_);
v___x_2611_ = lp_bounded_List_any___at___00Bounded_accClsOf_spec__2(v_acc_2608_);
v___x_2612_ = lean_box(v___x_2610_);
v___x_2613_ = lean_box(v___x_2611_);
v___x_2614_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2614_, 0, v___x_2612_);
lean_ctor_set(v___x_2614_, 1, v___x_2613_);
v___x_2615_ = lean_box(v___x_2609_);
v___x_2616_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2616_, 0, v___x_2615_);
lean_ctor_set(v___x_2616_, 1, v___x_2614_);
return v___x_2616_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_accClsOf___boxed(lean_object* v_acc_2617_){
_start:
{
lean_object* v_res_2618_; 
v_res_2618_ = lp_bounded_Bounded_accClsOf(v_acc_2617_);
lean_dec(v_acc_2617_);
return v_res_2618_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqSigR_decEq___lam__0(uint8_t v___x_2619_, uint8_t v___y_2620_, uint8_t v___y_2621_){
_start:
{
if (v___y_2620_ == 0)
{
if (v___y_2621_ == 0)
{
return v___x_2619_;
}
else
{
return v___y_2620_;
}
}
else
{
return v___y_2621_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqSigR_decEq___lam__0___boxed(lean_object* v___x_2622_, lean_object* v___y_2623_, lean_object* v___y_2624_){
_start:
{
uint8_t v___x_863__boxed_2625_; uint8_t v___y_864__boxed_2626_; uint8_t v___y_865__boxed_2627_; uint8_t v_res_2628_; lean_object* v_r_2629_; 
v___x_863__boxed_2625_ = lean_unbox(v___x_2622_);
v___y_864__boxed_2626_ = lean_unbox(v___y_2623_);
v___y_865__boxed_2627_ = lean_unbox(v___y_2624_);
v_res_2628_ = lp_bounded_Bounded_instDecidableEqSigR_decEq___lam__0(v___x_863__boxed_2625_, v___y_864__boxed_2626_, v___y_865__boxed_2627_);
v_r_2629_ = lean_box(v_res_2628_);
return v_r_2629_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqSigR_decEq___lam__1(lean_object* v___f_2630_, lean_object* v_a_2631_, lean_object* v_b_2632_){
_start:
{
uint8_t v___x_2633_; 
lean_inc_ref(v___f_2630_);
v___x_2633_ = l_instDecidableEqProd___redArg(v___f_2630_, v___f_2630_, v_a_2631_, v_b_2632_);
return v___x_2633_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqSigR_decEq___lam__1___boxed(lean_object* v___f_2634_, lean_object* v_a_2635_, lean_object* v_b_2636_){
_start:
{
uint8_t v_res_2637_; lean_object* v_r_2638_; 
v_res_2637_ = lp_bounded_Bounded_instDecidableEqSigR_decEq___lam__1(v___f_2634_, v_a_2635_, v_b_2636_);
v_r_2638_ = lean_box(v_res_2637_);
return v_r_2638_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqSigR_decEq(lean_object* v_x_2639_, lean_object* v_x_2640_){
_start:
{
uint8_t v_rule_2641_; uint8_t v_present_2642_; uint8_t v_stCls_2643_; uint8_t v_retiredB_2644_; uint8_t v_tRel_2645_; lean_object* v_headStep_2646_; uint8_t v_remEmpty_2647_; uint8_t v_reliedB_2648_; uint8_t v_hasChild_2649_; uint8_t v_slotFree_2650_; uint8_t v_provConf_2651_; uint8_t v_parentLive_2652_; lean_object* v_accCls_2653_; lean_object* v_satCls_2654_; uint8_t v_rule_2655_; uint8_t v_present_2656_; uint8_t v_stCls_2657_; uint8_t v_retiredB_2658_; uint8_t v_tRel_2659_; lean_object* v_headStep_2660_; uint8_t v_remEmpty_2661_; uint8_t v_reliedB_2662_; uint8_t v_hasChild_2663_; uint8_t v_slotFree_2664_; uint8_t v_provConf_2665_; uint8_t v_parentLive_2666_; lean_object* v_accCls_2667_; lean_object* v_satCls_2668_; uint8_t v___x_2669_; 
v_rule_2641_ = lean_ctor_get_uint8(v_x_2639_, sizeof(void*)*3);
v_present_2642_ = lean_ctor_get_uint8(v_x_2639_, sizeof(void*)*3 + 1);
v_stCls_2643_ = lean_ctor_get_uint8(v_x_2639_, sizeof(void*)*3 + 2);
v_retiredB_2644_ = lean_ctor_get_uint8(v_x_2639_, sizeof(void*)*3 + 3);
v_tRel_2645_ = lean_ctor_get_uint8(v_x_2639_, sizeof(void*)*3 + 4);
v_headStep_2646_ = lean_ctor_get(v_x_2639_, 0);
lean_inc(v_headStep_2646_);
v_remEmpty_2647_ = lean_ctor_get_uint8(v_x_2639_, sizeof(void*)*3 + 5);
v_reliedB_2648_ = lean_ctor_get_uint8(v_x_2639_, sizeof(void*)*3 + 6);
v_hasChild_2649_ = lean_ctor_get_uint8(v_x_2639_, sizeof(void*)*3 + 7);
v_slotFree_2650_ = lean_ctor_get_uint8(v_x_2639_, sizeof(void*)*3 + 8);
v_provConf_2651_ = lean_ctor_get_uint8(v_x_2639_, sizeof(void*)*3 + 9);
v_parentLive_2652_ = lean_ctor_get_uint8(v_x_2639_, sizeof(void*)*3 + 10);
v_accCls_2653_ = lean_ctor_get(v_x_2639_, 1);
lean_inc_ref(v_accCls_2653_);
v_satCls_2654_ = lean_ctor_get(v_x_2639_, 2);
lean_inc_ref(v_satCls_2654_);
lean_dec_ref(v_x_2639_);
v_rule_2655_ = lean_ctor_get_uint8(v_x_2640_, sizeof(void*)*3);
v_present_2656_ = lean_ctor_get_uint8(v_x_2640_, sizeof(void*)*3 + 1);
v_stCls_2657_ = lean_ctor_get_uint8(v_x_2640_, sizeof(void*)*3 + 2);
v_retiredB_2658_ = lean_ctor_get_uint8(v_x_2640_, sizeof(void*)*3 + 3);
v_tRel_2659_ = lean_ctor_get_uint8(v_x_2640_, sizeof(void*)*3 + 4);
v_headStep_2660_ = lean_ctor_get(v_x_2640_, 0);
lean_inc(v_headStep_2660_);
v_remEmpty_2661_ = lean_ctor_get_uint8(v_x_2640_, sizeof(void*)*3 + 5);
v_reliedB_2662_ = lean_ctor_get_uint8(v_x_2640_, sizeof(void*)*3 + 6);
v_hasChild_2663_ = lean_ctor_get_uint8(v_x_2640_, sizeof(void*)*3 + 7);
v_slotFree_2664_ = lean_ctor_get_uint8(v_x_2640_, sizeof(void*)*3 + 8);
v_provConf_2665_ = lean_ctor_get_uint8(v_x_2640_, sizeof(void*)*3 + 9);
v_parentLive_2666_ = lean_ctor_get_uint8(v_x_2640_, sizeof(void*)*3 + 10);
v_accCls_2667_ = lean_ctor_get(v_x_2640_, 1);
lean_inc_ref(v_accCls_2667_);
v_satCls_2668_ = lean_ctor_get(v_x_2640_, 2);
lean_inc_ref(v_satCls_2668_);
lean_dec_ref(v_x_2640_);
v___x_2669_ = lp_bounded_Bounded_instDecidableEqRule(v_rule_2641_, v_rule_2655_);
if (v___x_2669_ == 0)
{
lean_dec_ref(v_satCls_2668_);
lean_dec_ref(v_accCls_2667_);
lean_dec(v_headStep_2660_);
lean_dec_ref(v_satCls_2654_);
lean_dec_ref(v_accCls_2653_);
lean_dec(v_headStep_2646_);
return v___x_2669_;
}
else
{
lean_object* v___x_2670_; lean_object* v___f_2671_; lean_object* v___f_2672_; 
v___x_2670_ = lean_box(v___x_2669_);
v___f_2671_ = lean_alloc_closure((void*)(lp_bounded_Bounded_instDecidableEqSigR_decEq___lam__0___boxed), 3, 1);
lean_closure_set(v___f_2671_, 0, v___x_2670_);
lean_inc_ref(v___f_2671_);
v___f_2672_ = lean_alloc_closure((void*)(lp_bounded_Bounded_instDecidableEqSigR_decEq___lam__1___boxed), 3, 1);
lean_closure_set(v___f_2672_, 0, v___f_2671_);
if (v_present_2642_ == 0)
{
if (v_present_2656_ == 0)
{
goto v___jp_2685_;
}
else
{
lean_dec_ref(v___f_2672_);
lean_dec_ref(v___f_2671_);
lean_dec_ref(v_satCls_2668_);
lean_dec_ref(v_accCls_2667_);
lean_dec(v_headStep_2660_);
lean_dec_ref(v_satCls_2654_);
lean_dec_ref(v_accCls_2653_);
lean_dec(v_headStep_2646_);
return v_present_2642_;
}
}
else
{
if (v_present_2656_ == 0)
{
lean_dec_ref(v___f_2672_);
lean_dec_ref(v___f_2671_);
lean_dec_ref(v_satCls_2668_);
lean_dec_ref(v_accCls_2667_);
lean_dec(v_headStep_2660_);
lean_dec_ref(v_satCls_2654_);
lean_dec_ref(v_accCls_2653_);
lean_dec(v_headStep_2646_);
return v_present_2656_;
}
else
{
goto v___jp_2685_;
}
}
v___jp_2673_:
{
uint8_t v___x_2674_; 
lean_inc_ref(v___f_2672_);
lean_inc_ref(v___f_2671_);
v___x_2674_ = l_instDecidableEqProd___redArg(v___f_2671_, v___f_2672_, v_accCls_2653_, v_accCls_2667_);
if (v___x_2674_ == 0)
{
lean_dec_ref(v___f_2672_);
lean_dec_ref(v___f_2671_);
lean_dec_ref(v_satCls_2668_);
lean_dec_ref(v_satCls_2654_);
return v___x_2674_;
}
else
{
uint8_t v___x_2675_; 
v___x_2675_ = l_instDecidableEqProd___redArg(v___f_2671_, v___f_2672_, v_satCls_2654_, v_satCls_2668_);
return v___x_2675_;
}
}
v___jp_2676_:
{
if (v_parentLive_2652_ == 0)
{
if (v_parentLive_2666_ == 0)
{
goto v___jp_2673_;
}
else
{
lean_dec_ref(v___f_2672_);
lean_dec_ref(v___f_2671_);
lean_dec_ref(v_satCls_2668_);
lean_dec_ref(v_accCls_2667_);
lean_dec_ref(v_satCls_2654_);
lean_dec_ref(v_accCls_2653_);
return v_parentLive_2652_;
}
}
else
{
if (v_parentLive_2666_ == 0)
{
lean_dec_ref(v___f_2672_);
lean_dec_ref(v___f_2671_);
lean_dec_ref(v_satCls_2668_);
lean_dec_ref(v_accCls_2667_);
lean_dec_ref(v_satCls_2654_);
lean_dec_ref(v_accCls_2653_);
return v_parentLive_2666_;
}
else
{
goto v___jp_2673_;
}
}
}
v___jp_2677_:
{
if (v_provConf_2651_ == 0)
{
if (v_provConf_2665_ == 0)
{
goto v___jp_2676_;
}
else
{
lean_dec_ref(v___f_2672_);
lean_dec_ref(v___f_2671_);
lean_dec_ref(v_satCls_2668_);
lean_dec_ref(v_accCls_2667_);
lean_dec_ref(v_satCls_2654_);
lean_dec_ref(v_accCls_2653_);
return v_provConf_2651_;
}
}
else
{
if (v_provConf_2665_ == 0)
{
lean_dec_ref(v___f_2672_);
lean_dec_ref(v___f_2671_);
lean_dec_ref(v_satCls_2668_);
lean_dec_ref(v_accCls_2667_);
lean_dec_ref(v_satCls_2654_);
lean_dec_ref(v_accCls_2653_);
return v_provConf_2665_;
}
else
{
goto v___jp_2676_;
}
}
}
v___jp_2678_:
{
if (v_slotFree_2650_ == 0)
{
if (v_slotFree_2664_ == 0)
{
goto v___jp_2677_;
}
else
{
lean_dec_ref(v___f_2672_);
lean_dec_ref(v___f_2671_);
lean_dec_ref(v_satCls_2668_);
lean_dec_ref(v_accCls_2667_);
lean_dec_ref(v_satCls_2654_);
lean_dec_ref(v_accCls_2653_);
return v_slotFree_2650_;
}
}
else
{
if (v_slotFree_2664_ == 0)
{
lean_dec_ref(v___f_2672_);
lean_dec_ref(v___f_2671_);
lean_dec_ref(v_satCls_2668_);
lean_dec_ref(v_accCls_2667_);
lean_dec_ref(v_satCls_2654_);
lean_dec_ref(v_accCls_2653_);
return v_slotFree_2664_;
}
else
{
goto v___jp_2677_;
}
}
}
v___jp_2679_:
{
if (v_hasChild_2649_ == 0)
{
if (v_hasChild_2663_ == 0)
{
goto v___jp_2678_;
}
else
{
lean_dec_ref(v___f_2672_);
lean_dec_ref(v___f_2671_);
lean_dec_ref(v_satCls_2668_);
lean_dec_ref(v_accCls_2667_);
lean_dec_ref(v_satCls_2654_);
lean_dec_ref(v_accCls_2653_);
return v_hasChild_2649_;
}
}
else
{
if (v_hasChild_2663_ == 0)
{
lean_dec_ref(v___f_2672_);
lean_dec_ref(v___f_2671_);
lean_dec_ref(v_satCls_2668_);
lean_dec_ref(v_accCls_2667_);
lean_dec_ref(v_satCls_2654_);
lean_dec_ref(v_accCls_2653_);
return v_hasChild_2663_;
}
else
{
goto v___jp_2678_;
}
}
}
v___jp_2680_:
{
if (v_reliedB_2648_ == 0)
{
if (v_reliedB_2662_ == 0)
{
goto v___jp_2679_;
}
else
{
lean_dec_ref(v___f_2672_);
lean_dec_ref(v___f_2671_);
lean_dec_ref(v_satCls_2668_);
lean_dec_ref(v_accCls_2667_);
lean_dec_ref(v_satCls_2654_);
lean_dec_ref(v_accCls_2653_);
return v_reliedB_2648_;
}
}
else
{
if (v_reliedB_2662_ == 0)
{
lean_dec_ref(v___f_2672_);
lean_dec_ref(v___f_2671_);
lean_dec_ref(v_satCls_2668_);
lean_dec_ref(v_accCls_2667_);
lean_dec_ref(v_satCls_2654_);
lean_dec_ref(v_accCls_2653_);
return v_reliedB_2662_;
}
else
{
goto v___jp_2679_;
}
}
}
v___jp_2681_:
{
uint8_t v___x_2682_; 
v___x_2682_ = lp_bounded_Bounded_instDecidableEqTRel(v_tRel_2645_, v_tRel_2659_);
if (v___x_2682_ == 0)
{
lean_dec_ref(v___f_2672_);
lean_dec_ref(v___f_2671_);
lean_dec_ref(v_satCls_2668_);
lean_dec_ref(v_accCls_2667_);
lean_dec(v_headStep_2660_);
lean_dec_ref(v_satCls_2654_);
lean_dec_ref(v_accCls_2653_);
lean_dec(v_headStep_2646_);
return v___x_2682_;
}
else
{
lean_object* v___x_2683_; uint8_t v___x_2684_; 
v___x_2683_ = lean_alloc_closure((void*)(lp_bounded_Bounded_instDecidableEqStepSig___boxed), 2, 0);
v___x_2684_ = l_Option_instDecidableEq___redArg(v___x_2683_, v_headStep_2646_, v_headStep_2660_);
if (v___x_2684_ == 0)
{
lean_dec_ref(v___f_2672_);
lean_dec_ref(v___f_2671_);
lean_dec_ref(v_satCls_2668_);
lean_dec_ref(v_accCls_2667_);
lean_dec_ref(v_satCls_2654_);
lean_dec_ref(v_accCls_2653_);
return v___x_2684_;
}
else
{
if (v_remEmpty_2647_ == 0)
{
if (v_remEmpty_2661_ == 0)
{
goto v___jp_2680_;
}
else
{
lean_dec_ref(v___f_2672_);
lean_dec_ref(v___f_2671_);
lean_dec_ref(v_satCls_2668_);
lean_dec_ref(v_accCls_2667_);
lean_dec_ref(v_satCls_2654_);
lean_dec_ref(v_accCls_2653_);
return v_remEmpty_2647_;
}
}
else
{
if (v_remEmpty_2661_ == 0)
{
lean_dec_ref(v___f_2672_);
lean_dec_ref(v___f_2671_);
lean_dec_ref(v_satCls_2668_);
lean_dec_ref(v_accCls_2667_);
lean_dec_ref(v_satCls_2654_);
lean_dec_ref(v_accCls_2653_);
return v_remEmpty_2661_;
}
else
{
goto v___jp_2680_;
}
}
}
}
}
v___jp_2685_:
{
uint8_t v___x_2686_; 
v___x_2686_ = lp_bounded_Bounded_instDecidableEqStCls(v_stCls_2643_, v_stCls_2657_);
if (v___x_2686_ == 0)
{
lean_dec_ref(v___f_2672_);
lean_dec_ref(v___f_2671_);
lean_dec_ref(v_satCls_2668_);
lean_dec_ref(v_accCls_2667_);
lean_dec(v_headStep_2660_);
lean_dec_ref(v_satCls_2654_);
lean_dec_ref(v_accCls_2653_);
lean_dec(v_headStep_2646_);
return v___x_2686_;
}
else
{
if (v_retiredB_2644_ == 0)
{
if (v_retiredB_2658_ == 0)
{
goto v___jp_2681_;
}
else
{
lean_dec_ref(v___f_2672_);
lean_dec_ref(v___f_2671_);
lean_dec_ref(v_satCls_2668_);
lean_dec_ref(v_accCls_2667_);
lean_dec(v_headStep_2660_);
lean_dec_ref(v_satCls_2654_);
lean_dec_ref(v_accCls_2653_);
lean_dec(v_headStep_2646_);
return v_retiredB_2644_;
}
}
else
{
if (v_retiredB_2658_ == 0)
{
lean_dec_ref(v___f_2672_);
lean_dec_ref(v___f_2671_);
lean_dec_ref(v_satCls_2668_);
lean_dec_ref(v_accCls_2667_);
lean_dec(v_headStep_2660_);
lean_dec_ref(v_satCls_2654_);
lean_dec_ref(v_accCls_2653_);
lean_dec(v_headStep_2646_);
return v_retiredB_2658_;
}
else
{
goto v___jp_2681_;
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqSigR_decEq___boxed(lean_object* v_x_2687_, lean_object* v_x_2688_){
_start:
{
uint8_t v_res_2689_; lean_object* v_r_2690_; 
v_res_2689_ = lp_bounded_Bounded_instDecidableEqSigR_decEq(v_x_2687_, v_x_2688_);
v_r_2690_ = lean_box(v_res_2689_);
return v_r_2690_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqSigR(lean_object* v_x_2691_, lean_object* v_x_2692_){
_start:
{
uint8_t v___x_2693_; 
v___x_2693_ = lp_bounded_Bounded_instDecidableEqSigR_decEq(v_x_2691_, v_x_2692_);
return v___x_2693_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqSigR___boxed(lean_object* v_x_2694_, lean_object* v_x_2695_){
_start:
{
uint8_t v_res_2696_; lean_object* v_r_2697_; 
v_res_2696_ = lp_bounded_Bounded_instDecidableEqSigR(v_x_2694_, v_x_2695_);
v_r_2697_ = lean_box(v_res_2696_);
return v_r_2697_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Option_repr___at___00Bounded_instReprSigR_repr_spec__0(lean_object* v_x_2704_, lean_object* v_x_2705_){
_start:
{
if (lean_obj_tag(v_x_2704_) == 0)
{
lean_object* v___x_2706_; 
v___x_2706_ = ((lean_object*)(lp_bounded_Option_repr___at___00Bounded_instReprSigR_repr_spec__0___closed__1));
return v___x_2706_;
}
else
{
lean_object* v_val_2707_; lean_object* v___x_2708_; lean_object* v___x_2709_; lean_object* v___x_2710_; lean_object* v___x_2711_; lean_object* v___x_2712_; 
v_val_2707_ = lean_ctor_get(v_x_2704_, 0);
v___x_2708_ = ((lean_object*)(lp_bounded_Option_repr___at___00Bounded_instReprSigR_repr_spec__0___closed__3));
v___x_2709_ = lean_unsigned_to_nat(1024u);
v___x_2710_ = lp_bounded_Bounded_instReprStepSig_repr(v_val_2707_, v___x_2709_);
v___x_2711_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2711_, 0, v___x_2708_);
lean_ctor_set(v___x_2711_, 1, v___x_2710_);
v___x_2712_ = l_Repr_addAppParen(v___x_2711_, v_x_2705_);
return v___x_2712_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Option_repr___at___00Bounded_instReprSigR_repr_spec__0___boxed(lean_object* v_x_2713_, lean_object* v_x_2714_){
_start:
{
lean_object* v_res_2715_; 
v_res_2715_ = lp_bounded_Option_repr___at___00Bounded_instReprSigR_repr_spec__0(v_x_2713_, v_x_2714_);
lean_dec(v_x_2714_);
lean_dec(v_x_2713_);
return v_res_2715_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Prod_reprTuple___at___00Prod_repr___at___00Bounded_instReprSigR_repr_spec__1_spec__1(lean_object* v_x_2716_, lean_object* v_x_2717_){
_start:
{
lean_object* v_fst_2718_; lean_object* v_snd_2719_; lean_object* v___x_2721_; uint8_t v_isShared_2722_; uint8_t v_isSharedCheck_2731_; 
v_fst_2718_ = lean_ctor_get(v_x_2716_, 0);
v_snd_2719_ = lean_ctor_get(v_x_2716_, 1);
v_isSharedCheck_2731_ = !lean_is_exclusive(v_x_2716_);
if (v_isSharedCheck_2731_ == 0)
{
v___x_2721_ = v_x_2716_;
v_isShared_2722_ = v_isSharedCheck_2731_;
goto v_resetjp_2720_;
}
else
{
lean_inc(v_snd_2719_);
lean_inc(v_fst_2718_);
lean_dec(v_x_2716_);
v___x_2721_ = lean_box(0);
v_isShared_2722_ = v_isSharedCheck_2731_;
goto v_resetjp_2720_;
}
v_resetjp_2720_:
{
uint8_t v___x_2723_; lean_object* v___x_2724_; lean_object* v___x_2726_; 
v___x_2723_ = lean_unbox(v_fst_2718_);
lean_dec(v_fst_2718_);
v___x_2724_ = l_Bool_repr___redArg(v___x_2723_);
if (v_isShared_2722_ == 0)
{
lean_ctor_set_tag(v___x_2721_, 1);
lean_ctor_set(v___x_2721_, 1, v_x_2717_);
lean_ctor_set(v___x_2721_, 0, v___x_2724_);
v___x_2726_ = v___x_2721_;
goto v_reusejp_2725_;
}
else
{
lean_object* v_reuseFailAlloc_2730_; 
v_reuseFailAlloc_2730_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_2730_, 0, v___x_2724_);
lean_ctor_set(v_reuseFailAlloc_2730_, 1, v_x_2717_);
v___x_2726_ = v_reuseFailAlloc_2730_;
goto v_reusejp_2725_;
}
v_reusejp_2725_:
{
uint8_t v___x_2727_; lean_object* v___x_2728_; lean_object* v___x_2729_; 
v___x_2727_ = lean_unbox(v_snd_2719_);
lean_dec(v_snd_2719_);
v___x_2728_ = l_Bool_repr___redArg(v___x_2727_);
v___x_2729_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2729_, 0, v___x_2728_);
lean_ctor_set(v___x_2729_, 1, v___x_2726_);
return v___x_2729_;
}
}
}
}
static lean_object* _init_lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg___closed__5(void){
_start:
{
lean_object* v___x_2740_; lean_object* v___x_2741_; 
v___x_2740_ = ((lean_object*)(lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg___closed__0));
v___x_2741_ = lean_string_length(v___x_2740_);
return v___x_2741_;
}
}
static lean_object* _init_lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg___closed__6(void){
_start:
{
lean_object* v___x_2742_; lean_object* v___x_2743_; 
v___x_2742_ = lean_obj_once(&lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg___closed__5, &lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg___closed__5_once, _init_lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg___closed__5);
v___x_2743_ = lean_nat_to_int(v___x_2742_);
return v___x_2743_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg(lean_object* v_x_2748_){
_start:
{
lean_object* v_fst_2749_; lean_object* v_snd_2750_; lean_object* v___x_2752_; uint8_t v_isShared_2753_; uint8_t v_isSharedCheck_2772_; 
v_fst_2749_ = lean_ctor_get(v_x_2748_, 0);
v_snd_2750_ = lean_ctor_get(v_x_2748_, 1);
v_isSharedCheck_2772_ = !lean_is_exclusive(v_x_2748_);
if (v_isSharedCheck_2772_ == 0)
{
v___x_2752_ = v_x_2748_;
v_isShared_2753_ = v_isSharedCheck_2772_;
goto v_resetjp_2751_;
}
else
{
lean_inc(v_snd_2750_);
lean_inc(v_fst_2749_);
lean_dec(v_x_2748_);
v___x_2752_ = lean_box(0);
v_isShared_2753_ = v_isSharedCheck_2772_;
goto v_resetjp_2751_;
}
v_resetjp_2751_:
{
uint8_t v___x_2754_; lean_object* v___x_2755_; lean_object* v___x_2756_; lean_object* v___x_2758_; 
v___x_2754_ = lean_unbox(v_fst_2749_);
lean_dec(v_fst_2749_);
v___x_2755_ = l_Bool_repr___redArg(v___x_2754_);
v___x_2756_ = lean_box(0);
if (v_isShared_2753_ == 0)
{
lean_ctor_set_tag(v___x_2752_, 1);
lean_ctor_set(v___x_2752_, 1, v___x_2756_);
lean_ctor_set(v___x_2752_, 0, v___x_2755_);
v___x_2758_ = v___x_2752_;
goto v_reusejp_2757_;
}
else
{
lean_object* v_reuseFailAlloc_2771_; 
v_reuseFailAlloc_2771_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_2771_, 0, v___x_2755_);
lean_ctor_set(v_reuseFailAlloc_2771_, 1, v___x_2756_);
v___x_2758_ = v_reuseFailAlloc_2771_;
goto v_reusejp_2757_;
}
v_reusejp_2757_:
{
lean_object* v___x_2759_; lean_object* v___x_2760_; lean_object* v___x_2761_; lean_object* v___x_2762_; lean_object* v___x_2763_; lean_object* v___x_2764_; lean_object* v___x_2765_; lean_object* v___x_2766_; lean_object* v___x_2767_; lean_object* v___x_2768_; uint8_t v___x_2769_; lean_object* v___x_2770_; 
v___x_2759_ = lp_bounded_Prod_reprTuple___at___00Prod_repr___at___00Bounded_instReprSigR_repr_spec__1_spec__1(v_snd_2750_, v___x_2758_);
v___x_2760_ = l_List_reverse___redArg(v___x_2759_);
v___x_2761_ = ((lean_object*)(lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg___closed__3));
v___x_2762_ = l_Std_Format_joinSep___at___00Lean_Syntax_formatStxAux_spec__2(v___x_2760_, v___x_2761_);
v___x_2763_ = lean_obj_once(&lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg___closed__6, &lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg___closed__6_once, _init_lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg___closed__6);
v___x_2764_ = ((lean_object*)(lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg___closed__7));
v___x_2765_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2765_, 0, v___x_2764_);
lean_ctor_set(v___x_2765_, 1, v___x_2762_);
v___x_2766_ = ((lean_object*)(lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg___closed__8));
v___x_2767_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2767_, 0, v___x_2765_);
lean_ctor_set(v___x_2767_, 1, v___x_2766_);
v___x_2768_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_2768_, 0, v___x_2763_);
lean_ctor_set(v___x_2768_, 1, v___x_2767_);
v___x_2769_ = 0;
v___x_2770_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_2770_, 0, v___x_2768_);
lean_ctor_set_uint8(v___x_2770_, sizeof(void*)*1, v___x_2769_);
return v___x_2770_;
}
}
}
}
static lean_object* _init_lp_bounded_Bounded_instReprSigR_repr___redArg___closed__7(void){
_start:
{
lean_object* v___x_2786_; lean_object* v___x_2787_; 
v___x_2786_ = lean_unsigned_to_nat(8u);
v___x_2787_ = lean_nat_to_int(v___x_2786_);
return v___x_2787_;
}
}
static lean_object* _init_lp_bounded_Bounded_instReprSigR_repr___redArg___closed__10(void){
_start:
{
lean_object* v___x_2791_; lean_object* v___x_2792_; 
v___x_2791_ = lean_unsigned_to_nat(11u);
v___x_2792_ = lean_nat_to_int(v___x_2791_);
return v___x_2792_;
}
}
static lean_object* _init_lp_bounded_Bounded_instReprSigR_repr___redArg___closed__13(void){
_start:
{
lean_object* v___x_2796_; lean_object* v___x_2797_; 
v___x_2796_ = lean_unsigned_to_nat(9u);
v___x_2797_ = lean_nat_to_int(v___x_2796_);
return v___x_2797_;
}
}
static lean_object* _init_lp_bounded_Bounded_instReprSigR_repr___redArg___closed__16(void){
_start:
{
lean_object* v___x_2801_; lean_object* v___x_2802_; 
v___x_2801_ = lean_unsigned_to_nat(12u);
v___x_2802_ = lean_nat_to_int(v___x_2801_);
return v___x_2802_;
}
}
static lean_object* _init_lp_bounded_Bounded_instReprSigR_repr___redArg___closed__33(void){
_start:
{
lean_object* v___x_2827_; lean_object* v___x_2828_; 
v___x_2827_ = lean_unsigned_to_nat(14u);
v___x_2828_ = lean_nat_to_int(v___x_2827_);
return v___x_2828_;
}
}
static lean_object* _init_lp_bounded_Bounded_instReprSigR_repr___redArg___closed__36(void){
_start:
{
lean_object* v___x_2832_; lean_object* v___x_2833_; 
v___x_2832_ = lean_unsigned_to_nat(10u);
v___x_2833_ = lean_nat_to_int(v___x_2832_);
return v___x_2833_;
}
}
static lean_object* _init_lp_bounded_Bounded_instReprSigR_repr___redArg___closed__40(void){
_start:
{
lean_object* v___x_2838_; lean_object* v___x_2839_; 
v___x_2838_ = ((lean_object*)(lp_bounded_Bounded_instReprSigR_repr___redArg___closed__0));
v___x_2839_ = lean_string_length(v___x_2838_);
return v___x_2839_;
}
}
static lean_object* _init_lp_bounded_Bounded_instReprSigR_repr___redArg___closed__41(void){
_start:
{
lean_object* v___x_2840_; lean_object* v___x_2841_; 
v___x_2840_ = lean_obj_once(&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__40, &lp_bounded_Bounded_instReprSigR_repr___redArg___closed__40_once, _init_lp_bounded_Bounded_instReprSigR_repr___redArg___closed__40);
v___x_2841_ = lean_nat_to_int(v___x_2840_);
return v___x_2841_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprSigR_repr___redArg(lean_object* v_x_2846_){
_start:
{
uint8_t v_rule_2847_; uint8_t v_present_2848_; uint8_t v_stCls_2849_; uint8_t v_retiredB_2850_; uint8_t v_tRel_2851_; lean_object* v_headStep_2852_; uint8_t v_remEmpty_2853_; uint8_t v_reliedB_2854_; uint8_t v_hasChild_2855_; uint8_t v_slotFree_2856_; uint8_t v_provConf_2857_; uint8_t v_parentLive_2858_; lean_object* v_accCls_2859_; lean_object* v_satCls_2860_; lean_object* v___x_2861_; lean_object* v___x_2862_; lean_object* v___x_2863_; lean_object* v___x_2864_; lean_object* v___x_2865_; lean_object* v___x_2866_; uint8_t v___x_2867_; lean_object* v___x_2868_; lean_object* v___x_2869_; lean_object* v___x_2870_; lean_object* v___x_2871_; lean_object* v___x_2872_; lean_object* v___x_2873_; lean_object* v___x_2874_; lean_object* v___x_2875_; lean_object* v___x_2876_; lean_object* v___x_2877_; lean_object* v___x_2878_; lean_object* v___x_2879_; lean_object* v___x_2880_; lean_object* v___x_2881_; lean_object* v___x_2882_; lean_object* v___x_2883_; lean_object* v___x_2884_; lean_object* v___x_2885_; lean_object* v___x_2886_; lean_object* v___x_2887_; lean_object* v___x_2888_; lean_object* v___x_2889_; lean_object* v___x_2890_; lean_object* v___x_2891_; lean_object* v___x_2892_; lean_object* v___x_2893_; lean_object* v___x_2894_; lean_object* v___x_2895_; lean_object* v___x_2896_; lean_object* v___x_2897_; lean_object* v___x_2898_; lean_object* v___x_2899_; lean_object* v___x_2900_; lean_object* v___x_2901_; lean_object* v___x_2902_; lean_object* v___x_2903_; lean_object* v___x_2904_; lean_object* v___x_2905_; lean_object* v___x_2906_; lean_object* v___x_2907_; lean_object* v___x_2908_; lean_object* v___x_2909_; lean_object* v___x_2910_; lean_object* v___x_2911_; lean_object* v___x_2912_; lean_object* v___x_2913_; lean_object* v___x_2914_; lean_object* v___x_2915_; lean_object* v___x_2916_; lean_object* v___x_2917_; lean_object* v___x_2918_; lean_object* v___x_2919_; lean_object* v___x_2920_; lean_object* v___x_2921_; lean_object* v___x_2922_; lean_object* v___x_2923_; lean_object* v___x_2924_; lean_object* v___x_2925_; lean_object* v___x_2926_; lean_object* v___x_2927_; lean_object* v___x_2928_; lean_object* v___x_2929_; lean_object* v___x_2930_; lean_object* v___x_2931_; lean_object* v___x_2932_; lean_object* v___x_2933_; lean_object* v___x_2934_; lean_object* v___x_2935_; lean_object* v___x_2936_; lean_object* v___x_2937_; lean_object* v___x_2938_; lean_object* v___x_2939_; lean_object* v___x_2940_; lean_object* v___x_2941_; lean_object* v___x_2942_; lean_object* v___x_2943_; lean_object* v___x_2944_; lean_object* v___x_2945_; lean_object* v___x_2946_; lean_object* v___x_2947_; lean_object* v___x_2948_; lean_object* v___x_2949_; lean_object* v___x_2950_; lean_object* v___x_2951_; lean_object* v___x_2952_; lean_object* v___x_2953_; lean_object* v___x_2954_; lean_object* v___x_2955_; lean_object* v___x_2956_; lean_object* v___x_2957_; lean_object* v___x_2958_; lean_object* v___x_2959_; lean_object* v___x_2960_; lean_object* v___x_2961_; lean_object* v___x_2962_; lean_object* v___x_2963_; lean_object* v___x_2964_; lean_object* v___x_2965_; lean_object* v___x_2966_; lean_object* v___x_2967_; lean_object* v___x_2968_; lean_object* v___x_2969_; lean_object* v___x_2970_; lean_object* v___x_2971_; lean_object* v___x_2972_; lean_object* v___x_2973_; lean_object* v___x_2974_; lean_object* v___x_2975_; lean_object* v___x_2976_; lean_object* v___x_2977_; lean_object* v___x_2978_; lean_object* v___x_2979_; lean_object* v___x_2980_; lean_object* v___x_2981_; lean_object* v___x_2982_; lean_object* v___x_2983_; lean_object* v___x_2984_; lean_object* v___x_2985_; lean_object* v___x_2986_; lean_object* v___x_2987_; lean_object* v___x_2988_; lean_object* v___x_2989_; lean_object* v___x_2990_; lean_object* v___x_2991_; lean_object* v___x_2992_; lean_object* v___x_2993_; lean_object* v___x_2994_; lean_object* v___x_2995_; lean_object* v___x_2996_; lean_object* v___x_2997_; lean_object* v___x_2998_; lean_object* v___x_2999_; lean_object* v___x_3000_; 
v_rule_2847_ = lean_ctor_get_uint8(v_x_2846_, sizeof(void*)*3);
v_present_2848_ = lean_ctor_get_uint8(v_x_2846_, sizeof(void*)*3 + 1);
v_stCls_2849_ = lean_ctor_get_uint8(v_x_2846_, sizeof(void*)*3 + 2);
v_retiredB_2850_ = lean_ctor_get_uint8(v_x_2846_, sizeof(void*)*3 + 3);
v_tRel_2851_ = lean_ctor_get_uint8(v_x_2846_, sizeof(void*)*3 + 4);
v_headStep_2852_ = lean_ctor_get(v_x_2846_, 0);
lean_inc(v_headStep_2852_);
v_remEmpty_2853_ = lean_ctor_get_uint8(v_x_2846_, sizeof(void*)*3 + 5);
v_reliedB_2854_ = lean_ctor_get_uint8(v_x_2846_, sizeof(void*)*3 + 6);
v_hasChild_2855_ = lean_ctor_get_uint8(v_x_2846_, sizeof(void*)*3 + 7);
v_slotFree_2856_ = lean_ctor_get_uint8(v_x_2846_, sizeof(void*)*3 + 8);
v_provConf_2857_ = lean_ctor_get_uint8(v_x_2846_, sizeof(void*)*3 + 9);
v_parentLive_2858_ = lean_ctor_get_uint8(v_x_2846_, sizeof(void*)*3 + 10);
v_accCls_2859_ = lean_ctor_get(v_x_2846_, 1);
lean_inc_ref(v_accCls_2859_);
v_satCls_2860_ = lean_ctor_get(v_x_2846_, 2);
lean_inc_ref(v_satCls_2860_);
lean_dec_ref(v_x_2846_);
v___x_2861_ = ((lean_object*)(lp_bounded_Bounded_instReprSigR_repr___redArg___closed__5));
v___x_2862_ = ((lean_object*)(lp_bounded_Bounded_instReprSigR_repr___redArg___closed__6));
v___x_2863_ = lean_obj_once(&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__7, &lp_bounded_Bounded_instReprSigR_repr___redArg___closed__7_once, _init_lp_bounded_Bounded_instReprSigR_repr___redArg___closed__7);
v___x_2864_ = lean_unsigned_to_nat(0u);
v___x_2865_ = lp_bounded_Bounded_instReprRule_repr(v_rule_2847_, v___x_2864_);
v___x_2866_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_2866_, 0, v___x_2863_);
lean_ctor_set(v___x_2866_, 1, v___x_2865_);
v___x_2867_ = 0;
v___x_2868_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_2868_, 0, v___x_2866_);
lean_ctor_set_uint8(v___x_2868_, sizeof(void*)*1, v___x_2867_);
v___x_2869_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2869_, 0, v___x_2862_);
lean_ctor_set(v___x_2869_, 1, v___x_2868_);
v___x_2870_ = ((lean_object*)(lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg___closed__2));
v___x_2871_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2871_, 0, v___x_2869_);
lean_ctor_set(v___x_2871_, 1, v___x_2870_);
v___x_2872_ = lean_box(1);
v___x_2873_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2873_, 0, v___x_2871_);
lean_ctor_set(v___x_2873_, 1, v___x_2872_);
v___x_2874_ = ((lean_object*)(lp_bounded_Bounded_instReprSigR_repr___redArg___closed__9));
v___x_2875_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2875_, 0, v___x_2873_);
lean_ctor_set(v___x_2875_, 1, v___x_2874_);
v___x_2876_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2876_, 0, v___x_2875_);
lean_ctor_set(v___x_2876_, 1, v___x_2861_);
v___x_2877_ = lean_obj_once(&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__10, &lp_bounded_Bounded_instReprSigR_repr___redArg___closed__10_once, _init_lp_bounded_Bounded_instReprSigR_repr___redArg___closed__10);
v___x_2878_ = l_Bool_repr___redArg(v_present_2848_);
v___x_2879_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_2879_, 0, v___x_2877_);
lean_ctor_set(v___x_2879_, 1, v___x_2878_);
v___x_2880_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_2880_, 0, v___x_2879_);
lean_ctor_set_uint8(v___x_2880_, sizeof(void*)*1, v___x_2867_);
v___x_2881_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2881_, 0, v___x_2876_);
lean_ctor_set(v___x_2881_, 1, v___x_2880_);
v___x_2882_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2882_, 0, v___x_2881_);
lean_ctor_set(v___x_2882_, 1, v___x_2870_);
v___x_2883_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2883_, 0, v___x_2882_);
lean_ctor_set(v___x_2883_, 1, v___x_2872_);
v___x_2884_ = ((lean_object*)(lp_bounded_Bounded_instReprSigR_repr___redArg___closed__12));
v___x_2885_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2885_, 0, v___x_2883_);
lean_ctor_set(v___x_2885_, 1, v___x_2884_);
v___x_2886_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2886_, 0, v___x_2885_);
lean_ctor_set(v___x_2886_, 1, v___x_2861_);
v___x_2887_ = lean_obj_once(&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__13, &lp_bounded_Bounded_instReprSigR_repr___redArg___closed__13_once, _init_lp_bounded_Bounded_instReprSigR_repr___redArg___closed__13);
v___x_2888_ = lp_bounded_Bounded_instReprStCls_repr(v_stCls_2849_, v___x_2864_);
v___x_2889_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_2889_, 0, v___x_2887_);
lean_ctor_set(v___x_2889_, 1, v___x_2888_);
v___x_2890_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_2890_, 0, v___x_2889_);
lean_ctor_set_uint8(v___x_2890_, sizeof(void*)*1, v___x_2867_);
v___x_2891_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2891_, 0, v___x_2886_);
lean_ctor_set(v___x_2891_, 1, v___x_2890_);
v___x_2892_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2892_, 0, v___x_2891_);
lean_ctor_set(v___x_2892_, 1, v___x_2870_);
v___x_2893_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2893_, 0, v___x_2892_);
lean_ctor_set(v___x_2893_, 1, v___x_2872_);
v___x_2894_ = ((lean_object*)(lp_bounded_Bounded_instReprSigR_repr___redArg___closed__15));
v___x_2895_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2895_, 0, v___x_2893_);
lean_ctor_set(v___x_2895_, 1, v___x_2894_);
v___x_2896_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2896_, 0, v___x_2895_);
lean_ctor_set(v___x_2896_, 1, v___x_2861_);
v___x_2897_ = lean_obj_once(&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__16, &lp_bounded_Bounded_instReprSigR_repr___redArg___closed__16_once, _init_lp_bounded_Bounded_instReprSigR_repr___redArg___closed__16);
v___x_2898_ = l_Bool_repr___redArg(v_retiredB_2850_);
v___x_2899_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_2899_, 0, v___x_2897_);
lean_ctor_set(v___x_2899_, 1, v___x_2898_);
v___x_2900_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_2900_, 0, v___x_2899_);
lean_ctor_set_uint8(v___x_2900_, sizeof(void*)*1, v___x_2867_);
v___x_2901_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2901_, 0, v___x_2896_);
lean_ctor_set(v___x_2901_, 1, v___x_2900_);
v___x_2902_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2902_, 0, v___x_2901_);
lean_ctor_set(v___x_2902_, 1, v___x_2870_);
v___x_2903_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2903_, 0, v___x_2902_);
lean_ctor_set(v___x_2903_, 1, v___x_2872_);
v___x_2904_ = ((lean_object*)(lp_bounded_Bounded_instReprSigR_repr___redArg___closed__18));
v___x_2905_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2905_, 0, v___x_2903_);
lean_ctor_set(v___x_2905_, 1, v___x_2904_);
v___x_2906_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2906_, 0, v___x_2905_);
lean_ctor_set(v___x_2906_, 1, v___x_2861_);
v___x_2907_ = lp_bounded_Bounded_instReprTRel_repr(v_tRel_2851_, v___x_2864_);
v___x_2908_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_2908_, 0, v___x_2863_);
lean_ctor_set(v___x_2908_, 1, v___x_2907_);
v___x_2909_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_2909_, 0, v___x_2908_);
lean_ctor_set_uint8(v___x_2909_, sizeof(void*)*1, v___x_2867_);
v___x_2910_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2910_, 0, v___x_2906_);
lean_ctor_set(v___x_2910_, 1, v___x_2909_);
v___x_2911_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2911_, 0, v___x_2910_);
lean_ctor_set(v___x_2911_, 1, v___x_2870_);
v___x_2912_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2912_, 0, v___x_2911_);
lean_ctor_set(v___x_2912_, 1, v___x_2872_);
v___x_2913_ = ((lean_object*)(lp_bounded_Bounded_instReprSigR_repr___redArg___closed__20));
v___x_2914_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2914_, 0, v___x_2912_);
lean_ctor_set(v___x_2914_, 1, v___x_2913_);
v___x_2915_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2915_, 0, v___x_2914_);
lean_ctor_set(v___x_2915_, 1, v___x_2861_);
v___x_2916_ = lp_bounded_Option_repr___at___00Bounded_instReprSigR_repr_spec__0(v_headStep_2852_, v___x_2864_);
lean_dec(v_headStep_2852_);
v___x_2917_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_2917_, 0, v___x_2897_);
lean_ctor_set(v___x_2917_, 1, v___x_2916_);
v___x_2918_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_2918_, 0, v___x_2917_);
lean_ctor_set_uint8(v___x_2918_, sizeof(void*)*1, v___x_2867_);
v___x_2919_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2919_, 0, v___x_2915_);
lean_ctor_set(v___x_2919_, 1, v___x_2918_);
v___x_2920_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2920_, 0, v___x_2919_);
lean_ctor_set(v___x_2920_, 1, v___x_2870_);
v___x_2921_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2921_, 0, v___x_2920_);
lean_ctor_set(v___x_2921_, 1, v___x_2872_);
v___x_2922_ = ((lean_object*)(lp_bounded_Bounded_instReprSigR_repr___redArg___closed__22));
v___x_2923_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2923_, 0, v___x_2921_);
lean_ctor_set(v___x_2923_, 1, v___x_2922_);
v___x_2924_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2924_, 0, v___x_2923_);
lean_ctor_set(v___x_2924_, 1, v___x_2861_);
v___x_2925_ = l_Bool_repr___redArg(v_remEmpty_2853_);
v___x_2926_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_2926_, 0, v___x_2897_);
lean_ctor_set(v___x_2926_, 1, v___x_2925_);
v___x_2927_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_2927_, 0, v___x_2926_);
lean_ctor_set_uint8(v___x_2927_, sizeof(void*)*1, v___x_2867_);
v___x_2928_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2928_, 0, v___x_2924_);
lean_ctor_set(v___x_2928_, 1, v___x_2927_);
v___x_2929_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2929_, 0, v___x_2928_);
lean_ctor_set(v___x_2929_, 1, v___x_2870_);
v___x_2930_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2930_, 0, v___x_2929_);
lean_ctor_set(v___x_2930_, 1, v___x_2872_);
v___x_2931_ = ((lean_object*)(lp_bounded_Bounded_instReprSigR_repr___redArg___closed__24));
v___x_2932_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2932_, 0, v___x_2930_);
lean_ctor_set(v___x_2932_, 1, v___x_2931_);
v___x_2933_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2933_, 0, v___x_2932_);
lean_ctor_set(v___x_2933_, 1, v___x_2861_);
v___x_2934_ = l_Bool_repr___redArg(v_reliedB_2854_);
v___x_2935_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_2935_, 0, v___x_2877_);
lean_ctor_set(v___x_2935_, 1, v___x_2934_);
v___x_2936_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_2936_, 0, v___x_2935_);
lean_ctor_set_uint8(v___x_2936_, sizeof(void*)*1, v___x_2867_);
v___x_2937_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2937_, 0, v___x_2933_);
lean_ctor_set(v___x_2937_, 1, v___x_2936_);
v___x_2938_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2938_, 0, v___x_2937_);
lean_ctor_set(v___x_2938_, 1, v___x_2870_);
v___x_2939_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2939_, 0, v___x_2938_);
lean_ctor_set(v___x_2939_, 1, v___x_2872_);
v___x_2940_ = ((lean_object*)(lp_bounded_Bounded_instReprSigR_repr___redArg___closed__26));
v___x_2941_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2941_, 0, v___x_2939_);
lean_ctor_set(v___x_2941_, 1, v___x_2940_);
v___x_2942_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2942_, 0, v___x_2941_);
lean_ctor_set(v___x_2942_, 1, v___x_2861_);
v___x_2943_ = l_Bool_repr___redArg(v_hasChild_2855_);
v___x_2944_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_2944_, 0, v___x_2897_);
lean_ctor_set(v___x_2944_, 1, v___x_2943_);
v___x_2945_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_2945_, 0, v___x_2944_);
lean_ctor_set_uint8(v___x_2945_, sizeof(void*)*1, v___x_2867_);
v___x_2946_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2946_, 0, v___x_2942_);
lean_ctor_set(v___x_2946_, 1, v___x_2945_);
v___x_2947_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2947_, 0, v___x_2946_);
lean_ctor_set(v___x_2947_, 1, v___x_2870_);
v___x_2948_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2948_, 0, v___x_2947_);
lean_ctor_set(v___x_2948_, 1, v___x_2872_);
v___x_2949_ = ((lean_object*)(lp_bounded_Bounded_instReprSigR_repr___redArg___closed__28));
v___x_2950_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2950_, 0, v___x_2948_);
lean_ctor_set(v___x_2950_, 1, v___x_2949_);
v___x_2951_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2951_, 0, v___x_2950_);
lean_ctor_set(v___x_2951_, 1, v___x_2861_);
v___x_2952_ = l_Bool_repr___redArg(v_slotFree_2856_);
v___x_2953_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_2953_, 0, v___x_2897_);
lean_ctor_set(v___x_2953_, 1, v___x_2952_);
v___x_2954_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_2954_, 0, v___x_2953_);
lean_ctor_set_uint8(v___x_2954_, sizeof(void*)*1, v___x_2867_);
v___x_2955_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2955_, 0, v___x_2951_);
lean_ctor_set(v___x_2955_, 1, v___x_2954_);
v___x_2956_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2956_, 0, v___x_2955_);
lean_ctor_set(v___x_2956_, 1, v___x_2870_);
v___x_2957_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2957_, 0, v___x_2956_);
lean_ctor_set(v___x_2957_, 1, v___x_2872_);
v___x_2958_ = ((lean_object*)(lp_bounded_Bounded_instReprSigR_repr___redArg___closed__30));
v___x_2959_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2959_, 0, v___x_2957_);
lean_ctor_set(v___x_2959_, 1, v___x_2958_);
v___x_2960_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2960_, 0, v___x_2959_);
lean_ctor_set(v___x_2960_, 1, v___x_2861_);
v___x_2961_ = l_Bool_repr___redArg(v_provConf_2857_);
v___x_2962_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_2962_, 0, v___x_2897_);
lean_ctor_set(v___x_2962_, 1, v___x_2961_);
v___x_2963_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_2963_, 0, v___x_2962_);
lean_ctor_set_uint8(v___x_2963_, sizeof(void*)*1, v___x_2867_);
v___x_2964_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2964_, 0, v___x_2960_);
lean_ctor_set(v___x_2964_, 1, v___x_2963_);
v___x_2965_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2965_, 0, v___x_2964_);
lean_ctor_set(v___x_2965_, 1, v___x_2870_);
v___x_2966_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2966_, 0, v___x_2965_);
lean_ctor_set(v___x_2966_, 1, v___x_2872_);
v___x_2967_ = ((lean_object*)(lp_bounded_Bounded_instReprSigR_repr___redArg___closed__32));
v___x_2968_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2968_, 0, v___x_2966_);
lean_ctor_set(v___x_2968_, 1, v___x_2967_);
v___x_2969_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2969_, 0, v___x_2968_);
lean_ctor_set(v___x_2969_, 1, v___x_2861_);
v___x_2970_ = lean_obj_once(&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__33, &lp_bounded_Bounded_instReprSigR_repr___redArg___closed__33_once, _init_lp_bounded_Bounded_instReprSigR_repr___redArg___closed__33);
v___x_2971_ = l_Bool_repr___redArg(v_parentLive_2858_);
v___x_2972_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_2972_, 0, v___x_2970_);
lean_ctor_set(v___x_2972_, 1, v___x_2971_);
v___x_2973_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_2973_, 0, v___x_2972_);
lean_ctor_set_uint8(v___x_2973_, sizeof(void*)*1, v___x_2867_);
v___x_2974_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2974_, 0, v___x_2969_);
lean_ctor_set(v___x_2974_, 1, v___x_2973_);
v___x_2975_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2975_, 0, v___x_2974_);
lean_ctor_set(v___x_2975_, 1, v___x_2870_);
v___x_2976_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2976_, 0, v___x_2975_);
lean_ctor_set(v___x_2976_, 1, v___x_2872_);
v___x_2977_ = ((lean_object*)(lp_bounded_Bounded_instReprSigR_repr___redArg___closed__35));
v___x_2978_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2978_, 0, v___x_2976_);
lean_ctor_set(v___x_2978_, 1, v___x_2977_);
v___x_2979_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2979_, 0, v___x_2978_);
lean_ctor_set(v___x_2979_, 1, v___x_2861_);
v___x_2980_ = lean_obj_once(&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__36, &lp_bounded_Bounded_instReprSigR_repr___redArg___closed__36_once, _init_lp_bounded_Bounded_instReprSigR_repr___redArg___closed__36);
v___x_2981_ = lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg(v_accCls_2859_);
v___x_2982_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_2982_, 0, v___x_2980_);
lean_ctor_set(v___x_2982_, 1, v___x_2981_);
v___x_2983_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_2983_, 0, v___x_2982_);
lean_ctor_set_uint8(v___x_2983_, sizeof(void*)*1, v___x_2867_);
v___x_2984_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2984_, 0, v___x_2979_);
lean_ctor_set(v___x_2984_, 1, v___x_2983_);
v___x_2985_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2985_, 0, v___x_2984_);
lean_ctor_set(v___x_2985_, 1, v___x_2870_);
v___x_2986_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2986_, 0, v___x_2985_);
lean_ctor_set(v___x_2986_, 1, v___x_2872_);
v___x_2987_ = ((lean_object*)(lp_bounded_Bounded_instReprSigR_repr___redArg___closed__38));
v___x_2988_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2988_, 0, v___x_2986_);
lean_ctor_set(v___x_2988_, 1, v___x_2987_);
v___x_2989_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2989_, 0, v___x_2988_);
lean_ctor_set(v___x_2989_, 1, v___x_2861_);
v___x_2990_ = lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg(v_satCls_2860_);
v___x_2991_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_2991_, 0, v___x_2980_);
lean_ctor_set(v___x_2991_, 1, v___x_2990_);
v___x_2992_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_2992_, 0, v___x_2991_);
lean_ctor_set_uint8(v___x_2992_, sizeof(void*)*1, v___x_2867_);
v___x_2993_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2993_, 0, v___x_2989_);
lean_ctor_set(v___x_2993_, 1, v___x_2992_);
v___x_2994_ = lean_obj_once(&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__41, &lp_bounded_Bounded_instReprSigR_repr___redArg___closed__41_once, _init_lp_bounded_Bounded_instReprSigR_repr___redArg___closed__41);
v___x_2995_ = ((lean_object*)(lp_bounded_Bounded_instReprSigR_repr___redArg___closed__42));
v___x_2996_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2996_, 0, v___x_2995_);
lean_ctor_set(v___x_2996_, 1, v___x_2993_);
v___x_2997_ = ((lean_object*)(lp_bounded_Bounded_instReprSigR_repr___redArg___closed__43));
v___x_2998_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_2998_, 0, v___x_2996_);
lean_ctor_set(v___x_2998_, 1, v___x_2997_);
v___x_2999_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_2999_, 0, v___x_2994_);
lean_ctor_set(v___x_2999_, 1, v___x_2998_);
v___x_3000_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_3000_, 0, v___x_2999_);
lean_ctor_set_uint8(v___x_3000_, sizeof(void*)*1, v___x_2867_);
return v___x_3000_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprSigR_repr(lean_object* v_x_3001_, lean_object* v_prec_3002_){
_start:
{
lean_object* v___x_3003_; 
v___x_3003_ = lp_bounded_Bounded_instReprSigR_repr___redArg(v_x_3001_);
return v___x_3003_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprSigR_repr___boxed(lean_object* v_x_3004_, lean_object* v_prec_3005_){
_start:
{
lean_object* v_res_3006_; 
v_res_3006_ = lp_bounded_Bounded_instReprSigR_repr(v_x_3004_, v_prec_3005_);
lean_dec(v_prec_3005_);
return v_res_3006_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1(lean_object* v_x_3007_, lean_object* v_x_3008_){
_start:
{
lean_object* v___x_3009_; 
v___x_3009_ = lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg(v_x_3007_);
return v___x_3009_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___boxed(lean_object* v_x_3010_, lean_object* v_x_3011_){
_start:
{
lean_object* v_res_3012_; 
v_res_3012_ = lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1(v_x_3010_, v_x_3011_);
lean_dec(v_x_3011_);
return v_res_3012_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_remOf(lean_object* v_x_3015_){
_start:
{
if (lean_obj_tag(v_x_3015_) == 0)
{
lean_object* v___x_3016_; 
v___x_3016_ = lean_box(0);
return v___x_3016_;
}
else
{
lean_object* v_val_3017_; lean_object* v___x_3019_; uint8_t v_isShared_3020_; uint8_t v_isSharedCheck_3027_; 
v_val_3017_ = lean_ctor_get(v_x_3015_, 0);
v_isSharedCheck_3027_ = !lean_is_exclusive(v_x_3015_);
if (v_isSharedCheck_3027_ == 0)
{
v___x_3019_ = v_x_3015_;
v_isShared_3020_ = v_isSharedCheck_3027_;
goto v_resetjp_3018_;
}
else
{
lean_inc(v_val_3017_);
lean_dec(v_x_3015_);
v___x_3019_ = lean_box(0);
v_isShared_3020_ = v_isSharedCheck_3027_;
goto v_resetjp_3018_;
}
v_resetjp_3018_:
{
lean_object* v_st_3021_; 
v_st_3021_ = lean_ctor_get(v_val_3017_, 3);
lean_inc_ref(v_st_3021_);
lean_dec(v_val_3017_);
if (lean_obj_tag(v_st_3021_) == 1)
{
lean_object* v_remaining_3022_; lean_object* v___x_3024_; 
v_remaining_3022_ = lean_ctor_get(v_st_3021_, 0);
lean_inc(v_remaining_3022_);
lean_dec_ref_known(v_st_3021_, 3);
if (v_isShared_3020_ == 0)
{
lean_ctor_set(v___x_3019_, 0, v_remaining_3022_);
v___x_3024_ = v___x_3019_;
goto v_reusejp_3023_;
}
else
{
lean_object* v_reuseFailAlloc_3025_; 
v_reuseFailAlloc_3025_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_3025_, 0, v_remaining_3022_);
v___x_3024_ = v_reuseFailAlloc_3025_;
goto v_reusejp_3023_;
}
v_reusejp_3023_:
{
return v___x_3024_;
}
}
else
{
lean_object* v___x_3026_; 
lean_dec_ref(v_st_3021_);
lean_del_object(v___x_3019_);
v___x_3026_ = lean_box(0);
return v___x_3026_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_accOf(lean_object* v_x_3028_){
_start:
{
if (lean_obj_tag(v_x_3028_) == 0)
{
lean_object* v___x_3029_; 
v___x_3029_ = lean_box(0);
return v___x_3029_;
}
else
{
lean_object* v_val_3030_; lean_object* v___x_3032_; uint8_t v_isShared_3033_; uint8_t v_isSharedCheck_3044_; 
v_val_3030_ = lean_ctor_get(v_x_3028_, 0);
v_isSharedCheck_3044_ = !lean_is_exclusive(v_x_3028_);
if (v_isSharedCheck_3044_ == 0)
{
v___x_3032_ = v_x_3028_;
v_isShared_3033_ = v_isSharedCheck_3044_;
goto v_resetjp_3031_;
}
else
{
lean_inc(v_val_3030_);
lean_dec(v_x_3028_);
v___x_3032_ = lean_box(0);
v_isShared_3033_ = v_isSharedCheck_3044_;
goto v_resetjp_3031_;
}
v_resetjp_3031_:
{
lean_object* v_st_3034_; 
v_st_3034_ = lean_ctor_get(v_val_3030_, 3);
lean_inc_ref(v_st_3034_);
lean_dec(v_val_3030_);
switch(lean_obj_tag(v_st_3034_))
{
case 1:
{
lean_object* v_acc_3035_; lean_object* v___x_3037_; 
v_acc_3035_ = lean_ctor_get(v_st_3034_, 1);
lean_inc(v_acc_3035_);
lean_dec_ref_known(v_st_3034_, 3);
if (v_isShared_3033_ == 0)
{
lean_ctor_set(v___x_3032_, 0, v_acc_3035_);
v___x_3037_ = v___x_3032_;
goto v_reusejp_3036_;
}
else
{
lean_object* v_reuseFailAlloc_3038_; 
v_reuseFailAlloc_3038_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_3038_, 0, v_acc_3035_);
v___x_3037_ = v_reuseFailAlloc_3038_;
goto v_reusejp_3036_;
}
v_reusejp_3036_:
{
return v___x_3037_;
}
}
case 3:
{
lean_object* v_acc_3039_; lean_object* v___x_3041_; 
v_acc_3039_ = lean_ctor_get(v_st_3034_, 0);
lean_inc(v_acc_3039_);
lean_dec_ref_known(v_st_3034_, 2);
if (v_isShared_3033_ == 0)
{
lean_ctor_set(v___x_3032_, 0, v_acc_3039_);
v___x_3041_ = v___x_3032_;
goto v_reusejp_3040_;
}
else
{
lean_object* v_reuseFailAlloc_3042_; 
v_reuseFailAlloc_3042_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_3042_, 0, v_acc_3039_);
v___x_3041_ = v_reuseFailAlloc_3042_;
goto v_reusejp_3040_;
}
v_reusejp_3040_:
{
return v___x_3041_;
}
}
default: 
{
lean_object* v___x_3043_; 
lean_dec_ref(v_st_3034_);
lean_del_object(v___x_3032_);
v___x_3043_ = lean_box(0);
return v___x_3043_;
}
}
}
}
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_remEmptyOf(lean_object* v_x_3045_){
_start:
{
lean_object* v___x_3046_; 
v___x_3046_ = lp_bounded_Bounded_remOf(v_x_3045_);
if (lean_obj_tag(v___x_3046_) == 0)
{
uint8_t v___x_3047_; 
v___x_3047_ = 1;
return v___x_3047_;
}
else
{
lean_object* v_val_3048_; uint8_t v___x_3049_; 
v_val_3048_ = lean_ctor_get(v___x_3046_, 0);
lean_inc(v_val_3048_);
lean_dec_ref_known(v___x_3046_, 1);
v___x_3049_ = l_List_isEmpty___redArg(v_val_3048_);
lean_dec(v_val_3048_);
return v___x_3049_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_remEmptyOf___boxed(lean_object* v_x_3050_){
_start:
{
uint8_t v_res_3051_; lean_object* v_r_3052_; 
v_res_3051_ = lp_bounded_Bounded_remEmptyOf(v_x_3050_);
v_r_3052_ = lean_box(v_res_3051_);
return v_r_3052_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_accClsOfOpt(lean_object* v_x_3061_){
_start:
{
lean_object* v___x_3062_; 
v___x_3062_ = lp_bounded_Bounded_accOf(v_x_3061_);
if (lean_obj_tag(v___x_3062_) == 0)
{
lean_object* v___x_3063_; 
v___x_3063_ = ((lean_object*)(lp_bounded_Bounded_accClsOfOpt___closed__1));
return v___x_3063_;
}
else
{
lean_object* v_val_3064_; lean_object* v___x_3065_; 
v_val_3064_ = lean_ctor_get(v___x_3062_, 0);
lean_inc(v_val_3064_);
lean_dec_ref_known(v___x_3062_, 1);
v___x_3065_ = lp_bounded_Bounded_accClsOf(v_val_3064_);
lean_dec(v_val_3064_);
return v___x_3065_;
}
}
}
LEAN_EXPORT uint8_t lp_bounded_List_any___at___00Bounded_sig_spec__0(lean_object* v_c_3066_, lean_object* v_val_3067_, lean_object* v_x_3068_){
_start:
{
if (lean_obj_tag(v_x_3068_) == 0)
{
uint8_t v___x_3069_; 
v___x_3069_ = 0;
return v___x_3069_;
}
else
{
lean_object* v_head_3070_; lean_object* v_tail_3071_; lean_object* v_provs_3072_; lean_object* v___x_3073_; uint8_t v___x_3074_; 
v_head_3070_ = lean_ctor_get(v_x_3068_, 0);
v_tail_3071_ = lean_ctor_get(v_x_3068_, 1);
v_provs_3072_ = lean_ctor_get(v_c_3066_, 1);
v___x_3073_ = lp_bounded_Bounded_KMap_get___redArg(v_provs_3072_, v_head_3070_);
v___x_3074_ = lean_unbox(v___x_3073_);
lean_dec(v___x_3073_);
if (v___x_3074_ == 0)
{
v_x_3068_ = v_tail_3071_;
goto _start;
}
else
{
lean_object* v_comp_3076_; lean_object* v_provs_3077_; lean_object* v___x_3078_; uint8_t v___x_3079_; 
v_comp_3076_ = lean_ctor_get(v_val_3067_, 0);
v_provs_3077_ = lean_ctor_get(v_comp_3076_, 1);
v___x_3078_ = lp_bounded_Bounded_KMap_get___redArg(v_provs_3077_, v_head_3070_);
v___x_3079_ = lean_unbox(v___x_3078_);
if (v___x_3079_ == 0)
{
lean_dec(v___x_3078_);
v_x_3068_ = v_tail_3071_;
goto _start;
}
else
{
uint8_t v___x_3081_; 
v___x_3081_ = lean_unbox(v___x_3078_);
lean_dec(v___x_3078_);
return v___x_3081_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_List_any___at___00Bounded_sig_spec__0___boxed(lean_object* v_c_3082_, lean_object* v_val_3083_, lean_object* v_x_3084_){
_start:
{
uint8_t v_res_3085_; lean_object* v_r_3086_; 
v_res_3085_ = lp_bounded_List_any___at___00Bounded_sig_spec__0(v_c_3082_, v_val_3083_, v_x_3084_);
lean_dec(v_x_3084_);
lean_dec_ref(v_val_3083_);
lean_dec_ref(v_c_3082_);
v_r_3086_ = lean_box(v_res_3085_);
return v_r_3086_;
}
}
LEAN_EXPORT uint8_t lp_bounded_List_any___at___00Bounded_sig_spec__1(lean_object* v_00_u03b3_3087_, lean_object* v_c_3088_, lean_object* v_x_3089_){
_start:
{
if (lean_obj_tag(v_x_3089_) == 0)
{
uint8_t v___x_3090_; 
v___x_3090_ = 0;
return v___x_3090_;
}
else
{
lean_object* v_head_3091_; lean_object* v_tail_3092_; lean_object* v___x_3093_; 
v_head_3091_ = lean_ctor_get(v_x_3089_, 0);
v_tail_3092_ = lean_ctor_get(v_x_3089_, 1);
v___x_3093_ = lp_bounded_Bounded_SMap_get___redArg(v_00_u03b3_3087_, v_head_3091_);
if (lean_obj_tag(v___x_3093_) == 0)
{
v_x_3089_ = v_tail_3092_;
goto _start;
}
else
{
lean_object* v_val_3095_; lean_object* v___x_3096_; uint8_t v___x_3097_; 
v_val_3095_ = lean_ctor_get(v___x_3093_, 0);
lean_inc(v_val_3095_);
lean_dec_ref_known(v___x_3093_, 1);
v___x_3096_ = lp_bounded_Bounded_allKeys;
v___x_3097_ = lp_bounded_List_any___at___00Bounded_sig_spec__0(v_c_3088_, v_val_3095_, v___x_3096_);
lean_dec(v_val_3095_);
if (v___x_3097_ == 0)
{
v_x_3089_ = v_tail_3092_;
goto _start;
}
else
{
return v___x_3097_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_List_any___at___00Bounded_sig_spec__1___boxed(lean_object* v_00_u03b3_3099_, lean_object* v_c_3100_, lean_object* v_x_3101_){
_start:
{
uint8_t v_res_3102_; lean_object* v_r_3103_; 
v_res_3102_ = lp_bounded_List_any___at___00Bounded_sig_spec__1(v_00_u03b3_3099_, v_c_3100_, v_x_3101_);
lean_dec(v_x_3101_);
lean_dec_ref(v_c_3100_);
lean_dec_ref(v_00_u03b3_3099_);
v_r_3103_ = lean_box(v_res_3102_);
return v_r_3103_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_sig(lean_object* v_a_3104_, lean_object* v_00_u03b3_3105_){
_start:
{
switch(lean_obj_tag(v_a_3104_))
{
case 0:
{
lean_object* v_n_3106_; lean_object* v_c_3107_; uint8_t v___x_3108_; uint8_t v___x_3109_; uint8_t v___x_3110_; uint8_t v___x_3111_; lean_object* v___x_3112_; uint8_t v___x_3113_; uint8_t v___y_3115_; lean_object* v___x_3120_; 
v_n_3106_ = lean_ctor_get(v_a_3104_, 0);
lean_inc(v_n_3106_);
v_c_3107_ = lean_ctor_get(v_a_3104_, 1);
lean_inc_ref(v_c_3107_);
lean_dec_ref_known(v_a_3104_, 2);
v___x_3108_ = 0;
v___x_3109_ = 0;
v___x_3110_ = 0;
v___x_3111_ = 0;
v___x_3112_ = lean_box(0);
v___x_3113_ = 1;
v___x_3120_ = lp_bounded_Bounded_SMap_get___redArg(v_00_u03b3_3105_, v_n_3106_);
lean_dec(v_n_3106_);
if (lean_obj_tag(v___x_3120_) == 0)
{
v___y_3115_ = v___x_3113_;
goto v___jp_3114_;
}
else
{
lean_dec_ref_known(v___x_3120_, 1);
v___y_3115_ = v___x_3109_;
goto v___jp_3114_;
}
v___jp_3114_:
{
lean_object* v___x_3116_; uint8_t v___x_3117_; lean_object* v___x_3118_; lean_object* v___x_3119_; 
v___x_3116_ = lp_bounded_Bounded_allSlots;
v___x_3117_ = lp_bounded_List_any___at___00Bounded_sig_spec__1(v_00_u03b3_3105_, v_c_3107_, v___x_3116_);
lean_dec_ref(v_c_3107_);
lean_dec_ref(v_00_u03b3_3105_);
v___x_3118_ = ((lean_object*)(lp_bounded_Bounded_accClsOfOpt___closed__1));
v___x_3119_ = lean_alloc_ctor(0, 3, 11);
lean_ctor_set(v___x_3119_, 0, v___x_3112_);
lean_ctor_set(v___x_3119_, 1, v___x_3118_);
lean_ctor_set(v___x_3119_, 2, v___x_3118_);
lean_ctor_set_uint8(v___x_3119_, sizeof(void*)*3, v___x_3108_);
lean_ctor_set_uint8(v___x_3119_, sizeof(void*)*3 + 1, v___x_3109_);
lean_ctor_set_uint8(v___x_3119_, sizeof(void*)*3 + 2, v___x_3110_);
lean_ctor_set_uint8(v___x_3119_, sizeof(void*)*3 + 3, v___x_3109_);
lean_ctor_set_uint8(v___x_3119_, sizeof(void*)*3 + 4, v___x_3111_);
lean_ctor_set_uint8(v___x_3119_, sizeof(void*)*3 + 5, v___x_3113_);
lean_ctor_set_uint8(v___x_3119_, sizeof(void*)*3 + 6, v___x_3109_);
lean_ctor_set_uint8(v___x_3119_, sizeof(void*)*3 + 7, v___x_3109_);
lean_ctor_set_uint8(v___x_3119_, sizeof(void*)*3 + 8, v___y_3115_);
lean_ctor_set_uint8(v___x_3119_, sizeof(void*)*3 + 9, v___x_3117_);
lean_ctor_set_uint8(v___x_3119_, sizeof(void*)*3 + 10, v___x_3113_);
return v___x_3119_;
}
}
case 1:
{
lean_object* v_n_3121_; uint8_t v___x_3122_; lean_object* v___x_3123_; uint8_t v___y_3125_; 
v_n_3121_ = lean_ctor_get(v_a_3104_, 0);
lean_inc(v_n_3121_);
lean_dec_ref_known(v_a_3104_, 1);
v___x_3122_ = 1;
v___x_3123_ = lp_bounded_Bounded_SMap_get___redArg(v_00_u03b3_3105_, v_n_3121_);
lean_dec(v_n_3121_);
lean_dec_ref(v_00_u03b3_3105_);
if (lean_obj_tag(v___x_3123_) == 0)
{
uint8_t v___x_3134_; 
v___x_3134_ = 0;
v___y_3125_ = v___x_3134_;
goto v___jp_3124_;
}
else
{
uint8_t v___x_3135_; 
v___x_3135_ = 1;
v___y_3125_ = v___x_3135_;
goto v___jp_3124_;
}
v___jp_3124_:
{
uint8_t v___x_3126_; uint8_t v___x_3127_; uint8_t v___x_3128_; lean_object* v___x_3129_; uint8_t v___x_3130_; uint8_t v___x_3131_; lean_object* v___x_3132_; lean_object* v___x_3133_; 
v___x_3126_ = lp_bounded_Bounded_stClsOf(v___x_3123_);
v___x_3127_ = lp_bounded_Bounded_retiredOf(v___x_3123_);
lean_dec(v___x_3123_);
v___x_3128_ = 0;
v___x_3129_ = lean_box(0);
v___x_3130_ = 1;
v___x_3131_ = 0;
v___x_3132_ = ((lean_object*)(lp_bounded_Bounded_accClsOfOpt___closed__1));
v___x_3133_ = lean_alloc_ctor(0, 3, 11);
lean_ctor_set(v___x_3133_, 0, v___x_3129_);
lean_ctor_set(v___x_3133_, 1, v___x_3132_);
lean_ctor_set(v___x_3133_, 2, v___x_3132_);
lean_ctor_set_uint8(v___x_3133_, sizeof(void*)*3, v___x_3122_);
lean_ctor_set_uint8(v___x_3133_, sizeof(void*)*3 + 1, v___y_3125_);
lean_ctor_set_uint8(v___x_3133_, sizeof(void*)*3 + 2, v___x_3126_);
lean_ctor_set_uint8(v___x_3133_, sizeof(void*)*3 + 3, v___x_3127_);
lean_ctor_set_uint8(v___x_3133_, sizeof(void*)*3 + 4, v___x_3128_);
lean_ctor_set_uint8(v___x_3133_, sizeof(void*)*3 + 5, v___x_3130_);
lean_ctor_set_uint8(v___x_3133_, sizeof(void*)*3 + 6, v___x_3131_);
lean_ctor_set_uint8(v___x_3133_, sizeof(void*)*3 + 7, v___x_3131_);
lean_ctor_set_uint8(v___x_3133_, sizeof(void*)*3 + 8, v___x_3131_);
lean_ctor_set_uint8(v___x_3133_, sizeof(void*)*3 + 9, v___x_3131_);
lean_ctor_set_uint8(v___x_3133_, sizeof(void*)*3 + 10, v___x_3130_);
return v___x_3133_;
}
}
case 2:
{
lean_object* v_n_3136_; uint8_t v___x_3137_; lean_object* v___x_3138_; uint8_t v___y_3140_; 
v_n_3136_ = lean_ctor_get(v_a_3104_, 0);
lean_inc(v_n_3136_);
lean_dec_ref_known(v_a_3104_, 1);
v___x_3137_ = 2;
v___x_3138_ = lp_bounded_Bounded_SMap_get___redArg(v_00_u03b3_3105_, v_n_3136_);
if (lean_obj_tag(v___x_3138_) == 0)
{
uint8_t v___x_3150_; 
v___x_3150_ = 0;
v___y_3140_ = v___x_3150_;
goto v___jp_3139_;
}
else
{
uint8_t v___x_3151_; 
v___x_3151_ = 1;
v___y_3140_ = v___x_3151_;
goto v___jp_3139_;
}
v___jp_3139_:
{
uint8_t v___x_3141_; uint8_t v___x_3142_; uint8_t v___x_3143_; lean_object* v___x_3144_; uint8_t v___x_3145_; uint8_t v___x_3146_; uint8_t v___x_3147_; lean_object* v___x_3148_; lean_object* v___x_3149_; 
v___x_3141_ = lp_bounded_Bounded_stClsOf(v___x_3138_);
v___x_3142_ = lp_bounded_Bounded_retiredOf(v___x_3138_);
lean_dec(v___x_3138_);
v___x_3143_ = 0;
v___x_3144_ = lean_box(0);
v___x_3145_ = 1;
v___x_3146_ = 0;
v___x_3147_ = lp_bounded_Bounded_hasChild(v_00_u03b3_3105_, v_n_3136_);
lean_dec_ref(v_00_u03b3_3105_);
v___x_3148_ = ((lean_object*)(lp_bounded_Bounded_accClsOfOpt___closed__1));
v___x_3149_ = lean_alloc_ctor(0, 3, 11);
lean_ctor_set(v___x_3149_, 0, v___x_3144_);
lean_ctor_set(v___x_3149_, 1, v___x_3148_);
lean_ctor_set(v___x_3149_, 2, v___x_3148_);
lean_ctor_set_uint8(v___x_3149_, sizeof(void*)*3, v___x_3137_);
lean_ctor_set_uint8(v___x_3149_, sizeof(void*)*3 + 1, v___y_3140_);
lean_ctor_set_uint8(v___x_3149_, sizeof(void*)*3 + 2, v___x_3141_);
lean_ctor_set_uint8(v___x_3149_, sizeof(void*)*3 + 3, v___x_3142_);
lean_ctor_set_uint8(v___x_3149_, sizeof(void*)*3 + 4, v___x_3143_);
lean_ctor_set_uint8(v___x_3149_, sizeof(void*)*3 + 5, v___x_3145_);
lean_ctor_set_uint8(v___x_3149_, sizeof(void*)*3 + 6, v___x_3146_);
lean_ctor_set_uint8(v___x_3149_, sizeof(void*)*3 + 7, v___x_3147_);
lean_ctor_set_uint8(v___x_3149_, sizeof(void*)*3 + 8, v___x_3146_);
lean_ctor_set_uint8(v___x_3149_, sizeof(void*)*3 + 9, v___x_3146_);
lean_ctor_set_uint8(v___x_3149_, sizeof(void*)*3 + 10, v___x_3145_);
return v___x_3149_;
}
}
case 3:
{
lean_object* v_n_3152_; uint8_t v___x_3153_; lean_object* v___x_3154_; uint8_t v___y_3156_; 
v_n_3152_ = lean_ctor_get(v_a_3104_, 0);
lean_inc(v_n_3152_);
lean_dec_ref_known(v_a_3104_, 1);
v___x_3153_ = 3;
v___x_3154_ = lp_bounded_Bounded_SMap_get___redArg(v_00_u03b3_3105_, v_n_3152_);
if (lean_obj_tag(v___x_3154_) == 0)
{
uint8_t v___x_3168_; 
v___x_3168_ = 0;
v___y_3156_ = v___x_3168_;
goto v___jp_3155_;
}
else
{
uint8_t v___x_3169_; 
v___x_3169_ = 1;
v___y_3156_ = v___x_3169_;
goto v___jp_3155_;
}
v___jp_3155_:
{
uint8_t v___x_3157_; uint8_t v___x_3158_; uint8_t v___x_3159_; lean_object* v___x_3160_; uint8_t v___x_3161_; uint8_t v___x_3162_; lean_object* v___x_3163_; 
v___x_3157_ = lp_bounded_Bounded_stClsOf(v___x_3154_);
v___x_3158_ = lp_bounded_Bounded_retiredOf(v___x_3154_);
lean_inc_ref(v_00_u03b3_3105_);
v___x_3159_ = lp_bounded_Bounded_tRelOf(v_00_u03b3_3105_, v_n_3152_);
lean_dec(v_n_3152_);
v___x_3160_ = lean_box(0);
v___x_3161_ = 1;
v___x_3162_ = 0;
v___x_3163_ = ((lean_object*)(lp_bounded_Bounded_accClsOfOpt___closed__1));
if (lean_obj_tag(v___x_3154_) == 0)
{
lean_object* v___x_3164_; 
lean_dec_ref(v_00_u03b3_3105_);
v___x_3164_ = lean_alloc_ctor(0, 3, 11);
lean_ctor_set(v___x_3164_, 0, v___x_3160_);
lean_ctor_set(v___x_3164_, 1, v___x_3163_);
lean_ctor_set(v___x_3164_, 2, v___x_3163_);
lean_ctor_set_uint8(v___x_3164_, sizeof(void*)*3, v___x_3153_);
lean_ctor_set_uint8(v___x_3164_, sizeof(void*)*3 + 1, v___y_3156_);
lean_ctor_set_uint8(v___x_3164_, sizeof(void*)*3 + 2, v___x_3157_);
lean_ctor_set_uint8(v___x_3164_, sizeof(void*)*3 + 3, v___x_3158_);
lean_ctor_set_uint8(v___x_3164_, sizeof(void*)*3 + 4, v___x_3159_);
lean_ctor_set_uint8(v___x_3164_, sizeof(void*)*3 + 5, v___x_3161_);
lean_ctor_set_uint8(v___x_3164_, sizeof(void*)*3 + 6, v___x_3162_);
lean_ctor_set_uint8(v___x_3164_, sizeof(void*)*3 + 7, v___x_3162_);
lean_ctor_set_uint8(v___x_3164_, sizeof(void*)*3 + 8, v___x_3162_);
lean_ctor_set_uint8(v___x_3164_, sizeof(void*)*3 + 9, v___x_3162_);
lean_ctor_set_uint8(v___x_3164_, sizeof(void*)*3 + 10, v___x_3161_);
return v___x_3164_;
}
else
{
lean_object* v_val_3165_; lean_object* v___x_3166_; lean_object* v___x_3167_; 
v_val_3165_ = lean_ctor_get(v___x_3154_, 0);
lean_inc(v_val_3165_);
lean_dec_ref_known(v___x_3154_, 1);
v___x_3166_ = lp_bounded_Bounded_satClsOf(v_00_u03b3_3105_, v_val_3165_);
lean_dec(v_val_3165_);
lean_dec_ref(v_00_u03b3_3105_);
v___x_3167_ = lean_alloc_ctor(0, 3, 11);
lean_ctor_set(v___x_3167_, 0, v___x_3160_);
lean_ctor_set(v___x_3167_, 1, v___x_3163_);
lean_ctor_set(v___x_3167_, 2, v___x_3166_);
lean_ctor_set_uint8(v___x_3167_, sizeof(void*)*3, v___x_3153_);
lean_ctor_set_uint8(v___x_3167_, sizeof(void*)*3 + 1, v___y_3156_);
lean_ctor_set_uint8(v___x_3167_, sizeof(void*)*3 + 2, v___x_3157_);
lean_ctor_set_uint8(v___x_3167_, sizeof(void*)*3 + 3, v___x_3158_);
lean_ctor_set_uint8(v___x_3167_, sizeof(void*)*3 + 4, v___x_3159_);
lean_ctor_set_uint8(v___x_3167_, sizeof(void*)*3 + 5, v___x_3161_);
lean_ctor_set_uint8(v___x_3167_, sizeof(void*)*3 + 6, v___x_3162_);
lean_ctor_set_uint8(v___x_3167_, sizeof(void*)*3 + 7, v___x_3162_);
lean_ctor_set_uint8(v___x_3167_, sizeof(void*)*3 + 8, v___x_3162_);
lean_ctor_set_uint8(v___x_3167_, sizeof(void*)*3 + 9, v___x_3162_);
lean_ctor_set_uint8(v___x_3167_, sizeof(void*)*3 + 10, v___x_3161_);
return v___x_3167_;
}
}
}
case 4:
{
lean_object* v_n_3170_; lean_object* v_creg_3171_; lean_object* v___x_3173_; uint8_t v_isShared_3174_; uint8_t v_isSharedCheck_3217_; 
v_n_3170_ = lean_ctor_get(v_a_3104_, 0);
v_creg_3171_ = lean_ctor_get(v_a_3104_, 1);
v_isSharedCheck_3217_ = !lean_is_exclusive(v_a_3104_);
if (v_isSharedCheck_3217_ == 0)
{
v___x_3173_ = v_a_3104_;
v_isShared_3174_ = v_isSharedCheck_3217_;
goto v_resetjp_3172_;
}
else
{
lean_inc(v_creg_3171_);
lean_inc(v_n_3170_);
lean_dec(v_a_3104_);
v___x_3173_ = lean_box(0);
v_isShared_3174_ = v_isSharedCheck_3217_;
goto v_resetjp_3172_;
}
v_resetjp_3172_:
{
uint8_t v___x_3175_; lean_object* v___x_3176_; uint8_t v___y_3178_; uint8_t v___y_3179_; uint8_t v___y_3180_; uint8_t v___y_3181_; lean_object* v___y_3182_; uint8_t v___y_3195_; 
v___x_3175_ = 4;
v___x_3176_ = lp_bounded_Bounded_SMap_get___redArg(v_00_u03b3_3105_, v_n_3170_);
if (lean_obj_tag(v___x_3176_) == 0)
{
uint8_t v___x_3215_; 
v___x_3215_ = 0;
v___y_3195_ = v___x_3215_;
goto v___jp_3194_;
}
else
{
uint8_t v___x_3216_; 
v___x_3216_ = 1;
v___y_3195_ = v___x_3216_;
goto v___jp_3194_;
}
v___jp_3177_:
{
uint8_t v___x_3183_; uint8_t v___x_3184_; lean_object* v___x_3185_; lean_object* v___x_3186_; lean_object* v___x_3187_; lean_object* v___x_3189_; 
lean_inc(v___x_3176_);
v___x_3183_ = lp_bounded_Bounded_remEmptyOf(v___x_3176_);
v___x_3184_ = 1;
v___x_3185_ = lp_bounded_Bounded_accClsOfOpt(v___x_3176_);
v___x_3186_ = lean_box(v___y_3180_);
v___x_3187_ = lean_box(v___y_3180_);
if (v_isShared_3174_ == 0)
{
lean_ctor_set_tag(v___x_3173_, 0);
lean_ctor_set(v___x_3173_, 1, v___x_3187_);
lean_ctor_set(v___x_3173_, 0, v___x_3186_);
v___x_3189_ = v___x_3173_;
goto v_reusejp_3188_;
}
else
{
lean_object* v_reuseFailAlloc_3193_; 
v_reuseFailAlloc_3193_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_3193_, 0, v___x_3186_);
lean_ctor_set(v_reuseFailAlloc_3193_, 1, v___x_3187_);
v___x_3189_ = v_reuseFailAlloc_3193_;
goto v_reusejp_3188_;
}
v_reusejp_3188_:
{
lean_object* v___x_3190_; lean_object* v___x_3191_; lean_object* v___x_3192_; 
v___x_3190_ = lean_box(v___y_3180_);
v___x_3191_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_3191_, 0, v___x_3190_);
lean_ctor_set(v___x_3191_, 1, v___x_3189_);
v___x_3192_ = lean_alloc_ctor(0, 3, 11);
lean_ctor_set(v___x_3192_, 0, v___y_3182_);
lean_ctor_set(v___x_3192_, 1, v___x_3185_);
lean_ctor_set(v___x_3192_, 2, v___x_3191_);
lean_ctor_set_uint8(v___x_3192_, sizeof(void*)*3, v___x_3175_);
lean_ctor_set_uint8(v___x_3192_, sizeof(void*)*3 + 1, v___y_3179_);
lean_ctor_set_uint8(v___x_3192_, sizeof(void*)*3 + 2, v___y_3181_);
lean_ctor_set_uint8(v___x_3192_, sizeof(void*)*3 + 3, v___y_3180_);
lean_ctor_set_uint8(v___x_3192_, sizeof(void*)*3 + 4, v___y_3178_);
lean_ctor_set_uint8(v___x_3192_, sizeof(void*)*3 + 5, v___x_3183_);
lean_ctor_set_uint8(v___x_3192_, sizeof(void*)*3 + 6, v___y_3180_);
lean_ctor_set_uint8(v___x_3192_, sizeof(void*)*3 + 7, v___y_3180_);
lean_ctor_set_uint8(v___x_3192_, sizeof(void*)*3 + 8, v___y_3180_);
lean_ctor_set_uint8(v___x_3192_, sizeof(void*)*3 + 9, v___y_3180_);
lean_ctor_set_uint8(v___x_3192_, sizeof(void*)*3 + 10, v___x_3184_);
return v___x_3192_;
}
}
v___jp_3194_:
{
uint8_t v___x_3196_; uint8_t v___x_3197_; uint8_t v___x_3198_; 
v___x_3196_ = lp_bounded_Bounded_stClsOf(v___x_3176_);
v___x_3197_ = 0;
lean_inc_ref(v_00_u03b3_3105_);
v___x_3198_ = lp_bounded_Bounded_tRelOf(v_00_u03b3_3105_, v_n_3170_);
if (lean_obj_tag(v___x_3176_) == 0)
{
lean_object* v___x_3199_; 
lean_dec(v_creg_3171_);
lean_dec(v_n_3170_);
lean_dec_ref(v_00_u03b3_3105_);
v___x_3199_ = lean_box(0);
v___y_3178_ = v___x_3198_;
v___y_3179_ = v___y_3195_;
v___y_3180_ = v___x_3197_;
v___y_3181_ = v___x_3196_;
v___y_3182_ = v___x_3199_;
goto v___jp_3177_;
}
else
{
lean_object* v_val_3200_; lean_object* v_st_3201_; 
v_val_3200_ = lean_ctor_get(v___x_3176_, 0);
lean_inc(v_val_3200_);
v_st_3201_ = lean_ctor_get(v_val_3200_, 3);
if (lean_obj_tag(v_st_3201_) == 1)
{
lean_object* v_remaining_3202_; lean_object* v___x_3203_; 
v_remaining_3202_ = lean_ctor_get(v_st_3201_, 0);
v___x_3203_ = l_List_head_x3f___redArg(v_remaining_3202_);
if (lean_obj_tag(v___x_3203_) == 0)
{
lean_object* v___x_3204_; 
lean_dec(v_val_3200_);
lean_dec(v_creg_3171_);
lean_dec(v_n_3170_);
lean_dec_ref(v_00_u03b3_3105_);
v___x_3204_ = lean_box(0);
v___y_3178_ = v___x_3198_;
v___y_3179_ = v___y_3195_;
v___y_3180_ = v___x_3197_;
v___y_3181_ = v___x_3196_;
v___y_3182_ = v___x_3204_;
goto v___jp_3177_;
}
else
{
lean_object* v_val_3205_; lean_object* v___x_3207_; uint8_t v_isShared_3208_; uint8_t v_isSharedCheck_3213_; 
v_val_3205_ = lean_ctor_get(v___x_3203_, 0);
v_isSharedCheck_3213_ = !lean_is_exclusive(v___x_3203_);
if (v_isSharedCheck_3213_ == 0)
{
v___x_3207_ = v___x_3203_;
v_isShared_3208_ = v_isSharedCheck_3213_;
goto v_resetjp_3206_;
}
else
{
lean_inc(v_val_3205_);
lean_dec(v___x_3203_);
v___x_3207_ = lean_box(0);
v_isShared_3208_ = v_isSharedCheck_3213_;
goto v_resetjp_3206_;
}
v_resetjp_3206_:
{
lean_object* v___x_3209_; lean_object* v___x_3211_; 
v___x_3209_ = lp_bounded_Bounded_classifyIter(v_00_u03b3_3105_, v_n_3170_, v_val_3200_, v_creg_3171_, v_val_3205_);
lean_dec(v_val_3205_);
lean_dec(v_creg_3171_);
lean_dec(v_val_3200_);
lean_dec(v_n_3170_);
lean_dec_ref(v_00_u03b3_3105_);
if (v_isShared_3208_ == 0)
{
lean_ctor_set(v___x_3207_, 0, v___x_3209_);
v___x_3211_ = v___x_3207_;
goto v_reusejp_3210_;
}
else
{
lean_object* v_reuseFailAlloc_3212_; 
v_reuseFailAlloc_3212_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_3212_, 0, v___x_3209_);
v___x_3211_ = v_reuseFailAlloc_3212_;
goto v_reusejp_3210_;
}
v_reusejp_3210_:
{
v___y_3178_ = v___x_3198_;
v___y_3179_ = v___y_3195_;
v___y_3180_ = v___x_3197_;
v___y_3181_ = v___x_3196_;
v___y_3182_ = v___x_3211_;
goto v___jp_3177_;
}
}
}
}
else
{
lean_object* v___x_3214_; 
lean_dec(v_val_3200_);
lean_dec(v_creg_3171_);
lean_dec(v_n_3170_);
lean_dec_ref(v_00_u03b3_3105_);
v___x_3214_ = lean_box(0);
v___y_3178_ = v___x_3198_;
v___y_3179_ = v___y_3195_;
v___y_3180_ = v___x_3197_;
v___y_3181_ = v___x_3196_;
v___y_3182_ = v___x_3214_;
goto v___jp_3177_;
}
}
}
}
}
case 5:
{
lean_object* v_n_3218_; uint8_t v___x_3219_; lean_object* v___x_3220_; uint8_t v___y_3222_; 
v_n_3218_ = lean_ctor_get(v_a_3104_, 0);
lean_inc(v_n_3218_);
lean_dec_ref_known(v_a_3104_, 1);
v___x_3219_ = 5;
v___x_3220_ = lp_bounded_Bounded_SMap_get___redArg(v_00_u03b3_3105_, v_n_3218_);
if (lean_obj_tag(v___x_3220_) == 0)
{
uint8_t v___x_3231_; 
v___x_3231_ = 0;
v___y_3222_ = v___x_3231_;
goto v___jp_3221_;
}
else
{
uint8_t v___x_3232_; 
v___x_3232_ = 1;
v___y_3222_ = v___x_3232_;
goto v___jp_3221_;
}
v___jp_3221_:
{
uint8_t v___x_3223_; uint8_t v___x_3224_; uint8_t v___x_3225_; lean_object* v___x_3226_; uint8_t v___x_3227_; uint8_t v___x_3228_; lean_object* v___x_3229_; lean_object* v___x_3230_; 
v___x_3223_ = lp_bounded_Bounded_stClsOf(v___x_3220_);
v___x_3224_ = 0;
v___x_3225_ = lp_bounded_Bounded_tRelOf(v_00_u03b3_3105_, v_n_3218_);
lean_dec(v_n_3218_);
v___x_3226_ = lean_box(0);
v___x_3227_ = lp_bounded_Bounded_remEmptyOf(v___x_3220_);
v___x_3228_ = 1;
v___x_3229_ = ((lean_object*)(lp_bounded_Bounded_accClsOfOpt___closed__1));
v___x_3230_ = lean_alloc_ctor(0, 3, 11);
lean_ctor_set(v___x_3230_, 0, v___x_3226_);
lean_ctor_set(v___x_3230_, 1, v___x_3229_);
lean_ctor_set(v___x_3230_, 2, v___x_3229_);
lean_ctor_set_uint8(v___x_3230_, sizeof(void*)*3, v___x_3219_);
lean_ctor_set_uint8(v___x_3230_, sizeof(void*)*3 + 1, v___y_3222_);
lean_ctor_set_uint8(v___x_3230_, sizeof(void*)*3 + 2, v___x_3223_);
lean_ctor_set_uint8(v___x_3230_, sizeof(void*)*3 + 3, v___x_3224_);
lean_ctor_set_uint8(v___x_3230_, sizeof(void*)*3 + 4, v___x_3225_);
lean_ctor_set_uint8(v___x_3230_, sizeof(void*)*3 + 5, v___x_3227_);
lean_ctor_set_uint8(v___x_3230_, sizeof(void*)*3 + 6, v___x_3224_);
lean_ctor_set_uint8(v___x_3230_, sizeof(void*)*3 + 7, v___x_3224_);
lean_ctor_set_uint8(v___x_3230_, sizeof(void*)*3 + 8, v___x_3224_);
lean_ctor_set_uint8(v___x_3230_, sizeof(void*)*3 + 9, v___x_3224_);
lean_ctor_set_uint8(v___x_3230_, sizeof(void*)*3 + 10, v___x_3228_);
return v___x_3230_;
}
}
case 6:
{
lean_object* v_n_3233_; uint8_t v___x_3234_; lean_object* v___x_3235_; uint8_t v___y_3237_; 
v_n_3233_ = lean_ctor_get(v_a_3104_, 0);
lean_inc(v_n_3233_);
lean_dec_ref_known(v_a_3104_, 1);
v___x_3234_ = 6;
v___x_3235_ = lp_bounded_Bounded_SMap_get___redArg(v_00_u03b3_3105_, v_n_3233_);
if (lean_obj_tag(v___x_3235_) == 0)
{
uint8_t v___x_3246_; 
v___x_3246_ = 0;
v___y_3237_ = v___x_3246_;
goto v___jp_3236_;
}
else
{
uint8_t v___x_3247_; 
v___x_3247_ = 1;
v___y_3237_ = v___x_3247_;
goto v___jp_3236_;
}
v___jp_3236_:
{
uint8_t v___x_3238_; uint8_t v___x_3239_; uint8_t v___x_3240_; lean_object* v___x_3241_; uint8_t v___x_3242_; lean_object* v___x_3243_; lean_object* v___x_3244_; lean_object* v___x_3245_; 
v___x_3238_ = lp_bounded_Bounded_stClsOf(v___x_3235_);
v___x_3239_ = 0;
v___x_3240_ = lp_bounded_Bounded_tRelOf(v_00_u03b3_3105_, v_n_3233_);
lean_dec(v_n_3233_);
v___x_3241_ = lean_box(0);
v___x_3242_ = 1;
v___x_3243_ = lp_bounded_Bounded_accClsOfOpt(v___x_3235_);
v___x_3244_ = ((lean_object*)(lp_bounded_Bounded_accClsOfOpt___closed__1));
v___x_3245_ = lean_alloc_ctor(0, 3, 11);
lean_ctor_set(v___x_3245_, 0, v___x_3241_);
lean_ctor_set(v___x_3245_, 1, v___x_3243_);
lean_ctor_set(v___x_3245_, 2, v___x_3244_);
lean_ctor_set_uint8(v___x_3245_, sizeof(void*)*3, v___x_3234_);
lean_ctor_set_uint8(v___x_3245_, sizeof(void*)*3 + 1, v___y_3237_);
lean_ctor_set_uint8(v___x_3245_, sizeof(void*)*3 + 2, v___x_3238_);
lean_ctor_set_uint8(v___x_3245_, sizeof(void*)*3 + 3, v___x_3239_);
lean_ctor_set_uint8(v___x_3245_, sizeof(void*)*3 + 4, v___x_3240_);
lean_ctor_set_uint8(v___x_3245_, sizeof(void*)*3 + 5, v___x_3242_);
lean_ctor_set_uint8(v___x_3245_, sizeof(void*)*3 + 6, v___x_3239_);
lean_ctor_set_uint8(v___x_3245_, sizeof(void*)*3 + 7, v___x_3239_);
lean_ctor_set_uint8(v___x_3245_, sizeof(void*)*3 + 8, v___x_3239_);
lean_ctor_set_uint8(v___x_3245_, sizeof(void*)*3 + 9, v___x_3239_);
lean_ctor_set_uint8(v___x_3245_, sizeof(void*)*3 + 10, v___x_3242_);
return v___x_3245_;
}
}
case 7:
{
lean_object* v_n_3248_; uint8_t v___x_3249_; lean_object* v___x_3250_; uint8_t v___y_3252_; uint8_t v___y_3253_; uint8_t v___y_3254_; uint8_t v___y_3255_; lean_object* v___y_3256_; uint8_t v___y_3267_; 
v_n_3248_ = lean_ctor_get(v_a_3104_, 0);
lean_inc(v_n_3248_);
lean_dec_ref_known(v_a_3104_, 1);
v___x_3249_ = 7;
v___x_3250_ = lp_bounded_Bounded_SMap_get___redArg(v_00_u03b3_3105_, v_n_3248_);
if (lean_obj_tag(v___x_3250_) == 0)
{
uint8_t v___x_3287_; 
v___x_3287_ = 0;
v___y_3267_ = v___x_3287_;
goto v___jp_3266_;
}
else
{
uint8_t v___x_3288_; 
v___x_3288_ = 1;
v___y_3267_ = v___x_3288_;
goto v___jp_3266_;
}
v___jp_3251_:
{
uint8_t v___x_3257_; uint8_t v___x_3258_; lean_object* v___x_3259_; lean_object* v___x_3260_; lean_object* v___x_3261_; lean_object* v___x_3262_; lean_object* v___x_3263_; lean_object* v___x_3264_; lean_object* v___x_3265_; 
lean_inc(v___x_3250_);
v___x_3257_ = lp_bounded_Bounded_remEmptyOf(v___x_3250_);
v___x_3258_ = 1;
v___x_3259_ = lp_bounded_Bounded_accClsOfOpt(v___x_3250_);
v___x_3260_ = lean_box(v___y_3252_);
v___x_3261_ = lean_box(v___y_3252_);
v___x_3262_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_3262_, 0, v___x_3260_);
lean_ctor_set(v___x_3262_, 1, v___x_3261_);
v___x_3263_ = lean_box(v___y_3252_);
v___x_3264_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_3264_, 0, v___x_3263_);
lean_ctor_set(v___x_3264_, 1, v___x_3262_);
v___x_3265_ = lean_alloc_ctor(0, 3, 11);
lean_ctor_set(v___x_3265_, 0, v___y_3256_);
lean_ctor_set(v___x_3265_, 1, v___x_3259_);
lean_ctor_set(v___x_3265_, 2, v___x_3264_);
lean_ctor_set_uint8(v___x_3265_, sizeof(void*)*3, v___x_3249_);
lean_ctor_set_uint8(v___x_3265_, sizeof(void*)*3 + 1, v___y_3254_);
lean_ctor_set_uint8(v___x_3265_, sizeof(void*)*3 + 2, v___y_3255_);
lean_ctor_set_uint8(v___x_3265_, sizeof(void*)*3 + 3, v___y_3252_);
lean_ctor_set_uint8(v___x_3265_, sizeof(void*)*3 + 4, v___y_3253_);
lean_ctor_set_uint8(v___x_3265_, sizeof(void*)*3 + 5, v___x_3257_);
lean_ctor_set_uint8(v___x_3265_, sizeof(void*)*3 + 6, v___y_3252_);
lean_ctor_set_uint8(v___x_3265_, sizeof(void*)*3 + 7, v___y_3252_);
lean_ctor_set_uint8(v___x_3265_, sizeof(void*)*3 + 8, v___y_3252_);
lean_ctor_set_uint8(v___x_3265_, sizeof(void*)*3 + 9, v___y_3252_);
lean_ctor_set_uint8(v___x_3265_, sizeof(void*)*3 + 10, v___x_3258_);
return v___x_3265_;
}
v___jp_3266_:
{
uint8_t v___x_3268_; uint8_t v___x_3269_; uint8_t v___x_3270_; 
v___x_3268_ = lp_bounded_Bounded_stClsOf(v___x_3250_);
v___x_3269_ = 0;
lean_inc_ref(v_00_u03b3_3105_);
v___x_3270_ = lp_bounded_Bounded_tRelOf(v_00_u03b3_3105_, v_n_3248_);
if (lean_obj_tag(v___x_3250_) == 0)
{
lean_object* v___x_3271_; 
lean_dec(v_n_3248_);
lean_dec_ref(v_00_u03b3_3105_);
v___x_3271_ = lean_box(0);
v___y_3252_ = v___x_3269_;
v___y_3253_ = v___x_3270_;
v___y_3254_ = v___y_3267_;
v___y_3255_ = v___x_3268_;
v___y_3256_ = v___x_3271_;
goto v___jp_3251_;
}
else
{
lean_object* v_val_3272_; lean_object* v_st_3273_; 
v_val_3272_ = lean_ctor_get(v___x_3250_, 0);
lean_inc(v_val_3272_);
v_st_3273_ = lean_ctor_get(v_val_3272_, 3);
if (lean_obj_tag(v_st_3273_) == 1)
{
lean_object* v_remaining_3274_; lean_object* v___x_3275_; 
v_remaining_3274_ = lean_ctor_get(v_st_3273_, 0);
v___x_3275_ = l_List_head_x3f___redArg(v_remaining_3274_);
if (lean_obj_tag(v___x_3275_) == 0)
{
lean_object* v___x_3276_; 
lean_dec(v_val_3272_);
lean_dec(v_n_3248_);
lean_dec_ref(v_00_u03b3_3105_);
v___x_3276_ = lean_box(0);
v___y_3252_ = v___x_3269_;
v___y_3253_ = v___x_3270_;
v___y_3254_ = v___y_3267_;
v___y_3255_ = v___x_3268_;
v___y_3256_ = v___x_3276_;
goto v___jp_3251_;
}
else
{
lean_object* v_val_3277_; lean_object* v___x_3279_; uint8_t v_isShared_3280_; uint8_t v_isSharedCheck_3285_; 
v_val_3277_ = lean_ctor_get(v___x_3275_, 0);
v_isSharedCheck_3285_ = !lean_is_exclusive(v___x_3275_);
if (v_isSharedCheck_3285_ == 0)
{
v___x_3279_ = v___x_3275_;
v_isShared_3280_ = v_isSharedCheck_3285_;
goto v_resetjp_3278_;
}
else
{
lean_inc(v_val_3277_);
lean_dec(v___x_3275_);
v___x_3279_ = lean_box(0);
v_isShared_3280_ = v_isSharedCheck_3285_;
goto v_resetjp_3278_;
}
v_resetjp_3278_:
{
lean_object* v___x_3281_; lean_object* v___x_3283_; 
v___x_3281_ = lp_bounded_Bounded_classifyCore(v_00_u03b3_3105_, v_n_3248_, v_val_3272_, v_val_3277_);
lean_dec(v_val_3277_);
lean_dec(v_val_3272_);
lean_dec(v_n_3248_);
lean_dec_ref(v_00_u03b3_3105_);
if (v_isShared_3280_ == 0)
{
lean_ctor_set(v___x_3279_, 0, v___x_3281_);
v___x_3283_ = v___x_3279_;
goto v_reusejp_3282_;
}
else
{
lean_object* v_reuseFailAlloc_3284_; 
v_reuseFailAlloc_3284_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_3284_, 0, v___x_3281_);
v___x_3283_ = v_reuseFailAlloc_3284_;
goto v_reusejp_3282_;
}
v_reusejp_3282_:
{
v___y_3252_ = v___x_3269_;
v___y_3253_ = v___x_3270_;
v___y_3254_ = v___y_3267_;
v___y_3255_ = v___x_3268_;
v___y_3256_ = v___x_3283_;
goto v___jp_3251_;
}
}
}
}
else
{
lean_object* v___x_3286_; 
lean_dec(v_val_3272_);
lean_dec(v_n_3248_);
lean_dec_ref(v_00_u03b3_3105_);
v___x_3286_ = lean_box(0);
v___y_3252_ = v___x_3269_;
v___y_3253_ = v___x_3270_;
v___y_3254_ = v___y_3267_;
v___y_3255_ = v___x_3268_;
v___y_3256_ = v___x_3286_;
goto v___jp_3251_;
}
}
}
}
case 8:
{
lean_object* v_n_3289_; uint8_t v___x_3290_; lean_object* v___x_3291_; uint8_t v___y_3293_; 
v_n_3289_ = lean_ctor_get(v_a_3104_, 0);
lean_inc(v_n_3289_);
lean_dec_ref_known(v_a_3104_, 1);
v___x_3290_ = 8;
v___x_3291_ = lp_bounded_Bounded_SMap_get___redArg(v_00_u03b3_3105_, v_n_3289_);
if (lean_obj_tag(v___x_3291_) == 0)
{
uint8_t v___x_3301_; 
v___x_3301_ = 0;
v___y_3293_ = v___x_3301_;
goto v___jp_3292_;
}
else
{
uint8_t v___x_3302_; 
v___x_3302_ = 1;
v___y_3293_ = v___x_3302_;
goto v___jp_3292_;
}
v___jp_3292_:
{
uint8_t v___x_3294_; uint8_t v___x_3295_; uint8_t v___x_3296_; lean_object* v___x_3297_; uint8_t v___x_3298_; lean_object* v___x_3299_; lean_object* v___x_3300_; 
v___x_3294_ = lp_bounded_Bounded_stClsOf(v___x_3291_);
lean_dec(v___x_3291_);
v___x_3295_ = 0;
v___x_3296_ = lp_bounded_Bounded_tRelOf(v_00_u03b3_3105_, v_n_3289_);
lean_dec(v_n_3289_);
v___x_3297_ = lean_box(0);
v___x_3298_ = 1;
v___x_3299_ = ((lean_object*)(lp_bounded_Bounded_accClsOfOpt___closed__1));
v___x_3300_ = lean_alloc_ctor(0, 3, 11);
lean_ctor_set(v___x_3300_, 0, v___x_3297_);
lean_ctor_set(v___x_3300_, 1, v___x_3299_);
lean_ctor_set(v___x_3300_, 2, v___x_3299_);
lean_ctor_set_uint8(v___x_3300_, sizeof(void*)*3, v___x_3290_);
lean_ctor_set_uint8(v___x_3300_, sizeof(void*)*3 + 1, v___y_3293_);
lean_ctor_set_uint8(v___x_3300_, sizeof(void*)*3 + 2, v___x_3294_);
lean_ctor_set_uint8(v___x_3300_, sizeof(void*)*3 + 3, v___x_3295_);
lean_ctor_set_uint8(v___x_3300_, sizeof(void*)*3 + 4, v___x_3296_);
lean_ctor_set_uint8(v___x_3300_, sizeof(void*)*3 + 5, v___x_3298_);
lean_ctor_set_uint8(v___x_3300_, sizeof(void*)*3 + 6, v___x_3295_);
lean_ctor_set_uint8(v___x_3300_, sizeof(void*)*3 + 7, v___x_3295_);
lean_ctor_set_uint8(v___x_3300_, sizeof(void*)*3 + 8, v___x_3295_);
lean_ctor_set_uint8(v___x_3300_, sizeof(void*)*3 + 9, v___x_3295_);
lean_ctor_set_uint8(v___x_3300_, sizeof(void*)*3 + 10, v___x_3298_);
return v___x_3300_;
}
}
default: 
{
lean_object* v_n_3303_; uint8_t v___x_3304_; lean_object* v___x_3305_; uint8_t v___y_3307_; 
v_n_3303_ = lean_ctor_get(v_a_3104_, 0);
lean_inc(v_n_3303_);
lean_dec_ref_known(v_a_3104_, 1);
v___x_3304_ = 9;
v___x_3305_ = lp_bounded_Bounded_SMap_get___redArg(v_00_u03b3_3105_, v_n_3303_);
if (lean_obj_tag(v___x_3305_) == 0)
{
uint8_t v___x_3318_; 
v___x_3318_ = 0;
v___y_3307_ = v___x_3318_;
goto v___jp_3306_;
}
else
{
uint8_t v___x_3319_; 
v___x_3319_ = 1;
v___y_3307_ = v___x_3319_;
goto v___jp_3306_;
}
v___jp_3306_:
{
uint8_t v___x_3308_; uint8_t v___x_3309_; uint8_t v___x_3310_; lean_object* v___x_3311_; uint8_t v___x_3312_; uint8_t v___x_3313_; uint8_t v___x_3314_; lean_object* v___x_3315_; lean_object* v___x_3316_; lean_object* v___x_3317_; 
v___x_3308_ = lp_bounded_Bounded_stClsOf(v___x_3305_);
v___x_3309_ = lp_bounded_Bounded_retiredOf(v___x_3305_);
v___x_3310_ = 0;
v___x_3311_ = lean_box(0);
v___x_3312_ = 1;
v___x_3313_ = lp_bounded_Bounded_reliedUpon(v_00_u03b3_3105_, v_n_3303_);
lean_dec_ref(v_00_u03b3_3105_);
v___x_3314_ = 0;
v___x_3315_ = lp_bounded_Bounded_accClsOfOpt(v___x_3305_);
v___x_3316_ = ((lean_object*)(lp_bounded_Bounded_accClsOfOpt___closed__1));
v___x_3317_ = lean_alloc_ctor(0, 3, 11);
lean_ctor_set(v___x_3317_, 0, v___x_3311_);
lean_ctor_set(v___x_3317_, 1, v___x_3315_);
lean_ctor_set(v___x_3317_, 2, v___x_3316_);
lean_ctor_set_uint8(v___x_3317_, sizeof(void*)*3, v___x_3304_);
lean_ctor_set_uint8(v___x_3317_, sizeof(void*)*3 + 1, v___y_3307_);
lean_ctor_set_uint8(v___x_3317_, sizeof(void*)*3 + 2, v___x_3308_);
lean_ctor_set_uint8(v___x_3317_, sizeof(void*)*3 + 3, v___x_3309_);
lean_ctor_set_uint8(v___x_3317_, sizeof(void*)*3 + 4, v___x_3310_);
lean_ctor_set_uint8(v___x_3317_, sizeof(void*)*3 + 5, v___x_3312_);
lean_ctor_set_uint8(v___x_3317_, sizeof(void*)*3 + 6, v___x_3313_);
lean_ctor_set_uint8(v___x_3317_, sizeof(void*)*3 + 7, v___x_3314_);
lean_ctor_set_uint8(v___x_3317_, sizeof(void*)*3 + 8, v___x_3314_);
lean_ctor_set_uint8(v___x_3317_, sizeof(void*)*3 + 9, v___x_3314_);
lean_ctor_set_uint8(v___x_3317_, sizeof(void*)*3 + 10, v___x_3312_);
return v___x_3317_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Variant_ctorIdx(uint8_t v_x_3320_){
_start:
{
switch(v_x_3320_)
{
case 0:
{
lean_object* v___x_3321_; 
v___x_3321_ = lean_unsigned_to_nat(0u);
return v___x_3321_;
}
case 1:
{
lean_object* v___x_3322_; 
v___x_3322_ = lean_unsigned_to_nat(1u);
return v___x_3322_;
}
default: 
{
lean_object* v___x_3323_; 
v___x_3323_ = lean_unsigned_to_nat(2u);
return v___x_3323_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Variant_ctorIdx___boxed(lean_object* v_x_3324_){
_start:
{
uint8_t v_x_boxed_3325_; lean_object* v_res_3326_; 
v_x_boxed_3325_ = lean_unbox(v_x_3324_);
v_res_3326_ = lp_bounded_Bounded_Variant_ctorIdx(v_x_boxed_3325_);
return v_res_3326_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Variant_toCtorIdx(uint8_t v_x_3327_){
_start:
{
lean_object* v___x_3328_; 
v___x_3328_ = lp_bounded_Bounded_Variant_ctorIdx(v_x_3327_);
return v___x_3328_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Variant_toCtorIdx___boxed(lean_object* v_x_3329_){
_start:
{
uint8_t v_x_4__boxed_3330_; lean_object* v_res_3331_; 
v_x_4__boxed_3330_ = lean_unbox(v_x_3329_);
v_res_3331_ = lp_bounded_Bounded_Variant_toCtorIdx(v_x_4__boxed_3330_);
return v_res_3331_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Variant_ctorElim___redArg(lean_object* v_k_3332_){
_start:
{
lean_inc(v_k_3332_);
return v_k_3332_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Variant_ctorElim___redArg___boxed(lean_object* v_k_3333_){
_start:
{
lean_object* v_res_3334_; 
v_res_3334_ = lp_bounded_Bounded_Variant_ctorElim___redArg(v_k_3333_);
lean_dec(v_k_3333_);
return v_res_3334_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Variant_ctorElim(lean_object* v_motive_3335_, lean_object* v_ctorIdx_3336_, uint8_t v_t_3337_, lean_object* v_h_3338_, lean_object* v_k_3339_){
_start:
{
lean_inc(v_k_3339_);
return v_k_3339_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Variant_ctorElim___boxed(lean_object* v_motive_3340_, lean_object* v_ctorIdx_3341_, lean_object* v_t_3342_, lean_object* v_h_3343_, lean_object* v_k_3344_){
_start:
{
uint8_t v_t_boxed_3345_; lean_object* v_res_3346_; 
v_t_boxed_3345_ = lean_unbox(v_t_3342_);
v_res_3346_ = lp_bounded_Bounded_Variant_ctorElim(v_motive_3340_, v_ctorIdx_3341_, v_t_boxed_3345_, v_h_3343_, v_k_3344_);
lean_dec(v_k_3344_);
lean_dec(v_ctorIdx_3341_);
return v_res_3346_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Variant_std_elim___redArg(lean_object* v_std_3347_){
_start:
{
lean_inc(v_std_3347_);
return v_std_3347_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Variant_std_elim___redArg___boxed(lean_object* v_std_3348_){
_start:
{
lean_object* v_res_3349_; 
v_res_3349_ = lp_bounded_Bounded_Variant_std_elim___redArg(v_std_3348_);
lean_dec(v_std_3348_);
return v_res_3349_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Variant_std_elim(lean_object* v_motive_3350_, uint8_t v_t_3351_, lean_object* v_h_3352_, lean_object* v_std_3353_){
_start:
{
lean_inc(v_std_3353_);
return v_std_3353_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Variant_std_elim___boxed(lean_object* v_motive_3354_, lean_object* v_t_3355_, lean_object* v_h_3356_, lean_object* v_std_3357_){
_start:
{
uint8_t v_t_boxed_3358_; lean_object* v_res_3359_; 
v_t_boxed_3358_ = lean_unbox(v_t_3355_);
v_res_3359_ = lp_bounded_Bounded_Variant_std_elim(v_motive_3354_, v_t_boxed_3358_, v_h_3356_, v_std_3357_);
lean_dec(v_std_3357_);
return v_res_3359_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Variant_fifoAcc_elim___redArg(lean_object* v_fifoAcc_3360_){
_start:
{
lean_inc(v_fifoAcc_3360_);
return v_fifoAcc_3360_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Variant_fifoAcc_elim___redArg___boxed(lean_object* v_fifoAcc_3361_){
_start:
{
lean_object* v_res_3362_; 
v_res_3362_ = lp_bounded_Bounded_Variant_fifoAcc_elim___redArg(v_fifoAcc_3361_);
lean_dec(v_fifoAcc_3361_);
return v_res_3362_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Variant_fifoAcc_elim(lean_object* v_motive_3363_, uint8_t v_t_3364_, lean_object* v_h_3365_, lean_object* v_fifoAcc_3366_){
_start:
{
lean_inc(v_fifoAcc_3366_);
return v_fifoAcc_3366_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Variant_fifoAcc_elim___boxed(lean_object* v_motive_3367_, lean_object* v_t_3368_, lean_object* v_h_3369_, lean_object* v_fifoAcc_3370_){
_start:
{
uint8_t v_t_boxed_3371_; lean_object* v_res_3372_; 
v_t_boxed_3371_ = lean_unbox(v_t_3368_);
v_res_3372_ = lp_bounded_Bounded_Variant_fifoAcc_elim(v_motive_3367_, v_t_boxed_3371_, v_h_3369_, v_fifoAcc_3370_);
lean_dec(v_fifoAcc_3370_);
return v_res_3372_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Variant_dropAcc_elim___redArg(lean_object* v_dropAcc_3373_){
_start:
{
lean_inc(v_dropAcc_3373_);
return v_dropAcc_3373_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Variant_dropAcc_elim___redArg___boxed(lean_object* v_dropAcc_3374_){
_start:
{
lean_object* v_res_3375_; 
v_res_3375_ = lp_bounded_Bounded_Variant_dropAcc_elim___redArg(v_dropAcc_3374_);
lean_dec(v_dropAcc_3374_);
return v_res_3375_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Variant_dropAcc_elim(lean_object* v_motive_3376_, uint8_t v_t_3377_, lean_object* v_h_3378_, lean_object* v_dropAcc_3379_){
_start:
{
lean_inc(v_dropAcc_3379_);
return v_dropAcc_3379_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Variant_dropAcc_elim___boxed(lean_object* v_motive_3380_, lean_object* v_t_3381_, lean_object* v_h_3382_, lean_object* v_dropAcc_3383_){
_start:
{
uint8_t v_t_boxed_3384_; lean_object* v_res_3385_; 
v_t_boxed_3384_ = lean_unbox(v_t_3381_);
v_res_3385_ = lp_bounded_Bounded_Variant_dropAcc_elim(v_motive_3380_, v_t_boxed_3384_, v_h_3382_, v_dropAcc_3383_);
lean_dec(v_dropAcc_3383_);
return v_res_3385_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_Variant_ofNat(lean_object* v_n_3386_){
_start:
{
lean_object* v___x_3387_; uint8_t v___x_3388_; 
v___x_3387_ = lean_unsigned_to_nat(0u);
v___x_3388_ = lean_nat_dec_le(v_n_3386_, v___x_3387_);
if (v___x_3388_ == 0)
{
lean_object* v___x_3389_; uint8_t v___x_3390_; 
v___x_3389_ = lean_unsigned_to_nat(1u);
v___x_3390_ = lean_nat_dec_le(v_n_3386_, v___x_3389_);
if (v___x_3390_ == 0)
{
uint8_t v___x_3391_; 
v___x_3391_ = 2;
return v___x_3391_;
}
else
{
uint8_t v___x_3392_; 
v___x_3392_ = 1;
return v___x_3392_;
}
}
else
{
uint8_t v___x_3393_; 
v___x_3393_ = 0;
return v___x_3393_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Variant_ofNat___boxed(lean_object* v_n_3394_){
_start:
{
uint8_t v_res_3395_; lean_object* v_r_3396_; 
v_res_3395_ = lp_bounded_Bounded_Variant_ofNat(v_n_3394_);
lean_dec(v_n_3394_);
v_r_3396_ = lean_box(v_res_3395_);
return v_r_3396_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqVariant(uint8_t v_x_3397_, uint8_t v_y_3398_){
_start:
{
lean_object* v___x_3399_; lean_object* v___x_3400_; uint8_t v___x_3401_; 
v___x_3399_ = lp_bounded_Bounded_Variant_ctorIdx(v_x_3397_);
v___x_3400_ = lp_bounded_Bounded_Variant_ctorIdx(v_y_3398_);
v___x_3401_ = lean_nat_dec_eq(v___x_3399_, v___x_3400_);
lean_dec(v___x_3400_);
lean_dec(v___x_3399_);
return v___x_3401_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqVariant___boxed(lean_object* v_x_3402_, lean_object* v_y_3403_){
_start:
{
uint8_t v_x_13__boxed_3404_; uint8_t v_y_14__boxed_3405_; uint8_t v_res_3406_; lean_object* v_r_3407_; 
v_x_13__boxed_3404_ = lean_unbox(v_x_3402_);
v_y_14__boxed_3405_ = lean_unbox(v_y_3403_);
v_res_3406_ = lp_bounded_Bounded_instDecidableEqVariant(v_x_13__boxed_3404_, v_y_14__boxed_3405_);
v_r_3407_ = lean_box(v_res_3406_);
return v_r_3407_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprVariant_repr(uint8_t v_x_3417_, lean_object* v_prec_3418_){
_start:
{
lean_object* v___y_3420_; lean_object* v___y_3427_; lean_object* v___y_3434_; 
switch(v_x_3417_)
{
case 0:
{
lean_object* v___x_3440_; uint8_t v___x_3441_; 
v___x_3440_ = lean_unsigned_to_nat(1024u);
v___x_3441_ = lean_nat_dec_le(v___x_3440_, v_prec_3418_);
if (v___x_3441_ == 0)
{
lean_object* v___x_3442_; 
v___x_3442_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_3420_ = v___x_3442_;
goto v___jp_3419_;
}
else
{
lean_object* v___x_3443_; 
v___x_3443_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_3420_ = v___x_3443_;
goto v___jp_3419_;
}
}
case 1:
{
lean_object* v___x_3444_; uint8_t v___x_3445_; 
v___x_3444_ = lean_unsigned_to_nat(1024u);
v___x_3445_ = lean_nat_dec_le(v___x_3444_, v_prec_3418_);
if (v___x_3445_ == 0)
{
lean_object* v___x_3446_; 
v___x_3446_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_3427_ = v___x_3446_;
goto v___jp_3426_;
}
else
{
lean_object* v___x_3447_; 
v___x_3447_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_3427_ = v___x_3447_;
goto v___jp_3426_;
}
}
default: 
{
lean_object* v___x_3448_; uint8_t v___x_3449_; 
v___x_3448_ = lean_unsigned_to_nat(1024u);
v___x_3449_ = lean_nat_dec_le(v___x_3448_, v_prec_3418_);
if (v___x_3449_ == 0)
{
lean_object* v___x_3450_; 
v___x_3450_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_3434_ = v___x_3450_;
goto v___jp_3433_;
}
else
{
lean_object* v___x_3451_; 
v___x_3451_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_3434_ = v___x_3451_;
goto v___jp_3433_;
}
}
}
v___jp_3419_:
{
lean_object* v___x_3421_; lean_object* v___x_3422_; uint8_t v___x_3423_; lean_object* v___x_3424_; lean_object* v___x_3425_; 
v___x_3421_ = ((lean_object*)(lp_bounded_Bounded_instReprVariant_repr___closed__1));
lean_inc(v___y_3420_);
v___x_3422_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_3422_, 0, v___y_3420_);
lean_ctor_set(v___x_3422_, 1, v___x_3421_);
v___x_3423_ = 0;
v___x_3424_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_3424_, 0, v___x_3422_);
lean_ctor_set_uint8(v___x_3424_, sizeof(void*)*1, v___x_3423_);
v___x_3425_ = l_Repr_addAppParen(v___x_3424_, v_prec_3418_);
return v___x_3425_;
}
v___jp_3426_:
{
lean_object* v___x_3428_; lean_object* v___x_3429_; uint8_t v___x_3430_; lean_object* v___x_3431_; lean_object* v___x_3432_; 
v___x_3428_ = ((lean_object*)(lp_bounded_Bounded_instReprVariant_repr___closed__3));
lean_inc(v___y_3427_);
v___x_3429_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_3429_, 0, v___y_3427_);
lean_ctor_set(v___x_3429_, 1, v___x_3428_);
v___x_3430_ = 0;
v___x_3431_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_3431_, 0, v___x_3429_);
lean_ctor_set_uint8(v___x_3431_, sizeof(void*)*1, v___x_3430_);
v___x_3432_ = l_Repr_addAppParen(v___x_3431_, v_prec_3418_);
return v___x_3432_;
}
v___jp_3433_:
{
lean_object* v___x_3435_; lean_object* v___x_3436_; uint8_t v___x_3437_; lean_object* v___x_3438_; lean_object* v___x_3439_; 
v___x_3435_ = ((lean_object*)(lp_bounded_Bounded_instReprVariant_repr___closed__5));
lean_inc(v___y_3434_);
v___x_3436_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_3436_, 0, v___y_3434_);
lean_ctor_set(v___x_3436_, 1, v___x_3435_);
v___x_3437_ = 0;
v___x_3438_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_3438_, 0, v___x_3436_);
lean_ctor_set_uint8(v___x_3438_, sizeof(void*)*1, v___x_3437_);
v___x_3439_ = l_Repr_addAppParen(v___x_3438_, v_prec_3418_);
return v___x_3439_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprVariant_repr___boxed(lean_object* v_x_3452_, lean_object* v_prec_3453_){
_start:
{
uint8_t v_x_173__boxed_3454_; lean_object* v_res_3455_; 
v_x_173__boxed_3454_ = lean_unbox(v_x_3452_);
v_res_3455_ = lp_bounded_Bounded_instReprVariant_repr(v_x_173__boxed_3454_, v_prec_3453_);
lean_dec(v_prec_3453_);
return v_res_3455_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Dec_ctorIdx(lean_object* v_x_3458_){
_start:
{
if (lean_obj_tag(v_x_3458_) == 0)
{
lean_object* v___x_3459_; 
v___x_3459_ = lean_unsigned_to_nat(0u);
return v___x_3459_;
}
else
{
lean_object* v___x_3460_; 
v___x_3460_ = lean_unsigned_to_nat(1u);
return v___x_3460_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Dec_ctorIdx___boxed(lean_object* v_x_3461_){
_start:
{
lean_object* v_res_3462_; 
v_res_3462_ = lp_bounded_Bounded_Dec_ctorIdx(v_x_3461_);
lean_dec(v_x_3461_);
return v_res_3462_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Dec_ctorElim___redArg(lean_object* v_t_3463_, lean_object* v_k_3464_){
_start:
{
if (lean_obj_tag(v_t_3463_) == 0)
{
return v_k_3464_;
}
else
{
uint8_t v_v_3465_; lean_object* v___x_3466_; lean_object* v___x_3467_; 
v_v_3465_ = lean_ctor_get_uint8(v_t_3463_, 0);
v___x_3466_ = lean_box(v_v_3465_);
v___x_3467_ = lean_apply_1(v_k_3464_, v___x_3466_);
return v___x_3467_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Dec_ctorElim___redArg___boxed(lean_object* v_t_3468_, lean_object* v_k_3469_){
_start:
{
lean_object* v_res_3470_; 
v_res_3470_ = lp_bounded_Bounded_Dec_ctorElim___redArg(v_t_3468_, v_k_3469_);
lean_dec(v_t_3468_);
return v_res_3470_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Dec_ctorElim(lean_object* v_motive_3471_, lean_object* v_ctorIdx_3472_, lean_object* v_t_3473_, lean_object* v_h_3474_, lean_object* v_k_3475_){
_start:
{
lean_object* v___x_3476_; 
v___x_3476_ = lp_bounded_Bounded_Dec_ctorElim___redArg(v_t_3473_, v_k_3475_);
return v___x_3476_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Dec_ctorElim___boxed(lean_object* v_motive_3477_, lean_object* v_ctorIdx_3478_, lean_object* v_t_3479_, lean_object* v_h_3480_, lean_object* v_k_3481_){
_start:
{
lean_object* v_res_3482_; 
v_res_3482_ = lp_bounded_Bounded_Dec_ctorElim(v_motive_3477_, v_ctorIdx_3478_, v_t_3479_, v_h_3480_, v_k_3481_);
lean_dec(v_t_3479_);
lean_dec(v_ctorIdx_3478_);
return v_res_3482_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Dec_disabled_elim___redArg(lean_object* v_t_3483_, lean_object* v_disabled_3484_){
_start:
{
lean_object* v___x_3485_; 
v___x_3485_ = lp_bounded_Bounded_Dec_ctorElim___redArg(v_t_3483_, v_disabled_3484_);
return v___x_3485_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Dec_disabled_elim___redArg___boxed(lean_object* v_t_3486_, lean_object* v_disabled_3487_){
_start:
{
lean_object* v_res_3488_; 
v_res_3488_ = lp_bounded_Bounded_Dec_disabled_elim___redArg(v_t_3486_, v_disabled_3487_);
lean_dec(v_t_3486_);
return v_res_3488_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Dec_disabled_elim(lean_object* v_motive_3489_, lean_object* v_t_3490_, lean_object* v_h_3491_, lean_object* v_disabled_3492_){
_start:
{
lean_object* v___x_3493_; 
v___x_3493_ = lp_bounded_Bounded_Dec_ctorElim___redArg(v_t_3490_, v_disabled_3492_);
return v___x_3493_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Dec_disabled_elim___boxed(lean_object* v_motive_3494_, lean_object* v_t_3495_, lean_object* v_h_3496_, lean_object* v_disabled_3497_){
_start:
{
lean_object* v_res_3498_; 
v_res_3498_ = lp_bounded_Bounded_Dec_disabled_elim(v_motive_3494_, v_t_3495_, v_h_3496_, v_disabled_3497_);
lean_dec(v_t_3495_);
return v_res_3498_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Dec_fire_elim___redArg(lean_object* v_t_3499_, lean_object* v_fire_3500_){
_start:
{
lean_object* v___x_3501_; 
v___x_3501_ = lp_bounded_Bounded_Dec_ctorElim___redArg(v_t_3499_, v_fire_3500_);
return v___x_3501_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Dec_fire_elim___redArg___boxed(lean_object* v_t_3502_, lean_object* v_fire_3503_){
_start:
{
lean_object* v_res_3504_; 
v_res_3504_ = lp_bounded_Bounded_Dec_fire_elim___redArg(v_t_3502_, v_fire_3503_);
lean_dec(v_t_3502_);
return v_res_3504_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Dec_fire_elim(lean_object* v_motive_3505_, lean_object* v_t_3506_, lean_object* v_h_3507_, lean_object* v_fire_3508_){
_start:
{
lean_object* v___x_3509_; 
v___x_3509_ = lp_bounded_Bounded_Dec_ctorElim___redArg(v_t_3506_, v_fire_3508_);
return v___x_3509_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Dec_fire_elim___boxed(lean_object* v_motive_3510_, lean_object* v_t_3511_, lean_object* v_h_3512_, lean_object* v_fire_3513_){
_start:
{
lean_object* v_res_3514_; 
v_res_3514_ = lp_bounded_Bounded_Dec_fire_elim(v_motive_3510_, v_t_3511_, v_h_3512_, v_fire_3513_);
lean_dec(v_t_3511_);
return v_res_3514_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqDec_decEq(lean_object* v_x_3515_, lean_object* v_x_3516_){
_start:
{
if (lean_obj_tag(v_x_3515_) == 0)
{
if (lean_obj_tag(v_x_3516_) == 0)
{
uint8_t v___x_3517_; 
v___x_3517_ = 1;
return v___x_3517_;
}
else
{
uint8_t v___x_3518_; 
v___x_3518_ = 0;
return v___x_3518_;
}
}
else
{
uint8_t v_v_3519_; uint8_t v___x_3520_; 
v_v_3519_ = lean_ctor_get_uint8(v_x_3515_, 0);
v___x_3520_ = 0;
if (lean_obj_tag(v_x_3516_) == 0)
{
return v___x_3520_;
}
else
{
uint8_t v_v_3521_; uint8_t v___x_3522_; 
v_v_3521_ = lean_ctor_get_uint8(v_x_3516_, 0);
v___x_3522_ = lp_bounded_Bounded_instDecidableEqVariant(v_v_3519_, v_v_3521_);
if (v___x_3522_ == 0)
{
return v___x_3520_;
}
else
{
return v___x_3522_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqDec_decEq___boxed(lean_object* v_x_3523_, lean_object* v_x_3524_){
_start:
{
uint8_t v_res_3525_; lean_object* v_r_3526_; 
v_res_3525_ = lp_bounded_Bounded_instDecidableEqDec_decEq(v_x_3523_, v_x_3524_);
lean_dec(v_x_3524_);
lean_dec(v_x_3523_);
v_r_3526_ = lean_box(v_res_3525_);
return v_r_3526_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqDec(lean_object* v_x_3527_, lean_object* v_x_3528_){
_start:
{
uint8_t v___x_3529_; 
v___x_3529_ = lp_bounded_Bounded_instDecidableEqDec_decEq(v_x_3527_, v_x_3528_);
return v___x_3529_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqDec___boxed(lean_object* v_x_3530_, lean_object* v_x_3531_){
_start:
{
uint8_t v_res_3532_; lean_object* v_r_3533_; 
v_res_3532_ = lp_bounded_Bounded_instDecidableEqDec(v_x_3530_, v_x_3531_);
lean_dec(v_x_3531_);
lean_dec(v_x_3530_);
v_r_3533_ = lean_box(v_res_3532_);
return v_r_3533_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprDec_repr(lean_object* v_x_3543_, lean_object* v_prec_3544_){
_start:
{
lean_object* v___y_3546_; 
if (lean_obj_tag(v_x_3543_) == 0)
{
lean_object* v___x_3552_; uint8_t v___x_3553_; 
v___x_3552_ = lean_unsigned_to_nat(1024u);
v___x_3553_ = lean_nat_dec_le(v___x_3552_, v_prec_3544_);
if (v___x_3553_ == 0)
{
lean_object* v___x_3554_; 
v___x_3554_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_3546_ = v___x_3554_;
goto v___jp_3545_;
}
else
{
lean_object* v___x_3555_; 
v___x_3555_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_3546_ = v___x_3555_;
goto v___jp_3545_;
}
}
else
{
uint8_t v_v_3556_; lean_object* v___y_3558_; lean_object* v___x_3567_; uint8_t v___x_3568_; 
v_v_3556_ = lean_ctor_get_uint8(v_x_3543_, 0);
v___x_3567_ = lean_unsigned_to_nat(1024u);
v___x_3568_ = lean_nat_dec_le(v___x_3567_, v_prec_3544_);
if (v___x_3568_ == 0)
{
lean_object* v___x_3569_; 
v___x_3569_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_3558_ = v___x_3569_;
goto v___jp_3557_;
}
else
{
lean_object* v___x_3570_; 
v___x_3570_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_3558_ = v___x_3570_;
goto v___jp_3557_;
}
v___jp_3557_:
{
lean_object* v___x_3559_; lean_object* v___x_3560_; lean_object* v___x_3561_; lean_object* v___x_3562_; lean_object* v___x_3563_; uint8_t v___x_3564_; lean_object* v___x_3565_; lean_object* v___x_3566_; 
v___x_3559_ = ((lean_object*)(lp_bounded_Bounded_instReprDec_repr___closed__4));
v___x_3560_ = lean_unsigned_to_nat(1024u);
v___x_3561_ = lp_bounded_Bounded_instReprVariant_repr(v_v_3556_, v___x_3560_);
v___x_3562_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_3562_, 0, v___x_3559_);
lean_ctor_set(v___x_3562_, 1, v___x_3561_);
lean_inc(v___y_3558_);
v___x_3563_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_3563_, 0, v___y_3558_);
lean_ctor_set(v___x_3563_, 1, v___x_3562_);
v___x_3564_ = 0;
v___x_3565_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_3565_, 0, v___x_3563_);
lean_ctor_set_uint8(v___x_3565_, sizeof(void*)*1, v___x_3564_);
v___x_3566_ = l_Repr_addAppParen(v___x_3565_, v_prec_3544_);
return v___x_3566_;
}
}
v___jp_3545_:
{
lean_object* v___x_3547_; lean_object* v___x_3548_; uint8_t v___x_3549_; lean_object* v___x_3550_; lean_object* v___x_3551_; 
v___x_3547_ = ((lean_object*)(lp_bounded_Bounded_instReprDec_repr___closed__1));
lean_inc(v___y_3546_);
v___x_3548_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_3548_, 0, v___y_3546_);
lean_ctor_set(v___x_3548_, 1, v___x_3547_);
v___x_3549_ = 0;
v___x_3550_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_3550_, 0, v___x_3548_);
lean_ctor_set_uint8(v___x_3550_, sizeof(void*)*1, v___x_3549_);
v___x_3551_ = l_Repr_addAppParen(v___x_3550_, v_prec_3544_);
return v___x_3551_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprDec_repr___boxed(lean_object* v_x_3571_, lean_object* v_prec_3572_){
_start:
{
lean_object* v_res_3573_; 
v_res_3573_ = lp_bounded_Bounded_instReprDec_repr(v_x_3571_, v_prec_3572_);
lean_dec(v_prec_3572_);
lean_dec(v_x_3571_);
return v_res_3573_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumDec___lam__0(uint8_t v_v_3589_){
_start:
{
lean_object* v___x_3590_; 
v___x_3590_ = lean_alloc_ctor(1, 0, 1);
lean_ctor_set_uint8(v___x_3590_, 0, v_v_3589_);
return v___x_3590_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instFinEnumDec___lam__0___boxed(lean_object* v_v_3591_){
_start:
{
uint8_t v_v_boxed_3592_; lean_object* v_res_3593_; 
v_v_boxed_3592_ = lean_unbox(v_v_3591_);
v_res_3593_ = lp_bounded_Bounded_instFinEnumDec___lam__0(v_v_boxed_3592_);
return v_res_3593_;
}
}
static lean_object* _init_lp_bounded_Bounded_instFinEnumDec___closed__1(void){
_start:
{
lean_object* v___x_3595_; lean_object* v___x_3596_; lean_object* v___f_3597_; lean_object* v___x_3598_; 
v___x_3595_ = lean_box(0);
v___x_3596_ = ((lean_object*)(lp_bounded_Bounded_instFinEnumVariant___closed__2));
v___f_3597_ = ((lean_object*)(lp_bounded_Bounded_instFinEnumDec___closed__0));
v___x_3598_ = l_List_mapTR_loop___redArg(v___f_3597_, v___x_3596_, v___x_3595_);
return v___x_3598_;
}
}
static lean_object* _init_lp_bounded_Bounded_instFinEnumDec___closed__2(void){
_start:
{
lean_object* v___x_3599_; lean_object* v___x_3600_; lean_object* v___x_3601_; 
v___x_3599_ = lean_obj_once(&lp_bounded_Bounded_instFinEnumDec___closed__1, &lp_bounded_Bounded_instFinEnumDec___closed__1_once, _init_lp_bounded_Bounded_instFinEnumDec___closed__1);
v___x_3600_ = lean_box(0);
v___x_3601_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_3601_, 0, v___x_3600_);
lean_ctor_set(v___x_3601_, 1, v___x_3599_);
return v___x_3601_;
}
}
static lean_object* _init_lp_bounded_Bounded_instFinEnumDec(void){
_start:
{
lean_object* v___x_3602_; 
v___x_3602_ = lean_obj_once(&lp_bounded_Bounded_instFinEnumDec___closed__2, &lp_bounded_Bounded_instFinEnumDec___closed__2_once, _init_lp_bounded_Bounded_instFinEnumDec___closed__2);
return v___x_3602_;
}
}
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_allDecs_spec__0(lean_object* v_a_3603_, lean_object* v_a_3604_){
_start:
{
if (lean_obj_tag(v_a_3603_) == 0)
{
lean_object* v___x_3605_; 
v___x_3605_ = l_List_reverse___redArg(v_a_3604_);
return v___x_3605_;
}
else
{
lean_object* v_head_3606_; lean_object* v_tail_3607_; lean_object* v___x_3609_; uint8_t v_isShared_3610_; uint8_t v_isSharedCheck_3617_; 
v_head_3606_ = lean_ctor_get(v_a_3603_, 0);
v_tail_3607_ = lean_ctor_get(v_a_3603_, 1);
v_isSharedCheck_3617_ = !lean_is_exclusive(v_a_3603_);
if (v_isSharedCheck_3617_ == 0)
{
v___x_3609_ = v_a_3603_;
v_isShared_3610_ = v_isSharedCheck_3617_;
goto v_resetjp_3608_;
}
else
{
lean_inc(v_tail_3607_);
lean_inc(v_head_3606_);
lean_dec(v_a_3603_);
v___x_3609_ = lean_box(0);
v_isShared_3610_ = v_isSharedCheck_3617_;
goto v_resetjp_3608_;
}
v_resetjp_3608_:
{
lean_object* v___x_3611_; uint8_t v___x_3612_; lean_object* v___x_3614_; 
v___x_3611_ = lean_alloc_ctor(1, 0, 1);
v___x_3612_ = lean_unbox(v_head_3606_);
lean_dec(v_head_3606_);
lean_ctor_set_uint8(v___x_3611_, 0, v___x_3612_);
if (v_isShared_3610_ == 0)
{
lean_ctor_set(v___x_3609_, 1, v_a_3604_);
lean_ctor_set(v___x_3609_, 0, v___x_3611_);
v___x_3614_ = v___x_3609_;
goto v_reusejp_3613_;
}
else
{
lean_object* v_reuseFailAlloc_3616_; 
v_reuseFailAlloc_3616_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_3616_, 0, v___x_3611_);
lean_ctor_set(v_reuseFailAlloc_3616_, 1, v_a_3604_);
v___x_3614_ = v_reuseFailAlloc_3616_;
goto v_reusejp_3613_;
}
v_reusejp_3613_:
{
v_a_3603_ = v_tail_3607_;
v_a_3604_ = v___x_3614_;
goto _start;
}
}
}
}
}
static lean_object* _init_lp_bounded_Bounded_allDecs___closed__0(void){
_start:
{
lean_object* v___x_3618_; lean_object* v___x_3619_; lean_object* v___x_3620_; 
v___x_3618_ = lean_box(0);
v___x_3619_ = ((lean_object*)(lp_bounded_Bounded_instFinEnumVariant___closed__2));
v___x_3620_ = lp_bounded_List_mapTR_loop___at___00Bounded_allDecs_spec__0(v___x_3619_, v___x_3618_);
return v___x_3620_;
}
}
static lean_object* _init_lp_bounded_Bounded_allDecs___closed__1(void){
_start:
{
lean_object* v___x_3621_; lean_object* v___x_3622_; lean_object* v___x_3623_; 
v___x_3621_ = lean_obj_once(&lp_bounded_Bounded_allDecs___closed__0, &lp_bounded_Bounded_allDecs___closed__0_once, _init_lp_bounded_Bounded_allDecs___closed__0);
v___x_3622_ = lean_box(0);
v___x_3623_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_3623_, 0, v___x_3622_);
lean_ctor_set(v___x_3623_, 1, v___x_3621_);
return v___x_3623_;
}
}
static lean_object* _init_lp_bounded_Bounded_allDecs(void){
_start:
{
lean_object* v___x_3624_; 
v___x_3624_ = lean_obj_once(&lp_bounded_Bounded_allDecs___closed__1, &lp_bounded_Bounded_allDecs___closed__1_once, _init_lp_bounded_Bounded_allDecs___closed__1);
return v___x_3624_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_headOkB(lean_object* v_x_3625_){
_start:
{
if (lean_obj_tag(v_x_3625_) == 1)
{
lean_object* v_val_3626_; 
v_val_3626_ = lean_ctor_get(v_x_3625_, 0);
switch(lean_obj_tag(v_val_3626_))
{
case 0:
{
uint8_t v___x_3627_; 
v___x_3627_ = 1;
return v___x_3627_;
}
case 2:
{
uint8_t v___x_3628_; 
v___x_3628_ = 1;
return v___x_3628_;
}
case 3:
{
uint8_t v___x_3629_; 
v___x_3629_ = 1;
return v___x_3629_;
}
case 4:
{
uint8_t v___x_3630_; 
v___x_3630_ = 1;
return v___x_3630_;
}
case 6:
{
uint8_t v___x_3631_; 
v___x_3631_ = 1;
return v___x_3631_;
}
default: 
{
uint8_t v___x_3632_; 
v___x_3632_ = 0;
return v___x_3632_;
}
}
}
else
{
uint8_t v___x_3633_; 
v___x_3633_ = 0;
return v___x_3633_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_headOkB___boxed(lean_object* v_x_3634_){
_start:
{
uint8_t v_res_3635_; lean_object* v_r_3636_; 
v_res_3635_ = lp_bounded_Bounded_headOkB(v_x_3634_);
lean_dec(v_x_3634_);
v_r_3636_ = lean_box(v_res_3635_);
return v_r_3636_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_headFailB(lean_object* v_x_3637_){
_start:
{
if (lean_obj_tag(v_x_3637_) == 1)
{
lean_object* v_val_3638_; 
v_val_3638_ = lean_ctor_get(v_x_3637_, 0);
switch(lean_obj_tag(v_val_3638_))
{
case 1:
{
uint8_t v___x_3639_; 
v___x_3639_ = 1;
return v___x_3639_;
}
case 5:
{
uint8_t v___x_3640_; 
v___x_3640_ = 1;
return v___x_3640_;
}
case 7:
{
uint8_t v___x_3641_; 
v___x_3641_ = 1;
return v___x_3641_;
}
case 8:
{
uint8_t v___x_3642_; 
v___x_3642_ = 1;
return v___x_3642_;
}
default: 
{
uint8_t v___x_3643_; 
v___x_3643_ = 0;
return v___x_3643_;
}
}
}
else
{
uint8_t v___x_3644_; 
v___x_3644_ = 0;
return v___x_3644_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_headFailB___boxed(lean_object* v_x_3645_){
_start:
{
uint8_t v_res_3646_; lean_object* v_r_3647_; 
v_res_3646_ = lp_bounded_Bounded_headFailB(v_x_3645_);
lean_dec(v_x_3645_);
v_r_3647_ = lean_box(v_res_3646_);
return v_r_3647_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_enabledS(lean_object* v_s_3648_){
_start:
{
uint8_t v_rule_3649_; uint8_t v_present_3650_; uint8_t v_stCls_3651_; uint8_t v_retiredB_3652_; uint8_t v_tRel_3653_; lean_object* v_headStep_3654_; uint8_t v_remEmpty_3655_; uint8_t v_reliedB_3656_; uint8_t v_hasChild_3657_; uint8_t v_slotFree_3658_; uint8_t v_provConf_3659_; uint8_t v_parentLive_3660_; uint8_t v___y_3662_; uint8_t v___y_3665_; 
v_rule_3649_ = lean_ctor_get_uint8(v_s_3648_, sizeof(void*)*3);
v_present_3650_ = lean_ctor_get_uint8(v_s_3648_, sizeof(void*)*3 + 1);
v_stCls_3651_ = lean_ctor_get_uint8(v_s_3648_, sizeof(void*)*3 + 2);
v_retiredB_3652_ = lean_ctor_get_uint8(v_s_3648_, sizeof(void*)*3 + 3);
v_tRel_3653_ = lean_ctor_get_uint8(v_s_3648_, sizeof(void*)*3 + 4);
v_headStep_3654_ = lean_ctor_get(v_s_3648_, 0);
v_remEmpty_3655_ = lean_ctor_get_uint8(v_s_3648_, sizeof(void*)*3 + 5);
v_reliedB_3656_ = lean_ctor_get_uint8(v_s_3648_, sizeof(void*)*3 + 6);
v_hasChild_3657_ = lean_ctor_get_uint8(v_s_3648_, sizeof(void*)*3 + 7);
v_slotFree_3658_ = lean_ctor_get_uint8(v_s_3648_, sizeof(void*)*3 + 8);
v_provConf_3659_ = lean_ctor_get_uint8(v_s_3648_, sizeof(void*)*3 + 9);
v_parentLive_3660_ = lean_ctor_get_uint8(v_s_3648_, sizeof(void*)*3 + 10);
switch(v_rule_3649_)
{
case 0:
{
if (v_slotFree_3658_ == 0)
{
return v_slotFree_3658_;
}
else
{
if (v_provConf_3659_ == 0)
{
return v_parentLive_3660_;
}
else
{
uint8_t v___x_3667_; 
v___x_3667_ = 0;
return v___x_3667_;
}
}
}
case 1:
{
return v_present_3650_;
}
case 2:
{
if (v_present_3650_ == 0)
{
return v_present_3650_;
}
else
{
if (v_retiredB_3652_ == 0)
{
return v_retiredB_3652_;
}
else
{
uint8_t v___x_3668_; uint8_t v___x_3669_; 
v___x_3668_ = 1;
v___x_3669_ = lp_bounded_Bounded_instDecidableEqStCls(v_stCls_3651_, v___x_3668_);
if (v___x_3669_ == 0)
{
uint8_t v___x_3670_; uint8_t v___x_3671_; 
v___x_3670_ = 2;
v___x_3671_ = lp_bounded_Bounded_instDecidableEqStCls(v_stCls_3651_, v___x_3670_);
v___y_3662_ = v___x_3671_;
goto v___jp_3661_;
}
else
{
v___y_3662_ = v___x_3669_;
goto v___jp_3661_;
}
}
}
}
case 3:
{
if (v_present_3650_ == 0)
{
return v_present_3650_;
}
else
{
uint8_t v___x_3672_; uint8_t v___x_3673_; 
v___x_3672_ = 1;
v___x_3673_ = lp_bounded_Bounded_instDecidableEqStCls(v_stCls_3651_, v___x_3672_);
if (v___x_3673_ == 0)
{
return v___x_3673_;
}
else
{
uint8_t v___x_3674_; uint8_t v___x_3675_; 
v___x_3674_ = 2;
v___x_3675_ = lp_bounded_Bounded_instDecidableEqTRel(v_tRel_3653_, v___x_3674_);
return v___x_3675_;
}
}
}
case 4:
{
if (v_present_3650_ == 0)
{
return v_present_3650_;
}
else
{
uint8_t v___x_3676_; uint8_t v___x_3677_; 
v___x_3676_ = 3;
v___x_3677_ = lp_bounded_Bounded_instDecidableEqStCls(v_stCls_3651_, v___x_3676_);
if (v___x_3677_ == 0)
{
return v___x_3677_;
}
else
{
uint8_t v___x_3678_; uint8_t v___x_3679_; 
v___x_3678_ = 1;
v___x_3679_ = lp_bounded_Bounded_instDecidableEqTRel(v_tRel_3653_, v___x_3678_);
if (v___x_3679_ == 0)
{
return v___x_3679_;
}
else
{
if (v_remEmpty_3655_ == 0)
{
uint8_t v___x_3680_; 
v___x_3680_ = lp_bounded_Bounded_headOkB(v_headStep_3654_);
return v___x_3680_;
}
else
{
uint8_t v___x_3681_; 
v___x_3681_ = 0;
return v___x_3681_;
}
}
}
}
}
case 5:
{
if (v_present_3650_ == 0)
{
return v_present_3650_;
}
else
{
uint8_t v___x_3682_; uint8_t v___x_3683_; 
v___x_3682_ = 3;
v___x_3683_ = lp_bounded_Bounded_instDecidableEqStCls(v_stCls_3651_, v___x_3682_);
if (v___x_3683_ == 0)
{
return v___x_3683_;
}
else
{
uint8_t v___x_3684_; uint8_t v___x_3685_; 
v___x_3684_ = 1;
v___x_3685_ = lp_bounded_Bounded_instDecidableEqTRel(v_tRel_3653_, v___x_3684_);
if (v___x_3685_ == 0)
{
return v___x_3685_;
}
else
{
return v_remEmpty_3655_;
}
}
}
}
case 6:
{
if (v_present_3650_ == 0)
{
return v_present_3650_;
}
else
{
uint8_t v___x_3686_; uint8_t v___x_3687_; 
v___x_3686_ = 3;
v___x_3687_ = lp_bounded_Bounded_instDecidableEqStCls(v_stCls_3651_, v___x_3686_);
if (v___x_3687_ == 0)
{
return v___x_3687_;
}
else
{
uint8_t v___x_3688_; uint8_t v___x_3689_; 
v___x_3688_ = 1;
v___x_3689_ = lp_bounded_Bounded_instDecidableEqTRel(v_tRel_3653_, v___x_3688_);
if (v___x_3689_ == 0)
{
return v___x_3687_;
}
else
{
uint8_t v___x_3690_; 
v___x_3690_ = 0;
return v___x_3690_;
}
}
}
}
case 7:
{
if (v_present_3650_ == 0)
{
return v_present_3650_;
}
else
{
uint8_t v___x_3691_; uint8_t v___x_3692_; 
v___x_3691_ = 3;
v___x_3692_ = lp_bounded_Bounded_instDecidableEqStCls(v_stCls_3651_, v___x_3691_);
if (v___x_3692_ == 0)
{
return v___x_3692_;
}
else
{
uint8_t v___x_3693_; uint8_t v___x_3694_; 
v___x_3693_ = 1;
v___x_3694_ = lp_bounded_Bounded_instDecidableEqTRel(v_tRel_3653_, v___x_3693_);
if (v___x_3694_ == 0)
{
return v___x_3694_;
}
else
{
if (v_remEmpty_3655_ == 0)
{
uint8_t v___x_3695_; 
v___x_3695_ = lp_bounded_Bounded_headFailB(v_headStep_3654_);
return v___x_3695_;
}
else
{
uint8_t v___x_3696_; 
v___x_3696_ = 0;
return v___x_3696_;
}
}
}
}
}
case 8:
{
if (v_present_3650_ == 0)
{
return v_present_3650_;
}
else
{
uint8_t v___x_3697_; uint8_t v___x_3698_; 
v___x_3697_ = 4;
v___x_3698_ = lp_bounded_Bounded_instDecidableEqStCls(v_stCls_3651_, v___x_3697_);
if (v___x_3698_ == 0)
{
return v___x_3698_;
}
else
{
uint8_t v___x_3699_; uint8_t v___x_3700_; 
v___x_3699_ = 1;
v___x_3700_ = lp_bounded_Bounded_instDecidableEqTRel(v_tRel_3653_, v___x_3699_);
if (v___x_3700_ == 0)
{
return v___x_3698_;
}
else
{
uint8_t v___x_3701_; 
v___x_3701_ = 0;
return v___x_3701_;
}
}
}
}
default: 
{
if (v_present_3650_ == 0)
{
return v_present_3650_;
}
else
{
uint8_t v___x_3702_; uint8_t v___x_3703_; 
v___x_3702_ = 5;
v___x_3703_ = lp_bounded_Bounded_instDecidableEqStCls(v_stCls_3651_, v___x_3702_);
if (v___x_3703_ == 0)
{
uint8_t v___x_3704_; uint8_t v___x_3705_; 
v___x_3704_ = 6;
v___x_3705_ = lp_bounded_Bounded_instDecidableEqStCls(v_stCls_3651_, v___x_3704_);
v___y_3665_ = v___x_3705_;
goto v___jp_3664_;
}
else
{
v___y_3665_ = v___x_3703_;
goto v___jp_3664_;
}
}
}
}
v___jp_3661_:
{
if (v___y_3662_ == 0)
{
return v___y_3662_;
}
else
{
if (v_hasChild_3657_ == 0)
{
return v___y_3662_;
}
else
{
uint8_t v___x_3663_; 
v___x_3663_ = 0;
return v___x_3663_;
}
}
}
v___jp_3664_:
{
if (v___y_3665_ == 0)
{
return v___y_3665_;
}
else
{
if (v_reliedB_3656_ == 0)
{
return v___y_3665_;
}
else
{
uint8_t v___x_3666_; 
v___x_3666_ = 0;
return v___x_3666_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_enabledS___boxed(lean_object* v_s_3706_){
_start:
{
uint8_t v_res_3707_; lean_object* v_r_3708_; 
v_res_3707_ = lp_bounded_Bounded_enabledS(v_s_3706_);
lean_dec_ref(v_s_3706_);
v_r_3708_ = lean_box(v_res_3707_);
return v_r_3708_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_fS(lean_object* v_s_3711_){
_start:
{
uint8_t v___x_3712_; 
v___x_3712_ = lp_bounded_Bounded_enabledS(v_s_3711_);
if (v___x_3712_ == 0)
{
lean_object* v___x_3713_; 
v___x_3713_ = lean_box(0);
return v___x_3713_;
}
else
{
lean_object* v___x_3714_; 
v___x_3714_ = ((lean_object*)(lp_bounded_Bounded_fS___closed__0));
return v___x_3714_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_fS___boxed(lean_object* v_s_3715_){
_start:
{
lean_object* v_res_3716_; 
v_res_3716_ = lp_bounded_Bounded_fS(v_s_3715_);
lean_dec_ref(v_s_3715_);
return v_res_3716_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_freshFiber(lean_object* v_c_3721_, lean_object* v_parent_3722_){
_start:
{
uint8_t v___x_3723_; lean_object* v___x_3724_; lean_object* v___x_3725_; lean_object* v___x_3726_; 
v___x_3723_ = 0;
v___x_3724_ = ((lean_object*)(lp_bounded_Bounded_freshFiber___closed__0));
v___x_3725_ = ((lean_object*)(lp_bounded_Bounded_freshFiber___closed__1));
v___x_3726_ = lean_alloc_ctor(0, 4, 1);
lean_ctor_set(v___x_3726_, 0, v_c_3721_);
lean_ctor_set(v___x_3726_, 1, v_parent_3722_);
lean_ctor_set(v___x_3726_, 2, v___x_3724_);
lean_ctor_set(v___x_3726_, 3, v___x_3725_);
lean_ctor_set_uint8(v___x_3726_, sizeof(void*)*4, v___x_3723_);
return v___x_3726_;
}
}
static lean_object* _init_lp_bounded_Bounded_childComp___closed__1(void){
_start:
{
lean_object* v___x_3731_; lean_object* v___x_3732_; lean_object* v___x_3733_; 
v___x_3731_ = lean_unsigned_to_nat(2u);
v___x_3732_ = lean_unsigned_to_nat(0u);
v___x_3733_ = lean_nat_mod(v___x_3732_, v___x_3731_);
return v___x_3733_;
}
}
static lean_object* _init_lp_bounded_Bounded_childComp___closed__2(void){
_start:
{
lean_object* v___x_3734_; lean_object* v___x_3735_; 
v___x_3734_ = lean_obj_once(&lp_bounded_Bounded_childComp___closed__1, &lp_bounded_Bounded_childComp___closed__1_once, _init_lp_bounded_Bounded_childComp___closed__1);
v___x_3735_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_3735_, 0, v___x_3734_);
return v___x_3735_;
}
}
static lean_object* _init_lp_bounded_Bounded_childComp___closed__3(void){
_start:
{
lean_object* v___x_3736_; lean_object* v___x_3737_; 
v___x_3736_ = lean_obj_once(&lp_bounded_Bounded_childComp___closed__1, &lp_bounded_Bounded_childComp___closed__1_once, _init_lp_bounded_Bounded_childComp___closed__1);
v___x_3737_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_3737_, 0, v___x_3736_);
return v___x_3737_;
}
}
static lean_object* _init_lp_bounded_Bounded_childComp___closed__5(void){
_start:
{
lean_object* v___x_3741_; lean_object* v___x_3742_; lean_object* v___x_3743_; 
v___x_3741_ = ((lean_object*)(lp_bounded_Bounded_childComp___closed__4));
v___x_3742_ = lean_obj_once(&lp_bounded_Bounded_childComp___closed__3, &lp_bounded_Bounded_childComp___closed__3_once, _init_lp_bounded_Bounded_childComp___closed__3);
v___x_3743_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_3743_, 0, v___x_3742_);
lean_ctor_set(v___x_3743_, 1, v___x_3741_);
return v___x_3743_;
}
}
static lean_object* _init_lp_bounded_Bounded_childComp___closed__6(void){
_start:
{
lean_object* v___x_3744_; lean_object* v___x_3745_; lean_object* v___x_3746_; 
v___x_3744_ = lean_obj_once(&lp_bounded_Bounded_childComp___closed__5, &lp_bounded_Bounded_childComp___closed__5_once, _init_lp_bounded_Bounded_childComp___closed__5);
v___x_3745_ = lean_obj_once(&lp_bounded_Bounded_childComp___closed__2, &lp_bounded_Bounded_childComp___closed__2_once, _init_lp_bounded_Bounded_childComp___closed__2);
v___x_3746_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_3746_, 0, v___x_3745_);
lean_ctor_set(v___x_3746_, 1, v___x_3744_);
return v___x_3746_;
}
}
static lean_object* _init_lp_bounded_Bounded_childComp___closed__7(void){
_start:
{
lean_object* v___x_3747_; lean_object* v___x_3748_; lean_object* v___x_3749_; 
v___x_3747_ = lean_obj_once(&lp_bounded_Bounded_childComp___closed__6, &lp_bounded_Bounded_childComp___closed__6_once, _init_lp_bounded_Bounded_childComp___closed__6);
v___x_3748_ = ((lean_object*)(lp_bounded_Bounded_childComp___closed__0));
v___x_3749_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_3749_, 0, v___x_3748_);
lean_ctor_set(v___x_3749_, 1, v___x_3748_);
lean_ctor_set(v___x_3749_, 2, v___x_3747_);
return v___x_3749_;
}
}
static lean_object* _init_lp_bounded_Bounded_childComp(void){
_start:
{
lean_object* v___x_3750_; 
v___x_3750_ = lean_obj_once(&lp_bounded_Bounded_childComp___closed__7, &lp_bounded_Bounded_childComp___closed__7_once, _init_lp_bounded_Bounded_childComp___closed__7);
return v___x_3750_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_execStep(lean_object* v_00_u03b3_3751_, lean_object* v_n_3752_, lean_object* v_f_3753_, lean_object* v_s_3754_, lean_object* v_rem_3755_, lean_object* v_acc_3756_, lean_object* v_00_u03c9_3757_, lean_object* v_creg_3758_){
_start:
{
lean_object* v___y_3760_; 
switch(lean_obj_tag(v_s_3754_))
{
case 0:
{
lean_object* v_k_3779_; lean_object* v_v_3780_; lean_object* v___x_3782_; uint8_t v_isShared_3783_; uint8_t v_isSharedCheck_3810_; 
lean_dec(v_creg_3758_);
v_k_3779_ = lean_ctor_get(v_s_3754_, 0);
v_v_3780_ = lean_ctor_get(v_s_3754_, 1);
v_isSharedCheck_3810_ = !lean_is_exclusive(v_s_3754_);
if (v_isSharedCheck_3810_ == 0)
{
v___x_3782_ = v_s_3754_;
v_isShared_3783_ = v_isSharedCheck_3810_;
goto v_resetjp_3781_;
}
else
{
lean_inc(v_v_3780_);
lean_inc(v_k_3779_);
lean_dec(v_s_3754_);
v___x_3782_ = lean_box(0);
v_isShared_3783_ = v_isSharedCheck_3810_;
goto v_resetjp_3781_;
}
v_resetjp_3781_:
{
lean_object* v_comp_3784_; lean_object* v_parent_3785_; uint8_t v_retired_3786_; lean_object* v_table_3787_; lean_object* v___x_3789_; uint8_t v_isShared_3790_; uint8_t v_isSharedCheck_3808_; 
v_comp_3784_ = lean_ctor_get(v_f_3753_, 0);
v_parent_3785_ = lean_ctor_get(v_f_3753_, 1);
v_retired_3786_ = lean_ctor_get_uint8(v_f_3753_, sizeof(void*)*4);
v_table_3787_ = lean_ctor_get(v_f_3753_, 2);
v_isSharedCheck_3808_ = !lean_is_exclusive(v_f_3753_);
if (v_isSharedCheck_3808_ == 0)
{
lean_object* v_unused_3809_; 
v_unused_3809_ = lean_ctor_get(v_f_3753_, 3);
lean_dec(v_unused_3809_);
v___x_3789_ = v_f_3753_;
v_isShared_3790_ = v_isSharedCheck_3808_;
goto v_resetjp_3788_;
}
else
{
lean_inc(v_table_3787_);
lean_inc(v_parent_3785_);
lean_inc(v_comp_3784_);
lean_dec(v_f_3753_);
v___x_3789_ = lean_box(0);
v_isShared_3790_ = v_isSharedCheck_3808_;
goto v_resetjp_3788_;
}
v_resetjp_3788_:
{
lean_object* v___x_3791_; lean_object* v___x_3792_; lean_object* v___x_3793_; lean_object* v___x_3794_; lean_object* v___x_3795_; lean_object* v___x_3796_; lean_object* v_f_x27_3798_; 
v___x_3791_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_3791_, 0, v_v_3780_);
v___x_3792_ = lp_bounded_Bounded_KMap_set___redArg(v_table_3787_, v_k_3779_, v___x_3791_);
v___x_3793_ = lean_unsigned_to_nat(3u);
lean_inc(v_k_3779_);
v___x_3794_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_3794_, 0, v_k_3779_);
v___x_3795_ = lp_bounded_Bounded_BList_push___redArg(v___x_3793_, v_acc_3756_, v___x_3794_);
v___x_3796_ = lean_alloc_ctor(1, 3, 0);
lean_ctor_set(v___x_3796_, 0, v_rem_3755_);
lean_ctor_set(v___x_3796_, 1, v___x_3795_);
lean_ctor_set(v___x_3796_, 2, v_00_u03c9_3757_);
if (v_isShared_3790_ == 0)
{
lean_ctor_set(v___x_3789_, 3, v___x_3796_);
lean_ctor_set(v___x_3789_, 2, v___x_3792_);
v_f_x27_3798_ = v___x_3789_;
goto v_reusejp_3797_;
}
else
{
lean_object* v_reuseFailAlloc_3807_; 
v_reuseFailAlloc_3807_ = lean_alloc_ctor(0, 4, 1);
lean_ctor_set(v_reuseFailAlloc_3807_, 0, v_comp_3784_);
lean_ctor_set(v_reuseFailAlloc_3807_, 1, v_parent_3785_);
lean_ctor_set(v_reuseFailAlloc_3807_, 2, v___x_3792_);
lean_ctor_set(v_reuseFailAlloc_3807_, 3, v___x_3796_);
lean_ctor_set_uint8(v_reuseFailAlloc_3807_, sizeof(void*)*4, v_retired_3786_);
v_f_x27_3798_ = v_reuseFailAlloc_3807_;
goto v_reusejp_3797_;
}
v_reusejp_3797_:
{
lean_object* v___x_3800_; 
lean_inc(v_n_3752_);
if (v_isShared_3783_ == 0)
{
lean_ctor_set_tag(v___x_3782_, 4);
lean_ctor_set(v___x_3782_, 1, v_k_3779_);
lean_ctor_set(v___x_3782_, 0, v_n_3752_);
v___x_3800_ = v___x_3782_;
goto v_reusejp_3799_;
}
else
{
lean_object* v_reuseFailAlloc_3806_; 
v_reuseFailAlloc_3806_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v_reuseFailAlloc_3806_, 0, v_n_3752_);
lean_ctor_set(v_reuseFailAlloc_3806_, 1, v_k_3779_);
v___x_3800_ = v_reuseFailAlloc_3806_;
goto v_reusejp_3799_;
}
v_reusejp_3799_:
{
lean_object* v___x_3801_; lean_object* v___x_3802_; lean_object* v___x_3803_; lean_object* v___x_3804_; lean_object* v___x_3805_; 
v___x_3801_ = lean_box(0);
v___x_3802_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_3802_, 0, v___x_3800_);
lean_ctor_set(v___x_3802_, 1, v___x_3801_);
v___x_3803_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_3803_, 0, v_f_x27_3798_);
v___x_3804_ = lp_bounded_Bounded_SMap_set___redArg(v_00_u03b3_3751_, v_n_3752_, v___x_3803_);
lean_dec(v_n_3752_);
v___x_3805_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_3805_, 0, v___x_3802_);
lean_ctor_set(v___x_3805_, 1, v___x_3804_);
return v___x_3805_;
}
}
}
}
}
case 1:
{
lean_object* v_t_3811_; lean_object* v___x_3813_; uint8_t v_isShared_3814_; uint8_t v_isSharedCheck_3839_; 
lean_dec(v_creg_3758_);
v_t_3811_ = lean_ctor_get(v_s_3754_, 0);
v_isSharedCheck_3839_ = !lean_is_exclusive(v_s_3754_);
if (v_isSharedCheck_3839_ == 0)
{
v___x_3813_ = v_s_3754_;
v_isShared_3814_ = v_isSharedCheck_3839_;
goto v_resetjp_3812_;
}
else
{
lean_inc(v_t_3811_);
lean_dec(v_s_3754_);
v___x_3813_ = lean_box(0);
v_isShared_3814_ = v_isSharedCheck_3839_;
goto v_resetjp_3812_;
}
v_resetjp_3812_:
{
lean_object* v_comp_3815_; lean_object* v_parent_3816_; uint8_t v_retired_3817_; lean_object* v_table_3818_; lean_object* v___x_3820_; uint8_t v_isShared_3821_; uint8_t v_isSharedCheck_3837_; 
v_comp_3815_ = lean_ctor_get(v_f_3753_, 0);
v_parent_3816_ = lean_ctor_get(v_f_3753_, 1);
v_retired_3817_ = lean_ctor_get_uint8(v_f_3753_, sizeof(void*)*4);
v_table_3818_ = lean_ctor_get(v_f_3753_, 2);
v_isSharedCheck_3837_ = !lean_is_exclusive(v_f_3753_);
if (v_isSharedCheck_3837_ == 0)
{
lean_object* v_unused_3838_; 
v_unused_3838_ = lean_ctor_get(v_f_3753_, 3);
lean_dec(v_unused_3838_);
v___x_3820_ = v_f_3753_;
v_isShared_3821_ = v_isSharedCheck_3837_;
goto v_resetjp_3819_;
}
else
{
lean_inc(v_table_3818_);
lean_inc(v_parent_3816_);
lean_inc(v_comp_3815_);
lean_dec(v_f_3753_);
v___x_3820_ = lean_box(0);
v_isShared_3821_ = v_isSharedCheck_3837_;
goto v_resetjp_3819_;
}
v_resetjp_3819_:
{
lean_object* v___x_3822_; lean_object* v___x_3823_; lean_object* v___x_3824_; lean_object* v___x_3825_; lean_object* v___x_3827_; 
lean_inc(v_t_3811_);
lean_inc(v_n_3752_);
v___x_3822_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_3822_, 0, v_n_3752_);
lean_ctor_set(v___x_3822_, 1, v_t_3811_);
v___x_3823_ = lean_box(0);
v___x_3824_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_3824_, 0, v___x_3822_);
lean_ctor_set(v___x_3824_, 1, v___x_3823_);
v___x_3825_ = lean_unsigned_to_nat(3u);
if (v_isShared_3814_ == 0)
{
v___x_3827_ = v___x_3813_;
goto v_reusejp_3826_;
}
else
{
lean_object* v_reuseFailAlloc_3836_; 
v_reuseFailAlloc_3836_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_3836_, 0, v_t_3811_);
v___x_3827_ = v_reuseFailAlloc_3836_;
goto v_reusejp_3826_;
}
v_reusejp_3826_:
{
lean_object* v___x_3828_; lean_object* v___x_3829_; lean_object* v___x_3831_; 
v___x_3828_ = lp_bounded_Bounded_BList_push___redArg(v___x_3825_, v_acc_3756_, v___x_3827_);
v___x_3829_ = lean_alloc_ctor(1, 3, 0);
lean_ctor_set(v___x_3829_, 0, v_rem_3755_);
lean_ctor_set(v___x_3829_, 1, v___x_3828_);
lean_ctor_set(v___x_3829_, 2, v_00_u03c9_3757_);
if (v_isShared_3821_ == 0)
{
lean_ctor_set(v___x_3820_, 3, v___x_3829_);
v___x_3831_ = v___x_3820_;
goto v_reusejp_3830_;
}
else
{
lean_object* v_reuseFailAlloc_3835_; 
v_reuseFailAlloc_3835_ = lean_alloc_ctor(0, 4, 1);
lean_ctor_set(v_reuseFailAlloc_3835_, 0, v_comp_3815_);
lean_ctor_set(v_reuseFailAlloc_3835_, 1, v_parent_3816_);
lean_ctor_set(v_reuseFailAlloc_3835_, 2, v_table_3818_);
lean_ctor_set(v_reuseFailAlloc_3835_, 3, v___x_3829_);
lean_ctor_set_uint8(v_reuseFailAlloc_3835_, sizeof(void*)*4, v_retired_3817_);
v___x_3831_ = v_reuseFailAlloc_3835_;
goto v_reusejp_3830_;
}
v_reusejp_3830_:
{
lean_object* v___x_3832_; lean_object* v___x_3833_; lean_object* v___x_3834_; 
v___x_3832_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_3832_, 0, v___x_3831_);
v___x_3833_ = lp_bounded_Bounded_SMap_set___redArg(v_00_u03b3_3751_, v_n_3752_, v___x_3832_);
lean_dec(v_n_3752_);
v___x_3834_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_3834_, 0, v___x_3824_);
lean_ctor_set(v___x_3834_, 1, v___x_3833_);
return v___x_3834_;
}
}
}
}
}
case 2:
{
lean_object* v_k_3840_; lean_object* v___x_3841_; uint8_t v___x_3842_; lean_object* v___x_3843_; 
lean_dec(v_creg_3758_);
v_k_3840_ = lean_ctor_get(v_s_3754_, 0);
lean_inc(v_k_3840_);
lean_dec_ref_known(v_s_3754_, 1);
v___x_3841_ = lean_unsigned_to_nat(4u);
v___x_3842_ = 0;
v___x_3843_ = lp_bounded_Bounded_readC(v_00_u03b3_3751_, v___x_3841_, v_n_3752_, v_k_3840_, v___x_3842_);
switch(lean_obj_tag(v___x_3843_))
{
case 0:
{
lean_object* v_v_3844_; lean_object* v___x_3845_; 
v_v_3844_ = lean_ctor_get(v___x_3843_, 0);
lean_inc(v_v_3844_);
lean_dec_ref_known(v___x_3843_, 1);
lean_inc(v_n_3752_);
v___x_3845_ = lean_alloc_ctor(6, 3, 0);
lean_ctor_set(v___x_3845_, 0, v_n_3752_);
lean_ctor_set(v___x_3845_, 1, v_k_3840_);
lean_ctor_set(v___x_3845_, 2, v_v_3844_);
v___y_3760_ = v___x_3845_;
goto v___jp_3759_;
}
case 1:
{
uint8_t v___x_3846_; lean_object* v___x_3847_; 
v___x_3846_ = 1;
lean_inc(v_n_3752_);
v___x_3847_ = lean_alloc_ctor(7, 2, 1);
lean_ctor_set(v___x_3847_, 0, v_n_3752_);
lean_ctor_set(v___x_3847_, 1, v_k_3840_);
lean_ctor_set_uint8(v___x_3847_, sizeof(void*)*2, v___x_3846_);
v___y_3760_ = v___x_3847_;
goto v___jp_3759_;
}
default: 
{
lean_object* v___x_3848_; 
lean_inc(v_n_3752_);
v___x_3848_ = lean_alloc_ctor(7, 2, 1);
lean_ctor_set(v___x_3848_, 0, v_n_3752_);
lean_ctor_set(v___x_3848_, 1, v_k_3840_);
lean_ctor_set_uint8(v___x_3848_, sizeof(void*)*2, v___x_3842_);
v___y_3760_ = v___x_3848_;
goto v___jp_3759_;
}
}
}
case 3:
{
lean_object* v_k_3849_; lean_object* v_v_3850_; lean_object* v___x_3852_; uint8_t v_isShared_3853_; uint8_t v_isSharedCheck_3895_; 
lean_dec(v_creg_3758_);
v_k_3849_ = lean_ctor_get(v_s_3754_, 0);
v_v_3850_ = lean_ctor_get(v_s_3754_, 1);
v_isSharedCheck_3895_ = !lean_is_exclusive(v_s_3754_);
if (v_isSharedCheck_3895_ == 0)
{
v___x_3852_ = v_s_3754_;
v_isShared_3853_ = v_isSharedCheck_3895_;
goto v_resetjp_3851_;
}
else
{
lean_inc(v_v_3850_);
lean_inc(v_k_3849_);
lean_dec(v_s_3754_);
v___x_3852_ = lean_box(0);
v_isShared_3853_ = v_isSharedCheck_3895_;
goto v_resetjp_3851_;
}
v_resetjp_3851_:
{
lean_object* v_comp_3854_; lean_object* v_parent_3855_; uint8_t v_retired_3856_; lean_object* v_table_3857_; lean_object* v___x_3859_; uint8_t v_isShared_3860_; uint8_t v_isSharedCheck_3893_; 
v_comp_3854_ = lean_ctor_get(v_f_3753_, 0);
v_parent_3855_ = lean_ctor_get(v_f_3753_, 1);
v_retired_3856_ = lean_ctor_get_uint8(v_f_3753_, sizeof(void*)*4);
v_table_3857_ = lean_ctor_get(v_f_3753_, 2);
v_isSharedCheck_3893_ = !lean_is_exclusive(v_f_3753_);
if (v_isSharedCheck_3893_ == 0)
{
lean_object* v_unused_3894_; 
v_unused_3894_ = lean_ctor_get(v_f_3753_, 3);
lean_dec(v_unused_3894_);
v___x_3859_ = v_f_3753_;
v_isShared_3860_ = v_isSharedCheck_3893_;
goto v_resetjp_3858_;
}
else
{
lean_inc(v_table_3857_);
lean_inc(v_parent_3855_);
lean_inc(v_comp_3854_);
lean_dec(v_f_3753_);
v___x_3859_ = lean_box(0);
v_isShared_3860_ = v_isSharedCheck_3893_;
goto v_resetjp_3858_;
}
v_resetjp_3858_:
{
lean_object* v___x_3861_; 
v___x_3861_ = lp_bounded_Bounded_KMap_get___redArg(v_table_3857_, v_k_3849_);
if (lean_obj_tag(v___x_3861_) == 0)
{
lean_object* v___x_3862_; lean_object* v___x_3863_; lean_object* v___x_3865_; 
lean_dec(v_v_3850_);
lean_dec(v_k_3849_);
v___x_3862_ = lean_box(0);
v___x_3863_ = lean_alloc_ctor(1, 3, 0);
lean_ctor_set(v___x_3863_, 0, v_rem_3755_);
lean_ctor_set(v___x_3863_, 1, v_acc_3756_);
lean_ctor_set(v___x_3863_, 2, v_00_u03c9_3757_);
if (v_isShared_3860_ == 0)
{
lean_ctor_set(v___x_3859_, 3, v___x_3863_);
v___x_3865_ = v___x_3859_;
goto v_reusejp_3864_;
}
else
{
lean_object* v_reuseFailAlloc_3871_; 
v_reuseFailAlloc_3871_ = lean_alloc_ctor(0, 4, 1);
lean_ctor_set(v_reuseFailAlloc_3871_, 0, v_comp_3854_);
lean_ctor_set(v_reuseFailAlloc_3871_, 1, v_parent_3855_);
lean_ctor_set(v_reuseFailAlloc_3871_, 2, v_table_3857_);
lean_ctor_set(v_reuseFailAlloc_3871_, 3, v___x_3863_);
lean_ctor_set_uint8(v_reuseFailAlloc_3871_, sizeof(void*)*4, v_retired_3856_);
v___x_3865_ = v_reuseFailAlloc_3871_;
goto v_reusejp_3864_;
}
v_reusejp_3864_:
{
lean_object* v___x_3866_; lean_object* v___x_3867_; lean_object* v___x_3869_; 
v___x_3866_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_3866_, 0, v___x_3865_);
v___x_3867_ = lp_bounded_Bounded_SMap_set___redArg(v_00_u03b3_3751_, v_n_3752_, v___x_3866_);
lean_dec(v_n_3752_);
if (v_isShared_3853_ == 0)
{
lean_ctor_set_tag(v___x_3852_, 0);
lean_ctor_set(v___x_3852_, 1, v___x_3867_);
lean_ctor_set(v___x_3852_, 0, v___x_3862_);
v___x_3869_ = v___x_3852_;
goto v_reusejp_3868_;
}
else
{
lean_object* v_reuseFailAlloc_3870_; 
v_reuseFailAlloc_3870_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_3870_, 0, v___x_3862_);
lean_ctor_set(v_reuseFailAlloc_3870_, 1, v___x_3867_);
v___x_3869_ = v_reuseFailAlloc_3870_;
goto v_reusejp_3868_;
}
v_reusejp_3868_:
{
return v___x_3869_;
}
}
}
else
{
lean_object* v___x_3873_; uint8_t v_isShared_3874_; uint8_t v_isSharedCheck_3891_; 
v_isSharedCheck_3891_ = !lean_is_exclusive(v___x_3861_);
if (v_isSharedCheck_3891_ == 0)
{
lean_object* v_unused_3892_; 
v_unused_3892_ = lean_ctor_get(v___x_3861_, 0);
lean_dec(v_unused_3892_);
v___x_3873_ = v___x_3861_;
v_isShared_3874_ = v_isSharedCheck_3891_;
goto v_resetjp_3872_;
}
else
{
lean_dec(v___x_3861_);
v___x_3873_ = lean_box(0);
v_isShared_3874_ = v_isSharedCheck_3891_;
goto v_resetjp_3872_;
}
v_resetjp_3872_:
{
lean_object* v___x_3875_; lean_object* v___x_3876_; lean_object* v___x_3878_; 
lean_inc(v_v_3850_);
lean_inc(v_k_3849_);
lean_inc(v_n_3752_);
v___x_3875_ = lean_alloc_ctor(8, 3, 0);
lean_ctor_set(v___x_3875_, 0, v_n_3752_);
lean_ctor_set(v___x_3875_, 1, v_k_3849_);
lean_ctor_set(v___x_3875_, 2, v_v_3850_);
v___x_3876_ = lean_box(0);
if (v_isShared_3853_ == 0)
{
lean_ctor_set_tag(v___x_3852_, 1);
lean_ctor_set(v___x_3852_, 1, v___x_3876_);
lean_ctor_set(v___x_3852_, 0, v___x_3875_);
v___x_3878_ = v___x_3852_;
goto v_reusejp_3877_;
}
else
{
lean_object* v_reuseFailAlloc_3890_; 
v_reuseFailAlloc_3890_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_3890_, 0, v___x_3875_);
lean_ctor_set(v_reuseFailAlloc_3890_, 1, v___x_3876_);
v___x_3878_ = v_reuseFailAlloc_3890_;
goto v_reusejp_3877_;
}
v_reusejp_3877_:
{
lean_object* v___x_3880_; 
if (v_isShared_3874_ == 0)
{
lean_ctor_set(v___x_3873_, 0, v_v_3850_);
v___x_3880_ = v___x_3873_;
goto v_reusejp_3879_;
}
else
{
lean_object* v_reuseFailAlloc_3889_; 
v_reuseFailAlloc_3889_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_3889_, 0, v_v_3850_);
v___x_3880_ = v_reuseFailAlloc_3889_;
goto v_reusejp_3879_;
}
v_reusejp_3879_:
{
lean_object* v___x_3881_; lean_object* v___x_3882_; lean_object* v___x_3884_; 
v___x_3881_ = lp_bounded_Bounded_KMap_set___redArg(v_table_3857_, v_k_3849_, v___x_3880_);
lean_dec(v_k_3849_);
v___x_3882_ = lean_alloc_ctor(1, 3, 0);
lean_ctor_set(v___x_3882_, 0, v_rem_3755_);
lean_ctor_set(v___x_3882_, 1, v_acc_3756_);
lean_ctor_set(v___x_3882_, 2, v_00_u03c9_3757_);
if (v_isShared_3860_ == 0)
{
lean_ctor_set(v___x_3859_, 3, v___x_3882_);
lean_ctor_set(v___x_3859_, 2, v___x_3881_);
v___x_3884_ = v___x_3859_;
goto v_reusejp_3883_;
}
else
{
lean_object* v_reuseFailAlloc_3888_; 
v_reuseFailAlloc_3888_ = lean_alloc_ctor(0, 4, 1);
lean_ctor_set(v_reuseFailAlloc_3888_, 0, v_comp_3854_);
lean_ctor_set(v_reuseFailAlloc_3888_, 1, v_parent_3855_);
lean_ctor_set(v_reuseFailAlloc_3888_, 2, v___x_3881_);
lean_ctor_set(v_reuseFailAlloc_3888_, 3, v___x_3882_);
lean_ctor_set_uint8(v_reuseFailAlloc_3888_, sizeof(void*)*4, v_retired_3856_);
v___x_3884_ = v_reuseFailAlloc_3888_;
goto v_reusejp_3883_;
}
v_reusejp_3883_:
{
lean_object* v___x_3885_; lean_object* v___x_3886_; lean_object* v___x_3887_; 
v___x_3885_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_3885_, 0, v___x_3884_);
v___x_3886_ = lp_bounded_Bounded_SMap_set___redArg(v_00_u03b3_3751_, v_n_3752_, v___x_3885_);
lean_dec(v_n_3752_);
v___x_3887_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_3887_, 0, v___x_3878_);
lean_ctor_set(v___x_3887_, 1, v___x_3886_);
return v___x_3887_;
}
}
}
}
}
}
}
}
case 4:
{
if (lean_obj_tag(v_creg_3758_) == 0)
{
lean_object* v_comp_3896_; lean_object* v_parent_3897_; uint8_t v_retired_3898_; lean_object* v_table_3899_; lean_object* v___x_3901_; uint8_t v_isShared_3902_; uint8_t v_isSharedCheck_3911_; 
v_comp_3896_ = lean_ctor_get(v_f_3753_, 0);
v_parent_3897_ = lean_ctor_get(v_f_3753_, 1);
v_retired_3898_ = lean_ctor_get_uint8(v_f_3753_, sizeof(void*)*4);
v_table_3899_ = lean_ctor_get(v_f_3753_, 2);
v_isSharedCheck_3911_ = !lean_is_exclusive(v_f_3753_);
if (v_isSharedCheck_3911_ == 0)
{
lean_object* v_unused_3912_; 
v_unused_3912_ = lean_ctor_get(v_f_3753_, 3);
lean_dec(v_unused_3912_);
v___x_3901_ = v_f_3753_;
v_isShared_3902_ = v_isSharedCheck_3911_;
goto v_resetjp_3900_;
}
else
{
lean_inc(v_table_3899_);
lean_inc(v_parent_3897_);
lean_inc(v_comp_3896_);
lean_dec(v_f_3753_);
v___x_3901_ = lean_box(0);
v_isShared_3902_ = v_isSharedCheck_3911_;
goto v_resetjp_3900_;
}
v_resetjp_3900_:
{
lean_object* v___x_3903_; lean_object* v___x_3904_; lean_object* v___x_3906_; 
v___x_3903_ = lean_box(0);
v___x_3904_ = lean_alloc_ctor(1, 3, 0);
lean_ctor_set(v___x_3904_, 0, v_rem_3755_);
lean_ctor_set(v___x_3904_, 1, v_acc_3756_);
lean_ctor_set(v___x_3904_, 2, v_00_u03c9_3757_);
if (v_isShared_3902_ == 0)
{
lean_ctor_set(v___x_3901_, 3, v___x_3904_);
v___x_3906_ = v___x_3901_;
goto v_reusejp_3905_;
}
else
{
lean_object* v_reuseFailAlloc_3910_; 
v_reuseFailAlloc_3910_ = lean_alloc_ctor(0, 4, 1);
lean_ctor_set(v_reuseFailAlloc_3910_, 0, v_comp_3896_);
lean_ctor_set(v_reuseFailAlloc_3910_, 1, v_parent_3897_);
lean_ctor_set(v_reuseFailAlloc_3910_, 2, v_table_3899_);
lean_ctor_set(v_reuseFailAlloc_3910_, 3, v___x_3904_);
lean_ctor_set_uint8(v_reuseFailAlloc_3910_, sizeof(void*)*4, v_retired_3898_);
v___x_3906_ = v_reuseFailAlloc_3910_;
goto v_reusejp_3905_;
}
v_reusejp_3905_:
{
lean_object* v___x_3907_; lean_object* v___x_3908_; lean_object* v___x_3909_; 
v___x_3907_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_3907_, 0, v___x_3906_);
v___x_3908_ = lp_bounded_Bounded_SMap_set___redArg(v_00_u03b3_3751_, v_n_3752_, v___x_3907_);
lean_dec(v_n_3752_);
v___x_3909_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_3909_, 0, v___x_3903_);
lean_ctor_set(v___x_3909_, 1, v___x_3908_);
return v___x_3909_;
}
}
}
else
{
lean_object* v_val_3913_; lean_object* v___x_3915_; uint8_t v_isShared_3916_; uint8_t v_isSharedCheck_3971_; 
v_val_3913_ = lean_ctor_get(v_creg_3758_, 0);
v_isSharedCheck_3971_ = !lean_is_exclusive(v_creg_3758_);
if (v_isSharedCheck_3971_ == 0)
{
v___x_3915_ = v_creg_3758_;
v_isShared_3916_ = v_isSharedCheck_3971_;
goto v_resetjp_3914_;
}
else
{
lean_inc(v_val_3913_);
lean_dec(v_creg_3758_);
v___x_3915_ = lean_box(0);
v_isShared_3916_ = v_isSharedCheck_3971_;
goto v_resetjp_3914_;
}
v_resetjp_3914_:
{
lean_object* v___x_3917_; 
v___x_3917_ = lp_bounded_Bounded_SMap_get___redArg(v_00_u03b3_3751_, v_val_3913_);
if (lean_obj_tag(v___x_3917_) == 0)
{
lean_object* v_comp_3918_; lean_object* v_parent_3919_; uint8_t v_retired_3920_; lean_object* v_table_3921_; lean_object* v___x_3923_; uint8_t v_isShared_3924_; uint8_t v_isSharedCheck_3945_; 
v_comp_3918_ = lean_ctor_get(v_f_3753_, 0);
v_parent_3919_ = lean_ctor_get(v_f_3753_, 1);
v_retired_3920_ = lean_ctor_get_uint8(v_f_3753_, sizeof(void*)*4);
v_table_3921_ = lean_ctor_get(v_f_3753_, 2);
v_isSharedCheck_3945_ = !lean_is_exclusive(v_f_3753_);
if (v_isSharedCheck_3945_ == 0)
{
lean_object* v_unused_3946_; 
v_unused_3946_ = lean_ctor_get(v_f_3753_, 3);
lean_dec(v_unused_3946_);
v___x_3923_ = v_f_3753_;
v_isShared_3924_ = v_isSharedCheck_3945_;
goto v_resetjp_3922_;
}
else
{
lean_inc(v_table_3921_);
lean_inc(v_parent_3919_);
lean_inc(v_comp_3918_);
lean_dec(v_f_3753_);
v___x_3923_ = lean_box(0);
v_isShared_3924_ = v_isSharedCheck_3945_;
goto v_resetjp_3922_;
}
v_resetjp_3922_:
{
lean_object* v___x_3925_; lean_object* v___x_3927_; 
v___x_3925_ = lp_bounded_Bounded_childComp;
lean_inc(v_n_3752_);
if (v_isShared_3916_ == 0)
{
lean_ctor_set(v___x_3915_, 0, v_n_3752_);
v___x_3927_ = v___x_3915_;
goto v_reusejp_3926_;
}
else
{
lean_object* v_reuseFailAlloc_3944_; 
v_reuseFailAlloc_3944_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_3944_, 0, v_n_3752_);
v___x_3927_ = v_reuseFailAlloc_3944_;
goto v_reusejp_3926_;
}
v_reusejp_3926_:
{
lean_object* v___x_3928_; lean_object* v___x_3929_; lean_object* v_00_u03b31_3930_; lean_object* v___x_3931_; lean_object* v___x_3932_; lean_object* v___x_3933_; lean_object* v___x_3934_; lean_object* v___x_3935_; lean_object* v___x_3936_; lean_object* v___x_3937_; lean_object* v___x_3939_; 
v___x_3928_ = lp_bounded_Bounded_freshFiber(v___x_3925_, v___x_3927_);
v___x_3929_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_3929_, 0, v___x_3928_);
v_00_u03b31_3930_ = lp_bounded_Bounded_SMap_set___redArg(v_00_u03b3_3751_, v_val_3913_, v___x_3929_);
lean_inc(v_val_3913_);
lean_inc(v_n_3752_);
v___x_3931_ = lean_alloc_ctor(9, 2, 0);
lean_ctor_set(v___x_3931_, 0, v_n_3752_);
lean_ctor_set(v___x_3931_, 1, v_val_3913_);
v___x_3932_ = lean_box(0);
v___x_3933_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_3933_, 0, v___x_3931_);
lean_ctor_set(v___x_3933_, 1, v___x_3932_);
v___x_3934_ = lean_unsigned_to_nat(3u);
v___x_3935_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_3935_, 0, v_val_3913_);
v___x_3936_ = lp_bounded_Bounded_BList_push___redArg(v___x_3934_, v_acc_3756_, v___x_3935_);
v___x_3937_ = lean_alloc_ctor(1, 3, 0);
lean_ctor_set(v___x_3937_, 0, v_rem_3755_);
lean_ctor_set(v___x_3937_, 1, v___x_3936_);
lean_ctor_set(v___x_3937_, 2, v_00_u03c9_3757_);
if (v_isShared_3924_ == 0)
{
lean_ctor_set(v___x_3923_, 3, v___x_3937_);
v___x_3939_ = v___x_3923_;
goto v_reusejp_3938_;
}
else
{
lean_object* v_reuseFailAlloc_3943_; 
v_reuseFailAlloc_3943_ = lean_alloc_ctor(0, 4, 1);
lean_ctor_set(v_reuseFailAlloc_3943_, 0, v_comp_3918_);
lean_ctor_set(v_reuseFailAlloc_3943_, 1, v_parent_3919_);
lean_ctor_set(v_reuseFailAlloc_3943_, 2, v_table_3921_);
lean_ctor_set(v_reuseFailAlloc_3943_, 3, v___x_3937_);
lean_ctor_set_uint8(v_reuseFailAlloc_3943_, sizeof(void*)*4, v_retired_3920_);
v___x_3939_ = v_reuseFailAlloc_3943_;
goto v_reusejp_3938_;
}
v_reusejp_3938_:
{
lean_object* v___x_3940_; lean_object* v___x_3941_; lean_object* v___x_3942_; 
v___x_3940_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_3940_, 0, v___x_3939_);
v___x_3941_ = lp_bounded_Bounded_SMap_set___redArg(v_00_u03b31_3930_, v_n_3752_, v___x_3940_);
lean_dec(v_n_3752_);
v___x_3942_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_3942_, 0, v___x_3933_);
lean_ctor_set(v___x_3942_, 1, v___x_3941_);
return v___x_3942_;
}
}
}
}
else
{
lean_object* v___x_3948_; uint8_t v_isShared_3949_; uint8_t v_isSharedCheck_3969_; 
lean_del_object(v___x_3915_);
lean_dec(v_val_3913_);
v_isSharedCheck_3969_ = !lean_is_exclusive(v___x_3917_);
if (v_isSharedCheck_3969_ == 0)
{
lean_object* v_unused_3970_; 
v_unused_3970_ = lean_ctor_get(v___x_3917_, 0);
lean_dec(v_unused_3970_);
v___x_3948_ = v___x_3917_;
v_isShared_3949_ = v_isSharedCheck_3969_;
goto v_resetjp_3947_;
}
else
{
lean_dec(v___x_3917_);
v___x_3948_ = lean_box(0);
v_isShared_3949_ = v_isSharedCheck_3969_;
goto v_resetjp_3947_;
}
v_resetjp_3947_:
{
lean_object* v_comp_3950_; lean_object* v_parent_3951_; uint8_t v_retired_3952_; lean_object* v_table_3953_; lean_object* v___x_3955_; uint8_t v_isShared_3956_; uint8_t v_isSharedCheck_3967_; 
v_comp_3950_ = lean_ctor_get(v_f_3753_, 0);
v_parent_3951_ = lean_ctor_get(v_f_3753_, 1);
v_retired_3952_ = lean_ctor_get_uint8(v_f_3753_, sizeof(void*)*4);
v_table_3953_ = lean_ctor_get(v_f_3753_, 2);
v_isSharedCheck_3967_ = !lean_is_exclusive(v_f_3753_);
if (v_isSharedCheck_3967_ == 0)
{
lean_object* v_unused_3968_; 
v_unused_3968_ = lean_ctor_get(v_f_3753_, 3);
lean_dec(v_unused_3968_);
v___x_3955_ = v_f_3753_;
v_isShared_3956_ = v_isSharedCheck_3967_;
goto v_resetjp_3954_;
}
else
{
lean_inc(v_table_3953_);
lean_inc(v_parent_3951_);
lean_inc(v_comp_3950_);
lean_dec(v_f_3753_);
v___x_3955_ = lean_box(0);
v_isShared_3956_ = v_isSharedCheck_3967_;
goto v_resetjp_3954_;
}
v_resetjp_3954_:
{
lean_object* v___x_3957_; lean_object* v___x_3958_; lean_object* v___x_3960_; 
v___x_3957_ = lean_box(0);
v___x_3958_ = lean_alloc_ctor(1, 3, 0);
lean_ctor_set(v___x_3958_, 0, v_rem_3755_);
lean_ctor_set(v___x_3958_, 1, v_acc_3756_);
lean_ctor_set(v___x_3958_, 2, v_00_u03c9_3757_);
if (v_isShared_3956_ == 0)
{
lean_ctor_set(v___x_3955_, 3, v___x_3958_);
v___x_3960_ = v___x_3955_;
goto v_reusejp_3959_;
}
else
{
lean_object* v_reuseFailAlloc_3966_; 
v_reuseFailAlloc_3966_ = lean_alloc_ctor(0, 4, 1);
lean_ctor_set(v_reuseFailAlloc_3966_, 0, v_comp_3950_);
lean_ctor_set(v_reuseFailAlloc_3966_, 1, v_parent_3951_);
lean_ctor_set(v_reuseFailAlloc_3966_, 2, v_table_3953_);
lean_ctor_set(v_reuseFailAlloc_3966_, 3, v___x_3958_);
lean_ctor_set_uint8(v_reuseFailAlloc_3966_, sizeof(void*)*4, v_retired_3952_);
v___x_3960_ = v_reuseFailAlloc_3966_;
goto v_reusejp_3959_;
}
v_reusejp_3959_:
{
lean_object* v___x_3962_; 
if (v_isShared_3949_ == 0)
{
lean_ctor_set(v___x_3948_, 0, v___x_3960_);
v___x_3962_ = v___x_3948_;
goto v_reusejp_3961_;
}
else
{
lean_object* v_reuseFailAlloc_3965_; 
v_reuseFailAlloc_3965_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_3965_, 0, v___x_3960_);
v___x_3962_ = v_reuseFailAlloc_3965_;
goto v_reusejp_3961_;
}
v_reusejp_3961_:
{
lean_object* v___x_3963_; lean_object* v___x_3964_; 
v___x_3963_ = lp_bounded_Bounded_SMap_set___redArg(v_00_u03b3_3751_, v_n_3752_, v___x_3962_);
lean_dec(v_n_3752_);
v___x_3964_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_3964_, 0, v___x_3957_);
lean_ctor_set(v___x_3964_, 1, v___x_3963_);
return v___x_3964_;
}
}
}
}
}
}
}
}
default: 
{
lean_object* v_comp_3972_; lean_object* v_parent_3973_; uint8_t v_retired_3974_; lean_object* v_table_3975_; lean_object* v___x_3977_; uint8_t v_isShared_3978_; uint8_t v_isSharedCheck_3987_; 
lean_dec(v_creg_3758_);
v_comp_3972_ = lean_ctor_get(v_f_3753_, 0);
v_parent_3973_ = lean_ctor_get(v_f_3753_, 1);
v_retired_3974_ = lean_ctor_get_uint8(v_f_3753_, sizeof(void*)*4);
v_table_3975_ = lean_ctor_get(v_f_3753_, 2);
v_isSharedCheck_3987_ = !lean_is_exclusive(v_f_3753_);
if (v_isSharedCheck_3987_ == 0)
{
lean_object* v_unused_3988_; 
v_unused_3988_ = lean_ctor_get(v_f_3753_, 3);
lean_dec(v_unused_3988_);
v___x_3977_ = v_f_3753_;
v_isShared_3978_ = v_isSharedCheck_3987_;
goto v_resetjp_3976_;
}
else
{
lean_inc(v_table_3975_);
lean_inc(v_parent_3973_);
lean_inc(v_comp_3972_);
lean_dec(v_f_3753_);
v___x_3977_ = lean_box(0);
v_isShared_3978_ = v_isSharedCheck_3987_;
goto v_resetjp_3976_;
}
v_resetjp_3976_:
{
lean_object* v___x_3979_; lean_object* v___x_3980_; lean_object* v___x_3982_; 
v___x_3979_ = lean_box(0);
v___x_3980_ = lean_alloc_ctor(1, 3, 0);
lean_ctor_set(v___x_3980_, 0, v_rem_3755_);
lean_ctor_set(v___x_3980_, 1, v_acc_3756_);
lean_ctor_set(v___x_3980_, 2, v_00_u03c9_3757_);
if (v_isShared_3978_ == 0)
{
lean_ctor_set(v___x_3977_, 3, v___x_3980_);
v___x_3982_ = v___x_3977_;
goto v_reusejp_3981_;
}
else
{
lean_object* v_reuseFailAlloc_3986_; 
v_reuseFailAlloc_3986_ = lean_alloc_ctor(0, 4, 1);
lean_ctor_set(v_reuseFailAlloc_3986_, 0, v_comp_3972_);
lean_ctor_set(v_reuseFailAlloc_3986_, 1, v_parent_3973_);
lean_ctor_set(v_reuseFailAlloc_3986_, 2, v_table_3975_);
lean_ctor_set(v_reuseFailAlloc_3986_, 3, v___x_3980_);
lean_ctor_set_uint8(v_reuseFailAlloc_3986_, sizeof(void*)*4, v_retired_3974_);
v___x_3982_ = v_reuseFailAlloc_3986_;
goto v_reusejp_3981_;
}
v_reusejp_3981_:
{
lean_object* v___x_3983_; lean_object* v___x_3984_; lean_object* v___x_3985_; 
v___x_3983_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_3983_, 0, v___x_3982_);
v___x_3984_ = lp_bounded_Bounded_SMap_set___redArg(v_00_u03b3_3751_, v_n_3752_, v___x_3983_);
lean_dec(v_n_3752_);
v___x_3985_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_3985_, 0, v___x_3979_);
lean_ctor_set(v___x_3985_, 1, v___x_3984_);
return v___x_3985_;
}
}
}
}
v___jp_3759_:
{
lean_object* v_comp_3761_; lean_object* v_parent_3762_; uint8_t v_retired_3763_; lean_object* v_table_3764_; lean_object* v___x_3766_; uint8_t v_isShared_3767_; uint8_t v_isSharedCheck_3777_; 
v_comp_3761_ = lean_ctor_get(v_f_3753_, 0);
v_parent_3762_ = lean_ctor_get(v_f_3753_, 1);
v_retired_3763_ = lean_ctor_get_uint8(v_f_3753_, sizeof(void*)*4);
v_table_3764_ = lean_ctor_get(v_f_3753_, 2);
v_isSharedCheck_3777_ = !lean_is_exclusive(v_f_3753_);
if (v_isSharedCheck_3777_ == 0)
{
lean_object* v_unused_3778_; 
v_unused_3778_ = lean_ctor_get(v_f_3753_, 3);
lean_dec(v_unused_3778_);
v___x_3766_ = v_f_3753_;
v_isShared_3767_ = v_isSharedCheck_3777_;
goto v_resetjp_3765_;
}
else
{
lean_inc(v_table_3764_);
lean_inc(v_parent_3762_);
lean_inc(v_comp_3761_);
lean_dec(v_f_3753_);
v___x_3766_ = lean_box(0);
v_isShared_3767_ = v_isSharedCheck_3777_;
goto v_resetjp_3765_;
}
v_resetjp_3765_:
{
lean_object* v___x_3768_; lean_object* v___x_3769_; lean_object* v___x_3770_; lean_object* v___x_3772_; 
v___x_3768_ = lean_box(0);
v___x_3769_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_3769_, 0, v___y_3760_);
lean_ctor_set(v___x_3769_, 1, v___x_3768_);
v___x_3770_ = lean_alloc_ctor(1, 3, 0);
lean_ctor_set(v___x_3770_, 0, v_rem_3755_);
lean_ctor_set(v___x_3770_, 1, v_acc_3756_);
lean_ctor_set(v___x_3770_, 2, v_00_u03c9_3757_);
if (v_isShared_3767_ == 0)
{
lean_ctor_set(v___x_3766_, 3, v___x_3770_);
v___x_3772_ = v___x_3766_;
goto v_reusejp_3771_;
}
else
{
lean_object* v_reuseFailAlloc_3776_; 
v_reuseFailAlloc_3776_ = lean_alloc_ctor(0, 4, 1);
lean_ctor_set(v_reuseFailAlloc_3776_, 0, v_comp_3761_);
lean_ctor_set(v_reuseFailAlloc_3776_, 1, v_parent_3762_);
lean_ctor_set(v_reuseFailAlloc_3776_, 2, v_table_3764_);
lean_ctor_set(v_reuseFailAlloc_3776_, 3, v___x_3770_);
lean_ctor_set_uint8(v_reuseFailAlloc_3776_, sizeof(void*)*4, v_retired_3763_);
v___x_3772_ = v_reuseFailAlloc_3776_;
goto v_reusejp_3771_;
}
v_reusejp_3771_:
{
lean_object* v___x_3773_; lean_object* v___x_3774_; lean_object* v___x_3775_; 
v___x_3773_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_3773_, 0, v___x_3772_);
v___x_3774_ = lp_bounded_Bounded_SMap_set___redArg(v_00_u03b3_3751_, v_n_3752_, v___x_3773_);
lean_dec(v_n_3752_);
v___x_3775_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_3775_, 0, v___x_3769_);
lean_ctor_set(v___x_3775_, 1, v___x_3774_);
return v___x_3775_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_applyInv(lean_object* v_n_3989_, lean_object* v_x_3990_, lean_object* v_x_3991_){
_start:
{
switch(lean_obj_tag(v_x_3991_))
{
case 0:
{
lean_object* v_fst_3992_; lean_object* v_snd_3993_; lean_object* v___x_3995_; uint8_t v_isShared_3996_; uint8_t v_isSharedCheck_4032_; 
v_fst_3992_ = lean_ctor_get(v_x_3990_, 0);
v_snd_3993_ = lean_ctor_get(v_x_3990_, 1);
v_isSharedCheck_4032_ = !lean_is_exclusive(v_x_3990_);
if (v_isSharedCheck_4032_ == 0)
{
v___x_3995_ = v_x_3990_;
v_isShared_3996_ = v_isSharedCheck_4032_;
goto v_resetjp_3994_;
}
else
{
lean_inc(v_snd_3993_);
lean_inc(v_fst_3992_);
lean_dec(v_x_3990_);
v___x_3995_ = lean_box(0);
v_isShared_3996_ = v_isSharedCheck_4032_;
goto v_resetjp_3994_;
}
v_resetjp_3994_:
{
lean_object* v_k_3997_; lean_object* v___x_3998_; lean_object* v___x_3999_; lean_object* v___x_4000_; lean_object* v___x_4001_; lean_object* v___x_4002_; 
v_k_3997_ = lean_ctor_get(v_x_3991_, 0);
lean_inc(v_k_3997_);
lean_inc(v_n_3989_);
v___x_3998_ = lean_alloc_ctor(15, 2, 0);
lean_ctor_set(v___x_3998_, 0, v_n_3989_);
lean_ctor_set(v___x_3998_, 1, v_k_3997_);
v___x_3999_ = lean_box(0);
v___x_4000_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_4000_, 0, v___x_3998_);
lean_ctor_set(v___x_4000_, 1, v___x_3999_);
v___x_4001_ = l_List_appendTR___redArg(v_fst_3992_, v___x_4000_);
v___x_4002_ = lp_bounded_Bounded_SMap_get___redArg(v_snd_3993_, v_n_3989_);
if (lean_obj_tag(v___x_4002_) == 0)
{
lean_object* v___x_4004_; 
lean_dec(v_n_3989_);
if (v_isShared_3996_ == 0)
{
lean_ctor_set(v___x_3995_, 0, v___x_4001_);
v___x_4004_ = v___x_3995_;
goto v_reusejp_4003_;
}
else
{
lean_object* v_reuseFailAlloc_4005_; 
v_reuseFailAlloc_4005_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_4005_, 0, v___x_4001_);
lean_ctor_set(v_reuseFailAlloc_4005_, 1, v_snd_3993_);
v___x_4004_ = v_reuseFailAlloc_4005_;
goto v_reusejp_4003_;
}
v_reusejp_4003_:
{
return v___x_4004_;
}
}
else
{
lean_object* v_val_4006_; lean_object* v___x_4008_; uint8_t v_isShared_4009_; uint8_t v_isSharedCheck_4031_; 
v_val_4006_ = lean_ctor_get(v___x_4002_, 0);
v_isSharedCheck_4031_ = !lean_is_exclusive(v___x_4002_);
if (v_isSharedCheck_4031_ == 0)
{
v___x_4008_ = v___x_4002_;
v_isShared_4009_ = v_isSharedCheck_4031_;
goto v_resetjp_4007_;
}
else
{
lean_inc(v_val_4006_);
lean_dec(v___x_4002_);
v___x_4008_ = lean_box(0);
v_isShared_4009_ = v_isSharedCheck_4031_;
goto v_resetjp_4007_;
}
v_resetjp_4007_:
{
lean_object* v_comp_4010_; lean_object* v_parent_4011_; uint8_t v_retired_4012_; lean_object* v_table_4013_; lean_object* v_st_4014_; lean_object* v___x_4016_; uint8_t v_isShared_4017_; uint8_t v_isSharedCheck_4030_; 
v_comp_4010_ = lean_ctor_get(v_val_4006_, 0);
v_parent_4011_ = lean_ctor_get(v_val_4006_, 1);
v_retired_4012_ = lean_ctor_get_uint8(v_val_4006_, sizeof(void*)*4);
v_table_4013_ = lean_ctor_get(v_val_4006_, 2);
v_st_4014_ = lean_ctor_get(v_val_4006_, 3);
v_isSharedCheck_4030_ = !lean_is_exclusive(v_val_4006_);
if (v_isSharedCheck_4030_ == 0)
{
v___x_4016_ = v_val_4006_;
v_isShared_4017_ = v_isSharedCheck_4030_;
goto v_resetjp_4015_;
}
else
{
lean_inc(v_st_4014_);
lean_inc(v_table_4013_);
lean_inc(v_parent_4011_);
lean_inc(v_comp_4010_);
lean_dec(v_val_4006_);
v___x_4016_ = lean_box(0);
v_isShared_4017_ = v_isSharedCheck_4030_;
goto v_resetjp_4015_;
}
v_resetjp_4015_:
{
lean_object* v___x_4018_; lean_object* v___x_4019_; lean_object* v___x_4021_; 
v___x_4018_ = lean_box(0);
v___x_4019_ = lp_bounded_Bounded_KMap_set___redArg(v_table_4013_, v_k_3997_, v___x_4018_);
if (v_isShared_4017_ == 0)
{
lean_ctor_set(v___x_4016_, 2, v___x_4019_);
v___x_4021_ = v___x_4016_;
goto v_reusejp_4020_;
}
else
{
lean_object* v_reuseFailAlloc_4029_; 
v_reuseFailAlloc_4029_ = lean_alloc_ctor(0, 4, 1);
lean_ctor_set(v_reuseFailAlloc_4029_, 0, v_comp_4010_);
lean_ctor_set(v_reuseFailAlloc_4029_, 1, v_parent_4011_);
lean_ctor_set(v_reuseFailAlloc_4029_, 2, v___x_4019_);
lean_ctor_set(v_reuseFailAlloc_4029_, 3, v_st_4014_);
lean_ctor_set_uint8(v_reuseFailAlloc_4029_, sizeof(void*)*4, v_retired_4012_);
v___x_4021_ = v_reuseFailAlloc_4029_;
goto v_reusejp_4020_;
}
v_reusejp_4020_:
{
lean_object* v___x_4023_; 
if (v_isShared_4009_ == 0)
{
lean_ctor_set(v___x_4008_, 0, v___x_4021_);
v___x_4023_ = v___x_4008_;
goto v_reusejp_4022_;
}
else
{
lean_object* v_reuseFailAlloc_4028_; 
v_reuseFailAlloc_4028_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_4028_, 0, v___x_4021_);
v___x_4023_ = v_reuseFailAlloc_4028_;
goto v_reusejp_4022_;
}
v_reusejp_4022_:
{
lean_object* v___x_4024_; lean_object* v___x_4026_; 
v___x_4024_ = lp_bounded_Bounded_SMap_set___redArg(v_snd_3993_, v_n_3989_, v___x_4023_);
lean_dec(v_n_3989_);
if (v_isShared_3996_ == 0)
{
lean_ctor_set(v___x_3995_, 1, v___x_4024_);
lean_ctor_set(v___x_3995_, 0, v___x_4001_);
v___x_4026_ = v___x_3995_;
goto v_reusejp_4025_;
}
else
{
lean_object* v_reuseFailAlloc_4027_; 
v_reuseFailAlloc_4027_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_4027_, 0, v___x_4001_);
lean_ctor_set(v_reuseFailAlloc_4027_, 1, v___x_4024_);
v___x_4026_ = v_reuseFailAlloc_4027_;
goto v_reusejp_4025_;
}
v_reusejp_4025_:
{
return v___x_4026_;
}
}
}
}
}
}
}
}
case 1:
{
lean_object* v_fst_4033_; lean_object* v_snd_4034_; lean_object* v___x_4036_; uint8_t v_isShared_4037_; uint8_t v_isSharedCheck_4046_; 
v_fst_4033_ = lean_ctor_get(v_x_3990_, 0);
v_snd_4034_ = lean_ctor_get(v_x_3990_, 1);
v_isSharedCheck_4046_ = !lean_is_exclusive(v_x_3990_);
if (v_isSharedCheck_4046_ == 0)
{
v___x_4036_ = v_x_3990_;
v_isShared_4037_ = v_isSharedCheck_4046_;
goto v_resetjp_4035_;
}
else
{
lean_inc(v_snd_4034_);
lean_inc(v_fst_4033_);
lean_dec(v_x_3990_);
v___x_4036_ = lean_box(0);
v_isShared_4037_ = v_isSharedCheck_4046_;
goto v_resetjp_4035_;
}
v_resetjp_4035_:
{
lean_object* v_t_4038_; lean_object* v___x_4039_; lean_object* v___x_4040_; lean_object* v___x_4041_; lean_object* v___x_4042_; lean_object* v___x_4044_; 
v_t_4038_ = lean_ctor_get(v_x_3991_, 0);
lean_inc(v_t_4038_);
v___x_4039_ = lean_alloc_ctor(14, 2, 0);
lean_ctor_set(v___x_4039_, 0, v_n_3989_);
lean_ctor_set(v___x_4039_, 1, v_t_4038_);
v___x_4040_ = lean_box(0);
v___x_4041_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_4041_, 0, v___x_4039_);
lean_ctor_set(v___x_4041_, 1, v___x_4040_);
v___x_4042_ = l_List_appendTR___redArg(v_fst_4033_, v___x_4041_);
if (v_isShared_4037_ == 0)
{
lean_ctor_set(v___x_4036_, 0, v___x_4042_);
v___x_4044_ = v___x_4036_;
goto v_reusejp_4043_;
}
else
{
lean_object* v_reuseFailAlloc_4045_; 
v_reuseFailAlloc_4045_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_4045_, 0, v___x_4042_);
lean_ctor_set(v_reuseFailAlloc_4045_, 1, v_snd_4034_);
v___x_4044_ = v_reuseFailAlloc_4045_;
goto v_reusejp_4043_;
}
v_reusejp_4043_:
{
return v___x_4044_;
}
}
}
default: 
{
lean_object* v_fst_4047_; lean_object* v_snd_4048_; lean_object* v___x_4050_; uint8_t v_isShared_4051_; uint8_t v_isSharedCheck_4085_; 
v_fst_4047_ = lean_ctor_get(v_x_3990_, 0);
v_snd_4048_ = lean_ctor_get(v_x_3990_, 1);
v_isSharedCheck_4085_ = !lean_is_exclusive(v_x_3990_);
if (v_isSharedCheck_4085_ == 0)
{
v___x_4050_ = v_x_3990_;
v_isShared_4051_ = v_isSharedCheck_4085_;
goto v_resetjp_4049_;
}
else
{
lean_inc(v_snd_4048_);
lean_inc(v_fst_4047_);
lean_dec(v_x_3990_);
v___x_4050_ = lean_box(0);
v_isShared_4051_ = v_isSharedCheck_4085_;
goto v_resetjp_4049_;
}
v_resetjp_4049_:
{
lean_object* v_s_4052_; lean_object* v___x_4053_; lean_object* v___x_4054_; lean_object* v___x_4055_; lean_object* v___x_4056_; lean_object* v___x_4057_; 
v_s_4052_ = lean_ctor_get(v_x_3991_, 0);
lean_inc(v_s_4052_);
v___x_4053_ = lean_alloc_ctor(16, 2, 0);
lean_ctor_set(v___x_4053_, 0, v_n_3989_);
lean_ctor_set(v___x_4053_, 1, v_s_4052_);
v___x_4054_ = lean_box(0);
v___x_4055_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_4055_, 0, v___x_4053_);
lean_ctor_set(v___x_4055_, 1, v___x_4054_);
v___x_4056_ = l_List_appendTR___redArg(v_fst_4047_, v___x_4055_);
v___x_4057_ = lp_bounded_Bounded_SMap_get___redArg(v_snd_4048_, v_s_4052_);
if (lean_obj_tag(v___x_4057_) == 0)
{
lean_object* v___x_4059_; 
if (v_isShared_4051_ == 0)
{
lean_ctor_set(v___x_4050_, 0, v___x_4056_);
v___x_4059_ = v___x_4050_;
goto v_reusejp_4058_;
}
else
{
lean_object* v_reuseFailAlloc_4060_; 
v_reuseFailAlloc_4060_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_4060_, 0, v___x_4056_);
lean_ctor_set(v_reuseFailAlloc_4060_, 1, v_snd_4048_);
v___x_4059_ = v_reuseFailAlloc_4060_;
goto v_reusejp_4058_;
}
v_reusejp_4058_:
{
return v___x_4059_;
}
}
else
{
lean_object* v_val_4061_; lean_object* v___x_4063_; uint8_t v_isShared_4064_; uint8_t v_isSharedCheck_4084_; 
v_val_4061_ = lean_ctor_get(v___x_4057_, 0);
v_isSharedCheck_4084_ = !lean_is_exclusive(v___x_4057_);
if (v_isSharedCheck_4084_ == 0)
{
v___x_4063_ = v___x_4057_;
v_isShared_4064_ = v_isSharedCheck_4084_;
goto v_resetjp_4062_;
}
else
{
lean_inc(v_val_4061_);
lean_dec(v___x_4057_);
v___x_4063_ = lean_box(0);
v_isShared_4064_ = v_isSharedCheck_4084_;
goto v_resetjp_4062_;
}
v_resetjp_4062_:
{
lean_object* v_comp_4065_; lean_object* v_parent_4066_; lean_object* v_table_4067_; lean_object* v_st_4068_; lean_object* v___x_4070_; uint8_t v_isShared_4071_; uint8_t v_isSharedCheck_4083_; 
v_comp_4065_ = lean_ctor_get(v_val_4061_, 0);
v_parent_4066_ = lean_ctor_get(v_val_4061_, 1);
v_table_4067_ = lean_ctor_get(v_val_4061_, 2);
v_st_4068_ = lean_ctor_get(v_val_4061_, 3);
v_isSharedCheck_4083_ = !lean_is_exclusive(v_val_4061_);
if (v_isSharedCheck_4083_ == 0)
{
v___x_4070_ = v_val_4061_;
v_isShared_4071_ = v_isSharedCheck_4083_;
goto v_resetjp_4069_;
}
else
{
lean_inc(v_st_4068_);
lean_inc(v_table_4067_);
lean_inc(v_parent_4066_);
lean_inc(v_comp_4065_);
lean_dec(v_val_4061_);
v___x_4070_ = lean_box(0);
v_isShared_4071_ = v_isSharedCheck_4083_;
goto v_resetjp_4069_;
}
v_resetjp_4069_:
{
uint8_t v___x_4072_; lean_object* v___x_4074_; 
v___x_4072_ = 1;
if (v_isShared_4071_ == 0)
{
v___x_4074_ = v___x_4070_;
goto v_reusejp_4073_;
}
else
{
lean_object* v_reuseFailAlloc_4082_; 
v_reuseFailAlloc_4082_ = lean_alloc_ctor(0, 4, 1);
lean_ctor_set(v_reuseFailAlloc_4082_, 0, v_comp_4065_);
lean_ctor_set(v_reuseFailAlloc_4082_, 1, v_parent_4066_);
lean_ctor_set(v_reuseFailAlloc_4082_, 2, v_table_4067_);
lean_ctor_set(v_reuseFailAlloc_4082_, 3, v_st_4068_);
v___x_4074_ = v_reuseFailAlloc_4082_;
goto v_reusejp_4073_;
}
v_reusejp_4073_:
{
lean_object* v___x_4076_; 
lean_ctor_set_uint8(v___x_4074_, sizeof(void*)*4, v___x_4072_);
if (v_isShared_4064_ == 0)
{
lean_ctor_set(v___x_4063_, 0, v___x_4074_);
v___x_4076_ = v___x_4063_;
goto v_reusejp_4075_;
}
else
{
lean_object* v_reuseFailAlloc_4081_; 
v_reuseFailAlloc_4081_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_4081_, 0, v___x_4074_);
v___x_4076_ = v_reuseFailAlloc_4081_;
goto v_reusejp_4075_;
}
v_reusejp_4075_:
{
lean_object* v___x_4077_; lean_object* v___x_4079_; 
v___x_4077_ = lp_bounded_Bounded_SMap_set___redArg(v_snd_4048_, v_s_4052_, v___x_4076_);
if (v_isShared_4051_ == 0)
{
lean_ctor_set(v___x_4050_, 1, v___x_4077_);
lean_ctor_set(v___x_4050_, 0, v___x_4056_);
v___x_4079_ = v___x_4050_;
goto v_reusejp_4078_;
}
else
{
lean_object* v_reuseFailAlloc_4080_; 
v_reuseFailAlloc_4080_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_4080_, 0, v___x_4056_);
lean_ctor_set(v_reuseFailAlloc_4080_, 1, v___x_4077_);
v___x_4079_ = v_reuseFailAlloc_4080_;
goto v_reusejp_4078_;
}
v_reusejp_4078_:
{
return v___x_4079_;
}
}
}
}
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_applyInv___boxed(lean_object* v_n_4086_, lean_object* v_x_4087_, lean_object* v_x_4088_){
_start:
{
lean_object* v_res_4089_; 
v_res_4089_ = lp_bounded_Bounded_applyInv(v_n_4086_, v_x_4087_, v_x_4088_);
lean_dec_ref(v_x_4088_);
return v_res_4089_;
}
}
LEAN_EXPORT lean_object* lp_bounded_List_foldl___at___00Bounded_liftStep_spec__0(lean_object* v_n_4090_, lean_object* v_x_4091_, lean_object* v_x_4092_){
_start:
{
if (lean_obj_tag(v_x_4092_) == 0)
{
lean_dec(v_n_4090_);
return v_x_4091_;
}
else
{
lean_object* v_head_4093_; lean_object* v_tail_4094_; lean_object* v___x_4095_; 
v_head_4093_ = lean_ctor_get(v_x_4092_, 0);
v_tail_4094_ = lean_ctor_get(v_x_4092_, 1);
lean_inc(v_n_4090_);
v___x_4095_ = lp_bounded_Bounded_applyInv(v_n_4090_, v_x_4091_, v_head_4093_);
v_x_4091_ = v___x_4095_;
v_x_4092_ = v_tail_4094_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_List_foldl___at___00Bounded_liftStep_spec__0___boxed(lean_object* v_n_4097_, lean_object* v_x_4098_, lean_object* v_x_4099_){
_start:
{
lean_object* v_res_4100_; 
v_res_4100_ = lp_bounded_List_foldl___at___00Bounded_liftStep_spec__0(v_n_4097_, v_x_4098_, v_x_4099_);
lean_dec(v_x_4099_);
return v_res_4100_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_liftStep(lean_object* v_a_4101_, lean_object* v_00_u03b3_4102_, lean_object* v_d_4103_){
_start:
{
if (lean_obj_tag(v_d_4103_) == 0)
{
lean_object* v___x_4104_; 
lean_dec_ref(v_00_u03b3_4102_);
lean_dec_ref(v_a_4101_);
v___x_4104_ = lean_box(0);
return v___x_4104_;
}
else
{
switch(lean_obj_tag(v_a_4101_))
{
case 0:
{
lean_object* v_n_4105_; lean_object* v_c_4106_; lean_object* v___x_4108_; uint8_t v_isShared_4109_; uint8_t v_isSharedCheck_4123_; 
lean_dec_ref_known(v_d_4103_, 0);
v_n_4105_ = lean_ctor_get(v_a_4101_, 0);
v_c_4106_ = lean_ctor_get(v_a_4101_, 1);
v_isSharedCheck_4123_ = !lean_is_exclusive(v_a_4101_);
if (v_isSharedCheck_4123_ == 0)
{
v___x_4108_ = v_a_4101_;
v_isShared_4109_ = v_isSharedCheck_4123_;
goto v_resetjp_4107_;
}
else
{
lean_inc(v_c_4106_);
lean_inc(v_n_4105_);
lean_dec(v_a_4101_);
v___x_4108_ = lean_box(0);
v_isShared_4109_ = v_isSharedCheck_4123_;
goto v_resetjp_4107_;
}
v_resetjp_4107_:
{
lean_object* v___x_4110_; 
v___x_4110_ = lp_bounded_Bounded_SMap_get___redArg(v_00_u03b3_4102_, v_n_4105_);
if (lean_obj_tag(v___x_4110_) == 0)
{
lean_object* v___x_4111_; lean_object* v___x_4112_; lean_object* v___x_4114_; 
lean_inc(v_n_4105_);
v___x_4111_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_4111_, 0, v_n_4105_);
v___x_4112_ = lean_box(0);
if (v_isShared_4109_ == 0)
{
lean_ctor_set_tag(v___x_4108_, 1);
lean_ctor_set(v___x_4108_, 1, v___x_4112_);
lean_ctor_set(v___x_4108_, 0, v___x_4111_);
v___x_4114_ = v___x_4108_;
goto v_reusejp_4113_;
}
else
{
lean_object* v_reuseFailAlloc_4121_; 
v_reuseFailAlloc_4121_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_4121_, 0, v___x_4111_);
lean_ctor_set(v_reuseFailAlloc_4121_, 1, v___x_4112_);
v___x_4114_ = v_reuseFailAlloc_4121_;
goto v_reusejp_4113_;
}
v_reusejp_4113_:
{
lean_object* v___x_4115_; lean_object* v___x_4116_; lean_object* v___x_4117_; lean_object* v___x_4118_; lean_object* v___x_4119_; lean_object* v___x_4120_; 
v___x_4115_ = lean_box(0);
v___x_4116_ = lp_bounded_Bounded_freshFiber(v_c_4106_, v___x_4115_);
v___x_4117_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_4117_, 0, v___x_4116_);
v___x_4118_ = lp_bounded_Bounded_SMap_set___redArg(v_00_u03b3_4102_, v_n_4105_, v___x_4117_);
lean_dec(v_n_4105_);
v___x_4119_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_4119_, 0, v___x_4114_);
lean_ctor_set(v___x_4119_, 1, v___x_4118_);
v___x_4120_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_4120_, 0, v___x_4119_);
return v___x_4120_;
}
}
else
{
lean_object* v___x_4122_; 
lean_dec_ref_known(v___x_4110_, 1);
lean_del_object(v___x_4108_);
lean_dec_ref(v_c_4106_);
lean_dec(v_n_4105_);
lean_dec_ref(v_00_u03b3_4102_);
v___x_4122_ = lean_box(0);
return v___x_4122_;
}
}
}
case 1:
{
lean_object* v_n_4124_; lean_object* v___x_4126_; uint8_t v_isShared_4127_; uint8_t v_isSharedCheck_4158_; 
lean_dec_ref_known(v_d_4103_, 0);
v_n_4124_ = lean_ctor_get(v_a_4101_, 0);
v_isSharedCheck_4158_ = !lean_is_exclusive(v_a_4101_);
if (v_isSharedCheck_4158_ == 0)
{
v___x_4126_ = v_a_4101_;
v_isShared_4127_ = v_isSharedCheck_4158_;
goto v_resetjp_4125_;
}
else
{
lean_inc(v_n_4124_);
lean_dec(v_a_4101_);
v___x_4126_ = lean_box(0);
v_isShared_4127_ = v_isSharedCheck_4158_;
goto v_resetjp_4125_;
}
v_resetjp_4125_:
{
lean_object* v___x_4128_; 
v___x_4128_ = lp_bounded_Bounded_SMap_get___redArg(v_00_u03b3_4102_, v_n_4124_);
if (lean_obj_tag(v___x_4128_) == 0)
{
lean_object* v___x_4129_; 
lean_del_object(v___x_4126_);
lean_dec(v_n_4124_);
lean_dec_ref(v_00_u03b3_4102_);
v___x_4129_ = lean_box(0);
return v___x_4129_;
}
else
{
lean_object* v_val_4130_; lean_object* v___x_4132_; uint8_t v_isShared_4133_; uint8_t v_isSharedCheck_4157_; 
v_val_4130_ = lean_ctor_get(v___x_4128_, 0);
v_isSharedCheck_4157_ = !lean_is_exclusive(v___x_4128_);
if (v_isSharedCheck_4157_ == 0)
{
v___x_4132_ = v___x_4128_;
v_isShared_4133_ = v_isSharedCheck_4157_;
goto v_resetjp_4131_;
}
else
{
lean_inc(v_val_4130_);
lean_dec(v___x_4128_);
v___x_4132_ = lean_box(0);
v_isShared_4133_ = v_isSharedCheck_4157_;
goto v_resetjp_4131_;
}
v_resetjp_4131_:
{
lean_object* v_comp_4134_; lean_object* v_parent_4135_; lean_object* v_table_4136_; lean_object* v_st_4137_; lean_object* v___x_4139_; uint8_t v_isShared_4140_; uint8_t v_isSharedCheck_4156_; 
v_comp_4134_ = lean_ctor_get(v_val_4130_, 0);
v_parent_4135_ = lean_ctor_get(v_val_4130_, 1);
v_table_4136_ = lean_ctor_get(v_val_4130_, 2);
v_st_4137_ = lean_ctor_get(v_val_4130_, 3);
v_isSharedCheck_4156_ = !lean_is_exclusive(v_val_4130_);
if (v_isSharedCheck_4156_ == 0)
{
v___x_4139_ = v_val_4130_;
v_isShared_4140_ = v_isSharedCheck_4156_;
goto v_resetjp_4138_;
}
else
{
lean_inc(v_st_4137_);
lean_inc(v_table_4136_);
lean_inc(v_parent_4135_);
lean_inc(v_comp_4134_);
lean_dec(v_val_4130_);
v___x_4139_ = lean_box(0);
v_isShared_4140_ = v_isSharedCheck_4156_;
goto v_resetjp_4138_;
}
v_resetjp_4138_:
{
lean_object* v___x_4142_; 
lean_inc(v_n_4124_);
if (v_isShared_4127_ == 0)
{
v___x_4142_ = v___x_4126_;
goto v_reusejp_4141_;
}
else
{
lean_object* v_reuseFailAlloc_4155_; 
v_reuseFailAlloc_4155_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_4155_, 0, v_n_4124_);
v___x_4142_ = v_reuseFailAlloc_4155_;
goto v_reusejp_4141_;
}
v_reusejp_4141_:
{
lean_object* v___x_4143_; lean_object* v___x_4144_; uint8_t v___x_4145_; lean_object* v___x_4147_; 
v___x_4143_ = lean_box(0);
v___x_4144_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_4144_, 0, v___x_4142_);
lean_ctor_set(v___x_4144_, 1, v___x_4143_);
v___x_4145_ = 1;
if (v_isShared_4140_ == 0)
{
v___x_4147_ = v___x_4139_;
goto v_reusejp_4146_;
}
else
{
lean_object* v_reuseFailAlloc_4154_; 
v_reuseFailAlloc_4154_ = lean_alloc_ctor(0, 4, 1);
lean_ctor_set(v_reuseFailAlloc_4154_, 0, v_comp_4134_);
lean_ctor_set(v_reuseFailAlloc_4154_, 1, v_parent_4135_);
lean_ctor_set(v_reuseFailAlloc_4154_, 2, v_table_4136_);
lean_ctor_set(v_reuseFailAlloc_4154_, 3, v_st_4137_);
v___x_4147_ = v_reuseFailAlloc_4154_;
goto v_reusejp_4146_;
}
v_reusejp_4146_:
{
lean_object* v___x_4149_; 
lean_ctor_set_uint8(v___x_4147_, sizeof(void*)*4, v___x_4145_);
if (v_isShared_4133_ == 0)
{
lean_ctor_set(v___x_4132_, 0, v___x_4147_);
v___x_4149_ = v___x_4132_;
goto v_reusejp_4148_;
}
else
{
lean_object* v_reuseFailAlloc_4153_; 
v_reuseFailAlloc_4153_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_4153_, 0, v___x_4147_);
v___x_4149_ = v_reuseFailAlloc_4153_;
goto v_reusejp_4148_;
}
v_reusejp_4148_:
{
lean_object* v___x_4150_; lean_object* v___x_4151_; lean_object* v___x_4152_; 
v___x_4150_ = lp_bounded_Bounded_SMap_set___redArg(v_00_u03b3_4102_, v_n_4124_, v___x_4149_);
lean_dec(v_n_4124_);
v___x_4151_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_4151_, 0, v___x_4144_);
lean_ctor_set(v___x_4151_, 1, v___x_4150_);
v___x_4152_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_4152_, 0, v___x_4151_);
return v___x_4152_;
}
}
}
}
}
}
}
}
case 2:
{
lean_object* v_n_4159_; lean_object* v___x_4161_; uint8_t v_isShared_4162_; uint8_t v_isSharedCheck_4181_; 
lean_dec_ref_known(v_d_4103_, 0);
v_n_4159_ = lean_ctor_get(v_a_4101_, 0);
v_isSharedCheck_4181_ = !lean_is_exclusive(v_a_4101_);
if (v_isSharedCheck_4181_ == 0)
{
v___x_4161_ = v_a_4101_;
v_isShared_4162_ = v_isSharedCheck_4181_;
goto v_resetjp_4160_;
}
else
{
lean_inc(v_n_4159_);
lean_dec(v_a_4101_);
v___x_4161_ = lean_box(0);
v_isShared_4162_ = v_isSharedCheck_4181_;
goto v_resetjp_4160_;
}
v_resetjp_4160_:
{
lean_object* v___x_4163_; 
v___x_4163_ = lp_bounded_Bounded_SMap_get___redArg(v_00_u03b3_4102_, v_n_4159_);
if (lean_obj_tag(v___x_4163_) == 0)
{
lean_object* v___x_4164_; 
lean_del_object(v___x_4161_);
lean_dec(v_n_4159_);
lean_dec_ref(v_00_u03b3_4102_);
v___x_4164_ = lean_box(0);
return v___x_4164_;
}
else
{
lean_object* v___x_4166_; uint8_t v_isShared_4167_; uint8_t v_isSharedCheck_4179_; 
v_isSharedCheck_4179_ = !lean_is_exclusive(v___x_4163_);
if (v_isSharedCheck_4179_ == 0)
{
lean_object* v_unused_4180_; 
v_unused_4180_ = lean_ctor_get(v___x_4163_, 0);
lean_dec(v_unused_4180_);
v___x_4166_ = v___x_4163_;
v_isShared_4167_ = v_isSharedCheck_4179_;
goto v_resetjp_4165_;
}
else
{
lean_dec(v___x_4163_);
v___x_4166_ = lean_box(0);
v_isShared_4167_ = v_isSharedCheck_4179_;
goto v_resetjp_4165_;
}
v_resetjp_4165_:
{
lean_object* v___x_4169_; 
lean_inc(v_n_4159_);
if (v_isShared_4162_ == 0)
{
v___x_4169_ = v___x_4161_;
goto v_reusejp_4168_;
}
else
{
lean_object* v_reuseFailAlloc_4178_; 
v_reuseFailAlloc_4178_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v_reuseFailAlloc_4178_, 0, v_n_4159_);
v___x_4169_ = v_reuseFailAlloc_4178_;
goto v_reusejp_4168_;
}
v_reusejp_4168_:
{
lean_object* v___x_4170_; lean_object* v___x_4171_; lean_object* v___x_4172_; lean_object* v___x_4173_; lean_object* v___x_4174_; lean_object* v___x_4176_; 
v___x_4170_ = lean_box(0);
v___x_4171_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_4171_, 0, v___x_4169_);
lean_ctor_set(v___x_4171_, 1, v___x_4170_);
v___x_4172_ = lean_box(0);
v___x_4173_ = lp_bounded_Bounded_SMap_set___redArg(v_00_u03b3_4102_, v_n_4159_, v___x_4172_);
lean_dec(v_n_4159_);
v___x_4174_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_4174_, 0, v___x_4171_);
lean_ctor_set(v___x_4174_, 1, v___x_4173_);
if (v_isShared_4167_ == 0)
{
lean_ctor_set(v___x_4166_, 0, v___x_4174_);
v___x_4176_ = v___x_4166_;
goto v_reusejp_4175_;
}
else
{
lean_object* v_reuseFailAlloc_4177_; 
v_reuseFailAlloc_4177_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_4177_, 0, v___x_4174_);
v___x_4176_ = v_reuseFailAlloc_4177_;
goto v_reusejp_4175_;
}
v_reusejp_4175_:
{
return v___x_4176_;
}
}
}
}
}
}
case 3:
{
lean_object* v_n_4182_; lean_object* v___x_4184_; uint8_t v_isShared_4185_; uint8_t v_isSharedCheck_4214_; 
lean_dec_ref_known(v_d_4103_, 0);
v_n_4182_ = lean_ctor_get(v_a_4101_, 0);
v_isSharedCheck_4214_ = !lean_is_exclusive(v_a_4101_);
if (v_isSharedCheck_4214_ == 0)
{
v___x_4184_ = v_a_4101_;
v_isShared_4185_ = v_isSharedCheck_4214_;
goto v_resetjp_4183_;
}
else
{
lean_inc(v_n_4182_);
lean_dec(v_a_4101_);
v___x_4184_ = lean_box(0);
v_isShared_4185_ = v_isSharedCheck_4214_;
goto v_resetjp_4183_;
}
v_resetjp_4183_:
{
lean_object* v___x_4186_; 
v___x_4186_ = lp_bounded_Bounded_SMap_get___redArg(v_00_u03b3_4102_, v_n_4182_);
if (lean_obj_tag(v___x_4186_) == 0)
{
lean_object* v___x_4187_; 
lean_del_object(v___x_4184_);
lean_dec(v_n_4182_);
lean_dec_ref(v_00_u03b3_4102_);
v___x_4187_ = lean_box(0);
return v___x_4187_;
}
else
{
lean_object* v_val_4188_; lean_object* v___x_4190_; uint8_t v_isShared_4191_; uint8_t v_isSharedCheck_4213_; 
v_val_4188_ = lean_ctor_get(v___x_4186_, 0);
v_isSharedCheck_4213_ = !lean_is_exclusive(v___x_4186_);
if (v_isSharedCheck_4213_ == 0)
{
v___x_4190_ = v___x_4186_;
v_isShared_4191_ = v_isSharedCheck_4213_;
goto v_resetjp_4189_;
}
else
{
lean_inc(v_val_4188_);
lean_dec(v___x_4186_);
v___x_4190_ = lean_box(0);
v_isShared_4191_ = v_isSharedCheck_4213_;
goto v_resetjp_4189_;
}
v_resetjp_4189_:
{
lean_object* v_st_4192_; 
v_st_4192_ = lean_ctor_get(v_val_4188_, 3);
if (lean_obj_tag(v_st_4192_) == 0)
{
lean_object* v_comp_4193_; lean_object* v_parent_4194_; uint8_t v_retired_4195_; lean_object* v_table_4196_; lean_object* v_script_4197_; lean_object* v___x_4199_; 
v_comp_4193_ = lean_ctor_get(v_val_4188_, 0);
lean_inc_ref(v_comp_4193_);
v_parent_4194_ = lean_ctor_get(v_val_4188_, 1);
lean_inc(v_parent_4194_);
v_retired_4195_ = lean_ctor_get_uint8(v_val_4188_, sizeof(void*)*4);
v_table_4196_ = lean_ctor_get(v_val_4188_, 2);
lean_inc_ref(v_table_4196_);
v_script_4197_ = lean_ctor_get(v_comp_4193_, 2);
lean_inc(v_n_4182_);
if (v_isShared_4185_ == 0)
{
v___x_4199_ = v___x_4184_;
goto v_reusejp_4198_;
}
else
{
lean_object* v_reuseFailAlloc_4211_; 
v_reuseFailAlloc_4211_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v_reuseFailAlloc_4211_, 0, v_n_4182_);
v___x_4199_ = v_reuseFailAlloc_4211_;
goto v_reusejp_4198_;
}
v_reusejp_4198_:
{
lean_object* v___x_4200_; lean_object* v___x_4201_; lean_object* v___x_4202_; lean_object* v___x_4203_; lean_object* v___x_4204_; lean_object* v___x_4206_; 
v___x_4200_ = lean_box(0);
v___x_4201_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_4201_, 0, v___x_4199_);
lean_ctor_set(v___x_4201_, 1, v___x_4200_);
lean_inc_ref(v_00_u03b3_4102_);
v___x_4202_ = lp_bounded_Bounded_partialTarget(v_00_u03b3_4102_, v_val_4188_);
lean_inc(v_script_4197_);
v___x_4203_ = lean_alloc_ctor(1, 3, 0);
lean_ctor_set(v___x_4203_, 0, v_script_4197_);
lean_ctor_set(v___x_4203_, 1, v___x_4200_);
lean_ctor_set(v___x_4203_, 2, v___x_4202_);
v___x_4204_ = lean_alloc_ctor(0, 4, 1);
lean_ctor_set(v___x_4204_, 0, v_comp_4193_);
lean_ctor_set(v___x_4204_, 1, v_parent_4194_);
lean_ctor_set(v___x_4204_, 2, v_table_4196_);
lean_ctor_set(v___x_4204_, 3, v___x_4203_);
lean_ctor_set_uint8(v___x_4204_, sizeof(void*)*4, v_retired_4195_);
if (v_isShared_4191_ == 0)
{
lean_ctor_set(v___x_4190_, 0, v___x_4204_);
v___x_4206_ = v___x_4190_;
goto v_reusejp_4205_;
}
else
{
lean_object* v_reuseFailAlloc_4210_; 
v_reuseFailAlloc_4210_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_4210_, 0, v___x_4204_);
v___x_4206_ = v_reuseFailAlloc_4210_;
goto v_reusejp_4205_;
}
v_reusejp_4205_:
{
lean_object* v___x_4207_; lean_object* v___x_4208_; lean_object* v___x_4209_; 
v___x_4207_ = lp_bounded_Bounded_SMap_set___redArg(v_00_u03b3_4102_, v_n_4182_, v___x_4206_);
lean_dec(v_n_4182_);
v___x_4208_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_4208_, 0, v___x_4201_);
lean_ctor_set(v___x_4208_, 1, v___x_4207_);
v___x_4209_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_4209_, 0, v___x_4208_);
return v___x_4209_;
}
}
}
else
{
lean_object* v___x_4212_; 
lean_del_object(v___x_4190_);
lean_dec(v_val_4188_);
lean_del_object(v___x_4184_);
lean_dec(v_n_4182_);
lean_dec_ref(v_00_u03b3_4102_);
v___x_4212_ = lean_box(0);
return v___x_4212_;
}
}
}
}
}
case 4:
{
lean_object* v_n_4215_; lean_object* v_creg_4216_; lean_object* v___x_4217_; 
lean_dec_ref_known(v_d_4103_, 0);
v_n_4215_ = lean_ctor_get(v_a_4101_, 0);
lean_inc(v_n_4215_);
v_creg_4216_ = lean_ctor_get(v_a_4101_, 1);
lean_inc(v_creg_4216_);
lean_dec_ref_known(v_a_4101_, 2);
v___x_4217_ = lp_bounded_Bounded_SMap_get___redArg(v_00_u03b3_4102_, v_n_4215_);
if (lean_obj_tag(v___x_4217_) == 0)
{
lean_object* v___x_4218_; 
lean_dec(v_creg_4216_);
lean_dec(v_n_4215_);
lean_dec_ref(v_00_u03b3_4102_);
v___x_4218_ = lean_box(0);
return v___x_4218_;
}
else
{
lean_object* v_val_4219_; lean_object* v_st_4220_; 
v_val_4219_ = lean_ctor_get(v___x_4217_, 0);
lean_inc(v_val_4219_);
lean_dec_ref_known(v___x_4217_, 1);
v_st_4220_ = lean_ctor_get(v_val_4219_, 3);
if (lean_obj_tag(v_st_4220_) == 1)
{
lean_object* v_remaining_4221_; lean_object* v_acc_4222_; lean_object* v_view_4223_; lean_object* v___x_4224_; 
v_remaining_4221_ = lean_ctor_get(v_st_4220_, 0);
v_acc_4222_ = lean_ctor_get(v_st_4220_, 1);
lean_inc(v_acc_4222_);
v_view_4223_ = lean_ctor_get(v_st_4220_, 2);
lean_inc_ref(v_view_4223_);
v___x_4224_ = l_List_head_x3f___redArg(v_remaining_4221_);
if (lean_obj_tag(v___x_4224_) == 0)
{
lean_object* v___x_4225_; 
lean_dec_ref(v_view_4223_);
lean_dec(v_acc_4222_);
lean_dec(v_val_4219_);
lean_dec(v_creg_4216_);
lean_dec(v_n_4215_);
lean_dec_ref(v_00_u03b3_4102_);
v___x_4225_ = lean_box(0);
return v___x_4225_;
}
else
{
lean_object* v_val_4226_; lean_object* v___x_4228_; uint8_t v_isShared_4229_; uint8_t v_isSharedCheck_4237_; 
v_val_4226_ = lean_ctor_get(v___x_4224_, 0);
v_isSharedCheck_4237_ = !lean_is_exclusive(v___x_4224_);
if (v_isSharedCheck_4237_ == 0)
{
v___x_4228_ = v___x_4224_;
v_isShared_4229_ = v_isSharedCheck_4237_;
goto v_resetjp_4227_;
}
else
{
lean_inc(v_val_4226_);
lean_dec(v___x_4224_);
v___x_4228_ = lean_box(0);
v_isShared_4229_ = v_isSharedCheck_4237_;
goto v_resetjp_4227_;
}
v_resetjp_4227_:
{
lean_object* v___y_4231_; 
if (lean_obj_tag(v_remaining_4221_) == 0)
{
v___y_4231_ = v_remaining_4221_;
goto v___jp_4230_;
}
else
{
lean_object* v_tail_4236_; 
v_tail_4236_ = lean_ctor_get(v_remaining_4221_, 1);
lean_inc(v_tail_4236_);
v___y_4231_ = v_tail_4236_;
goto v___jp_4230_;
}
v___jp_4230_:
{
lean_object* v___x_4232_; lean_object* v___x_4234_; 
v___x_4232_ = lp_bounded_Bounded_execStep(v_00_u03b3_4102_, v_n_4215_, v_val_4219_, v_val_4226_, v___y_4231_, v_acc_4222_, v_view_4223_, v_creg_4216_);
if (v_isShared_4229_ == 0)
{
lean_ctor_set(v___x_4228_, 0, v___x_4232_);
v___x_4234_ = v___x_4228_;
goto v_reusejp_4233_;
}
else
{
lean_object* v_reuseFailAlloc_4235_; 
v_reuseFailAlloc_4235_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_4235_, 0, v___x_4232_);
v___x_4234_ = v_reuseFailAlloc_4235_;
goto v_reusejp_4233_;
}
v_reusejp_4233_:
{
return v___x_4234_;
}
}
}
}
}
else
{
lean_object* v___x_4238_; 
lean_dec(v_val_4219_);
lean_dec(v_creg_4216_);
lean_dec(v_n_4215_);
lean_dec_ref(v_00_u03b3_4102_);
v___x_4238_ = lean_box(0);
return v___x_4238_;
}
}
}
case 5:
{
lean_object* v_n_4239_; lean_object* v___x_4241_; uint8_t v_isShared_4242_; uint8_t v_isSharedCheck_4278_; 
lean_dec_ref_known(v_d_4103_, 0);
v_n_4239_ = lean_ctor_get(v_a_4101_, 0);
v_isSharedCheck_4278_ = !lean_is_exclusive(v_a_4101_);
if (v_isSharedCheck_4278_ == 0)
{
v___x_4241_ = v_a_4101_;
v_isShared_4242_ = v_isSharedCheck_4278_;
goto v_resetjp_4240_;
}
else
{
lean_inc(v_n_4239_);
lean_dec(v_a_4101_);
v___x_4241_ = lean_box(0);
v_isShared_4242_ = v_isSharedCheck_4278_;
goto v_resetjp_4240_;
}
v_resetjp_4240_:
{
lean_object* v___x_4243_; 
v___x_4243_ = lp_bounded_Bounded_SMap_get___redArg(v_00_u03b3_4102_, v_n_4239_);
if (lean_obj_tag(v___x_4243_) == 0)
{
lean_object* v___x_4244_; 
lean_del_object(v___x_4241_);
lean_dec(v_n_4239_);
lean_dec_ref(v_00_u03b3_4102_);
v___x_4244_ = lean_box(0);
return v___x_4244_;
}
else
{
lean_object* v_val_4245_; lean_object* v___x_4247_; uint8_t v_isShared_4248_; uint8_t v_isSharedCheck_4277_; 
v_val_4245_ = lean_ctor_get(v___x_4243_, 0);
v_isSharedCheck_4277_ = !lean_is_exclusive(v___x_4243_);
if (v_isSharedCheck_4277_ == 0)
{
v___x_4247_ = v___x_4243_;
v_isShared_4248_ = v_isSharedCheck_4277_;
goto v_resetjp_4246_;
}
else
{
lean_inc(v_val_4245_);
lean_dec(v___x_4243_);
v___x_4247_ = lean_box(0);
v_isShared_4248_ = v_isSharedCheck_4277_;
goto v_resetjp_4246_;
}
v_resetjp_4246_:
{
lean_object* v_st_4249_; 
v_st_4249_ = lean_ctor_get(v_val_4245_, 3);
lean_inc_ref(v_st_4249_);
if (lean_obj_tag(v_st_4249_) == 1)
{
lean_object* v_comp_4250_; lean_object* v_parent_4251_; uint8_t v_retired_4252_; lean_object* v_table_4253_; lean_object* v___x_4255_; uint8_t v_isShared_4256_; uint8_t v_isSharedCheck_4274_; 
v_comp_4250_ = lean_ctor_get(v_val_4245_, 0);
v_parent_4251_ = lean_ctor_get(v_val_4245_, 1);
v_retired_4252_ = lean_ctor_get_uint8(v_val_4245_, sizeof(void*)*4);
v_table_4253_ = lean_ctor_get(v_val_4245_, 2);
v_isSharedCheck_4274_ = !lean_is_exclusive(v_val_4245_);
if (v_isSharedCheck_4274_ == 0)
{
lean_object* v_unused_4275_; 
v_unused_4275_ = lean_ctor_get(v_val_4245_, 3);
lean_dec(v_unused_4275_);
v___x_4255_ = v_val_4245_;
v_isShared_4256_ = v_isSharedCheck_4274_;
goto v_resetjp_4254_;
}
else
{
lean_inc(v_table_4253_);
lean_inc(v_parent_4251_);
lean_inc(v_comp_4250_);
lean_dec(v_val_4245_);
v___x_4255_ = lean_box(0);
v_isShared_4256_ = v_isSharedCheck_4274_;
goto v_resetjp_4254_;
}
v_resetjp_4254_:
{
lean_object* v_acc_4257_; lean_object* v_view_4258_; lean_object* v___x_4260_; 
v_acc_4257_ = lean_ctor_get(v_st_4249_, 1);
lean_inc(v_acc_4257_);
v_view_4258_ = lean_ctor_get(v_st_4249_, 2);
lean_inc_ref(v_view_4258_);
lean_dec_ref_known(v_st_4249_, 3);
lean_inc(v_n_4239_);
if (v_isShared_4242_ == 0)
{
lean_ctor_set_tag(v___x_4241_, 11);
v___x_4260_ = v___x_4241_;
goto v_reusejp_4259_;
}
else
{
lean_object* v_reuseFailAlloc_4273_; 
v_reuseFailAlloc_4273_ = lean_alloc_ctor(11, 1, 0);
lean_ctor_set(v_reuseFailAlloc_4273_, 0, v_n_4239_);
v___x_4260_ = v_reuseFailAlloc_4273_;
goto v_reusejp_4259_;
}
v_reusejp_4259_:
{
lean_object* v___x_4261_; lean_object* v___x_4262_; lean_object* v___x_4263_; lean_object* v___x_4265_; 
v___x_4261_ = lean_box(0);
v___x_4262_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_4262_, 0, v___x_4260_);
lean_ctor_set(v___x_4262_, 1, v___x_4261_);
v___x_4263_ = lean_alloc_ctor(2, 2, 0);
lean_ctor_set(v___x_4263_, 0, v_acc_4257_);
lean_ctor_set(v___x_4263_, 1, v_view_4258_);
if (v_isShared_4256_ == 0)
{
lean_ctor_set(v___x_4255_, 3, v___x_4263_);
v___x_4265_ = v___x_4255_;
goto v_reusejp_4264_;
}
else
{
lean_object* v_reuseFailAlloc_4272_; 
v_reuseFailAlloc_4272_ = lean_alloc_ctor(0, 4, 1);
lean_ctor_set(v_reuseFailAlloc_4272_, 0, v_comp_4250_);
lean_ctor_set(v_reuseFailAlloc_4272_, 1, v_parent_4251_);
lean_ctor_set(v_reuseFailAlloc_4272_, 2, v_table_4253_);
lean_ctor_set(v_reuseFailAlloc_4272_, 3, v___x_4263_);
lean_ctor_set_uint8(v_reuseFailAlloc_4272_, sizeof(void*)*4, v_retired_4252_);
v___x_4265_ = v_reuseFailAlloc_4272_;
goto v_reusejp_4264_;
}
v_reusejp_4264_:
{
lean_object* v___x_4267_; 
if (v_isShared_4248_ == 0)
{
lean_ctor_set(v___x_4247_, 0, v___x_4265_);
v___x_4267_ = v___x_4247_;
goto v_reusejp_4266_;
}
else
{
lean_object* v_reuseFailAlloc_4271_; 
v_reuseFailAlloc_4271_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_4271_, 0, v___x_4265_);
v___x_4267_ = v_reuseFailAlloc_4271_;
goto v_reusejp_4266_;
}
v_reusejp_4266_:
{
lean_object* v___x_4268_; lean_object* v___x_4269_; lean_object* v___x_4270_; 
v___x_4268_ = lp_bounded_Bounded_SMap_set___redArg(v_00_u03b3_4102_, v_n_4239_, v___x_4267_);
lean_dec(v_n_4239_);
v___x_4269_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_4269_, 0, v___x_4262_);
lean_ctor_set(v___x_4269_, 1, v___x_4268_);
v___x_4270_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_4270_, 0, v___x_4269_);
return v___x_4270_;
}
}
}
}
}
else
{
lean_object* v___x_4276_; 
lean_dec_ref(v_st_4249_);
lean_del_object(v___x_4247_);
lean_dec(v_val_4245_);
lean_del_object(v___x_4241_);
lean_dec(v_n_4239_);
lean_dec_ref(v_00_u03b3_4102_);
v___x_4276_ = lean_box(0);
return v___x_4276_;
}
}
}
}
}
case 6:
{
uint8_t v_v_4279_; lean_object* v_n_4280_; lean_object* v___x_4282_; uint8_t v_isShared_4283_; uint8_t v_isSharedCheck_4325_; 
v_v_4279_ = lean_ctor_get_uint8(v_d_4103_, 0);
lean_dec_ref_known(v_d_4103_, 0);
v_n_4280_ = lean_ctor_get(v_a_4101_, 0);
v_isSharedCheck_4325_ = !lean_is_exclusive(v_a_4101_);
if (v_isSharedCheck_4325_ == 0)
{
v___x_4282_ = v_a_4101_;
v_isShared_4283_ = v_isSharedCheck_4325_;
goto v_resetjp_4281_;
}
else
{
lean_inc(v_n_4280_);
lean_dec(v_a_4101_);
v___x_4282_ = lean_box(0);
v_isShared_4283_ = v_isSharedCheck_4325_;
goto v_resetjp_4281_;
}
v_resetjp_4281_:
{
lean_object* v___x_4284_; 
v___x_4284_ = lp_bounded_Bounded_SMap_get___redArg(v_00_u03b3_4102_, v_n_4280_);
if (lean_obj_tag(v___x_4284_) == 0)
{
lean_object* v___x_4285_; 
lean_del_object(v___x_4282_);
lean_dec(v_n_4280_);
lean_dec_ref(v_00_u03b3_4102_);
v___x_4285_ = lean_box(0);
return v___x_4285_;
}
else
{
lean_object* v_val_4286_; lean_object* v___x_4288_; uint8_t v_isShared_4289_; uint8_t v_isSharedCheck_4324_; 
v_val_4286_ = lean_ctor_get(v___x_4284_, 0);
v_isSharedCheck_4324_ = !lean_is_exclusive(v___x_4284_);
if (v_isSharedCheck_4324_ == 0)
{
v___x_4288_ = v___x_4284_;
v_isShared_4289_ = v_isSharedCheck_4324_;
goto v_resetjp_4287_;
}
else
{
lean_inc(v_val_4286_);
lean_dec(v___x_4284_);
v___x_4288_ = lean_box(0);
v_isShared_4289_ = v_isSharedCheck_4324_;
goto v_resetjp_4287_;
}
v_resetjp_4287_:
{
lean_object* v_st_4290_; 
v_st_4290_ = lean_ctor_get(v_val_4286_, 3);
lean_inc_ref(v_st_4290_);
if (lean_obj_tag(v_st_4290_) == 1)
{
lean_object* v_comp_4291_; lean_object* v_parent_4292_; uint8_t v_retired_4293_; lean_object* v_table_4294_; lean_object* v___x_4296_; uint8_t v_isShared_4297_; uint8_t v_isSharedCheck_4321_; 
v_comp_4291_ = lean_ctor_get(v_val_4286_, 0);
v_parent_4292_ = lean_ctor_get(v_val_4286_, 1);
v_retired_4293_ = lean_ctor_get_uint8(v_val_4286_, sizeof(void*)*4);
v_table_4294_ = lean_ctor_get(v_val_4286_, 2);
v_isSharedCheck_4321_ = !lean_is_exclusive(v_val_4286_);
if (v_isSharedCheck_4321_ == 0)
{
lean_object* v_unused_4322_; 
v_unused_4322_ = lean_ctor_get(v_val_4286_, 3);
lean_dec(v_unused_4322_);
v___x_4296_ = v_val_4286_;
v_isShared_4297_ = v_isSharedCheck_4321_;
goto v_resetjp_4295_;
}
else
{
lean_inc(v_table_4294_);
lean_inc(v_parent_4292_);
lean_inc(v_comp_4291_);
lean_dec(v_val_4286_);
v___x_4296_ = lean_box(0);
v_isShared_4297_ = v_isSharedCheck_4321_;
goto v_resetjp_4295_;
}
v_resetjp_4295_:
{
lean_object* v_acc_4298_; lean_object* v_view_4299_; lean_object* v___y_4301_; uint8_t v___x_4318_; uint8_t v___x_4319_; 
v_acc_4298_ = lean_ctor_get(v_st_4290_, 1);
lean_inc(v_acc_4298_);
v_view_4299_ = lean_ctor_get(v_st_4290_, 2);
lean_inc_ref(v_view_4299_);
lean_dec_ref_known(v_st_4290_, 3);
v___x_4318_ = 2;
v___x_4319_ = lp_bounded_Bounded_instDecidableEqVariant(v_v_4279_, v___x_4318_);
if (v___x_4319_ == 0)
{
v___y_4301_ = v_acc_4298_;
goto v___jp_4300_;
}
else
{
lean_object* v___x_4320_; 
lean_dec(v_acc_4298_);
v___x_4320_ = lean_box(0);
v___y_4301_ = v___x_4320_;
goto v___jp_4300_;
}
v___jp_4300_:
{
lean_object* v___x_4303_; 
lean_inc(v_n_4280_);
if (v_isShared_4283_ == 0)
{
lean_ctor_set_tag(v___x_4282_, 12);
v___x_4303_ = v___x_4282_;
goto v_reusejp_4302_;
}
else
{
lean_object* v_reuseFailAlloc_4317_; 
v_reuseFailAlloc_4317_ = lean_alloc_ctor(12, 1, 0);
lean_ctor_set(v_reuseFailAlloc_4317_, 0, v_n_4280_);
v___x_4303_ = v_reuseFailAlloc_4317_;
goto v_reusejp_4302_;
}
v_reusejp_4302_:
{
lean_object* v___x_4304_; lean_object* v___x_4305_; uint8_t v___x_4306_; lean_object* v___x_4307_; lean_object* v___x_4309_; 
v___x_4304_ = lean_box(0);
v___x_4305_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_4305_, 0, v___x_4303_);
lean_ctor_set(v___x_4305_, 1, v___x_4304_);
v___x_4306_ = 0;
v___x_4307_ = lean_alloc_ctor(3, 2, 1);
lean_ctor_set(v___x_4307_, 0, v___y_4301_);
lean_ctor_set(v___x_4307_, 1, v_view_4299_);
lean_ctor_set_uint8(v___x_4307_, sizeof(void*)*2, v___x_4306_);
if (v_isShared_4297_ == 0)
{
lean_ctor_set(v___x_4296_, 3, v___x_4307_);
v___x_4309_ = v___x_4296_;
goto v_reusejp_4308_;
}
else
{
lean_object* v_reuseFailAlloc_4316_; 
v_reuseFailAlloc_4316_ = lean_alloc_ctor(0, 4, 1);
lean_ctor_set(v_reuseFailAlloc_4316_, 0, v_comp_4291_);
lean_ctor_set(v_reuseFailAlloc_4316_, 1, v_parent_4292_);
lean_ctor_set(v_reuseFailAlloc_4316_, 2, v_table_4294_);
lean_ctor_set(v_reuseFailAlloc_4316_, 3, v___x_4307_);
lean_ctor_set_uint8(v_reuseFailAlloc_4316_, sizeof(void*)*4, v_retired_4293_);
v___x_4309_ = v_reuseFailAlloc_4316_;
goto v_reusejp_4308_;
}
v_reusejp_4308_:
{
lean_object* v___x_4311_; 
if (v_isShared_4289_ == 0)
{
lean_ctor_set(v___x_4288_, 0, v___x_4309_);
v___x_4311_ = v___x_4288_;
goto v_reusejp_4310_;
}
else
{
lean_object* v_reuseFailAlloc_4315_; 
v_reuseFailAlloc_4315_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_4315_, 0, v___x_4309_);
v___x_4311_ = v_reuseFailAlloc_4315_;
goto v_reusejp_4310_;
}
v_reusejp_4310_:
{
lean_object* v___x_4312_; lean_object* v___x_4313_; lean_object* v___x_4314_; 
v___x_4312_ = lp_bounded_Bounded_SMap_set___redArg(v_00_u03b3_4102_, v_n_4280_, v___x_4311_);
lean_dec(v_n_4280_);
v___x_4313_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_4313_, 0, v___x_4305_);
lean_ctor_set(v___x_4313_, 1, v___x_4312_);
v___x_4314_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_4314_, 0, v___x_4313_);
return v___x_4314_;
}
}
}
}
}
}
else
{
lean_object* v___x_4323_; 
lean_dec_ref(v_st_4290_);
lean_del_object(v___x_4288_);
lean_dec(v_val_4286_);
lean_del_object(v___x_4282_);
lean_dec(v_n_4280_);
lean_dec_ref(v_00_u03b3_4102_);
v___x_4323_ = lean_box(0);
return v___x_4323_;
}
}
}
}
}
case 7:
{
uint8_t v_v_4326_; lean_object* v_n_4327_; lean_object* v___x_4329_; uint8_t v_isShared_4330_; uint8_t v_isSharedCheck_4372_; 
v_v_4326_ = lean_ctor_get_uint8(v_d_4103_, 0);
lean_dec_ref_known(v_d_4103_, 0);
v_n_4327_ = lean_ctor_get(v_a_4101_, 0);
v_isSharedCheck_4372_ = !lean_is_exclusive(v_a_4101_);
if (v_isSharedCheck_4372_ == 0)
{
v___x_4329_ = v_a_4101_;
v_isShared_4330_ = v_isSharedCheck_4372_;
goto v_resetjp_4328_;
}
else
{
lean_inc(v_n_4327_);
lean_dec(v_a_4101_);
v___x_4329_ = lean_box(0);
v_isShared_4330_ = v_isSharedCheck_4372_;
goto v_resetjp_4328_;
}
v_resetjp_4328_:
{
lean_object* v___x_4331_; 
v___x_4331_ = lp_bounded_Bounded_SMap_get___redArg(v_00_u03b3_4102_, v_n_4327_);
if (lean_obj_tag(v___x_4331_) == 0)
{
lean_object* v___x_4332_; 
lean_del_object(v___x_4329_);
lean_dec(v_n_4327_);
lean_dec_ref(v_00_u03b3_4102_);
v___x_4332_ = lean_box(0);
return v___x_4332_;
}
else
{
lean_object* v_val_4333_; lean_object* v___x_4335_; uint8_t v_isShared_4336_; uint8_t v_isSharedCheck_4371_; 
v_val_4333_ = lean_ctor_get(v___x_4331_, 0);
v_isSharedCheck_4371_ = !lean_is_exclusive(v___x_4331_);
if (v_isSharedCheck_4371_ == 0)
{
v___x_4335_ = v___x_4331_;
v_isShared_4336_ = v_isSharedCheck_4371_;
goto v_resetjp_4334_;
}
else
{
lean_inc(v_val_4333_);
lean_dec(v___x_4331_);
v___x_4335_ = lean_box(0);
v_isShared_4336_ = v_isSharedCheck_4371_;
goto v_resetjp_4334_;
}
v_resetjp_4334_:
{
lean_object* v_st_4337_; 
v_st_4337_ = lean_ctor_get(v_val_4333_, 3);
lean_inc_ref(v_st_4337_);
if (lean_obj_tag(v_st_4337_) == 1)
{
lean_object* v_comp_4338_; lean_object* v_parent_4339_; uint8_t v_retired_4340_; lean_object* v_table_4341_; lean_object* v___x_4343_; uint8_t v_isShared_4344_; uint8_t v_isSharedCheck_4368_; 
v_comp_4338_ = lean_ctor_get(v_val_4333_, 0);
v_parent_4339_ = lean_ctor_get(v_val_4333_, 1);
v_retired_4340_ = lean_ctor_get_uint8(v_val_4333_, sizeof(void*)*4);
v_table_4341_ = lean_ctor_get(v_val_4333_, 2);
v_isSharedCheck_4368_ = !lean_is_exclusive(v_val_4333_);
if (v_isSharedCheck_4368_ == 0)
{
lean_object* v_unused_4369_; 
v_unused_4369_ = lean_ctor_get(v_val_4333_, 3);
lean_dec(v_unused_4369_);
v___x_4343_ = v_val_4333_;
v_isShared_4344_ = v_isSharedCheck_4368_;
goto v_resetjp_4342_;
}
else
{
lean_inc(v_table_4341_);
lean_inc(v_parent_4339_);
lean_inc(v_comp_4338_);
lean_dec(v_val_4333_);
v___x_4343_ = lean_box(0);
v_isShared_4344_ = v_isSharedCheck_4368_;
goto v_resetjp_4342_;
}
v_resetjp_4342_:
{
lean_object* v_acc_4345_; lean_object* v_view_4346_; lean_object* v___y_4348_; uint8_t v___x_4365_; uint8_t v___x_4366_; 
v_acc_4345_ = lean_ctor_get(v_st_4337_, 1);
lean_inc(v_acc_4345_);
v_view_4346_ = lean_ctor_get(v_st_4337_, 2);
lean_inc_ref(v_view_4346_);
lean_dec_ref_known(v_st_4337_, 3);
v___x_4365_ = 2;
v___x_4366_ = lp_bounded_Bounded_instDecidableEqVariant(v_v_4326_, v___x_4365_);
if (v___x_4366_ == 0)
{
v___y_4348_ = v_acc_4345_;
goto v___jp_4347_;
}
else
{
lean_object* v___x_4367_; 
lean_dec(v_acc_4345_);
v___x_4367_ = lean_box(0);
v___y_4348_ = v___x_4367_;
goto v___jp_4347_;
}
v___jp_4347_:
{
lean_object* v___x_4350_; 
lean_inc(v_n_4327_);
if (v_isShared_4330_ == 0)
{
lean_ctor_set_tag(v___x_4329_, 10);
v___x_4350_ = v___x_4329_;
goto v_reusejp_4349_;
}
else
{
lean_object* v_reuseFailAlloc_4364_; 
v_reuseFailAlloc_4364_ = lean_alloc_ctor(10, 1, 0);
lean_ctor_set(v_reuseFailAlloc_4364_, 0, v_n_4327_);
v___x_4350_ = v_reuseFailAlloc_4364_;
goto v_reusejp_4349_;
}
v_reusejp_4349_:
{
lean_object* v___x_4351_; lean_object* v___x_4352_; uint8_t v___x_4353_; lean_object* v___x_4354_; lean_object* v___x_4356_; 
v___x_4351_ = lean_box(0);
v___x_4352_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_4352_, 0, v___x_4350_);
lean_ctor_set(v___x_4352_, 1, v___x_4351_);
v___x_4353_ = 1;
v___x_4354_ = lean_alloc_ctor(3, 2, 1);
lean_ctor_set(v___x_4354_, 0, v___y_4348_);
lean_ctor_set(v___x_4354_, 1, v_view_4346_);
lean_ctor_set_uint8(v___x_4354_, sizeof(void*)*2, v___x_4353_);
if (v_isShared_4344_ == 0)
{
lean_ctor_set(v___x_4343_, 3, v___x_4354_);
v___x_4356_ = v___x_4343_;
goto v_reusejp_4355_;
}
else
{
lean_object* v_reuseFailAlloc_4363_; 
v_reuseFailAlloc_4363_ = lean_alloc_ctor(0, 4, 1);
lean_ctor_set(v_reuseFailAlloc_4363_, 0, v_comp_4338_);
lean_ctor_set(v_reuseFailAlloc_4363_, 1, v_parent_4339_);
lean_ctor_set(v_reuseFailAlloc_4363_, 2, v_table_4341_);
lean_ctor_set(v_reuseFailAlloc_4363_, 3, v___x_4354_);
lean_ctor_set_uint8(v_reuseFailAlloc_4363_, sizeof(void*)*4, v_retired_4340_);
v___x_4356_ = v_reuseFailAlloc_4363_;
goto v_reusejp_4355_;
}
v_reusejp_4355_:
{
lean_object* v___x_4358_; 
if (v_isShared_4336_ == 0)
{
lean_ctor_set(v___x_4335_, 0, v___x_4356_);
v___x_4358_ = v___x_4335_;
goto v_reusejp_4357_;
}
else
{
lean_object* v_reuseFailAlloc_4362_; 
v_reuseFailAlloc_4362_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_4362_, 0, v___x_4356_);
v___x_4358_ = v_reuseFailAlloc_4362_;
goto v_reusejp_4357_;
}
v_reusejp_4357_:
{
lean_object* v___x_4359_; lean_object* v___x_4360_; lean_object* v___x_4361_; 
v___x_4359_ = lp_bounded_Bounded_SMap_set___redArg(v_00_u03b3_4102_, v_n_4327_, v___x_4358_);
lean_dec(v_n_4327_);
v___x_4360_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_4360_, 0, v___x_4352_);
lean_ctor_set(v___x_4360_, 1, v___x_4359_);
v___x_4361_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_4361_, 0, v___x_4360_);
return v___x_4361_;
}
}
}
}
}
}
else
{
lean_object* v___x_4370_; 
lean_dec_ref(v_st_4337_);
lean_del_object(v___x_4335_);
lean_dec(v_val_4333_);
lean_del_object(v___x_4329_);
lean_dec(v_n_4327_);
lean_dec_ref(v_00_u03b3_4102_);
v___x_4370_ = lean_box(0);
return v___x_4370_;
}
}
}
}
}
case 8:
{
lean_object* v_n_4373_; lean_object* v___x_4375_; uint8_t v_isShared_4376_; uint8_t v_isSharedCheck_4419_; 
lean_dec_ref_known(v_d_4103_, 0);
v_n_4373_ = lean_ctor_get(v_a_4101_, 0);
v_isSharedCheck_4419_ = !lean_is_exclusive(v_a_4101_);
if (v_isSharedCheck_4419_ == 0)
{
v___x_4375_ = v_a_4101_;
v_isShared_4376_ = v_isSharedCheck_4419_;
goto v_resetjp_4374_;
}
else
{
lean_inc(v_n_4373_);
lean_dec(v_a_4101_);
v___x_4375_ = lean_box(0);
v_isShared_4376_ = v_isSharedCheck_4419_;
goto v_resetjp_4374_;
}
v_resetjp_4374_:
{
lean_object* v___x_4377_; 
v___x_4377_ = lp_bounded_Bounded_SMap_get___redArg(v_00_u03b3_4102_, v_n_4373_);
if (lean_obj_tag(v___x_4377_) == 0)
{
lean_object* v___x_4378_; 
lean_del_object(v___x_4375_);
lean_dec(v_n_4373_);
lean_dec_ref(v_00_u03b3_4102_);
v___x_4378_ = lean_box(0);
return v___x_4378_;
}
else
{
lean_object* v_val_4379_; lean_object* v___x_4381_; uint8_t v_isShared_4382_; uint8_t v_isSharedCheck_4418_; 
v_val_4379_ = lean_ctor_get(v___x_4377_, 0);
v_isSharedCheck_4418_ = !lean_is_exclusive(v___x_4377_);
if (v_isSharedCheck_4418_ == 0)
{
v___x_4381_ = v___x_4377_;
v_isShared_4382_ = v_isSharedCheck_4418_;
goto v_resetjp_4380_;
}
else
{
lean_inc(v_val_4379_);
lean_dec(v___x_4377_);
v___x_4381_ = lean_box(0);
v_isShared_4382_ = v_isSharedCheck_4418_;
goto v_resetjp_4380_;
}
v_resetjp_4380_:
{
lean_object* v_st_4383_; 
v_st_4383_ = lean_ctor_get(v_val_4379_, 3);
lean_inc_ref(v_st_4383_);
if (lean_obj_tag(v_st_4383_) == 2)
{
lean_object* v_comp_4384_; lean_object* v_parent_4385_; uint8_t v_retired_4386_; lean_object* v_table_4387_; lean_object* v___x_4389_; uint8_t v_isShared_4390_; uint8_t v_isSharedCheck_4415_; 
v_comp_4384_ = lean_ctor_get(v_val_4379_, 0);
v_parent_4385_ = lean_ctor_get(v_val_4379_, 1);
v_retired_4386_ = lean_ctor_get_uint8(v_val_4379_, sizeof(void*)*4);
v_table_4387_ = lean_ctor_get(v_val_4379_, 2);
v_isSharedCheck_4415_ = !lean_is_exclusive(v_val_4379_);
if (v_isSharedCheck_4415_ == 0)
{
lean_object* v_unused_4416_; 
v_unused_4416_ = lean_ctor_get(v_val_4379_, 3);
lean_dec(v_unused_4416_);
v___x_4389_ = v_val_4379_;
v_isShared_4390_ = v_isSharedCheck_4415_;
goto v_resetjp_4388_;
}
else
{
lean_inc(v_table_4387_);
lean_inc(v_parent_4385_);
lean_inc(v_comp_4384_);
lean_dec(v_val_4379_);
v___x_4389_ = lean_box(0);
v_isShared_4390_ = v_isSharedCheck_4415_;
goto v_resetjp_4388_;
}
v_resetjp_4388_:
{
lean_object* v_acc_4391_; lean_object* v_view_4392_; lean_object* v___x_4394_; uint8_t v_isShared_4395_; uint8_t v_isSharedCheck_4414_; 
v_acc_4391_ = lean_ctor_get(v_st_4383_, 0);
v_view_4392_ = lean_ctor_get(v_st_4383_, 1);
v_isSharedCheck_4414_ = !lean_is_exclusive(v_st_4383_);
if (v_isSharedCheck_4414_ == 0)
{
v___x_4394_ = v_st_4383_;
v_isShared_4395_ = v_isSharedCheck_4414_;
goto v_resetjp_4393_;
}
else
{
lean_inc(v_view_4392_);
lean_inc(v_acc_4391_);
lean_dec(v_st_4383_);
v___x_4394_ = lean_box(0);
v_isShared_4395_ = v_isSharedCheck_4414_;
goto v_resetjp_4393_;
}
v_resetjp_4393_:
{
lean_object* v___x_4397_; 
lean_inc(v_n_4373_);
if (v_isShared_4376_ == 0)
{
lean_ctor_set_tag(v___x_4375_, 13);
v___x_4397_ = v___x_4375_;
goto v_reusejp_4396_;
}
else
{
lean_object* v_reuseFailAlloc_4413_; 
v_reuseFailAlloc_4413_ = lean_alloc_ctor(13, 1, 0);
lean_ctor_set(v_reuseFailAlloc_4413_, 0, v_n_4373_);
v___x_4397_ = v_reuseFailAlloc_4413_;
goto v_reusejp_4396_;
}
v_reusejp_4396_:
{
lean_object* v___x_4398_; lean_object* v___x_4400_; 
v___x_4398_ = lean_box(0);
if (v_isShared_4395_ == 0)
{
lean_ctor_set_tag(v___x_4394_, 1);
lean_ctor_set(v___x_4394_, 1, v___x_4398_);
lean_ctor_set(v___x_4394_, 0, v___x_4397_);
v___x_4400_ = v___x_4394_;
goto v_reusejp_4399_;
}
else
{
lean_object* v_reuseFailAlloc_4412_; 
v_reuseFailAlloc_4412_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_4412_, 0, v___x_4397_);
lean_ctor_set(v_reuseFailAlloc_4412_, 1, v___x_4398_);
v___x_4400_ = v_reuseFailAlloc_4412_;
goto v_reusejp_4399_;
}
v_reusejp_4399_:
{
uint8_t v___x_4401_; lean_object* v___x_4402_; lean_object* v___x_4404_; 
v___x_4401_ = 0;
v___x_4402_ = lean_alloc_ctor(3, 2, 1);
lean_ctor_set(v___x_4402_, 0, v_acc_4391_);
lean_ctor_set(v___x_4402_, 1, v_view_4392_);
lean_ctor_set_uint8(v___x_4402_, sizeof(void*)*2, v___x_4401_);
if (v_isShared_4390_ == 0)
{
lean_ctor_set(v___x_4389_, 3, v___x_4402_);
v___x_4404_ = v___x_4389_;
goto v_reusejp_4403_;
}
else
{
lean_object* v_reuseFailAlloc_4411_; 
v_reuseFailAlloc_4411_ = lean_alloc_ctor(0, 4, 1);
lean_ctor_set(v_reuseFailAlloc_4411_, 0, v_comp_4384_);
lean_ctor_set(v_reuseFailAlloc_4411_, 1, v_parent_4385_);
lean_ctor_set(v_reuseFailAlloc_4411_, 2, v_table_4387_);
lean_ctor_set(v_reuseFailAlloc_4411_, 3, v___x_4402_);
lean_ctor_set_uint8(v_reuseFailAlloc_4411_, sizeof(void*)*4, v_retired_4386_);
v___x_4404_ = v_reuseFailAlloc_4411_;
goto v_reusejp_4403_;
}
v_reusejp_4403_:
{
lean_object* v___x_4406_; 
if (v_isShared_4382_ == 0)
{
lean_ctor_set(v___x_4381_, 0, v___x_4404_);
v___x_4406_ = v___x_4381_;
goto v_reusejp_4405_;
}
else
{
lean_object* v_reuseFailAlloc_4410_; 
v_reuseFailAlloc_4410_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_4410_, 0, v___x_4404_);
v___x_4406_ = v_reuseFailAlloc_4410_;
goto v_reusejp_4405_;
}
v_reusejp_4405_:
{
lean_object* v___x_4407_; lean_object* v___x_4408_; lean_object* v___x_4409_; 
v___x_4407_ = lp_bounded_Bounded_SMap_set___redArg(v_00_u03b3_4102_, v_n_4373_, v___x_4406_);
lean_dec(v_n_4373_);
v___x_4408_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_4408_, 0, v___x_4400_);
lean_ctor_set(v___x_4408_, 1, v___x_4407_);
v___x_4409_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_4409_, 0, v___x_4408_);
return v___x_4409_;
}
}
}
}
}
}
}
else
{
lean_object* v___x_4417_; 
lean_dec_ref(v_st_4383_);
lean_del_object(v___x_4381_);
lean_dec(v_val_4379_);
lean_del_object(v___x_4375_);
lean_dec(v_n_4373_);
lean_dec_ref(v_00_u03b3_4102_);
v___x_4417_ = lean_box(0);
return v___x_4417_;
}
}
}
}
}
default: 
{
uint8_t v_v_4420_; lean_object* v___x_4422_; uint8_t v_isShared_4423_; uint8_t v_isSharedCheck_4488_; 
v_v_4420_ = lean_ctor_get_uint8(v_d_4103_, 0);
v_isSharedCheck_4488_ = !lean_is_exclusive(v_d_4103_);
if (v_isSharedCheck_4488_ == 0)
{
v___x_4422_ = v_d_4103_;
v_isShared_4423_ = v_isSharedCheck_4488_;
goto v_resetjp_4421_;
}
else
{
lean_dec(v_d_4103_);
v___x_4422_ = lean_box(0);
v_isShared_4423_ = v_isSharedCheck_4488_;
goto v_resetjp_4421_;
}
v_resetjp_4421_:
{
lean_object* v_n_4424_; lean_object* v___x_4426_; uint8_t v_isShared_4427_; uint8_t v_isSharedCheck_4487_; 
v_n_4424_ = lean_ctor_get(v_a_4101_, 0);
v_isSharedCheck_4487_ = !lean_is_exclusive(v_a_4101_);
if (v_isSharedCheck_4487_ == 0)
{
v___x_4426_ = v_a_4101_;
v_isShared_4427_ = v_isSharedCheck_4487_;
goto v_resetjp_4425_;
}
else
{
lean_inc(v_n_4424_);
lean_dec(v_a_4101_);
v___x_4426_ = lean_box(0);
v_isShared_4427_ = v_isSharedCheck_4487_;
goto v_resetjp_4425_;
}
v_resetjp_4425_:
{
lean_object* v___y_4429_; lean_object* v___y_4430_; lean_object* v___y_4431_; lean_object* v___x_4447_; 
v___x_4447_ = lp_bounded_Bounded_SMap_get___redArg(v_00_u03b3_4102_, v_n_4424_);
if (lean_obj_tag(v___x_4447_) == 0)
{
lean_object* v___x_4448_; 
lean_del_object(v___x_4426_);
lean_dec(v_n_4424_);
lean_del_object(v___x_4422_);
lean_dec_ref(v_00_u03b3_4102_);
v___x_4448_ = lean_box(0);
return v___x_4448_;
}
else
{
lean_object* v_val_4449_; lean_object* v_st_4450_; 
v_val_4449_ = lean_ctor_get(v___x_4447_, 0);
lean_inc(v_val_4449_);
lean_dec_ref_known(v___x_4447_, 1);
v_st_4450_ = lean_ctor_get(v_val_4449_, 3);
lean_inc_ref(v_st_4450_);
lean_dec(v_val_4449_);
if (lean_obj_tag(v_st_4450_) == 3)
{
lean_object* v_acc_4451_; uint8_t v_o_4452_; lean_object* v___y_4454_; 
v_acc_4451_ = lean_ctor_get(v_st_4450_, 0);
lean_inc(v_acc_4451_);
v_o_4452_ = lean_ctor_get_uint8(v_st_4450_, sizeof(void*)*2);
lean_dec_ref_known(v_st_4450_, 2);
switch(v_v_4420_)
{
case 0:
{
lean_object* v___x_4484_; 
v___x_4484_ = l_List_reverse___redArg(v_acc_4451_);
v___y_4454_ = v___x_4484_;
goto v___jp_4453_;
}
case 1:
{
v___y_4454_ = v_acc_4451_;
goto v___jp_4453_;
}
default: 
{
lean_object* v___x_4485_; 
lean_dec(v_acc_4451_);
v___x_4485_ = lean_box(0);
v___y_4454_ = v___x_4485_;
goto v___jp_4453_;
}
}
v___jp_4453_:
{
lean_object* v___x_4455_; lean_object* v___x_4456_; lean_object* v_r_4457_; lean_object* v_snd_4458_; lean_object* v___x_4459_; 
v___x_4455_ = lean_box(0);
v___x_4456_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_4456_, 0, v___x_4455_);
lean_ctor_set(v___x_4456_, 1, v_00_u03b3_4102_);
lean_inc(v_n_4424_);
v_r_4457_ = lp_bounded_List_foldl___at___00Bounded_liftStep_spec__0(v_n_4424_, v___x_4456_, v___y_4454_);
lean_dec(v___y_4454_);
v_snd_4458_ = lean_ctor_get(v_r_4457_, 1);
lean_inc(v_snd_4458_);
v___x_4459_ = lp_bounded_Bounded_SMap_get___redArg(v_snd_4458_, v_n_4424_);
if (lean_obj_tag(v___x_4459_) == 0)
{
lean_del_object(v___x_4422_);
v___y_4429_ = v___x_4455_;
v___y_4430_ = v_r_4457_;
v___y_4431_ = v_snd_4458_;
goto v___jp_4428_;
}
else
{
lean_object* v_val_4460_; lean_object* v___x_4462_; uint8_t v_isShared_4463_; uint8_t v_isSharedCheck_4483_; 
v_val_4460_ = lean_ctor_get(v___x_4459_, 0);
v_isSharedCheck_4483_ = !lean_is_exclusive(v___x_4459_);
if (v_isSharedCheck_4483_ == 0)
{
v___x_4462_ = v___x_4459_;
v_isShared_4463_ = v_isSharedCheck_4483_;
goto v_resetjp_4461_;
}
else
{
lean_inc(v_val_4460_);
lean_dec(v___x_4459_);
v___x_4462_ = lean_box(0);
v_isShared_4463_ = v_isSharedCheck_4483_;
goto v_resetjp_4461_;
}
v_resetjp_4461_:
{
lean_object* v_comp_4464_; lean_object* v_parent_4465_; uint8_t v_retired_4466_; lean_object* v_table_4467_; lean_object* v___x_4469_; uint8_t v_isShared_4470_; uint8_t v_isSharedCheck_4481_; 
v_comp_4464_ = lean_ctor_get(v_val_4460_, 0);
v_parent_4465_ = lean_ctor_get(v_val_4460_, 1);
v_retired_4466_ = lean_ctor_get_uint8(v_val_4460_, sizeof(void*)*4);
v_table_4467_ = lean_ctor_get(v_val_4460_, 2);
v_isSharedCheck_4481_ = !lean_is_exclusive(v_val_4460_);
if (v_isSharedCheck_4481_ == 0)
{
lean_object* v_unused_4482_; 
v_unused_4482_ = lean_ctor_get(v_val_4460_, 3);
lean_dec(v_unused_4482_);
v___x_4469_ = v_val_4460_;
v_isShared_4470_ = v_isSharedCheck_4481_;
goto v_resetjp_4468_;
}
else
{
lean_inc(v_table_4467_);
lean_inc(v_parent_4465_);
lean_inc(v_comp_4464_);
lean_dec(v_val_4460_);
v___x_4469_ = lean_box(0);
v_isShared_4470_ = v_isSharedCheck_4481_;
goto v_resetjp_4468_;
}
v_resetjp_4468_:
{
lean_object* v___x_4472_; 
if (v_isShared_4423_ == 0)
{
lean_ctor_set_tag(v___x_4422_, 0);
v___x_4472_ = v___x_4422_;
goto v_reusejp_4471_;
}
else
{
lean_object* v_reuseFailAlloc_4480_; 
v_reuseFailAlloc_4480_ = lean_alloc_ctor(0, 0, 1);
v___x_4472_ = v_reuseFailAlloc_4480_;
goto v_reusejp_4471_;
}
v_reusejp_4471_:
{
lean_object* v___x_4474_; 
lean_ctor_set_uint8(v___x_4472_, 0, v_o_4452_);
if (v_isShared_4470_ == 0)
{
lean_ctor_set(v___x_4469_, 3, v___x_4472_);
v___x_4474_ = v___x_4469_;
goto v_reusejp_4473_;
}
else
{
lean_object* v_reuseFailAlloc_4479_; 
v_reuseFailAlloc_4479_ = lean_alloc_ctor(0, 4, 1);
lean_ctor_set(v_reuseFailAlloc_4479_, 0, v_comp_4464_);
lean_ctor_set(v_reuseFailAlloc_4479_, 1, v_parent_4465_);
lean_ctor_set(v_reuseFailAlloc_4479_, 2, v_table_4467_);
lean_ctor_set(v_reuseFailAlloc_4479_, 3, v___x_4472_);
lean_ctor_set_uint8(v_reuseFailAlloc_4479_, sizeof(void*)*4, v_retired_4466_);
v___x_4474_ = v_reuseFailAlloc_4479_;
goto v_reusejp_4473_;
}
v_reusejp_4473_:
{
lean_object* v___x_4476_; 
if (v_isShared_4463_ == 0)
{
lean_ctor_set(v___x_4462_, 0, v___x_4474_);
v___x_4476_ = v___x_4462_;
goto v_reusejp_4475_;
}
else
{
lean_object* v_reuseFailAlloc_4478_; 
v_reuseFailAlloc_4478_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_4478_, 0, v___x_4474_);
v___x_4476_ = v_reuseFailAlloc_4478_;
goto v_reusejp_4475_;
}
v_reusejp_4475_:
{
lean_object* v___x_4477_; 
v___x_4477_ = lp_bounded_Bounded_SMap_set___redArg(v_snd_4458_, v_n_4424_, v___x_4476_);
v___y_4429_ = v___x_4455_;
v___y_4430_ = v_r_4457_;
v___y_4431_ = v___x_4477_;
goto v___jp_4428_;
}
}
}
}
}
}
}
}
else
{
lean_object* v___x_4486_; 
lean_dec_ref(v_st_4450_);
lean_del_object(v___x_4426_);
lean_dec(v_n_4424_);
lean_del_object(v___x_4422_);
lean_dec_ref(v_00_u03b3_4102_);
v___x_4486_ = lean_box(0);
return v___x_4486_;
}
}
v___jp_4428_:
{
lean_object* v_fst_4432_; lean_object* v___x_4434_; uint8_t v_isShared_4435_; uint8_t v_isSharedCheck_4445_; 
v_fst_4432_ = lean_ctor_get(v___y_4430_, 0);
v_isSharedCheck_4445_ = !lean_is_exclusive(v___y_4430_);
if (v_isSharedCheck_4445_ == 0)
{
lean_object* v_unused_4446_; 
v_unused_4446_ = lean_ctor_get(v___y_4430_, 1);
lean_dec(v_unused_4446_);
v___x_4434_ = v___y_4430_;
v_isShared_4435_ = v_isSharedCheck_4445_;
goto v_resetjp_4433_;
}
else
{
lean_inc(v_fst_4432_);
lean_dec(v___y_4430_);
v___x_4434_ = lean_box(0);
v_isShared_4435_ = v_isSharedCheck_4445_;
goto v_resetjp_4433_;
}
v_resetjp_4433_:
{
lean_object* v___x_4437_; 
if (v_isShared_4427_ == 0)
{
lean_ctor_set_tag(v___x_4426_, 17);
v___x_4437_ = v___x_4426_;
goto v_reusejp_4436_;
}
else
{
lean_object* v_reuseFailAlloc_4444_; 
v_reuseFailAlloc_4444_ = lean_alloc_ctor(17, 1, 0);
lean_ctor_set(v_reuseFailAlloc_4444_, 0, v_n_4424_);
v___x_4437_ = v_reuseFailAlloc_4444_;
goto v_reusejp_4436_;
}
v_reusejp_4436_:
{
lean_object* v___x_4438_; lean_object* v___x_4439_; lean_object* v___x_4441_; 
lean_inc(v___y_4429_);
v___x_4438_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_4438_, 0, v___x_4437_);
lean_ctor_set(v___x_4438_, 1, v___y_4429_);
v___x_4439_ = l_List_appendTR___redArg(v_fst_4432_, v___x_4438_);
if (v_isShared_4435_ == 0)
{
lean_ctor_set(v___x_4434_, 1, v___y_4431_);
lean_ctor_set(v___x_4434_, 0, v___x_4439_);
v___x_4441_ = v___x_4434_;
goto v_reusejp_4440_;
}
else
{
lean_object* v_reuseFailAlloc_4443_; 
v_reuseFailAlloc_4443_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_4443_, 0, v___x_4439_);
lean_ctor_set(v_reuseFailAlloc_4443_, 1, v___y_4431_);
v___x_4441_ = v_reuseFailAlloc_4443_;
goto v_reusejp_4440_;
}
v_reusejp_4440_:
{
lean_object* v___x_4442_; 
v___x_4442_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_4442_, 0, v___x_4441_);
return v___x_4442_;
}
}
}
}
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_specStep(lean_object* v_a_4489_, lean_object* v_00_u03b3_4490_){
_start:
{
lean_object* v___x_4491_; lean_object* v___x_4492_; lean_object* v___x_4493_; 
lean_inc_ref(v_00_u03b3_4490_);
lean_inc_ref(v_a_4489_);
v___x_4491_ = lp_bounded_Bounded_sig(v_a_4489_, v_00_u03b3_4490_);
v___x_4492_ = lp_bounded_Bounded_fS(v___x_4491_);
lean_dec_ref(v___x_4491_);
v___x_4493_ = lp_bounded_Bounded_liftStep(v_a_4489_, v_00_u03b3_4490_, v___x_4492_);
return v___x_4493_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_ctorIdx(uint8_t v_x_4494_){
_start:
{
switch(v_x_4494_)
{
case 0:
{
lean_object* v___x_4495_; 
v___x_4495_ = lean_unsigned_to_nat(0u);
return v___x_4495_;
}
case 1:
{
lean_object* v___x_4496_; 
v___x_4496_ = lean_unsigned_to_nat(1u);
return v___x_4496_;
}
case 2:
{
lean_object* v___x_4497_; 
v___x_4497_ = lean_unsigned_to_nat(2u);
return v___x_4497_;
}
case 3:
{
lean_object* v___x_4498_; 
v___x_4498_ = lean_unsigned_to_nat(3u);
return v___x_4498_;
}
case 4:
{
lean_object* v___x_4499_; 
v___x_4499_ = lean_unsigned_to_nat(4u);
return v___x_4499_;
}
default: 
{
lean_object* v___x_4500_; 
v___x_4500_ = lean_unsigned_to_nat(5u);
return v___x_4500_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_ctorIdx___boxed(lean_object* v_x_4501_){
_start:
{
uint8_t v_x_boxed_4502_; lean_object* v_res_4503_; 
v_x_boxed_4502_ = lean_unbox(v_x_4501_);
v_res_4503_ = lp_bounded_Bounded_Status_ctorIdx(v_x_boxed_4502_);
return v_res_4503_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_toCtorIdx(uint8_t v_x_4504_){
_start:
{
lean_object* v___x_4505_; 
v___x_4505_ = lp_bounded_Bounded_Status_ctorIdx(v_x_4504_);
return v___x_4505_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_toCtorIdx___boxed(lean_object* v_x_4506_){
_start:
{
uint8_t v_x_4__boxed_4507_; lean_object* v_res_4508_; 
v_x_4__boxed_4507_ = lean_unbox(v_x_4506_);
v_res_4508_ = lp_bounded_Bounded_Status_toCtorIdx(v_x_4__boxed_4507_);
return v_res_4508_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_ctorElim___redArg(lean_object* v_k_4509_){
_start:
{
lean_inc(v_k_4509_);
return v_k_4509_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_ctorElim___redArg___boxed(lean_object* v_k_4510_){
_start:
{
lean_object* v_res_4511_; 
v_res_4511_ = lp_bounded_Bounded_Status_ctorElim___redArg(v_k_4510_);
lean_dec(v_k_4510_);
return v_res_4511_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_ctorElim(lean_object* v_motive_4512_, lean_object* v_ctorIdx_4513_, uint8_t v_t_4514_, lean_object* v_h_4515_, lean_object* v_k_4516_){
_start:
{
lean_inc(v_k_4516_);
return v_k_4516_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_ctorElim___boxed(lean_object* v_motive_4517_, lean_object* v_ctorIdx_4518_, lean_object* v_t_4519_, lean_object* v_h_4520_, lean_object* v_k_4521_){
_start:
{
uint8_t v_t_boxed_4522_; lean_object* v_res_4523_; 
v_t_boxed_4522_ = lean_unbox(v_t_4519_);
v_res_4523_ = lp_bounded_Bounded_Status_ctorElim(v_motive_4517_, v_ctorIdx_4518_, v_t_boxed_4522_, v_h_4520_, v_k_4521_);
lean_dec(v_k_4521_);
lean_dec(v_ctorIdx_4518_);
return v_res_4523_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_absent_elim___redArg(lean_object* v_absent_4524_){
_start:
{
lean_inc(v_absent_4524_);
return v_absent_4524_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_absent_elim___redArg___boxed(lean_object* v_absent_4525_){
_start:
{
lean_object* v_res_4526_; 
v_res_4526_ = lp_bounded_Bounded_Status_absent_elim___redArg(v_absent_4525_);
lean_dec(v_absent_4525_);
return v_res_4526_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_absent_elim(lean_object* v_motive_4527_, uint8_t v_t_4528_, lean_object* v_h_4529_, lean_object* v_absent_4530_){
_start:
{
lean_inc(v_absent_4530_);
return v_absent_4530_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_absent_elim___boxed(lean_object* v_motive_4531_, lean_object* v_t_4532_, lean_object* v_h_4533_, lean_object* v_absent_4534_){
_start:
{
uint8_t v_t_boxed_4535_; lean_object* v_res_4536_; 
v_t_boxed_4535_ = lean_unbox(v_t_4532_);
v_res_4536_ = lp_bounded_Bounded_Status_absent_elim(v_motive_4531_, v_t_boxed_4535_, v_h_4533_, v_absent_4534_);
lean_dec(v_absent_4534_);
return v_res_4536_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_pending_elim___redArg(lean_object* v_pending_4537_){
_start:
{
lean_inc(v_pending_4537_);
return v_pending_4537_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_pending_elim___redArg___boxed(lean_object* v_pending_4538_){
_start:
{
lean_object* v_res_4539_; 
v_res_4539_ = lp_bounded_Bounded_Status_pending_elim___redArg(v_pending_4538_);
lean_dec(v_pending_4538_);
return v_res_4539_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_pending_elim(lean_object* v_motive_4540_, uint8_t v_t_4541_, lean_object* v_h_4542_, lean_object* v_pending_4543_){
_start:
{
lean_inc(v_pending_4543_);
return v_pending_4543_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_pending_elim___boxed(lean_object* v_motive_4544_, lean_object* v_t_4545_, lean_object* v_h_4546_, lean_object* v_pending_4547_){
_start:
{
uint8_t v_t_boxed_4548_; lean_object* v_res_4549_; 
v_t_boxed_4548_ = lean_unbox(v_t_4545_);
v_res_4549_ = lp_bounded_Bounded_Status_pending_elim(v_motive_4544_, v_t_boxed_4548_, v_h_4546_, v_pending_4547_);
lean_dec(v_pending_4547_);
return v_res_4549_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_failed_elim___redArg(lean_object* v_failed_4550_){
_start:
{
lean_inc(v_failed_4550_);
return v_failed_4550_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_failed_elim___redArg___boxed(lean_object* v_failed_4551_){
_start:
{
lean_object* v_res_4552_; 
v_res_4552_ = lp_bounded_Bounded_Status_failed_elim___redArg(v_failed_4551_);
lean_dec(v_failed_4551_);
return v_res_4552_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_failed_elim(lean_object* v_motive_4553_, uint8_t v_t_4554_, lean_object* v_h_4555_, lean_object* v_failed_4556_){
_start:
{
lean_inc(v_failed_4556_);
return v_failed_4556_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_failed_elim___boxed(lean_object* v_motive_4557_, lean_object* v_t_4558_, lean_object* v_h_4559_, lean_object* v_failed_4560_){
_start:
{
uint8_t v_t_boxed_4561_; lean_object* v_res_4562_; 
v_t_boxed_4561_ = lean_unbox(v_t_4558_);
v_res_4562_ = lp_bounded_Bounded_Status_failed_elim(v_motive_4557_, v_t_boxed_4561_, v_h_4559_, v_failed_4560_);
lean_dec(v_failed_4560_);
return v_res_4562_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_loading_elim___redArg(lean_object* v_loading_4563_){
_start:
{
lean_inc(v_loading_4563_);
return v_loading_4563_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_loading_elim___redArg___boxed(lean_object* v_loading_4564_){
_start:
{
lean_object* v_res_4565_; 
v_res_4565_ = lp_bounded_Bounded_Status_loading_elim___redArg(v_loading_4564_);
lean_dec(v_loading_4564_);
return v_res_4565_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_loading_elim(lean_object* v_motive_4566_, uint8_t v_t_4567_, lean_object* v_h_4568_, lean_object* v_loading_4569_){
_start:
{
lean_inc(v_loading_4569_);
return v_loading_4569_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_loading_elim___boxed(lean_object* v_motive_4570_, lean_object* v_t_4571_, lean_object* v_h_4572_, lean_object* v_loading_4573_){
_start:
{
uint8_t v_t_boxed_4574_; lean_object* v_res_4575_; 
v_t_boxed_4574_ = lean_unbox(v_t_4571_);
v_res_4575_ = lp_bounded_Bounded_Status_loading_elim(v_motive_4570_, v_t_boxed_4574_, v_h_4572_, v_loading_4573_);
lean_dec(v_loading_4573_);
return v_res_4575_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_activeS_elim___redArg(lean_object* v_activeS_4576_){
_start:
{
lean_inc(v_activeS_4576_);
return v_activeS_4576_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_activeS_elim___redArg___boxed(lean_object* v_activeS_4577_){
_start:
{
lean_object* v_res_4578_; 
v_res_4578_ = lp_bounded_Bounded_Status_activeS_elim___redArg(v_activeS_4577_);
lean_dec(v_activeS_4577_);
return v_res_4578_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_activeS_elim(lean_object* v_motive_4579_, uint8_t v_t_4580_, lean_object* v_h_4581_, lean_object* v_activeS_4582_){
_start:
{
lean_inc(v_activeS_4582_);
return v_activeS_4582_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_activeS_elim___boxed(lean_object* v_motive_4583_, lean_object* v_t_4584_, lean_object* v_h_4585_, lean_object* v_activeS_4586_){
_start:
{
uint8_t v_t_boxed_4587_; lean_object* v_res_4588_; 
v_t_boxed_4587_ = lean_unbox(v_t_4584_);
v_res_4588_ = lp_bounded_Bounded_Status_activeS_elim(v_motive_4583_, v_t_boxed_4587_, v_h_4585_, v_activeS_4586_);
lean_dec(v_activeS_4586_);
return v_res_4588_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_unloadingS_elim___redArg(lean_object* v_unloadingS_4589_){
_start:
{
lean_inc(v_unloadingS_4589_);
return v_unloadingS_4589_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_unloadingS_elim___redArg___boxed(lean_object* v_unloadingS_4590_){
_start:
{
lean_object* v_res_4591_; 
v_res_4591_ = lp_bounded_Bounded_Status_unloadingS_elim___redArg(v_unloadingS_4590_);
lean_dec(v_unloadingS_4590_);
return v_res_4591_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_unloadingS_elim(lean_object* v_motive_4592_, uint8_t v_t_4593_, lean_object* v_h_4594_, lean_object* v_unloadingS_4595_){
_start:
{
lean_inc(v_unloadingS_4595_);
return v_unloadingS_4595_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_unloadingS_elim___boxed(lean_object* v_motive_4596_, lean_object* v_t_4597_, lean_object* v_h_4598_, lean_object* v_unloadingS_4599_){
_start:
{
uint8_t v_t_boxed_4600_; lean_object* v_res_4601_; 
v_t_boxed_4600_ = lean_unbox(v_t_4597_);
v_res_4601_ = lp_bounded_Bounded_Status_unloadingS_elim(v_motive_4596_, v_t_boxed_4600_, v_h_4598_, v_unloadingS_4599_);
lean_dec(v_unloadingS_4599_);
return v_res_4601_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_Status_ofNat(lean_object* v_n_4602_){
_start:
{
lean_object* v___x_4603_; uint8_t v___x_4604_; 
v___x_4603_ = lean_unsigned_to_nat(2u);
v___x_4604_ = lean_nat_dec_le(v_n_4602_, v___x_4603_);
if (v___x_4604_ == 0)
{
lean_object* v___x_4605_; uint8_t v___x_4606_; 
v___x_4605_ = lean_unsigned_to_nat(3u);
v___x_4606_ = lean_nat_dec_le(v_n_4602_, v___x_4605_);
if (v___x_4606_ == 0)
{
lean_object* v___x_4607_; uint8_t v___x_4608_; 
v___x_4607_ = lean_unsigned_to_nat(4u);
v___x_4608_ = lean_nat_dec_le(v_n_4602_, v___x_4607_);
if (v___x_4608_ == 0)
{
uint8_t v___x_4609_; 
v___x_4609_ = 5;
return v___x_4609_;
}
else
{
uint8_t v___x_4610_; 
v___x_4610_ = 4;
return v___x_4610_;
}
}
else
{
uint8_t v___x_4611_; 
v___x_4611_ = 3;
return v___x_4611_;
}
}
else
{
lean_object* v___x_4612_; uint8_t v___x_4613_; 
v___x_4612_ = lean_unsigned_to_nat(0u);
v___x_4613_ = lean_nat_dec_le(v_n_4602_, v___x_4612_);
if (v___x_4613_ == 0)
{
lean_object* v___x_4614_; uint8_t v___x_4615_; 
v___x_4614_ = lean_unsigned_to_nat(1u);
v___x_4615_ = lean_nat_dec_le(v_n_4602_, v___x_4614_);
if (v___x_4615_ == 0)
{
uint8_t v___x_4616_; 
v___x_4616_ = 2;
return v___x_4616_;
}
else
{
uint8_t v___x_4617_; 
v___x_4617_ = 1;
return v___x_4617_;
}
}
else
{
uint8_t v___x_4618_; 
v___x_4618_ = 0;
return v___x_4618_;
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_Status_ofNat___boxed(lean_object* v_n_4619_){
_start:
{
uint8_t v_res_4620_; lean_object* v_r_4621_; 
v_res_4620_ = lp_bounded_Bounded_Status_ofNat(v_n_4619_);
lean_dec(v_n_4619_);
v_r_4621_ = lean_box(v_res_4620_);
return v_r_4621_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqStatus(uint8_t v_x_4622_, uint8_t v_y_4623_){
_start:
{
lean_object* v___x_4624_; lean_object* v___x_4625_; uint8_t v___x_4626_; 
v___x_4624_ = lp_bounded_Bounded_Status_ctorIdx(v_x_4622_);
v___x_4625_ = lp_bounded_Bounded_Status_ctorIdx(v_y_4623_);
v___x_4626_ = lean_nat_dec_eq(v___x_4624_, v___x_4625_);
lean_dec(v___x_4625_);
lean_dec(v___x_4624_);
return v___x_4626_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqStatus___boxed(lean_object* v_x_4627_, lean_object* v_y_4628_){
_start:
{
uint8_t v_x_13__boxed_4629_; uint8_t v_y_14__boxed_4630_; uint8_t v_res_4631_; lean_object* v_r_4632_; 
v_x_13__boxed_4629_ = lean_unbox(v_x_4627_);
v_y_14__boxed_4630_ = lean_unbox(v_y_4628_);
v_res_4631_ = lp_bounded_Bounded_instDecidableEqStatus(v_x_13__boxed_4629_, v_y_14__boxed_4630_);
v_r_4632_ = lean_box(v_res_4631_);
return v_r_4632_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprStatus_repr(uint8_t v_x_4651_, lean_object* v_prec_4652_){
_start:
{
lean_object* v___y_4654_; lean_object* v___y_4661_; lean_object* v___y_4668_; lean_object* v___y_4675_; lean_object* v___y_4682_; lean_object* v___y_4689_; 
switch(v_x_4651_)
{
case 0:
{
lean_object* v___x_4695_; uint8_t v___x_4696_; 
v___x_4695_ = lean_unsigned_to_nat(1024u);
v___x_4696_ = lean_nat_dec_le(v___x_4695_, v_prec_4652_);
if (v___x_4696_ == 0)
{
lean_object* v___x_4697_; 
v___x_4697_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_4654_ = v___x_4697_;
goto v___jp_4653_;
}
else
{
lean_object* v___x_4698_; 
v___x_4698_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_4654_ = v___x_4698_;
goto v___jp_4653_;
}
}
case 1:
{
lean_object* v___x_4699_; uint8_t v___x_4700_; 
v___x_4699_ = lean_unsigned_to_nat(1024u);
v___x_4700_ = lean_nat_dec_le(v___x_4699_, v_prec_4652_);
if (v___x_4700_ == 0)
{
lean_object* v___x_4701_; 
v___x_4701_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_4661_ = v___x_4701_;
goto v___jp_4660_;
}
else
{
lean_object* v___x_4702_; 
v___x_4702_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_4661_ = v___x_4702_;
goto v___jp_4660_;
}
}
case 2:
{
lean_object* v___x_4703_; uint8_t v___x_4704_; 
v___x_4703_ = lean_unsigned_to_nat(1024u);
v___x_4704_ = lean_nat_dec_le(v___x_4703_, v_prec_4652_);
if (v___x_4704_ == 0)
{
lean_object* v___x_4705_; 
v___x_4705_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_4668_ = v___x_4705_;
goto v___jp_4667_;
}
else
{
lean_object* v___x_4706_; 
v___x_4706_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_4668_ = v___x_4706_;
goto v___jp_4667_;
}
}
case 3:
{
lean_object* v___x_4707_; uint8_t v___x_4708_; 
v___x_4707_ = lean_unsigned_to_nat(1024u);
v___x_4708_ = lean_nat_dec_le(v___x_4707_, v_prec_4652_);
if (v___x_4708_ == 0)
{
lean_object* v___x_4709_; 
v___x_4709_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_4675_ = v___x_4709_;
goto v___jp_4674_;
}
else
{
lean_object* v___x_4710_; 
v___x_4710_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_4675_ = v___x_4710_;
goto v___jp_4674_;
}
}
case 4:
{
lean_object* v___x_4711_; uint8_t v___x_4712_; 
v___x_4711_ = lean_unsigned_to_nat(1024u);
v___x_4712_ = lean_nat_dec_le(v___x_4711_, v_prec_4652_);
if (v___x_4712_ == 0)
{
lean_object* v___x_4713_; 
v___x_4713_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_4682_ = v___x_4713_;
goto v___jp_4681_;
}
else
{
lean_object* v___x_4714_; 
v___x_4714_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_4682_ = v___x_4714_;
goto v___jp_4681_;
}
}
default: 
{
lean_object* v___x_4715_; uint8_t v___x_4716_; 
v___x_4715_ = lean_unsigned_to_nat(1024u);
v___x_4716_ = lean_nat_dec_le(v___x_4715_, v_prec_4652_);
if (v___x_4716_ == 0)
{
lean_object* v___x_4717_; 
v___x_4717_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__20, &lp_bounded_Bounded_instReprRule_repr___closed__20_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__20);
v___y_4689_ = v___x_4717_;
goto v___jp_4688_;
}
else
{
lean_object* v___x_4718_; 
v___x_4718_ = lean_obj_once(&lp_bounded_Bounded_instReprRule_repr___closed__21, &lp_bounded_Bounded_instReprRule_repr___closed__21_once, _init_lp_bounded_Bounded_instReprRule_repr___closed__21);
v___y_4689_ = v___x_4718_;
goto v___jp_4688_;
}
}
}
v___jp_4653_:
{
lean_object* v___x_4655_; lean_object* v___x_4656_; uint8_t v___x_4657_; lean_object* v___x_4658_; lean_object* v___x_4659_; 
v___x_4655_ = ((lean_object*)(lp_bounded_Bounded_instReprStatus_repr___closed__1));
lean_inc(v___y_4654_);
v___x_4656_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_4656_, 0, v___y_4654_);
lean_ctor_set(v___x_4656_, 1, v___x_4655_);
v___x_4657_ = 0;
v___x_4658_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_4658_, 0, v___x_4656_);
lean_ctor_set_uint8(v___x_4658_, sizeof(void*)*1, v___x_4657_);
v___x_4659_ = l_Repr_addAppParen(v___x_4658_, v_prec_4652_);
return v___x_4659_;
}
v___jp_4660_:
{
lean_object* v___x_4662_; lean_object* v___x_4663_; uint8_t v___x_4664_; lean_object* v___x_4665_; lean_object* v___x_4666_; 
v___x_4662_ = ((lean_object*)(lp_bounded_Bounded_instReprStatus_repr___closed__3));
lean_inc(v___y_4661_);
v___x_4663_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_4663_, 0, v___y_4661_);
lean_ctor_set(v___x_4663_, 1, v___x_4662_);
v___x_4664_ = 0;
v___x_4665_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_4665_, 0, v___x_4663_);
lean_ctor_set_uint8(v___x_4665_, sizeof(void*)*1, v___x_4664_);
v___x_4666_ = l_Repr_addAppParen(v___x_4665_, v_prec_4652_);
return v___x_4666_;
}
v___jp_4667_:
{
lean_object* v___x_4669_; lean_object* v___x_4670_; uint8_t v___x_4671_; lean_object* v___x_4672_; lean_object* v___x_4673_; 
v___x_4669_ = ((lean_object*)(lp_bounded_Bounded_instReprStatus_repr___closed__5));
lean_inc(v___y_4668_);
v___x_4670_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_4670_, 0, v___y_4668_);
lean_ctor_set(v___x_4670_, 1, v___x_4669_);
v___x_4671_ = 0;
v___x_4672_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_4672_, 0, v___x_4670_);
lean_ctor_set_uint8(v___x_4672_, sizeof(void*)*1, v___x_4671_);
v___x_4673_ = l_Repr_addAppParen(v___x_4672_, v_prec_4652_);
return v___x_4673_;
}
v___jp_4674_:
{
lean_object* v___x_4676_; lean_object* v___x_4677_; uint8_t v___x_4678_; lean_object* v___x_4679_; lean_object* v___x_4680_; 
v___x_4676_ = ((lean_object*)(lp_bounded_Bounded_instReprStatus_repr___closed__7));
lean_inc(v___y_4675_);
v___x_4677_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_4677_, 0, v___y_4675_);
lean_ctor_set(v___x_4677_, 1, v___x_4676_);
v___x_4678_ = 0;
v___x_4679_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_4679_, 0, v___x_4677_);
lean_ctor_set_uint8(v___x_4679_, sizeof(void*)*1, v___x_4678_);
v___x_4680_ = l_Repr_addAppParen(v___x_4679_, v_prec_4652_);
return v___x_4680_;
}
v___jp_4681_:
{
lean_object* v___x_4683_; lean_object* v___x_4684_; uint8_t v___x_4685_; lean_object* v___x_4686_; lean_object* v___x_4687_; 
v___x_4683_ = ((lean_object*)(lp_bounded_Bounded_instReprStatus_repr___closed__9));
lean_inc(v___y_4682_);
v___x_4684_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_4684_, 0, v___y_4682_);
lean_ctor_set(v___x_4684_, 1, v___x_4683_);
v___x_4685_ = 0;
v___x_4686_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_4686_, 0, v___x_4684_);
lean_ctor_set_uint8(v___x_4686_, sizeof(void*)*1, v___x_4685_);
v___x_4687_ = l_Repr_addAppParen(v___x_4686_, v_prec_4652_);
return v___x_4687_;
}
v___jp_4688_:
{
lean_object* v___x_4690_; lean_object* v___x_4691_; uint8_t v___x_4692_; lean_object* v___x_4693_; lean_object* v___x_4694_; 
v___x_4690_ = ((lean_object*)(lp_bounded_Bounded_instReprStatus_repr___closed__11));
lean_inc(v___y_4689_);
v___x_4691_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_4691_, 0, v___y_4689_);
lean_ctor_set(v___x_4691_, 1, v___x_4690_);
v___x_4692_ = 0;
v___x_4693_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_4693_, 0, v___x_4691_);
lean_ctor_set_uint8(v___x_4693_, sizeof(void*)*1, v___x_4692_);
v___x_4694_ = l_Repr_addAppParen(v___x_4693_, v_prec_4652_);
return v___x_4694_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprStatus_repr___boxed(lean_object* v_x_4719_, lean_object* v_prec_4720_){
_start:
{
uint8_t v_x_341__boxed_4721_; lean_object* v_res_4722_; 
v_x_341__boxed_4721_ = lean_unbox(v_x_4719_);
v_res_4722_ = lp_bounded_Bounded_instReprStatus_repr(v_x_341__boxed_4721_, v_prec_4720_);
lean_dec(v_prec_4720_);
return v_res_4722_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_statusOf(lean_object* v_x_4730_){
_start:
{
if (lean_obj_tag(v_x_4730_) == 0)
{
lean_object* v___x_4731_; 
v___x_4731_ = ((lean_object*)(lp_bounded_Bounded_statusOf___closed__0));
return v___x_4731_;
}
else
{
lean_object* v_val_4732_; lean_object* v_st_4733_; 
v_val_4732_ = lean_ctor_get(v_x_4730_, 0);
lean_inc(v_val_4732_);
lean_dec_ref_known(v_x_4730_, 1);
v_st_4733_ = lean_ctor_get(v_val_4732_, 3);
lean_inc_ref(v_st_4733_);
switch(lean_obj_tag(v_st_4733_))
{
case 0:
{
uint8_t v_o_4734_; 
v_o_4734_ = lean_ctor_get_uint8(v_st_4733_, 0);
lean_dec_ref_known(v_st_4733_, 0);
if (v_o_4734_ == 0)
{
uint8_t v_retired_4735_; uint8_t v___x_4736_; lean_object* v___x_4737_; lean_object* v___x_4738_; lean_object* v___x_4739_; 
v_retired_4735_ = lean_ctor_get_uint8(v_val_4732_, sizeof(void*)*4);
lean_dec(v_val_4732_);
v___x_4736_ = 1;
v___x_4737_ = lean_box(v___x_4736_);
v___x_4738_ = lean_box(v_retired_4735_);
v___x_4739_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_4739_, 0, v___x_4737_);
lean_ctor_set(v___x_4739_, 1, v___x_4738_);
return v___x_4739_;
}
else
{
uint8_t v_retired_4740_; uint8_t v___x_4741_; lean_object* v___x_4742_; lean_object* v___x_4743_; lean_object* v___x_4744_; 
v_retired_4740_ = lean_ctor_get_uint8(v_val_4732_, sizeof(void*)*4);
lean_dec(v_val_4732_);
v___x_4741_ = 2;
v___x_4742_ = lean_box(v___x_4741_);
v___x_4743_ = lean_box(v_retired_4740_);
v___x_4744_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_4744_, 0, v___x_4742_);
lean_ctor_set(v___x_4744_, 1, v___x_4743_);
return v___x_4744_;
}
}
case 1:
{
uint8_t v_retired_4745_; uint8_t v___x_4746_; lean_object* v___x_4747_; lean_object* v___x_4748_; lean_object* v___x_4749_; 
lean_dec_ref_known(v_st_4733_, 3);
v_retired_4745_ = lean_ctor_get_uint8(v_val_4732_, sizeof(void*)*4);
lean_dec(v_val_4732_);
v___x_4746_ = 3;
v___x_4747_ = lean_box(v___x_4746_);
v___x_4748_ = lean_box(v_retired_4745_);
v___x_4749_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_4749_, 0, v___x_4747_);
lean_ctor_set(v___x_4749_, 1, v___x_4748_);
return v___x_4749_;
}
case 2:
{
uint8_t v_retired_4750_; lean_object* v___x_4752_; uint8_t v_isShared_4753_; uint8_t v_isSharedCheck_4760_; 
v_retired_4750_ = lean_ctor_get_uint8(v_val_4732_, sizeof(void*)*4);
lean_dec(v_val_4732_);
v_isSharedCheck_4760_ = !lean_is_exclusive(v_st_4733_);
if (v_isSharedCheck_4760_ == 0)
{
lean_object* v_unused_4761_; lean_object* v_unused_4762_; 
v_unused_4761_ = lean_ctor_get(v_st_4733_, 1);
lean_dec(v_unused_4761_);
v_unused_4762_ = lean_ctor_get(v_st_4733_, 0);
lean_dec(v_unused_4762_);
v___x_4752_ = v_st_4733_;
v_isShared_4753_ = v_isSharedCheck_4760_;
goto v_resetjp_4751_;
}
else
{
lean_dec(v_st_4733_);
v___x_4752_ = lean_box(0);
v_isShared_4753_ = v_isSharedCheck_4760_;
goto v_resetjp_4751_;
}
v_resetjp_4751_:
{
uint8_t v___x_4754_; lean_object* v___x_4755_; lean_object* v___x_4756_; lean_object* v___x_4758_; 
v___x_4754_ = 4;
v___x_4755_ = lean_box(v___x_4754_);
v___x_4756_ = lean_box(v_retired_4750_);
if (v_isShared_4753_ == 0)
{
lean_ctor_set_tag(v___x_4752_, 0);
lean_ctor_set(v___x_4752_, 1, v___x_4756_);
lean_ctor_set(v___x_4752_, 0, v___x_4755_);
v___x_4758_ = v___x_4752_;
goto v_reusejp_4757_;
}
else
{
lean_object* v_reuseFailAlloc_4759_; 
v_reuseFailAlloc_4759_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_4759_, 0, v___x_4755_);
lean_ctor_set(v_reuseFailAlloc_4759_, 1, v___x_4756_);
v___x_4758_ = v_reuseFailAlloc_4759_;
goto v_reusejp_4757_;
}
v_reusejp_4757_:
{
return v___x_4758_;
}
}
}
default: 
{
uint8_t v_retired_4763_; uint8_t v___x_4764_; lean_object* v___x_4765_; lean_object* v___x_4766_; lean_object* v___x_4767_; 
lean_dec_ref_known(v_st_4733_, 2);
v_retired_4763_ = lean_ctor_get_uint8(v_val_4732_, sizeof(void*)*4);
lean_dec(v_val_4732_);
v___x_4764_ = 5;
v___x_4765_ = lean_box(v___x_4764_);
v___x_4766_ = lean_box(v_retired_4763_);
v___x_4767_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_4767_, 0, v___x_4765_);
lean_ctor_set(v___x_4767_, 1, v___x_4766_);
return v___x_4767_;
}
}
}
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqObs_decEq___lam__0(uint8_t v___y_4768_, uint8_t v___y_4769_){
_start:
{
if (v___y_4768_ == 0)
{
if (v___y_4769_ == 0)
{
uint8_t v___x_4770_; 
v___x_4770_ = 1;
return v___x_4770_;
}
else
{
return v___y_4768_;
}
}
else
{
return v___y_4769_;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqObs_decEq___lam__0___boxed(lean_object* v___y_4771_, lean_object* v___y_4772_){
_start:
{
uint8_t v___y_112__boxed_4773_; uint8_t v___y_113__boxed_4774_; uint8_t v_res_4775_; lean_object* v_r_4776_; 
v___y_112__boxed_4773_ = lean_unbox(v___y_4771_);
v___y_113__boxed_4774_ = lean_unbox(v___y_4772_);
v_res_4775_ = lp_bounded_Bounded_instDecidableEqObs_decEq___lam__0(v___y_112__boxed_4773_, v___y_113__boxed_4774_);
v_r_4776_ = lean_box(v_res_4775_);
return v_r_4776_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqObs_decEq___lam__1(lean_object* v___f_4777_, lean_object* v_a_4778_, lean_object* v_b_4779_){
_start:
{
lean_object* v___x_4780_; uint8_t v___x_4781_; 
v___x_4780_ = lean_alloc_closure((void*)(lp_bounded_Bounded_instDecidableEqStatus___boxed), 2, 0);
v___x_4781_ = l_instDecidableEqProd___redArg(v___x_4780_, v___f_4777_, v_a_4778_, v_b_4779_);
return v___x_4781_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqObs_decEq___lam__1___boxed(lean_object* v___f_4782_, lean_object* v_a_4783_, lean_object* v_b_4784_){
_start:
{
uint8_t v_res_4785_; lean_object* v_r_4786_; 
v_res_4785_ = lp_bounded_Bounded_instDecidableEqObs_decEq___lam__1(v___f_4782_, v_a_4783_, v_b_4784_);
v_r_4786_ = lean_box(v_res_4785_);
return v_r_4786_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqObs_decEq___lam__2(lean_object* v_a_4789_, lean_object* v_b_4790_){
_start:
{
lean_object* v___x_4791_; uint8_t v___x_4792_; 
v___x_4791_ = ((lean_object*)(lp_bounded_Bounded_instDecidableEqObs_decEq___lam__2___closed__0));
v___x_4792_ = l_Option_instDecidableEq___redArg(v___x_4791_, v_a_4789_, v_b_4790_);
return v___x_4792_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqObs_decEq___lam__2___boxed(lean_object* v_a_4793_, lean_object* v_b_4794_){
_start:
{
uint8_t v_res_4795_; lean_object* v_r_4796_; 
v_res_4795_ = lp_bounded_Bounded_instDecidableEqObs_decEq___lam__2(v_a_4793_, v_b_4794_);
v_r_4796_ = lean_box(v_res_4795_);
return v_r_4796_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqObs_decEq(lean_object* v_x_4801_, lean_object* v_x_4802_){
_start:
{
lean_object* v_statuses_4803_; lean_object* v_store_4804_; uint8_t v_quiescent_4805_; lean_object* v_statuses_4806_; lean_object* v_store_4807_; uint8_t v_quiescent_4808_; lean_object* v___f_4809_; uint8_t v___x_4810_; 
v_statuses_4803_ = lean_ctor_get(v_x_4801_, 0);
lean_inc_ref(v_statuses_4803_);
v_store_4804_ = lean_ctor_get(v_x_4801_, 1);
lean_inc_ref(v_store_4804_);
v_quiescent_4805_ = lean_ctor_get_uint8(v_x_4801_, sizeof(void*)*2);
lean_dec_ref(v_x_4801_);
v_statuses_4806_ = lean_ctor_get(v_x_4802_, 0);
lean_inc_ref(v_statuses_4806_);
v_store_4807_ = lean_ctor_get(v_x_4802_, 1);
lean_inc_ref(v_store_4807_);
v_quiescent_4808_ = lean_ctor_get_uint8(v_x_4802_, sizeof(void*)*2);
lean_dec_ref(v_x_4802_);
v___f_4809_ = ((lean_object*)(lp_bounded_Bounded_instDecidableEqObs_decEq___closed__1));
v___x_4810_ = lp_bounded_Bounded_instDecidableEqSMap_decEq___redArg(v___f_4809_, v_statuses_4803_, v_statuses_4806_);
if (v___x_4810_ == 0)
{
lean_dec_ref(v_store_4807_);
lean_dec_ref(v_store_4804_);
return v___x_4810_;
}
else
{
lean_object* v___f_4811_; uint8_t v___x_4812_; 
v___f_4811_ = ((lean_object*)(lp_bounded_Bounded_instDecidableEqObs_decEq___closed__2));
v___x_4812_ = lp_bounded_Bounded_instDecidableEqKMap_decEq___redArg(v___f_4811_, v_store_4804_, v_store_4807_);
if (v___x_4812_ == 0)
{
return v___x_4812_;
}
else
{
if (v_quiescent_4805_ == 0)
{
if (v_quiescent_4808_ == 0)
{
return v___x_4812_;
}
else
{
return v_quiescent_4805_;
}
}
else
{
return v_quiescent_4808_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqObs_decEq___boxed(lean_object* v_x_4813_, lean_object* v_x_4814_){
_start:
{
uint8_t v_res_4815_; lean_object* v_r_4816_; 
v_res_4815_ = lp_bounded_Bounded_instDecidableEqObs_decEq(v_x_4813_, v_x_4814_);
v_r_4816_ = lean_box(v_res_4815_);
return v_r_4816_;
}
}
LEAN_EXPORT uint8_t lp_bounded_Bounded_instDecidableEqObs(lean_object* v_x_4817_, lean_object* v_x_4818_){
_start:
{
uint8_t v___x_4819_; 
v___x_4819_ = lp_bounded_Bounded_instDecidableEqObs_decEq(v_x_4817_, v_x_4818_);
return v___x_4819_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instDecidableEqObs___boxed(lean_object* v_x_4820_, lean_object* v_x_4821_){
_start:
{
uint8_t v_res_4822_; lean_object* v_r_4823_; 
v_res_4822_ = lp_bounded_Bounded_instDecidableEqObs(v_x_4820_, v_x_4821_);
v_r_4823_ = lean_box(v_res_4822_);
return v_r_4823_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Prod_repr___at___00Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0_spec__0___redArg(lean_object* v_x_4824_){
_start:
{
lean_object* v_fst_4825_; lean_object* v_snd_4826_; lean_object* v___x_4828_; uint8_t v_isShared_4829_; uint8_t v_isSharedCheck_4851_; 
v_fst_4825_ = lean_ctor_get(v_x_4824_, 0);
v_snd_4826_ = lean_ctor_get(v_x_4824_, 1);
v_isSharedCheck_4851_ = !lean_is_exclusive(v_x_4824_);
if (v_isSharedCheck_4851_ == 0)
{
v___x_4828_ = v_x_4824_;
v_isShared_4829_ = v_isSharedCheck_4851_;
goto v_resetjp_4827_;
}
else
{
lean_inc(v_snd_4826_);
lean_inc(v_fst_4825_);
lean_dec(v_x_4824_);
v___x_4828_ = lean_box(0);
v_isShared_4829_ = v_isSharedCheck_4851_;
goto v_resetjp_4827_;
}
v_resetjp_4827_:
{
lean_object* v___x_4830_; uint8_t v___x_4831_; lean_object* v___x_4832_; lean_object* v___x_4833_; lean_object* v___x_4835_; 
v___x_4830_ = lean_unsigned_to_nat(0u);
v___x_4831_ = lean_unbox(v_fst_4825_);
lean_dec(v_fst_4825_);
v___x_4832_ = lp_bounded_Bounded_instReprStatus_repr(v___x_4831_, v___x_4830_);
v___x_4833_ = lean_box(0);
if (v_isShared_4829_ == 0)
{
lean_ctor_set_tag(v___x_4828_, 1);
lean_ctor_set(v___x_4828_, 1, v___x_4833_);
lean_ctor_set(v___x_4828_, 0, v___x_4832_);
v___x_4835_ = v___x_4828_;
goto v_reusejp_4834_;
}
else
{
lean_object* v_reuseFailAlloc_4850_; 
v_reuseFailAlloc_4850_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_4850_, 0, v___x_4832_);
lean_ctor_set(v_reuseFailAlloc_4850_, 1, v___x_4833_);
v___x_4835_ = v_reuseFailAlloc_4850_;
goto v_reusejp_4834_;
}
v_reusejp_4834_:
{
uint8_t v___x_4836_; lean_object* v___x_4837_; lean_object* v___x_4838_; lean_object* v___x_4839_; lean_object* v___x_4840_; lean_object* v___x_4841_; lean_object* v___x_4842_; lean_object* v___x_4843_; lean_object* v___x_4844_; lean_object* v___x_4845_; lean_object* v___x_4846_; lean_object* v___x_4847_; uint8_t v___x_4848_; lean_object* v___x_4849_; 
v___x_4836_ = lean_unbox(v_snd_4826_);
lean_dec(v_snd_4826_);
v___x_4837_ = l_Bool_repr___redArg(v___x_4836_);
v___x_4838_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_4838_, 0, v___x_4837_);
lean_ctor_set(v___x_4838_, 1, v___x_4835_);
v___x_4839_ = l_List_reverse___redArg(v___x_4838_);
v___x_4840_ = ((lean_object*)(lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg___closed__3));
v___x_4841_ = l_Std_Format_joinSep___at___00Lean_Syntax_formatStxAux_spec__2(v___x_4839_, v___x_4840_);
v___x_4842_ = lean_obj_once(&lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg___closed__6, &lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg___closed__6_once, _init_lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg___closed__6);
v___x_4843_ = ((lean_object*)(lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg___closed__7));
v___x_4844_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_4844_, 0, v___x_4843_);
lean_ctor_set(v___x_4844_, 1, v___x_4841_);
v___x_4845_ = ((lean_object*)(lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg___closed__8));
v___x_4846_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_4846_, 0, v___x_4844_);
lean_ctor_set(v___x_4846_, 1, v___x_4845_);
v___x_4847_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_4847_, 0, v___x_4842_);
lean_ctor_set(v___x_4847_, 1, v___x_4846_);
v___x_4848_ = 0;
v___x_4849_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_4849_, 0, v___x_4847_);
lean_ctor_set_uint8(v___x_4849_, sizeof(void*)*1, v___x_4848_);
return v___x_4849_;
}
}
}
}
static lean_object* _init_lp_bounded_Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0___redArg___closed__4(void){
_start:
{
lean_object* v___x_4861_; lean_object* v___x_4862_; 
v___x_4861_ = lean_unsigned_to_nat(6u);
v___x_4862_ = lean_nat_to_int(v___x_4861_);
return v___x_4862_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0___redArg(lean_object* v_x_4869_){
_start:
{
lean_object* v_s0_4870_; lean_object* v_s1_4871_; lean_object* v_s2_4872_; lean_object* v___x_4873_; lean_object* v___x_4874_; lean_object* v___x_4875_; lean_object* v___x_4876_; lean_object* v___x_4877_; uint8_t v___x_4878_; lean_object* v___x_4879_; lean_object* v___x_4880_; lean_object* v___x_4881_; lean_object* v___x_4882_; lean_object* v___x_4883_; lean_object* v___x_4884_; lean_object* v___x_4885_; lean_object* v___x_4886_; lean_object* v___x_4887_; lean_object* v___x_4888_; lean_object* v___x_4889_; lean_object* v___x_4890_; lean_object* v___x_4891_; lean_object* v___x_4892_; lean_object* v___x_4893_; lean_object* v___x_4894_; lean_object* v___x_4895_; lean_object* v___x_4896_; lean_object* v___x_4897_; lean_object* v___x_4898_; lean_object* v___x_4899_; lean_object* v___x_4900_; lean_object* v___x_4901_; lean_object* v___x_4902_; lean_object* v___x_4903_; lean_object* v___x_4904_; lean_object* v___x_4905_; lean_object* v___x_4906_; lean_object* v___x_4907_; 
v_s0_4870_ = lean_ctor_get(v_x_4869_, 0);
lean_inc(v_s0_4870_);
v_s1_4871_ = lean_ctor_get(v_x_4869_, 1);
lean_inc(v_s1_4871_);
v_s2_4872_ = lean_ctor_get(v_x_4869_, 2);
lean_inc(v_s2_4872_);
lean_dec_ref(v_x_4869_);
v___x_4873_ = ((lean_object*)(lp_bounded_Bounded_instReprSigR_repr___redArg___closed__5));
v___x_4874_ = ((lean_object*)(lp_bounded_Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0___redArg___closed__3));
v___x_4875_ = lean_obj_once(&lp_bounded_Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0___redArg___closed__4, &lp_bounded_Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0___redArg___closed__4_once, _init_lp_bounded_Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0___redArg___closed__4);
v___x_4876_ = lp_bounded_Prod_repr___at___00Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0_spec__0___redArg(v_s0_4870_);
v___x_4877_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_4877_, 0, v___x_4875_);
lean_ctor_set(v___x_4877_, 1, v___x_4876_);
v___x_4878_ = 0;
v___x_4879_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_4879_, 0, v___x_4877_);
lean_ctor_set_uint8(v___x_4879_, sizeof(void*)*1, v___x_4878_);
v___x_4880_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_4880_, 0, v___x_4874_);
lean_ctor_set(v___x_4880_, 1, v___x_4879_);
v___x_4881_ = ((lean_object*)(lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg___closed__2));
v___x_4882_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_4882_, 0, v___x_4880_);
lean_ctor_set(v___x_4882_, 1, v___x_4881_);
v___x_4883_ = lean_box(1);
v___x_4884_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_4884_, 0, v___x_4882_);
lean_ctor_set(v___x_4884_, 1, v___x_4883_);
v___x_4885_ = ((lean_object*)(lp_bounded_Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0___redArg___closed__6));
v___x_4886_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_4886_, 0, v___x_4884_);
lean_ctor_set(v___x_4886_, 1, v___x_4885_);
v___x_4887_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_4887_, 0, v___x_4886_);
lean_ctor_set(v___x_4887_, 1, v___x_4873_);
v___x_4888_ = lp_bounded_Prod_repr___at___00Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0_spec__0___redArg(v_s1_4871_);
v___x_4889_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_4889_, 0, v___x_4875_);
lean_ctor_set(v___x_4889_, 1, v___x_4888_);
v___x_4890_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_4890_, 0, v___x_4889_);
lean_ctor_set_uint8(v___x_4890_, sizeof(void*)*1, v___x_4878_);
v___x_4891_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_4891_, 0, v___x_4887_);
lean_ctor_set(v___x_4891_, 1, v___x_4890_);
v___x_4892_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_4892_, 0, v___x_4891_);
lean_ctor_set(v___x_4892_, 1, v___x_4881_);
v___x_4893_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_4893_, 0, v___x_4892_);
lean_ctor_set(v___x_4893_, 1, v___x_4883_);
v___x_4894_ = ((lean_object*)(lp_bounded_Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0___redArg___closed__8));
v___x_4895_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_4895_, 0, v___x_4893_);
lean_ctor_set(v___x_4895_, 1, v___x_4894_);
v___x_4896_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_4896_, 0, v___x_4895_);
lean_ctor_set(v___x_4896_, 1, v___x_4873_);
v___x_4897_ = lp_bounded_Prod_repr___at___00Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0_spec__0___redArg(v_s2_4872_);
v___x_4898_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_4898_, 0, v___x_4875_);
lean_ctor_set(v___x_4898_, 1, v___x_4897_);
v___x_4899_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_4899_, 0, v___x_4898_);
lean_ctor_set_uint8(v___x_4899_, sizeof(void*)*1, v___x_4878_);
v___x_4900_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_4900_, 0, v___x_4896_);
lean_ctor_set(v___x_4900_, 1, v___x_4899_);
v___x_4901_ = lean_obj_once(&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__41, &lp_bounded_Bounded_instReprSigR_repr___redArg___closed__41_once, _init_lp_bounded_Bounded_instReprSigR_repr___redArg___closed__41);
v___x_4902_ = ((lean_object*)(lp_bounded_Bounded_instReprSigR_repr___redArg___closed__42));
v___x_4903_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_4903_, 0, v___x_4902_);
lean_ctor_set(v___x_4903_, 1, v___x_4900_);
v___x_4904_ = ((lean_object*)(lp_bounded_Bounded_instReprSigR_repr___redArg___closed__43));
v___x_4905_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_4905_, 0, v___x_4903_);
lean_ctor_set(v___x_4905_, 1, v___x_4904_);
v___x_4906_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_4906_, 0, v___x_4901_);
lean_ctor_set(v___x_4906_, 1, v___x_4905_);
v___x_4907_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_4907_, 0, v___x_4906_);
lean_ctor_set_uint8(v___x_4907_, sizeof(void*)*1, v___x_4878_);
return v___x_4907_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Option_repr___at___00Bounded_instReprKMap_repr___at___00Bounded_instReprObs_repr_spec__1_spec__2(lean_object* v_x_4908_, lean_object* v_x_4909_){
_start:
{
if (lean_obj_tag(v_x_4908_) == 0)
{
lean_object* v___x_4910_; 
v___x_4910_ = ((lean_object*)(lp_bounded_Option_repr___at___00Bounded_instReprSigR_repr_spec__0___closed__1));
return v___x_4910_;
}
else
{
lean_object* v_val_4911_; lean_object* v___x_4913_; uint8_t v_isShared_4914_; uint8_t v_isSharedCheck_4922_; 
v_val_4911_ = lean_ctor_get(v_x_4908_, 0);
v_isSharedCheck_4922_ = !lean_is_exclusive(v_x_4908_);
if (v_isSharedCheck_4922_ == 0)
{
v___x_4913_ = v_x_4908_;
v_isShared_4914_ = v_isSharedCheck_4922_;
goto v_resetjp_4912_;
}
else
{
lean_inc(v_val_4911_);
lean_dec(v_x_4908_);
v___x_4913_ = lean_box(0);
v_isShared_4914_ = v_isSharedCheck_4922_;
goto v_resetjp_4912_;
}
v_resetjp_4912_:
{
lean_object* v___x_4915_; lean_object* v___x_4916_; lean_object* v___x_4918_; 
v___x_4915_ = ((lean_object*)(lp_bounded_Option_repr___at___00Bounded_instReprSigR_repr_spec__0___closed__3));
v___x_4916_ = l_Nat_reprFast(v_val_4911_);
if (v_isShared_4914_ == 0)
{
lean_ctor_set_tag(v___x_4913_, 3);
lean_ctor_set(v___x_4913_, 0, v___x_4916_);
v___x_4918_ = v___x_4913_;
goto v_reusejp_4917_;
}
else
{
lean_object* v_reuseFailAlloc_4921_; 
v_reuseFailAlloc_4921_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v_reuseFailAlloc_4921_, 0, v___x_4916_);
v___x_4918_ = v_reuseFailAlloc_4921_;
goto v_reusejp_4917_;
}
v_reusejp_4917_:
{
lean_object* v___x_4919_; lean_object* v___x_4920_; 
v___x_4919_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_4919_, 0, v___x_4915_);
lean_ctor_set(v___x_4919_, 1, v___x_4918_);
v___x_4920_ = l_Repr_addAppParen(v___x_4919_, v_x_4909_);
return v___x_4920_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_Option_repr___at___00Bounded_instReprKMap_repr___at___00Bounded_instReprObs_repr_spec__1_spec__2___boxed(lean_object* v_x_4923_, lean_object* v_x_4924_){
_start:
{
lean_object* v_res_4925_; 
v_res_4925_ = lp_bounded_Option_repr___at___00Bounded_instReprKMap_repr___at___00Bounded_instReprObs_repr_spec__1_spec__2(v_x_4923_, v_x_4924_);
lean_dec(v_x_4924_);
return v_res_4925_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprKMap_repr___at___00Bounded_instReprObs_repr_spec__1___redArg(lean_object* v_x_4938_){
_start:
{
lean_object* v_k0_4939_; lean_object* v_k1_4940_; lean_object* v___x_4942_; uint8_t v_isShared_4943_; uint8_t v_isSharedCheck_4973_; 
v_k0_4939_ = lean_ctor_get(v_x_4938_, 0);
v_k1_4940_ = lean_ctor_get(v_x_4938_, 1);
v_isSharedCheck_4973_ = !lean_is_exclusive(v_x_4938_);
if (v_isSharedCheck_4973_ == 0)
{
v___x_4942_ = v_x_4938_;
v_isShared_4943_ = v_isSharedCheck_4973_;
goto v_resetjp_4941_;
}
else
{
lean_inc(v_k1_4940_);
lean_inc(v_k0_4939_);
lean_dec(v_x_4938_);
v___x_4942_ = lean_box(0);
v_isShared_4943_ = v_isSharedCheck_4973_;
goto v_resetjp_4941_;
}
v_resetjp_4941_:
{
lean_object* v___x_4944_; lean_object* v___x_4945_; lean_object* v___x_4946_; lean_object* v___x_4947_; lean_object* v___x_4948_; lean_object* v___x_4950_; 
v___x_4944_ = ((lean_object*)(lp_bounded_Bounded_instReprSigR_repr___redArg___closed__5));
v___x_4945_ = ((lean_object*)(lp_bounded_Bounded_instReprKMap_repr___at___00Bounded_instReprObs_repr_spec__1___redArg___closed__3));
v___x_4946_ = lean_obj_once(&lp_bounded_Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0___redArg___closed__4, &lp_bounded_Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0___redArg___closed__4_once, _init_lp_bounded_Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0___redArg___closed__4);
v___x_4947_ = lean_unsigned_to_nat(0u);
v___x_4948_ = lp_bounded_Option_repr___at___00Bounded_instReprKMap_repr___at___00Bounded_instReprObs_repr_spec__1_spec__2(v_k0_4939_, v___x_4947_);
if (v_isShared_4943_ == 0)
{
lean_ctor_set_tag(v___x_4942_, 4);
lean_ctor_set(v___x_4942_, 1, v___x_4948_);
lean_ctor_set(v___x_4942_, 0, v___x_4946_);
v___x_4950_ = v___x_4942_;
goto v_reusejp_4949_;
}
else
{
lean_object* v_reuseFailAlloc_4972_; 
v_reuseFailAlloc_4972_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v_reuseFailAlloc_4972_, 0, v___x_4946_);
lean_ctor_set(v_reuseFailAlloc_4972_, 1, v___x_4948_);
v___x_4950_ = v_reuseFailAlloc_4972_;
goto v_reusejp_4949_;
}
v_reusejp_4949_:
{
uint8_t v___x_4951_; lean_object* v___x_4952_; lean_object* v___x_4953_; lean_object* v___x_4954_; lean_object* v___x_4955_; lean_object* v___x_4956_; lean_object* v___x_4957_; lean_object* v___x_4958_; lean_object* v___x_4959_; lean_object* v___x_4960_; lean_object* v___x_4961_; lean_object* v___x_4962_; lean_object* v___x_4963_; lean_object* v___x_4964_; lean_object* v___x_4965_; lean_object* v___x_4966_; lean_object* v___x_4967_; lean_object* v___x_4968_; lean_object* v___x_4969_; lean_object* v___x_4970_; lean_object* v___x_4971_; 
v___x_4951_ = 0;
v___x_4952_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_4952_, 0, v___x_4950_);
lean_ctor_set_uint8(v___x_4952_, sizeof(void*)*1, v___x_4951_);
v___x_4953_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_4953_, 0, v___x_4945_);
lean_ctor_set(v___x_4953_, 1, v___x_4952_);
v___x_4954_ = ((lean_object*)(lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg___closed__2));
v___x_4955_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_4955_, 0, v___x_4953_);
lean_ctor_set(v___x_4955_, 1, v___x_4954_);
v___x_4956_ = lean_box(1);
v___x_4957_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_4957_, 0, v___x_4955_);
lean_ctor_set(v___x_4957_, 1, v___x_4956_);
v___x_4958_ = ((lean_object*)(lp_bounded_Bounded_instReprKMap_repr___at___00Bounded_instReprObs_repr_spec__1___redArg___closed__5));
v___x_4959_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_4959_, 0, v___x_4957_);
lean_ctor_set(v___x_4959_, 1, v___x_4958_);
v___x_4960_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_4960_, 0, v___x_4959_);
lean_ctor_set(v___x_4960_, 1, v___x_4944_);
v___x_4961_ = lp_bounded_Option_repr___at___00Bounded_instReprKMap_repr___at___00Bounded_instReprObs_repr_spec__1_spec__2(v_k1_4940_, v___x_4947_);
v___x_4962_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_4962_, 0, v___x_4946_);
lean_ctor_set(v___x_4962_, 1, v___x_4961_);
v___x_4963_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_4963_, 0, v___x_4962_);
lean_ctor_set_uint8(v___x_4963_, sizeof(void*)*1, v___x_4951_);
v___x_4964_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_4964_, 0, v___x_4960_);
lean_ctor_set(v___x_4964_, 1, v___x_4963_);
v___x_4965_ = lean_obj_once(&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__41, &lp_bounded_Bounded_instReprSigR_repr___redArg___closed__41_once, _init_lp_bounded_Bounded_instReprSigR_repr___redArg___closed__41);
v___x_4966_ = ((lean_object*)(lp_bounded_Bounded_instReprSigR_repr___redArg___closed__42));
v___x_4967_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_4967_, 0, v___x_4966_);
lean_ctor_set(v___x_4967_, 1, v___x_4964_);
v___x_4968_ = ((lean_object*)(lp_bounded_Bounded_instReprSigR_repr___redArg___closed__43));
v___x_4969_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_4969_, 0, v___x_4967_);
lean_ctor_set(v___x_4969_, 1, v___x_4968_);
v___x_4970_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_4970_, 0, v___x_4965_);
lean_ctor_set(v___x_4970_, 1, v___x_4969_);
v___x_4971_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_4971_, 0, v___x_4970_);
lean_ctor_set_uint8(v___x_4971_, sizeof(void*)*1, v___x_4951_);
return v___x_4971_;
}
}
}
}
static lean_object* _init_lp_bounded_Bounded_instReprObs_repr___redArg___closed__8(void){
_start:
{
lean_object* v___x_4989_; lean_object* v___x_4990_; 
v___x_4989_ = lean_unsigned_to_nat(13u);
v___x_4990_ = lean_nat_to_int(v___x_4989_);
return v___x_4990_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprObs_repr___redArg(lean_object* v_x_4991_){
_start:
{
lean_object* v_statuses_4992_; lean_object* v_store_4993_; uint8_t v_quiescent_4994_; lean_object* v___x_4995_; lean_object* v___x_4996_; lean_object* v___x_4997_; lean_object* v___x_4998_; lean_object* v___x_4999_; uint8_t v___x_5000_; lean_object* v___x_5001_; lean_object* v___x_5002_; lean_object* v___x_5003_; lean_object* v___x_5004_; lean_object* v___x_5005_; lean_object* v___x_5006_; lean_object* v___x_5007_; lean_object* v___x_5008_; lean_object* v___x_5009_; lean_object* v___x_5010_; lean_object* v___x_5011_; lean_object* v___x_5012_; lean_object* v___x_5013_; lean_object* v___x_5014_; lean_object* v___x_5015_; lean_object* v___x_5016_; lean_object* v___x_5017_; lean_object* v___x_5018_; lean_object* v___x_5019_; lean_object* v___x_5020_; lean_object* v___x_5021_; lean_object* v___x_5022_; lean_object* v___x_5023_; lean_object* v___x_5024_; lean_object* v___x_5025_; lean_object* v___x_5026_; lean_object* v___x_5027_; lean_object* v___x_5028_; lean_object* v___x_5029_; lean_object* v___x_5030_; lean_object* v___x_5031_; 
v_statuses_4992_ = lean_ctor_get(v_x_4991_, 0);
lean_inc_ref(v_statuses_4992_);
v_store_4993_ = lean_ctor_get(v_x_4991_, 1);
lean_inc_ref(v_store_4993_);
v_quiescent_4994_ = lean_ctor_get_uint8(v_x_4991_, sizeof(void*)*2);
lean_dec_ref(v_x_4991_);
v___x_4995_ = ((lean_object*)(lp_bounded_Bounded_instReprSigR_repr___redArg___closed__5));
v___x_4996_ = ((lean_object*)(lp_bounded_Bounded_instReprObs_repr___redArg___closed__3));
v___x_4997_ = lean_obj_once(&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__16, &lp_bounded_Bounded_instReprSigR_repr___redArg___closed__16_once, _init_lp_bounded_Bounded_instReprSigR_repr___redArg___closed__16);
v___x_4998_ = lp_bounded_Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0___redArg(v_statuses_4992_);
v___x_4999_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_4999_, 0, v___x_4997_);
lean_ctor_set(v___x_4999_, 1, v___x_4998_);
v___x_5000_ = 0;
v___x_5001_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_5001_, 0, v___x_4999_);
lean_ctor_set_uint8(v___x_5001_, sizeof(void*)*1, v___x_5000_);
v___x_5002_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_5002_, 0, v___x_4996_);
lean_ctor_set(v___x_5002_, 1, v___x_5001_);
v___x_5003_ = ((lean_object*)(lp_bounded_Prod_repr___at___00Bounded_instReprSigR_repr_spec__1___redArg___closed__2));
v___x_5004_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_5004_, 0, v___x_5002_);
lean_ctor_set(v___x_5004_, 1, v___x_5003_);
v___x_5005_ = lean_box(1);
v___x_5006_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_5006_, 0, v___x_5004_);
lean_ctor_set(v___x_5006_, 1, v___x_5005_);
v___x_5007_ = ((lean_object*)(lp_bounded_Bounded_instReprObs_repr___redArg___closed__5));
v___x_5008_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_5008_, 0, v___x_5006_);
lean_ctor_set(v___x_5008_, 1, v___x_5007_);
v___x_5009_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_5009_, 0, v___x_5008_);
lean_ctor_set(v___x_5009_, 1, v___x_4995_);
v___x_5010_ = lean_obj_once(&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__13, &lp_bounded_Bounded_instReprSigR_repr___redArg___closed__13_once, _init_lp_bounded_Bounded_instReprSigR_repr___redArg___closed__13);
v___x_5011_ = lp_bounded_Bounded_instReprKMap_repr___at___00Bounded_instReprObs_repr_spec__1___redArg(v_store_4993_);
v___x_5012_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_5012_, 0, v___x_5010_);
lean_ctor_set(v___x_5012_, 1, v___x_5011_);
v___x_5013_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_5013_, 0, v___x_5012_);
lean_ctor_set_uint8(v___x_5013_, sizeof(void*)*1, v___x_5000_);
v___x_5014_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_5014_, 0, v___x_5009_);
lean_ctor_set(v___x_5014_, 1, v___x_5013_);
v___x_5015_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_5015_, 0, v___x_5014_);
lean_ctor_set(v___x_5015_, 1, v___x_5003_);
v___x_5016_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_5016_, 0, v___x_5015_);
lean_ctor_set(v___x_5016_, 1, v___x_5005_);
v___x_5017_ = ((lean_object*)(lp_bounded_Bounded_instReprObs_repr___redArg___closed__7));
v___x_5018_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_5018_, 0, v___x_5016_);
lean_ctor_set(v___x_5018_, 1, v___x_5017_);
v___x_5019_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_5019_, 0, v___x_5018_);
lean_ctor_set(v___x_5019_, 1, v___x_4995_);
v___x_5020_ = lean_obj_once(&lp_bounded_Bounded_instReprObs_repr___redArg___closed__8, &lp_bounded_Bounded_instReprObs_repr___redArg___closed__8_once, _init_lp_bounded_Bounded_instReprObs_repr___redArg___closed__8);
v___x_5021_ = l_Bool_repr___redArg(v_quiescent_4994_);
v___x_5022_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_5022_, 0, v___x_5020_);
lean_ctor_set(v___x_5022_, 1, v___x_5021_);
v___x_5023_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_5023_, 0, v___x_5022_);
lean_ctor_set_uint8(v___x_5023_, sizeof(void*)*1, v___x_5000_);
v___x_5024_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_5024_, 0, v___x_5019_);
lean_ctor_set(v___x_5024_, 1, v___x_5023_);
v___x_5025_ = lean_obj_once(&lp_bounded_Bounded_instReprSigR_repr___redArg___closed__41, &lp_bounded_Bounded_instReprSigR_repr___redArg___closed__41_once, _init_lp_bounded_Bounded_instReprSigR_repr___redArg___closed__41);
v___x_5026_ = ((lean_object*)(lp_bounded_Bounded_instReprSigR_repr___redArg___closed__42));
v___x_5027_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_5027_, 0, v___x_5026_);
lean_ctor_set(v___x_5027_, 1, v___x_5024_);
v___x_5028_ = ((lean_object*)(lp_bounded_Bounded_instReprSigR_repr___redArg___closed__43));
v___x_5029_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_5029_, 0, v___x_5027_);
lean_ctor_set(v___x_5029_, 1, v___x_5028_);
v___x_5030_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_5030_, 0, v___x_5025_);
lean_ctor_set(v___x_5030_, 1, v___x_5029_);
v___x_5031_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_5031_, 0, v___x_5030_);
lean_ctor_set_uint8(v___x_5031_, sizeof(void*)*1, v___x_5000_);
return v___x_5031_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprObs_repr(lean_object* v_x_5032_, lean_object* v_prec_5033_){
_start:
{
lean_object* v___x_5034_; 
v___x_5034_ = lp_bounded_Bounded_instReprObs_repr___redArg(v_x_5032_);
return v___x_5034_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprObs_repr___boxed(lean_object* v_x_5035_, lean_object* v_prec_5036_){
_start:
{
lean_object* v_res_5037_; 
v_res_5037_ = lp_bounded_Bounded_instReprObs_repr(v_x_5035_, v_prec_5036_);
lean_dec(v_prec_5036_);
return v_res_5037_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0(lean_object* v_x_5038_, lean_object* v_prec_5039_){
_start:
{
lean_object* v___x_5040_; 
v___x_5040_ = lp_bounded_Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0___redArg(v_x_5038_);
return v___x_5040_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0___boxed(lean_object* v_x_5041_, lean_object* v_prec_5042_){
_start:
{
lean_object* v_res_5043_; 
v_res_5043_ = lp_bounded_Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0(v_x_5041_, v_prec_5042_);
lean_dec(v_prec_5042_);
return v_res_5043_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprKMap_repr___at___00Bounded_instReprObs_repr_spec__1(lean_object* v_x_5044_, lean_object* v_prec_5045_){
_start:
{
lean_object* v___x_5046_; 
v___x_5046_ = lp_bounded_Bounded_instReprKMap_repr___at___00Bounded_instReprObs_repr_spec__1___redArg(v_x_5044_);
return v___x_5046_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_instReprKMap_repr___at___00Bounded_instReprObs_repr_spec__1___boxed(lean_object* v_x_5047_, lean_object* v_prec_5048_){
_start:
{
lean_object* v_res_5049_; 
v_res_5049_ = lp_bounded_Bounded_instReprKMap_repr___at___00Bounded_instReprObs_repr_spec__1(v_x_5047_, v_prec_5048_);
lean_dec(v_prec_5048_);
return v_res_5049_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Prod_repr___at___00Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0_spec__0(lean_object* v_x_5050_, lean_object* v_x_5051_){
_start:
{
lean_object* v___x_5052_; 
v___x_5052_ = lp_bounded_Prod_repr___at___00Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0_spec__0___redArg(v_x_5050_);
return v___x_5052_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Prod_repr___at___00Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0_spec__0___boxed(lean_object* v_x_5053_, lean_object* v_x_5054_){
_start:
{
lean_object* v_res_5055_; 
v_res_5055_ = lp_bounded_Prod_repr___at___00Bounded_instReprSMap_repr___at___00Bounded_instReprObs_repr_spec__0_spec__0(v_x_5053_, v_x_5054_);
lean_dec(v_x_5054_);
return v_res_5055_;
}
}
static lean_object* _init_lp_bounded_Bounded_obs___closed__0(void){
_start:
{
lean_object* v___x_5058_; lean_object* v___x_5059_; lean_object* v___x_5060_; 
v___x_5058_ = lean_unsigned_to_nat(3u);
v___x_5059_ = lean_unsigned_to_nat(0u);
v___x_5060_ = lean_nat_mod(v___x_5059_, v___x_5058_);
return v___x_5060_;
}
}
static lean_object* _init_lp_bounded_Bounded_obs___closed__1(void){
_start:
{
lean_object* v___x_5061_; lean_object* v___x_5062_; lean_object* v___x_5063_; 
v___x_5061_ = lean_unsigned_to_nat(3u);
v___x_5062_ = lean_unsigned_to_nat(1u);
v___x_5063_ = lean_nat_mod(v___x_5062_, v___x_5061_);
return v___x_5063_;
}
}
static lean_object* _init_lp_bounded_Bounded_obs___closed__2(void){
_start:
{
lean_object* v___x_5064_; lean_object* v___x_5065_; lean_object* v___x_5066_; 
v___x_5064_ = lean_unsigned_to_nat(3u);
v___x_5065_ = lean_unsigned_to_nat(2u);
v___x_5066_ = lean_nat_mod(v___x_5065_, v___x_5064_);
return v___x_5066_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_obs(lean_object* v_00_u03b3_5067_){
_start:
{
lean_object* v___x_5068_; lean_object* v___x_5069_; lean_object* v___x_5070_; lean_object* v___x_5071_; lean_object* v___x_5072_; lean_object* v___x_5073_; lean_object* v___x_5074_; lean_object* v___x_5075_; lean_object* v___x_5076_; lean_object* v___x_5077_; lean_object* v___x_5078_; lean_object* v___x_5079_; uint8_t v___x_5080_; lean_object* v___x_5081_; 
v___x_5068_ = lean_obj_once(&lp_bounded_Bounded_obs___closed__0, &lp_bounded_Bounded_obs___closed__0_once, _init_lp_bounded_Bounded_obs___closed__0);
v___x_5069_ = lp_bounded_Bounded_SMap_get___redArg(v_00_u03b3_5067_, v___x_5068_);
v___x_5070_ = lp_bounded_Bounded_statusOf(v___x_5069_);
v___x_5071_ = lean_obj_once(&lp_bounded_Bounded_obs___closed__1, &lp_bounded_Bounded_obs___closed__1_once, _init_lp_bounded_Bounded_obs___closed__1);
v___x_5072_ = lp_bounded_Bounded_SMap_get___redArg(v_00_u03b3_5067_, v___x_5071_);
v___x_5073_ = lp_bounded_Bounded_statusOf(v___x_5072_);
v___x_5074_ = lean_obj_once(&lp_bounded_Bounded_obs___closed__2, &lp_bounded_Bounded_obs___closed__2_once, _init_lp_bounded_Bounded_obs___closed__2);
v___x_5075_ = lp_bounded_Bounded_SMap_get___redArg(v_00_u03b3_5067_, v___x_5074_);
v___x_5076_ = lp_bounded_Bounded_statusOf(v___x_5075_);
v___x_5077_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_5077_, 0, v___x_5070_);
lean_ctor_set(v___x_5077_, 1, v___x_5073_);
lean_ctor_set(v___x_5077_, 2, v___x_5076_);
lean_inc_ref(v_00_u03b3_5067_);
v___x_5078_ = lean_alloc_closure((void*)(lp_bounded_Bounded_storeOf___boxed), 2, 1);
lean_closure_set(v___x_5078_, 0, v_00_u03b3_5067_);
v___x_5079_ = lp_bounded_Bounded_KMap_ofFun___redArg(v___x_5078_);
v___x_5080_ = lp_bounded_Bounded_quiet(v_00_u03b3_5067_);
v___x_5081_ = lean_alloc_ctor(0, 2, 1);
lean_ctor_set(v___x_5081_, 0, v___x_5077_);
lean_ctor_set(v___x_5081_, 1, v___x_5079_);
lean_ctor_set_uint8(v___x_5081_, sizeof(void*)*2, v___x_5080_);
return v___x_5081_;
}
}
LEAN_EXPORT lean_object* lp_bounded_Bounded_obsRow(lean_object* v_x_5082_){
_start:
{
if (lean_obj_tag(v_x_5082_) == 0)
{
lean_object* v___x_5083_; 
v___x_5083_ = lean_box(0);
return v___x_5083_;
}
else
{
lean_object* v_val_5084_; lean_object* v___x_5086_; uint8_t v_isShared_5087_; uint8_t v_isSharedCheck_5101_; 
v_val_5084_ = lean_ctor_get(v_x_5082_, 0);
v_isSharedCheck_5101_ = !lean_is_exclusive(v_x_5082_);
if (v_isSharedCheck_5101_ == 0)
{
v___x_5086_ = v_x_5082_;
v_isShared_5087_ = v_isSharedCheck_5101_;
goto v_resetjp_5085_;
}
else
{
lean_inc(v_val_5084_);
lean_dec(v_x_5082_);
v___x_5086_ = lean_box(0);
v_isShared_5087_ = v_isSharedCheck_5101_;
goto v_resetjp_5085_;
}
v_resetjp_5085_:
{
lean_object* v_fst_5088_; lean_object* v_snd_5089_; lean_object* v___x_5091_; uint8_t v_isShared_5092_; uint8_t v_isSharedCheck_5100_; 
v_fst_5088_ = lean_ctor_get(v_val_5084_, 0);
v_snd_5089_ = lean_ctor_get(v_val_5084_, 1);
v_isSharedCheck_5100_ = !lean_is_exclusive(v_val_5084_);
if (v_isSharedCheck_5100_ == 0)
{
v___x_5091_ = v_val_5084_;
v_isShared_5092_ = v_isSharedCheck_5100_;
goto v_resetjp_5090_;
}
else
{
lean_inc(v_snd_5089_);
lean_inc(v_fst_5088_);
lean_dec(v_val_5084_);
v___x_5091_ = lean_box(0);
v_isShared_5092_ = v_isSharedCheck_5100_;
goto v_resetjp_5090_;
}
v_resetjp_5090_:
{
lean_object* v___x_5093_; lean_object* v___x_5095_; 
v___x_5093_ = lp_bounded_Bounded_obs(v_snd_5089_);
if (v_isShared_5092_ == 0)
{
lean_ctor_set(v___x_5091_, 1, v___x_5093_);
v___x_5095_ = v___x_5091_;
goto v_reusejp_5094_;
}
else
{
lean_object* v_reuseFailAlloc_5099_; 
v_reuseFailAlloc_5099_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_5099_, 0, v_fst_5088_);
lean_ctor_set(v_reuseFailAlloc_5099_, 1, v___x_5093_);
v___x_5095_ = v_reuseFailAlloc_5099_;
goto v_reusejp_5094_;
}
v_reusejp_5094_:
{
lean_object* v___x_5097_; 
if (v_isShared_5087_ == 0)
{
lean_ctor_set(v___x_5086_, 0, v___x_5095_);
v___x_5097_ = v___x_5086_;
goto v_reusejp_5096_;
}
else
{
lean_object* v_reuseFailAlloc_5098_; 
v_reuseFailAlloc_5098_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_5098_, 0, v___x_5095_);
v___x_5097_ = v_reuseFailAlloc_5098_;
goto v_reusejp_5096_;
}
v_reusejp_5096_:
{
return v___x_5097_;
}
}
}
}
}
}
}
static lean_object* _init_lp_bounded_Bounded_cProv___closed__1(void){
_start:
{
lean_object* v___x_5107_; lean_object* v___x_5108_; 
v___x_5107_ = lean_obj_once(&lp_bounded_Bounded_childComp___closed__1, &lp_bounded_Bounded_childComp___closed__1_once, _init_lp_bounded_Bounded_childComp___closed__1);
v___x_5108_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_5108_, 0, v___x_5107_);
lean_ctor_set(v___x_5108_, 1, v___x_5107_);
return v___x_5108_;
}
}
static lean_object* _init_lp_bounded_Bounded_cProv___closed__2(void){
_start:
{
lean_object* v___x_5109_; lean_object* v___x_5110_; lean_object* v___x_5111_; 
v___x_5109_ = lean_box(0);
v___x_5110_ = lean_obj_once(&lp_bounded_Bounded_cProv___closed__1, &lp_bounded_Bounded_cProv___closed__1_once, _init_lp_bounded_Bounded_cProv___closed__1);
v___x_5111_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_5111_, 0, v___x_5110_);
lean_ctor_set(v___x_5111_, 1, v___x_5109_);
return v___x_5111_;
}
}
static lean_object* _init_lp_bounded_Bounded_cProv___closed__3(void){
_start:
{
lean_object* v___x_5112_; lean_object* v___x_5113_; lean_object* v___x_5114_; lean_object* v___x_5115_; 
v___x_5112_ = lean_obj_once(&lp_bounded_Bounded_cProv___closed__2, &lp_bounded_Bounded_cProv___closed__2_once, _init_lp_bounded_Bounded_cProv___closed__2);
v___x_5113_ = ((lean_object*)(lp_bounded_Bounded_cProv___closed__0));
v___x_5114_ = ((lean_object*)(lp_bounded_Bounded_childComp___closed__0));
v___x_5115_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_5115_, 0, v___x_5114_);
lean_ctor_set(v___x_5115_, 1, v___x_5113_);
lean_ctor_set(v___x_5115_, 2, v___x_5112_);
return v___x_5115_;
}
}
static lean_object* _init_lp_bounded_Bounded_cProv(void){
_start:
{
lean_object* v___x_5116_; 
v___x_5116_ = lean_obj_once(&lp_bounded_Bounded_cProv___closed__3, &lp_bounded_Bounded_cProv___closed__3_once, _init_lp_bounded_Bounded_cProv___closed__3);
return v___x_5116_;
}
}
static lean_object* _init_lp_bounded_Bounded_cCons___closed__0(void){
_start:
{
lean_object* v___x_5117_; lean_object* v___x_5118_; lean_object* v___x_5119_; 
v___x_5117_ = lean_unsigned_to_nat(2u);
v___x_5118_ = lean_unsigned_to_nat(1u);
v___x_5119_ = lean_nat_mod(v___x_5118_, v___x_5117_);
return v___x_5119_;
}
}
static lean_object* _init_lp_bounded_Bounded_cCons___closed__1(void){
_start:
{
lean_object* v___x_5120_; lean_object* v___x_5121_; 
v___x_5120_ = lean_obj_once(&lp_bounded_Bounded_cCons___closed__0, &lp_bounded_Bounded_cCons___closed__0_once, _init_lp_bounded_Bounded_cCons___closed__0);
v___x_5121_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_5121_, 0, v___x_5120_);
return v___x_5121_;
}
}
static lean_object* _init_lp_bounded_Bounded_cCons___closed__2(void){
_start:
{
lean_object* v___x_5122_; lean_object* v___x_5123_; lean_object* v___x_5124_; 
v___x_5122_ = lean_box(0);
v___x_5123_ = lean_obj_once(&lp_bounded_Bounded_cCons___closed__1, &lp_bounded_Bounded_cCons___closed__1_once, _init_lp_bounded_Bounded_cCons___closed__1);
v___x_5124_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_5124_, 0, v___x_5123_);
lean_ctor_set(v___x_5124_, 1, v___x_5122_);
return v___x_5124_;
}
}
static lean_object* _init_lp_bounded_Bounded_cCons___closed__3(void){
_start:
{
lean_object* v___x_5125_; lean_object* v___x_5126_; lean_object* v___x_5127_; 
v___x_5125_ = lean_obj_once(&lp_bounded_Bounded_cCons___closed__2, &lp_bounded_Bounded_cCons___closed__2_once, _init_lp_bounded_Bounded_cCons___closed__2);
v___x_5126_ = lean_obj_once(&lp_bounded_Bounded_childComp___closed__3, &lp_bounded_Bounded_childComp___closed__3_once, _init_lp_bounded_Bounded_childComp___closed__3);
v___x_5127_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_5127_, 0, v___x_5126_);
lean_ctor_set(v___x_5127_, 1, v___x_5125_);
return v___x_5127_;
}
}
static lean_object* _init_lp_bounded_Bounded_cCons___closed__4(void){
_start:
{
lean_object* v___x_5128_; lean_object* v___x_5129_; lean_object* v___x_5130_; 
v___x_5128_ = lean_obj_once(&lp_bounded_Bounded_cCons___closed__3, &lp_bounded_Bounded_cCons___closed__3_once, _init_lp_bounded_Bounded_cCons___closed__3);
v___x_5129_ = lean_obj_once(&lp_bounded_Bounded_childComp___closed__2, &lp_bounded_Bounded_childComp___closed__2_once, _init_lp_bounded_Bounded_childComp___closed__2);
v___x_5130_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_5130_, 0, v___x_5129_);
lean_ctor_set(v___x_5130_, 1, v___x_5128_);
return v___x_5130_;
}
}
static lean_object* _init_lp_bounded_Bounded_cCons___closed__5(void){
_start:
{
lean_object* v___x_5131_; lean_object* v___x_5132_; lean_object* v___x_5133_; lean_object* v___x_5134_; 
v___x_5131_ = lean_obj_once(&lp_bounded_Bounded_cCons___closed__4, &lp_bounded_Bounded_cCons___closed__4_once, _init_lp_bounded_Bounded_cCons___closed__4);
v___x_5132_ = ((lean_object*)(lp_bounded_Bounded_childComp___closed__0));
v___x_5133_ = ((lean_object*)(lp_bounded_Bounded_cProv___closed__0));
v___x_5134_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_5134_, 0, v___x_5133_);
lean_ctor_set(v___x_5134_, 1, v___x_5132_);
lean_ctor_set(v___x_5134_, 2, v___x_5131_);
return v___x_5134_;
}
}
static lean_object* _init_lp_bounded_Bounded_cCons(void){
_start:
{
lean_object* v___x_5135_; 
v___x_5135_ = lean_obj_once(&lp_bounded_Bounded_cCons___closed__5, &lp_bounded_Bounded_cCons___closed__5_once, _init_lp_bounded_Bounded_cCons___closed__5);
return v___x_5135_;
}
}
static lean_object* _init_lp_bounded_Bounded_catalog___closed__1(void){
_start:
{
lean_object* v___x_5147_; lean_object* v___x_5148_; lean_object* v___x_5149_; 
v___x_5147_ = ((lean_object*)(lp_bounded_Bounded_catalog___closed__0));
v___x_5148_ = lp_bounded_Bounded_cCons;
v___x_5149_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_5149_, 0, v___x_5148_);
lean_ctor_set(v___x_5149_, 1, v___x_5147_);
return v___x_5149_;
}
}
static lean_object* _init_lp_bounded_Bounded_catalog___closed__2(void){
_start:
{
lean_object* v___x_5150_; lean_object* v___x_5151_; lean_object* v___x_5152_; 
v___x_5150_ = lean_obj_once(&lp_bounded_Bounded_catalog___closed__1, &lp_bounded_Bounded_catalog___closed__1_once, _init_lp_bounded_Bounded_catalog___closed__1);
v___x_5151_ = lp_bounded_Bounded_cProv;
v___x_5152_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_5152_, 0, v___x_5151_);
lean_ctor_set(v___x_5152_, 1, v___x_5150_);
return v___x_5152_;
}
}
static lean_object* _init_lp_bounded_Bounded_catalog(void){
_start:
{
lean_object* v___x_5153_; 
v___x_5153_ = lean_obj_once(&lp_bounded_Bounded_catalog___closed__2, &lp_bounded_Bounded_catalog___closed__2_once, _init_lp_bounded_Bounded_catalog___closed__2);
return v___x_5153_;
}
}
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_catalogActs_spec__12(lean_object* v_a_5154_, lean_object* v_a_5155_){
_start:
{
if (lean_obj_tag(v_a_5154_) == 0)
{
lean_object* v___x_5156_; 
v___x_5156_ = l_List_reverse___redArg(v_a_5155_);
return v___x_5156_;
}
else
{
lean_object* v_head_5157_; lean_object* v_tail_5158_; lean_object* v___x_5160_; uint8_t v_isShared_5161_; uint8_t v_isSharedCheck_5167_; 
v_head_5157_ = lean_ctor_get(v_a_5154_, 0);
v_tail_5158_ = lean_ctor_get(v_a_5154_, 1);
v_isSharedCheck_5167_ = !lean_is_exclusive(v_a_5154_);
if (v_isSharedCheck_5167_ == 0)
{
v___x_5160_ = v_a_5154_;
v_isShared_5161_ = v_isSharedCheck_5167_;
goto v_resetjp_5159_;
}
else
{
lean_inc(v_tail_5158_);
lean_inc(v_head_5157_);
lean_dec(v_a_5154_);
v___x_5160_ = lean_box(0);
v_isShared_5161_ = v_isSharedCheck_5167_;
goto v_resetjp_5159_;
}
v_resetjp_5159_:
{
lean_object* v___x_5162_; lean_object* v___x_5164_; 
v___x_5162_ = lean_alloc_ctor(9, 1, 0);
lean_ctor_set(v___x_5162_, 0, v_head_5157_);
if (v_isShared_5161_ == 0)
{
lean_ctor_set(v___x_5160_, 1, v_a_5155_);
lean_ctor_set(v___x_5160_, 0, v___x_5162_);
v___x_5164_ = v___x_5160_;
goto v_reusejp_5163_;
}
else
{
lean_object* v_reuseFailAlloc_5166_; 
v_reuseFailAlloc_5166_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_5166_, 0, v___x_5162_);
lean_ctor_set(v_reuseFailAlloc_5166_, 1, v_a_5155_);
v___x_5164_ = v_reuseFailAlloc_5166_;
goto v_reusejp_5163_;
}
v_reusejp_5163_:
{
v_a_5154_ = v_tail_5158_;
v_a_5155_ = v___x_5164_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_catalogActs_spec__5(lean_object* v_a_5168_, lean_object* v_a_5169_){
_start:
{
if (lean_obj_tag(v_a_5168_) == 0)
{
lean_object* v___x_5170_; 
v___x_5170_ = l_List_reverse___redArg(v_a_5169_);
return v___x_5170_;
}
else
{
lean_object* v_head_5171_; lean_object* v_tail_5172_; lean_object* v___x_5174_; uint8_t v_isShared_5175_; uint8_t v_isSharedCheck_5181_; 
v_head_5171_ = lean_ctor_get(v_a_5168_, 0);
v_tail_5172_ = lean_ctor_get(v_a_5168_, 1);
v_isSharedCheck_5181_ = !lean_is_exclusive(v_a_5168_);
if (v_isSharedCheck_5181_ == 0)
{
v___x_5174_ = v_a_5168_;
v_isShared_5175_ = v_isSharedCheck_5181_;
goto v_resetjp_5173_;
}
else
{
lean_inc(v_tail_5172_);
lean_inc(v_head_5171_);
lean_dec(v_a_5168_);
v___x_5174_ = lean_box(0);
v_isShared_5175_ = v_isSharedCheck_5181_;
goto v_resetjp_5173_;
}
v_resetjp_5173_:
{
lean_object* v___x_5176_; lean_object* v___x_5178_; 
v___x_5176_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_5176_, 0, v_head_5171_);
if (v_isShared_5175_ == 0)
{
lean_ctor_set(v___x_5174_, 1, v_a_5169_);
lean_ctor_set(v___x_5174_, 0, v___x_5176_);
v___x_5178_ = v___x_5174_;
goto v_reusejp_5177_;
}
else
{
lean_object* v_reuseFailAlloc_5180_; 
v_reuseFailAlloc_5180_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_5180_, 0, v___x_5176_);
lean_ctor_set(v_reuseFailAlloc_5180_, 1, v_a_5169_);
v___x_5178_ = v_reuseFailAlloc_5180_;
goto v_reusejp_5177_;
}
v_reusejp_5177_:
{
v_a_5168_ = v_tail_5172_;
v_a_5169_ = v___x_5178_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_catalogActs_spec__1(lean_object* v_a_5182_, lean_object* v_a_5183_){
_start:
{
if (lean_obj_tag(v_a_5182_) == 0)
{
lean_object* v___x_5184_; 
v___x_5184_ = l_List_reverse___redArg(v_a_5183_);
return v___x_5184_;
}
else
{
lean_object* v_head_5185_; lean_object* v_tail_5186_; lean_object* v___x_5188_; uint8_t v_isShared_5189_; uint8_t v_isSharedCheck_5195_; 
v_head_5185_ = lean_ctor_get(v_a_5182_, 0);
v_tail_5186_ = lean_ctor_get(v_a_5182_, 1);
v_isSharedCheck_5195_ = !lean_is_exclusive(v_a_5182_);
if (v_isSharedCheck_5195_ == 0)
{
v___x_5188_ = v_a_5182_;
v_isShared_5189_ = v_isSharedCheck_5195_;
goto v_resetjp_5187_;
}
else
{
lean_inc(v_tail_5186_);
lean_inc(v_head_5185_);
lean_dec(v_a_5182_);
v___x_5188_ = lean_box(0);
v_isShared_5189_ = v_isSharedCheck_5195_;
goto v_resetjp_5187_;
}
v_resetjp_5187_:
{
lean_object* v___x_5190_; lean_object* v___x_5192_; 
v___x_5190_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_5190_, 0, v_head_5185_);
if (v_isShared_5189_ == 0)
{
lean_ctor_set(v___x_5188_, 1, v_a_5183_);
lean_ctor_set(v___x_5188_, 0, v___x_5190_);
v___x_5192_ = v___x_5188_;
goto v_reusejp_5191_;
}
else
{
lean_object* v_reuseFailAlloc_5194_; 
v_reuseFailAlloc_5194_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_5194_, 0, v___x_5190_);
lean_ctor_set(v_reuseFailAlloc_5194_, 1, v_a_5183_);
v___x_5192_ = v_reuseFailAlloc_5194_;
goto v_reusejp_5191_;
}
v_reusejp_5191_:
{
v_a_5182_ = v_tail_5186_;
v_a_5183_ = v___x_5192_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_catalogActs_spec__2(lean_object* v_n_5196_, lean_object* v_a_5197_, lean_object* v_a_5198_){
_start:
{
if (lean_obj_tag(v_a_5197_) == 0)
{
lean_object* v___x_5199_; 
lean_dec(v_n_5196_);
v___x_5199_ = l_List_reverse___redArg(v_a_5198_);
return v___x_5199_;
}
else
{
lean_object* v_head_5200_; lean_object* v_tail_5201_; lean_object* v___x_5203_; uint8_t v_isShared_5204_; uint8_t v_isSharedCheck_5210_; 
v_head_5200_ = lean_ctor_get(v_a_5197_, 0);
v_tail_5201_ = lean_ctor_get(v_a_5197_, 1);
v_isSharedCheck_5210_ = !lean_is_exclusive(v_a_5197_);
if (v_isSharedCheck_5210_ == 0)
{
v___x_5203_ = v_a_5197_;
v_isShared_5204_ = v_isSharedCheck_5210_;
goto v_resetjp_5202_;
}
else
{
lean_inc(v_tail_5201_);
lean_inc(v_head_5200_);
lean_dec(v_a_5197_);
v___x_5203_ = lean_box(0);
v_isShared_5204_ = v_isSharedCheck_5210_;
goto v_resetjp_5202_;
}
v_resetjp_5202_:
{
lean_object* v___x_5205_; lean_object* v___x_5207_; 
lean_inc(v_n_5196_);
v___x_5205_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_5205_, 0, v_n_5196_);
lean_ctor_set(v___x_5205_, 1, v_head_5200_);
if (v_isShared_5204_ == 0)
{
lean_ctor_set(v___x_5203_, 1, v_a_5198_);
lean_ctor_set(v___x_5203_, 0, v___x_5205_);
v___x_5207_ = v___x_5203_;
goto v_reusejp_5206_;
}
else
{
lean_object* v_reuseFailAlloc_5209_; 
v_reuseFailAlloc_5209_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_5209_, 0, v___x_5205_);
lean_ctor_set(v_reuseFailAlloc_5209_, 1, v_a_5198_);
v___x_5207_ = v_reuseFailAlloc_5209_;
goto v_reusejp_5206_;
}
v_reusejp_5206_:
{
v_a_5197_ = v_tail_5201_;
v_a_5198_ = v___x_5207_;
goto _start;
}
}
}
}
}
static lean_object* _init_lp_bounded___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Bounded_catalogActs_spec__7___closed__0(void){
_start:
{
lean_object* v___x_5211_; lean_object* v___x_5212_; lean_object* v___x_5213_; 
v___x_5211_ = lean_box(0);
v___x_5212_ = lp_bounded_Bounded_allSlots;
v___x_5213_ = lp_bounded_List_mapTR_loop___at___00Bounded_catalogActs_spec__1(v___x_5212_, v___x_5211_);
return v___x_5213_;
}
}
static lean_object* _init_lp_bounded___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Bounded_catalogActs_spec__7___closed__1(void){
_start:
{
lean_object* v___x_5214_; lean_object* v___x_5215_; lean_object* v___x_5216_; 
v___x_5214_ = lean_obj_once(&lp_bounded___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Bounded_catalogActs_spec__7___closed__0, &lp_bounded___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Bounded_catalogActs_spec__7___closed__0_once, _init_lp_bounded___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Bounded_catalogActs_spec__7___closed__0);
v___x_5215_ = lean_box(0);
v___x_5216_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_5216_, 0, v___x_5215_);
lean_ctor_set(v___x_5216_, 1, v___x_5214_);
return v___x_5216_;
}
}
LEAN_EXPORT lean_object* lp_bounded___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Bounded_catalogActs_spec__7(lean_object* v_a_5217_, lean_object* v_a_5218_){
_start:
{
if (lean_obj_tag(v_a_5217_) == 0)
{
lean_object* v___x_5219_; 
v___x_5219_ = lean_array_to_list(v_a_5218_);
return v___x_5219_;
}
else
{
lean_object* v_head_5220_; lean_object* v_tail_5221_; lean_object* v___x_5222_; lean_object* v___x_5223_; lean_object* v___x_5224_; lean_object* v___x_5225_; 
v_head_5220_ = lean_ctor_get(v_a_5217_, 0);
lean_inc(v_head_5220_);
v_tail_5221_ = lean_ctor_get(v_a_5217_, 1);
lean_inc(v_tail_5221_);
lean_dec_ref_known(v_a_5217_, 2);
v___x_5222_ = lean_box(0);
v___x_5223_ = lean_obj_once(&lp_bounded___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Bounded_catalogActs_spec__7___closed__1, &lp_bounded___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Bounded_catalogActs_spec__7___closed__1_once, _init_lp_bounded___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Bounded_catalogActs_spec__7___closed__1);
v___x_5224_ = lp_bounded_List_mapTR_loop___at___00Bounded_catalogActs_spec__2(v_head_5220_, v___x_5223_, v___x_5222_);
v___x_5225_ = l_List_foldl___at___00Array_appendList_spec__0___redArg(v_a_5218_, v___x_5224_);
v_a_5217_ = v_tail_5221_;
v_a_5218_ = v___x_5225_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_catalogActs_spec__4(lean_object* v_a_5227_, lean_object* v_a_5228_){
_start:
{
if (lean_obj_tag(v_a_5227_) == 0)
{
lean_object* v___x_5229_; 
v___x_5229_ = l_List_reverse___redArg(v_a_5228_);
return v___x_5229_;
}
else
{
lean_object* v_head_5230_; lean_object* v_tail_5231_; lean_object* v___x_5233_; uint8_t v_isShared_5234_; uint8_t v_isSharedCheck_5240_; 
v_head_5230_ = lean_ctor_get(v_a_5227_, 0);
v_tail_5231_ = lean_ctor_get(v_a_5227_, 1);
v_isSharedCheck_5240_ = !lean_is_exclusive(v_a_5227_);
if (v_isSharedCheck_5240_ == 0)
{
v___x_5233_ = v_a_5227_;
v_isShared_5234_ = v_isSharedCheck_5240_;
goto v_resetjp_5232_;
}
else
{
lean_inc(v_tail_5231_);
lean_inc(v_head_5230_);
lean_dec(v_a_5227_);
v___x_5233_ = lean_box(0);
v_isShared_5234_ = v_isSharedCheck_5240_;
goto v_resetjp_5232_;
}
v_resetjp_5232_:
{
lean_object* v___x_5235_; lean_object* v___x_5237_; 
v___x_5235_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_5235_, 0, v_head_5230_);
if (v_isShared_5234_ == 0)
{
lean_ctor_set(v___x_5233_, 1, v_a_5228_);
lean_ctor_set(v___x_5233_, 0, v___x_5235_);
v___x_5237_ = v___x_5233_;
goto v_reusejp_5236_;
}
else
{
lean_object* v_reuseFailAlloc_5239_; 
v_reuseFailAlloc_5239_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_5239_, 0, v___x_5235_);
lean_ctor_set(v_reuseFailAlloc_5239_, 1, v_a_5228_);
v___x_5237_ = v_reuseFailAlloc_5239_;
goto v_reusejp_5236_;
}
v_reusejp_5236_:
{
v_a_5227_ = v_tail_5231_;
v_a_5228_ = v___x_5237_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_catalogActs_spec__11(lean_object* v_a_5241_, lean_object* v_a_5242_){
_start:
{
if (lean_obj_tag(v_a_5241_) == 0)
{
lean_object* v___x_5243_; 
v___x_5243_ = l_List_reverse___redArg(v_a_5242_);
return v___x_5243_;
}
else
{
lean_object* v_head_5244_; lean_object* v_tail_5245_; lean_object* v___x_5247_; uint8_t v_isShared_5248_; uint8_t v_isSharedCheck_5254_; 
v_head_5244_ = lean_ctor_get(v_a_5241_, 0);
v_tail_5245_ = lean_ctor_get(v_a_5241_, 1);
v_isSharedCheck_5254_ = !lean_is_exclusive(v_a_5241_);
if (v_isSharedCheck_5254_ == 0)
{
v___x_5247_ = v_a_5241_;
v_isShared_5248_ = v_isSharedCheck_5254_;
goto v_resetjp_5246_;
}
else
{
lean_inc(v_tail_5245_);
lean_inc(v_head_5244_);
lean_dec(v_a_5241_);
v___x_5247_ = lean_box(0);
v_isShared_5248_ = v_isSharedCheck_5254_;
goto v_resetjp_5246_;
}
v_resetjp_5246_:
{
lean_object* v___x_5249_; lean_object* v___x_5251_; 
v___x_5249_ = lean_alloc_ctor(8, 1, 0);
lean_ctor_set(v___x_5249_, 0, v_head_5244_);
if (v_isShared_5248_ == 0)
{
lean_ctor_set(v___x_5247_, 1, v_a_5242_);
lean_ctor_set(v___x_5247_, 0, v___x_5249_);
v___x_5251_ = v___x_5247_;
goto v_reusejp_5250_;
}
else
{
lean_object* v_reuseFailAlloc_5253_; 
v_reuseFailAlloc_5253_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_5253_, 0, v___x_5249_);
lean_ctor_set(v_reuseFailAlloc_5253_, 1, v_a_5242_);
v___x_5251_ = v_reuseFailAlloc_5253_;
goto v_reusejp_5250_;
}
v_reusejp_5250_:
{
v_a_5241_ = v_tail_5245_;
v_a_5242_ = v___x_5251_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_catalogActs_spec__10(lean_object* v_a_5255_, lean_object* v_a_5256_){
_start:
{
if (lean_obj_tag(v_a_5255_) == 0)
{
lean_object* v___x_5257_; 
v___x_5257_ = l_List_reverse___redArg(v_a_5256_);
return v___x_5257_;
}
else
{
lean_object* v_head_5258_; lean_object* v_tail_5259_; lean_object* v___x_5261_; uint8_t v_isShared_5262_; uint8_t v_isSharedCheck_5268_; 
v_head_5258_ = lean_ctor_get(v_a_5255_, 0);
v_tail_5259_ = lean_ctor_get(v_a_5255_, 1);
v_isSharedCheck_5268_ = !lean_is_exclusive(v_a_5255_);
if (v_isSharedCheck_5268_ == 0)
{
v___x_5261_ = v_a_5255_;
v_isShared_5262_ = v_isSharedCheck_5268_;
goto v_resetjp_5260_;
}
else
{
lean_inc(v_tail_5259_);
lean_inc(v_head_5258_);
lean_dec(v_a_5255_);
v___x_5261_ = lean_box(0);
v_isShared_5262_ = v_isSharedCheck_5268_;
goto v_resetjp_5260_;
}
v_resetjp_5260_:
{
lean_object* v___x_5263_; lean_object* v___x_5265_; 
v___x_5263_ = lean_alloc_ctor(7, 1, 0);
lean_ctor_set(v___x_5263_, 0, v_head_5258_);
if (v_isShared_5262_ == 0)
{
lean_ctor_set(v___x_5261_, 1, v_a_5256_);
lean_ctor_set(v___x_5261_, 0, v___x_5263_);
v___x_5265_ = v___x_5261_;
goto v_reusejp_5264_;
}
else
{
lean_object* v_reuseFailAlloc_5267_; 
v_reuseFailAlloc_5267_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_5267_, 0, v___x_5263_);
lean_ctor_set(v_reuseFailAlloc_5267_, 1, v_a_5256_);
v___x_5265_ = v_reuseFailAlloc_5267_;
goto v_reusejp_5264_;
}
v_reusejp_5264_:
{
v_a_5255_ = v_tail_5259_;
v_a_5256_ = v___x_5265_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_catalogActs_spec__9(lean_object* v_a_5269_, lean_object* v_a_5270_){
_start:
{
if (lean_obj_tag(v_a_5269_) == 0)
{
lean_object* v___x_5271_; 
v___x_5271_ = l_List_reverse___redArg(v_a_5270_);
return v___x_5271_;
}
else
{
lean_object* v_head_5272_; lean_object* v_tail_5273_; lean_object* v___x_5275_; uint8_t v_isShared_5276_; uint8_t v_isSharedCheck_5282_; 
v_head_5272_ = lean_ctor_get(v_a_5269_, 0);
v_tail_5273_ = lean_ctor_get(v_a_5269_, 1);
v_isSharedCheck_5282_ = !lean_is_exclusive(v_a_5269_);
if (v_isSharedCheck_5282_ == 0)
{
v___x_5275_ = v_a_5269_;
v_isShared_5276_ = v_isSharedCheck_5282_;
goto v_resetjp_5274_;
}
else
{
lean_inc(v_tail_5273_);
lean_inc(v_head_5272_);
lean_dec(v_a_5269_);
v___x_5275_ = lean_box(0);
v_isShared_5276_ = v_isSharedCheck_5282_;
goto v_resetjp_5274_;
}
v_resetjp_5274_:
{
lean_object* v___x_5277_; lean_object* v___x_5279_; 
v___x_5277_ = lean_alloc_ctor(6, 1, 0);
lean_ctor_set(v___x_5277_, 0, v_head_5272_);
if (v_isShared_5276_ == 0)
{
lean_ctor_set(v___x_5275_, 1, v_a_5270_);
lean_ctor_set(v___x_5275_, 0, v___x_5277_);
v___x_5279_ = v___x_5275_;
goto v_reusejp_5278_;
}
else
{
lean_object* v_reuseFailAlloc_5281_; 
v_reuseFailAlloc_5281_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_5281_, 0, v___x_5277_);
lean_ctor_set(v_reuseFailAlloc_5281_, 1, v_a_5270_);
v___x_5279_ = v_reuseFailAlloc_5281_;
goto v_reusejp_5278_;
}
v_reusejp_5278_:
{
v_a_5269_ = v_tail_5273_;
v_a_5270_ = v___x_5279_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_catalogActs_spec__8(lean_object* v_a_5283_, lean_object* v_a_5284_){
_start:
{
if (lean_obj_tag(v_a_5283_) == 0)
{
lean_object* v___x_5285_; 
v___x_5285_ = l_List_reverse___redArg(v_a_5284_);
return v___x_5285_;
}
else
{
lean_object* v_head_5286_; lean_object* v_tail_5287_; lean_object* v___x_5289_; uint8_t v_isShared_5290_; uint8_t v_isSharedCheck_5296_; 
v_head_5286_ = lean_ctor_get(v_a_5283_, 0);
v_tail_5287_ = lean_ctor_get(v_a_5283_, 1);
v_isSharedCheck_5296_ = !lean_is_exclusive(v_a_5283_);
if (v_isSharedCheck_5296_ == 0)
{
v___x_5289_ = v_a_5283_;
v_isShared_5290_ = v_isSharedCheck_5296_;
goto v_resetjp_5288_;
}
else
{
lean_inc(v_tail_5287_);
lean_inc(v_head_5286_);
lean_dec(v_a_5283_);
v___x_5289_ = lean_box(0);
v_isShared_5290_ = v_isSharedCheck_5296_;
goto v_resetjp_5288_;
}
v_resetjp_5288_:
{
lean_object* v___x_5291_; lean_object* v___x_5293_; 
v___x_5291_ = lean_alloc_ctor(5, 1, 0);
lean_ctor_set(v___x_5291_, 0, v_head_5286_);
if (v_isShared_5290_ == 0)
{
lean_ctor_set(v___x_5289_, 1, v_a_5284_);
lean_ctor_set(v___x_5289_, 0, v___x_5291_);
v___x_5293_ = v___x_5289_;
goto v_reusejp_5292_;
}
else
{
lean_object* v_reuseFailAlloc_5295_; 
v_reuseFailAlloc_5295_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_5295_, 0, v___x_5291_);
lean_ctor_set(v_reuseFailAlloc_5295_, 1, v_a_5284_);
v___x_5293_ = v_reuseFailAlloc_5295_;
goto v_reusejp_5292_;
}
v_reusejp_5292_:
{
v_a_5283_ = v_tail_5287_;
v_a_5284_ = v___x_5293_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_catalogActs_spec__6(lean_object* v_a_5297_, lean_object* v_a_5298_){
_start:
{
if (lean_obj_tag(v_a_5297_) == 0)
{
lean_object* v___x_5299_; 
v___x_5299_ = l_List_reverse___redArg(v_a_5298_);
return v___x_5299_;
}
else
{
lean_object* v_head_5300_; lean_object* v_tail_5301_; lean_object* v___x_5303_; uint8_t v_isShared_5304_; uint8_t v_isSharedCheck_5310_; 
v_head_5300_ = lean_ctor_get(v_a_5297_, 0);
v_tail_5301_ = lean_ctor_get(v_a_5297_, 1);
v_isSharedCheck_5310_ = !lean_is_exclusive(v_a_5297_);
if (v_isSharedCheck_5310_ == 0)
{
v___x_5303_ = v_a_5297_;
v_isShared_5304_ = v_isSharedCheck_5310_;
goto v_resetjp_5302_;
}
else
{
lean_inc(v_tail_5301_);
lean_inc(v_head_5300_);
lean_dec(v_a_5297_);
v___x_5303_ = lean_box(0);
v_isShared_5304_ = v_isSharedCheck_5310_;
goto v_resetjp_5302_;
}
v_resetjp_5302_:
{
lean_object* v___x_5305_; lean_object* v___x_5307_; 
v___x_5305_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_5305_, 0, v_head_5300_);
if (v_isShared_5304_ == 0)
{
lean_ctor_set(v___x_5303_, 1, v_a_5298_);
lean_ctor_set(v___x_5303_, 0, v___x_5305_);
v___x_5307_ = v___x_5303_;
goto v_reusejp_5306_;
}
else
{
lean_object* v_reuseFailAlloc_5309_; 
v_reuseFailAlloc_5309_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_5309_, 0, v___x_5305_);
lean_ctor_set(v_reuseFailAlloc_5309_, 1, v_a_5298_);
v___x_5307_ = v_reuseFailAlloc_5309_;
goto v_reusejp_5306_;
}
v_reusejp_5306_:
{
v_a_5297_ = v_tail_5301_;
v_a_5298_ = v___x_5307_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded_List_mapTR_loop___at___00Bounded_catalogActs_spec__0(lean_object* v_n_5311_, lean_object* v_a_5312_, lean_object* v_a_5313_){
_start:
{
if (lean_obj_tag(v_a_5312_) == 0)
{
lean_object* v___x_5314_; 
lean_dec(v_n_5311_);
v___x_5314_ = l_List_reverse___redArg(v_a_5313_);
return v___x_5314_;
}
else
{
lean_object* v_head_5315_; lean_object* v_tail_5316_; lean_object* v___x_5318_; uint8_t v_isShared_5319_; uint8_t v_isSharedCheck_5325_; 
v_head_5315_ = lean_ctor_get(v_a_5312_, 0);
v_tail_5316_ = lean_ctor_get(v_a_5312_, 1);
v_isSharedCheck_5325_ = !lean_is_exclusive(v_a_5312_);
if (v_isSharedCheck_5325_ == 0)
{
v___x_5318_ = v_a_5312_;
v_isShared_5319_ = v_isSharedCheck_5325_;
goto v_resetjp_5317_;
}
else
{
lean_inc(v_tail_5316_);
lean_inc(v_head_5315_);
lean_dec(v_a_5312_);
v___x_5318_ = lean_box(0);
v_isShared_5319_ = v_isSharedCheck_5325_;
goto v_resetjp_5317_;
}
v_resetjp_5317_:
{
lean_object* v___x_5320_; lean_object* v___x_5322_; 
lean_inc(v_n_5311_);
v___x_5320_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_5320_, 0, v_n_5311_);
lean_ctor_set(v___x_5320_, 1, v_head_5315_);
if (v_isShared_5319_ == 0)
{
lean_ctor_set(v___x_5318_, 1, v_a_5313_);
lean_ctor_set(v___x_5318_, 0, v___x_5320_);
v___x_5322_ = v___x_5318_;
goto v_reusejp_5321_;
}
else
{
lean_object* v_reuseFailAlloc_5324_; 
v_reuseFailAlloc_5324_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_5324_, 0, v___x_5320_);
lean_ctor_set(v_reuseFailAlloc_5324_, 1, v_a_5313_);
v___x_5322_ = v_reuseFailAlloc_5324_;
goto v_reusejp_5321_;
}
v_reusejp_5321_:
{
v_a_5312_ = v_tail_5316_;
v_a_5313_ = v___x_5322_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_bounded___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Bounded_catalogActs_spec__3(lean_object* v_a_5326_, lean_object* v_a_5327_){
_start:
{
if (lean_obj_tag(v_a_5326_) == 0)
{
lean_object* v___x_5328_; 
v___x_5328_ = lean_array_to_list(v_a_5327_);
return v___x_5328_;
}
else
{
lean_object* v_head_5329_; lean_object* v_tail_5330_; lean_object* v___x_5331_; lean_object* v___x_5332_; lean_object* v___x_5333_; lean_object* v___x_5334_; 
v_head_5329_ = lean_ctor_get(v_a_5326_, 0);
lean_inc(v_head_5329_);
v_tail_5330_ = lean_ctor_get(v_a_5326_, 1);
lean_inc(v_tail_5330_);
lean_dec_ref_known(v_a_5326_, 2);
v___x_5331_ = lp_bounded_Bounded_catalog;
v___x_5332_ = lean_box(0);
v___x_5333_ = lp_bounded_List_mapTR_loop___at___00Bounded_catalogActs_spec__0(v_head_5329_, v___x_5331_, v___x_5332_);
v___x_5334_ = l_List_foldl___at___00Array_appendList_spec__0___redArg(v_a_5327_, v___x_5333_);
v_a_5326_ = v_tail_5330_;
v_a_5327_ = v___x_5334_;
goto _start;
}
}
}
static lean_object* _init_lp_bounded_Bounded_catalogActs___closed__1(void){
_start:
{
lean_object* v___x_5338_; lean_object* v___x_5339_; lean_object* v___x_5340_; 
v___x_5338_ = ((lean_object*)(lp_bounded_Bounded_catalogActs___closed__0));
v___x_5339_ = lp_bounded_Bounded_allSlots;
v___x_5340_ = lp_bounded___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Bounded_catalogActs_spec__3(v___x_5339_, v___x_5338_);
return v___x_5340_;
}
}
static lean_object* _init_lp_bounded_Bounded_catalogActs___closed__2(void){
_start:
{
lean_object* v___x_5341_; lean_object* v___x_5342_; lean_object* v___x_5343_; 
v___x_5341_ = lean_box(0);
v___x_5342_ = lp_bounded_Bounded_allSlots;
v___x_5343_ = lp_bounded_List_mapTR_loop___at___00Bounded_catalogActs_spec__4(v___x_5342_, v___x_5341_);
return v___x_5343_;
}
}
static lean_object* _init_lp_bounded_Bounded_catalogActs___closed__3(void){
_start:
{
lean_object* v___x_5344_; lean_object* v___x_5345_; lean_object* v___x_5346_; 
v___x_5344_ = lean_obj_once(&lp_bounded_Bounded_catalogActs___closed__2, &lp_bounded_Bounded_catalogActs___closed__2_once, _init_lp_bounded_Bounded_catalogActs___closed__2);
v___x_5345_ = lean_obj_once(&lp_bounded_Bounded_catalogActs___closed__1, &lp_bounded_Bounded_catalogActs___closed__1_once, _init_lp_bounded_Bounded_catalogActs___closed__1);
v___x_5346_ = l_List_appendTR___redArg(v___x_5345_, v___x_5344_);
return v___x_5346_;
}
}
static lean_object* _init_lp_bounded_Bounded_catalogActs___closed__4(void){
_start:
{
lean_object* v___x_5347_; lean_object* v___x_5348_; lean_object* v___x_5349_; 
v___x_5347_ = lean_box(0);
v___x_5348_ = lp_bounded_Bounded_allSlots;
v___x_5349_ = lp_bounded_List_mapTR_loop___at___00Bounded_catalogActs_spec__5(v___x_5348_, v___x_5347_);
return v___x_5349_;
}
}
static lean_object* _init_lp_bounded_Bounded_catalogActs___closed__5(void){
_start:
{
lean_object* v___x_5350_; lean_object* v___x_5351_; lean_object* v___x_5352_; 
v___x_5350_ = lean_obj_once(&lp_bounded_Bounded_catalogActs___closed__4, &lp_bounded_Bounded_catalogActs___closed__4_once, _init_lp_bounded_Bounded_catalogActs___closed__4);
v___x_5351_ = lean_obj_once(&lp_bounded_Bounded_catalogActs___closed__3, &lp_bounded_Bounded_catalogActs___closed__3_once, _init_lp_bounded_Bounded_catalogActs___closed__3);
v___x_5352_ = l_List_appendTR___redArg(v___x_5351_, v___x_5350_);
return v___x_5352_;
}
}
static lean_object* _init_lp_bounded_Bounded_catalogActs___closed__6(void){
_start:
{
lean_object* v___x_5353_; lean_object* v___x_5354_; lean_object* v___x_5355_; 
v___x_5353_ = lean_box(0);
v___x_5354_ = lp_bounded_Bounded_allSlots;
v___x_5355_ = lp_bounded_List_mapTR_loop___at___00Bounded_catalogActs_spec__6(v___x_5354_, v___x_5353_);
return v___x_5355_;
}
}
static lean_object* _init_lp_bounded_Bounded_catalogActs___closed__7(void){
_start:
{
lean_object* v___x_5356_; lean_object* v___x_5357_; lean_object* v___x_5358_; 
v___x_5356_ = lean_obj_once(&lp_bounded_Bounded_catalogActs___closed__6, &lp_bounded_Bounded_catalogActs___closed__6_once, _init_lp_bounded_Bounded_catalogActs___closed__6);
v___x_5357_ = lean_obj_once(&lp_bounded_Bounded_catalogActs___closed__5, &lp_bounded_Bounded_catalogActs___closed__5_once, _init_lp_bounded_Bounded_catalogActs___closed__5);
v___x_5358_ = l_List_appendTR___redArg(v___x_5357_, v___x_5356_);
return v___x_5358_;
}
}
static lean_object* _init_lp_bounded_Bounded_catalogActs___closed__8(void){
_start:
{
lean_object* v___x_5359_; lean_object* v___x_5360_; lean_object* v___x_5361_; 
v___x_5359_ = ((lean_object*)(lp_bounded_Bounded_catalogActs___closed__0));
v___x_5360_ = lp_bounded_Bounded_allSlots;
v___x_5361_ = lp_bounded___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00Bounded_catalogActs_spec__7(v___x_5360_, v___x_5359_);
return v___x_5361_;
}
}
static lean_object* _init_lp_bounded_Bounded_catalogActs___closed__9(void){
_start:
{
lean_object* v___x_5362_; lean_object* v___x_5363_; lean_object* v___x_5364_; 
v___x_5362_ = lean_obj_once(&lp_bounded_Bounded_catalogActs___closed__8, &lp_bounded_Bounded_catalogActs___closed__8_once, _init_lp_bounded_Bounded_catalogActs___closed__8);
v___x_5363_ = lean_obj_once(&lp_bounded_Bounded_catalogActs___closed__7, &lp_bounded_Bounded_catalogActs___closed__7_once, _init_lp_bounded_Bounded_catalogActs___closed__7);
v___x_5364_ = l_List_appendTR___redArg(v___x_5363_, v___x_5362_);
return v___x_5364_;
}
}
static lean_object* _init_lp_bounded_Bounded_catalogActs___closed__10(void){
_start:
{
lean_object* v___x_5365_; lean_object* v___x_5366_; lean_object* v___x_5367_; 
v___x_5365_ = lean_box(0);
v___x_5366_ = lp_bounded_Bounded_allSlots;
v___x_5367_ = lp_bounded_List_mapTR_loop___at___00Bounded_catalogActs_spec__8(v___x_5366_, v___x_5365_);
return v___x_5367_;
}
}
static lean_object* _init_lp_bounded_Bounded_catalogActs___closed__11(void){
_start:
{
lean_object* v___x_5368_; lean_object* v___x_5369_; lean_object* v___x_5370_; 
v___x_5368_ = lean_obj_once(&lp_bounded_Bounded_catalogActs___closed__10, &lp_bounded_Bounded_catalogActs___closed__10_once, _init_lp_bounded_Bounded_catalogActs___closed__10);
v___x_5369_ = lean_obj_once(&lp_bounded_Bounded_catalogActs___closed__9, &lp_bounded_Bounded_catalogActs___closed__9_once, _init_lp_bounded_Bounded_catalogActs___closed__9);
v___x_5370_ = l_List_appendTR___redArg(v___x_5369_, v___x_5368_);
return v___x_5370_;
}
}
static lean_object* _init_lp_bounded_Bounded_catalogActs___closed__12(void){
_start:
{
lean_object* v___x_5371_; lean_object* v___x_5372_; lean_object* v___x_5373_; 
v___x_5371_ = lean_box(0);
v___x_5372_ = lp_bounded_Bounded_allSlots;
v___x_5373_ = lp_bounded_List_mapTR_loop___at___00Bounded_catalogActs_spec__9(v___x_5372_, v___x_5371_);
return v___x_5373_;
}
}
static lean_object* _init_lp_bounded_Bounded_catalogActs___closed__13(void){
_start:
{
lean_object* v___x_5374_; lean_object* v___x_5375_; lean_object* v___x_5376_; 
v___x_5374_ = lean_obj_once(&lp_bounded_Bounded_catalogActs___closed__12, &lp_bounded_Bounded_catalogActs___closed__12_once, _init_lp_bounded_Bounded_catalogActs___closed__12);
v___x_5375_ = lean_obj_once(&lp_bounded_Bounded_catalogActs___closed__11, &lp_bounded_Bounded_catalogActs___closed__11_once, _init_lp_bounded_Bounded_catalogActs___closed__11);
v___x_5376_ = l_List_appendTR___redArg(v___x_5375_, v___x_5374_);
return v___x_5376_;
}
}
static lean_object* _init_lp_bounded_Bounded_catalogActs___closed__14(void){
_start:
{
lean_object* v___x_5377_; lean_object* v___x_5378_; lean_object* v___x_5379_; 
v___x_5377_ = lean_box(0);
v___x_5378_ = lp_bounded_Bounded_allSlots;
v___x_5379_ = lp_bounded_List_mapTR_loop___at___00Bounded_catalogActs_spec__10(v___x_5378_, v___x_5377_);
return v___x_5379_;
}
}
static lean_object* _init_lp_bounded_Bounded_catalogActs___closed__15(void){
_start:
{
lean_object* v___x_5380_; lean_object* v___x_5381_; lean_object* v___x_5382_; 
v___x_5380_ = lean_obj_once(&lp_bounded_Bounded_catalogActs___closed__14, &lp_bounded_Bounded_catalogActs___closed__14_once, _init_lp_bounded_Bounded_catalogActs___closed__14);
v___x_5381_ = lean_obj_once(&lp_bounded_Bounded_catalogActs___closed__13, &lp_bounded_Bounded_catalogActs___closed__13_once, _init_lp_bounded_Bounded_catalogActs___closed__13);
v___x_5382_ = l_List_appendTR___redArg(v___x_5381_, v___x_5380_);
return v___x_5382_;
}
}
static lean_object* _init_lp_bounded_Bounded_catalogActs___closed__16(void){
_start:
{
lean_object* v___x_5383_; lean_object* v___x_5384_; lean_object* v___x_5385_; 
v___x_5383_ = lean_box(0);
v___x_5384_ = lp_bounded_Bounded_allSlots;
v___x_5385_ = lp_bounded_List_mapTR_loop___at___00Bounded_catalogActs_spec__11(v___x_5384_, v___x_5383_);
return v___x_5385_;
}
}
static lean_object* _init_lp_bounded_Bounded_catalogActs___closed__17(void){
_start:
{
lean_object* v___x_5386_; lean_object* v___x_5387_; lean_object* v___x_5388_; 
v___x_5386_ = lean_obj_once(&lp_bounded_Bounded_catalogActs___closed__16, &lp_bounded_Bounded_catalogActs___closed__16_once, _init_lp_bounded_Bounded_catalogActs___closed__16);
v___x_5387_ = lean_obj_once(&lp_bounded_Bounded_catalogActs___closed__15, &lp_bounded_Bounded_catalogActs___closed__15_once, _init_lp_bounded_Bounded_catalogActs___closed__15);
v___x_5388_ = l_List_appendTR___redArg(v___x_5387_, v___x_5386_);
return v___x_5388_;
}
}
static lean_object* _init_lp_bounded_Bounded_catalogActs___closed__18(void){
_start:
{
lean_object* v___x_5389_; lean_object* v___x_5390_; lean_object* v___x_5391_; 
v___x_5389_ = lean_box(0);
v___x_5390_ = lp_bounded_Bounded_allSlots;
v___x_5391_ = lp_bounded_List_mapTR_loop___at___00Bounded_catalogActs_spec__12(v___x_5390_, v___x_5389_);
return v___x_5391_;
}
}
static lean_object* _init_lp_bounded_Bounded_catalogActs___closed__19(void){
_start:
{
lean_object* v___x_5392_; lean_object* v___x_5393_; lean_object* v___x_5394_; 
v___x_5392_ = lean_obj_once(&lp_bounded_Bounded_catalogActs___closed__18, &lp_bounded_Bounded_catalogActs___closed__18_once, _init_lp_bounded_Bounded_catalogActs___closed__18);
v___x_5393_ = lean_obj_once(&lp_bounded_Bounded_catalogActs___closed__17, &lp_bounded_Bounded_catalogActs___closed__17_once, _init_lp_bounded_Bounded_catalogActs___closed__17);
v___x_5394_ = l_List_appendTR___redArg(v___x_5393_, v___x_5392_);
return v___x_5394_;
}
}
static lean_object* _init_lp_bounded_Bounded_catalogActs(void){
_start:
{
lean_object* v___x_5395_; 
v___x_5395_ = lean_obj_once(&lp_bounded_Bounded_catalogActs___closed__19, &lp_bounded_Bounded_catalogActs___closed__19_once, _init_lp_bounded_Bounded_catalogActs___closed__19);
return v___x_5395_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_bounded_Bounded_Calc(uint8_t builtin);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_bounded_Bounded_SigDec(uint8_t builtin) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_bounded_Bounded_Calc(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
lp_bounded_Bounded_instFinEnumDec = _init_lp_bounded_Bounded_instFinEnumDec();
lean_mark_persistent(lp_bounded_Bounded_instFinEnumDec);
lp_bounded_Bounded_allDecs = _init_lp_bounded_Bounded_allDecs();
lean_mark_persistent(lp_bounded_Bounded_allDecs);
lp_bounded_Bounded_childComp = _init_lp_bounded_Bounded_childComp();
lean_mark_persistent(lp_bounded_Bounded_childComp);
lp_bounded_Bounded_cProv = _init_lp_bounded_Bounded_cProv();
lean_mark_persistent(lp_bounded_Bounded_cProv);
lp_bounded_Bounded_cCons = _init_lp_bounded_Bounded_cCons();
lean_mark_persistent(lp_bounded_Bounded_cCons);
lp_bounded_Bounded_catalog = _init_lp_bounded_Bounded_catalog();
lean_mark_persistent(lp_bounded_Bounded_catalog);
lp_bounded_Bounded_catalogActs = _init_lp_bounded_Bounded_catalogActs();
lean_mark_persistent(lp_bounded_Bounded_catalogActs);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
