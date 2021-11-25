let arr =[];
const configs = [{defaultValue: "0.0.0",
description: "dlp ini版本",
group: "DLP配置",
name: "version",
required: true,
type: "string"}];
arr = [{defaultValue: "0.0.0",
description: "dlp ini版本",
group: "DLP配置",
name: "version",
required: true,
type: "string"}];
for(let i =0;i<arr.length;++i){
    console.log(configs.indexOf(arr[i]));
}

console.log(null+null===null)


let temp = ['dfdsfs','sfsd','name','value'];
console.log(temp.indexOf('value'));