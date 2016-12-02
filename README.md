HaselLibrary
====
これは私が今までに書いたプログラムを蓄積しておくための、ライブラリとは名ばかりの雑書庫です。<br/>
全てのプログラムはnamespace haselに含まれており、さらにいくつかの名前空間に分類されています。
## hasel::math
hasel::mathには数学に関するプログラムが含まれています。<br/>
<ul>
<li>math::Vector2</li>
一般的な二次元ベクトルクラスです。他ライブラリに依存しないために作られました。
<li>math::MathHelper</li>
数学系の補助関数が含まれるユーティリティクラスです。
</ul>

## hasel::memory
hasel::memoryにはメモリに関するプログラムが含まれています。<br/>
<ul>
<li>memory::UniquePtrObserver</li>
std::unique_ptrを監視するために作られたクラスです。
unique_ptrの!ptrの動作に名前を付けたかったのがおおよその制作動機ですが、きっと必要ないのでいつか削除されるでしょう。
</ul>

## hasel::shape
hasel::shapeには形状に関するプログラムが含まれています。<br/>
<ul>
<li>shape::Shape</li>
全ての形状の基本クラスです。haselにおける全ての形状クラスはShapeを継承しています。
<li>shape::Circle</li>
円形状クラスです。
<li>shape::AABB</li>
AABBクラスです。形状といえば形状なのですが、このクラスはshapeを継承していません。
<li>shape::ShapeHelper</li>
形状,AABBに関する補助関数が含まれるユーティリティクラスです。
</ul>

## hasel::cs2d
hasel::cs2dには2D衝突判定に関するプログラムが含まれています。現在、物理計算の機能は含まれていません。
<ul>
<li>cs2d::RigidBody</li>
剛体クラスです。複数の形状クラスを含ませることができます。
<li>cs2d::World</li>
衝突の検出と応答を行うクラスです。
<li>cs2d::CollisionCallback</li>
衝突時のコールバック関数を登録するクラスです。<br/>
剛体同士の衝突時には、このクラスから衝突処理関数を呼び出します。
<li>cs2d::CollisionHelper</li>
衝突判定に関する補助関数が含まれるユーティリティクラスです。<br/>
</ul>

## Example
以下のコードは、円形状を持つ2つの剛体を同じ位置に出現させ、衝突判定を行うものです。
実行するとコンソールに"HIT!"と表示されます。
<code>

	const int Ally = 1;
	const int Enemy = 2;

	auto world = WorldBuilder().buildUnique();

	auto bodyA = RigidBodyBuilder()
		.addAttribute(Ally)
		.addShape(CircleBuilder(10.f).buildRaw())
		.setPosition(Vector2(0.f, 0.f))
		.buildUnique();

	auto bodyB = RigidBodyBuilder()
		.addAttribute(Enemy)
		.addShape(CircleBuilder(10.f).buildRaw())
		.setPosition(Vector2(0.f, 0.f))
		.buildUnique();

	auto callback = CollisionCallbackBuilder(Ally, Enemy)
		.addCallbacks([](const uptr<RigidBody>& A, const uptr<RigidBody>& B)
	{
		cout<<"HIT!"<<endl;
	}).buildUnique();

	world->addRigidBody(move(bodyA));
	world->addRigidBody(move(bodyB));
	world->addCollisionCallback(move(callback));

	world->executeCollision();
</code>
