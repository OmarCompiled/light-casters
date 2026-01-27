// The contents of this file are only for reference
// The file should NOT be included in any file
// the .h extension is purly for vim syntax highlighting. :)


#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"


// Init Portion

// Setup Dear ImGui context
IMGUI_CHECKVERSION();
ImGui::CreateContext();
ImGuiIO& io = ImGui::GetIO();
io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // IF using Docking Branch

// Setup Platform/Renderer backends
ImGui_ImplGlfw_InitForOpenGL(YOUR_WINDOW, true);          // Second param install_callback=true will install GLFW callbacks and chain to existing ones.
ImGui_ImplOpenGL3_Init();

// Init Portion

// Start of main loop
// (Your code calls glfwPollEvents())
// ...
// Start the Dear ImGui frame
ImGui_ImplOpenGL3_NewFrame();
ImGui_ImplGlfw_NewFrame();
ImGui::NewFrame();
ImGui::ShowDemoWindow(); // Show demo window! :)
// Start of main loop

// End of main loop

// Rendering
// (Your code clears your framebuffer, renders your other stuff etc.)
ImGui::Render();
ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
// (Your code calls glfwSwapBuffers() etc.)

// End of main loop

// Shutdown
ImGui_ImplOpenGL3_Shutdown();
ImGui_ImplGlfw_Shutdown();
ImGui::DestroyContext();
// Shutdown
