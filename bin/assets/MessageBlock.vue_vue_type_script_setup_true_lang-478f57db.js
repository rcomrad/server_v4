import{D as r,G as o,o as s,c as t,K as l,N as n,L as c,J as m}from"./runtime-core.esm-bundler-866dbb67.js";const _=r({__name:"MessageBlock",setup(g){const e=o([]);return localStorage.getItem("messages")!=null&&(e.value=JSON.parse(localStorage.getItem("messages")),localStorage.removeItem("messages")),(p,i)=>(s(!0),t(m,null,l(e.value,a=>(s(),t("div",{class:n(["alert my-2","alert-"+a.type]),role:"alert"},c(a.data),3))),256))}});export{_};
