#ifndef INCLUDED_OTHER_REPEAR_ALPHA_HPP
#define INCLUDED_OTHER_REPEAR_ALPHA_HPP
#
# include <boost/preprocessor/cat.hpp>
# include <boost/preprocessor/config/config.hpp>
# include <boost/preprocessor/debug/error.hpp>
# include <boost/preprocessor/detail/auto_rec.hpp>
# include <boost/preprocessor/tuple/eat.hpp>
#
# if 0
#    define BOOST_PP_REPEAT_ALPHA(count, macro, data)
# endif
#
# define BOOST_PP_REPEAT_ALPHA(c, m, d) BOOST_PP_REPEAT_ALPHA_I(c, m, d)
#
# define BOOST_PP_REPEAT_ALPHA_I(c, m, d) BOOST_PP_REPEAT_ALPHA_ ## c(m, d)
#
# define BOOST_PP_REPEAT_ALPHA_A(m, d) m(2, A, d)
# define BOOST_PP_REPEAT_ALPHA_B(m, d) BOOST_PP_REPEAT_ALPHA_A(m, d) m(2, B, d)
# define BOOST_PP_REPEAT_ALPHA_C(m, d) BOOST_PP_REPEAT_ALPHA_B(m, d) m(2, C, d)
# define BOOST_PP_REPEAT_ALPHA_D(m, d) BOOST_PP_REPEAT_ALPHA_C(m, d) m(2, D, d)
# define BOOST_PP_REPEAT_ALPHA_E(m, d) BOOST_PP_REPEAT_ALPHA_D(m, d) m(2, E, d)
# define BOOST_PP_REPEAT_ALPHA_F(m, d) BOOST_PP_REPEAT_ALPHA_E(m, d) m(2, F, d)
# define BOOST_PP_REPEAT_ALPHA_G(m, d) BOOST_PP_REPEAT_ALPHA_F(m, d) m(2, G, d)
# define BOOST_PP_REPEAT_ALPHA_H(m, d) BOOST_PP_REPEAT_ALPHA_G(m, d) m(2, H, d)
# define BOOST_PP_REPEAT_ALPHA_I(m, d) BOOST_PP_REPEAT_ALPHA_H(m, d) m(2, I, d)
# define BOOST_PP_REPEAT_ALPHA_J(m, d) BOOST_PP_REPEAT_ALPHA_I(m, d) m(2, J, d)
# define BOOST_PP_REPEAT_ALPHA_K(m, d) BOOST_PP_REPEAT_ALPHA_J(m, d) m(2, K, d)
# define BOOST_PP_REPEAT_ALPHA_L(m, d) BOOST_PP_REPEAT_ALPHA_K(m, d) m(2, L, d)
# define BOOST_PP_REPEAT_ALPHA_M(m, d) BOOST_PP_REPEAT_ALPHA_L(m, d) m(2, M, d)
# define BOOST_PP_REPEAT_ALPHA_N(m, d) BOOST_PP_REPEAT_ALPHA_M(m, d) m(2, N, d)
# define BOOST_PP_REPEAT_ALPHA_O(m, d) BOOST_PP_REPEAT_ALPHA_N(m, d) m(2, O, d)
# define BOOST_PP_REPEAT_ALPHA_P(m, d) BOOST_PP_REPEAT_ALPHA_O(m, d) m(2, P, d)
# define BOOST_PP_REPEAT_ALPHA_Q(m, d) BOOST_PP_REPEAT_ALPHA_P(m, d) m(2, Q, d)
# define BOOST_PP_REPEAT_ALPHA_R(m, d) BOOST_PP_REPEAT_ALPHA_Q(m, d) m(2, R, d)
# define BOOST_PP_REPEAT_ALPHA_S(m, d) BOOST_PP_REPEAT_ALPHA_R(m, d) m(2, S, d)
# define BOOST_PP_REPEAT_ALPHA_T(m, d) BOOST_PP_REPEAT_ALPHA_S(m, d) m(2, T, d)
# define BOOST_PP_REPEAT_ALPHA_U(m, d) BOOST_PP_REPEAT_ALPHA_T(m, d) m(2, U, d)
# define BOOST_PP_REPEAT_ALPHA_V(m, d) BOOST_PP_REPEAT_ALPHA_U(m, d) m(2, V, d)
# define BOOST_PP_REPEAT_ALPHA_W(m, d) BOOST_PP_REPEAT_ALPHA_V(m, d) m(2, W, d)
# define BOOST_PP_REPEAT_ALPHA_X(m, d) BOOST_PP_REPEAT_ALPHA_W(m, d) m(2, X, d)
# define BOOST_PP_REPEAT_ALPHA_Y(m, d) BOOST_PP_REPEAT_ALPHA_X(m, d) m(2, Y, d)
# define BOOST_PP_REPEAT_ALPHA_Z(m, d) BOOST_PP_REPEAT_ALPHA_Y(m, d) m(2, Z, d)
#
#endif //#ifndef INCLUDED_OTHER_REPEAR_ALPHA_HPP