/* alert('coucou'); */

addEventListener('load', function() {
  var blocks = document.querySelectorAll('pre code.hljs');
  Array.prototype.forEach.call(blocks, function(block, index) {
    var language = block.result.language;

	var languageDetails = languageFromIdentifier(language);
	$(blocks[index]).parent().prepend("<div style='padding: 6px 12px; border: 1px solid #e1e4e5; border-bottom: 0; display: inline-block; font-size: 12px; color:"  + languageDetails.color + " ;'>" + languageDetails.name + "</div>");
  });
  
  function	languageFromIdentifier(identifier)
  {
	  var values = {"objc": {"name": "Objective-C", "color": "#3366ff"},
	  "objectivec": {"name": "Objective-C", "color": "#3366ff"},
	  "swift": {"name": "Swift", "color": "#ff9900"}};
	  
	  if (values[identifier])
	  {
		  return values[identifier];
	  }
	  return {"name": identifier, "color": "#eee"};
  }
})