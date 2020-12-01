#include <node.h>
#include <iostream>
#include <string.h>
#include "cuadrilatero.h"
using namespace std;

namespace cuadrilatero {
    using v8::FunctionCallbackInfo;
    using v8::Isolate;
    using v8::Local;
    using v8::Object;
    using v8::Number;
    using v8::String;
    using v8::NewStringType;
    using v8::Value;
    
    Cuadrilatero* c1 = new Cuadrilatero(0, 0, "");

    void crearCuadrilatero(const FunctionCallbackInfo<Value>&args) {
        Isolate* isolate = args.GetIsolate();

        float ancho = args[0].As<Number>()->Value();
        float alto = args[1].As<Number>()->Value();
        String::Utf8Value str(isolate, args[2]);
        string color(*str);

        if(ancho == alto) {
            c1 = new Cuadrilatero(ancho, color);
        } else {
            c1 = new Cuadrilatero(ancho, alto, color);
        }
    }

    void getPerimetro(const FunctionCallbackInfo<Value>&args) {
        Isolate* isolate = args.GetIsolate();

        float perimetro = c1->obtenerPerimetro();

        Local<Number> pem = Number::New(isolate, perimetro);

        args.GetReturnValue().Set(pem);
    }  

    void getArea(const FunctionCallbackInfo<Value>&args) {
        Isolate* isolate = args.GetIsolate();

        float area = c1->obtenerArea();

        Local<Number> ar = Number::New(isolate, area);

        args.GetReturnValue().Set(ar);
    } 

    void getAncho(const FunctionCallbackInfo<Value>&args) {
        Isolate* isolate = args.GetIsolate();

        float ancho = c1->getAncho();

        Local<Number> val = Number::New(isolate, ancho);

        args.GetReturnValue().Set(val);
    } 

    void getAlto(const FunctionCallbackInfo<Value>&args) {
        Isolate* isolate = args.GetIsolate();

        float alto = c1->getAlto();

        Local<Number> val = Number::New(isolate, alto);

        args.GetReturnValue().Set(val);
    } 

    void getColor(const FunctionCallbackInfo<Value>&args) {
        Isolate* isolate = args.GetIsolate();

        string str = c1->getColor();
        char *color = new char[str.length() + 1];
        strcpy(color, str.c_str());

        args.GetReturnValue().Set(String::NewFromUtf8(isolate, color, NewStringType::kNormal).ToLocalChecked());
    } 

    void setAncho(const FunctionCallbackInfo<Value>&args) {
        Isolate* isolate = args.GetIsolate();

        float ancho = args[0].As<Number>()->Value();

        c1->setAncho(ancho);
    } 

    void setAlto(const FunctionCallbackInfo<Value>&args) {
        Isolate* isolate = args.GetIsolate();

        float alto = args[0].As<Number>()->Value();

        c1->setAlto(alto);
    } 

    void setColor(const FunctionCallbackInfo<Value>&args) {
        Isolate* isolate = args.GetIsolate();

        String::Utf8Value str(isolate, args[0]);
        string color(*str);

        c1->setColor(color);
    } 

    void Initialize(Local<Object> exports) {
        NODE_SET_METHOD(exports, "crear", crearCuadrilatero);
        NODE_SET_METHOD(exports, "calcularPerimetro", getPerimetro);
        NODE_SET_METHOD(exports, "calcularArea", getArea);
        NODE_SET_METHOD(exports, "obtenerAncho", getAncho);
        NODE_SET_METHOD(exports, "obtenerAlto", getAlto);
        NODE_SET_METHOD(exports, "obtenerColor", getColor);
        NODE_SET_METHOD(exports, "cambiarAncho", setAncho);
        NODE_SET_METHOD(exports, "cambiarAlto", setAlto);
        NODE_SET_METHOD(exports, "cambiarColor", setColor);
    }

    NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize);

}