<?php

?>

<table class="image-setting">
<tr>
<th>Original Image</th><th class="max-300px">Description with recomended dimensions</th><th>New Image</th>
</tr>
<tr>
<td><img id='logoimg' src="images/logo.png" /></td><td>Show in the navigation menubar (92x85)</td><td>
<input type="file" id='logo' name="FileInput" id="file" value=""/><input type="button" onclick="updateimage('logo')" value="Update" class="float-right"/></td>
</tr>
<tr>
<td><img src="images/homepagepic.png" /></td><td>Show in the Home page (450x425)</td><td><input type="file" /><input type="button" value="Update" class="float-right"/></td>
</tr>
<tr>
<td><img src="images/call.png" class="transparent-grid sm-img"/></td><td>Show in the footer(35x35 with transparent background)</td><td><input type="file" /><input type="button" value="Update" class="float-right"/></td>
</tr>
<tr>
<td><img src="images/feedback.png" class="transparent-grid sm-img"/></td><td>Show in the footer (35x35 with transparent background)</td><td><input type="file" /><input type="button" value="Update" class="float-right"/></td>
</tr>
<tr>
<td><img src="images/follow.png" class="transparent-grid sm-img"/></td><td>Show in the footer (35x35 with transparent background)</td><td><input type="file" /><input type="button" value="Update" class="float-right"/></td>
</tr>
<tr>
<td><img src="images/fb.png" class="transparent-grid sm-img"/></td><td>Show in the facebook link (25x25)</td><td><input type="file" /><input type="button" value="Update" class="float-right"/></td>
</tr>
<tr>
<td><img src="images/g-plus.png" class="transparent-grid sm-img"/></td><td>Show in the google+ link (25x25)</td><td><input type="file" /><input type="button" value="Update" class="float-right"/></td>
</tr>
<tr>
<td><img src="images/twitter.png" class="transparent-grid sm-img"/></td><td>Show in the twitter link (25x25)</td><td><input type="file" /><input type="button" value="Update" class="float-right"/></td>
</tr>
<tr>
<td><img src="images/cart.png" class="transparent-grid"/></td><td>Show in the sidebar cart (100x43)</td><td><input type="file" /><input type="button" value="Update" class="float-right"/></td>
</tr>
<tr>
<td><img src="images/loading.gif" class="transparent-grid sm-img"/></td><td>Show when loading (50x50 with animation)</td><td><input type="file" /><input type="button" value="Update" class="float-right"/></td>
</tr>
<tr>
<td><img src="images/login1.png" class="transparent-grid sm-img"/> 
<img src="images/login2.png" class="transparent-grid sm-img"/> 
</td><td>Login box animation <br />from  top image to bottom image (310x423)</td><td>From <input type="file" /> <br />To <input type="file" /><input type="button" value="Update" class="float-right"/></td>
</tr>
<tr>
<td><img src="images/blue-coupon.png" class="transparent-grid sm-img"/></td><td>Show in daily chance (100x100)</td><td><input type="file" /><input type="button" value="Update" class="float-right"/></td>
</tr>
<tr>
<td><img src="images/green-coupon.png" class="transparent-grid sm-img"/></td><td>Show in daily chance (100x100)</td><td><input type="file" /><input type="button" value="Update" class="float-right"/></td>
</tr>
<tr>
<td><img src="images/yellow-coupon.png" class="transparent-grid sm-img"/></td><td>Show in daily chance(100x100)</td><td><input type="file" /><input type="button" value="Update" class="float-right"/></td>
</tr>
</table>
</form>
<script type="text/javascript">
function updateimage(img){
	$('#wrapper').append( "<div class='overlay' id='overlay'></div><div class='loading-img' id='loading'></div>");
	var oldurl = 'images/logo.png';
	
	var inputElement = document.getElementById(img).files;
	var fdata = new FormData();
	fdata.append('newURL',inputElement[0]);
	fdata.append('oldURL',oldurl);
	$.ajax({
	  type: 'POST',
	  url: 'backend.php',
	  data: fdata,
      async: false,
      cache: false,
      contentType: false,
      processData: false,
	  success: function(data) {
		 document.getElementById(img+'img').src = oldurl;
	  	$('#overlay').remove();
		$('#loading').remove();
	  }
	});


	
}
</script>