class Vector2D
{
public:
  float x;
  float y;
  Vector2D(float x, float y);
  ~Vector2D();
  void normalize();
  void clampUnit();
};

Vector2D::Vector2D(float x, float y)
{
  this->x = x;
  this->y = y;
}

Vector2D::~Vector2D() {}

void Vector2D::normalize()
{
  float l = sqrt((this->x*this->x) + (this->y*this->y));
  this->x /= l;
  this->y /= l;
}

void Vector2D::clampUnit()
{
  float l = sqrt((this->x*this->x) + (this->y*this->y));
  if (l>1)
  {
    this->x /= l;
    this->y /= l;
  }
}

float dotProduct(Vector2D a, Vector2D b)
{
  return a.x*b.x + a.y*b.y;
}