// Lean compiler output
// Module: Bounded
// Imports: public import Init public meta import Init public import Bounded.Basic public import Bounded.Perm public import Bounded.Calc public import Bounded.SigDec public import Bounded.Enum public import Bounded.Explore public import Bounded.Equiv public import Bounded.Charact public import Bounded.Cutoff
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
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_bounded_Bounded_Basic(uint8_t builtin);
lean_object* initialize_bounded_Bounded_Perm(uint8_t builtin);
lean_object* initialize_bounded_Bounded_Calc(uint8_t builtin);
lean_object* initialize_bounded_Bounded_SigDec(uint8_t builtin);
lean_object* initialize_bounded_Bounded_Enum(uint8_t builtin);
lean_object* initialize_bounded_Bounded_Explore(uint8_t builtin);
lean_object* initialize_bounded_Bounded_Equiv(uint8_t builtin);
lean_object* initialize_bounded_Bounded_Charact(uint8_t builtin);
lean_object* initialize_bounded_Bounded_Cutoff(uint8_t builtin);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_bounded_Bounded(uint8_t builtin) {
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
res = initialize_bounded_Bounded_Perm(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_bounded_Bounded_Calc(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_bounded_Bounded_SigDec(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_bounded_Bounded_Enum(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_bounded_Bounded_Explore(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_bounded_Bounded_Equiv(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_bounded_Bounded_Charact(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_bounded_Bounded_Cutoff(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
