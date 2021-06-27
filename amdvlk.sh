#!/bin/bash

# Ubuntu 16.04 with /opt/amdvlk64.so from amdvlk_2020.Q2.2_amd64.deb (c1966f16b20abf229b741a662ccb2569361896f704b7078f35b378f5bdf7fef9, downloaded from https://github.com/GPUOpen-Drivers/AMDVLK/releases/tag/v-2020.Q2.2)

mkdir -p ~/.local/share/vulkan/icd.d

echo "{"                                           >  ~/.local/share/vulkan/icd.d/amd_icd64.json
echo "  \"file_format_version\": \"1.0.0\","       >> ~/.local/share/vulkan/icd.d/amd_icd64.json
echo "  \"ICD\": {"                                >> ~/.local/share/vulkan/icd.d/amd_icd64.json
echo "    \"library_path\": \"/opt/amdvlk64.so\"," >> ~/.local/share/vulkan/icd.d/amd_icd64.json
echo "    \"api_version\": \"1.2.135\""            >> ~/.local/share/vulkan/icd.d/amd_icd64.json
echo "  }"                                         >> ~/.local/share/vulkan/icd.d/amd_icd64.json
echo "}"                                           >> ~/.local/share/vulkan/icd.d/amd_icd64.json

mkdir -p ~/.config

echo "MaxNumCmdStreamsPerSubmit,4"       >  ~/.config/amdPalSettings.cfg
echo "CommandBufferCombineDePreambles,1" >> ~/.config/amdPalSettings.cfg

# xdpyinfo | grep DRI
# cat /var/log/Xorg.0.log | grep EE
# cat /usr/share/X11/xorg.conf.d/10-amdgpu.conf
#
# Section "OutputClass"
#   Identifier "AMDgpu"
#   MatchDriver "amdgpu"
#   Driver "amdgpu"
# EndSection