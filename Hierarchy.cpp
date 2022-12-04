#include "Hierarchy.h"
#include "ImGui/imgui.h"

Hierarchy::Hierarchy()
{
	active = true;

	


}

Hierarchy::~Hierarchy()
{
	//https://www.youtube.com/watch?v=9Gognvp8BvQ&ab_channel=OneShot mirar para repasar cosas de ImGuI
}

void Hierarchy::Draw()
{
	ImGui::SetNextWindowBgAlpha(1.0f);
	ImGui::Begin("Hierarchy");
	{
		ImGui::SetWindowPos({ 0,20 });
		ImGui::SetWindowSize({ 300,550});
		ProcessGameObject(App->scene_intro->rootObject);
	}
	ImGui::End();

}

void Hierarchy::PopUpOptions(ModuleGameObject* gameObject)
{
	ImGui::Begin("Tools");

	if(ImGui::BeginChild("Hierarchy Tools"))
	{
		if (ImGui::MenuItem("Delete Selected"))
		{
			
		}

		if (ImGui::MenuItem("Create Empty Child GameObject"))
		{

		}

		ImGui::EndChild();
	}
	ImGui::End();
}

void Hierarchy::ProcessGameObject(ModuleGameObject* GameObject)
{
	ImGuiTreeNodeFlags node_flags = ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_SpanAvailWidth;


	if (GameObject->childs.empty())
	{
		node_flags |= ImGuiTreeNodeFlags_Leaf;
	}
	if (GameObject == App->scene_intro->rootObject)
	{
		node_flags |= ImGuiTreeNodeFlags_DefaultOpen;
	}
	if (GameObject ==App->scene_intro->GetSelectedGameObject())
	{
		node_flags |= ImGuiTreeNodeFlags_Selected;
	}
	if (ImGui::TreeNodeEx(GameObject->GetName().c_str(), node_flags))
	{
		if (GameObject != App->scene_intro->rootObject)
		{
			if (ImGui::IsItemClicked(ImGuiMouseButton_Left))								
			{																				
				App->scene_intro->SelectItem(GameObject);
			}																				

			if (ImGui::IsItemClicked(ImGuiMouseButton_Right))								
			{																				
				App->scene_intro->SelectItem(GameObject);
			}																				
			
		}

		if (!GameObject->childs.empty())
		{
			for (uint i = 0; i < GameObject->childs.size(); ++i)
			{
				ProcessGameObject(GameObject->childs[i]);
			}
		}

		ImGui::TreePop();
	}
}