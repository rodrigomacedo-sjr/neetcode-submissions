type SquareHole struct {
    sideLength float64
}

func NewSquareHole(sideLength float64) *SquareHole {
    return &SquareHole{sideLength: sideLength}
}

func (sh *SquareHole) CanFit(square *Square) bool {
    return sh.sideLength >= square.GetSideLength()
}

type Square struct {
    sideLength float64
}

func NewSquare(sideLength float64) *Square {
    return &Square{sideLength: sideLength}
}

func (s *Square) GetSideLength() float64 {
    return s.sideLength
}

type Circle struct {
    radius float64
}

func NewCircle(radius float64) *Circle {
    return &Circle{radius: radius}
}

func (c *Circle) GetRadius() float64 {
    return c.radius
}

type CircleToSquareAdapter struct {
    circle *Circle
}

func NewCircleToSquareAdapter(circle *Circle) *CircleToSquareAdapter {
    return &CircleToSquareAdapter{circle: circle}
}

func (a *CircleToSquareAdapter) GetSideLength() float64 {
    return a.circle.radius * 2
}
