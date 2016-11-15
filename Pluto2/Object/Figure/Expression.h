#ifndef INCLUDED_OBJECT_FIGURE_EXPRESSION_H
#define INCLUDED_OBJECT_FIGURE_EXPRESSION_H

template <class L, class Op, class R>
class Expression {
    const L& l_;
    const R& r_;
public:
    Expression(const L& l, const R& r)
        : l_(l), r_(r) {}

    float operator[](std::size_t i) const
    {
        return Op::Apply(l_[i], r_[i]);
    }
};

#endif //#ifndef INCLUDED_OBJECT_FIGURE_EXPRESSION_H