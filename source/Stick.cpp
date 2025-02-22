#include <cmath>

#include "Stick.h"
#include "Point.h"

Stick::Stick(Point& p0, Point& p1, float length)
	: p0(p0)
	, p1(p1)
	, length(length)
{
}

void Stick::Update()
{
	if (!isActive)
		return;

	const Vec2 p0Pos = p0.GetPosition();
	const Vec2 p1Pos = p1.GetPosition();

	const Vec2 diff = p0Pos - p1Pos;
	const float dist = sqrtf(diff.x * diff.x + diff.y * diff.y);
	const float diffFactor = (length - dist) / dist;
	const Vec2 offset = diff * diffFactor * 0.5f;

	p0.SetPosition(p0Pos.x + offset.x, p0Pos.y + offset.y);
	p1.SetPosition(p1Pos.x - offset.x, p1Pos.y - offset.y);
}

void Stick::Draw(const Renderer* renderer) const
{
	if (!isActive)
		return;

	Vec2 p0Pos = p0.GetPosition();
	Vec2 p1Pos = p1.GetPosition();

	renderer->DrawLine(p0Pos.x, p0Pos.y, p1Pos.x, p1Pos.y, isSelected ? colorWhenSelected : color);
}

void Stick::Break()
{
	isActive = false;
}

void Stick::SetIsSelected(bool value)
{
	isSelected = value;
}
