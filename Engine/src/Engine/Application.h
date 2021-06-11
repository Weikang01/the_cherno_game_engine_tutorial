#pragma once
#include "Core.h"

#include "Engine/Window.h"
#include "Engine/LayerStack.h"
#include "Engine/Events/ApplicationEvent.h"
#include "Engine/Events/KeyEvent.h"
#include "Engine/Events/MouseEvent.h"

namespace Engine
{
	class ImGuiLayer;

	class ENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();

		void OnEvent(Event& evnt);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		static Application& Get() { return *s_instance; }
		Window& GetWindow() { return *m_window; }
	private:
		static Application* s_instance;

		bool OnWindowClose(WindowCloseEvent& evnt);

		std::unique_ptr<Window> m_window;
		ImGuiLayer* m_imGuiLayer = nullptr;
		bool m_running = true;
		LayerStack m_layerStack;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}
