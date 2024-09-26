#include "imgui.h"
#include <string>
#include <vector>

bool permanent_spoofing = false;
bool efi_spoofing = false;
bool tournament_fixer = false;
bool network_spoof = false;
bool registry_spoof = false;
bool disk_guid_spoof = false;

std::string mainLogMessages;
std::string additionalLogMessages;

bool showSettingsWindow = false;
int spoofConfigIndex = 0; 
int motherboardIndex = 0; 
bool debugMode = false; 

void AddMainLog(const std::string& message) {
    mainLogMessages += message + "\n";
}

void AddAdditionalLog(const std::string& message) {
    additionalLogMessages += message + "\n";
}

void ApplyCustomStyle() {
    ImGui::StyleColorsDark();

    ImGuiStyle& style = ImGui::GetStyle();
    ImVec4* colors = style.Colors;

    colors[ImGuiCol_WindowBg] = ImVec4(0.15f, 0.15f, 0.15f, 1.00f);
    colors[ImGuiCol_TitleBg] = ImVec4(0.10f, 0.10f, 0.10f, 1.00f);
    colors[ImGuiCol_TitleBgActive] = ImVec4(0.12f, 0.12f, 0.12f, 1.00f);
    colors[ImGuiCol_FrameBg] = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
    colors[ImGuiCol_FrameBgActive] = ImVec4(0.30f, 0.30f, 0.30f, 1.00f);

    colors[ImGuiCol_Button] = ImVec4(0.96f, 0.81f, 0.81f, 1.00f);
    colors[ImGuiCol_CheckMark] = ImVec4(0.96f, 0.81f, 0.81f, 1.00f);

    colors[ImGuiCol_ButtonHovered] = ImVec4(0.96f, 0.74f, 0.74f, 1.00f);
    colors[ImGuiCol_ButtonActive] = ImVec4(0.96f, 0.66f, 0.66f, 1.00f);

    colors[ImGuiCol_Text] = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
}

void RenderSettingsWindow() {
    if (showSettingsWindow) {
        ImGui::Begin("Settings", &showSettingsWindow, ImGuiWindowFlags_NoResize);
        if (ImGui::IsWindowHovered() && ImGui::IsMouseDragging(ImGuiMouseButton_Left)) {
            ImVec2 dragDelta = ImGui::GetMouseDragDelta(ImGuiMouseButton_Left);
            ImVec2 newPos = ImGui::GetWindowPos();
            newPos.x += dragDelta.x;
            newPos.y += dragDelta.y;
            ImGui::SetWindowPos(newPos);
            ImGui::ResetMouseDragDelta(ImGuiMouseButton_Left);
        }

        ImGui::Text("Spoof Config");
        const char* spoofConfigs[] = { "9-26-2024", "2", "3", "4" };
        ImGui::Combo("##spoofconfig", &spoofConfigIndex, spoofConfigs, IM_ARRAYSIZE(spoofConfigs));
        ImGui::Text("Motherboard");
        const char* motherboards[] = { "ASUS", "Gigabyte", "MSI", "ASRock" };
        ImGui::Combo("##motherboard", &motherboardIndex, motherboards, IM_ARRAYSIZE(motherboards));

        ImGui::Spacing();
        ImGui::Separator();
        ImGui::Spacing();

        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.96f, 0.81f, 0.81f, 1.00f));
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.96f, 0.74f, 0.74f, 1.00f));
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.96f, 0.66f, 0.66f, 1.00f));

        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.15f, 0.15f, 0.15f, 1.0f)); 
        if (ImGui::Button("Save Config", ImVec2(315, 38))) {
            
        }
        ImGui::PopStyleColor(); 

        ImGui::Spacing();

        ImGui::Checkbox("Debug Mode", &debugMode);

        ImGui::PopStyleColor(3);

        ImGui::End();
    }
}



void RenderMenu() {
    ApplyCustomStyle();

    ImGui::SetNextWindowSize(ImVec2(420, 600));
    ImGui::SetNextWindowPos(ImVec2(100, 100), ImGuiCond_FirstUseEver);

    ImGui::Begin("Spoofing Menu", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar);

    if (ImGui::IsWindowHovered() && !showSettingsWindow && ImGui::IsMouseDragging(ImGuiMouseButton_Left)) {
        ImVec2 dragDelta = ImGui::GetMouseDragDelta(ImGuiMouseButton_Left);
        ImVec2 newPos = ImGui::GetWindowPos();
        newPos.x += dragDelta.x;
        newPos.y += dragDelta.y;
        ImGui::SetWindowPos(newPos);
        ImGui::ResetMouseDragDelta(ImGuiMouseButton_Left);
    }

    ImGui::Separator();
    ImGui::Text("scylla spoof | freeware");
    ImGui::Separator();

    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));

    if (ImGui::Checkbox("Permanent Spoofing", &permanent_spoofing)) {
        if (permanent_spoofing) AddMainLog("Enabled Permanent Spoofing");
        else AddMainLog("Disabled Permanent Spoofing");
    }

    if (ImGui::Checkbox("Permanent EFI Spoofing", &efi_spoofing)) {
        if (efi_spoofing) AddMainLog("Enabled Permanent EFI Spoofing");
        else AddMainLog("Disabled Permanent EFI Spoofing");
    }

    if (ImGui::Checkbox("Tournament Fixer", &tournament_fixer)) {
        if (tournament_fixer) AddMainLog("Enabled Tournament Fixer");
        else AddMainLog("Disabled Tournament Fixer");
    }

    ImGui::Separator();

    if (ImGui::Checkbox("Network Spoof", &network_spoof)) {
        if (network_spoof) AddMainLog("Enabled Network Spoof");
        else AddMainLog("Disabled Network Spoof");
    }

    if (ImGui::Checkbox("Handle Registry", &registry_spoof)) {
        if (registry_spoof) AddMainLog("Enabled Registry Spoof");
        else AddMainLog("Disabled Registry Spoof");
    }

    if (ImGui::Checkbox("Disk GUID Spoof", &disk_guid_spoof)) {
        if (disk_guid_spoof) AddMainLog("Enabled Disk GUID Spoof");
        else AddMainLog("Disabled Disk GUID Spoof");
    }

    ImGui::PopStyleColor();

    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Spacing();

    ImGui::BeginChild("Main Log Box", ImVec2(400, 100), true, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
    ImGui::TextWrapped("%s", mainLogMessages.c_str());
    ImGui::EndChild();


    ImGui::BeginChild("Additional Log Box", ImVec2(400, 100), true, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
    ImGui::TextWrapped("%s", additionalLogMessages.c_str());
    ImGui::EndChild();

    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Spacing();

    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.15f, 0.15f, 0.15f, 1.0f));

    float windowWidth = ImGui::GetWindowSize().x;

    float buttonHeight = 38.0f;
    float buttonWidth = windowWidth - 20.0f;

    float offsetX = (windowWidth - buttonWidth) * 0.5f;

    ImGui::SetCursorPosX(offsetX);
    if (ImGui::Button("Launch Module", ImVec2(buttonWidth, buttonHeight))) {
        AddAdditionalLog("Virtualizing Hardware");
        AddAdditionalLog("Virtualizing Registry");
        AddAdditionalLog("Virtualized MSI32  ");
        AddAdditionalLog("Reading BIOS Model  ");
        AddAdditionalLog("Executed BIOS Model  ");
    }

    ImGui::Spacing();

    ImGui::SetCursorPosX(offsetX);
    if (ImGui::Button("Check Serials", ImVec2(buttonWidth, buttonHeight))) {
        AddAdditionalLog("Serials saved to serials.txt");
    }

    ImGui::Spacing();

    ImGui::SetCursorPosX(offsetX);
    if (ImGui::Button("Open settings", ImVec2(buttonWidth, buttonHeight))) {
        showSettingsWindow = true;
    }

    ImGui::PopStyleColor();

    ImGui::End();

    RenderSettingsWindow();
}
