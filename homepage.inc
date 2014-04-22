<?php
$promotion = get_page_data("promotion");
?>
<div class="home-page-leftside circle"></div>
<img class="home-page-leftside" src="images/homepagepic.png" alt="The Mobile Market">
<div class="home-page-rightside">	<strong>Welcome</strong>
<br>to our Mobile Market!</div>
<div class="promotion-display">
<div class="star">
  <img src="images/star.png" alt="Important">
</div>
 <h1>
    <?php echo $promotion['title']?>
</h1>

<hr>
<p class="justify"><?php echo $promotion['content']; ?></p>
</div>
