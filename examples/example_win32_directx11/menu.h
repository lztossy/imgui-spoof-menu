#ifndef MENU_H
#define MENU_H

#include <string>

extern bool permanent_spoofing;
extern bool efi_spoofing;
extern bool tournament_fixer;
extern bool network_spoof;
extern bool registry_spoof;
extern bool disk_guid_spoof;

extern std::string mainLogMessages;
extern std::string additionalLogMessages;

// Function declarations
void AddMainLog(const std::string& message);
void AddAdditionalLog(const std::string& message);
void ApplyCustomStyle();
void RenderMenu();

#endif 
