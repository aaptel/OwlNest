#include "PluginPatchProcessor.h"
#include "PluginProcessor.h"

PluginPatchProcessor::PluginPatchProcessor(StompBoxAudioProcessor* pl)
  : plugin(pl){
}

PluginPatchProcessor::~PluginPatchProcessor(){
  plugin = NULL;
}

void PluginPatchProcessor::setPatch(Patch* p){
  patch = p;
}

void PluginPatchProcessor::registerParameter(PatchParameterId pid, const std::string& name, const std::string& description){
  plugin->registerParameter(pid, name, description);
}

float PluginPatchProcessor::getParameterValue(PatchParameterId pid){
  return plugin->getParameter(pid);
}

int PluginPatchProcessor::getBlockSize(){
  return plugin->getBlockSize();
}

double PluginPatchProcessor::getSampleRate(){
  return plugin->getSampleRate();
}

AudioBuffer* PluginPatchProcessor::createMemoryBuffer(int channels, int samples){
  MemoryBuffer* buf = new MemoryBuffer(channels, samples);
  buffers.add(buf);
  return buf;
}
  
void PluginPatchProcessor::processAudio(AudioBuffer& buffer){
  patch->processAudio(buffer);
}
