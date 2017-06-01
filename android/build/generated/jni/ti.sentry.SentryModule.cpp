/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2011-2013 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

/** This code is generated, do not edit by hand. **/

#include "ti.sentry.SentryModule.h"

#include "AndroidUtil.h"
#include "EventEmitter.h"
#include "JNIUtil.h"
#include "JSException.h"
#include "Proxy.h"
#include "ProxyFactory.h"
#include "TypeConverter.h"
#include "V8Util.h"




#include "org.appcelerator.kroll.KrollModule.h"

#define TAG "SentryModule"

using namespace v8;

		namespace ti {
		namespace sentry {


Persistent<FunctionTemplate> SentryModule::proxyTemplate = Persistent<FunctionTemplate>();
jclass SentryModule::javaClass = NULL;

SentryModule::SentryModule(jobject javaObject) : titanium::Proxy(javaObject)
{
}

void SentryModule::bindProxy(Handle<Object> exports)
{
	if (proxyTemplate.IsEmpty()) {
		getProxyTemplate();
	}

	// use symbol over string for efficiency
	Handle<String> nameSymbol = String::NewSymbol("Sentry");

	Local<Function> proxyConstructor = proxyTemplate->GetFunction();
	Local<Object> moduleInstance = proxyConstructor->NewInstance();
	exports->Set(nameSymbol, moduleInstance);
}

void SentryModule::dispose()
{
	LOGD(TAG, "dispose()");
	if (!proxyTemplate.IsEmpty()) {
		proxyTemplate.Dispose();
		proxyTemplate = Persistent<FunctionTemplate>();
	}

	titanium::KrollModule::dispose();
}

Handle<FunctionTemplate> SentryModule::getProxyTemplate()
{
	if (!proxyTemplate.IsEmpty()) {
		return proxyTemplate;
	}

	LOGD(TAG, "GetProxyTemplate");

	javaClass = titanium::JNIUtil::findClass("ti/sentry/SentryModule");
	HandleScope scope;

	// use symbol over string for efficiency
	Handle<String> nameSymbol = String::NewSymbol("Sentry");

	Handle<FunctionTemplate> t = titanium::Proxy::inheritProxyTemplate(
		titanium::KrollModule::getProxyTemplate()
, javaClass, nameSymbol);

	proxyTemplate = Persistent<FunctionTemplate>::New(t);
	proxyTemplate->Set(titanium::Proxy::inheritSymbol,
		FunctionTemplate::New(titanium::Proxy::inherit<SentryModule>)->GetFunction());

	titanium::ProxyFactory::registerProxyPair(javaClass, *proxyTemplate);

	// Method bindings --------------------------------------------------------
	DEFINE_PROTOTYPE_METHOD(proxyTemplate, "captureMessage", SentryModule::captureMessage);
	DEFINE_PROTOTYPE_METHOD(proxyTemplate, "addBreadcrumb", SentryModule::addBreadcrumb);
	DEFINE_PROTOTYPE_METHOD(proxyTemplate, "addNavigationBreadcrumb", SentryModule::addNavigationBreadcrumb);
	DEFINE_PROTOTYPE_METHOD(proxyTemplate, "addHttpBreadcrumb", SentryModule::addHttpBreadcrumb);
	DEFINE_PROTOTYPE_METHOD(proxyTemplate, "captureEvent", SentryModule::captureEvent);

	Local<ObjectTemplate> prototypeTemplate = proxyTemplate->PrototypeTemplate();
	Local<ObjectTemplate> instanceTemplate = proxyTemplate->InstanceTemplate();

	// Delegate indexed property get and set to the Java proxy.
	instanceTemplate->SetIndexedPropertyHandler(titanium::Proxy::getIndexedProperty,
		titanium::Proxy::setIndexedProperty);

	// Constants --------------------------------------------------------------

	// Dynamic properties -----------------------------------------------------

	// Accessors --------------------------------------------------------------

	return proxyTemplate;
}

// Methods --------------------------------------------------------------------
Handle<Value> SentryModule::captureMessage(const Arguments& args)
{
	LOGD(TAG, "captureMessage()");
	HandleScope scope;

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		return titanium::JSException::GetJNIEnvironmentError();
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(SentryModule::javaClass, "captureMessage", "(Ljava/lang/String;)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'captureMessage' with signature '(Ljava/lang/String;)V'";
			LOGE(TAG, error);
				return titanium::JSException::Error(error);
		}
	}

	titanium::Proxy* proxy = titanium::Proxy::unwrap(args.Holder());

	if (args.Length() < 1) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "captureMessage: Invalid number of arguments. Expected 1 but got %d", args.Length());
		return ThrowException(Exception::Error(String::New(errorStringBuffer)));
	}

	jvalue jArguments[1];




	
	
	if (!args[0]->IsNull()) {
		Local<Value> arg_0 = args[0];
		jArguments[0].l =
			titanium::TypeConverter::jsValueToJavaString(env, arg_0);
	} else {
		jArguments[0].l = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	if (!JavaObject::useGlobalRefs) {
		env->DeleteLocalRef(javaProxy);
	}



				env->DeleteLocalRef(jArguments[0].l);


	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException();
		env->ExceptionClear();
	}




	return v8::Undefined();

}
Handle<Value> SentryModule::addBreadcrumb(const Arguments& args)
{
	LOGD(TAG, "addBreadcrumb()");
	HandleScope scope;

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		return titanium::JSException::GetJNIEnvironmentError();
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(SentryModule::javaClass, "addBreadcrumb", "(Ljava/lang/String;Ljava/lang/String;)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'addBreadcrumb' with signature '(Ljava/lang/String;Ljava/lang/String;)V'";
			LOGE(TAG, error);
				return titanium::JSException::Error(error);
		}
	}

	titanium::Proxy* proxy = titanium::Proxy::unwrap(args.Holder());

	if (args.Length() < 2) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "addBreadcrumb: Invalid number of arguments. Expected 2 but got %d", args.Length());
		return ThrowException(Exception::Error(String::New(errorStringBuffer)));
	}

	jvalue jArguments[2];




	
	
	if (!args[0]->IsNull()) {
		Local<Value> arg_0 = args[0];
		jArguments[0].l =
			titanium::TypeConverter::jsValueToJavaString(env, arg_0);
	} else {
		jArguments[0].l = NULL;
	}

	
	
	if (!args[1]->IsNull()) {
		Local<Value> arg_1 = args[1];
		jArguments[1].l =
			titanium::TypeConverter::jsValueToJavaString(env, arg_1);
	} else {
		jArguments[1].l = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	if (!JavaObject::useGlobalRefs) {
		env->DeleteLocalRef(javaProxy);
	}



				env->DeleteLocalRef(jArguments[0].l);


				env->DeleteLocalRef(jArguments[1].l);


	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException();
		env->ExceptionClear();
	}




	return v8::Undefined();

}
Handle<Value> SentryModule::addNavigationBreadcrumb(const Arguments& args)
{
	LOGD(TAG, "addNavigationBreadcrumb()");
	HandleScope scope;

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		return titanium::JSException::GetJNIEnvironmentError();
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(SentryModule::javaClass, "addNavigationBreadcrumb", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'addNavigationBreadcrumb' with signature '(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V'";
			LOGE(TAG, error);
				return titanium::JSException::Error(error);
		}
	}

	titanium::Proxy* proxy = titanium::Proxy::unwrap(args.Holder());

	if (args.Length() < 3) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "addNavigationBreadcrumb: Invalid number of arguments. Expected 3 but got %d", args.Length());
		return ThrowException(Exception::Error(String::New(errorStringBuffer)));
	}

	jvalue jArguments[3];




	
	
	if (!args[0]->IsNull()) {
		Local<Value> arg_0 = args[0];
		jArguments[0].l =
			titanium::TypeConverter::jsValueToJavaString(env, arg_0);
	} else {
		jArguments[0].l = NULL;
	}

	
	
	if (!args[1]->IsNull()) {
		Local<Value> arg_1 = args[1];
		jArguments[1].l =
			titanium::TypeConverter::jsValueToJavaString(env, arg_1);
	} else {
		jArguments[1].l = NULL;
	}

	
	
	if (!args[2]->IsNull()) {
		Local<Value> arg_2 = args[2];
		jArguments[2].l =
			titanium::TypeConverter::jsValueToJavaString(env, arg_2);
	} else {
		jArguments[2].l = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	if (!JavaObject::useGlobalRefs) {
		env->DeleteLocalRef(javaProxy);
	}



				env->DeleteLocalRef(jArguments[0].l);


				env->DeleteLocalRef(jArguments[1].l);


				env->DeleteLocalRef(jArguments[2].l);


	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException();
		env->ExceptionClear();
	}




	return v8::Undefined();

}
Handle<Value> SentryModule::addHttpBreadcrumb(const Arguments& args)
{
	LOGD(TAG, "addHttpBreadcrumb()");
	HandleScope scope;

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		return titanium::JSException::GetJNIEnvironmentError();
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(SentryModule::javaClass, "addHttpBreadcrumb", "(Ljava/lang/String;Ljava/lang/String;I)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'addHttpBreadcrumb' with signature '(Ljava/lang/String;Ljava/lang/String;I)V'";
			LOGE(TAG, error);
				return titanium::JSException::Error(error);
		}
	}

	titanium::Proxy* proxy = titanium::Proxy::unwrap(args.Holder());

	if (args.Length() < 3) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "addHttpBreadcrumb: Invalid number of arguments. Expected 3 but got %d", args.Length());
		return ThrowException(Exception::Error(String::New(errorStringBuffer)));
	}

	jvalue jArguments[3];




	
	
	if (!args[0]->IsNull()) {
		Local<Value> arg_0 = args[0];
		jArguments[0].l =
			titanium::TypeConverter::jsValueToJavaString(env, arg_0);
	} else {
		jArguments[0].l = NULL;
	}

	
	
	if (!args[1]->IsNull()) {
		Local<Value> arg_1 = args[1];
		jArguments[1].l =
			titanium::TypeConverter::jsValueToJavaString(env, arg_1);
	} else {
		jArguments[1].l = NULL;
	}

	
	
		if ((titanium::V8Util::isNaN(args[2]) && !args[2]->IsUndefined()) || args[2]->ToString()->Length() == 0) {
			const char *error = "Invalid value, expected type Number.";
			LOGE(TAG, error);
			return titanium::JSException::Error(error);
		}
	if (!args[2]->IsNull()) {
		Local<Number> arg_2 = args[2]->ToNumber();
		jArguments[2].i =
			titanium::TypeConverter::jsNumberToJavaInt(env, arg_2);
	} else {
		jArguments[2].i = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	if (!JavaObject::useGlobalRefs) {
		env->DeleteLocalRef(javaProxy);
	}



				env->DeleteLocalRef(jArguments[0].l);


				env->DeleteLocalRef(jArguments[1].l);


	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException();
		env->ExceptionClear();
	}




	return v8::Undefined();

}
Handle<Value> SentryModule::captureEvent(const Arguments& args)
{
	LOGD(TAG, "captureEvent()");
	HandleScope scope;

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		return titanium::JSException::GetJNIEnvironmentError();
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(SentryModule::javaClass, "captureEvent", "(Lorg/appcelerator/kroll/KrollDict;)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'captureEvent' with signature '(Lorg/appcelerator/kroll/KrollDict;)V'";
			LOGE(TAG, error);
				return titanium::JSException::Error(error);
		}
	}

	titanium::Proxy* proxy = titanium::Proxy::unwrap(args.Holder());

	if (args.Length() < 1) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "captureEvent: Invalid number of arguments. Expected 1 but got %d", args.Length());
		return ThrowException(Exception::Error(String::New(errorStringBuffer)));
	}

	jvalue jArguments[1];




	bool isNew_0;
	
	if (!args[0]->IsNull()) {
		Local<Value> arg_0 = args[0];
		jArguments[0].l =
			titanium::TypeConverter::jsObjectToJavaKrollDict(env, arg_0, &isNew_0);
	} else {
		jArguments[0].l = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	if (!JavaObject::useGlobalRefs) {
		env->DeleteLocalRef(javaProxy);
	}



			if (isNew_0) {
				env->DeleteLocalRef(jArguments[0].l);
			}


	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException();
		env->ExceptionClear();
	}




	return v8::Undefined();

}

// Dynamic property accessors -------------------------------------------------


		} // sentry
		} // ti
