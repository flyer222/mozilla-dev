/* -*- Mode: c++; c-basic-offset: 2; indent-tabs-mode: nil; tab-width: 40 -*- */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef mozilla_dom_workers_scriptloader_h__
#define mozilla_dom_workers_scriptloader_h__

#include "Workers.h"

class nsIPrincipal;
class nsIURI;
class nsIDocument;
class nsString;
class nsIChannel;

namespace mozilla {

class ErrorResult;

namespace dom {

template <typename T>
class Sequence;

} // namespace dom
} // namespace mozilla

BEGIN_WORKERS_NAMESPACE

namespace scriptloader {

nsresult
ChannelFromScriptURLMainThread(nsIPrincipal* aPrincipal,
                               nsIURI* aBaseURI,
                               nsIDocument* aParentDoc,
                               const nsAString& aScriptURL,
                               bool aIsServiceWorker,
                               nsIChannel** aChannel);

nsresult
ChannelFromScriptURLWorkerThread(JSContext* aCx,
                                 WorkerPrivate* aParent,
                                 const nsAString& aScriptURL,
                                 nsIChannel** aChannel);

void ReportLoadError(JSContext* aCx, const nsAString& aURL,
                     nsresult aLoadResult, bool aIsMainThread);

bool LoadWorkerScript(JSContext* aCx);

void Load(JSContext* aCx,
          WorkerPrivate* aWorkerPrivate,
          const mozilla::dom::Sequence<nsString>& aScriptURLs,
          mozilla::ErrorResult& aRv);

} // namespace scriptloader

END_WORKERS_NAMESPACE

#endif /* mozilla_dom_workers_scriptloader_h__ */
