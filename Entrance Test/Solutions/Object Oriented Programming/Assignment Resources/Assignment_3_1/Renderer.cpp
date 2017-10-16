#include "Renderer.h"
#include "World.h"
#include "Player.h"

extern World* g_pWorld;


void Renderer::Render() const
{
	const auto player = g_pWorld->GetPlayer();

	player->DrawUi();

	auto entities = g_pWorld->GetEntities();

	for(int i = 0; i < entities.size(); ++i)
	{
		entities[i]->Draw();
	}
}

Renderer::Renderer() {}

Renderer::~Renderer() {}