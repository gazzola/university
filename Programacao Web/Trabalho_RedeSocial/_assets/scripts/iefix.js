function toAbsURL(s){ //redefine a tag base, pois IE8- nao consegue encontrar
  var l = location, h, p, f, i; 

  if (/^\w+:/.test(s))
    return s; 

  h = l.protocol + '//' + l.host + (l.port!=''?(':' + l.port):''); 
  
  if (s.indexOf('/') == 0)
    return h + s; 

  p = l.pathname.replace(/\/[^\/]*$/, ''); 
  f = s.match(/\.\.\//g); 

  if(f){ 
    s = s.substring(f.length * 3); 
    for (i = f.length; i--;)
      p = p.substring(0, p.lastIndexOf('/')); 
  } 

  return h + p + '/' + s; 
}
   

var base = document.getElementsByTagName('base')[0];
base.href = toAbsURL(base.href);