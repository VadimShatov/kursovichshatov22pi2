##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=speedrun
ConfigurationName      :=Debug
WorkspacePath          :=/home/stud/C++Projects/C++Projects
ProjectPath            :=/home/stud/C++Projects/C++Projects/speedrun
IntermediateDirectory  :=$(ConfigurationName)
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=
Date                   :=12/26/23
CodeLitePath           :=/home/stud/.codelite
LinkerName             :=/usr/bin/g++-10
SharedObjectLinkerName :=/usr/bin/g++-10 -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="speedrun.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++-10
CC       := /usr/bin/gcc-10
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/md5h.cpp$(ObjectSuffix) $(IntermediateDirectory)/datareader.cpp$(ObjectSuffix) $(IntermediateDirectory)/server.cpp$(ObjectSuffix) $(IntermediateDirectory)/unittest.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d $(ConfigurationName) || $(MakeDirCommand) $(ConfigurationName)


$(IntermediateDirectory)/.d:
	@test -d $(ConfigurationName) || $(MakeDirCommand) $(ConfigurationName)

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/md5h.cpp$(ObjectSuffix): md5h.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/md5h.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/md5h.cpp$(DependSuffix) -MM md5h.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/stud/C++Projects/C++Projects/speedrun/md5h.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/md5h.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/md5h.cpp$(PreprocessSuffix): md5h.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/md5h.cpp$(PreprocessSuffix) md5h.cpp

$(IntermediateDirectory)/datareader.cpp$(ObjectSuffix): datareader.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/datareader.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/datareader.cpp$(DependSuffix) -MM datareader.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/stud/C++Projects/C++Projects/speedrun/datareader.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/datareader.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/datareader.cpp$(PreprocessSuffix): datareader.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/datareader.cpp$(PreprocessSuffix) datareader.cpp

$(IntermediateDirectory)/server.cpp$(ObjectSuffix): server.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/server.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/server.cpp$(DependSuffix) -MM server.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/stud/C++Projects/C++Projects/speedrun/server.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/server.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/server.cpp$(PreprocessSuffix): server.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/server.cpp$(PreprocessSuffix) server.cpp

$(IntermediateDirectory)/unittest.cpp$(ObjectSuffix): unittest.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/unittest.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/unittest.cpp$(DependSuffix) -MM unittest.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/stud/C++Projects/C++Projects/speedrun/unittest.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/unittest.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/unittest.cpp$(PreprocessSuffix): unittest.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/unittest.cpp$(PreprocessSuffix) unittest.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/stud/C++Projects/C++Projects/speedrun/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(ConfigurationName)/


