  <!DOCTYPE html>

  
 <html>
    <head>
      <title>Stress Controller Configuration</title>
      <style type="text/css">
      body{
        background-image:url('back.jpg');
        background-size: cover;
        background-attachment: fixed;
      }
      .content{
        background: white;
        width: 50%;
        padding: 30px;
        margin: 100px auto;
        font-family: serif;
        border: solid 10px black;
        border-radius: 25px;
      }
      </style>
    </head>
    <body>
    <center>

    <div class = "content">
    <h1 style = "font-family:serif;font-size:30px;"> Stress Controller Device Configuration </h1>

    <hr>
      <form method="post">
        Enter Your Name:<br>
        <input type="text" name="namedata"><br>
        Enter Your age:<br>
        <input type="text" name="agedata"><br>
        Enter Your height:<br>
        <input type="text" name="heightdata"><br>
        Enter Your weight:<br>
        <input type="text" name="weightdata"><br>
        <input type="submit" name="submit">
      </form>
      </div>
      </center>

    </body>
    </html>
   <?php
                  
    if(isset($_POST['namedata']))
    {
   $name=$_POST['namedata'];
   $age=$_POST['agedata'];
   $height=$_POST['heightdata'];
   $weight=$_POST['weightdata'];
  
  unlink('/home/user/Project/data.txt') or die("Couldn't delete file");
  $fp = fopen('/home/user/Project/data.txt', 'a');
  
  fwrite($fp, $name. " ");
  fwrite($fp, $age. " ");
  fwrite($fp, $height. " ");
  fwrite($fp, $weight. " " . "\r\n");
  fclose($fp);
  
  }
  ?>
