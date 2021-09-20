#pragma once
using namespace std;

class rectangleType {
    public:
        double getLength() const;
        double getWidth() const;
        double area() const;
        double perimeter() const;
        void setDimension(double l, double w);

        friend ostream& operator<<(ostream&, const rectangleType&);
        friend istream& operator>>(istream&, rectangleType&);

        rectangleType operator + (const rectangleType&) const;
        rectangleType operator - (const rectangleType&) const;
        rectangleType operator * (const rectangleType&) const;
        rectangleType operator ++ ();   
        rectangleType operator ++ (int);
        rectangleType operator -- ();   
        rectangleType operator -- (int);
        bool operator == (const rectangleType&) const;
        bool operator != (const rectangleType&) const;
        bool operator <= (const rectangleType&) const;
        bool operator < (const rectangleType&) const;
        bool operator >= (const rectangleType&) const;
        bool operator > (const rectangleType&) const;

        rectangleType();
        rectangleType(double l, double w);

    private:
        double length;
        double width;
};

double rectangleType::getLength() const {
    return length;
}
double rectangleType::getWidth() const {
    return width;
}
double rectangleType::area() const  { 
    return length * width;  
} 
double rectangleType::perimeter() const {
    return 2 * (length + width);
}
void rectangleType::setDimension(double l, double w) {
    if (l >= 0)
        length = l;
    else
        length = 0;

    if ( w>= 0)
        width = w;
    else
        width = 0;
}

rectangleType::rectangleType() {
    length = 0;
    width = 0;
}
rectangleType::rectangleType(double l, double w) {
    setDimension(l, w);
}

ostream& operator<<(ostream&, const rectangleType&) {

}
istream& operator>>(istream&, rectangleType&) {

}

rectangleType rectangleType::operator + (const rectangleType& rectangle) const {
    rectangleType newRectangle;
    newRectangle.length = length + rectangle.length;
    newRectangle.width = width + rectangle.width;
    return newRectangle;
}
rectangleType rectangleType::operator - (const rectangleType& rectangle) const {
    rectangleType newRectangle;
    newRectangle.length = length - rectangle.length;
    newRectangle.width = width - rectangle.width;

    if (newRectangle.length < 0)
        newRectangle.length = 0;
    if (newRectangle.width < 0)
        newRectangle.width = 0;

    return newRectangle;
}
rectangleType rectangleType::operator * (const rectangleType& rectangle) const {
    rectangleType newRectangle;
    newRectangle.length = length * rectangle.length;
    newRectangle.width = width * rectangle.width;
    return newRectangle;
}
rectangleType rectangleType::operator ++ () {
    this->length++;
    this->width++;
    return(*this);
}  
rectangleType rectangleType::operator ++ (int u) {
    rectangleType temp = *this;
    length++;
    width++;
    return temp;
}
rectangleType rectangleType::operator -- () {
    this->length--;
    this->width--;
    return(*this);
}
rectangleType rectangleType::operator -- (int u) {
    rectangleType temp = *this;
    length--;
    width--;
    return temp;
}

bool rectangleType::operator == (const rectangleType& rectangle) const {
    return (this->area() == rectangle.area());
}
bool rectangleType::operator != (const rectangleType& rectangle) const {
    return (this->area() != rectangle.area());
}
bool rectangleType::operator <= (const rectangleType& rectangle) const {
    return (this->area() <= rectangle.area());
}
bool rectangleType::operator < (const rectangleType& rectangle) const {
    return (this->area() < rectangle.area());
}
bool rectangleType::operator >= (const rectangleType& rectangle) const {
    return (this->area() >= rectangle.area());
}
bool rectangleType::operator > (const rectangleType& rectangle) const {
    return (this->area() > rectangle.area());
}