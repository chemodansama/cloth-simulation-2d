#include "Cloth.h"

Cloth::Cloth(int width, int height, float spacing, float startX, float startY)
{
	points.reserve((height + 1) *  (width + 1));
	sticks.reserve((height + 1) *  (width + 1) * 2);

	for (int y = 0; y <= height; y++) {
		for (int x = 0; x <= width; x++)
		{
			Point &point = points.emplace_back(static_cast<float>(startX + x * spacing),
				static_cast<float>(startY + y * spacing));

			if (x != 0)
			{
				Point *leftPoint = &points[x - 1 + y * (width + 1)];
				Stick *s = &sticks.emplace_back(point, *leftPoint, spacing);
				leftPoint->AddStick(s, 0);
				point.AddStick(s, 0);
			}

			if (y != 0)
			{
				Point* upPoint = &points[x + (y - 1) * (width + 1)];
				Stick* s = &sticks.emplace_back(point, *upPoint, spacing);
				upPoint->AddStick(s, 1);
				point.AddStick(s, 1);
			}

			if (y == 0 && x % 2 == 0)
			{
				point.Pin();
			}
		}
	}
}

void Cloth::Update(Renderer* renderer, Mouse* mouse, float deltaTime)
{
	for (auto &p : points)
	{
		p.Update(deltaTime, drag, gravity, elasticity, mouse, renderer->GetWindowWidth(), renderer->GetWindowHeight());
	}

	for (int i = 0; i < 10; i++) {
		for (auto &stick : sticks) {
			stick.Update();
		}
	}
}

void Cloth::Draw(Renderer* renderer) const
{
	for (auto &stick : sticks)
	{
		stick.Draw(renderer);
	}
}
