#include "Monom.h"

Monom::Monom()
{
    step = 0;
    coef = 0.0;
    next = 0;
}

Monom::Monom(double a, int b)
{
    if (a == 0)
        throw "invalid coefficient";
    coef = a;
    if (b < 0 || b > 999)
        throw "invalid stepen";
    step = b;
    next = 0;
}

Monom::Monom(const Monom& m)
{
    coef = m.coef;
    step = m.step;
    next = 0;
}

void Monom::Plus(Monom* m)
{
    //step = step + m->step;
    coef = coef + m->coef;
}

Monom Monom::Mult(Monom& m)
{
    int k1, k2;

    k1 = this->step % 10;
    k2 = m.step % 10;
    if (k1 + k2 > 9)
        throw "incorrect power";

    k1 = this->step % 100 / 10;
    k2 = m.step % 100 / 10;
    if (k1 + k2 > 9)
        throw "incorrect power";

    k1 = this->step / 100;
    k2 = m.step / 100;
    if (k1 + k2 > 9)
        throw "incorrect power";

    Monom result;
    result.coef = this->coef * m.coef;
    result.step= this->step + m.step;
    return result;
}

Monom Monom::operator*(const Monom& m)
{
    double r = m.coef * coef;
    int res = m.step + step;
    if (res <= 9)
        return Monom(r, res);
    else
    {
        cout << "step beyond the limit of the allowed value" << endl;
        return Monom(r, 0);
    }
}



istream& operator>>(istream& in, Monom& m)
{
    in >> m.coef >> m.step;
    return in;
}

#include <sstream>
string Monom::toString()
{
    std::ostringstream ss;

    ss << coef;
    if (step / 100 != 0)
        ss << "x^" << step / 100;

    if (step % 100 / 10 != 0)
        ss << "y^" << step % 100 / 10;

    if (step % 10 != 0)
        ss << "z^" << step % 10;

    return ss.str();
}

ostream& operator<<(ostream& out, const Monom& m)
{
	out << m.coef;
	if (m.step / 100 != 0)
		out << "x^" << m.step / 100;

	if (m.step % 100 / 10 != 0)
		out << "y^" << m.step % 100 / 10;

	if (m.step % 10 != 0)
		out << "z^" << m.step % 10;

	return out;
}

