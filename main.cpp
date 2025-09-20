#include "qtclasstemplate.h"
#include "regex"
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

std::string strToUpper(std::string input) {
  std::transform(input.begin(), input.end(), input.begin(), ::toupper);
  return input;
}

std::string strToLower(std::string input) {
  std::transform(input.begin(), input.end(), input.begin(), ::tolower);
  return input;
}

void saveToFile(std::string path, std::string contex) {
  std::cout<<"fileName = "<<path<<"\r\n";
  std::ifstream ifs(path);
  if (ifs.is_open()) {
    std::cout << "this file is already exits:"<<path<<"\r\n";
    ifs.close();
  }
  std::ofstream ofs(path);
  ofs << contex;
  ofs.close();
  std::cout << "********************************\r\n";
}

void createClassTemplateFile(std::string className, std::string clsssType) {
  std::string src_ui, src_h, src_cpp, templateClassName;
  if (className == "widgets") {
    src_ui = widgets_ui;
    src_h = widgets_h;
    src_cpp = widgets_cpp;
    templateClassName = "TestWidgets";
  } else {
    src_ui = dialog_ui;
    src_h = dialog_h;
    src_cpp = dialog_cpp;
    templateClassName = "TestDialog";
  }
  auto templateClassNameLow = strToLower(templateClassName);
  auto templateClassNameUp = strToUpper(templateClassName);

  src_ui = std::regex_replace(src_ui, std::regex(templateClassName), className);

  src_h = std::regex_replace(src_h, std::regex(templateClassNameUp),
                             strToUpper(className));
  src_h = std::regex_replace(src_h, std::regex(templateClassName), className);

  src_cpp = std::regex_replace(src_cpp, std::regex(templateClassNameLow),
                               strToLower(className));
  src_cpp =
      std::regex_replace(src_cpp, std::regex(templateClassName), className);

  saveToFile(className + ".h", src_h);
  saveToFile(className+ ".ui", src_ui);
  saveToFile(className+ ".cpp", src_cpp);
}

int main(int argc, char **argv) {
  std::regex re_argv(R"(\s*-(\S*)\s*)");
  for (int i = 1; i < argc; i++) {

    auto s = std::string(argv[i]);
    std::smatch match;
    auto hasType = std::regex_search(s, match, re_argv);
    std::cout<<"s="<<s<<" hasType = "<<hasType<<"\r\n";
    std::string sType = "";
    std::string sTypeName = "widgets";
    std::string className = "";
    if (hasType && i + 1 < argc) { 
      sType = match[i];
      sTypeName = argv[i + 1];
      if (sTypeName != "dialog" && sTypeName != "widgets") {
            std::cout << "error type!\r\n"; //-t后面必须时dialog或者widges;
            return -1;
          }
        i += 2; // 输入的型号顺序是:类型 类型名称 类名，这里要+2;
        className = argv[i + 2];
    } else {
      className = argv[i];
    }
    if(className.empty() && !className.empty()){
      std::cout << "className = " << className << "\r\n";
      createClassTemplateFile(className, sTypeName);
    }
  }
}
