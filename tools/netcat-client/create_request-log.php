<?php

// Usage: php create_request-log.php connection.json

$connection = json_decode(file_get_contents($argv[1]));
$encrypt = isset($argv[2]) && $argv[2] == "0" ? false : true;

$req = array(
        "_t" => time(),
	"datetime" => round(microtime(true) * 1000),
	"logger" => "some-logger",
	"msg" => "Efficient real-time centralized logging server ⚡ ",
	"file" => "index.html",
	"line" => 857,
	"app" => "Residue Netcat Sample",
	"level" => 16,
);
if ($encrypt) {
    $req = addslashes(json_encode($req));
    echo shell_exec("echo $req | ripe -e --key $connection->key --client-id $connection->client_id");
} else {
    $req["client_id"] = $connection->client_id;
    $req = addslashes(json_encode($req));
    echo $req;
}
